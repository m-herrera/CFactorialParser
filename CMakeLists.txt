cmake_minimum_required(VERSION 3.9)

project(CodeParser)

set(CMAKE_CXX_STANDARD 11)

find_package(Boost)
if(Boost_FOUND)
    include_directories(${Boost_INCLUDE_DIRS})
endif()


add_executable(CodeParser main.cpp tokenType.h Token.cpp Token.h Variable.cpp Variable.h tinyexpr.h tinyexpr.c Parser.cpp Parser.h)
target_link_libraries(CodeParser ${Boost_LIBRARIES})
