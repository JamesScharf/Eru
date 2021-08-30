cmake_minimum_required(VERSION 3.0.0)
project(eru VERSION 0.1.0)

include(CTest)
enable_testing()

include_directories(includes)

set(EXEC eru)
# puts all .cpp files inside src to the SOURCES variable
file(GLOB SOURCES src/*.cpp)

add_executable(${EXEC} ${SOURCES})

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)