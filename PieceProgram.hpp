//
//  PieceProgram.hpp
//  Rubik_Cube
//
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
//
//  Created by 刘罡 on 13/4/2016.
//  Copyright © 2016 刘罡. All rights reserved.
//

#ifndef PieceProgram_hpp
#define PieceProgram_hpp

//#if defined(__linux__)
#include <GL/glew.h>
//#elif defined(__APPLE__) && defined(__MACH__)
//#include <OpenGL/gl3.h>
//    #include <OpenGL/gl3ext.h>
//#endif
#include <FreeImage.h>
#include <glm/glm.hpp>
#include <glm/ext.hpp>

using namespace glm;

namespace cube {
    class PieceProgram final{
    public:
        static PieceProgram* get_program();
        static void delete_program();
    public:
        ~PieceProgram();
        
        void enable();
        void disable();
        
        void set_pvm(const glm::mat4 &pvm) const;
        void set_color(const glm::vec3 &color) const;
        void set_sampler(GLint value) const;
        
        GLint get_position_index() const;
        GLint get_texture_index() const;
        
    private:
        PieceProgram();
        
        GLuint create_shader(const char* src, const GLenum type) const;
        GLuint create_program();
        void init_variables();
        GLuint create_texture() const;
        
        void create_vao();
    private:
        static PieceProgram *piece_program;
        const static char* VERTEX_SHADER;
        const static char* FRAGMENT_SHADER;

        
    private:
        bool program_enabled;
        
        GLuint program;
        GLuint vao;
        GLuint ibo;
        GLuint texture;
        vec3 *color;
        
        GLint text_attrib_index;
        GLint posi_attrib_index;
        GLint color_uni_index;
        GLint trans_uni_index;
        GLint sampler_uni_index;
    };
}

#endif /* PieceProgram_hpp */
