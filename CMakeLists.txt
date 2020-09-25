cmake_minimum_required(VERSION 3.5)

project(PEX48DS)

set(CMAKE_CXX_STANDARD 14)

set(TANGO_INCLUDE_DIR "/usr/include/tango")
set(IXPIO_INCLUDE_DIR "/usr/include/ixpio")
include_directories(${PROJECT_SOURCE_DIR})
include_directories(${TANGO_INCLUDE_DIR})
include_directories(${IXPIO_INCLUDE_DIR})

find_library(TANGO_LIB tango)
find_library(OMNIDYNAMIC4_LIB omniDynamic4)
find_library(COS4_LIB COS4)
find_library(OMNIORB4_LIB omniORB4)
find_library(OMNITHREAD_LIB omnithread)
find_library(LOG4TANGO_LIB log4tango)
find_library(ZMQ_LIB zmq)

set(CMAKE_CXX_STANDARD 11)

#set(CMAKE_CXX_FLAGS -w)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pthread")


add_executable(PEX48DS
        main.cpp
        PEX48DS.cpp PEX48DS.h
        PEX48DSClass.cpp PEX48DSClass.h
        PEX48DSStateMachine.cpp
        ClassFactory.cpp
        Pex48Device.cpp Pex48Device.h)

target_link_libraries(PEX48DS
        ${TANGO_LIB}
        ${OMNIDYNAMIC4_LIB}
        ${COS4_LIB}
        ${OMNIORB4_LIB}
        ${OMNITHREAD_LIB}
        ${LOG4TANGO_LIB}
        ${ZMQ_LIB})
