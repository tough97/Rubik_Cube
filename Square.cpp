//
//  Square.cpp
//  Rubik_Cube_2
//
//  Created by 刘罡 on 3/5/2016.
//  Copyright © 2016 刘罡. All rights reserved.
//

#include "Square.hpp"
#include "RubikCube.hpp"

const GLfloat cube::Square::PI = 3.14159265358979323846f;

const vec3 cube::Square::FRONT_COLOR =  glm::vec3(1.0f, 0.0f, 0.0f);
const mat4 cube::Square::FRONT_TRANS =  glm::translate(glm::mat4(1), glm::vec3(0.0f, 0.0f, 0.5f));
const vec3 cube::Square::BACK_COLOR  =  glm::vec3(1.0f, 0.6f, 0.0f);
const mat4 cube::Square::BACK_TRANS  =  glm::translate(glm::mat4(1), glm::vec3(0.0f, 0.0f, -0.5f)) *
                                        glm::rotate(glm::mat4(1), PI, glm::vec3(0.0f, 1.0f, 0.0f));
const vec3 cube::Square::RIGHT_COLOR =  glm::vec3(0.0f, 1.0f, 0.0f);
const mat4 cube::Square::RIGHT_TRANS =  glm::translate(glm::mat4(1), glm::vec3(0.5f, 0.0f, 0.0f)) *
                                        glm::rotate(glm::mat4(1), PI/2, glm::vec3(0.0f, 1.0f, 0.0f));
const vec3 cube::Square::LEFT_COLOR  =  glm::vec3(0.0f, 0.0f, 1.0f);
const mat4 cube::Square::LEFT_TRANS  =  glm::translate(glm::mat4(1), glm::vec3(-0.5f, 0.0f, 0.0f)) *
                                        glm::rotate(glm::mat4(1), -1 * PI/2, glm::vec3(0.0f, 1.0f, 0.0f));
const vec3 cube::Square::TOP_COLOR   =  glm::vec3(1.0f, 1.0f, 0.0f);
const mat4 cube::Square::TOP_TRANS   =  glm::translate(glm::mat4(1), glm::vec3(0.0f, 0.5f, 0.0f)) *
                                        glm::rotate(glm::mat4(1), -1 * PI/2, glm::vec3(1.0f, 0.0f, 0.0f));
const vec3 cube::Square::BOTTOM_COLOR = glm::vec3(1.0f, 1.0f, 1.0f);
const mat4 cube::Square::BOTTOM_TRANS = glm::translate(glm::mat4(1), glm::vec3(0.0f, -0.5f, 0.0f)) *
                                        glm::rotate(glm::mat4(1), PI/2, glm::vec3(1.0f, 0.0f, 0.0f));

cube::Square::Square(cube::RubikCube &parent, const glm::vec3 &translate){
    this->parent = &parent;
    this->translate = new glm::mat4(glm::translate(glm::mat4(1), translate));
    this->rotation = new glm::mat4(1.0f);
    pieces = new std::vector<cube::Piece*>();
}

cube::Square::~Square(){
    for(auto p = pieces->begin(); p != pieces->end(); ++p){
        delete (*p);
    }
    delete translate;
    delete rotation;
    delete pieces;
}

void cube::Square::render() const{
    for(auto p = pieces->begin(); p != pieces->end(); ++p){
        (*p)->render();
    }
}

void cube::Square::add_rotation(const glm::mat4 &rotation){    
    (*this->rotation) = rotation * (*this->rotation);
//    (*this->rotation) *= rotation;
}

void cube::Square::set_rotation(const glm::mat4 &rotation){
    if(this->rotation != nullptr){
        delete this->rotation;
    }
    this->rotation = new glm::mat4(rotation);
}

const glm::mat4 cube::Square::get_transform_to_parent() const{
    return (*this->rotation) * (*this->translate);
}
const glm::mat4 cube::Square::get_transform_to_world() const{
    return parent->get_transform_to_world() * get_transform_to_parent();
}

cube::Square& cube::Square::create_front(const glm::vec3 *color){
    create_face(color == nullptr ? FRONT_COLOR : *color, FRONT_TRANS);
    return *this;
}

cube::Square& cube::Square::create_back(const glm::vec3 *color){
    create_face(color == nullptr ? BACK_COLOR : *color, BACK_TRANS);
    return *this;
}

cube::Square& cube::Square::create_top(const glm::vec3 *color){
    create_face(color == nullptr ? TOP_COLOR : *color, TOP_TRANS);
    return *this;
}

cube::Square& cube::Square::create_bottom(const glm::vec3 *color){
    create_face(color == nullptr ? BOTTOM_COLOR : *color, BOTTOM_TRANS);
    return *this;
}

cube::Square& cube::Square::create_left(const glm::vec3 *color){
    create_face(color == nullptr ? LEFT_COLOR : *color, LEFT_TRANS);
    return *this;
}

cube::Square& cube::Square::create_right(const glm::vec3 *color){
    create_face(color == nullptr ? RIGHT_COLOR : *color, RIGHT_TRANS);
    return *this;
}

void cube::Square::create_face(const vec3 &color, const mat4 &trans){
    pieces->push_back(new cube::Piece(*this, &trans, &color));
}
