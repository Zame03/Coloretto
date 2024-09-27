#ifndef PUNTUACION_H
#define PUNTUACION_H

#include <map>
#include <string>
#include "carta.h"
#include "jugador.h"

class Puntuacion {
private:
    std::map<int, int> puntuacion;
    std::map<std::string, int> puntajeColor;


public:
    Puntuacion() {
        int lado;

        do {
            cout << "¿Con que puntuación deseas jugar? (1. Marron 2. Morada): ";
            cin >> lado;
        } while (lado < 1 || lado > 2);

        if (lado == 1) {
            puntuacion[1] = 1;
            puntuacion[2] = 3;
            puntuacion[3] = 6;
            puntuacion[4] = 10;
            puntuacion[5] = 15;
            puntuacion[6] = 21;

        } else {
            puntuacion[1] = 1;
            puntuacion[2] = 4;
            puntuacion[3] = 8;
            puntuacion[4] = 7;
            puntuacion[5] = 6;
            puntuacion[6] = 3;
        }
    }

    int calcularPuntuacion(Jugador jugador) {
        std::string colores[] = {"rojo", "verde", "azul", "amarillo", "morado", "naranja", "rosa"};

        puntajeColor["rojo"] = 0;
        puntajeColor["verde"] = 0;
        puntajeColor["azul"] = 0;
        puntajeColor["amarillo"] = 0;
        puntajeColor["morado"] = 0;
        puntajeColor["naranja"] = 0;
        puntajeColor["rosa"] = 0;
        puntajeColor["comodin"] = 0;
        puntajeColor["+2"] = 0;

        vector<Carta> mano = jugador.obtenerMano();
        int puntos = 0;

        for (const auto& carta : mano) {
            puntajeColor[carta.obtenerColor()]++;
        }

        puntos = puntajeColor["+2"] * 2;

        for (int i = 0; i < puntajeColor["comodin"]; i++) {
            int eleccion = 0;
            cout << "Tienes " <<puntajeColor["comodin"] << " comodines, asignalos a un color: " << endl;

            for (const auto& color : colores) {
                int j = 0;

                cout << j << ". " << color << endl;


                i++;
            }

            cin >> eleccion;
            puntajeColor[colores[eleccion]] += 1;

        }

        for (const auto& color : colores) {
            for (int i = 0; i < color.size(); i++) {
                if (puntajeColor[color] == i) {
                    puntos += puntuacion[i];
                }
            }
        }

        return puntos;
    }
};



#endif //PUNTUACION_H
