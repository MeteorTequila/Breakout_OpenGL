cmake_minimum_required(VERSION 3.0.0)
project(FirstOpenGLGame)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "${CAMKE_CXX_FLAGS} -Wall -O3")
# 编译选项
# target_compile_options(${PROJECT_NAME} PUBLIC -Wall -Wextra -pedantic -Werror)


# 不设置会出现 Undefined symbols错误，主要是因为GLFW3的动态库没有链接上
set(CMAKE_OSX_ARCHITECTURES "arm64")

# opengl
find_package(OpenGL REQUIRED)
message(STATUS "OpenGL included at ${OPENGL_INCLUDE_DIR}")

# glfw3
find_package(glfw3 REQUIRED)
message(STATUS "Found glfw3 in ${GLFW3_INCLUDE_DIR}")



# glm
find_package(glm REQUIRED)

# glew
find_package(GLEW REQUIRED)

# glad
set(GLAD_INCLUDE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/dependencies/glad/include")


#stb_image
set(STBIMAGE_INCLUDE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/dependencies/stbImage")

# Assimp
find_package(Assimp REQUIRED)
message(STATUS "Found ASSIMP in ${ASSIMP_INCLUDE_DIR}")




aux_source_directory(. src_file)


# 输出可执行文件
add_executable(${PROJECT_NAME} ${src_file})



# 可执行文件输出路径
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_CURRENT_SOURCE_DIR}/bin)




target_include_directories ( ${PROJECT_NAME}
	PRIVATE
        ${OPENGL_INCLUDE_DIR}
        ${glm_DIR}
        ${GLEW_INCLUDE_DIRS}
        ${GLAD_INCLUDE_DIR}
        ${STBIMAGE_INCLUDE_DIR}

)

target_link_libraries ( ${PROJECT_NAME} 
    PRIVATE 
        ${OPENGL_gl_LIBRARY}
        glfw 
        GLEW::glew_s
        assimp::assimp
)