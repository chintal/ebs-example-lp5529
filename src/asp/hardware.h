/* 
   Copyright (c) 
     (c) 2019 Chintalagiri Shashank, Quazar Technologies Pvt. Ltd.
   
   This file is part of
   Embedded bootstraps : uC Support Package
   
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
 * @file asp/hardware.h
 * @brief Highest level include for Hardware definitions.
 *
 * This file, and the file hierarchy that it includes, should define
 * all available capabilities of the entirety of the hardware, 
 * independent of the finer details of the application.
 *  
 */

#ifndef ASP_HARDWARE_H
#define ASP_HARDWARE_H

#include "bsp/board.h"

/**
* @name Sharp Memory LCD Hardware Configuration
*/
/**@{*/ 
    #define SHARP_MEMLCD_PANEL                  SHARP_MEMLCD_LS013B4DN04
    #define SHARP_MEMLCD_SPI_INTFNUM            1
    #define SHARP_MEMLCD_SPI_BASE_FREQ          uC_SPI1_SCLK_BASE_FREQ
    #define SHARP_MEMLCD_SPI_CS_PORT            6
    #define SHARP_MEMLCD_SPI_CS_PIN             _BV(6)
    #define SHARP_MEMLCD_ENABLE_PORT            1
    #define SHARP_MEMLCD_ENABLE_PIN             _BV(6)
    #define SHARP_MEMLCD_COMINV_PORT            2
    #define SHARP_MEMLCD_COMINV_PIN             _BV(0)
    #define SHARP_MEMLCD_COMINV_INTFNUM         1
    #define SHARP_MEMLCD_COMINV_INTFCHN         1
    #define SHARP_MEMLCD_COMINV_CLKSOURCE_FREQ  uC_TIMER1_CLKSOURCE_FREQ
    #define SHARP_MEMLCD_COMINV_CLK_PRESCALER   24
    #define SHARP_MEMLCD_COMINV_CLK_PRESCALER_B TIMER_PRESCALER_DIV24
/**@}*/

#endif
