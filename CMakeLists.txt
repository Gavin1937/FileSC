if (WIN32)
    cmake_minimum_required(VERSION 3.18)
elseif (UNIX)
    cmake_minimum_required(VERSION 3.16)
endif()

project(FileSC)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_definitions(-DUNICODE -D_UNICODE)

set(SRC
    main.cpp
    ArgumentHandler.cpp
    GlobTools.cpp
)
set(HEADER
    ArgumentHandler.h
    GlobTools.h
)

add_executable(FileSC
    ${SRC} ${HEADER}
)