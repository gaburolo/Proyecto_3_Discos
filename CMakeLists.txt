cmake_minimum_required(VERSION 3.8)
project(Discos)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp LectorXML.h Listas/LinkedList.h Listas/Node.h BaseDatos.cpp BaseDatos.h Singleton.cpp Singleton.h ControladorVideo.cpp ControladorVideo.h LectorXML.h)
add_executable(Discos ${SOURCE_FILES})

set(CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/cmake_modules")
find_package(SFML REQUIRED system window graphics network audio)
if (SFML_FOUND)
    include_directories(${SFML_INCLUDE_DIR})
    target_link_libraries(Discos ${SFML_LIBRARIES})
endif()