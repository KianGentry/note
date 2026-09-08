cmake_minimum_required(VERSION 3.10)
project(note)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR})

add_executable(note src/main.cpp)

install(TARGETS note DESTINATION /usr/bin)

install(CODE "
    file(MAKE_DIRECTORY \"\$ENV{HOME}/.config\")
    if(NOT EXISTS \"\$ENV{HOME}/.config/noterc\")
        file(WRITE \"\$ENV{HOME}/.config/noterc\" \"textEditor=nano\n\")
        message(STATUS \"config written to \$ENV{HOME}/.config/noterc\")
    endif()
")