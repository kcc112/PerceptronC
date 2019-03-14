#include <iostream>
#include <ctime>
#include <cstdlib>
#include "Function.h"
#include "Perceptron.h"
#include "Point.h"
#include "Gnuplot_i.h"
#define POINTS 1000 //use 500 points to train

int main() {

    Gnuplot main_plot;
    srand(time(NULL));
    perceptron_ptr p1(new Perceptron());
    function_ptr f1(new Function());
    point_ptr points[POINTS];

    //vectors for training points
    std::vector<double> class_green_x;
    std::vector<double> class_read_x;
    std::vector<double> class_green_y;
    std::vector<double> class_read_y
    ;
    //vectors for drawing perceptron
    std::vector<double> perceptronLineX;
    std::vector<double> perceptronLineY;

    //perceptron weights
    std::vector<double> weight;

    //generate 500 points
    for(int i = 0; i < POINTS; i++){
        double x = ((double(rand()) / double(RAND_MAX)) * (10));
        double y = ((double(rand()) / double(RAND_MAX)) * (25));
        int answer = 1;
        if(y < f1->function(x)){
            answer = -1;
            class_green_x.push_back(x);
            class_green_y.push_back(y);
        }else{
            class_read_x.push_back(x);
            class_read_y.push_back(y);
        }
        point_ptr point(new Point(x,y,answer));
        points[i] = point;
    }

    //get points for perceptron line
    for(int i = 1; i < 10; i++){
        weight = p1->getWeight();
        perceptronLineX.push_back(i);
        perceptronLineY.push_back((-weight[0]/weight[1])*i-(weight[2]/weight[1]));
    }

    //draw before first train
    main_plot.set_grid();
    main_plot.set_style("lines");
    main_plot.plot_equation("-1*x+10");
    main_plot.set_style("points");
    main_plot.plot_xy(class_read_x,class_read_y,"draw points under line");
    main_plot.plot_xy(class_green_x,class_green_y,"draw points over line");
    main_plot.set_style("lines");
    main_plot.plot_xy(perceptronLineX,perceptronLineY,"draw perceptron line");
    perceptronLineX.clear();
    perceptronLineY.clear();
    main_plot.reset_plot();

    std::cout << "Percepron before training press 'a' to continue" << std::endl;
    getchar();
    int p = 1;
    while(p == 1){

        //train perceptron
        for(int j = 0; j< POINTS; j++){
            p1->train(points[j]->getInputs(),points[j]->getAnswer());
        }

        //get points for perceptron line
        for(int i = 1; i < 10; i++){
            weight = p1->getWeight();
            perceptronLineX.push_back(i);
            perceptronLineY.push_back((-weight[0]/weight[1])*i-(weight[2]/weight[1]));
        }

        //draw after first train
        main_plot.set_grid();
        main_plot.set_style( "lines" );
        main_plot.plot_equation("-1*x+10");
        main_plot.set_style( "points" );
        main_plot.plot_xy(class_read_x,class_read_y,"draw points under line");
        main_plot.plot_xy(class_green_x,class_green_y,"draw points over line");
        main_plot.set_style("lines");
        main_plot.plot_xy(perceptronLineX,perceptronLineY,"draw perceptron line");
        perceptronLineX.clear();
        perceptronLineY.clear();
        main_plot.reset_plot();

        std::cout << "Press 1 to continue" << std::endl;
        std::cin >> p;
    }
    return 0;
}