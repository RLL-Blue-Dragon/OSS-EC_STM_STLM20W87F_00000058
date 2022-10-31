// License       : License.txt
// Specifications: Spec-00000058.pdf
/*-- File Header Comment Start -----------------------------------------------*/
// File Name        : STLM20W87F_00000058.cpp
// BSL              : 00000058
// Model number     : STMicroelectronics STLM20W87F
// Spec               Component type       : ADC
//                    OS                   : Mbed
//                    Calculation          : Floating-point
//                    Conversion type      : Linear
//                    Moving average filter: Moving average filter select
//                    Diagnosis            : Range (Min to Max)
// Reason for change: 01.00.00 : 25/10/'22 : New Release
// Nickname         : Blue Dragon
/*-- File Header Comment End -------------------------------------------------*/

#include "STLM20W87F.h"

AnalogIn STLM20W87F_adc( iSTLM20W87F_pin , iVref );     // AnalogIn object

// Main Function
pp2ap_adc_t STLM20W87F_00000058( void )
{
        pp2ap_adc_t res = pp_00000058( STLM20W87F_adc , tbl_STLM20W87F );
        return( res );
}
