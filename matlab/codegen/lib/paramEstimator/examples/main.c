/*
 * File: main.c
 *
 * MATLAB Coder version            : 5.6
 * C/C++ source code generated on  : 29-Feb-2024 16:44:30
 */

/*************************************************************************/
/* This automatically generated example C main file shows how to call    */
/* entry-point functions that MATLAB Coder generated. You must customize */
/* this file for your application. Do not modify this file directly.     */
/* Instead, make a copy of this file, modify it, and integrate it into   */
/* your development environment.                                         */
/*                                                                       */
/* This file initializes entry-point function arguments to a default     */
/* size and value before calling the entry-point functions. It does      */
/* not store or use any values returned from the entry-point functions.  */
/* If necessary, it does pre-allocate memory for returned values.        */
/* You can use this file as a starting point for a main function that    */
/* you can deploy in your application.                                   */
/*                                                                       */
/* After you copy the file, and before you deploy it, you must make the  */
/* following changes:                                                    */
/* * For variable-size function arguments, change the example sizes to   */
/* the sizes that your application requires.                             */
/* * Change the example values of function arguments to the values that  */
/* your application requires.                                            */
/* * If the entry-point functions return values, store these values or   */
/* otherwise use them as required by your application.                   */
/*                                                                       */
/*************************************************************************/

/* Include Files */
#include "main.h"
#include "paramEstimator.h"
#include "paramEstimator_terminate.h"
#include "paramEstimator_types.h"
#include "rt_nonfinite.h"

/* Function Declarations */
static void argInit_1x20_param(param result[20]);

static void argInit_1x23_real_T(double result[23]);

static param argInit_param(void);

static double argInit_real_T(void);

/* Function Definitions */
/*
 * Arguments    : param result[20]
 * Return Type  : void
 */
static void argInit_1x20_param(param result[20])
{
  int idx1;
  /* Loop over the array to initialize each element. */
  for (idx1 = 0; idx1 < 20; idx1++) {
    /* Set the value of the array element.
Change this value to the value that the application requires. */
    result[idx1] = argInit_param();
  }
}

/*
 * Arguments    : double result[23]
 * Return Type  : void
 */
static void argInit_1x23_real_T(double result[23])
{
  int idx1;
  /* Loop over the array to initialize each element. */
  for (idx1 = 0; idx1 < 23; idx1++) {
    /* Set the value of the array element.
Change this value to the value that the application requires. */
    result[idx1] = argInit_real_T();
  }
}

/*
 * Arguments    : void
 * Return Type  : param
 */
static param argInit_param(void)
{
  param result;
  double result_tmp;
  /* Set the value of each structure field.
Change this value to the value that the application requires. */
  result_tmp = argInit_real_T();
  result.gravity = result_tmp;
  result.mass = result_tmp;
  result.Jxx = result_tmp;
  result.Jyy = result_tmp;
  result.Jzz = result_tmp;
  result.tau = result_tmp;
  result.Ts = result_tmp;
  return result;
}

/*
 * Arguments    : void
 * Return Type  : double
 */
static double argInit_real_T(void)
{
  return 0.0;
}

/*
 * Arguments    : int argc
 *                char **argv
 * Return Type  : int
 */
int main(int argc, char **argv)
{
  (void)argc;
  (void)argv;
  /* The initialize function is being called automatically from your entry-point
   * function. So, a call to initialize is not included here. */
  /* Invoke the entry-point functions.
You can call entry-point functions multiple times. */
  main_paramEstimator();
  /* Terminate the application.
You do not need to do this more than one time. */
  paramEstimator_terminate();
  return 0;
}

/*
 * Arguments    : void
 * Return Type  : void
 */
void main_paramEstimator(void)
{
  param rv[20];
  double dv[23];
  double out[8];
  /* Initialize function 'paramEstimator' input arguments. */
  /* Initialize function input argument 'u'. */
  /* Initialize function input argument 'P'. */
  /* Call the entry-point 'paramEstimator'. */
  argInit_1x23_real_T(dv);
  argInit_1x20_param(rv);
  paramEstimator(dv, rv, out);
}

/*
 * File trailer for main.c
 *
 * [EOF]
 */
