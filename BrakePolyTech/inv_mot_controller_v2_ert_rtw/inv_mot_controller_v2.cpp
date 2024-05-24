//
// File: inv_mot_controller_v2.cpp
//
// Code generated for Simulink model 'inv_mot_controller_v2'.
//
// Model version                  : 1.4
// Simulink Coder version         : 9.9 (R2023a) 19-Nov-2022
// C/C++ source code generated on : Thu May 23 22:34:38 2024
//
// Target selection: ert.tlc
// Embedded hardware selection: ARM Compatible->ARM Cortex-M
// Code generation objectives:
//    1. Execution efficiency
//    2. RAM efficiency
// Validation result: Not run
//
#include "inv_mot_controller_v2.h"
#include "rtwtypes.h"
#include <cmath>
#include <cfloat>
#include <stddef.h>
#define NumBitsPerChar                 8U

extern real_T rt_atan2d_snf(real_T u0, real_T u1);
extern real_T rt_modd_snf(real_T u0, real_T u1);
extern real_T rt_hypotd_snf(real_T u0, real_T u1);

//===========*
//  Constants *
// ===========
#define RT_PI                          3.14159265358979323846
#define RT_PIF                         3.1415927F
#define RT_LN_10                       2.30258509299404568402
#define RT_LN_10F                      2.3025851F
#define RT_LOG10E                      0.43429448190325182765
#define RT_LOG10EF                     0.43429449F
#define RT_E                           2.7182818284590452354
#define RT_EF                          2.7182817F

//
//  UNUSED_PARAMETER(x)
//    Used to specify that a function parameter (argument) is required but not
//    accessed by the function body.

#ifndef UNUSED_PARAMETER
#if defined(__LCC__)
#define UNUSED_PARAMETER(x)                                      // do nothing
#else

//
//  This is the semi-ANSI standard way of indicating that an
//  unused function parameter is required.

#define UNUSED_PARAMETER(x)            (void) (x)
#endif
#endif

extern "C"
{
  real_T rtInf;
  real_T rtMinusInf;
  real_T rtNaN;
  real32_T rtInfF;
  real32_T rtMinusInfF;
  real32_T rtNaNF;
}

extern "C"
{
  //
  // Initialize rtNaN needed by the generated code.
  // NaN is initialized as non-signaling. Assumes IEEE.
  //
  static real_T rtGetNaN(void)
  {
    size_t bitsPerReal{ sizeof(real_T) * (NumBitsPerChar) };

    real_T nan{ 0.0 };

    if (bitsPerReal == 32U) {
      nan = rtGetNaNF();
    } else {
      union {
        LittleEndianIEEEDouble bitVal;
        real_T fltVal;
      } tmpVal;

      tmpVal.bitVal.words.wordH = 0xFFF80000U;
      tmpVal.bitVal.words.wordL = 0x00000000U;
      nan = tmpVal.fltVal;
    }

    return nan;
  }

  //
  // Initialize rtNaNF needed by the generated code.
  // NaN is initialized as non-signaling. Assumes IEEE.
  //
  static real32_T rtGetNaNF(void)
  {
    IEEESingle nanF{ { 0.0F } };

    nanF.wordL.wordLuint = 0xFFC00000U;
    return nanF.wordL.wordLreal;
  }
}

extern "C"
{
  //
  // Initialize the rtInf, rtMinusInf, and rtNaN needed by the
  // generated code. NaN is initialized as non-signaling. Assumes IEEE.
  //
  static void rt_InitInfAndNaN(size_t realSize)
  {
    (void) (realSize);
    rtNaN = rtGetNaN();
    rtNaNF = rtGetNaNF();
    rtInf = rtGetInf();
    rtInfF = rtGetInfF();
    rtMinusInf = rtGetMinusInf();
    rtMinusInfF = rtGetMinusInfF();
  }

  // Test if value is infinite
  static boolean_T rtIsInf(real_T value)
  {
    return (boolean_T)((value==rtInf || value==rtMinusInf) ? 1U : 0U);
  }

  // Test if single-precision value is infinite
  static boolean_T rtIsInfF(real32_T value)
  {
    return (boolean_T)(((value)==rtInfF || (value)==rtMinusInfF) ? 1U : 0U);
  }

  // Test if value is not a number
  static boolean_T rtIsNaN(real_T value)
  {
    boolean_T result{ (boolean_T) 0 };

    size_t bitsPerReal{ sizeof(real_T) * (NumBitsPerChar) };

    if (bitsPerReal == 32U) {
      result = rtIsNaNF((real32_T)value);
    } else {
      union {
        LittleEndianIEEEDouble bitVal;
        real_T fltVal;
      } tmpVal;

      tmpVal.fltVal = value;
      result = (boolean_T)((tmpVal.bitVal.words.wordH & 0x7FF00000) ==
                           0x7FF00000 &&
                           ( (tmpVal.bitVal.words.wordH & 0x000FFFFF) != 0 ||
                            (tmpVal.bitVal.words.wordL != 0) ));
    }

    return result;
  }

  // Test if single-precision value is not a number
  static boolean_T rtIsNaNF(real32_T value)
  {
    IEEESingle tmp;
    tmp.wordL.wordLreal = value;
    return (boolean_T)( (tmp.wordL.wordLuint & 0x7F800000) == 0x7F800000 &&
                       (tmp.wordL.wordLuint & 0x007FFFFF) != 0 );
  }
}

extern "C"
{
  //
  // Initialize rtInf needed by the generated code.
  // Inf is initialized as non-signaling. Assumes IEEE.
  //
  static real_T rtGetInf(void)
  {
    size_t bitsPerReal{ sizeof(real_T) * (NumBitsPerChar) };

    real_T inf{ 0.0 };

    if (bitsPerReal == 32U) {
      inf = rtGetInfF();
    } else {
      union {
        LittleEndianIEEEDouble bitVal;
        real_T fltVal;
      } tmpVal;

      tmpVal.bitVal.words.wordH = 0x7FF00000U;
      tmpVal.bitVal.words.wordL = 0x00000000U;
      inf = tmpVal.fltVal;
    }

    return inf;
  }

  //
  // Initialize rtInfF needed by the generated code.
  // Inf is initialized as non-signaling. Assumes IEEE.
  //
  static real32_T rtGetInfF(void)
  {
    IEEESingle infF;
    infF.wordL.wordLuint = 0x7F800000U;
    return infF.wordL.wordLreal;
  }

  //
  // Initialize rtMinusInf needed by the generated code.
  // Inf is initialized as non-signaling. Assumes IEEE.
  //
  static real_T rtGetMinusInf(void)
  {
    size_t bitsPerReal{ sizeof(real_T) * (NumBitsPerChar) };

    real_T minf{ 0.0 };

    if (bitsPerReal == 32U) {
      minf = rtGetMinusInfF();
    } else {
      union {
        LittleEndianIEEEDouble bitVal;
        real_T fltVal;
      } tmpVal;

      tmpVal.bitVal.words.wordH = 0xFFF00000U;
      tmpVal.bitVal.words.wordL = 0x00000000U;
      minf = tmpVal.fltVal;
    }

    return minf;
  }

  //
  // Initialize rtMinusInfF needed by the generated code.
  // Inf is initialized as non-signaling. Assumes IEEE.
  //
  static real32_T rtGetMinusInfF(void)
  {
    IEEESingle minfF;
    minfF.wordL.wordLuint = 0xFF800000U;
    return minfF.wordL.wordLreal;
  }
}

real_T rt_atan2d_snf(real_T u0, real_T u1)
{
  real_T y;
  if (std::isnan(u0) || std::isnan(u1)) {
    y = (rtNaN);
  } else if (std::isinf(u0) && std::isinf(u1)) {
    int32_T tmp;
    int32_T tmp_0;
    if (u0 > 0.0) {
      tmp = 1;
    } else {
      tmp = -1;
    }

    if (u1 > 0.0) {
      tmp_0 = 1;
    } else {
      tmp_0 = -1;
    }

    y = std::atan2(static_cast<real_T>(tmp), static_cast<real_T>(tmp_0));
  } else if (u1 == 0.0) {
    if (u0 > 0.0) {
      y = RT_PI / 2.0;
    } else if (u0 < 0.0) {
      y = -(RT_PI / 2.0);
    } else {
      y = 0.0;
    }
  } else {
    y = std::atan2(u0, u1);
  }

  return y;
}

real_T rt_modd_snf(real_T u0, real_T u1)
{
  real_T y;
  y = u0;
  if (u1 == 0.0) {
    if (u0 == 0.0) {
      y = u1;
    }
  } else if (std::isnan(u0) || std::isnan(u1) || std::isinf(u0)) {
    y = (rtNaN);
  } else if (u0 == 0.0) {
    y = 0.0 / u1;
  } else if (std::isinf(u1)) {
    if ((u1 < 0.0) != (u0 < 0.0)) {
      y = u1;
    }
  } else {
    boolean_T yEq;
    y = std::fmod(u0, u1);
    yEq = (y == 0.0);
    if ((!yEq) && (u1 > std::floor(u1))) {
      real_T q;
      q = std::abs(u0 / u1);
      yEq = !(std::abs(q - std::floor(q + 0.5)) > DBL_EPSILON * q);
    }

    if (yEq) {
      y = u1 * 0.0;
    } else if ((u0 < 0.0) != (u1 < 0.0)) {
      y += u1;
    }
  }

  return y;
}

real_T rt_hypotd_snf(real_T u0, real_T u1)
{
  real_T a;
  real_T b;
  real_T y;
  a = std::abs(u0);
  b = std::abs(u1);
  if (a < b) {
    a /= b;
    y = std::sqrt(a * a + 1.0) * b;
  } else if (a > b) {
    b /= a;
    y = std::sqrt(b * b + 1.0) * a;
  } else if (std::isnan(b)) {
    y = (rtNaN);
  } else {
    y = a * 1.4142135623730951;
  }

  return y;
}

// Model step function
void inv_mot_controller_v2::step()
{
  real_T rtb_Add1;
  real_T rtb_Cos;
  real_T rtb_DeadZone;
  real_T rtb_DeadZone_n;
  real_T rtb_Diff;
  real_T rtb_IntegralGain;
  real_T rtb_IntegralGain_b;
  real_T rtb_IntegralGain_e;
  real_T rtb_Integrator_m;
  real_T rtb_Saturation;
  real_T rtb_Sin;
  real_T rtb_Switch_o_idx_0;
  real_T rtb_Switch_o_idx_0_tmp;
  int32_T n;
  int8_T tmp;
  int8_T tmp_0;
  boolean_T rtb_Compare_d;
  boolean_T rtb_NOT;

  // Gain: '<Root>/Gain' incorporates:
  //   Inport: '<Root>/RotorAngle'

  rtb_IntegralGain = 4.0 * rtU.RotorAngle;

  // Trigonometry: '<Root>/Sin'
  rtb_Sin = std::sin(rtb_IntegralGain);

  // Trigonometry: '<Root>/Cos'
  rtb_Cos = std::cos(rtb_IntegralGain);

  // Outputs for Atomic SubSystem: '<Root>/Clarke Transform'
  // Gain: '<S2>/one_by_sqrt3' incorporates:
  //   Inport: '<Root>/Ia'
  //   Inport: '<Root>/Ib'
  //   Sum: '<S2>/a_plus_2b'

  rtb_IntegralGain = ((rtU.Ia + rtU.Ib) + rtU.Ib) * 0.57735026918962584;

  // Outputs for Atomic SubSystem: '<Root>/Park Transform'
  // Sum: '<S13>/sum_Ds' incorporates:
  //   AlgorithmDescriptorDelegate generated from: '<S2>/a16'
  //   Inport: '<Root>/Ia'
  //   Product: '<S13>/acos'
  //   Product: '<S13>/bsin'

  rtb_Switch_o_idx_0_tmp = rtU.Ia * rtb_Cos + rtb_IntegralGain * rtb_Sin;

  // End of Outputs for SubSystem: '<Root>/Clarke Transform'

  // Sum: '<S163>/Sum' incorporates:
  //   Constant: '<Root>/Constant3'
  //   DiscreteIntegrator: '<S154>/Integrator'
  //   Gain: '<S159>/Proportional Gain'
  //   Sum: '<Root>/Sum'
  //   Sum: '<S13>/sum_Ds'

  rtb_DeadZone = (0.0 - rtb_Switch_o_idx_0_tmp) * 0.15 + rtDW.Integrator_DSTATE;

  // End of Outputs for SubSystem: '<Root>/Park Transform'

  // Saturate: '<S161>/Saturation'
  if (rtb_DeadZone > 15.0) {
    rtb_Saturation = 15.0;
  } else if (rtb_DeadZone < -15.0) {
    rtb_Saturation = -15.0;
  } else {
    rtb_Saturation = rtb_DeadZone;
  }

  // End of Saturate: '<S161>/Saturation'

  // Product: '<Root>/Product' incorporates:
  //   Gain: '<Root>/Gain2'
  //   Inport: '<Root>/CurrentLimit'
  //   Inport: '<Root>/pedal'

  rtb_Diff = 0.01 * rtU.pedal * rtU.CurrentLimit;

  // RelationalOperator: '<S6>/Compare' incorporates:
  //   Constant: '<S6>/Constant'

  rtb_Compare_d = (rtb_Diff <= 0.0);

  // Logic: '<Root>/NOT'
  rtb_NOT = !rtb_Compare_d;

  // DiscreteIntegrator: '<Root>/Discrete-Time Integrator' incorporates:
  //   DataTypeConversion: '<Root>/Data Type Conversion'

  if (rtb_NOT && (rtDW.DiscreteTimeIntegrator_PrevRese <= 0)) {
    rtDW.DiscreteTimeIntegrator_DSTATE = 0.0;
  }

  // Switch: '<Root>/Switch1' incorporates:
  //   Constant: '<S3>/Constant'
  //   Constant: '<S5>/Constant'
  //   DiscreteIntegrator: '<Root>/Discrete-Time Integrator'
  //   Inport: '<Root>/RotationAngle'
  //   Inport: '<Root>/Speed'
  //   Logic: '<Root>/AND'
  //   RelationalOperator: '<S3>/Compare'
  //   RelationalOperator: '<S5>/Compare'

  if ((!(rtU.Speed <= 0.1)) || (!(rtDW.DiscreteTimeIntegrator_DSTATE >= 0.01)))
  {
    rtb_Diff = rtU.RotationAngle;
  }

  // End of Switch: '<Root>/Switch1'

  // Gain: '<S207>/Proportional Gain' incorporates:
  //   Inport: '<Root>/ReturnAngle'
  //   Inport: '<Root>/RotorAngle'
  //   Quantizer: '<Root>/Quantizer'
  //   Sum: '<Root>/Sum4'

  rtb_Integrator_m = std::round((rtU.ReturnAngle - rtU.RotorAngle) / 0.1) * 0.1 *
    50.0;

  // Saturate: '<S209>/Saturation'
  if (rtb_Integrator_m > 35.0) {
    rtb_Integrator_m = 35.0;
  } else if (rtb_Integrator_m < -315.0) {
    rtb_Integrator_m = -315.0;
  }

  // End of Saturate: '<S209>/Saturation'

  // Sum: '<S17>/Add1' incorporates:
  //   Constant: '<S17>/Filter_Constant'
  //   Constant: '<S17>/One'
  //   Inport: '<Root>/Speed'
  //   Product: '<S17>/Product'
  //   Product: '<S17>/Product1'
  //   UnitDelay: '<S17>/Unit Delay'

  rtb_Add1 = rtU.Speed * 0.7 + 0.30000000000000004 * rtDW.UnitDelay_DSTATE;

  // Switch: '<Root>/Switch' incorporates:
  //   Inport: '<Root>/TargerBreakSpeed'

  if (rtb_Compare_d) {
    rtb_Switch_o_idx_0 = rtb_Integrator_m;
  } else {
    rtb_Switch_o_idx_0 = rtU.TargerBreakSpeed;
  }

  // Sum: '<Root>/Sum3' incorporates:
  //   Switch: '<Root>/Switch'

  rtb_IntegralGain_e = rtb_Switch_o_idx_0 - rtb_Add1;

  // RelationalOperator: '<S4>/Compare' incorporates:
  //   Constant: '<S4>/Constant'

  rtb_Compare_d = (rtb_Integrator_m <= -0.1);

  // DiscreteIntegrator: '<S103>/Integrator'
  if ((!rtb_Compare_d) && (rtDW.Integrator_PrevResetState == 1)) {
    rtDW.Integrator_DSTATE_m = 0.0;
  }

  // Sum: '<S113>/Sum' incorporates:
  //   DiscreteIntegrator: '<S103>/Integrator'
  //   Gain: '<S108>/Proportional Gain'

  rtb_Integrator_m = 0.6 * rtb_IntegralGain_e + rtDW.Integrator_DSTATE_m;

  // Switch: '<S111>/Switch2' incorporates:
  //   Inport: '<Root>/ReturnCurrentLimit'
  //   RelationalOperator: '<S111>/LowerRelop1'
  //   RelationalOperator: '<S111>/UpperRelop'
  //   Switch: '<S111>/Switch'

  if (rtb_Integrator_m > rtb_Diff) {
    rtb_Switch_o_idx_0 = rtb_Diff;
  } else if (rtb_Integrator_m < rtU.ReturnCurrentLimit) {
    // Switch: '<S111>/Switch' incorporates:
    //   Inport: '<Root>/ReturnCurrentLimit'

    rtb_Switch_o_idx_0 = rtU.ReturnCurrentLimit;
  } else {
    rtb_Switch_o_idx_0 = rtb_Integrator_m;
  }

  // Outputs for Atomic SubSystem: '<Root>/Park Transform'
  // Outputs for Atomic SubSystem: '<Root>/Clarke Transform'
  // Sum: '<Root>/Sum1' incorporates:
  //   AlgorithmDescriptorDelegate generated from: '<S2>/a16'
  //   Inport: '<Root>/Ia'
  //   Product: '<S13>/asin'
  //   Product: '<S13>/bcos'
  //   Sum: '<S13>/sum_Qs'
  //   Switch: '<S111>/Switch2'

  rtb_IntegralGain_b = rtb_Switch_o_idx_0 - (rtb_IntegralGain * rtb_Cos - rtU.Ia
    * rtb_Sin);

  // End of Outputs for SubSystem: '<Root>/Clarke Transform'
  // End of Outputs for SubSystem: '<Root>/Park Transform'

  // Sum: '<S61>/Sum' incorporates:
  //   DiscreteIntegrator: '<S52>/Integrator'
  //   Gain: '<S57>/Proportional Gain'

  rtb_DeadZone_n = 0.15 * rtb_IntegralGain_b + rtDW.Integrator_DSTATE_j;

  // Saturate: '<S59>/Saturation'
  if (rtb_DeadZone_n > 15.0) {
    rtb_Switch_o_idx_0 = 15.0;
  } else if (rtb_DeadZone_n < -15.0) {
    rtb_Switch_o_idx_0 = -15.0;
  } else {
    rtb_Switch_o_idx_0 = rtb_DeadZone_n;
  }

  // Sum: '<Root>/Sum2' incorporates:
  //   Gain: '<Root>/Gain1'
  //   Saturate: '<S59>/Saturation'

  rtb_IntegralGain = 0.0376432375511636 * rtb_Add1 + rtb_Switch_o_idx_0;

  // Outputs for Atomic SubSystem: '<Root>/Inverse Park Transform'
  // Switch: '<S18>/Switch' incorporates:
  //   Product: '<S8>/dcos'
  //   Product: '<S8>/dsin'
  //   Product: '<S8>/qcos'
  //   Product: '<S8>/qsin'
  //   Sum: '<S8>/sum_alpha'
  //   Sum: '<S8>/sum_beta'

  rtb_Switch_o_idx_0 = rtb_Saturation * rtb_Cos - rtb_IntegralGain * rtb_Sin;
  rtb_Sin = rtb_IntegralGain * rtb_Cos + rtb_Saturation * rtb_Sin;

  // Math: '<Root>/Mod' incorporates:
  //   AlgorithmDescriptorDelegate generated from: '<S8>/a16'
  //   Constant: '<Root>/Constant'
  //   Fcn: '<S1>/x->theta'

  rtb_Cos = rt_modd_snf(rt_atan2d_snf(rtb_Sin, rtb_Switch_o_idx_0),
                        6.2831853071795862);

  // End of Outputs for SubSystem: '<Root>/Inverse Park Transform'

  // MATLAB Function: '<Root>/SVPWM' incorporates:
  //   AlgorithmDescriptorDelegate generated from: '<S8>/a16'
  //   Fcn: '<S1>/x->r'
  //   Inport: '<Root>/Ia'
  //   Inport: '<Root>/Ib'
  //   Inport: '<Root>/VDC'

  if ((rtb_Cos >= 0.0) && (rtb_Cos < 1.0471975511965976)) {
    n = 1;
  } else if ((rtb_Cos >= 1.0471975511965976) && (rtb_Cos < 2.0943951023931953))
  {
    n = 2;
  } else if ((rtb_Cos >= 2.0943951023931953) && (rtb_Cos < 3.1415926535897931))
  {
    n = 3;
  } else if ((rtb_Cos >= 3.1415926535897931) && (rtb_Cos < 4.1887902047863905))
  {
    n = 4;
  } else if ((rtb_Cos >= 4.1887902047863905) && (rtb_Cos < 5.2359877559829888))
  {
    n = 5;
  } else {
    n = 6;
  }

  rtb_Saturation = rtb_Cos - (static_cast<real_T>(n) - 1.0) * 3.1415926535897931
    / 3.0;

  // Outputs for Atomic SubSystem: '<Root>/Inverse Park Transform'
  rtb_Sin = rt_hypotd_snf(rtb_Switch_o_idx_0, rtb_Sin) / rtU.VDC;

  // End of Outputs for SubSystem: '<Root>/Inverse Park Transform'
  rtb_Cos = std::sin(1.0471975511965976 - rtb_Saturation) * rtb_Sin /
    0.8660254037844386;
  rtb_Saturation = rtb_Sin * std::sin(rtb_Saturation) / 0.8660254037844386;
  rtb_Switch_o_idx_0 = (1.0 - rtb_Cos) - rtb_Saturation;
  switch (n) {
   case 1:
    rtb_IntegralGain = (rtb_Cos + rtb_Saturation) + rtb_Switch_o_idx_0 / 2.0;
    rtb_Sin = rtb_Switch_o_idx_0 / 2.0 + rtb_Saturation;
    rtb_Saturation = rtb_Switch_o_idx_0 / 2.0;
    break;

   case 2:
    rtb_IntegralGain = rtb_Switch_o_idx_0 / 2.0 + rtb_Cos;
    rtb_Sin = (rtb_Cos + rtb_Saturation) + rtb_Switch_o_idx_0 / 2.0;
    rtb_Saturation = rtb_Switch_o_idx_0 / 2.0;
    break;

   case 3:
    rtb_IntegralGain = rtb_Switch_o_idx_0 / 2.0;
    rtb_Sin = (rtb_Cos + rtb_Saturation) + rtb_Switch_o_idx_0 / 2.0;
    rtb_Saturation += rtb_Switch_o_idx_0 / 2.0;
    break;

   case 4:
    rtb_IntegralGain = rtb_Switch_o_idx_0 / 2.0;
    rtb_Sin = rtb_Switch_o_idx_0 / 2.0 + rtb_Cos;
    rtb_Saturation = (rtb_Cos + rtb_Saturation) + rtb_Switch_o_idx_0 / 2.0;
    break;

   case 5:
    rtb_IntegralGain = rtb_Switch_o_idx_0 / 2.0 + rtb_Saturation;
    rtb_Sin = rtb_Switch_o_idx_0 / 2.0;
    rtb_Saturation = (rtb_Cos + rtb_Saturation) + rtb_Switch_o_idx_0 / 2.0;
    break;

   default:
    rtb_IntegralGain = (rtb_Cos + rtb_Saturation) + rtb_Switch_o_idx_0 / 2.0;
    rtb_Sin = rtb_Switch_o_idx_0 / 2.0;
    rtb_Saturation = rtb_Switch_o_idx_0 / 2.0 + rtb_Cos;
    break;
  }

  if (rtb_IntegralGain > 0.95) {
    rtb_IntegralGain = 0.95;
  } else if (rtb_IntegralGain < 0.05) {
    rtb_IntegralGain = 0.05;
  }

  if (rtb_Sin > 0.95) {
    rtb_Sin = 0.95;
  } else if (rtb_Sin < 0.05) {
    rtb_Sin = 0.05;
  }

  if (rtb_Saturation > 0.95) {
    rtb_Saturation = 0.95;
  } else if (rtb_Saturation < 0.05) {
    rtb_Saturation = 0.05;
  }

  if (rtU.Ia > 0.0) {
    // Outport: '<Root>/Ts1'
    rtY.Ts1 = (rtb_IntegralGain - 0.0046875) + 0.0046875;

    // Outport: '<Root>/Ts2'
    rtY.Ts2 = (rtb_IntegralGain + 0.0046875) + 0.0046875;
  } else {
    // Outport: '<Root>/Ts1'
    rtY.Ts1 = (rtb_IntegralGain - 0.0046875) - 0.0046875;

    // Outport: '<Root>/Ts2'
    rtY.Ts2 = (rtb_IntegralGain + 0.0046875) - 0.0046875;
  }

  if (rtU.Ib > 0.0) {
    // Outport: '<Root>/Ts3'
    rtY.Ts3 = (rtb_Sin - 0.0046875) + 0.0046875;

    // Outport: '<Root>/Ts4'
    rtY.Ts4 = (rtb_Sin + 0.0046875) + 0.0046875;
  } else {
    // Outport: '<Root>/Ts3'
    rtY.Ts3 = (rtb_Sin - 0.0046875) - 0.0046875;

    // Outport: '<Root>/Ts4'
    rtY.Ts4 = (rtb_Sin + 0.0046875) - 0.0046875;
  }

  if (-rtU.Ia - rtU.Ib > 0.0) {
    // Outport: '<Root>/Ts5'
    rtY.Ts5 = (rtb_Saturation - 0.0046875) + 0.0046875;

    // Outport: '<Root>/Ts6'
    rtY.Ts6 = (rtb_Saturation + 0.0046875) + 0.0046875;
  } else {
    // Outport: '<Root>/Ts5'
    rtY.Ts5 = (rtb_Saturation - 0.0046875) - 0.0046875;

    // Outport: '<Root>/Ts6'
    rtY.Ts6 = (rtb_Saturation + 0.0046875) - 0.0046875;
  }

  // End of MATLAB Function: '<Root>/SVPWM'

  // DeadZone: '<S45>/DeadZone'
  if (rtb_DeadZone_n > 15.0) {
    rtb_DeadZone_n -= 15.0;
  } else if (rtb_DeadZone_n >= -15.0) {
    rtb_DeadZone_n = 0.0;
  } else {
    rtb_DeadZone_n -= -15.0;
  }

  // End of DeadZone: '<S45>/DeadZone'

  // Gain: '<S49>/Integral Gain'
  rtb_IntegralGain_b *= 89.85;

  // Switch: '<S96>/Switch' incorporates:
  //   RelationalOperator: '<S96>/u_GTE_up'

  if (!(rtb_Integrator_m >= rtb_Diff)) {
    // Switch: '<S96>/Switch1' incorporates:
    //   Inport: '<Root>/ReturnCurrentLimit'
    //   RelationalOperator: '<S96>/u_GT_lo'

    if (rtb_Integrator_m > rtU.ReturnCurrentLimit) {
      rtb_Diff = rtb_Integrator_m;
    } else {
      rtb_Diff = rtU.ReturnCurrentLimit;
    }

    // End of Switch: '<S96>/Switch1'
  }

  // End of Switch: '<S96>/Switch'

  // Sum: '<S96>/Diff'
  rtb_Diff = rtb_Integrator_m - rtb_Diff;

  // DeadZone: '<S147>/DeadZone'
  if (rtb_DeadZone > 15.0) {
    rtb_DeadZone -= 15.0;
  } else if (rtb_DeadZone >= -15.0) {
    rtb_DeadZone = 0.0;
  } else {
    rtb_DeadZone -= -15.0;
  }

  // End of DeadZone: '<S147>/DeadZone'

  // Outputs for Atomic SubSystem: '<Root>/Park Transform'
  // Gain: '<S151>/Integral Gain' incorporates:
  //   Constant: '<Root>/Constant3'
  //   Sum: '<Root>/Sum'

  rtb_IntegralGain = (0.0 - rtb_Switch_o_idx_0_tmp) * 89.85;

  // End of Outputs for SubSystem: '<Root>/Park Transform'

  // Switch: '<S145>/Switch1' incorporates:
  //   Constant: '<S145>/Clamping_zero'
  //   Constant: '<S145>/Constant'
  //   Constant: '<S145>/Constant2'
  //   RelationalOperator: '<S145>/fix for DT propagation issue'

  if (rtb_DeadZone > 0.0) {
    tmp = 1;
  } else {
    tmp = -1;
  }

  // Switch: '<S145>/Switch2' incorporates:
  //   Constant: '<S145>/Clamping_zero'
  //   Constant: '<S145>/Constant3'
  //   Constant: '<S145>/Constant4'
  //   RelationalOperator: '<S145>/fix for DT propagation issue1'

  if (rtb_IntegralGain > 0.0) {
    tmp_0 = 1;
  } else {
    tmp_0 = -1;
  }

  // Switch: '<S145>/Switch' incorporates:
  //   Constant: '<S145>/Clamping_zero'
  //   Constant: '<S145>/Constant1'
  //   Logic: '<S145>/AND3'
  //   RelationalOperator: '<S145>/Equal1'
  //   RelationalOperator: '<S145>/Relational Operator'
  //   Switch: '<S145>/Switch1'
  //   Switch: '<S145>/Switch2'

  if ((rtb_DeadZone != 0.0) && (tmp == tmp_0)) {
    rtb_IntegralGain = 0.0;
  }

  // Update for DiscreteIntegrator: '<S154>/Integrator' incorporates:
  //   Switch: '<S145>/Switch'

  rtDW.Integrator_DSTATE += 8.0E-5 * rtb_IntegralGain;

  // Update for DiscreteIntegrator: '<Root>/Discrete-Time Integrator' incorporates:
  //   DataTypeConversion: '<Root>/Data Type Conversion'

  rtDW.DiscreteTimeIntegrator_DSTATE += 8.0E-5 * static_cast<real_T>(rtb_NOT);
  if (rtb_NOT) {
    rtDW.DiscreteTimeIntegrator_PrevRese = 1;
  } else {
    rtDW.DiscreteTimeIntegrator_PrevRese = 0;
  }

  // End of Update for DiscreteIntegrator: '<Root>/Discrete-Time Integrator'

  // Update for UnitDelay: '<S17>/Unit Delay'
  rtDW.UnitDelay_DSTATE = rtb_Add1;

  // Switch: '<S93>/Switch1' incorporates:
  //   Constant: '<S93>/Clamping_zero'
  //   Constant: '<S93>/Constant'
  //   Constant: '<S93>/Constant2'
  //   RelationalOperator: '<S93>/fix for DT propagation issue'

  if (rtb_Diff > 0.0) {
    tmp = 1;
  } else {
    tmp = -1;
  }

  // Switch: '<S93>/Switch' incorporates:
  //   Constant: '<S93>/Clamping_zero'
  //   Constant: '<S93>/Constant1'
  //   Gain: '<S100>/Integral Gain'
  //   Logic: '<S93>/AND3'
  //   RelationalOperator: '<S93>/Equal1'
  //   RelationalOperator: '<S93>/Relational Operator'
  //   Switch: '<S93>/Switch1'
  //   Switch: '<S93>/Switch2'

  if ((rtb_Diff != 0.0) && (tmp == -1)) {
    rtb_Switch_o_idx_0 = 0.0;
  } else {
    rtb_Switch_o_idx_0 = 0.0 * rtb_IntegralGain_e;
  }

  // Update for DiscreteIntegrator: '<S103>/Integrator' incorporates:
  //   Switch: '<S93>/Switch'

  rtDW.Integrator_DSTATE_m += 8.0E-5 * rtb_Switch_o_idx_0;
  rtDW.Integrator_PrevResetState = static_cast<int8_T>(rtb_Compare_d);

  // Switch: '<S43>/Switch1' incorporates:
  //   Constant: '<S43>/Clamping_zero'
  //   Constant: '<S43>/Constant'
  //   Constant: '<S43>/Constant2'
  //   RelationalOperator: '<S43>/fix for DT propagation issue'

  if (rtb_DeadZone_n > 0.0) {
    tmp = 1;
  } else {
    tmp = -1;
  }

  // Switch: '<S43>/Switch2' incorporates:
  //   Constant: '<S43>/Clamping_zero'
  //   Constant: '<S43>/Constant3'
  //   Constant: '<S43>/Constant4'
  //   RelationalOperator: '<S43>/fix for DT propagation issue1'

  if (rtb_IntegralGain_b > 0.0) {
    tmp_0 = 1;
  } else {
    tmp_0 = -1;
  }

  // Switch: '<S43>/Switch' incorporates:
  //   Constant: '<S43>/Clamping_zero'
  //   Constant: '<S43>/Constant1'
  //   Logic: '<S43>/AND3'
  //   RelationalOperator: '<S43>/Equal1'
  //   RelationalOperator: '<S43>/Relational Operator'
  //   Switch: '<S43>/Switch1'
  //   Switch: '<S43>/Switch2'

  if ((rtb_DeadZone_n != 0.0) && (tmp == tmp_0)) {
    rtb_IntegralGain_b = 0.0;
  }

  // Update for DiscreteIntegrator: '<S52>/Integrator' incorporates:
  //   Switch: '<S43>/Switch'

  rtDW.Integrator_DSTATE_j += 8.0E-5 * rtb_IntegralGain_b;
}

// Model initialize function
void inv_mot_controller_v2::initialize()
{
  // Registration code

  // initialize non-finites
  rt_InitInfAndNaN(sizeof(real_T));

  // InitializeConditions for DiscreteIntegrator: '<Root>/Discrete-Time Integrator' 
  rtDW.DiscreteTimeIntegrator_PrevRese = 2;

  // InitializeConditions for DiscreteIntegrator: '<S103>/Integrator'
  rtDW.Integrator_PrevResetState = 2;
}

// Constructor
inv_mot_controller_v2::inv_mot_controller_v2() :
  rtU(),
  rtY(),
  rtDW(),
  rtM()
{
  // Currently there is no constructor body generated.
}

// Destructor
// Currently there is no destructor body generated.
inv_mot_controller_v2::~inv_mot_controller_v2() = default;

// Real-Time Model get method
inv_mot_controller_v2::RT_MODEL * inv_mot_controller_v2::getRTM()
{
  return (&rtM);
}

//
// File trailer for generated code.
//
// [EOF]
//
