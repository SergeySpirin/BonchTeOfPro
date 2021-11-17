project(main)
cmake_minimum_required(VERSION 2.6)

include_directories(../lib/headers)

set(SOURCES_PATH ./lib/sources)

set(MAIN ./lib/main.cpp)
set(VEHICLE ${SOURCES_PATH}/Vehicle.cpp)
set(CAR ${SOURCES_PATH}/Car.cpp)
set(PLANE ${SOURCES_PATH}/Plane.cpp)

add_executable(${PROJECT_NAME} ${MAIN} ${VEHICLE} ${CAR} ${PLANE})
