//
// Created by kamil on 3/10/19.
//

#ifndef PERCEPTRON_FUNCTION_H
#define PERCEPTRON_FUNCTION_H

#include <memory>
#include <vector>

class Point;

typedef std::shared_ptr<Point> point_ptr;

class Function {

public:
    double function(double x);
};

typedef std::shared_ptr<Function> function_ptr;

#endif //PERCEPTRON_FUNCTION_H
