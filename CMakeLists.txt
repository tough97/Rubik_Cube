cmake_minimum_required(VERSION 3.9)

set(PROJECT_NAME Rubik_Cube_2)
#set(PROJECT_NAME RubikCube)
project(${PROJECT_NAME})

set(CMAKE_CXX_STANDARD 11)

find_package(OpenGL REQUIRED)

find_package(GLEW 2.0 REQUIRED)
if(GLEW_FOUND)
    include_directories(${GLEW_INCLUDE_DIRS})
    link_libraries(${GLEW_LIBRARIES})
    message(STATUS "GLEW 2.0 found")
endif()

if(OPENGL_FOUND)
    message(STATUS "OpenGL is found")
else (OPENGL_FOUND)
    message(STATUS "Moving on, OpenGL not found")
endif(OPENGL_FOUND)

find_package(glfw3 REQUIRED)
if(glfw3_FOUND)
    message(STATUS "glfw found")
    include_directories(${GLFW3_INCLUDE_DIRS})
    link_libraries(${GLFW3_LIBRARIES})
else(glfw3_FOUND)
    message(STATUS "glfw not found")
endif(glfw3_FOUND)

find_package(JNI REQUIRED)
if(JNI_FOUND)
    include_directories(${JNI_INCLUDE_DIRS})
endif(JNI_FOUND)

set(FREEIMAGE_LIBRARY_AND_HEADER_DIRRECTORY libs/FreeImage)
find_path(FREEIMAGE_LIBRARY_AND_HEADER_DIRRECTORY FreeImage.h)
include_directories(${FREEIMAGE_LIBRARY_AND_HEADER_DIRRECTORY})

SET(GCC_COVERAGE_COMPILE_FLAGS "-fprofile-arcs -ftest-coverage")
SET(GCC_COVERAGE_LINK_FLAGS    "-lgcov")

#add_executable(${PROJECT_NAME} Camera.hpp Camera.cpp main.cpp Piece.cpp Piece.hpp PieceProgram.hpp PieceProgram.cpp RubikCube.hpp RubikCube.cpp Square.hpp Square.cpp Window.hpp Window.cpp Student.cpp Student.h)
#target_link_libraries(${PROJECT_NAME} glfw ${OPENGL_LIBRARIES} freeimage)

add_library(RubikCube STATIC ${GLFW_LIBRARIES} Camera.hpp Camera.cpp main.cpp Piece.cpp Piece.hpp PieceProgram.hpp PieceProgram.cpp RubikCube.hpp RubikCube.cpp Square.hpp Square.cpp Window.hpp Window.cpp Student.cpp Student.h RubikCube.h RubikCubeRun.cpp)
install(TARGETS RubikCube DESTINATION .)
