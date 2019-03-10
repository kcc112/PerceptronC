//
// Created by kamil on 3/10/19.
//

#include "Function.h"
#include "Point.h"
#include <iostream>
#include <cstdlib>
#include <string>
#include <fstream>

double Function::function(double x) {
    return 2*x + 1;
}

void Function::writeToFile(std::vector<point_ptr> input, std::string filename) {
    std::string line;
    std::fstream file;

    file.open(filename,std::ios::out | std::ios::trunc);
    if(file.good() == true){
        for(int i = 0; i < (int)input.size(); i++){
            std::vector<double> array;
            array = input[i]->getInputs();
            file << array[0] << " " << array[1] << std::endl;
        }
        file.close();
    }

}
