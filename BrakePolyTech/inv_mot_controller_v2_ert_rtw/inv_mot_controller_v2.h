//
// File: inv_mot_controller_v2.h
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
#ifndef RTW_HEADER_inv_mot_controller_v2_h_
#define RTW_HEADER_inv_mot_controller_v2_h_
#include "rtwtypes.h"
#include <stddef.h>

// Macros for accessing real-time model data structure
#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

extern "C"
{
  static real_T rtGetNaN(void);
  static real32_T rtGetNaNF(void);
}                                      // extern "C"

#define NOT_USING_NONFINITE_LITERALS   1

extern "C"
{
  extern real_T rtInf;
  extern real_T rtMinusInf;
  extern real_T rtNaN;
  extern real32_T rtInfF;
  extern real32_T rtMinusInfF;
  extern real32_T rtNaNF;
  static void rt_InitInfAndNaN(size_t realSize);
  static boolean_T rtIsInf(real_T value);
  static boolean_T rtIsInfF(real32_T value);
  static boolean_T rtIsNaN(real_T value);
  static boolean_T rtIsNaNF(real32_T value);
  struct BigEndianIEEEDouble {
    struct {
      uint32_T wordH;
      uint32_T wordL;
    } words;
  };

  struct LittleEndianIEEEDouble {
    struct {
      uint32_T wordL;
      uint32_T wordH;
    } words;
  };

  struct IEEESingle {
    union {
      real32_T wordLreal;
      uint32_T wordLuint;
    } wordL;
  };
}                                      // extern "C"

extern "C"
{
  static real_T rtGetInf(void);
  static real32_T rtGetInfF(void);
  static real_T rtGetMinusInf(void);
  static real32_T rtGetMinusInfF(void);
}                                      // extern "C"

// Class declaration for model inv_mot_controller_v2
class inv_mot_controller_v2 final
{
  // public data and function members
 public:
  // Block signals and states (default storage) for system '<Root>'
  struct DW {
    real_T Integrator_DSTATE;          // '<S154>/Integrator'
    real_T DiscreteTimeIntegrator_DSTATE;// '<Root>/Discrete-Time Integrator'
    real_T UnitDelay_DSTATE;           // '<S17>/Unit Delay'
    real_T Integrator_DSTATE_m;        // '<S103>/Integrator'
    real_T Integrator_DSTATE_j;        // '<S52>/Integrator'
    int8_T DiscreteTimeIntegrator_PrevRese;// '<Root>/Discrete-Time Integrator'
    int8_T Integrator_PrevResetState;  // '<S103>/Integrator'
  };

  // External inputs (root inport signals with default storage)
  struct ExtU {
    real_T Ia;                         // '<Root>/Ia'
    real_T Ib;                         // '<Root>/Ib'
    real_T TargerBreakSpeed;           // '<Root>/TargerBreakSpeed'
    real_T pedal;                      // '<Root>/pedal'
    real_T CurrentLimit;               // '<Root>/CurrentLimit'
    real_T ReturnAngle;                // '<Root>/ReturnAngle'
    real_T RotorAngle;                 // '<Root>/RotorAngle'
    real_T RotationAngle;              // '<Root>/RotationAngle'
    real_T Speed;                      // '<Root>/Speed'
    real_T ReturnCurrentLimit;         // '<Root>/ReturnCurrentLimit'
    real_T VDC;                        // '<Root>/VDC'
  };

  // External outputs (root outports fed by signals with default storage)
  struct ExtY {
    real_T Ts1;                        // '<Root>/Ts1'
    real_T Ts2;                        // '<Root>/Ts2'
    real_T Ts3;                        // '<Root>/Ts3'
    real_T Ts4;                        // '<Root>/Ts4'
    real_T Ts5;                        // '<Root>/Ts5'
    real_T Ts6;                        // '<Root>/Ts6'
  };

  // Real-time Model Data Structure
  struct RT_MODEL {
    const char_T * volatile errorStatus;
  };

  // Copy Constructor
  inv_mot_controller_v2(inv_mot_controller_v2 const&) = delete;

  // Assignment Operator
  inv_mot_controller_v2& operator= (inv_mot_controller_v2 const&) & = delete;

  // Move Constructor
  inv_mot_controller_v2(inv_mot_controller_v2 &&) = delete;

  // Move Assignment Operator
  inv_mot_controller_v2& operator= (inv_mot_controller_v2 &&) = delete;

  // Real-Time Model get method
  inv_mot_controller_v2::RT_MODEL * getRTM();

  // External inputs
  ExtU rtU;

  // External outputs
  ExtY rtY;

  // model initialize function
  void initialize();

  // model step function
  void step();

  // Constructor
  inv_mot_controller_v2();

  // Destructor
  ~inv_mot_controller_v2();

  // private data and function members
 private:
  // Block states
  DW rtDW;

  // Real-Time Model
  RT_MODEL rtM;
};

//-
//  These blocks were eliminated from the model due to optimizations:
//
//  Block '<S2>/Data Type Duplicate' : Unused code path elimination
//  Block '<S17>/Data Type Duplicate' : Unused code path elimination
//  Block '<S8>/Data Type Duplicate' : Unused code path elimination
//  Block '<S8>/Data Type Duplicate1' : Unused code path elimination
//  Block '<S111>/Data Type Duplicate' : Unused code path elimination
//  Block '<S111>/Data Type Propagation' : Unused code path elimination
//  Block '<S13>/Data Type Duplicate' : Unused code path elimination
//  Block '<S13>/Data Type Duplicate1' : Unused code path elimination
//  Block '<Root>/Scope3' : Unused code path elimination
//  Block '<Root>/Scope5' : Unused code path elimination
//  Block '<Root>/Scope6' : Unused code path elimination
//  Block '<Root>/Scope7' : Unused code path elimination
//  Block '<S18>/Offset' : Unused code path elimination
//  Block '<S18>/Unary_Minus' : Unused code path elimination
//  Block '<S219>/Offset' : Unused code path elimination
//  Block '<S219>/Unary_Minus' : Unused code path elimination


//-
//  The generated code includes comments that allow you to trace directly
//  back to the appropriate location in the model.  The basic format
//  is <system>/block_name, where system is the system number (uniquely
//  assigned by Simulink) and block_name is the name of the block.
//
//  Use the MATLAB hilite_system command to trace the generated code back
//  to the model.  For example,
//
//  hilite_system('<S3>')    - opens system 3
//  hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
//
//  Here is the system hierarchy for this model
//
//  '<Root>' : 'inv_mot_controller_v2'
//  '<S1>'   : 'inv_mot_controller_v2/Cartesian to Polar'
//  '<S2>'   : 'inv_mot_controller_v2/Clarke Transform'
//  '<S3>'   : 'inv_mot_controller_v2/Compare To Constant'
//  '<S4>'   : 'inv_mot_controller_v2/Compare To Constant1'
//  '<S5>'   : 'inv_mot_controller_v2/Compare To Constant2'
//  '<S6>'   : 'inv_mot_controller_v2/Compare To Zero'
//  '<S7>'   : 'inv_mot_controller_v2/IIR Filter'
//  '<S8>'   : 'inv_mot_controller_v2/Inverse Park Transform'
//  '<S9>'   : 'inv_mot_controller_v2/PID Controller1'
//  '<S10>'  : 'inv_mot_controller_v2/PID Controller2'
//  '<S11>'  : 'inv_mot_controller_v2/PID Controller3'
//  '<S12>'  : 'inv_mot_controller_v2/PID Controller4'
//  '<S13>'  : 'inv_mot_controller_v2/Park Transform'
//  '<S14>'  : 'inv_mot_controller_v2/SVPWM'
//  '<S15>'  : 'inv_mot_controller_v2/IIR Filter/IIR Filter'
//  '<S16>'  : 'inv_mot_controller_v2/IIR Filter/IIR Filter/Low-pass'
//  '<S17>'  : 'inv_mot_controller_v2/IIR Filter/IIR Filter/Low-pass/IIR Low Pass Filter'
//  '<S18>'  : 'inv_mot_controller_v2/Inverse Park Transform/Switch_Axis'
//  '<S19>'  : 'inv_mot_controller_v2/PID Controller1/Anti-windup'
//  '<S20>'  : 'inv_mot_controller_v2/PID Controller1/D Gain'
//  '<S21>'  : 'inv_mot_controller_v2/PID Controller1/Filter'
//  '<S22>'  : 'inv_mot_controller_v2/PID Controller1/Filter ICs'
//  '<S23>'  : 'inv_mot_controller_v2/PID Controller1/I Gain'
//  '<S24>'  : 'inv_mot_controller_v2/PID Controller1/Ideal P Gain'
//  '<S25>'  : 'inv_mot_controller_v2/PID Controller1/Ideal P Gain Fdbk'
//  '<S26>'  : 'inv_mot_controller_v2/PID Controller1/Integrator'
//  '<S27>'  : 'inv_mot_controller_v2/PID Controller1/Integrator ICs'
//  '<S28>'  : 'inv_mot_controller_v2/PID Controller1/N Copy'
//  '<S29>'  : 'inv_mot_controller_v2/PID Controller1/N Gain'
//  '<S30>'  : 'inv_mot_controller_v2/PID Controller1/P Copy'
//  '<S31>'  : 'inv_mot_controller_v2/PID Controller1/Parallel P Gain'
//  '<S32>'  : 'inv_mot_controller_v2/PID Controller1/Reset Signal'
//  '<S33>'  : 'inv_mot_controller_v2/PID Controller1/Saturation'
//  '<S34>'  : 'inv_mot_controller_v2/PID Controller1/Saturation Fdbk'
//  '<S35>'  : 'inv_mot_controller_v2/PID Controller1/Sum'
//  '<S36>'  : 'inv_mot_controller_v2/PID Controller1/Sum Fdbk'
//  '<S37>'  : 'inv_mot_controller_v2/PID Controller1/Tracking Mode'
//  '<S38>'  : 'inv_mot_controller_v2/PID Controller1/Tracking Mode Sum'
//  '<S39>'  : 'inv_mot_controller_v2/PID Controller1/Tsamp - Integral'
//  '<S40>'  : 'inv_mot_controller_v2/PID Controller1/Tsamp - Ngain'
//  '<S41>'  : 'inv_mot_controller_v2/PID Controller1/postSat Signal'
//  '<S42>'  : 'inv_mot_controller_v2/PID Controller1/preSat Signal'
//  '<S43>'  : 'inv_mot_controller_v2/PID Controller1/Anti-windup/Disc. Clamping Parallel'
//  '<S44>'  : 'inv_mot_controller_v2/PID Controller1/Anti-windup/Disc. Clamping Parallel/Dead Zone'
//  '<S45>'  : 'inv_mot_controller_v2/PID Controller1/Anti-windup/Disc. Clamping Parallel/Dead Zone/Enabled'
//  '<S46>'  : 'inv_mot_controller_v2/PID Controller1/D Gain/Disabled'
//  '<S47>'  : 'inv_mot_controller_v2/PID Controller1/Filter/Disabled'
//  '<S48>'  : 'inv_mot_controller_v2/PID Controller1/Filter ICs/Disabled'
//  '<S49>'  : 'inv_mot_controller_v2/PID Controller1/I Gain/Internal Parameters'
//  '<S50>'  : 'inv_mot_controller_v2/PID Controller1/Ideal P Gain/Passthrough'
//  '<S51>'  : 'inv_mot_controller_v2/PID Controller1/Ideal P Gain Fdbk/Disabled'
//  '<S52>'  : 'inv_mot_controller_v2/PID Controller1/Integrator/Discrete'
//  '<S53>'  : 'inv_mot_controller_v2/PID Controller1/Integrator ICs/Internal IC'
//  '<S54>'  : 'inv_mot_controller_v2/PID Controller1/N Copy/Disabled wSignal Specification'
//  '<S55>'  : 'inv_mot_controller_v2/PID Controller1/N Gain/Disabled'
//  '<S56>'  : 'inv_mot_controller_v2/PID Controller1/P Copy/Disabled'
//  '<S57>'  : 'inv_mot_controller_v2/PID Controller1/Parallel P Gain/Internal Parameters'
//  '<S58>'  : 'inv_mot_controller_v2/PID Controller1/Reset Signal/Disabled'
//  '<S59>'  : 'inv_mot_controller_v2/PID Controller1/Saturation/Enabled'
//  '<S60>'  : 'inv_mot_controller_v2/PID Controller1/Saturation Fdbk/Disabled'
//  '<S61>'  : 'inv_mot_controller_v2/PID Controller1/Sum/Sum_PI'
//  '<S62>'  : 'inv_mot_controller_v2/PID Controller1/Sum Fdbk/Disabled'
//  '<S63>'  : 'inv_mot_controller_v2/PID Controller1/Tracking Mode/Disabled'
//  '<S64>'  : 'inv_mot_controller_v2/PID Controller1/Tracking Mode Sum/Passthrough'
//  '<S65>'  : 'inv_mot_controller_v2/PID Controller1/Tsamp - Integral/TsSignalSpecification'
//  '<S66>'  : 'inv_mot_controller_v2/PID Controller1/Tsamp - Ngain/Passthrough'
//  '<S67>'  : 'inv_mot_controller_v2/PID Controller1/postSat Signal/Forward_Path'
//  '<S68>'  : 'inv_mot_controller_v2/PID Controller1/preSat Signal/Forward_Path'
//  '<S69>'  : 'inv_mot_controller_v2/PID Controller2/Anti-windup'
//  '<S70>'  : 'inv_mot_controller_v2/PID Controller2/D Gain'
//  '<S71>'  : 'inv_mot_controller_v2/PID Controller2/Filter'
//  '<S72>'  : 'inv_mot_controller_v2/PID Controller2/Filter ICs'
//  '<S73>'  : 'inv_mot_controller_v2/PID Controller2/I Gain'
//  '<S74>'  : 'inv_mot_controller_v2/PID Controller2/Ideal P Gain'
//  '<S75>'  : 'inv_mot_controller_v2/PID Controller2/Ideal P Gain Fdbk'
//  '<S76>'  : 'inv_mot_controller_v2/PID Controller2/Integrator'
//  '<S77>'  : 'inv_mot_controller_v2/PID Controller2/Integrator ICs'
//  '<S78>'  : 'inv_mot_controller_v2/PID Controller2/N Copy'
//  '<S79>'  : 'inv_mot_controller_v2/PID Controller2/N Gain'
//  '<S80>'  : 'inv_mot_controller_v2/PID Controller2/P Copy'
//  '<S81>'  : 'inv_mot_controller_v2/PID Controller2/Parallel P Gain'
//  '<S82>'  : 'inv_mot_controller_v2/PID Controller2/Reset Signal'
//  '<S83>'  : 'inv_mot_controller_v2/PID Controller2/Saturation'
//  '<S84>'  : 'inv_mot_controller_v2/PID Controller2/Saturation Fdbk'
//  '<S85>'  : 'inv_mot_controller_v2/PID Controller2/Sum'
//  '<S86>'  : 'inv_mot_controller_v2/PID Controller2/Sum Fdbk'
//  '<S87>'  : 'inv_mot_controller_v2/PID Controller2/Tracking Mode'
//  '<S88>'  : 'inv_mot_controller_v2/PID Controller2/Tracking Mode Sum'
//  '<S89>'  : 'inv_mot_controller_v2/PID Controller2/Tsamp - Integral'
//  '<S90>'  : 'inv_mot_controller_v2/PID Controller2/Tsamp - Ngain'
//  '<S91>'  : 'inv_mot_controller_v2/PID Controller2/postSat Signal'
//  '<S92>'  : 'inv_mot_controller_v2/PID Controller2/preSat Signal'
//  '<S93>'  : 'inv_mot_controller_v2/PID Controller2/Anti-windup/Disc. Clamping Parallel'
//  '<S94>'  : 'inv_mot_controller_v2/PID Controller2/Anti-windup/Disc. Clamping Parallel/Dead Zone'
//  '<S95>'  : 'inv_mot_controller_v2/PID Controller2/Anti-windup/Disc. Clamping Parallel/Dead Zone/External'
//  '<S96>'  : 'inv_mot_controller_v2/PID Controller2/Anti-windup/Disc. Clamping Parallel/Dead Zone/External/Dead Zone Dynamic'
//  '<S97>'  : 'inv_mot_controller_v2/PID Controller2/D Gain/Disabled'
//  '<S98>'  : 'inv_mot_controller_v2/PID Controller2/Filter/Disabled'
//  '<S99>'  : 'inv_mot_controller_v2/PID Controller2/Filter ICs/Disabled'
//  '<S100>' : 'inv_mot_controller_v2/PID Controller2/I Gain/Internal Parameters'
//  '<S101>' : 'inv_mot_controller_v2/PID Controller2/Ideal P Gain/Passthrough'
//  '<S102>' : 'inv_mot_controller_v2/PID Controller2/Ideal P Gain Fdbk/Disabled'
//  '<S103>' : 'inv_mot_controller_v2/PID Controller2/Integrator/Discrete'
//  '<S104>' : 'inv_mot_controller_v2/PID Controller2/Integrator ICs/Internal IC'
//  '<S105>' : 'inv_mot_controller_v2/PID Controller2/N Copy/Disabled wSignal Specification'
//  '<S106>' : 'inv_mot_controller_v2/PID Controller2/N Gain/Disabled'
//  '<S107>' : 'inv_mot_controller_v2/PID Controller2/P Copy/Disabled'
//  '<S108>' : 'inv_mot_controller_v2/PID Controller2/Parallel P Gain/Internal Parameters'
//  '<S109>' : 'inv_mot_controller_v2/PID Controller2/Reset Signal/External Reset'
//  '<S110>' : 'inv_mot_controller_v2/PID Controller2/Saturation/External'
//  '<S111>' : 'inv_mot_controller_v2/PID Controller2/Saturation/External/Saturation Dynamic'
//  '<S112>' : 'inv_mot_controller_v2/PID Controller2/Saturation Fdbk/Disabled'
//  '<S113>' : 'inv_mot_controller_v2/PID Controller2/Sum/Sum_PI'
//  '<S114>' : 'inv_mot_controller_v2/PID Controller2/Sum Fdbk/Disabled'
//  '<S115>' : 'inv_mot_controller_v2/PID Controller2/Tracking Mode/Disabled'
//  '<S116>' : 'inv_mot_controller_v2/PID Controller2/Tracking Mode Sum/Passthrough'
//  '<S117>' : 'inv_mot_controller_v2/PID Controller2/Tsamp - Integral/TsSignalSpecification'
//  '<S118>' : 'inv_mot_controller_v2/PID Controller2/Tsamp - Ngain/Passthrough'
//  '<S119>' : 'inv_mot_controller_v2/PID Controller2/postSat Signal/Forward_Path'
//  '<S120>' : 'inv_mot_controller_v2/PID Controller2/preSat Signal/Forward_Path'
//  '<S121>' : 'inv_mot_controller_v2/PID Controller3/Anti-windup'
//  '<S122>' : 'inv_mot_controller_v2/PID Controller3/D Gain'
//  '<S123>' : 'inv_mot_controller_v2/PID Controller3/Filter'
//  '<S124>' : 'inv_mot_controller_v2/PID Controller3/Filter ICs'
//  '<S125>' : 'inv_mot_controller_v2/PID Controller3/I Gain'
//  '<S126>' : 'inv_mot_controller_v2/PID Controller3/Ideal P Gain'
//  '<S127>' : 'inv_mot_controller_v2/PID Controller3/Ideal P Gain Fdbk'
//  '<S128>' : 'inv_mot_controller_v2/PID Controller3/Integrator'
//  '<S129>' : 'inv_mot_controller_v2/PID Controller3/Integrator ICs'
//  '<S130>' : 'inv_mot_controller_v2/PID Controller3/N Copy'
//  '<S131>' : 'inv_mot_controller_v2/PID Controller3/N Gain'
//  '<S132>' : 'inv_mot_controller_v2/PID Controller3/P Copy'
//  '<S133>' : 'inv_mot_controller_v2/PID Controller3/Parallel P Gain'
//  '<S134>' : 'inv_mot_controller_v2/PID Controller3/Reset Signal'
//  '<S135>' : 'inv_mot_controller_v2/PID Controller3/Saturation'
//  '<S136>' : 'inv_mot_controller_v2/PID Controller3/Saturation Fdbk'
//  '<S137>' : 'inv_mot_controller_v2/PID Controller3/Sum'
//  '<S138>' : 'inv_mot_controller_v2/PID Controller3/Sum Fdbk'
//  '<S139>' : 'inv_mot_controller_v2/PID Controller3/Tracking Mode'
//  '<S140>' : 'inv_mot_controller_v2/PID Controller3/Tracking Mode Sum'
//  '<S141>' : 'inv_mot_controller_v2/PID Controller3/Tsamp - Integral'
//  '<S142>' : 'inv_mot_controller_v2/PID Controller3/Tsamp - Ngain'
//  '<S143>' : 'inv_mot_controller_v2/PID Controller3/postSat Signal'
//  '<S144>' : 'inv_mot_controller_v2/PID Controller3/preSat Signal'
//  '<S145>' : 'inv_mot_controller_v2/PID Controller3/Anti-windup/Disc. Clamping Parallel'
//  '<S146>' : 'inv_mot_controller_v2/PID Controller3/Anti-windup/Disc. Clamping Parallel/Dead Zone'
//  '<S147>' : 'inv_mot_controller_v2/PID Controller3/Anti-windup/Disc. Clamping Parallel/Dead Zone/Enabled'
//  '<S148>' : 'inv_mot_controller_v2/PID Controller3/D Gain/Disabled'
//  '<S149>' : 'inv_mot_controller_v2/PID Controller3/Filter/Disabled'
//  '<S150>' : 'inv_mot_controller_v2/PID Controller3/Filter ICs/Disabled'
//  '<S151>' : 'inv_mot_controller_v2/PID Controller3/I Gain/Internal Parameters'
//  '<S152>' : 'inv_mot_controller_v2/PID Controller3/Ideal P Gain/Passthrough'
//  '<S153>' : 'inv_mot_controller_v2/PID Controller3/Ideal P Gain Fdbk/Disabled'
//  '<S154>' : 'inv_mot_controller_v2/PID Controller3/Integrator/Discrete'
//  '<S155>' : 'inv_mot_controller_v2/PID Controller3/Integrator ICs/Internal IC'
//  '<S156>' : 'inv_mot_controller_v2/PID Controller3/N Copy/Disabled wSignal Specification'
//  '<S157>' : 'inv_mot_controller_v2/PID Controller3/N Gain/Disabled'
//  '<S158>' : 'inv_mot_controller_v2/PID Controller3/P Copy/Disabled'
//  '<S159>' : 'inv_mot_controller_v2/PID Controller3/Parallel P Gain/Internal Parameters'
//  '<S160>' : 'inv_mot_controller_v2/PID Controller3/Reset Signal/Disabled'
//  '<S161>' : 'inv_mot_controller_v2/PID Controller3/Saturation/Enabled'
//  '<S162>' : 'inv_mot_controller_v2/PID Controller3/Saturation Fdbk/Disabled'
//  '<S163>' : 'inv_mot_controller_v2/PID Controller3/Sum/Sum_PI'
//  '<S164>' : 'inv_mot_controller_v2/PID Controller3/Sum Fdbk/Disabled'
//  '<S165>' : 'inv_mot_controller_v2/PID Controller3/Tracking Mode/Disabled'
//  '<S166>' : 'inv_mot_controller_v2/PID Controller3/Tracking Mode Sum/Passthrough'
//  '<S167>' : 'inv_mot_controller_v2/PID Controller3/Tsamp - Integral/TsSignalSpecification'
//  '<S168>' : 'inv_mot_controller_v2/PID Controller3/Tsamp - Ngain/Passthrough'
//  '<S169>' : 'inv_mot_controller_v2/PID Controller3/postSat Signal/Forward_Path'
//  '<S170>' : 'inv_mot_controller_v2/PID Controller3/preSat Signal/Forward_Path'
//  '<S171>' : 'inv_mot_controller_v2/PID Controller4/Anti-windup'
//  '<S172>' : 'inv_mot_controller_v2/PID Controller4/D Gain'
//  '<S173>' : 'inv_mot_controller_v2/PID Controller4/Filter'
//  '<S174>' : 'inv_mot_controller_v2/PID Controller4/Filter ICs'
//  '<S175>' : 'inv_mot_controller_v2/PID Controller4/I Gain'
//  '<S176>' : 'inv_mot_controller_v2/PID Controller4/Ideal P Gain'
//  '<S177>' : 'inv_mot_controller_v2/PID Controller4/Ideal P Gain Fdbk'
//  '<S178>' : 'inv_mot_controller_v2/PID Controller4/Integrator'
//  '<S179>' : 'inv_mot_controller_v2/PID Controller4/Integrator ICs'
//  '<S180>' : 'inv_mot_controller_v2/PID Controller4/N Copy'
//  '<S181>' : 'inv_mot_controller_v2/PID Controller4/N Gain'
//  '<S182>' : 'inv_mot_controller_v2/PID Controller4/P Copy'
//  '<S183>' : 'inv_mot_controller_v2/PID Controller4/Parallel P Gain'
//  '<S184>' : 'inv_mot_controller_v2/PID Controller4/Reset Signal'
//  '<S185>' : 'inv_mot_controller_v2/PID Controller4/Saturation'
//  '<S186>' : 'inv_mot_controller_v2/PID Controller4/Saturation Fdbk'
//  '<S187>' : 'inv_mot_controller_v2/PID Controller4/Sum'
//  '<S188>' : 'inv_mot_controller_v2/PID Controller4/Sum Fdbk'
//  '<S189>' : 'inv_mot_controller_v2/PID Controller4/Tracking Mode'
//  '<S190>' : 'inv_mot_controller_v2/PID Controller4/Tracking Mode Sum'
//  '<S191>' : 'inv_mot_controller_v2/PID Controller4/Tsamp - Integral'
//  '<S192>' : 'inv_mot_controller_v2/PID Controller4/Tsamp - Ngain'
//  '<S193>' : 'inv_mot_controller_v2/PID Controller4/postSat Signal'
//  '<S194>' : 'inv_mot_controller_v2/PID Controller4/preSat Signal'
//  '<S195>' : 'inv_mot_controller_v2/PID Controller4/Anti-windup/Disabled'
//  '<S196>' : 'inv_mot_controller_v2/PID Controller4/D Gain/Disabled'
//  '<S197>' : 'inv_mot_controller_v2/PID Controller4/Filter/Disabled'
//  '<S198>' : 'inv_mot_controller_v2/PID Controller4/Filter ICs/Disabled'
//  '<S199>' : 'inv_mot_controller_v2/PID Controller4/I Gain/Disabled'
//  '<S200>' : 'inv_mot_controller_v2/PID Controller4/Ideal P Gain/Passthrough'
//  '<S201>' : 'inv_mot_controller_v2/PID Controller4/Ideal P Gain Fdbk/Disabled'
//  '<S202>' : 'inv_mot_controller_v2/PID Controller4/Integrator/Disabled'
//  '<S203>' : 'inv_mot_controller_v2/PID Controller4/Integrator ICs/Disabled'
//  '<S204>' : 'inv_mot_controller_v2/PID Controller4/N Copy/Disabled wSignal Specification'
//  '<S205>' : 'inv_mot_controller_v2/PID Controller4/N Gain/Disabled'
//  '<S206>' : 'inv_mot_controller_v2/PID Controller4/P Copy/Disabled'
//  '<S207>' : 'inv_mot_controller_v2/PID Controller4/Parallel P Gain/Internal Parameters'
//  '<S208>' : 'inv_mot_controller_v2/PID Controller4/Reset Signal/Disabled'
//  '<S209>' : 'inv_mot_controller_v2/PID Controller4/Saturation/Enabled'
//  '<S210>' : 'inv_mot_controller_v2/PID Controller4/Saturation Fdbk/Disabled'
//  '<S211>' : 'inv_mot_controller_v2/PID Controller4/Sum/Passthrough_P'
//  '<S212>' : 'inv_mot_controller_v2/PID Controller4/Sum Fdbk/Disabled'
//  '<S213>' : 'inv_mot_controller_v2/PID Controller4/Tracking Mode/Disabled'
//  '<S214>' : 'inv_mot_controller_v2/PID Controller4/Tracking Mode Sum/Passthrough'
//  '<S215>' : 'inv_mot_controller_v2/PID Controller4/Tsamp - Integral/TsSignalSpecification'
//  '<S216>' : 'inv_mot_controller_v2/PID Controller4/Tsamp - Ngain/Passthrough'
//  '<S217>' : 'inv_mot_controller_v2/PID Controller4/postSat Signal/Forward_Path'
//  '<S218>' : 'inv_mot_controller_v2/PID Controller4/preSat Signal/Forward_Path'
//  '<S219>' : 'inv_mot_controller_v2/Park Transform/Switch_Axis'

#endif                                 // RTW_HEADER_inv_mot_controller_v2_h_

//
// File trailer for generated code.
//
// [EOF]
//
