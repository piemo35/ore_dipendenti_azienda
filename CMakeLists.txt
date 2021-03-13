cmake_minimum_required(VERSION 3.17)
project(ore_dipendenti_azienda C)

set(CMAKE_C_STANDARD 11)

include_directories(.)

add_executable(ore_dipendenti_azienda
        funzioni.h
        orario.c)
