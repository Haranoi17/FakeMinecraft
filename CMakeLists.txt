cmake_minimum_required(VERSION 3.0)

project(game)

set(
    SRC
    ${CMAKE_CURRENT_SOURCE_DIR}/Include/Bullet/bullet_src.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/Include/MyClasses/Camera.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/Include/MyClasses/World.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/Include/MyClasses/Enemy.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/Include/MyClasses/Player.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/Include/MyFunctions/dealWithCollisions.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/Include/MyFunctions/initBullet.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/Include/MyFunctions/reshapeScreen.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/Include/MyFunctions/setMaterial.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/Include/MyFunctions/initGL.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/Include/MyFunctions/drawScreen.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/Include/MyFunctions/initShaders.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/Include/MyFunctions/update.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/Include/MyFunctions/vectorOperations.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/Include/MyFunctions/mouseHandling.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/Include/MyFunctions/eventHandling.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/Include/MyFunctions/finishBullet.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/Include/MyFunctions/playerShoot.cpp
    main.cpp
    )

include_directories(
    ${CMAKE_CURRENT_SOURCE_DIR}/Include/
    ${CMAKE_CURRENT_SOURCE_DIR}/Include/Bullet
    ${CMAKE_CURRENT_SOURCE_DIR}/Include/MyClasses
    ${CMAKE_CURRENT_SOURCE_DIR}/Include/MyFunctions
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