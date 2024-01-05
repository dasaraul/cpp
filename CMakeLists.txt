cmake_minimum_required(VERSION 3.26)
project(Dasprog)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(Dasprog
        aritmatika.cpp
        cabang.cpp
        geometri.cpp
        log.cpp
        luas_bangun.cpp
        ojan.cpp
        percabangan.cpp
        perkalian1_10.cpp
        pert1.cpp
        pert3.cpp
        pert5.cpp)
