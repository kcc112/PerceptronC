#include <iostream>
#include "Function.h"
#include "Perceptron.h"
#include "Point.h"
#include <ctime>
#include <cstdlib>
#define POINTS 100

int main() {
    srand(time(NULL));
    perceptron_ptr p1(new Perceptron());
    function_ptr f1(new Function());
    point_ptr points[POINTS];
    std::vector<point_ptr> class1;
    std::vector<point_ptr> class2;

    for(int i = 0; i < POINTS; i++){
        double x = ((double(rand()) / double(RAND_MAX)) * (10));
        double y = ((double(rand()) / double(RAND_MAX)) * (10));
        int answer = 1;
        if(y < f1->function(x)) answer = -1;
        point_ptr point(new Point(x,y,answer));
        points[i] = point;
    }

    int p = 1;
    while(p == 1){
        for(int j = 0; j< POINTS; j++){
            int answer = p1->train(points[j]->getInputs(),points[j]->getAnswer());
            if(points[j]->getAnswer() == answer){
                class1.push_back(points[j]);
            } else{
                class2.push_back((points[j]));
            }
        }
        f1->writeToFile(class1,"file1");
        f1->writeToFile(class2,"file2");
        class1.clear();
        class2.clear();
        std::cout << "STOP 1 == FALSE" << std::endl;
        std::cin >> p;
    }

    //plot 2*x+1, "file1"using 1:2 pt 7 ps 1.5 , "file2" using 1:2 pt 7 ps 1.5(gnuplot)

    return 0;
}