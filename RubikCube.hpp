//
//  RubikCube.hpp
//  Rubik_Cube_2
//
//  Created by 刘罡 on 3/5/2016.
//  Copyright © 2016 刘罡. All rights reserved.
//

#ifndef RubikCube_hpp
#define RubikCube_hpp

#include "Square.hpp"

namespace cube {
    
    enum class Rotation_Type{
        x_clock, x_counter_clock, y_clock, y_counter_clock, z_clock, z_counter_clock
    };
    
    class RubikCube final{
        
    public:
        class Rotation{
        private:            
            int cnt;
            int index;
            cube::Rotation_Type type;
            glm::mat4 *rotation;
        public:
            Rotation(const cube::Rotation_Type &type, const int index);
            ~Rotation();
            
            bool rotate();
            cube::Rotation_Type get_rotation_type() const;
            int get_index() const;
        };
        
    public:
        RubikCube();
        ~RubikCube();
        
        void add_local_transform(glm::mat4 &transform);
        void set_world_transform(glm::mat4 &world_tarnsform);
        
        void render() const;
        
        const glm::mat4 get_transform_to_parent() const;
        const glm::mat4 get_transform_to_world() const;
        
        bool is_rotating() const;
        void start_rotation(const cube::Rotation_Type &type, const int index);
        void keep_rotating();
        
    private:
        const static unsigned int ROTATION_COUNT;
        const static glm::mat4 ROTATION_X_CLOCK;
        const static glm::mat4 ROTATION_X_COUNTER_CLOCK;
        const static glm::mat4 ROTATION_Y_CLOCK;
        const static glm::mat4 ROTATION_Y_COUNTER_CLOCK;
        const static glm::mat4 ROTATION_Z_CLOCK;
        const static glm::mat4 ROTATION_Z_COUNTER_CLOCK;
        
        void switch_squares();
        cube::RubikCube::Rotation *rotation;
        glm::mat4 *rotation_transform;
        glm::mat4 *local_transform;
        glm::mat4 *world_transform;
        cube::Square *square[3][3][3];
    };
    
    
}

#endif /* RubikCube_hpp */
