//
// Created by kamil on 3/10/19.
//

#include "Perceptron.h"
#include <ctime>
#include <cstdlib>
#include <iostream>

Perceptron::Perceptron(){
    lRate = 0.1;
    srand(time(NULL));
    for(int i = 0; i < 3; i++){
        weight.push_back(((double(rand())/double(RAND_MAX))*(4))-2);
    }
}

int Perceptron::sign(double input) {
    if(input > 0){
        return 1;
    } else{
        return -1;
    }
}

int Perceptron::train(std::vector<double> inputs, int desired) {
    int answer = guess(inputs);
    double error = desired - answer;
    for(int i = 0; i < 3; i++){
        weight[i] = weight[i] + lRate * error * inputs[i];
    }
    return answer;
}

int Perceptron::guess(std::vector<double> inputs){
    double sum = 0;
    for(int i = 0; i < 3; i++){
        sum += inputs[i]*weight[i];
    }
    return sign(sum);
}

std::vector<double> Perceptron::getWeight() {
    return weight;
}