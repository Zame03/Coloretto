#ifndef MAZO_H
#define MAZO_H

#include <vector>
#include <algorithm>
#include <ctime>
#include <cstdlib>
#include "carta.h"
#include "ronda.h"

class Mazo {
private:
    std::vector<Carta> cartas;
    bool ultimaRonda = false;

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
        cartas.push_back(Carta("comodinDorado", "comodinDorado"));

        // 1 carta de 'última ronda'
        // cartas.push_back(Carta("ultimaRonda", "ultimaRonda"));
    }

    void barajar() {
        std::srand(unsigned(std::time(0)));
        std::random_shuffle(cartas.begin(), cartas.end());

        // Se inserta la carta de ultima ronda
        Carta UltimaRonda = Carta("ultimaRonda", "ultimaRonda");
        cartas.insert(cartas.begin() + 70, UltimaRonda);
        //cartas.insert(cartas.begin() + 16, Carta("comodin", "comodin"));
        //cartas.insert(cartas.begin() + 70, Carta("comodinDorado", "comodinDorado"));
    }

    Carta tomarCarta() {
        Carta carta = cartas.back();
        cartas.pop_back();

        if (carta.obtenerTipo() == "ultimaRonda") {
            std::cout << carta.toString() << std::endl;
            std::cout << "En la proxima ronda finalizara la partida" << std::endl;
            ultimaRonda = true;

            carta = tomarCarta();
        }
        return carta;
    }

    bool estaVacio() const {
        return cartas.empty();
    }

    int obtenerCartasRestantes() const {
        return cartas.size();
    }

    std::vector<Carta> getCards() {
        return cartas;
    }

    bool esUltimaRonda() {
        return ultimaRonda;
    }
};

#endif
