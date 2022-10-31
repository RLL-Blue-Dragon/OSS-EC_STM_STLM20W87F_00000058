// License       : License.txt
// Specifications: Spec-STLM20W87F.pdf
/*-- File Header Comment Start -----------------------------------------------*/
// File Name        : STLM20W87F.h
// Reason for change: 01.00.00 : 25/10/'22 : New Release
// Nickname         : Blue Dragon
/*-- File Header Comment End -------------------------------------------------*/

#ifndef __STLM20W87F_H__
#define __STLM20W87F_H__

#include "user_define.h"

// Components number
#define iSTLM20W87F             124U                    // STMicroelectronics STLM20W87F

// STLM20W87F System Parts definitions
#define iSTLM20W87F_xoff        1.8528F                 // X offset [V]
#define iSTLM20W87F_yoff        0.0F                    // Y offset [degree celsius]
#define iSTLM20W87F_gain        -0.01179F               // Gain [V/degree celsius]
#define iSTLM20W87F_max         130.0F                  // Temperature Max [degree celsius]
#define iSTLM20W87F_min         -55.0F                  // Temperature Min [degree celsius]

extern const tbl_adc_t tbl_STLM20W87F;

#endif /*__STLM20W87F_H__*/
