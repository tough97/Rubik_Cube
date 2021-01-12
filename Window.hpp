//
//  Window.hpp
//  Rubik_Cube
//
//
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
//
//
//  Created by 刘罡 on 13/4/2016.
//  Copyright © 2016 刘罡. All rights reserved.
//

#ifndef Window_hpp
#define Window_hpp


#include <string>
#include <stdexcept>

#include "RubikCube.hpp"
#include "Camera.hpp"

#include <GLFW/glfw3.h>

namespace cube {
    
    class Window final {
    public:
        Window(const int width, const int height, const std::string title);
        ~Window();
        void start() const;
    private:
        void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods);
        
        klm::fps_camera *camera;
        cube::RubikCube *c;
        
        int direction;
        int index;
        bool in_motion;
        
        int width;
        int height;
        std::string title;
        GLFWwindow *window;
    };
}

#endif /* Window_hpp */
