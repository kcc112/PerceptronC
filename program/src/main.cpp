#include <iostream>
#include <ctime>
#include <cstdlib>
#include "Function.h"
#include "Perceptron.h"
#include "Point.h"
#include "Gnuplot_i.h"
#define POINTS 100

int main() {

    Gnuplot main_plot;
    srand(time(NULL));
    perceptron_ptr p1(new Perceptron());
    function_ptr f1(new Function());
    point_ptr points[POINTS];
    std::vector<double>  class_green_x;
    std::vector<double>  class_read_x;
    std::vector<double>  class_green_y;
    std::vector<double>  class_read_y;
    std::vector<double>  perceptronLineX;
    std::vector<double>  perceptronLineY;
    std::vector<double>  weight;

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

    for(int i = 1; i < 10; i++){
        weight = p1->getWeight();
        perceptronLineX.push_back(i);
        perceptronLineY.push_back((-weight[0]/weight[1])*i-(weight[2]/weight[1]));
    }

    main_plot.set_grid();
    main_plot.set_style("lines");
    main_plot.plot_equation("-1*x+25");
    main_plot.set_style("points");
    main_plot.plot_xy(class_read_x,class_read_y,"xd");
    main_plot.plot_xy(class_green_x,class_green_y,"xdd");
    main_plot.set_style("lines");
    main_plot.plot_xy(perceptronLineX,perceptronLineY,"dd");
    perceptronLineX.clear();
    perceptronLineY.clear();
    main_plot.reset_plot();

    getchar();
   int p = 1;
    while(p == 1){

        for (int k = 0; k < 10; ++k) {
            for(int j = 0; j< POINTS; j++){
                p1->train(points[j]->getInputs(),points[j]->getAnswer());
            }
        }

        for(int i = 1; i < 10; i++){
            weight = p1->getWeight();
            perceptronLineX.push_back(i);
            perceptronLineY.push_back((-weight[0]/weight[1])*i-(weight[2]/weight[1]));
        }
        main_plot.set_grid();
        main_plot.set_style( "lines" );
        main_plot.plot_equation("-1*x+25");
        main_plot.set_style( "points" );
        main_plot.plot_xy(class_read_x,class_read_y,"xd");
        main_plot.plot_xy(class_green_x,class_green_y,"xdd");
        main_plot.set_style("lines");
        main_plot.plot_xy(perceptronLineX,perceptronLineY,"dd");
        perceptronLineX.clear();
        perceptronLineY.clear();
        main_plot.reset_plot();

        std::cout << "STOP 1 == FALSE" << std::endl;
        std::cin >> p;
    }

    //plot 2*x+1, "file1"using 1:2 pt 7 ps 1.5 , "file2" using 1:2 pt 7 ps 1.5(gnuplot)

    return 0;
}