cmake_minimum_required(VERSION 3.23.2)

add_subdirectory("thirdParty/SDL-release-3.2.16")
add_subdirectory("thirdParty/SDL_image-release-3.2.4")
Project(snake)
file(GLOB_RECURSE MY_SOURCES CONFIGURE_DEPENDS "${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp")

add_executable(${PROJECT_NAME} "${MY_SOURCES}")

# GLobal resources folder path
target_compile_definitions(${PROJECT_NAME}  PUBLIC RESOURCES_PATH="${CMAKE_CURRENT_SOURCE_DIR}/resources/")

target_include_directories(${PROJECT_NAME}  PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include/")
target_link_libraries(${PROJECT_NAME}  PRIVATE SDL3::SDL3)
target_link_libraries(${PROJECT_NAME}  PRIVATE SDL3_image::SDL3_image)

if(WIN32)
    target_link_libraries(
        ${PROJECT_NAME} PRIVATE SDL2main
    )
endif()