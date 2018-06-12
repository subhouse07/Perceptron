# Perceptron
Written by Andy Peterson
## SUMMARY

    This program constructs a perceptron of N inputs which have values of either
	-1 or 1. The inputs are obtained from the file whose path is provided as an
	argument when executing the program. The perceptron is constructed as follows:

    	-N inputs, each with value -1 or 1
    	-N weights, initialized to the average of the values of the first sample 
        	of the data set
    	-A dummy input of -1 and weight of -N/2
    	-Learning rate of 0.2
    	-Threshold function:    1    if sum(inputs*weights) > 0 
        	                    -1   otherwise
    	-Weight calculation:   	w = w + L(d-y)x
                            	where w is weight, L is learning parameter, 
                            	d is desired output, and y is output from threshold
                            	function

	The program proceeds to train on the data set and test for convergence for a
	set number of iterations (defined as a constant MAX_ITERATIONS in main.cpp) 
	or until an error rate of 0 is achieved.
    After training the perceptron on the provided data set and testing to
	confirm convergence (or non-convergence) of the network, the program enters an 
	input loop and prompts for test input to run through the perceptron.


## COMPILING AND RUNNING

    This program consists of two files:
        main.cpp
        Perceptron.cpp

    It was written using the c++11 standard on a Linux machine.
    To compile enter the following command:
    
        g++ -std=c++11 main.cpp Perceptron.cpp

    Set the executable permission on the resulting executable file.
    
    The program takes in as an argument the file path of the file containing 
    the data set. So to run the program:
    
        EXECUTABLE_NAME PATH_TO_FILE

    The program will run through training and testing automatically, provided 
    the data set is in the following format:

    x y
    a1,1 a1,2 a1,3 . . . a1,x out1
    a2,1 a2,2 a2,3 . . . a2,x out2
    a3,1 a3,2 a3,3 . . . a3,x out3
                .
                .
                .
    ay,1 ay,2 ay,3 . . . ay,x outy

    where x is the number of inputs in each sample, y is the number of
    samples, and each input value and output is either -1 or 1.

    When the input loop begins, simply enter values of either -1 or 1 followed
    by ENTER until the Perceptron returns an output value. 

    To exit the program enter any character other than -1 or 1.
