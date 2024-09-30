cmake_minimum_required(VERSION 3.21)
project(Laboratorio)

set(CMAKE_CXX_STANDARD 17)

include_directories(include)

add_executable(Laboratorio
        src/main.cpp
        src/chat.cpp
        src/messaggio.cpp
        src/registrochat.cpp
        src/utente.cpp
        src/registroutenti.cpp)
