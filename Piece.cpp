//
//  Piece.cpp
//  Rubik_Cube_2
//
//  Created by 刘罡 on 3/5/2016.
//  Copyright © 2016 刘罡. All rights reserved.
//

#include "Piece.hpp"
#include "Square.hpp"
#include <FreeImage.h>
#include <iostream>

const GLfloat cube::Piece::POSITION[12] = {
    -0.5f, -0.5f,  0.0f,
     0.5f, -0.5f,  0.0f,
     0.5f,  0.5f,  0.0f,
    -0.5f,  0.5f,  0.0f,
};

const GLfloat cube::Piece::TEXTURE[8] ={
    0.0f, 0.0f,
    1.0f, 0.0f,
    1.0f, 1.0f,
    0.0f, 1.0f,
};

const GLushort cube::Piece::INDICIES[6] ={
    0, 1, 2,
    2, 3, 0
};

unsigned int cube::Piece::counter = 0;

cube::PieceProgram* cube::Piece::program = nullptr;

GLuint* cube::Piece::vao     = nullptr;
GLuint* cube::Piece::ibo     = nullptr;
GLuint* cube::Piece::vbo     = nullptr;
GLuint* cube::Piece::texture = nullptr;

cube::Piece::Piece(cube::Square &parent, const mat4 *trans, const vec3 *color){
    if(program == nullptr){
        program = PieceProgram::get_program();
    }
    if(vao == nullptr){
        create_vao();
    }
    if(texture == nullptr){
        create_texture();
    }
    
    this->transform = (trans == nullptr ? new mat4(1.0f) : new mat4(*trans));
    this->color = (color == nullptr ? new vec3(0.0f, 0.0f, 0.0f) : new vec3(*color));
    this->parent = &parent;
    counter++;
}

cube::Piece::~Piece(){
    delete transform;
    delete color;
    
    counter--;
    if(counter == 0){
        glDeleteBuffers(1, ibo);
        delete ibo;
        
        glDeleteBuffers(1, vbo);
        delete vbo;
        
        glDeleteVertexArrays(1, vao);
        delete vao;
        
        glDeleteTextures(1, texture);
        delete texture;
        
        delete program;
    }
}

void cube::Piece::create_texture(){
    
    const char* name = "/home/gang_liu/develop/C++/project/Rubik_Cube_2/face.jpg";
    texture = new GLuint;
    
    glGenTextures(1, texture);
    glBindTexture(GL_TEXTURE_2D, *texture);
    
#ifdef FREEIMAGE_LIB
    FreeImage_Initialise();
#endif
    
    FIBITMAP *bitmap = nullptr;
    FREE_IMAGE_FORMAT format = FreeImage_GetFileType(name, 0);
    if(format == FIF_UNKNOWN){
        format = FreeImage_GetFIFFromFilename(name);
    } else if(format != FIF_UNKNOWN && FreeImage_FIFSupportsReading(format)){
        bitmap = FreeImage_Load(format, name);
    } else {
        bitmap = nullptr;
    }
    
    if(bitmap){
        unsigned int w = FreeImage_GetWidth(bitmap);
        unsigned int h = FreeImage_GetHeight(bitmap);
        
        //get bits per pixel(BPP)
        unsigned int pixSize = FreeImage_GetBPP(bitmap);
        
        BYTE *data = (BYTE*)FreeImage_GetBits(bitmap);
        
        const GLenum formatEnum = pixSize == 24 ? GL_RGB : pixSize == 32 ? GL_RGB : GL_NO_ERROR;
        
        
        if(formatEnum == GL_NO_ERROR){
            std::cout<<"unsupported texture image"<<std::endl;
        } else {
            glTexImage2D(GL_TEXTURE_2D, 0, formatEnum, w, h, 0, formatEnum, GL_UNSIGNED_BYTE, (GLvoid*) data);
            glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
            glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
            glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
            glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
        }
    }
    
    FreeImage_Unload(bitmap);
#ifdef FREEIMAGE_LIB
    FreeImage_DeInitialise();
#endif
    
    program->enable();
    program->set_sampler(0);
    program->disable();
    
    glActiveTexture(GL_TEXTURE0);
    glBindTexture(GL_TEXTURE_2D, 0);
}

void cube::Piece::create_vao(){
    vbo = new GLuint;
    glGenBuffers(1, vbo);
    glBindBuffer(GL_ARRAY_BUFFER, *vbo);
    glBufferData(GL_ARRAY_BUFFER, sizeof(POSITION) + sizeof(TEXTURE), nullptr, GL_STATIC_DRAW);
    
    glBufferSubData(GL_ARRAY_BUFFER, 0, sizeof(POSITION), POSITION);
    glBufferSubData(GL_ARRAY_BUFFER, sizeof(POSITION), sizeof(TEXTURE), TEXTURE);
    
    ibo = new GLuint;
    glGenBuffers(1, ibo);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, *ibo);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(INDICIES), INDICIES, GL_STATIC_DRAW);
    
    cube::PieceProgram *program = cube::PieceProgram::get_program();
    program->enable();
    {
        vao = new GLuint;
        glGenVertexArrays(1, vao);
        glBindVertexArray(*vao);
        {
            glBindBuffer(GL_ARRAY_BUFFER, *vbo);
            glVertexAttribPointer(program->get_position_index(), 3, GL_FLOAT, GL_FALSE, 0, 0);
            glEnableVertexAttribArray(program->get_position_index());
            glVertexAttribPointer(program->get_texture_index(), 2, GL_FLOAT, GL_FALSE, 0, (void*)sizeof(POSITION));
            glEnableVertexAttribArray(program->get_texture_index());
        }
        glBindVertexArray(0);
        
    }
    program->disable();
}

void cube::Piece::render() const {
    program->enable();
    
    program->set_pvm(parent->get_transform_to_world() * (*(this->transform)));
    program->set_color(*(this->color));
    
    glActiveTexture(GL_TEXTURE0);
    program->set_sampler(0);
    
    glActiveTexture(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, *texture);
    
    glBindVertexArray(*vao);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, *ibo);
    {
        glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_SHORT, nullptr);
    }
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
    glBindVertexArray(0);
    glBindTexture(GL_TEXTURE_2D, 0);
    
    glBindVertexArray(0);
    program->disable();
}