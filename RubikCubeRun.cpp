//
// Created by gang_liu on 18-12-21.
//
#include "RubikCube.h"
#include "Window.hpp"
#include<iostream>

JNIEXPORT void JNICALL Java_RubikCube_run
(JNIEnv *, jobject){
    try {
        cube::Window *window = new cube::Window(800, 600, "");
    window->start();
        delete window;
    } catch (std::runtime_error& e){
    std::cout<<e.what()<<std::endl;
    }
}