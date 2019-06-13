

FIND_PACKAGE("ucdm" REQUIRED)
FIND_PACKAGE("time" REQUIRED)
FIND_PACKAGE("ds" REQUIRED)
FIND_PACKAGE("printf" REQUIRED)


SET(application_SRCS main.c
                     application_descriptors.c)
SET(deps "${deps} hal-uc-core hal-uc-gpio hal-uc-uart hal-uc-id") 
SET(deps "${deps} modbus ucdm-if time-if rand watchdog")
ADD_PLATFORM_EXECUTABLE(firmware ${deps} ${application_SRCS})
