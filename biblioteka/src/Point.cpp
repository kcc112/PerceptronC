//
// Created by kamil on 3/10/19.
//

#include "Point.h"

Point::Point(double x, double y, int a) {
    inputs.push_back(x);
    inputs.push_back(y);
    inputs.push_back(1);
    answer = a;
}

std::vector<double> Point::getInputs() {
    return inputs;
}

int Point::getAnswer() {
    return answer;
}
