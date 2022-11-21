cmake_minimum_required(VERSION 3.5)

project(LogisticProjectt LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Se crea
set(project_headers
    Extraccion/extraction.h
    Clase_Logistica/regressionlogistic.h)

# Se crea
set(project_sources
    main.cpp
    Extraccion/extraction.cpp
    Clase_Logistica/regressionlogistic.cpp)

# Se nombran los ejecutables
add_executable(${PROJECT_NAME}
    ${project_sources}
    ${project_headers})
