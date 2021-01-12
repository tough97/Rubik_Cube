//
//  PieceProgram.cpp
//  Rubik_Cube
//
//  Created by 刘罡 on 13/4/2016.
//  Copyright © 2016 刘罡. All rights reserved.
//

#include "PieceProgram.hpp"
#include <stdexcept>
#include <iostream>

using namespace std;

const char* cube::PieceProgram::VERTEX_SHADER =
"#version 400\n"
"in vec3 position;\n"
"in vec2 text_coord;\n"
"uniform vec3 color;\n"
"uniform mat4 transform;\n"
"out vec3 vs_color;\n"
"out vec2 vs_text_coord;\n"
"void main(){\n"
"   gl_Position = transform * vec4(position, 1.0);\n"
"   vs_color = color;\n"
"   vs_text_coord = text_coord;\n"
"}";

const char * cube::PieceProgram::FRAGMENT_SHADER =
"#version 400\n"
"in vec3 vs_color;\n"
"in vec2 vs_text_coord;\n"
"uniform sampler2D sampler;\n"
"out vec4 frag_color;\n"
"void main(){\n"
"   vec4 tc = texture(sampler, vs_text_coord);\n"
"   frag_color = vec4(vs_color, 1.0) * tc.zyxw;\n"
"}";


cube::PieceProgram* cube::PieceProgram::piece_program = nullptr;

cube::PieceProgram* cube::PieceProgram::get_program(){
    if(piece_program == nullptr){
        piece_program = new PieceProgram();
    }
    return piece_program;
}

void cube::PieceProgram::delete_program(){
    if(piece_program != nullptr){
        delete piece_program;
    }
}

cube::PieceProgram::PieceProgram(){
    try{
        program = create_program();
        program_enabled = false;
    } catch (const runtime_error &err){
        cout<<err.what()<<endl;
    }
}

cube::PieceProgram::~PieceProgram(){
    glDeleteProgram(program);
}

GLuint cube::PieceProgram::create_shader(const char* src, const GLenum type) const{
    GLuint shader = glCreateShader(type);
    glShaderSource(shader, 1, &src, nullptr);    
    glCompileShader(shader);
    
    GLint status = 0;
    glGetShaderiv(shader, GL_COMPILE_STATUS, &status);
    if(status == GL_FALSE){
        GLint length;
        glGetShaderiv(shader, GL_INFO_LOG_LENGTH, &length);
        string message("Failed to create ");
        message += (type == GL_VERTEX_SHADER ? "vertex shade:\n" : "fragment shader:\n");
        std::cout<<"length = "<<length<<std::endl;
        
        char *detail = new char[length];
        glGetShaderInfoLog(shader, length, &length, detail);
        message += detail;
        delete[] detail;
        
        glDeleteShader(shader);
        std::cout<<message<<std::endl;
        throw runtime_error(message);
    }
    return shader;
}


GLuint cube::PieceProgram::create_program(){
    program = glCreateProgram();
    try{
        GLuint vs = create_shader(VERTEX_SHADER, GL_VERTEX_SHADER);
        GLuint fs = create_shader(FRAGMENT_SHADER, GL_FRAGMENT_SHADER);
        glAttachShader(program, vs);
        glAttachShader(program, fs);
        
        glLinkProgram(program);
        
        GLint status;
        glGetProgramiv(program, GL_LINK_STATUS, &status);
        if(status == GL_FALSE){
            string message("Failed to link program ");
            GLint length;
            glGetProgramiv(program, GL_INFO_LOG_LENGTH, &length);
            
            char *detail = new char[length];
            message += detail;
            
            std::string detail_message(detail);
            delete[] detail;
            
            throw runtime_error(detail_message);
            
        }
        init_variables();
    } catch(runtime_error &e){
        std::cout<<"failed : "<<e.what()<<std::endl;
        throw runtime_error(e);
    }
    
    return program;
}

void cube::PieceProgram::init_variables(){
    text_attrib_index = glGetAttribLocation (program, "text_coord");
    posi_attrib_index = glGetAttribLocation (program, "position");
    color_uni_index   = glGetUniformLocation(program, "color");
    trans_uni_index   = glGetUniformLocation(program, "transform");
    sampler_uni_index = glGetUniformLocation(program, "sampler");
}

void cube::PieceProgram::enable(){
    if(!program_enabled){
        glUseProgram(program);
        program_enabled = true;
    }
}

void cube::PieceProgram::disable(){
    if(program_enabled){
        glUseProgram(0);
        program_enabled = false;
    }
}

void cube::PieceProgram::set_pvm(const glm::mat4 &pvm) const{
    glUniformMatrix4fv(trans_uni_index, 1, GL_FALSE, glm::value_ptr(pvm));
}

void cube::PieceProgram::set_color(const glm::vec3 &color) const{
    glUniform3fv(color_uni_index, 1, glm::value_ptr(color));
}

GLint cube::PieceProgram::get_position_index() const{
    return posi_attrib_index;
}

GLint cube::PieceProgram::get_texture_index() const{
    return text_attrib_index;
}

void cube::PieceProgram::set_sampler(GLint value) const{
    glUniform1i(sampler_uni_index, value);
}