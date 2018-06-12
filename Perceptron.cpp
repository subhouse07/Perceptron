
#include <vector>
#include "Perceptron.h"


Perceptron::Perceptron(int sample[], int numInputs) {
    double avg = 0,
           sum = 0;
    for (int i=0; i<numInputs; i++)
        sum += sample[i];
        
    avg = sum / ((double)numInputs);
    for (int i=0; i<numInputs; i++) {
        weights.push_back(avg);
    }
    weights.push_back((double)(-1*numInputs) / 2.0);
}

void Perceptron::train(int sample[], int numInputs) {
    output = 0;
    double total = 0;
    
    for (int i=0; i<numInputs; i++)
        total += (double)sample[i] * weights.at(i);
    total += (double)BIAS * weights.at(numInputs);
    
    sampleOutput = sample[numInputs];
    if (!activate(total)) 
        output = -1;
    else
        output = 1;
    
    if (output != sampleOutput) {
        for (int i=0; i<numInputs; i++)
            weights.at(i) += L * 
                    (double)(sampleOutput - output) * (double)sample[i];
        weights.at(numInputs) += L * (double)(sampleOutput - output) * (double)BIAS;
    }    
}

int Perceptron::test(int sample[], int numInputs) {
    double total = 0;
    
    for (int i=0; i<numInputs; i++)
        total += (double)sample[i] * weights.at(i);
    total += (double)BIAS * weights.at(numInputs);
    
    if (activate(total))
        return 1;
    else
        return -1;
}

bool Perceptron::activate(double total) { return total > 0; }

