cmake_minimum_required(VERSION 3.0)

project(game)

set(
    SRC
    ${CMAKE_CURRENT_SOURCE_DIR}/Include/Bullet/bullet_src.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/Include/MyClasses/Camera.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/Include/MyClasses/Cube.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/Include/MyClasses/Enemy.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/Include/MyClasses/Player.cpp
    /home/haranoi17/Documents/Projects/OpenGl_SFML/Include/MyFunctions/dealWithCollisions.cpp
    /home/haranoi17/Documents/Projects/OpenGl_SFML/Include/MyFunctions/initBullet.cpp
    /home/haranoi17/Documents/Projects/OpenGl_SFML/Include/MyFunctions/reshapeScreen.cpp
    /home/haranoi17/Documents/Projects/OpenGl_SFML/Include/MyFunctions/setMaterial.cpp
    /home/haranoi17/Documents/Projects/OpenGl_SFML/Include/MyFunctions/initGL.cpp
    /home/haranoi17/Documents/Projects/OpenGl_SFML/Include/MyFunctions/drawAxis.cpp
    /home/haranoi17/Documents/Projects/OpenGl_SFML/Include/MyFunctions/drawScreen.cpp
    /home/haranoi17/Documents/Projects/OpenGl_SFML/Include/MyFunctions/initShaders.cpp
    /home/haranoi17/Documents/Projects/OpenGl_SFML/Include/MyFunctions/update.cpp
    /home/haranoi17/Documents/Projects/OpenGl_SFML/Include/MyFunctions/vectorOperations.cpp
    /home/haranoi17/Documents/Projects/OpenGl_SFML/Include/MyFunctions/mouseHandling.cpp
    /home/haranoi17/Documents/Projects/OpenGl_SFML/Include/MyFunctions/eventHandling.cpp
    /home/haranoi17/Documents/Projects/OpenGl_SFML/Include/MyFunctions/finishBullet.cpp
    /home/haranoi17/Documents/Projects/OpenGl_SFML/Include/MyFunctions/playerShoot.cpp
    main.cpp
    )

include_directories(
    /home/haranoi17/Documents/Projects/OpenGl_SFML/Include/
    /home/haranoi17/Documents/Projects/OpenGl_SFML/Include/Bullet
    /home/haranoi17/Documents/Projects/OpenGl_SFML/Include/MyClasses
    /home/haranoi17/Documents/Projects/OpenGl_SFML/Include/MyFunctions
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