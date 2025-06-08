cmake_minimum_required(VERSION 3.23.2)

add_subdirectory("thirdParty/SDL-3.2.14")
add_subdirectory("thirdParty/SDL_image-release-3.2.4")
Project(SNAKE)
file(GLOB_RECURSE MY_SOURCES CONFIGURE_DEPENDS "${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp")

add_executable(SNAKE "${MY_SOURCES}")

# GLobal resources folder path
target_compile_definitions(SNAKE PUBLIC RESOURCES_PATH="${CMAKE_CURRENT_SOURCE_DIR}/resources/")

target_include_directories(SNAKE PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include/")
target_link_libraries(SNAKE PRIVATE SDL2)
target_link_libraries(SNAKE PRIVATE ${sdl3_image_target_name})

if(WIN32)
    target_link_libraries(
        main PRIVATE SDL2main
    )
endif()