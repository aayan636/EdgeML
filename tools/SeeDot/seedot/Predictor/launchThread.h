#pragma once

#include "datatypes.h"

void launchThread(int features_size, MYINT** features_int, MYINT*** features_intV, float** features_float, int counter, float* float_res, int* res, int** resV);

void seedotFloatWrap(float** X, float* res);

int getSwitches();