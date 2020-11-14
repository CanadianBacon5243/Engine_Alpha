CMAKE_MINIMUM_REQUIRED(VERSION 3.18)

project(Engine_Alpha VERSION 0.1)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

configure_file(src/Engine_AlphaConfig.h.in src/Engine_AlphaConfig.h)

include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup()

add_executable(Engine_Alpha src/main.cpp
        src/Display.cpp
        src/Display.h src/shader/Shader.cpp src/shader/Shader.h src/includes.h src/mesh/Mesh.cpp src/mesh/Mesh.h src/mesh/Vertex.cpp src/mesh/Vertex.h)

target_include_directories(
        Engine_Alpha PUBLIC
        "${PROJECT_BINARY_DIR}"
)

target_link_libraries(Engine_Alpha ${CONAN_LIBS})