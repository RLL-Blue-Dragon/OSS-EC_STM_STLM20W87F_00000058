// License       : License.txt
// Specifications: Spec-STLM20W87F.pdf
/*-- File Header Comment Start -----------------------------------------------*/
// File Name        : STLM20W87F.cpp
// Reason for change: 01.00.00 : 25/10/'22 : New Release
// Nickname         : Blue Dragon
/*-- File Header Comment End -------------------------------------------------*/

#include        "STLM20W87F.h"

#if     iSTLM20W87F_ma == iSMA                          // Simple moving average filter
static float32 STLM20W87F_sma_buf[iSTLM20W87F_SMA_num];
static sma_f32_t STLM20W87F_Phy_SMA =
{
        iInitial ,                                      // Initial state
        iSTLM20W87F_SMA_num ,                           // Simple moving average number & buf size
        0U ,                                            // buffer position
        0.0F ,                                          // sum
        &STLM20W87F_sma_buf[0]                          // buffer
};

#elif   iSTLM20W87F_ma == iEMA                          // Exponential moving average filter
static ema_f32_t STLM20W87F_Phy_EMA =
{
        iInitial ,                                      // Initial state
        0.0F ,                                          // Xn-1
        iSTLM20W87F_EMA_K                               // Exponential smoothing factor
};

#elif   iSTLM20W87F_ma == iWMA                          // Weighted moving average filter
static float32 STLM20W87F_wma_buf[iSTLM20W87F_WMA_num];
static wma_f32_t STLM20W87F_Phy_WMA =
{
        iInitial ,                                      // Initial state
        iSTLM20W87F_WMA_num ,                           // Weighted moving average number & buf size
        0U ,                                            // buffer poition
        iSTLM20W87F_WMA_num * (iSTLM20W87F_WMA_num + 1)/2 ,     // kn sum
        &STLM20W87F_wma_buf[0]                          // Xn buffer
};

#else                                                   // Non-moving average filter
#endif

#define iDummy_adr       0xffffffff                     // Dummy address

const tbl_adc_t tbl_STLM20W87F =
{
        iSTLM20W87F             ,
        iSTLM20W87F_pin         ,
        iSTLM20W87F_xoff        ,
        iSTLM20W87F_yoff        ,
        iSTLM20W87F_gain        ,
        iSTLM20W87F_max         ,
        iSTLM20W87F_min         ,
        iSTLM20W87F_ma          ,
        
#if     iSTLM20W87F_ma == iSMA                          // Simple moving average filter
        &STLM20W87F_Phy_SMA     ,
        (ema_f32_t*)iDummy_adr  ,
        (wma_f32_t*)iDummy_adr
#elif   iSTLM20W87F_ma == iEMA                          // Exponential moving average filter
        (sma_f32_t*)iDummy_adr  ,
        &STLM20W87F_Phy_EMA     ,
        (wma_f32_t*)iDummy_adr
#elif   iSTLM20W87F_ma == iWMA                          // Weighted moving average filter
        (sma_f32_t*)iDummy_adr  ,
        (ema_f32_t*)iDummy_adr  ,
        &STLM20W87F_Phy_WMA
#else                                                   // Non-moving average filter
        (sma_f32_t*)iDummy_adr  ,
        (ema_f32_t*)iDummy_adr  ,
        (wma_f32_t*)iDummy_adr
#endif

};
