//
//  Piece.hpp
//  Rubik_Cube_2
//
//  Created by 刘罡 on 3/5/2016.
//  Copyright © 2016 刘罡. All rights reserved.
//

#ifndef Piece_hpp
#define Piece_hpp

//#if defined(__linux__)
#include <GL/glew.h>
//#elif defined(__APPLE__) && defined(__MACH__)
//#include <OpenGL/gl3.h>
//    #include <OpenGL/gl3ext.h>
//#endif
#include <glm/glm.hpp>
#include <glm/ext.hpp>
#include "PieceProgram.hpp"


namespace cube{
    
    class Square;
    
    class Piece final{
    public:
        Piece(cube::Square &parent, const glm::mat4 *trans, const glm::vec3 *color);
        ~Piece();
        void render() const;
        
    private:
        cube::Square *parent;
        glm::mat4 *transform;
        glm::vec3 *color;
        
    private:
        const static GLfloat POSITION[12];
        const static GLfloat TEXTURE[8];
        const static GLushort INDICIES[6];
        
        static GLuint *vao;        
        static GLuint *vbo;
        static GLuint *ibo;
        static GLuint *texture;
        static cube::PieceProgram *program;
        static unsigned int counter;
        
        void static create_vao();
        void static create_texture();
    };
}

#endif /* Piece_hpp */
