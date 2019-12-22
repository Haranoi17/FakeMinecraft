cmake_minimum_required(VERSION 3.0)

project(game)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_BUILD_TYPE Debug)
include_directories(
    ${CMAKE_CURRENT_SOURCE_DIR}/Include/general
    ${CMAKE_CURRENT_SOURCE_DIR}/Include/MyClasses
    ${CMAKE_CURRENT_SOURCE_DIR}/Include/MyFunctions
    )
    
AUX_SOURCE_DIRECTORY(${CMAKE_CURRENT_SOURCE_DIR}/Include/MyClasses SourceFilesClasses)
AUX_SOURCE_DIRECTORY(${CMAKE_CURRENT_SOURCE_DIR}/Include/MyFunctions SourceFilesFunctions)

set(
    SRC
    ${CMAKE_CURRENT_SOURCE_DIR}/main.cpp
    ${SourceFilesClasses}
    ${SourceFilesFunctions}
)

link_libraries(
    sfml-graphics
    sfml-window
    sfml-system
    GL
    GLU
    glut    
    GLEW 
)

add_executable(game.out ${SRC})