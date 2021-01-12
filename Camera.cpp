//
//  Camera.cpp
//  Rubik_Cube_2
//
//  Created by 刘罡 on 6/5/16.
//  Copyright © 2016 刘罡. All rights reserved.
//

#include "Camera.hpp"

using namespace klm;
using namespace glm;

const GLfloat fps_camera::ROTATION_SPEED = 0.001f;
const GLfloat fps_camera::MOVING_SPEED = 0.5f;
const vec3 fps_camera::X_AXIS = vec3(1.0f, 0.0f, 0.0f);
const vec3 fps_camera::Y_AXIS = vec3(0.0f, 1.0f, 0.0f);

fps_camera::fps_camera():yaw_angle(0.0f), pitch_angle(0.0f){
    forward_dir = new vec3(0.0f, 0.0f, 1.0f);
    right_dir = new vec3(1.0f, 0.0f, 0.0f);
    position = new vec3(0.0f, 0.0f, -10.0f);
}

fps_camera::~fps_camera(){
    if(forward_dir){
        delete forward_dir;
    }
    if(right_dir){
        delete right_dir;
    }
    if(position){
        delete position;
    }
}

void fps_camera::rotate_dir(){
    mat4 rot = rotate(glm::mat4(1), yaw_angle, Y_AXIS) * rotate(glm::mat4(1), pitch_angle, X_AXIS);
    vec4 temp(*forward_dir, 0.0f);
    temp = rot * temp;
    if(temp.w != 0.0f){
        temp /= temp.x;
    }
    forward_dir->x = temp.x;
    forward_dir->y = temp.y;
    forward_dir->z = temp.z;
    
    (*right_dir) = cross(Y_AXIS, (*forward_dir));
}

void fps_camera::forward(){
    (*position) += vec3((*forward_dir).x, 0.0f ,(*forward_dir).z);
}

void fps_camera::backward(){
    (*position) -= vec3((*forward_dir).x, 0.0f ,(*forward_dir).z);
}

void fps_camera::left(){
    (*position) -= vec3((*right_dir).x, 0.0f ,(*right_dir).z);
}

void fps_camera::right(){
    (*position) += vec3((*right_dir).x, 0.0f ,(*right_dir).z);
}

void fps_camera::yaw_left(){
    yaw_angle -= ROTATION_SPEED;
}

void fps_camera::yaw_right(){
    yaw_angle += ROTATION_SPEED;
}

void fps_camera::pitch_up(){
    pitch_angle += ROTATION_SPEED;
}

void fps_camera::pitch_down(){
    pitch_angle -= ROTATION_SPEED;
}

mat4 fps_camera::get_viewing_matrx() const{
    return lookAt((*position), (*position)+(*forward_dir), Y_AXIS);
}