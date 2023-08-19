/*
 * ParkTrans.h
 *
 *  Created on: 2023Äê8ÔÂ1ÈÕ
 *      Author: Hex
 */

#ifndef MOTCTL_CORE_INCLUDE_PARKTRANS_H_
#define MOTCTL_CORE_INCLUDE_PARKTRANS_H_


// **************************************************************************
// the includes

#include "IQmathLib.h"
#include "ti_Lib/Include/math.h"
#include "types.h"


//!
//!
//! \defgroup PARK PARK
//!
//@{

// Include the algorithm overview defined in modules/<module>/docs/doxygen/doxygen.h
//! \defgroup PARK_OVERVIEW



// **************************************************************************
// the defines



// **************************************************************************
// the typedefs

//! \brief Defines the PARK object
//!
typedef struct _PARK_Obj_
{

  _iq  sinTh;      //!< the sine of the angle between the d,q and the alpha,beta coordinate systems
  _iq  cosTh;      //!< the cosine of the angle between the d,q and the alpha,beta coordinate systems

} PARK_Obj;


//! \brief Defines the PARK handle
//!
typedef struct _PARK_Obj_ *PARK_Handle;


// **************************************************************************
// the function prototypes

//! \brief     Gets the cosine of the angle between the d,q and the alpha,beta coordinate systems
//! \param[in] handle  The Park transform handle
//! \return    The cosine of the angle
static inline _iq PARK_getCosTh(PARK_Handle handle)
{
  PARK_Obj *obj = (PARK_Obj *)handle;

  return(obj->cosTh);
} // end of PARK_getCosTh() function



//! \brief     Gets the cosine/sine phasor for the Park transform
//! \param[in] handle   The Park transform handle
//! \param[in] pPhasor      The pointer to the cosine/sine phasor
static inline void PARK_getPhasor(PARK_Handle handle,MATH_vec2 *pPhasor)
{
  PARK_Obj *obj = (PARK_Obj *)handle;

  pPhasor->value[0] = obj->cosTh;
  pPhasor->value[1] = obj->sinTh;

  return;
} // end of PARK_getPhasor() function


//! \brief     Gets the sine of the angle between the d,q and the alpha,beta coordinate systems
//! \param[in] handle  The Park transform handle
//! \return    The sine of the angle
static inline _iq PARK_getSinTh(PARK_Handle handle)
{
  PARK_Obj *obj = (PARK_Obj *)handle;

  return(obj->sinTh);
} // end of PARK_getSinTh() function


//! \brief     Initializes the Park transform module
//! \param[in] pMemory      A pointer to the memory for the Park object
//! \param[in] numBytes     The number of bytes allocated for the Park object, bytes
//! \return The Park (PARK) object handle
extern PARK_Handle PARK_init(void *pMemory,const size_t numBytes);


//! \brief     Runs the Park transform module
//! \param[in] handle  The Park transform handle
//! \param[in] pInVec      The pointer to the input vector
//! \param[in] pOutVec     The pointer to the output vector
static inline void PARK_run(PARK_Handle handle,const MATH_vec2 *pInVec,MATH_vec2 *pOutVec)
{
  PARK_Obj *obj = (PARK_Obj *)handle;

  _iq sinTh = obj->sinTh;
  _iq cosTh = obj->cosTh;

  _iq value_0 = pInVec->value[0];
  _iq value_1 = pInVec->value[1];


  pOutVec->value[0] = _IQmpy(value_0,cosTh) + _IQmpy(value_1,sinTh);
  pOutVec->value[1] = _IQmpy(value_1,cosTh) - _IQmpy(value_0,sinTh);

  return;
} // end of PARK_run() function


//! \brief     Sets the cosine of the angle between the d,q and the alpha,beta coordinate systems
//! \param[in] handle  The Park transform handle
//! \param[in] cosTh       The cosine of the angle
static inline void PARK_setCosTh(PARK_Handle handle,const _iq cosTh)
{
  PARK_Obj *obj = (PARK_Obj *)handle;

  obj->cosTh = cosTh;

  return;
} // end of PARK_setCosTh() function


//! \brief     Sets the cosine/sine phasor for the inverse Park transform
//! \param[in] handle   The Park transform handle
//! \param[in] pPhasor      The pointer to the cosine/sine phasor, pu
static inline void PARK_setPhasor(PARK_Handle handle,const MATH_vec2 *pPhasor)
{
  PARK_Obj *obj = (PARK_Obj *)handle;

  obj->cosTh = pPhasor->value[0];
  obj->sinTh = pPhasor->value[1];

  return;
} // end of PARK_setPhasor() function


//! \brief     Sets the sine of the angle between the d,q and the alpha,beta coordinate systems
//! \param[in] handle  The Park transform handle
//! \param[in] sinTh       The sine of the angle
static inline void PARK_setSinTh(PARK_Handle handle,const _iq sinTh)
{
  PARK_Obj *obj = (PARK_Obj *)handle;

  obj->sinTh = sinTh;

  return;
} // end of PARK_setSinTh() function


//! \brief     Sets up the Park transform module
//! \param[in] handle  The Park transform handle
//! \param[in] angle_pu    The angle between the d,q and the alpha,beta coordinate systems, pu
static inline void PARK_setup(PARK_Handle handle,const _iq angle_pu)
{
  PARK_Obj *obj = (PARK_Obj *)handle;

  obj->sinTh = _IQsinPU(angle_pu);
  obj->cosTh = _IQcosPU(angle_pu);

  return;
} // end of PARK_setup() function


#endif /* MOTCTL_CORE_INCLUDE_PARKTRANS_H_ */
