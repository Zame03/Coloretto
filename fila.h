#ifndef FILA_H
#define FILA_H

#include <vector>
#include "carta.h"
#include <iostream>

class Fila {
private:
    std::vector<Carta> cartas;
    static const int maxCartas = 3;  // Máximo de 3 cartas por fila
    bool    estadoFila = true;

public:
    bool agregarCarta(const Carta& carta) {
        if (cartas.size() < maxCartas) {
            cartas.push_back(carta);
            return true;  // Indica que la carta fue colocada con éxito
        }
        return false;  // La fila ya tiene 3 cartas
    }

    std::vector<Carta> tomarCartas() {
        std::vector<Carta> cartasTomadas = cartas;
        cartas.clear();
        estadoFila = false;
        return cartasTomadas;
    }

    bool estaLlena() const {
        return cartas.size() == maxCartas;
    }

    void mostrar() const {
        if (estadoFila) {
            std::cout << "Fila con " << cartas.size() << " cartas: ";
            for (const auto& carta : cartas) {
                std::cout << carta.toString() << " | ";
            }
            std::cout << std::endl;
        }
        else {
            std::cout << "Fila ya tomada!" << std::endl;
        }
    }

    bool estaVacia() const {
        return cartas.empty();
    }

    bool estaActiva() const {
        return estadoFila;
    }
};

#endif
