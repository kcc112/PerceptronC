cmake_minimum_required(VERSION 3.4)
project(Biblioteka)

SET(SOURCE_FILES include/Perceptron.h src/Perceptron.cpp src/Point.cpp include/Point.h src/Function.cpp include/Function.h include/Gnuplot_i.h)

#utwórz bibliotekę typu STATIC, SHARED albo MODULE ze wskazanych źródeł
add_library(Biblioteka ${SOURCE_FILES})

target_include_directories(Biblioteka PUBLIC include)

