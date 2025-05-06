/**
  **************************************************************************
  * @file     user_config.h
  * @brief    LCD驱动程序兼容性配置
  * @author   1973688584@qq.com
  * @date     2025-05-05
  **************************************************************************
  */

#ifndef __USER_CONFIG_H
#define __USER_CONFIG_H

// SPI类型
#define SOFTWARE_SPI            (0x01)
#define HARDWARE_SPI            (0x02)

// MCU型号
#define  AT32                   (101)
#define  STM32                  (102)
#define  GD32                   (103)

#define ENABLE                  (1)
#define DISABLE                 (0)

////////////////////////////////////////////////////////////////////////
#define MCU_ID                  AT32 // STM32
#define SPI_TYPE                SOFTWARE_SPI
///////////////////////////////////////////////////////////////////////

#if (MCU_ID == AT32)
#include "at32f421_wk_config.h"
#include "wk_system.h"

#define delay_ms(x)         wk_delay_ms(x)
#endif

#endif
