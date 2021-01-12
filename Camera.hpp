//
//  Camera.hpp
//  Rubik_Cube_2
//
//                       _oo0oo_
//                      o8888888o
//                      88" . "88
//                      (| -_- |)
//                      0\  =  /0
//                    ___/`---'\___
//                  .' \\|     |// '.
//                 / \\|||  :  |||// \
//                / _||||| -:- |||||- \
//               |   | \\\  -  /// |   |
//               | \_|  ''\---/''  |_/ |
//               \  .-\__  '-'  ___/-. /
//             ___'. .'  /--.--\  `. .'___
//          ."" '<  `.___\_<|>_/___.' >' "".
//         | | :  `- \`.;`\ _ /`;.`/ - ` : | |
//         \  \ `_.   \_ __\ /__ _/   .-` /  /
//     =====`-.____`.___ \_____/___.-`___.-'=====
//                       `=---='
//
//     ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//           佛祖保佑                永无BUG
//
//  Created by 刘罡 on 6/5/16.
//  Copyright © 2016 刘罡. All rights reserved.
//

#ifndef Camera_hpp
#define Camera_hpp

//#if defined(__linux__)
#include <GL/glew.h>
//#elif defined(__APPLE__) && defined(__MACH__)
//    #include <OpenGL/gl3.h>
//    #include <OpenGL/gl3ext.h>
//#endif

#include <glm/glm.hpp>
#include <glm/ext.hpp>

using namespace glm;
namespace klm{
    class fps_camera final{
    private:
        const static GLfloat ROTATION_SPEED;
        const static GLfloat MOVING_SPEED;
        const static vec3 X_AXIS;
        const static vec3 Y_AXIS;
        
        GLfloat yaw_angle;
        GLfloat pitch_angle;
        vec3 *forward_dir;
        vec3 *right_dir;
        vec3 *position;
        
        mat4 yaw(const GLfloat angle);
        mat4 pitch(const GLfloat angle);        
        void rotate_dir();
        
    public:
        fps_camera();
        ~fps_camera();
        
        void yaw_left();
        void yaw_right();
        void pitch_up();
        void pitch_down();
        
        void forward();
        void backward();
        void left();
        void right();
        
        mat4 get_viewing_matrx() const;
    };
}

#endif /* Camera_hpp */
