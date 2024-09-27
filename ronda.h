#ifndef RONDA_H
#define RONDA_H

#include <vector>
#include "fila.h"
#include "mazo.h"

class Ronda {
private:
    std::vector<Fila> filas;
    int numFilas;

public:
    Ronda(int numJugadores) {
        numFilas = numJugadores;  // Número de filas igual al número de jugadores
        filas.resize(numFilas);   // Crear las filas
    }

    void mostrarFilas() const {
        for (int i = 0; i < numFilas; ++i) {
            std::cout << "Fila " << i + 1 << ": ";
            filas[i].mostrar();
        }
    }

    bool agregarCartaAFila(int filaIndex, const Carta& carta) {
        if (filaIndex >= 0 && filaIndex < numFilas && filas[filaIndex].estaActiva()) {
            return filas[filaIndex].agregarCarta(carta);  // Devuelve si la carta fue agregada exitosamente
        }
        return false;
    }

    bool todasFilasLlenas() const {
        for (const auto& fila : filas) {
            if (!fila.estaLlena() && fila.estaActiva()) {
                return false;  // Si una fila no está llena, devolvemos false
            }
        }
        return true;  // Todas las filas están llenas
    }

    bool todasFilasVacias() const {
        for (const auto& fila : filas) {
            if (!fila.estaVacia()) {
                return false;  // Si una fila no está vacía, devolvemos false
            }
        }
        return true;  // Todas las filas están vacías
    }

    bool todasFilasInactiva() const {
        for (const auto& fila : filas) {
            if (fila.estaActiva()) {
                return false;  // Si una fila esta activa, se devuelve falso
            }
        }
        return true;  // Todas las filas estan inactivas
    }

    Fila& obtenerFila(int filaIndex) {
        return filas[filaIndex];
    }
};


#endif
