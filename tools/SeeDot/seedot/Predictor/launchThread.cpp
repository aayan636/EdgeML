#include "launchThread.h"
#include "predictors.h"
#include "datatypes.h"

// Multi-threading is used to speed up exploration.
// Each thread, which invokes the following method, is responsible for taking in one datapoint
// and running it through all the generated codes.
// Number of threads generated equals the number of datapoints in the given dataset.
void launchThread(int features_size, MYINT** features_int, MYINT*** features_intV, float** features_float, int counter, float* float_res, int* res, int** resV) {
	seedotFixed(features_int, res);
	seedotFloat(features_float, float_res);

	for (int i = 0; i < features_size; i++) {
		delete features_int[i];
		delete features_float[i];
		for (int j = 0; j < switches; j++) {
			delete features_intV[j][i];
		}
	}
	delete[] features_int;
	delete[] features_float;
	for (int j = 0; j < switches; j++) {
		delete[] features_intV[j];
	}
	delete[] features_intV;
}

void seedotFloatWrap(float** X, float* res) {
	seedotFloat(X, res);
}

int getSwitches() {
	return switches;
}