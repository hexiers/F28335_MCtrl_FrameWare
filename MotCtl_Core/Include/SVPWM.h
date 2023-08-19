/*****************************************************************************
 * �ļ���: SVPWM.h
 *   �汾:  
 *   ����: Hex
 *   ����: 2023.08.01
 *   ˵��: SVPWM �����������ù�ģ��ѹ���ɷ���
 *****************************************************************************/

#ifndef MOTCTL_CORE_INCLUDE_SVPWM_H_
#define MOTCTL_CORE_INCLUDE_SVPWM_H_

// **************************************************************************
// include files
#include "IQmathLib.h"
#include "ti_Lib/Include/math.h"
#include "types.h"

// **************************************************************************
//������
// **************************************************************************
//! ��ֵ����
//! ���ռ�ձȣ�2/sqrt(3)
#define SVGEN_MAX_VAB_VOLTAGES                _IQ(1.1547005384)

//! Q15��ʽ��100%ռ�ձȣ�1 - 2^(-15)
#define SVGEN_100_PERCENT_MODULATION          _IQ(1.0 - 1.0/32768)

//! sqrt(3)/2
#define SVGEN_SQRT3_OVER_2                    _IQ(0.8660254038)

//! sqrt(3)/2
#define SVGEN_4_OVER_3                        _IQ(4.0/3.0)

// **************************************************************************
// typedef �ඨ��
// **************************************************************************
//! \brief ����SVM����
typedef struct _SVGEN_Obj_
{
  _iq   maxModulation;        //!< SVM�����Ʒ�ֵ
} SVGEN_Obj;


//! \brief ����SVGEN���
typedef struct _SVGEN_Obj_ *SVGEN_Handle;


// **************************************************************************
// ��������
// **************************************************************************
//! \brief��   ��ȡ�����ƱȲ���
//! \param[in]: SVGEN handle
//! \return    �����Ʊ�
static inline _iq SVGEN_getMaxModulation(SVGEN_Handle handle)
{
  SVGEN_Obj *obj = (SVGEN_Obj *)handle;

  return(obj->maxModulation);
} // end of SVGEN_getMaxModulation()


//! \brief     ��ʼ��SVGEN ģ��
//! \param[in] pMemory   ָ��SVGEN�����ڴ��ָ��
//! \param[in] numBytes  ������ռ�ʸ��������������ֽ�����bytes
//! \return    SVGEN ������ֵ
extern SVGEN_Handle SVGEN_init(void *pMemory,const size_t numBytes);


//! \brief	�ռ�ʸ���������У�����ֵMaxModulation
//! \param[in] handle  SVGEN ������
//! \param[in] pVab    ָ��ָ��alpha��beta���µĵ�ѹʸ��
//! \param[in] pT      ָ��PWMռ�ձ�ʱ���ָ��
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

	// �ȴ�С�õ� Vmin,Vmid,Vmax
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

	// ��ȥ��ģ����ʵ��״̬ʸ������
	pT->value[0] = (Va - Vcom);
	pT->value[1] = (Vb - Vcom);
	pT->value[2] = (Vc - Vcom);

	return;
} // end of SVGEN_run()


//! \brief     ����SVGEN��������ֵ
//! \param[in] handle         SVGEN ���
//! \param[in] maxModulation  ������ֵ
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
