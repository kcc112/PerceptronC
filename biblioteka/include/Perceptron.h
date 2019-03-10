//
// Created by kamil on 3/10/19.
//

#ifndef PERCEPTRON_PERCEPTRON_H
#define PERCEPTRON_PERCEPTRON_H

#include <memory>
#include <vector>

class Perceptron {

    double weight[3];
    double lRate;

public:

    Perceptron();
    ~Perceptron() = default;

    int guess(std::vector<double> inputs);
    int sign(double input);
    int train(std::vector<double> inputs, int desired);
};

typedef std::shared_ptr<Perceptron> perceptron_ptr;

#endif //PERCEPTRON_PERCEPTRON_H
