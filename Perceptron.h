#ifndef PERCEPTRON_H
#define PERCEPTRON_H

#include <vector>

class Perceptron {
public:
    Perceptron(int sample[], int numInputs);
    void train(int sample[], int numInputs);
    int test(int sample[], int numInputs);
private:
    const double L = 0.2;
    const int BIAS =-1;
    std::vector<double> weights;
    int output;
    int sampleOutput;
    bool activate(double total);
};

#endif /* PERCEPTRON_H */

