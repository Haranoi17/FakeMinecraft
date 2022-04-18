set(LibName FakeMinecraftLib)
File(GLOB_RECURSE SOURCES ${CMAKE_CURRENT_SOURCE_DIR}/src/GameTemp/ *.cpp)

add_library(${LibName} STATIC ${SOURCES})

target_include_directories(${LibName} PUBLIC
${CMAKE_CURRENT_SOURCE_DIR}/Include/GameTemp/
)

target_link_libraries(${LibName} PUBLIC 
sfml-graphics
sfml-window
sfml-system
GL
GLU
glut    
GLEW 
)