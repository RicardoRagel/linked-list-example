cmake_minimum_required(VERSION 2.8.9)
project(linked_list)

#########
# SETUP
#########

# Find dependencies
find_package(SDL2 REQUIRED)
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${PROJECT_SOURCE_DIR}/cmake")
find_package(SDL2_ttf REQUIRED)

# Create link to the text font in the build folder
execute_process(COMMAND bash -c "ln -f -s ${PROJECT_SOURCE_DIR}/resources/DejaVuSerif.ttf DejaVuSerif.ttf")

#########
# BUILD
#########
include_directories(include ${SDL2_INCLUDE_DIRS} ${SDL2_TTF_INCLUDE_DIRS})
add_executable(linked_list_example src/main.cpp src/LinkedList.cpp src/WhiteBoard.cpp)
target_link_libraries(linked_list_example ${SDL2_LIBRARIES} ${SDL2_TTF_LIBRARIES})
