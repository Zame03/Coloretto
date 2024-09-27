cmake_minimum_required(VERSION 3.29)
project(ColorettoManu)

set(CMAKE_CXX_STANDARD 20)

add_executable(ColorettoManu main.cpp
        jugador.h
        carta.h
        mazo.h
        fila.h
        ronda.h
        puntuacion.h)
