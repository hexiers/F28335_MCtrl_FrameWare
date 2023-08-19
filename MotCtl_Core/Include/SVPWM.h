/*****************************************************************************
 * 文件名: SVPWM.h
 *   版本:  
 *   作者: Hex
 *   日期: 2023.08.01
 *   说明: SVPWM 生成器，采用共模电压生成方法
 *****************************************************************************/

#ifndef MOTCTL_CORE_INCLUDE_SVPWM_H_
#define MOTCTL_CORE_INCLUDE_SVPWM_H_

// **************************************************************************
// include files
#include "IQmathLib.h"
#include "ti_Lib/Include/math.h"
#include "types.h"

// **************************************************************************
//！定义
// **************************************************************************
//! 数值定义
//! 最大占空比：2/sqrt(3)
#define SVGEN_MAX_VAB_VOLTAGES                _IQ(1.1547005384)

//! Q15格式的100%占空比：1 - 2^(-15)
#define SVGEN_100_PERCENT_MODULATION          _IQ(1.0 - 1.0/32768)

//! sqrt(3)/2
#define SVGEN_SQRT3_OVER_2                    _IQ(0.8660254038)

//! sqrt(3)/2
#define SVGEN_4_OVER_3                        _IQ(4.0/3.0)

// **************************************************************************
// typedef 类定义
// **************************************************************************
//! \brief 定义SVM对象
typedef struct _SVGEN_Obj_
{
  _iq   maxModulation;        //!< SVM最大调制幅值
} SVGEN_Obj;


//! \brief 定义SVGEN句柄
typedef struct _SVGEN_Obj_ *SVGEN_Handle;


// **************************************************************************
// 函数方法
// **************************************************************************
//! \brief：   获取最大调制比参数
//! \param[in]: SVGEN handle
//! \return    最大调制比
static inline _iq SVGEN_getMaxModulation(SVGEN_Handle handle)
{
  SVGEN_Obj *obj = (SVGEN_Obj *)handle;

  return(obj->maxModulation);
} // end of SVGEN_getMaxModulation()


//! \brief     初始化SVGEN 模块
//! \param[in] pMemory   指向SVGEN对象内存的指针
//! \param[in] numBytes  分配给空间矢量生成器对象的字节数，bytes
//! \return    SVGEN 对象句柄值
extern SVGEN_Handle SVGEN_init(void *pMemory,const size_t numBytes);


//! \brief	空间矢量调制运行，饱和值MaxModulation
//! \param[in] handle  SVGEN 对象句柄
//! \param[in] pVab    指针指向alpha、beta轴下的电压矢量
//! \param[in] pT      指向PWM占空比时间的指针
static inline void SVGEN_run(SVGEN_Handle handle,const MATH_vec2 *pVab,MATH_vec3 *pT)
{

	_iq Vmax,Vmin,Vcom;
	_iq Va,Vb,Vc;
	_iq Va_tmp = -(pVab->value[0]>>1);
	_iq Vb_tmp = _IQmpy(SVGEN_SQRT3_OVER_2,pVab->value[1]);

	Va = pVab->value[0];  //alpha
	Vb = Va_tmp + Vb_tmp; //-0.5*alpha + sqrt(3)/2 * beta;
	Vc = Va_tmp - Vb_tmp; //-0.5*alpha - sqrt(3)/2 * beta;

	Vmax=0;
	Vmin=0;

	// 比大小得到 Vmin,Vmid,Vmax
	if (Va > Vb)
	{
		Vmax = Va;
		Vmin = Vb;
	}
	else
	{
		Vmax = Vb;
		Vmin = Va;
	}

	if (Vc > Vmax)
	{
		Vmax = Vc;
	}
	else if (Vc < Vmin)
	{
		Vmin = Vc;
	}

	Vcom = _IQmpy(Vmax+Vmin, _IQ(0.5));

	// 减去共模项以实现状态矢量调制
	pT->value[0] = (Va - Vcom);
	pT->value[1] = (Vb - Vcom);
	pT->value[2] = (Vc - Vcom);

	return;
} // end of SVGEN_run()


//! \brief     设置SVGEN的最大调制值
//! \param[in] handle         SVGEN 句柄
//! \param[in] maxModulation  最大调制值
static inline void SVGEN_setMaxModulation(SVGEN_Handle handle,const _iq maxModulation)
{
  SVGEN_Obj *obj = (SVGEN_Obj *)handle;
  _iq maxMod = maxModulation;

  if(maxMod > SVGEN_4_OVER_3)
      maxMod = SVGEN_4_OVER_3;
  else if(maxMod < _IQ(0.0))
      maxMod = _IQ(0.0);

  obj->maxModulation = maxMod;

  return;
} // end of SVGEN_setMaxModulation() 



#endif /* MOTCTL_CORE_INCLUDE_SVPWM_H_ */
