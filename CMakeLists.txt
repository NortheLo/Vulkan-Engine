cmake_minimum_required(VERSION 3.26)
project(vulkan-engine)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(vulkan-engine src/main.cpp src/first_app.cpp 
             src/keyboard_movement_controller.cpp src/lve_buffer.cpp 
             src/lve_camera.cpp src/lve_descriptors.cpp src/lve_device.cpp 
             src/lve_game_object.cpp src/lve_model.cpp src/lve_pipeline.cpp 
             src/lve_renderer.cpp src/lve_swap_chain.cpp src/lve_window.cpp 
             src/point_light_system.cpp src/simple_render_system.cpp)
target_link_libraries(vulkan-engine -lglfw -lvulkan -ldl -lpthread -lX11 -lXrandr -lXi)
add_compile_options(CMAKE_CXX_FLAGS -g -Wall -Wextra -Werror)
set(CMAKE_CXX_FLAGS_RELEASE "-O2")