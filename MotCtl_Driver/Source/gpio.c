
//! @FilePath: \DSP28xx_MotCtl_Frameware\MotCtl_Driver\Source\gpio.c
//! @Author: Hex
//! @Date: 2023-08-20 21:25:26
//! @LastEditTime: 2023-08-27 08:57:25
//! @Description: API函数已修改

// **************************************************************************
// the includes

#include "../Include/gpio.h"

// **************************************************************************
// the defines

// **************************************************************************
// the globals

// **************************************************************************
// the functions
//! @brief: 获取GPIO位数据
bool GPIO_getData(GPIO_Handle gpioHandle, const GPIO_Number_e gpioNumber)
{
  GPIO_Obj *gpio = (GPIO_Obj *)gpioHandle;

  if (gpioNumber < GPIO_Number_32)
  {
    return (bool)((gpio->GPADAT >> gpioNumber) & 0x0001);
  }
  else if(gpioNumber < GPIO_Number_64)
  {
    return (bool)((gpio->GPBDAT >> (gpioNumber - GPIO_Number_32)) & 0x0001);
  }
  else
  {
    return (bool)((gpio->GPCDAT >> (gpioNumber - GPIO_Number_64)) & 0x0001);
  }

}// end of GPIO_getData() function

//! @brief: 获取GPIO端口数据
uint32_t GPIO_getPortData(GPIO_Handle gpioHandle, const GPIO_Port_e gpioPort)
{
  GPIO_Obj *gpio = (GPIO_Obj *)gpioHandle;

  if (gpioPort == GPIO_Port_A)
  {
    return (gpio->GPADAT);
  }
  else if (gpioPort == GPIO_Port_B)
  {
    return (gpio->GPBDAT);
  }
  else if (gpioPort == GPIO_Port_C)
  {
    return (gpio->GPCDAT);
  }

  return (NULL);

} // end of GPIO_getPortData() function

//! @brief: GPIO句柄初始化
//! @param void *pMemory
//! @param size_t numBytes
//! @return *
//! @details:
GPIO_Handle GPIO_init(void *pMemory, const size_t numBytes)
{
  GPIO_Handle gpioHandle;

  if (numBytes < sizeof(GPIO_Obj))
  {
    return ((GPIO_Handle)NULL);
  }

  // assign the handle
  gpioHandle = (GPIO_Handle)pMemory;

  return (gpioHandle);
} // end of GPIO_init() function

//! @brief: 内部上拉电阻使能
//! @param GPIO_Handle gpioHandle
//! @param GPIO_Number_e gpioNumber
//! @param GPIO_Pullup_e pullup
//! @return *
//! @details:
void GPIO_setPullup(GPIO_Handle gpioHandle, const GPIO_Number_e gpioNumber, const GPIO_Pullup_e pullup)
{
  GPIO_Obj *gpio = (GPIO_Obj *)gpioHandle;

  ENABLE_PROTECTED_REGISTER_WRITE_MODE;

  if (gpioNumber < GPIO_Number_32)
  {
    // clear the bit
    gpio->GPAPUD &= (~((uint32_t)1 << gpioNumber));

    // set the bit
    gpio->GPAPUD |= (uint32_t)pullup << gpioNumber;
  }
  else if (gpioNumber < GPIO_Number_64)
  {
    // clear the bit
    gpio->GPBPUD &= (~((uint32_t)1 << (gpioNumber - GPIO_Number_32)));

    // set the bit
    gpio->GPBPUD |= (uint32_t)pullup << (gpioNumber - GPIO_Number_32);
  }
  else if (gpioNumber < GPIO_numGpios)
  {
    // clear the bit
    gpio->GPCPUD &= (~((uint32_t)1 << (gpioNumber - GPIO_Number_64)));

    // set the bit
    gpio->GPCPUD |= (uint32_t)pullup << (gpioNumber - GPIO_Number_64);
  }

  DISABLE_PROTECTED_REGISTER_WRITE_MODE;

  return;
} // end of GPIO_setPullup() function

//! @brief: GPIO输出方向
void GPIO_setDirection(GPIO_Handle gpioHandle, const GPIO_Number_e gpioNumber, const GPIO_Direction_e direction)
{
  GPIO_Obj *gpio = (GPIO_Obj *)gpioHandle;

  ENABLE_PROTECTED_REGISTER_WRITE_MODE;

  if (gpioNumber < GPIO_Number_32)
  {
    // clear the bit
    gpio->GPADIR &= (~((uint32_t)1 << gpioNumber));

    // set the bit
    gpio->GPADIR |= (uint32_t)direction << gpioNumber;
  }
  else if (gpioNumber < GPIO_Number_64)
  {
    // clear the bit
    gpio->GPBDIR &= (~((uint32_t)1 << (gpioNumber - GPIO_Number_32)));

    // set the bit
    gpio->GPBDIR |= (uint32_t)direction << (gpioNumber - GPIO_Number_32);
  }
  else if (gpioNumber < GPIO_numGpios)
  {
    // clear the bit
    gpio->GPCDIR &= (~((uint32_t)1 << (gpioNumber - GPIO_Number_64)));

    // set the bit
    gpio->GPCDIR |= (uint32_t)direction << (gpioNumber - GPIO_Number_64);
  }

  DISABLE_PROTECTED_REGISTER_WRITE_MODE;

  return;
} // end of GPIO_setDirection() function

void GPIO_setExtInt(GPIO_Handle gpioHandle, const GPIO_Number_e gpioNumber, const CPU_ExtIntNumber_e intNumber)
{
  GPIO_Obj *gpio = (GPIO_Obj *)gpioHandle;

  ENABLE_PROTECTED_REGISTER_WRITE_MODE;

  // associate the interrupt with the GPIO pin
  gpio->GPIOXINTnSEL[intNumber] = gpioNumber;

  DISABLE_PROTECTED_REGISTER_WRITE_MODE;

  return;
} // end of GPIO_setExtInt() function

//! @brief: GPIO位读取
bool GPIO_read(GPIO_Handle gpioHandle, const GPIO_Number_e gpioNumber)
{
  GPIO_Obj *gpio = (GPIO_Obj *)gpioHandle;
  bool gpio_status = 0;
  uint32_t gpio_read = 0;

  if (gpioNumber < GPIO_Number_32)
  {
    gpio_read = (gpio->GPADAT) & ((uint32_t)1 << gpioNumber);
  }
  else if (gpioNumber < GPIO_Number_64)
  {
    gpio_read = (gpio->GPBDAT) & ((uint32_t)1 << (gpioNumber - GPIO_Number_32));
  }
  else if (gpioNumber < GPIO_numGpios)
  {
    gpio_read = (gpio->GPCDAT) & ((uint32_t)1 << (gpioNumber - GPIO_Number_64));
  }

  if (gpio_read == 0)
  {
    gpio_status = LOW;
  }
  else
  {
    gpio_status = HIGH;
  }

  return (gpio_status);
} // end of GPIO_read() function

//! @brief: GPIO位手动置高
void GPIO_setHigh(GPIO_Handle gpioHandle, const GPIO_Number_e gpioNumber)
{
  GPIO_Obj *gpio = (GPIO_Obj *)gpioHandle;

  ENABLE_PROTECTED_REGISTER_WRITE_MODE;

  if (gpioNumber < GPIO_Number_32)
  {
    gpio->GPASET = (uint32_t)1 << gpioNumber;
  }
  else if (gpioNumber < GPIO_Number_64)
  {
    gpio->GPBSET = (uint32_t)1 << (gpioNumber - GPIO_Number_32);
  }
  else if (gpioNumber < GPIO_numGpios)
  {
    gpio->GPCSET = (uint32_t)1 << (gpioNumber - GPIO_Number_64);
  }

  DISABLE_PROTECTED_REGISTER_WRITE_MODE;

  return;
} // end of GPIO_setHigh() function

//! @brief: GPIO位手动置低
void GPIO_setLow(GPIO_Handle gpioHandle, const GPIO_Number_e gpioNumber)
{
  GPIO_Obj *gpio = (GPIO_Obj *)gpioHandle;

  ENABLE_PROTECTED_REGISTER_WRITE_MODE;

  if (gpioNumber < GPIO_Number_32)
  {
    gpio->GPACLEAR = (uint32_t)1 << gpioNumber;
  }
  else if (gpioNumber < GPIO_Number_64)
  {
    gpio->GPBCLEAR = (uint32_t)1 << (gpioNumber - GPIO_Number_32);
  }
  else if (gpioNumber < GPIO_numGpios)
  {
    gpio->GPCCLEAR = (uint32_t)1 << (gpioNumber - GPIO_Number_64);
  }

  DISABLE_PROTECTED_REGISTER_WRITE_MODE;

  return;
} // end of GPIO_setLow() function

//! @brief: GPIO 模式选择
void GPIO_setMode(GPIO_Handle gpioHandle, const GPIO_Number_e gpioNumber, const GPIO_Mode_e mode)
{
  GPIO_Obj *gpio = (GPIO_Obj *)gpioHandle;

  ENABLE_PROTECTED_REGISTER_WRITE_MODE;

  if (gpioNumber < (GPIO_GPMUX_NUMGPIOS_PER_REG * 1))
  {
    uint_least8_t lShift = gpioNumber << 1;
    uint32_t clearBits = (uint32_t)GPIO_GPMUX_CONFIG_BITS << lShift;
    uint32_t setBits = (uint32_t)mode << lShift;

    // clear the bits
    gpio->GPAMUX1 &= (~clearBits);
    // set the bits
    gpio->GPAMUX1 |= setBits;
  }
  else if (gpioNumber < (GPIO_GPMUX_NUMGPIOS_PER_REG * 2))
  {
    uint_least8_t lShift = (gpioNumber - (GPIO_GPMUX_NUMGPIOS_PER_REG * 1)) << 1;
    uint32_t clearBits = (uint32_t)GPIO_GPMUX_CONFIG_BITS << lShift;
    uint32_t setBits = (uint32_t)mode << lShift;

    // clear the bits
    gpio->GPAMUX2 &= (~clearBits);

    // set the bits
    gpio->GPAMUX2 |= setBits;
  }
  else if (gpioNumber < (GPIO_GPMUX_NUMGPIOS_PER_REG * 3))
  {
    uint_least8_t lShift = (gpioNumber - (GPIO_GPMUX_NUMGPIOS_PER_REG * 2)) << 1;
    uint32_t clearBits = (uint32_t)GPIO_GPMUX_CONFIG_BITS << lShift;
    uint32_t setBits = (uint32_t)mode << lShift;

    // clear the bits
    gpio->GPBMUX1 &= (~clearBits);

    // set the bits
    gpio->GPBMUX1 |= setBits;
  }
  else if (gpioNumber < (GPIO_GPMUX_NUMGPIOS_PER_REG * 4))
  {
    uint_least8_t lShift = (gpioNumber - (GPIO_GPMUX_NUMGPIOS_PER_REG * 3)) << 1;
    uint32_t clearBits = (uint32_t)GPIO_GPMUX_CONFIG_BITS << lShift;
    uint32_t setBits = (uint32_t)mode << lShift;

    // clear the bits
    gpio->GPBMUX2 &= (~clearBits);

    // set the bits
    gpio->GPBMUX2 |= setBits;
  }
  else if (gpioNumber < (GPIO_GPMUX_NUMGPIOS_PER_REG * 5))
  {
    uint_least8_t lShift = (gpioNumber - (GPIO_GPMUX_NUMGPIOS_PER_REG * 4)) << 1;
    uint32_t clearBits = (uint32_t)GPIO_GPMUX_CONFIG_BITS << lShift;
    uint32_t setBits = (uint32_t)mode << lShift;

    // clear the bits
    gpio->GPCMUX1 &= (~clearBits);

    // set the bits
    gpio->GPCMUX1 |= setBits;
  }
  else if (gpioNumber < (GPIO_GPMUX_NUMGPIOS_PER_REG * 6))
  {
    uint_least8_t lShift = (gpioNumber - (GPIO_GPMUX_NUMGPIOS_PER_REG * 5)) << 1;
    uint32_t clearBits = (uint32_t)GPIO_GPMUX_CONFIG_BITS << lShift;
    uint32_t setBits = (uint32_t)mode << lShift;

    // clear the bits
    gpio->GPCMUX2 &= (~clearBits);

    // set the bits
    gpio->GPCMUX2 |= setBits;
  }

  DISABLE_PROTECTED_REGISTER_WRITE_MODE;

  return;
} // end of GPIO_setMode() function

//! @brief: GPIO 端口数据一键设置
void GPIO_setPortData(GPIO_Handle gpioHandle, const GPIO_Port_e gpioPort, const uint32_t data)
{
  GPIO_Obj *gpio = (GPIO_Obj *)gpioHandle;

  ENABLE_PROTECTED_REGISTER_WRITE_MODE;

  if (gpioPort == GPIO_Port_A)
  {
    gpio->GPADAT = data;
  }
  else if (gpioPort == GPIO_Port_B)
  {
    gpio->GPBDAT = data;
  }
  else if (gpioPort == GPIO_Port_C)
  {
    gpio->GPCDAT = data;
  }

  DISABLE_PROTECTED_REGISTER_WRITE_MODE;

  return;
} // end of GPIO_setPortData() function

//! @brief: GPIO 设置输入限定设置
void GPIO_setQualification(GPIO_Handle gpioHandle, const GPIO_Number_e gpioNumber, const GPIO_Qual_e qualification)
{
  GPIO_Obj *gpio = (GPIO_Obj *)gpioHandle;

  ENABLE_PROTECTED_REGISTER_WRITE_MODE;

  if (gpioNumber <= ((GPIO_GPxQSELx_NUMGPIOS_PER_REG * 1) - 1))
  {
    uint32_t clearBits = (uint32_t)GPIO_GPxQSELy_GPIOx_BITS << (2 * gpioNumber);
    gpio->GPAQSEL1 &= ~(clearBits);
    gpio->GPAQSEL1 |= (uint32_t)qualification << (2 * gpioNumber);
  }
  else if (gpioNumber <= ((GPIO_GPxQSELx_NUMGPIOS_PER_REG * 2) - 1))
  {
    uint32_t clearBits = (uint32_t)GPIO_GPxQSELy_GPIOx_BITS << (2 * (gpioNumber - (GPIO_GPxQSELx_NUMGPIOS_PER_REG * 1)));
    gpio->GPAQSEL2 &= ~(clearBits);
    gpio->GPAQSEL2 |= (uint32_t)qualification << (2 * (gpioNumber - (GPIO_GPxQSELx_NUMGPIOS_PER_REG * 1)));
  }
  else if (gpioNumber <= ((GPIO_GPxQSELx_NUMGPIOS_PER_REG * 3) - 1))
  {
    uint32_t clearBits = (uint32_t)GPIO_GPxQSELy_GPIOx_BITS << (2 * (gpioNumber - (GPIO_GPxQSELx_NUMGPIOS_PER_REG * 2)));
    gpio->GPBQSEL1 &= ~(clearBits);
    gpio->GPBQSEL1 |= (uint32_t)qualification << (2 * (gpioNumber - (GPIO_GPxQSELx_NUMGPIOS_PER_REG * 2)));
  }
  else if (gpioNumber <= ((GPIO_GPxQSELx_NUMGPIOS_PER_REG * 4) - 1))
  {
    uint32_t clearBits = (uint32_t)GPIO_GPxQSELy_GPIOx_BITS << (2 * (gpioNumber - (GPIO_GPxQSELx_NUMGPIOS_PER_REG * 3)));
    gpio->GPBQSEL2 &= ~(clearBits);
    gpio->GPBQSEL2 |= (uint32_t)qualification << (2 * (gpioNumber - (GPIO_GPxQSELx_NUMGPIOS_PER_REG * 3)));
  }

  DISABLE_PROTECTED_REGISTER_WRITE_MODE;

  return;
} // end of GPIO_setQualification() function

//! @brief: GPIO 设置采样窗宽度
void GPIO_setQualificationPeriod(GPIO_Handle gpioHandle, const GPIO_Number_e gpioNumber, const uint_least8_t period)
{
  GPIO_Obj *gpio = (GPIO_Obj *)gpioHandle;

  ENABLE_PROTECTED_REGISTER_WRITE_MODE;

  if (gpioNumber <= ((GPIO_GPxCTRL_QUALPRDx_NUMBITS_PER_REG * 1) - 1))
  {
    uint32_t clearBits = (uint32_t)GPIO_GPxCTRL_QUALPRDx_BITS;
    gpio->GPACTRL &= ~(clearBits);
    gpio->GPACTRL |= (uint32_t)period;
  }
  else if (gpioNumber <= ((GPIO_GPxCTRL_QUALPRDx_NUMBITS_PER_REG * 2) - 1))
  {
    uint32_t clearBits = (uint32_t)GPIO_GPxCTRL_QUALPRDx_BITS << 8;
    gpio->GPACTRL &= ~(clearBits);
    gpio->GPACTRL |= (uint32_t)period << 8;
  }
  else if (gpioNumber <= ((GPIO_GPxCTRL_QUALPRDx_NUMBITS_PER_REG * 3) - 1))
  {
    uint32_t clearBits = (uint32_t)GPIO_GPxCTRL_QUALPRDx_BITS << 16;
    gpio->GPACTRL &= ~(clearBits);
    gpio->GPACTRL |= (uint32_t)period << 16;
  }
  else if (gpioNumber <= ((GPIO_GPxCTRL_QUALPRDx_NUMBITS_PER_REG * 4) - 1))
  {
    uint32_t clearBits = (uint32_t)GPIO_GPxCTRL_QUALPRDx_BITS << 24;
    gpio->GPACTRL &= ~(clearBits);
    gpio->GPACTRL |= (uint32_t)period << 24;
  }
  else if (gpioNumber <= ((GPIO_GPxCTRL_QUALPRDx_NUMBITS_PER_REG * 5) - 1))
  {
    uint32_t clearBits = (uint32_t)GPIO_GPxCTRL_QUALPRDx_BITS;
    gpio->GPBCTRL &= ~(clearBits);
    gpio->GPBCTRL |= (uint32_t)period;
  }
  else if (gpioNumber <= ((GPIO_GPxCTRL_QUALPRDx_NUMBITS_PER_REG * 6) - 1))
  {
    uint32_t clearBits = (uint32_t)GPIO_GPxCTRL_QUALPRDx_BITS << 8;
    gpio->GPBCTRL &= ~(clearBits);
    gpio->GPBCTRL |= (uint32_t)period << 8;
  }
  else if (gpioNumber <= ((GPIO_GPxCTRL_QUALPRDx_NUMBITS_PER_REG * 7) - 1))
  {
    uint32_t clearBits = (uint32_t)GPIO_GPxCTRL_QUALPRDx_BITS << 16;
    gpio->GPBCTRL &= ~(clearBits);
    gpio->GPBCTRL |= (uint32_t)period << 16;
  }
  else if (gpioNumber <= ((GPIO_GPxCTRL_QUALPRDx_NUMBITS_PER_REG * 8) - 1))
  {
    uint32_t clearBits = (uint32_t)GPIO_GPxCTRL_QUALPRDx_BITS << 24;
    gpio->GPBCTRL &= ~(clearBits);
    gpio->GPBCTRL |= (uint32_t)period << 24;
  }

  DISABLE_PROTECTED_REGISTER_WRITE_MODE;

  return;
} // end of GPIO_setQualificationPeriod() function

//! @brief: GPIO位状态取反
void GPIO_toggle(GPIO_Handle gpioHandle, const GPIO_Number_e gpioNumber)
{
  GPIO_Obj *gpio = (GPIO_Obj *)gpioHandle;

  ENABLE_PROTECTED_REGISTER_WRITE_MODE;

  if (gpioNumber < GPIO_Number_32)
  {
    gpio->GPATOGGLE = (uint32_t)1 << gpioNumber;
  }
  else if (gpioNumber < GPIO_Number_64)
  {
    gpio->GPBTOGGLE = (uint32_t)1 << (gpioNumber - GPIO_Number_32);
  }
  else if (gpioNumber < GPIO_numGpios)
  {
    gpio->GPCTOGGLE = (uint32_t)1 << (gpioNumber - GPIO_Number_64);
  }

  DISABLE_PROTECTED_REGISTER_WRITE_MODE;

  return;
} // end of GPIO_toggle() function

void GPIO_lpmSelect(GPIO_Handle gpioHandle, const GPIO_Number_e gpioNumber)
{
  GPIO_Obj *gpio = (GPIO_Obj *)gpioHandle;

  ENABLE_PROTECTED_REGISTER_WRITE_MODE;

  gpio->GPIOLPMSEL |= ((uint32_t)1 << gpioNumber);

  DISABLE_PROTECTED_REGISTER_WRITE_MODE;

  return;
} // end of GPIO_lpmSelect() function
