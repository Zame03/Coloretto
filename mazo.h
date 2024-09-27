#ifndef MAZO_H
#define MAZO_H

#include <vector>
#include <algorithm>
#include <ctime>
#include <cstdlib>
#include "carta.h"

class Mazo {
private:
    std::vector<Carta> cartas;

public:
    Mazo() {
        generarCartas();
        barajar();
    }

    void generarCartas() {
        std::string colores[] = {"rojo", "verde", "azul", "amarillo", "morado", "naranja", "marron"};
        // 63 cartas de colores, 9 de cada uno de los 7 colores
        for (const auto& color : colores) {
            for (int i = 0; i < 9; ++i) {
                cartas.push_back(Carta(color));
            }
        }

        // 10 cartas '+2'
        for (int i = 0; i < 10; ++i) {
            cartas.push_back(Carta("+2", "+2"));
        }

        // 3 comodines
        cartas.push_back(Carta("comodin", "comodin"));
        cartas.push_back(Carta("comodin", "comodin"));
        cartas.push_back(Carta("comodin dorado", "comodin dorado"));

        // 1 carta de 'última ronda'
        // cartas.push_back(Carta("ultimaRonda", "ultimaRonda"));
    }

    void barajar() {
        std::srand(unsigned(std::time(0)));
        std::random_shuffle(cartas.begin(), cartas.end());

        // Se inserta la carta de ultima ronda
        Carta UltimaRonda = Carta("ultimaRonda", "ultimaRonda");
        cartas.insert(cartas.begin() + 70, UltimaRonda);
    }

    Carta tomarCarta() {
        Carta carta = cartas.back();
        cartas.pop_back();
        return carta;
    }

    bool estaVacio() const {
        return cartas.empty();
    }

    int obtenerCartasRestantes() const {
        return cartas.size();
    }
    vector<Carta> getCards() {
        return cartas;
    }
};

#endif
