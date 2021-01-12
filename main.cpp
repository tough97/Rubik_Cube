//
//  main.cpp
//  Rubik_Cube_2
//
//  Created by 刘罡 on 3/5/2016.
//  Copyright © 2016 刘罡. All rights reserved.
//

#include <iostream>
#include "Window.hpp"

using namespace std;
using namespace glm;


int main(int argc, const char * argv[]) {
    try {
        cube::Window *window = new cube::Window(800, 600, "");
        window->start();
        delete window;
    } catch (runtime_error& e){
        std::cout<<e.what()<<std::endl;
    }
}
