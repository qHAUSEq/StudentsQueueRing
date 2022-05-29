cmake_minimum_required(VERSION 3.23 FATAL_ERROR)

set(PROJECT_NAME StudentQueueRing)
project(${PROJECT_NAME})

add_executable(${PROJECT_NAME} src/Header.h src/QueueRing.h src/Student.h src/Student.cpp src/Source.cpp)