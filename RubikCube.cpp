//
//  RubikCube.cpp
//  Rubik_Cube_2
//
//  Created by 刘罡 on 3/5/2016.
//  Copyright © 2016 刘罡. All rights reserved.
//

#include "RubikCube.hpp"
#include <iostream>
#include <type_traits>

const unsigned int cube::RubikCube::ROTATION_COUNT = 100;

const glm::mat4 cube::RubikCube::ROTATION_X_CLOCK =
    glm::rotate(glm::mat4(1), cube::Square::PI/(2 * ROTATION_COUNT), glm::vec3(1.0f, 0.0f, 0.0f));
const glm::mat4 cube::RubikCube::ROTATION_X_COUNTER_CLOCK =
    glm::rotate(glm::mat4(1), -1 * cube::Square::PI/(2 * ROTATION_COUNT), glm::vec3(1.0f, 0.0f, 0.0f));
const glm::mat4 cube::RubikCube::ROTATION_Y_CLOCK =
    glm::rotate(glm::mat4(1), cube::Square::PI/(2 * ROTATION_COUNT), glm::vec3(0.0f, 1.0f, 0.0f));
const glm::mat4 cube::RubikCube::ROTATION_Y_COUNTER_CLOCK =
    glm::rotate(glm::mat4(1), -1 * cube::Square::PI/(2 * ROTATION_COUNT), glm::vec3(0.0f, 1.0f, 0.0f));
const glm::mat4 cube::RubikCube::ROTATION_Z_CLOCK =
    glm::rotate(glm::mat4(1), cube::Square::PI/(2 * ROTATION_COUNT), glm::vec3(0.0f, 0.0f, 1.0f));
const glm::mat4 cube::RubikCube::ROTATION_Z_COUNTER_CLOCK =
    glm::rotate(glm::mat4(1), -1 * cube::Square::PI/(2 * ROTATION_COUNT), glm::vec3(0.0f, 0.0f, 1.0f));

cube::RubikCube::RubikCube(){
    rotation_transform = nullptr;
    local_transform = new glm::mat4(1.0f);
    world_transform = new glm::mat4(1.0f);
    
    for(int x = 0; x != 3; ++x){
        for(int y = 0; y != 3; ++y){
            for(int z = 0; z != 3; ++z){
                if(x == 1 && y == 1 && z == 1){
                    continue;
                }
                glm::vec3 *white = new glm::vec3(0.0f, 0.0f, 0.0f);
                square[x][y][z] = new cube::Square(*this, glm::vec3((x-1) * 1.0f, (y-1) * 1.0f, (z-1) * 1.0f));
                square[x][y][z]->create_top     (y == 2 ? nullptr : white);
                square[x][y][z]->create_bottom  (y == 0 ? nullptr : white);
                square[x][y][z]->create_front   (z == 2 ? nullptr : white);
                square[x][y][z]->create_back    (z == 0 ? nullptr : white);
                square[x][y][z]->create_left    (x == 0 ? nullptr : white);
                square[x][y][z]->create_right   (x == 2 ? nullptr : white);
                delete white;
            }
        }
    }
    std::cout<<"Done"<<std::endl;
}

cube::RubikCube::~RubikCube(){
    for(int x = 0; x != 3; ++x){
        for(int y = 0; y != 3; ++y){
            for(int z = 0; z != 3; ++z){
                if(x == 1 && y == 1 && z == 1){
                    continue;
                }
                delete square[x][y][z];
            }
        }
    }
}

void cube::RubikCube::render() const{
    for(int x = 0; x != 3; ++x){
        for(int y = 0; y != 3; ++y){
            for(int z = 0; z != 3; ++z){
                if(x == 1 && y == 1 && z == 1){
                    continue;
                }
                square[x][y][z]->render();
            }
        }
    }
}

bool cube::RubikCube::is_rotating() const{
    return rotation != nullptr;
}

void cube::RubikCube::start_rotation(const cube::Rotation_Type &type, const int index){
    if(!is_rotating()){
        rotation = new cube::RubikCube::Rotation(type, index);
    }
}

int cube::RubikCube::Rotation::get_index() const{
    return index;
}

void cube::RubikCube::keep_rotating(){
    if(is_rotating()){
        bool end = rotation->rotate();
        int index = rotation->get_index();
        
//        for(int i = 0; i != 3; ++i){
//            for(int j = 0; j != 3; ++j){
//                if(index == 1 && i == 1 && j == 1){
//                    continue;
//                }
//                switch (rotation->get_rotation_type()) {
//                    case Rotation_Type::x_clock:
//                        square[index][i][j]->add_rotation(cube::RubikCube::ROTATION_X_CLOCK);
//                        break;
//                    case Rotation_Type::x_counter_clock:
//                        square[index][i][j]->add_rotation(cube::RubikCube::ROTATION_X_COUNTER_CLOCK);
//                        break;
//                    case Rotation_Type::y_clock:
//                        square[i][index][j]->add_rotation(cube::RubikCube::ROTATION_Y_CLOCK);
//                        break;
//                    case Rotation_Type::y_counter_clock:
//                        square[i][index][j]->add_rotation(cube::RubikCube::ROTATION_Y_COUNTER_CLOCK);
//                    case Rotation_Type::z_clock:
//                        square[i][j][index]->add_rotation(cube::RubikCube::ROTATION_Z_CLOCK);
//                        break;
//                    case Rotation_Type::z_counter_clock:
//                        square[i][j][index]->add_rotation(cube::RubikCube::ROTATION_Z_COUNTER_CLOCK);
//                    default:
//                        break;
//                }
//            }
//        }
        
        switch (rotation->get_rotation_type()) {
            case Rotation_Type::x_clock:
            case Rotation_Type::x_counter_clock:
                for(int i = 0; i != 3; ++i){
                    for(int j = 0; j != 3; ++j){
                        if(index == 1 && i == 1 && j == 1){
                            continue;
                        }
                        
                        square[index][i][j]->add_rotation(
                        rotation->get_rotation_type() == Rotation_Type::x_clock ?
                                        cube::RubikCube::ROTATION_X_CLOCK :
                                        cube::RubikCube::ROTATION_X_COUNTER_CLOCK
                        );
                    }
                }
                break;
            case Rotation_Type::y_clock:
            case Rotation_Type::y_counter_clock:
                for(int i = 0; i != 3; ++i){
                    for(int j = 0; j != 3; ++j){
                        if(index == 1 && i == 1 && j == 1){
                            continue;
                        }
                        square[i][index][j]->add_rotation(
                        rotation->get_rotation_type() == Rotation_Type::y_clock ?
                                        cube::RubikCube::ROTATION_Y_CLOCK :
                                        cube::RubikCube::ROTATION_Y_COUNTER_CLOCK
                        );
                    }
                }
                break;
            case Rotation_Type::z_clock:
            case Rotation_Type::z_counter_clock:
                for(int i = 0; i != 3; ++i){
                    for(int j = 0; j != 3; ++j){
                        if(index == 1 && i == 1 && j == 1){
                            continue;
                        }
                        square[i][j][index]->add_rotation(
                        rotation->get_rotation_type() == Rotation_Type::z_clock ?
                                            cube::RubikCube::ROTATION_Z_CLOCK :
                                            cube::RubikCube::ROTATION_Z_COUNTER_CLOCK
                        );
                    }
                }
                break;
        }
        
        if(end){
            switch_squares();
            if(rotation != nullptr){
                delete rotation;
                rotation =  nullptr;
            }
        }
        
    }
}

void cube::RubikCube::switch_squares(){
    
    cube::Square *temp;
    int index = rotation->get_index();
    
    switch (rotation->get_rotation_type()) {
        case Rotation_Type::x_clock:
            temp = square[index][2][2];
            square[index][2][2] = square[index][2][0];
            square[index][2][0] = square[index][0][0];
            square[index][0][0] = square[index][0][2];
            square[index][0][2] = temp;
            
            temp = square[index][2][1];
            square[index][2][1] = square[index][1][0];
            square[index][1][0] = square[index][0][1];
            square[index][0][1] = square[index][1][2];
            square[index][1][2] = temp;
            break;
        case Rotation_Type::x_counter_clock:
            temp = square[index][0][0];
            square[index][0][0] = square[index][2][0];
            square[index][2][0] = square[index][2][2];
            square[index][2][2] = square[index][0][2];
            square[index][0][2] = temp;
            
            temp = square[index][2][1];
            square[index][2][1] = square[index][1][2];
            square[index][1][2] = square[index][0][1];
            square[index][0][1] = square[index][1][0];
            square[index][1][0] = temp;
            break;
        case Rotation_Type::y_clock:
            temp = square[2][index][0];
            square[2][index][0] = square[2][index][2];
            square[2][index][2] = square[0][index][2];
            square[0][index][2] = square[0][index][0];
            square[0][index][0] = temp;
            
            temp = square[1][index][0];
            square[1][index][0] = square[2][index][1];
            square[2][index][1] = square[1][index][2];
            square[1][index][2] = square[0][index][1];
            square[0][index][1] = temp;
            break;
        case Rotation_Type::y_counter_clock:
            temp = square[2][index][0];
            square[2][index][0] = square[0][index][0];
            square[0][index][0] = square[0][index][2];
            square[0][index][2] = square[2][index][2];
            square[2][index][2] = temp;
            
            temp = square[1][index][0];
            square[1][index][0] = square[0][index][1];
            square[0][index][1] = square[1][index][2];
            square[1][index][2] = square[2][index][1];
            square[2][index][1] = temp;
            break;
        case Rotation_Type::z_counter_clock:
            temp = square[0][2][index];
            square[0][2][index] = square[0][0][index];
            square[0][0][index] = square[2][0][index];
            square[2][0][index] = square[2][2][index];
            square[2][2][index] = temp;
            
            temp = square[1][0][index];
            square[1][0][index] = square[2][1][index];
            square[2][1][index] = square[1][2][index];
            square[1][2][index] = square[0][1][index];
            square[0][1][index] = temp;
            break;
            
        case Rotation_Type::z_clock:
            temp = square[0][0][index];
            square[0][0][index] = square[0][2][index];
            square[0][2][index] = square[2][2][index];
            square[2][2][index] = square[2][0][index];
            square[2][0][index] = temp;
            
            temp = square[1][0][index];
            square[1][0][index] = square[0][1][index];
            square[0][1][index] = square[1][2][index];
            square[1][2][index] = square[2][1][index];
            square[2][1][index] = temp;
            break;
    }
}

cube::Rotation_Type cube::RubikCube::Rotation::get_rotation_type() const {
    return type;
}

void cube::RubikCube::add_local_transform(glm::mat4 &transform){
    (*local_transform) *= transform;
}

void cube::RubikCube::set_world_transform(glm::mat4 &world_tarnsform){
    if(this->world_transform != nullptr){
        delete this->world_transform;
    }
    this->world_transform = new glm::mat4(world_tarnsform);
}

const glm::mat4 cube::RubikCube::get_transform_to_parent() const{
    return (*local_transform);
}

const glm::mat4 cube::RubikCube::get_transform_to_world() const{
    return (*this->world_transform) * (*local_transform);
}

cube::RubikCube::Rotation::Rotation(const cube::Rotation_Type &type, const int index) : type(type), index(index), cnt(0){
    rotation = new glm::mat4(1.0f);
}

cube::RubikCube::Rotation::~Rotation(){
    if(rotation){
        delete rotation;
    }
}

bool cube::RubikCube::Rotation::rotate(){
    cnt++;
    return cnt >= cube::RubikCube::ROTATION_COUNT;
}