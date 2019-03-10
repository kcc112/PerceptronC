//
// Created by kamil on 3/10/19.
//

#ifndef PERCEPTRON_FUNCTION_H
#define PERCEPTRON_FUNCTION_H

#include <memory>
#include <vector>
#include <string>

class Point;

typedef std::shared_ptr<Point> point_ptr;

class Function {

public:
    double function(double x);
    void writeToFile(std::vector<point_ptr> input, std::string filename);
};

typedef std::shared_ptr<Function> function_ptr;

#endif //PERCEPTRON_FUNCTION_H
