# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.13

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/haranoi17/Documents/Projects/OpenGl_SFML

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/haranoi17/Documents/Projects/OpenGl_SFML/build

# Include any dependencies generated for this target.
include CMakeFiles/game.out.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/game.out.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/game.out.dir/flags.make

CMakeFiles/game.out.dir/main.cpp.o: CMakeFiles/game.out.dir/flags.make
CMakeFiles/game.out.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/haranoi17/Documents/Projects/OpenGl_SFML/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/game.out.dir/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/game.out.dir/main.cpp.o -c /home/haranoi17/Documents/Projects/OpenGl_SFML/main.cpp

CMakeFiles/game.out.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/game.out.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/haranoi17/Documents/Projects/OpenGl_SFML/main.cpp > CMakeFiles/game.out.dir/main.cpp.i

CMakeFiles/game.out.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/game.out.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/haranoi17/Documents/Projects/OpenGl_SFML/main.cpp -o CMakeFiles/game.out.dir/main.cpp.s

CMakeFiles/game.out.dir/src/Camera.cpp.o: CMakeFiles/game.out.dir/flags.make
CMakeFiles/game.out.dir/src/Camera.cpp.o: ../src/Camera.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/haranoi17/Documents/Projects/OpenGl_SFML/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/game.out.dir/src/Camera.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/game.out.dir/src/Camera.cpp.o -c /home/haranoi17/Documents/Projects/OpenGl_SFML/src/Camera.cpp

CMakeFiles/game.out.dir/src/Camera.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/game.out.dir/src/Camera.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/haranoi17/Documents/Projects/OpenGl_SFML/src/Camera.cpp > CMakeFiles/game.out.dir/src/Camera.cpp.i

CMakeFiles/game.out.dir/src/Camera.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/game.out.dir/src/Camera.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/haranoi17/Documents/Projects/OpenGl_SFML/src/Camera.cpp -o CMakeFiles/game.out.dir/src/Camera.cpp.s

CMakeFiles/game.out.dir/src/Enemy.cpp.o: CMakeFiles/game.out.dir/flags.make
CMakeFiles/game.out.dir/src/Enemy.cpp.o: ../src/Enemy.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/haranoi17/Documents/Projects/OpenGl_SFML/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/game.out.dir/src/Enemy.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/game.out.dir/src/Enemy.cpp.o -c /home/haranoi17/Documents/Projects/OpenGl_SFML/src/Enemy.cpp

CMakeFiles/game.out.dir/src/Enemy.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/game.out.dir/src/Enemy.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/haranoi17/Documents/Projects/OpenGl_SFML/src/Enemy.cpp > CMakeFiles/game.out.dir/src/Enemy.cpp.i

CMakeFiles/game.out.dir/src/Enemy.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/game.out.dir/src/Enemy.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/haranoi17/Documents/Projects/OpenGl_SFML/src/Enemy.cpp -o CMakeFiles/game.out.dir/src/Enemy.cpp.s

CMakeFiles/game.out.dir/src/InputController.cpp.o: CMakeFiles/game.out.dir/flags.make
CMakeFiles/game.out.dir/src/InputController.cpp.o: ../src/InputController.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/haranoi17/Documents/Projects/OpenGl_SFML/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/game.out.dir/src/InputController.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/game.out.dir/src/InputController.cpp.o -c /home/haranoi17/Documents/Projects/OpenGl_SFML/src/InputController.cpp

CMakeFiles/game.out.dir/src/InputController.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/game.out.dir/src/InputController.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/haranoi17/Documents/Projects/OpenGl_SFML/src/InputController.cpp > CMakeFiles/game.out.dir/src/InputController.cpp.i

CMakeFiles/game.out.dir/src/InputController.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/game.out.dir/src/InputController.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/haranoi17/Documents/Projects/OpenGl_SFML/src/InputController.cpp -o CMakeFiles/game.out.dir/src/InputController.cpp.s

CMakeFiles/game.out.dir/src/Player.cpp.o: CMakeFiles/game.out.dir/flags.make
CMakeFiles/game.out.dir/src/Player.cpp.o: ../src/Player.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/haranoi17/Documents/Projects/OpenGl_SFML/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/game.out.dir/src/Player.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/game.out.dir/src/Player.cpp.o -c /home/haranoi17/Documents/Projects/OpenGl_SFML/src/Player.cpp

CMakeFiles/game.out.dir/src/Player.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/game.out.dir/src/Player.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/haranoi17/Documents/Projects/OpenGl_SFML/src/Player.cpp > CMakeFiles/game.out.dir/src/Player.cpp.i

CMakeFiles/game.out.dir/src/Player.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/game.out.dir/src/Player.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/haranoi17/Documents/Projects/OpenGl_SFML/src/Player.cpp -o CMakeFiles/game.out.dir/src/Player.cpp.s

CMakeFiles/game.out.dir/src/World.cpp.o: CMakeFiles/game.out.dir/flags.make
CMakeFiles/game.out.dir/src/World.cpp.o: ../src/World.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/haranoi17/Documents/Projects/OpenGl_SFML/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/game.out.dir/src/World.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/game.out.dir/src/World.cpp.o -c /home/haranoi17/Documents/Projects/OpenGl_SFML/src/World.cpp

CMakeFiles/game.out.dir/src/World.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/game.out.dir/src/World.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/haranoi17/Documents/Projects/OpenGl_SFML/src/World.cpp > CMakeFiles/game.out.dir/src/World.cpp.i

CMakeFiles/game.out.dir/src/World.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/game.out.dir/src/World.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/haranoi17/Documents/Projects/OpenGl_SFML/src/World.cpp -o CMakeFiles/game.out.dir/src/World.cpp.s

CMakeFiles/game.out.dir/src/bullet_src.cpp.o: CMakeFiles/game.out.dir/flags.make
CMakeFiles/game.out.dir/src/bullet_src.cpp.o: ../src/bullet_src.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/haranoi17/Documents/Projects/OpenGl_SFML/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object CMakeFiles/game.out.dir/src/bullet_src.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/game.out.dir/src/bullet_src.cpp.o -c /home/haranoi17/Documents/Projects/OpenGl_SFML/src/bullet_src.cpp

CMakeFiles/game.out.dir/src/bullet_src.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/game.out.dir/src/bullet_src.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/haranoi17/Documents/Projects/OpenGl_SFML/src/bullet_src.cpp > CMakeFiles/game.out.dir/src/bullet_src.cpp.i

CMakeFiles/game.out.dir/src/bullet_src.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/game.out.dir/src/bullet_src.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/haranoi17/Documents/Projects/OpenGl_SFML/src/bullet_src.cpp -o CMakeFiles/game.out.dir/src/bullet_src.cpp.s

CMakeFiles/game.out.dir/src/dealWithCollisions.cpp.o: CMakeFiles/game.out.dir/flags.make
CMakeFiles/game.out.dir/src/dealWithCollisions.cpp.o: ../src/dealWithCollisions.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/haranoi17/Documents/Projects/OpenGl_SFML/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building CXX object CMakeFiles/game.out.dir/src/dealWithCollisions.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/game.out.dir/src/dealWithCollisions.cpp.o -c /home/haranoi17/Documents/Projects/OpenGl_SFML/src/dealWithCollisions.cpp

CMakeFiles/game.out.dir/src/dealWithCollisions.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/game.out.dir/src/dealWithCollisions.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/haranoi17/Documents/Projects/OpenGl_SFML/src/dealWithCollisions.cpp > CMakeFiles/game.out.dir/src/dealWithCollisions.cpp.i

CMakeFiles/game.out.dir/src/dealWithCollisions.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/game.out.dir/src/dealWithCollisions.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/haranoi17/Documents/Projects/OpenGl_SFML/src/dealWithCollisions.cpp -o CMakeFiles/game.out.dir/src/dealWithCollisions.cpp.s

CMakeFiles/game.out.dir/src/drawScreen.cpp.o: CMakeFiles/game.out.dir/flags.make
CMakeFiles/game.out.dir/src/drawScreen.cpp.o: ../src/drawScreen.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/haranoi17/Documents/Projects/OpenGl_SFML/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Building CXX object CMakeFiles/game.out.dir/src/drawScreen.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/game.out.dir/src/drawScreen.cpp.o -c /home/haranoi17/Documents/Projects/OpenGl_SFML/src/drawScreen.cpp

CMakeFiles/game.out.dir/src/drawScreen.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/game.out.dir/src/drawScreen.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/haranoi17/Documents/Projects/OpenGl_SFML/src/drawScreen.cpp > CMakeFiles/game.out.dir/src/drawScreen.cpp.i

CMakeFiles/game.out.dir/src/drawScreen.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/game.out.dir/src/drawScreen.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/haranoi17/Documents/Projects/OpenGl_SFML/src/drawScreen.cpp -o CMakeFiles/game.out.dir/src/drawScreen.cpp.s

CMakeFiles/game.out.dir/src/eventHandling.cpp.o: CMakeFiles/game.out.dir/flags.make
CMakeFiles/game.out.dir/src/eventHandling.cpp.o: ../src/eventHandling.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/haranoi17/Documents/Projects/OpenGl_SFML/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_10) "Building CXX object CMakeFiles/game.out.dir/src/eventHandling.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/game.out.dir/src/eventHandling.cpp.o -c /home/haranoi17/Documents/Projects/OpenGl_SFML/src/eventHandling.cpp

CMakeFiles/game.out.dir/src/eventHandling.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/game.out.dir/src/eventHandling.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/haranoi17/Documents/Projects/OpenGl_SFML/src/eventHandling.cpp > CMakeFiles/game.out.dir/src/eventHandling.cpp.i

CMakeFiles/game.out.dir/src/eventHandling.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/game.out.dir/src/eventHandling.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/haranoi17/Documents/Projects/OpenGl_SFML/src/eventHandling.cpp -o CMakeFiles/game.out.dir/src/eventHandling.cpp.s

CMakeFiles/game.out.dir/src/finishBullet.cpp.o: CMakeFiles/game.out.dir/flags.make
CMakeFiles/game.out.dir/src/finishBullet.cpp.o: ../src/finishBullet.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/haranoi17/Documents/Projects/OpenGl_SFML/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_11) "Building CXX object CMakeFiles/game.out.dir/src/finishBullet.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/game.out.dir/src/finishBullet.cpp.o -c /home/haranoi17/Documents/Projects/OpenGl_SFML/src/finishBullet.cpp

CMakeFiles/game.out.dir/src/finishBullet.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/game.out.dir/src/finishBullet.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/haranoi17/Documents/Projects/OpenGl_SFML/src/finishBullet.cpp > CMakeFiles/game.out.dir/src/finishBullet.cpp.i

CMakeFiles/game.out.dir/src/finishBullet.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/game.out.dir/src/finishBullet.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/haranoi17/Documents/Projects/OpenGl_SFML/src/finishBullet.cpp -o CMakeFiles/game.out.dir/src/finishBullet.cpp.s

CMakeFiles/game.out.dir/src/initBullet.cpp.o: CMakeFiles/game.out.dir/flags.make
CMakeFiles/game.out.dir/src/initBullet.cpp.o: ../src/initBullet.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/haranoi17/Documents/Projects/OpenGl_SFML/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_12) "Building CXX object CMakeFiles/game.out.dir/src/initBullet.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/game.out.dir/src/initBullet.cpp.o -c /home/haranoi17/Documents/Projects/OpenGl_SFML/src/initBullet.cpp

CMakeFiles/game.out.dir/src/initBullet.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/game.out.dir/src/initBullet.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/haranoi17/Documents/Projects/OpenGl_SFML/src/initBullet.cpp > CMakeFiles/game.out.dir/src/initBullet.cpp.i

CMakeFiles/game.out.dir/src/initBullet.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/game.out.dir/src/initBullet.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/haranoi17/Documents/Projects/OpenGl_SFML/src/initBullet.cpp -o CMakeFiles/game.out.dir/src/initBullet.cpp.s

CMakeFiles/game.out.dir/src/initGL.cpp.o: CMakeFiles/game.out.dir/flags.make
CMakeFiles/game.out.dir/src/initGL.cpp.o: ../src/initGL.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/haranoi17/Documents/Projects/OpenGl_SFML/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_13) "Building CXX object CMakeFiles/game.out.dir/src/initGL.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/game.out.dir/src/initGL.cpp.o -c /home/haranoi17/Documents/Projects/OpenGl_SFML/src/initGL.cpp

CMakeFiles/game.out.dir/src/initGL.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/game.out.dir/src/initGL.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/haranoi17/Documents/Projects/OpenGl_SFML/src/initGL.cpp > CMakeFiles/game.out.dir/src/initGL.cpp.i

CMakeFiles/game.out.dir/src/initGL.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/game.out.dir/src/initGL.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/haranoi17/Documents/Projects/OpenGl_SFML/src/initGL.cpp -o CMakeFiles/game.out.dir/src/initGL.cpp.s

CMakeFiles/game.out.dir/src/initValues.cpp.o: CMakeFiles/game.out.dir/flags.make
CMakeFiles/game.out.dir/src/initValues.cpp.o: ../src/initValues.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/haranoi17/Documents/Projects/OpenGl_SFML/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_14) "Building CXX object CMakeFiles/game.out.dir/src/initValues.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/game.out.dir/src/initValues.cpp.o -c /home/haranoi17/Documents/Projects/OpenGl_SFML/src/initValues.cpp

CMakeFiles/game.out.dir/src/initValues.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/game.out.dir/src/initValues.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/haranoi17/Documents/Projects/OpenGl_SFML/src/initValues.cpp > CMakeFiles/game.out.dir/src/initValues.cpp.i

CMakeFiles/game.out.dir/src/initValues.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/game.out.dir/src/initValues.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/haranoi17/Documents/Projects/OpenGl_SFML/src/initValues.cpp -o CMakeFiles/game.out.dir/src/initValues.cpp.s

CMakeFiles/game.out.dir/src/playerShoot.cpp.o: CMakeFiles/game.out.dir/flags.make
CMakeFiles/game.out.dir/src/playerShoot.cpp.o: ../src/playerShoot.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/haranoi17/Documents/Projects/OpenGl_SFML/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_15) "Building CXX object CMakeFiles/game.out.dir/src/playerShoot.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/game.out.dir/src/playerShoot.cpp.o -c /home/haranoi17/Documents/Projects/OpenGl_SFML/src/playerShoot.cpp

CMakeFiles/game.out.dir/src/playerShoot.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/game.out.dir/src/playerShoot.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/haranoi17/Documents/Projects/OpenGl_SFML/src/playerShoot.cpp > CMakeFiles/game.out.dir/src/playerShoot.cpp.i

CMakeFiles/game.out.dir/src/playerShoot.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/game.out.dir/src/playerShoot.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/haranoi17/Documents/Projects/OpenGl_SFML/src/playerShoot.cpp -o CMakeFiles/game.out.dir/src/playerShoot.cpp.s

CMakeFiles/game.out.dir/src/reshapeScreen.cpp.o: CMakeFiles/game.out.dir/flags.make
CMakeFiles/game.out.dir/src/reshapeScreen.cpp.o: ../src/reshapeScreen.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/haranoi17/Documents/Projects/OpenGl_SFML/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_16) "Building CXX object CMakeFiles/game.out.dir/src/reshapeScreen.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/game.out.dir/src/reshapeScreen.cpp.o -c /home/haranoi17/Documents/Projects/OpenGl_SFML/src/reshapeScreen.cpp

CMakeFiles/game.out.dir/src/reshapeScreen.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/game.out.dir/src/reshapeScreen.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/haranoi17/Documents/Projects/OpenGl_SFML/src/reshapeScreen.cpp > CMakeFiles/game.out.dir/src/reshapeScreen.cpp.i

CMakeFiles/game.out.dir/src/reshapeScreen.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/game.out.dir/src/reshapeScreen.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/haranoi17/Documents/Projects/OpenGl_SFML/src/reshapeScreen.cpp -o CMakeFiles/game.out.dir/src/reshapeScreen.cpp.s

CMakeFiles/game.out.dir/src/setMaterial.cpp.o: CMakeFiles/game.out.dir/flags.make
CMakeFiles/game.out.dir/src/setMaterial.cpp.o: ../src/setMaterial.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/haranoi17/Documents/Projects/OpenGl_SFML/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_17) "Building CXX object CMakeFiles/game.out.dir/src/setMaterial.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/game.out.dir/src/setMaterial.cpp.o -c /home/haranoi17/Documents/Projects/OpenGl_SFML/src/setMaterial.cpp

CMakeFiles/game.out.dir/src/setMaterial.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/game.out.dir/src/setMaterial.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/haranoi17/Documents/Projects/OpenGl_SFML/src/setMaterial.cpp > CMakeFiles/game.out.dir/src/setMaterial.cpp.i

CMakeFiles/game.out.dir/src/setMaterial.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/game.out.dir/src/setMaterial.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/haranoi17/Documents/Projects/OpenGl_SFML/src/setMaterial.cpp -o CMakeFiles/game.out.dir/src/setMaterial.cpp.s

CMakeFiles/game.out.dir/src/update.cpp.o: CMakeFiles/game.out.dir/flags.make
CMakeFiles/game.out.dir/src/update.cpp.o: ../src/update.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/haranoi17/Documents/Projects/OpenGl_SFML/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_18) "Building CXX object CMakeFiles/game.out.dir/src/update.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/game.out.dir/src/update.cpp.o -c /home/haranoi17/Documents/Projects/OpenGl_SFML/src/update.cpp

CMakeFiles/game.out.dir/src/update.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/game.out.dir/src/update.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/haranoi17/Documents/Projects/OpenGl_SFML/src/update.cpp > CMakeFiles/game.out.dir/src/update.cpp.i

CMakeFiles/game.out.dir/src/update.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/game.out.dir/src/update.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/haranoi17/Documents/Projects/OpenGl_SFML/src/update.cpp -o CMakeFiles/game.out.dir/src/update.cpp.s

CMakeFiles/game.out.dir/src/vectorOperations.cpp.o: CMakeFiles/game.out.dir/flags.make
CMakeFiles/game.out.dir/src/vectorOperations.cpp.o: ../src/vectorOperations.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/haranoi17/Documents/Projects/OpenGl_SFML/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_19) "Building CXX object CMakeFiles/game.out.dir/src/vectorOperations.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/game.out.dir/src/vectorOperations.cpp.o -c /home/haranoi17/Documents/Projects/OpenGl_SFML/src/vectorOperations.cpp

CMakeFiles/game.out.dir/src/vectorOperations.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/game.out.dir/src/vectorOperations.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/haranoi17/Documents/Projects/OpenGl_SFML/src/vectorOperations.cpp > CMakeFiles/game.out.dir/src/vectorOperations.cpp.i

CMakeFiles/game.out.dir/src/vectorOperations.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/game.out.dir/src/vectorOperations.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/haranoi17/Documents/Projects/OpenGl_SFML/src/vectorOperations.cpp -o CMakeFiles/game.out.dir/src/vectorOperations.cpp.s

# Object files for target game.out
game_out_OBJECTS = \
"CMakeFiles/game.out.dir/main.cpp.o" \
"CMakeFiles/game.out.dir/src/Camera.cpp.o" \
"CMakeFiles/game.out.dir/src/Enemy.cpp.o" \
"CMakeFiles/game.out.dir/src/InputController.cpp.o" \
"CMakeFiles/game.out.dir/src/Player.cpp.o" \
"CMakeFiles/game.out.dir/src/World.cpp.o" \
"CMakeFiles/game.out.dir/src/bullet_src.cpp.o" \
"CMakeFiles/game.out.dir/src/dealWithCollisions.cpp.o" \
"CMakeFiles/game.out.dir/src/drawScreen.cpp.o" \
"CMakeFiles/game.out.dir/src/eventHandling.cpp.o" \
"CMakeFiles/game.out.dir/src/finishBullet.cpp.o" \
"CMakeFiles/game.out.dir/src/initBullet.cpp.o" \
"CMakeFiles/game.out.dir/src/initGL.cpp.o" \
"CMakeFiles/game.out.dir/src/initValues.cpp.o" \
"CMakeFiles/game.out.dir/src/playerShoot.cpp.o" \
"CMakeFiles/game.out.dir/src/reshapeScreen.cpp.o" \
"CMakeFiles/game.out.dir/src/setMaterial.cpp.o" \
"CMakeFiles/game.out.dir/src/update.cpp.o" \
"CMakeFiles/game.out.dir/src/vectorOperations.cpp.o"

# External object files for target game.out
game_out_EXTERNAL_OBJECTS =

game.out: CMakeFiles/game.out.dir/main.cpp.o
game.out: CMakeFiles/game.out.dir/src/Camera.cpp.o
game.out: CMakeFiles/game.out.dir/src/Enemy.cpp.o
game.out: CMakeFiles/game.out.dir/src/InputController.cpp.o
game.out: CMakeFiles/game.out.dir/src/Player.cpp.o
game.out: CMakeFiles/game.out.dir/src/World.cpp.o
game.out: CMakeFiles/game.out.dir/src/bullet_src.cpp.o
game.out: CMakeFiles/game.out.dir/src/dealWithCollisions.cpp.o
game.out: CMakeFiles/game.out.dir/src/drawScreen.cpp.o
game.out: CMakeFiles/game.out.dir/src/eventHandling.cpp.o
game.out: CMakeFiles/game.out.dir/src/finishBullet.cpp.o
game.out: CMakeFiles/game.out.dir/src/initBullet.cpp.o
game.out: CMakeFiles/game.out.dir/src/initGL.cpp.o
game.out: CMakeFiles/game.out.dir/src/initValues.cpp.o
game.out: CMakeFiles/game.out.dir/src/playerShoot.cpp.o
game.out: CMakeFiles/game.out.dir/src/reshapeScreen.cpp.o
game.out: CMakeFiles/game.out.dir/src/setMaterial.cpp.o
game.out: CMakeFiles/game.out.dir/src/update.cpp.o
game.out: CMakeFiles/game.out.dir/src/vectorOperations.cpp.o
game.out: CMakeFiles/game.out.dir/build.make
game.out: CMakeFiles/game.out.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/haranoi17/Documents/Projects/OpenGl_SFML/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_20) "Linking CXX executable game.out"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/game.out.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/game.out.dir/build: game.out

.PHONY : CMakeFiles/game.out.dir/build

CMakeFiles/game.out.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/game.out.dir/cmake_clean.cmake
.PHONY : CMakeFiles/game.out.dir/clean

CMakeFiles/game.out.dir/depend:
	cd /home/haranoi17/Documents/Projects/OpenGl_SFML/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/haranoi17/Documents/Projects/OpenGl_SFML /home/haranoi17/Documents/Projects/OpenGl_SFML /home/haranoi17/Documents/Projects/OpenGl_SFML/build /home/haranoi17/Documents/Projects/OpenGl_SFML/build /home/haranoi17/Documents/Projects/OpenGl_SFML/build/CMakeFiles/game.out.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/game.out.dir/depend

