#pragma once

//Data Seperator
#define __DSep__ #:

//Data Precision on output Streams
#define __Out_Prec__ 10

//Data Fill for Column Formatting
#define __DFill__ 5


//Produce Density Color Plot
//#define __DENSITY_PLOT__

//Define toinclude a Var v Var Relation plot.
#define __VARVFRACVAR__


//Leave the first __L_F_IT__ before shuffling the con_matrix order
#define __L_F_IT__ 1


//Machine Epsilon for double comparision
#define __M_EPSILON__ 0.00000001
//### Machine Epsilon  - 10e-8











// These codes set the actual text to the specified color
#define RESETTEXT  "\x1B[0m" // Set all colors back to normal.
#define FORERED  "\x1B[31m" // Red
#define FOREBLU  "\x1B[34m" // Blue
#define FORECYN  "\x1B[36m" // Cyan
#define FOREWHT  "\x1B[37m" // White