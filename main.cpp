
#include <iostream>
#include <fstream>
#include "Perceptron.h"

using namespace std;

const int MAX_ITERATIONS = 25;

int main(int argc, char** argv) {
    if (argc < 2) {
        cerr << "Missing argument. Command to run is EXECUTABLE_NAME FILE_PATH."
             << endl;
        exit(1);
    }
    
    //Get sample data set from provided file
    string filePath = argv[1];
    int numInputs, totalData;
    ifstream inFile;
    inFile.open(filePath);
    if (!inFile) {
        cerr << "Error: Couldn't open the sample data file. Exiting now...\n";
        exit(1);
    }
    
    if (!(inFile >> numInputs) || !(inFile >> totalData)) {
        cerr << "Read error on initial dataset values...\n";
        exit(1);
    }
    
    int dataSet[totalData][numInputs+1];
    for (int i=0; i<totalData; i++) {
        for (int j=0; j<numInputs+1; j++) {
            if (!(inFile >> dataSet[i][j])) {
                cerr << "Read error on sample value...\n";
                exit(1);
            }
        }
    }
    inFile.close();
    
    
    //Construct perceptron, train, and test for maximum iterations
    Perceptron p = Perceptron(dataSet[0], numInputs);
    
    
    for (int i=0; i<MAX_ITERATIONS; i++) {

    	int failCount = 0;
        double errorRate = 0;            
        
		for (int j=0; j<totalData; j++)
            p.train(dataSet[j], numInputs);
        for (int j=0; j<totalData; j++) {
            int testOutput = p.test(dataSet[j], numInputs);
            if (!(testOutput == dataSet[j][numInputs]))
                failCount++;
        }
        
        errorRate = failCount / (double) totalData;
        cout << "Total samples:      " << totalData << endl;
        cout << "Incorrect outputs:  " << failCount << endl;
        cout << "Error rate:         " << errorRate << endl << endl;

        if (errorRate == 0) {
            cout << "Network has converged, breaking out of training loop.\n\n";
            break;
        }
    }
    
    cout << "Input -1 or 1 to test Perceptron.\n";
    cout << "Input anything else to exit the program.\n";
    
    //Test perceptron on user input
    int testInts[numInputs];
    while (true) {
        for (int i=0; i<numInputs; i++) {
            cout << "Input " << i+1 << ": ";
            while (!(cin >> testInts[i]) || 
                   !(testInts[i] == 1 || testInts[i] == -1)) 
            {
                cout << "Invalid value entered. Exiting now...\n";
                exit(0);
            }
        }
        cout << "Output value: " << p.test(testInts, numInputs) << endl << endl;
    }
    
    return 0;
}

