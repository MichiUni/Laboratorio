cmake_minimum_required(VERSION 3.21)
project(Laboratorio)
set(CMAKE_OSX_ARCHITECTURES "arm64")
set(CMAKE_CXX_STANDARD 17)

include_directories(include)

set(SOURCES
        src/main.cpp
        src/chat.cpp
        src/messaggio.cpp
        src/registrochat.cpp
        src/utente.cpp
        src/registroutenti.cpp
)

add_executable(Laboratorio ${SOURCES})

add_subdirectory(external/googletest)

enable_testing()

add_executable(UnitTests
        test/test_main.cpp
        test/test_utente.cpp
        test/test_messaggio.cpp
        test/test_chat.cpp
        test/test_registroutenti.cpp
        test/test_registrochat.cpp
        src/chat.cpp
        src/messaggio.cpp
        src/registrochat.cpp
        src/utente.cpp
        src/registroutenti.cpp

)

# Link con GoogleTest
target_link_libraries(UnitTests gtest_main)

# Aggiungi i test
include(GoogleTest)
gtest_discover_tests(UnitTests)

