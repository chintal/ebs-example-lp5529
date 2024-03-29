/* 
   Copyright (c) 
     (c) 2016      Chintalagiri Shashank, Quazar Technologies Pvt. Ltd.
   
   This file is part of
   Embedded bootstraps : Application Prototype
   
   This library is free software: you can redistribute it and/or modify
   it under the terms of the GNU Lesser General Public License as published
   by the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.
   
   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.
   
   You should have received a copy of the GNU Lesser General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>. 
*/

/**
 * @file application.h
 * @brief Application configuration parameters.
 *
 * This file, and the file hierarchy that it includes, should define
 * all the parameters necessary for configuring all inlcuded C code. 
 * This hierarchy should not possess any functional code within itself, 
 * and is to be used only as an in-code configuration store. It should 
 * only add preprocessor files and definitions and should not create 
 * any compilable code. It should be safe to include within _any_ file, 
 * and when included, provides all the compile-time preprocessor switches
 * necessary to correctly compile / link the appropriate code. 
 * 
 * All other source files should include this file, with the exception of
 * files within the uC HAL implementation, which will include this file
 * via hal_uc_map.h, which additionally processes the definitions here 
 * to provide 'calculated' compile time parameters. 
 * 
 * The lower level files in this hierarchy should not be included 
 * separately, and the information present in them should be accessed
 * only though this file.
 */


#ifndef APPLICATION_H
#define APPLICATION_H

#include "app/config.h"
#include <platform/types.h>

/**
* @name Backchannel Interface Configuration
*/
/**@{*/ 
    #define APP_ENABLE_BCIF                 1
    #define APP_BCIFACE_USE_USBCDC      ....1
/**@}*/ 

/**
* @name UCDM Configuration
*/
/**@{*/ 
    #define APP_ENABLE_UCDM                 1
    #define DMAP_MAX_REGISTERS              64
/**@}*/ 

/**
* @name Modbus Interface Configuration
*/
/**@{*/ 
    #define APP_ENABLE_MODBUS               1
    #define MODBUS_PLUGGABLE_TRANSPORTS     1
    #define MODBUS_ENABLE_TRANSPORT_UART    1
    #define MODBUS_TRANSPORT_UART_INTFNUM   1
    #define MODBUS_ENABLE_TRANSPORT_USBCDC  1
    #define MODBUS_TRANSPORT_USBCDC_INTFNUM 1
    #define APP_MODBUS_TRANSPORT            MODBUS_USBCDC
/**@}*/ 

/**
 * @name Entropy & Random Configuration
 */
/**@{*/ 
    #define APP_ENABLE_ENTROPY              1
    #define APP_ENTROPY_INTFNUM             1
    //#define RAND_GENERATOR                1
/**@}*/

/**
 * @name Time Configuration
 */
/**@{*/ 
    #define APP_ENABLE_SYSTICK              1
    #define APP_SYSTICK_TIMER_INTFNUM       2
    #define APP_SYSTICK_FREQ_Hz             1000

    #define APP_ENABLE_RTC                  0
    #define APP_ENABLE_CRON                 1
/**@}*/

/**
* @name SPI Core Interface Configuration
*/
/**@{*/ 
    #define APP_SUPPORT_SPI_SELECT_PIO      0
    #define APP_SUPPORT_SPI_SELECT_FUNC     1
    #define APP_SUPPORT_SPI_CTL             1
/**@}*/

/**
* @name Sharp Memory LCD Configuration
*/
/**@{*/ 
    #define APP_ENABLE_SHARP_MEMLCD         1
    #define SHARP_MEMLCD_COMINV             SHARP_MEMLCD_COMINV_HW_TIMER
    #define SHARP_MEMLCD_IMAGE_WRITER       0
    #define SHARP_MEMLCD_MANAGER            1
    #define SHARP_MEMLCD_FRAMEBUFFER        0
/**@}*/


// Core HAL Configuration. Should be calculated instead.

#define uC_USBCDC_ENABLED               1
#define uC_USBHID_ENABLED               0
#define uC_USBMSC_ENABLED               0
#define uC_USBPHDC_ENABLED              0

#define uC_UART0_ENABLED                0
#define uC_UART1_ENABLED                0

#define uC_TIMER0_ENABLED               0
#define uC_TIMER1_ENABLED               1
#define uC_TIMER2_ENABLED               1
#define uC_TIMER3_ENABLED               0

#define uC_TIMER2_TOP_IRQ_HANDLER       time_systick_handler

#define uC_SPI0_ENABLED                 0
#define uC_SPI1_ENABLED                 1
#define uC_SPI2_ENABLED                 0
#define uC_SPI3_ENABLED                 0

// BCIF based Hardware Configuration

#if APP_ENABLE_BCIF
#if APP_BCIFACE_USE_USBCDC

#undef uC_USBCDC_ENABLED
#define uC_USBCDC_ENABLED           1
#define APP_BCIFACE_PROVIDER        2

#else

#undef uC_UART1_ENABLED
#define uC_UART1_ENABLED            1
#define uC_UART1_BAUD               256000
#define uC_UART1_TXBUF_LEN          100
#define APP_BCIFACE_PROVIDER        1

#endif

#endif

#include "asp/hardware.h"
#include "devicemap.h"

#endif
