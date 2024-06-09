
//! @FilePath: \F28335_MotCtl_Frameware\DSP28xx_MotCtl_Frameware\MotCtl_Core\Source\PI_Ctrler.c
//! @Author: Hex
//! @Date: 2024-06-07 01:22:25
//! @LastEditTime: 2024-06-09 19:07:37
//! @Description: 

// the includes
#include "PI_Ctrler.h"


// **************************************************************************
// the functions

PI_Handle PI_init(void *pMemory,const size_t numBytes)
{
	PI_Handle handle;

	if(numBytes < sizeof(PI_Obj))

	  return((PI_Handle)NULL);

	// 设置句柄
	handle = (PI_Handle)pMemory;

	// 设置默认值
	PI_setUi(handle,_IQ(0.0));
	PI_setRefValue(handle,_IQ(0.0));
	PI_setFbackValue(handle,_IQ(0.0));

	return(handle);
} // end of PI_init()

//! \brief     PI运行方法（串联型）
//! \param[in] handle      PI句柄
//! \param[in] refValue    参考输入
//! \param[in] fbackValue  控制器反馈值
//! \param[in] pOutValue   控制输出指针
static inline void PI_run(PI_Handle handle,const _iq refValue,const _iq fbackValue,_iq *pOutValue)
{
  PI_Obj *obj = (PI_Obj *)handle;

  _iq Error;
  _iq Up,Ui;


  Error = refValue - fbackValue;

  Ui = obj->Ui;                                                  // 载入上一时刻的积分值
  Up = _IQmpy(obj->Kp,Error);                                    // 计算比例输出
  Ui = _IQsat(Ui + _IQmpy(obj->Ki,Up),obj->outMax,obj->outMin);  // 计算积分输出

  obj->Ui = Ui;                                                  // 存储积分累计值
  obj->refValue = refValue;
  obj->fbackValue = fbackValue;

  *pOutValue = _IQsat(Up + Ui,obj->outMax,obj->outMin);          // 限幅

  return;
} // end of PI_run()


// end of file

