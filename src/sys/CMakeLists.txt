
FIND_PACKAGE("time" REQUIRED)
FIND_PACKAGE("ucdm" REQUIRED)
FIND_PACKAGE("ds" REQUIRED)

ADD_PLATFORM_LIBRARY(ucdm-if STATIC "ucdm" ucdm_if.c)
ADD_PLATFORM_LIBRARY(time-if STATIC "hal-uc-timer time" time_if.c)
ADD_PLATFORM_LIBRARY(watchdog STATIC "hal-uc-core time" watchdog.c)

ADD_SUBDIRECTORY(modbus/src)

