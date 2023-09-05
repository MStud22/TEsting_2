cmake_minimum_required(VERSION 3.24)
project(TEsting_2)

set(CMAKE_CXX_STANDARD 20)

add_executable(TEsting_2 src/main.cpp src/Engine.cpp header/Engine.h src/Input.cpp src/Personaggio.cpp header/Personaggio.h src/Room.cpp header/Room.h header/Version.h src/SnakeAnimation.cpp src/Menu.cpp header/Menu.h src/getElapsedFrames.cpp src/Scelta_personaggio.cpp header/Scelta_personaggio.h src/Knight.cpp header/Knight.h src/Mage.cpp header/Mage.h)
include_directories(headers /usr/include c:/SFML/include)
set(CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/cmake_modules")
find_package(SFML REQUIRED  graphics window system )
if(SFML_FOUND)
    include_directories(${SFML_INCLUDE_DIR})
    target_link_libraries(TEsting_2 ${SFML_LIBRARIES})
endif()

file(COPY assets DESTINATION ${CMAKE_BINARY_DIR}) #vogliamo che CMake ci copi una serie di asset (deve esistere)  , come font , suoni , o altro e tenereli nella directory assets

#solo per windows , copia dlls per costruire la directory
if(WIN32)
    file(GLOB BINARY_DEP_DLLS "${SFML_INCLUDE_DIR}/../bin/*.dll")
    file(COPY ${BINARY_DEP_DLLS} DESTINATION ${CMAKE_BINARY_DIR})
ENDIF()