# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.15

# Default target executed when no arguments are given to make.
default_target: all

.PHONY : default_target

# Allow only one "make -f Makefile2" at a time, but pass parallelism.
.NOTPARALLEL:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /home/gang_liu/develop/C++/clion-2019.2/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /home/gang_liu/develop/C++/clion-2019.2/bin/cmake/linux/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/gang_liu/develop/C++/project/Rubik_Cube_2

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/gang_liu/develop/C++/project/Rubik_Cube_2

#=============================================================================
# Targets provided globally by CMake.

# Special rule for the target install/strip
install/strip: preinstall
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Installing the project stripped..."
	/home/gang_liu/develop/C++/clion-2019.2/bin/cmake/linux/bin/cmake -DCMAKE_INSTALL_DO_STRIP=1 -P cmake_install.cmake
.PHONY : install/strip

# Special rule for the target install/strip
install/strip/fast: preinstall/fast
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Installing the project stripped..."
	/home/gang_liu/develop/C++/clion-2019.2/bin/cmake/linux/bin/cmake -DCMAKE_INSTALL_DO_STRIP=1 -P cmake_install.cmake
.PHONY : install/strip/fast

# Special rule for the target edit_cache
edit_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "No interactive CMake dialog available..."
	/home/gang_liu/develop/C++/clion-2019.2/bin/cmake/linux/bin/cmake -E echo No\ interactive\ CMake\ dialog\ available.
.PHONY : edit_cache

# Special rule for the target edit_cache
edit_cache/fast: edit_cache

.PHONY : edit_cache/fast

# Special rule for the target rebuild_cache
rebuild_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Running CMake to regenerate build system..."
	/home/gang_liu/develop/C++/clion-2019.2/bin/cmake/linux/bin/cmake -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR)
.PHONY : rebuild_cache

# Special rule for the target rebuild_cache
rebuild_cache/fast: rebuild_cache

.PHONY : rebuild_cache/fast

# Special rule for the target list_install_components
list_install_components:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Available install components are: \"Unspecified\""
.PHONY : list_install_components

# Special rule for the target list_install_components
list_install_components/fast: list_install_components

.PHONY : list_install_components/fast

# Special rule for the target install/local
install/local: preinstall
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Installing only the local directory..."
	/home/gang_liu/develop/C++/clion-2019.2/bin/cmake/linux/bin/cmake -DCMAKE_INSTALL_LOCAL_ONLY=1 -P cmake_install.cmake
.PHONY : install/local

# Special rule for the target install/local
install/local/fast: preinstall/fast
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Installing only the local directory..."
	/home/gang_liu/develop/C++/clion-2019.2/bin/cmake/linux/bin/cmake -DCMAKE_INSTALL_LOCAL_ONLY=1 -P cmake_install.cmake
.PHONY : install/local/fast

# Special rule for the target install
install: preinstall
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Install the project..."
	/home/gang_liu/develop/C++/clion-2019.2/bin/cmake/linux/bin/cmake -P cmake_install.cmake
.PHONY : install

# Special rule for the target install
install/fast: preinstall/fast
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Install the project..."
	/home/gang_liu/develop/C++/clion-2019.2/bin/cmake/linux/bin/cmake -P cmake_install.cmake
.PHONY : install/fast

# The main all target
all: cmake_check_build_system
	$(CMAKE_COMMAND) -E cmake_progress_start /home/gang_liu/develop/C++/project/Rubik_Cube_2/CMakeFiles /home/gang_liu/develop/C++/project/Rubik_Cube_2/CMakeFiles/progress.marks
	$(MAKE) -f CMakeFiles/Makefile2 all
	$(CMAKE_COMMAND) -E cmake_progress_start /home/gang_liu/develop/C++/project/Rubik_Cube_2/CMakeFiles 0
.PHONY : all

# The main clean target
clean:
	$(MAKE) -f CMakeFiles/Makefile2 clean
.PHONY : clean

# The main clean target
clean/fast: clean

.PHONY : clean/fast

# Prepare targets for installation.
preinstall: all
	$(MAKE) -f CMakeFiles/Makefile2 preinstall
.PHONY : preinstall

# Prepare targets for installation.
preinstall/fast:
	$(MAKE) -f CMakeFiles/Makefile2 preinstall
.PHONY : preinstall/fast

# clear depends
depend:
	$(CMAKE_COMMAND) -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles/Makefile.cmake 1
.PHONY : depend

#=============================================================================
# Target rules for targets named RubikCube

# Build rule for target.
RubikCube: cmake_check_build_system
	$(MAKE) -f CMakeFiles/Makefile2 RubikCube
.PHONY : RubikCube

# fast build rule for target.
RubikCube/fast:
	$(MAKE) -f CMakeFiles/RubikCube.dir/build.make CMakeFiles/RubikCube.dir/build
.PHONY : RubikCube/fast

Camera.o: Camera.cpp.o

.PHONY : Camera.o

# target to build an object file
Camera.cpp.o:
	$(MAKE) -f CMakeFiles/RubikCube.dir/build.make CMakeFiles/RubikCube.dir/Camera.cpp.o
.PHONY : Camera.cpp.o

Camera.i: Camera.cpp.i

.PHONY : Camera.i

# target to preprocess a source file
Camera.cpp.i:
	$(MAKE) -f CMakeFiles/RubikCube.dir/build.make CMakeFiles/RubikCube.dir/Camera.cpp.i
.PHONY : Camera.cpp.i

Camera.s: Camera.cpp.s

.PHONY : Camera.s

# target to generate assembly for a file
Camera.cpp.s:
	$(MAKE) -f CMakeFiles/RubikCube.dir/build.make CMakeFiles/RubikCube.dir/Camera.cpp.s
.PHONY : Camera.cpp.s

Piece.o: Piece.cpp.o

.PHONY : Piece.o

# target to build an object file
Piece.cpp.o:
	$(MAKE) -f CMakeFiles/RubikCube.dir/build.make CMakeFiles/RubikCube.dir/Piece.cpp.o
.PHONY : Piece.cpp.o

Piece.i: Piece.cpp.i

.PHONY : Piece.i

# target to preprocess a source file
Piece.cpp.i:
	$(MAKE) -f CMakeFiles/RubikCube.dir/build.make CMakeFiles/RubikCube.dir/Piece.cpp.i
.PHONY : Piece.cpp.i

Piece.s: Piece.cpp.s

.PHONY : Piece.s

# target to generate assembly for a file
Piece.cpp.s:
	$(MAKE) -f CMakeFiles/RubikCube.dir/build.make CMakeFiles/RubikCube.dir/Piece.cpp.s
.PHONY : Piece.cpp.s

PieceProgram.o: PieceProgram.cpp.o

.PHONY : PieceProgram.o

# target to build an object file
PieceProgram.cpp.o:
	$(MAKE) -f CMakeFiles/RubikCube.dir/build.make CMakeFiles/RubikCube.dir/PieceProgram.cpp.o
.PHONY : PieceProgram.cpp.o

PieceProgram.i: PieceProgram.cpp.i

.PHONY : PieceProgram.i

# target to preprocess a source file
PieceProgram.cpp.i:
	$(MAKE) -f CMakeFiles/RubikCube.dir/build.make CMakeFiles/RubikCube.dir/PieceProgram.cpp.i
.PHONY : PieceProgram.cpp.i

PieceProgram.s: PieceProgram.cpp.s

.PHONY : PieceProgram.s

# target to generate assembly for a file
PieceProgram.cpp.s:
	$(MAKE) -f CMakeFiles/RubikCube.dir/build.make CMakeFiles/RubikCube.dir/PieceProgram.cpp.s
.PHONY : PieceProgram.cpp.s

RubikCube.o: RubikCube.cpp.o

.PHONY : RubikCube.o

# target to build an object file
RubikCube.cpp.o:
	$(MAKE) -f CMakeFiles/RubikCube.dir/build.make CMakeFiles/RubikCube.dir/RubikCube.cpp.o
.PHONY : RubikCube.cpp.o

RubikCube.i: RubikCube.cpp.i

.PHONY : RubikCube.i

# target to preprocess a source file
RubikCube.cpp.i:
	$(MAKE) -f CMakeFiles/RubikCube.dir/build.make CMakeFiles/RubikCube.dir/RubikCube.cpp.i
.PHONY : RubikCube.cpp.i

RubikCube.s: RubikCube.cpp.s

.PHONY : RubikCube.s

# target to generate assembly for a file
RubikCube.cpp.s:
	$(MAKE) -f CMakeFiles/RubikCube.dir/build.make CMakeFiles/RubikCube.dir/RubikCube.cpp.s
.PHONY : RubikCube.cpp.s

RubikCubeRun.o: RubikCubeRun.cpp.o

.PHONY : RubikCubeRun.o

# target to build an object file
RubikCubeRun.cpp.o:
	$(MAKE) -f CMakeFiles/RubikCube.dir/build.make CMakeFiles/RubikCube.dir/RubikCubeRun.cpp.o
.PHONY : RubikCubeRun.cpp.o

RubikCubeRun.i: RubikCubeRun.cpp.i

.PHONY : RubikCubeRun.i

# target to preprocess a source file
RubikCubeRun.cpp.i:
	$(MAKE) -f CMakeFiles/RubikCube.dir/build.make CMakeFiles/RubikCube.dir/RubikCubeRun.cpp.i
.PHONY : RubikCubeRun.cpp.i

RubikCubeRun.s: RubikCubeRun.cpp.s

.PHONY : RubikCubeRun.s

# target to generate assembly for a file
RubikCubeRun.cpp.s:
	$(MAKE) -f CMakeFiles/RubikCube.dir/build.make CMakeFiles/RubikCube.dir/RubikCubeRun.cpp.s
.PHONY : RubikCubeRun.cpp.s

Square.o: Square.cpp.o

.PHONY : Square.o

# target to build an object file
Square.cpp.o:
	$(MAKE) -f CMakeFiles/RubikCube.dir/build.make CMakeFiles/RubikCube.dir/Square.cpp.o
.PHONY : Square.cpp.o

Square.i: Square.cpp.i

.PHONY : Square.i

# target to preprocess a source file
Square.cpp.i:
	$(MAKE) -f CMakeFiles/RubikCube.dir/build.make CMakeFiles/RubikCube.dir/Square.cpp.i
.PHONY : Square.cpp.i

Square.s: Square.cpp.s

.PHONY : Square.s

# target to generate assembly for a file
Square.cpp.s:
	$(MAKE) -f CMakeFiles/RubikCube.dir/build.make CMakeFiles/RubikCube.dir/Square.cpp.s
.PHONY : Square.cpp.s

Student.o: Student.cpp.o

.PHONY : Student.o

# target to build an object file
Student.cpp.o:
	$(MAKE) -f CMakeFiles/RubikCube.dir/build.make CMakeFiles/RubikCube.dir/Student.cpp.o
.PHONY : Student.cpp.o

Student.i: Student.cpp.i

.PHONY : Student.i

# target to preprocess a source file
Student.cpp.i:
	$(MAKE) -f CMakeFiles/RubikCube.dir/build.make CMakeFiles/RubikCube.dir/Student.cpp.i
.PHONY : Student.cpp.i

Student.s: Student.cpp.s

.PHONY : Student.s

# target to generate assembly for a file
Student.cpp.s:
	$(MAKE) -f CMakeFiles/RubikCube.dir/build.make CMakeFiles/RubikCube.dir/Student.cpp.s
.PHONY : Student.cpp.s

Window.o: Window.cpp.o

.PHONY : Window.o

# target to build an object file
Window.cpp.o:
	$(MAKE) -f CMakeFiles/RubikCube.dir/build.make CMakeFiles/RubikCube.dir/Window.cpp.o
.PHONY : Window.cpp.o

Window.i: Window.cpp.i

.PHONY : Window.i

# target to preprocess a source file
Window.cpp.i:
	$(MAKE) -f CMakeFiles/RubikCube.dir/build.make CMakeFiles/RubikCube.dir/Window.cpp.i
.PHONY : Window.cpp.i

Window.s: Window.cpp.s

.PHONY : Window.s

# target to generate assembly for a file
Window.cpp.s:
	$(MAKE) -f CMakeFiles/RubikCube.dir/build.make CMakeFiles/RubikCube.dir/Window.cpp.s
.PHONY : Window.cpp.s

main.o: main.cpp.o

.PHONY : main.o

# target to build an object file
main.cpp.o:
	$(MAKE) -f CMakeFiles/RubikCube.dir/build.make CMakeFiles/RubikCube.dir/main.cpp.o
.PHONY : main.cpp.o

main.i: main.cpp.i

.PHONY : main.i

# target to preprocess a source file
main.cpp.i:
	$(MAKE) -f CMakeFiles/RubikCube.dir/build.make CMakeFiles/RubikCube.dir/main.cpp.i
.PHONY : main.cpp.i

main.s: main.cpp.s

.PHONY : main.s

# target to generate assembly for a file
main.cpp.s:
	$(MAKE) -f CMakeFiles/RubikCube.dir/build.make CMakeFiles/RubikCube.dir/main.cpp.s
.PHONY : main.cpp.s

# Help Target
help:
	@echo "The following are some of the valid targets for this Makefile:"
	@echo "... all (the default if no target is provided)"
	@echo "... clean"
	@echo "... depend"
	@echo "... install/strip"
	@echo "... edit_cache"
	@echo "... RubikCube"
	@echo "... rebuild_cache"
	@echo "... list_install_components"
	@echo "... install/local"
	@echo "... install"
	@echo "... Camera.o"
	@echo "... Camera.i"
	@echo "... Camera.s"
	@echo "... Piece.o"
	@echo "... Piece.i"
	@echo "... Piece.s"
	@echo "... PieceProgram.o"
	@echo "... PieceProgram.i"
	@echo "... PieceProgram.s"
	@echo "... RubikCube.o"
	@echo "... RubikCube.i"
	@echo "... RubikCube.s"
	@echo "... RubikCubeRun.o"
	@echo "... RubikCubeRun.i"
	@echo "... RubikCubeRun.s"
	@echo "... Square.o"
	@echo "... Square.i"
	@echo "... Square.s"
	@echo "... Student.o"
	@echo "... Student.i"
	@echo "... Student.s"
	@echo "... Window.o"
	@echo "... Window.i"
	@echo "... Window.s"
	@echo "... main.o"
	@echo "... main.i"
	@echo "... main.s"
.PHONY : help



#=============================================================================
# Special targets to cleanup operation of make.

# Special rule to run CMake to check the build system integrity.
# No rule that depends on this can have commands that come from listfiles
# because they might be regenerated.
cmake_check_build_system:
	$(CMAKE_COMMAND) -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles/Makefile.cmake 0
.PHONY : cmake_check_build_system
