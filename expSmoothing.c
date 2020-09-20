#include "expSmoothing.h"

int32_t expSmoothingInit(ExpSmoothing* filter, float kF){
    if(kF > 0 && kF < 1){
        filter->kF = kF;
        filter->output = 0;
        return 0;
    }
    else{
        return 1;
    }
}

float expSmoothingIterate(ExpSmoothing* filter, float input){
    filter->input = input;
    filter->output = (filter->kF * filter->input) + ((1 - filter->kF) * filter->output);
    return filter->output;
}

float expSmoothingSet(ExpSmoothing* filter, float output){
    filter->output = output;
}
