
#include "application.h"
#include "application_descriptors.h"
#include "hal/uc.h"
#include "drivers/led/led.h"
#include "drivers/sharp-memlcd/memlcd.h"
#include "sys/sys.h"

#include "sys/modbus/modbus.h"
#include "sys/watchdog.h"

#include <platform/cpu.h>
#include <time/cron.h>

volatile uint8_t rval=0;


static void deferred_exec(void);

static void deferred_exec(void){
    #if APP_ENABLE_MODBUS == 1
        modbus_state_machine();
    #endif
    #if APP_ENABLE_CRON == 1
        tm_cron_poll();
    #endif
    spi_reactor();
}


static void _initialize_interrupts(void);

static void _initialize_interrupts(void){
    // Needed to ensure linker includes interrupt handlers 
    // in the output.
    __uart_handler_inclusion = 1;
    __usb_handler_inclusion = 1;
    __timer_handler_inclusion = 1;
    __spi_handler_inclusion = 1;
}


int main(void)
{   
    // Pre-init, and assoicated Housekeeping
    _initialize_interrupts();
    
    // uC Core Initialization
    watchdog_hold();
    power_set_full();
    clock_set_default();
    global_interrupt_enable();
    
    spi_init();
    
    usb_init();
    id_init();
    application_descriptors_init();
    
    // Subsystems Initialization
    #if APP_ENABLE_BCIF == 1
        bc_init();
    #endif
    
    ucdm_init();
    app_tm_init(DMAP_TIME_BASE_ADDRESS);
    watchdog_service_init();
    
    #if APP_ENABLE_MODBUS == 1
        modbus_init(DMAP_MODBUS_BASE_ADDRESS, 
                    MODBUS_DEFAULT_DEVICE_ADDRESS);
    #endif
        
    #if APP_ENABLE_SHARP_MEMLCD == 1
        sharp_memlcd_init();
    #endif
    
    while(1){
        deferred_exec();
    }
    return(0);
}
