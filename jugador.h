#ifndef JUGADOR_H
#define JUGADOR_H

#include <vector>
#include <string>
#include <iostream>
#include <map>
#include "carta.h"
#include "fila.h"
#include "mazo.h"

using namespace std;

class Jugador {
private:
    string nombre;
    vector<Carta> mano;
    int puntuacion;
    bool estadoRonda = false; //activo true, inactivo false



public:
    // Constructor que solicita el nombre del jugador
    Jugador() {
        cout << "Ingresa el nombre del jugador: ";
        cin >> nombre; // Obtener el nombre del jugador desde el teclado
        puntuacion = 0;
    }

    std::string getNombre() const {
        return nombre;
    }

    void tomarFila(Fila& fila, Mazo& mazo, Ronda &ronda) {
        std::vector<Carta> cartasFila = fila.tomarCartas();

        mano.insert(mano.end(), cartasFila.begin(), cartasFila.end());

        for (int i = 0; i < cartasFila.size(); i++) {
            if (cartasFila[i].obtenerTipo() == "comodinDorado") {
                Carta cartaExtra = mazo.tomarCarta();
                mano.insert(mano.end(), cartaExtra);
                cout << "Hay un comodin dorado en la fila, toma otra carta: " << cartaExtra.toString() << endl;
            };

        }

        estadoRonda = false;
    }

    void mostrarMano() const {
        std::cout << "El jugador: " << nombre << " tiene las siguientes cartas en mano: " << std::endl;
        for (const auto& carta : mano) {
            std::cout << carta.toString() << " | ";
        }
        std::cout << std::endl;
    }

    // Calcular puntuación según la tabla


    [[nodiscard]] bool estadoJugador() const {
        return estadoRonda;
    }

    void cambiarEstadoRonda(bool estado) {
        estadoRonda = estado;
    }

    void ajustarPuntuacion(int puntos) {
        puntuacion = puntos;
    }

    int obtenerPuntuacion() const {
        return puntuacion;
    }

    vector<Carta> obtenerMano() {
        return mano;
    }
};

#endif
