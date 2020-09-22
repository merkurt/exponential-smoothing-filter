#ifndef EXPSMOOTHING
#define EXPSMOOTHING

#include <stdint.h>

typedef struct{
    float input;
    float output;
    float kF;
}ExpSmoothing;

int32_t expSmoothingInit(ExpSmoothing* filter, float kF);

float expSmoothingIterate(ExpSmoothing* filter, float input);

float expSmoothingSet(ExpSmoothing* filter, float output);

#endif
