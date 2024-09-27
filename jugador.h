#ifndef JUGADOR_H
#define JUGADOR_H

#include <vector>
#include <string>
#include <iostream>
#include <map>
#include "carta.h"
#include "fila.h"

using namespace std;

class Jugador {
private:
    string nombre;
    vector<Carta> mano;
    int puntuacion;
    bool estadoRonda = false; //activo true, inactivo false

    // Tabla de puntuación elsedel lado café y violeta
    int calcularPuntuacionPorColor(int cantidad, bool ladoCafe) const {
        if (cantidad == 1) return 1;
        else if (cantidad == 2) return ladoCafe ? 3 : 4;
        else if (cantidad == 3) return ladoCafe ? 6 : 8;
        else if (cantidad == 4) return ladoCafe ? 10 : 7;
        else if (cantidad == 5) return ladoCafe ? 15 : 6;
        else if (cantidad >= 6) return ladoCafe ? 21 : 5;
        return 0;
    }

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

    void tomarFila(Fila& fila) {
        std::vector<Carta> cartasFila = fila.tomarCartas();
        mano.insert(mano.end(), cartasFila.begin(), cartasFila.end());
        estadoRonda = false;
    }

    void mostrarMano() const {
        std::cout << nombre << " tiene las siguientes cartas en mano: " << std::endl;
        for (const auto& carta : mano) {
            std::cout << carta.toString() << " | ";
        }
        std::cout << std::endl;
    }

    // Calcular puntuación según la tabla
    void calcularPuntuacion(bool ladoPuntuacion) {
        std::map<std::string, int> coloresContador;
        int puntosExtra = 0;

        // Contar cuántas cartas de cada color y cartas '+2'
        for (const auto& carta : mano) {
            if (carta.obtenerTipo() == "color") {
                coloresContador[carta.obtenerColor()]++;
            } else if (carta.obtenerTipo() == "+2") {
                puntosExtra += 2;
            }
            // definir los comodines de color para

        }

        puntuacion = puntosExtra;
        for (const auto& [color, cantidad] : coloresContador) {
            puntuacion += calcularPuntuacionPorColor(cantidad, ladoPuntuacion);
        }



        std::cout << "Puntuación de " << nombre << ": " << puntuacion << " puntos." << std::endl;
    }

    [[nodiscard]] bool estadoJugador() const {
        return estadoRonda;
    }

    void cambiarEstadoRonda(bool estado) {
        estadoRonda = estado;
    }
};

#endif
