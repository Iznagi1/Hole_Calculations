cmake_minimum_required(VERSION 3.17)
project(Hole_Calculations)

set(CMAKE_CXX_STANDARD 17)

add_library(Objects_lib
    STATIC
        Objects/Alarm.cpp
        Objects/Field.cpp
        Objects/Hole.cpp
        Objects/Geometry/Circle.cpp
        Objects/Geometry/Rectangle.cpp
        Objects/Geometry/Point.cpp
        Objects/Include/Shape.h
)
add_library(Objects_lib::Objects_lib ALIAS Objects_lib)
target_include_directories(Objects_lib
    PUBLIC
        Objects/Include
)

add_library(Algorithm_lib
    STATIC
        Algorithm/Algorithm.cpp
)
add_library(Algorithm_lib::Algorithm_lib ALIAS Algorithm_lib)
target_include_directories(Algorithm_lib
    PUBLIC
        Algorithm/Include
)
target_link_libraries(Algorithm_lib
    PRIVATE
        Objects_lib::Objects_lib
)

add_library(Display_lib
    STATIC
        Display/DisplayTools.cpp
)
add_library(Display_lib::Display_lib ALIAS Display_lib)
find_package(FreeGLUT CONFIG REQUIRED)
find_package(glui CONFIG REQUIRED)
find_package(glfw3 CONFIG REQUIRED)
target_link_libraries(Display_lib
    PRIVATE
        Objects_lib::Objects_lib
        ${OPENGL_LIBRARIES}
        $<IF:$<TARGET_EXISTS:FreeGLUT::freeglut>,FreeGLUT::freeglut,FreeGLUT::freeglut_static>
        glui::glui glui::glui_static
        glfw
 )
target_include_directories(Display_lib
    PRIVATE
        ${OPENGL_INCLUDE_DIR}
    PUBLIC
        Display/Include
)

add_executable(${PROJECT_NAME}_exe main.cpp io_tools/XMLParser.cpp
)
find_package(pugixml)
find_library(LIB_TO_INCLUDE ClassLibrary D:/Hole_Calculations/libpugixml.a)
include_directories(${LIB_INCLUDES})
target_link_libraries(${PROJECT_NAME}_exe
        pugixml::pugixml D:/Hole_Calculations/libpugixml.a
        Objects_lib::Objects_lib
        Algorithm_lib::Algorithm_lib
        Display_lib::Display_lib
 )
target_include_directories(${PROJECT_NAME}_exe
    PRIVATE
        io_tools/
)