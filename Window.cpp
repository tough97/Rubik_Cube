//
//  Window.cpp
//  Rubik_Cube
//
//  Created by 刘罡 on 13/4/2016.
//  Copyright © 2016 刘罡. All rights reserved.
//

#include "Window.hpp"
#include <glm/ext.hpp>
#include <iostream>
#include <random>

using namespace std;
using namespace cube;

void Window::key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
    if (action != GLFW_PRESS)
        return;
    switch (key)
    {
        case GLFW_KEY_ESCAPE:
            glfwSetWindowShouldClose(window, GL_TRUE);
            break;
        case GLFW_KEY_W:
            camera->forward();
            cout<<"I am moving forward"<<endl;
            break;
        default:
            break;
    }
}

cube::Window::Window(const int width, const int height, const string title)
:width(width), height(height), title(title){

    if(!glfwInit()){
        throw runtime_error("Failed to initialize GLFW");
    }
    
    camera = new klm::fps_camera();    
    
    glfwWindowHint(GLFW_SAMPLES, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    
    window = glfwCreateWindow(width, height, title.c_str(), nullptr, nullptr);
    
    if(!window){
        throw runtime_error("Failed to create window");
    }
    
    glfwMakeContextCurrent(window);
    glfwSwapInterval(1);

    // Initialize GLEW
    glewExperimental = true; // Needed for core profile
    if (glewInit() != GLEW_OK) {
        std::cout<<"Failed to initialize GLEW"<<std::endl;
        glfwTerminate();
    } else {
        GLint majorVersion;
        GLint minoVersion;
        glGetIntegerv(GL_MAJOR_VERSION, &majorVersion);
        glGetIntegerv(GL_MINOR_VERSION, &minoVersion);
        std::cout<<"OpenGL version ["<<majorVersion<<"."<<minoVersion<<"]"<<std::endl;
    }
    
    glm::mat4 *world_trans = new glm::mat4(
                                           glm::perspective(45.0f, (float)width/height, 1.0f, 100.0f) *
                                           glm::lookAt(glm::vec3(0.0f, 0.0f, 10.0f), glm::vec3(0.0f, 0.0f, 0.0f),glm::vec3(0.0f, 1.0f, 0.0f))
    );

    glCreateProgram();
    c = new cube::RubikCube();
    
    (*world_trans) *= glm::translate(glm::mat4(1), glm::vec3(0.0f, 0.0f, 0.0f));
    c->set_world_transform(*world_trans);
    
    delete world_trans;
}

cube::Window::~Window(){
    if(window){
        glfwTerminate();        
    }
}

void cube::Window::start() const{
    
    cube::PieceProgram *program = cube::PieceProgram::get_program();
    program->enable();
    
    while(window && (!glfwWindowShouldClose(window))){
        glEnable(GL_DEPTH_TEST);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        glEnable(GL_CULL_FACE);
        glCullFace(GL_BACK);
        glClearColor(1.0f, 1.0f, 1.0f,  1.0f);
        
        glm::mat4 rot = glm::rotate(glm::mat4(1), 0.01f, glm::vec3(0.0f, 1.0f, 0.0f));
        c->add_local_transform(rot);
        
        if(!c->is_rotating()){
            int type = rand() % 6;
            int index = rand() % 3;
            cube::Rotation_Type t =
            type == 0 ? cube::Rotation_Type::x_clock :
            type == 1 ? cube::Rotation_Type::x_counter_clock :
            type == 2 ? cube::Rotation_Type::y_clock :
            type == 3 ? cube::Rotation_Type::y_counter_clock :
            type == 4 ? cube::Rotation_Type::z_clock : cube::Rotation_Type::z_counter_clock;
            c->start_rotation(t, index);
        }
        c->keep_rotating();    
        
        c->render();
        
        glm::mat4 rot1 = glm::rotate(glm::mat4(1), 0.01f, glm::vec3(0.0f, 1.0f, 0.0f));
        
        glfwPollEvents();
        glfwSwapBuffers(window);
    }
    
    program->disable();
}
