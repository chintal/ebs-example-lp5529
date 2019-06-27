

FIND_PACKAGE("time" REQUIRED)
FIND_PACKAGE("ds" REQUIRED)
FIND_PACKAGE("printf" REQUIRED)
FIND_PACKAGE("rand" REQUIRED)
FIND_PACKAGE("prbs" REQUIRED)
FIND_PACKAGE("crypto" REQUIRED)

SET(application_SRCS main.c
                     application_descriptors.c)
SET(deps "${deps} driver-sharp-memlcd") 
SET(deps "${deps} hal-uc-core hal-uc-gpio hal-uc-uart hal-uc-spi hal-uc-id") 
SET(deps "${deps} modbus ucdm-if time-if rand watchdog")
ADD_PLATFORM_EXECUTABLE(firmware ${deps} ${application_SRCS})
