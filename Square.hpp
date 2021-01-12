//
//  Square.hpp
//  Rubik_Cube_2
//
//  Created by 刘罡 on 3/5/2016.
//  Copyright © 2016 刘罡. All rights reserved.
//

#ifndef Square_hpp
#define Square_hpp

#include "Piece.hpp"
#include <vector>

namespace cube{
    class RubikCube;
    
    class Square final{
    public:
        
        Square(cube::RubikCube &parent, const glm::vec3 &translate);
        ~Square();
        const glm::mat4 get_transform_to_parent() const;
        const glm::mat4 get_transform_to_world() const;
        cube::Square& create_front(const glm::vec3 *color);
        cube::Square& create_back(const glm::vec3 *color);
        cube::Square& create_right(const glm::vec3 *color);
        cube::Square& create_left(const glm::vec3 *color);
        cube::Square& create_top(const glm::vec3 *color);
        cube::Square& create_bottom(const glm::vec3 *color);
        
        void render() const;
        void add_rotation(const glm::mat4 &rotation);
        void set_rotation(const glm::mat4 &rotation);
        
        const static GLfloat PI;
    private:
        cube::RubikCube *parent;
        glm::mat4 *rotation;
        glm::mat4 *translate;
        std::vector<cube::Piece*> *pieces;
        void create_face(const vec3& color, const mat4& trans);
    private:
        const static vec3 FRONT_COLOR;
        const static mat4 FRONT_TRANS;
        const static vec3 BACK_COLOR;
        const static mat4 BACK_TRANS;
        const static vec3 RIGHT_COLOR;
        const static mat4 RIGHT_TRANS;
        const static vec3 LEFT_COLOR;
        const static mat4 LEFT_TRANS;
        const static vec3 TOP_COLOR;
        const static mat4 TOP_TRANS;
        const static vec3 BOTTOM_COLOR;
        const static mat4 BOTTOM_TRANS;
    };
}

#endif /* Square_hpp */
