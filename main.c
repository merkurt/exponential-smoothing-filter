#include "expSmoothing.h"
#include <stdio.h>
#include <stdlib.h>

// simulations parameters
float input = 0.0;
float lowValue = 0.0;
float highValue = 1.0;
float simTotalTime = 4000;
float simRisingTime = 500;
float simFallingTime = 2000;
float simTickMs = 1;

int main(int argc, char **argv){
    ExpSmoothing filter0;
    ExpSmoothing filter1;
    ExpSmoothing filter2;

    // init filters
    if(expSmoothingInit(&filter0, 0.01) != 0){
        printf("Something went wrong at filter0!\n");
        return EXIT_FAILURE;
    }
    if(expSmoothingInit(&filter1, 0.05) != 0){
        printf("Something went wrong at filter1!\n");
        return EXIT_FAILURE;
    }
    if(expSmoothingInit(&filter2, 0.1) != 0){
        printf("Something went wrong at filter2!\n");
        return EXIT_FAILURE;
    }

    // open file
    FILE* fp = fopen("expSmooting.csv", "w+");
    if(fp == NULL){
        printf("Something went wrong at expSmoothing.csv!\n");
        return EXIT_FAILURE;
    }

    // simulation
    for(float t = 0; t < simTotalTime; t += simTickMs){
        if(t < simRisingTime){
            input = lowValue;           
        }
        else if(t < simFallingTime){
            input = highValue;
        }
        else{
            input = lowValue;
        }

        expSmoothingIterate(&filter0, input);
        expSmoothingIterate(&filter1, input);
        expSmoothingIterate(&filter2, input);

        fprintf(fp, "%f,%f,%f,%f,%f\n", t, input, filter0.output, filter1.output, filter2.output);
    }

    fclose(fp);
    printf("Simulation was succesfully");
    return EXIT_SUCCESS;
}