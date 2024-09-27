#include <iostream>
#include <vector>
#include "jugador.h"
#include "mazo.h"
#include "ronda.h"
#include "puntuacion.h"

#include "carta.h"

using namespace std;

void jalarCarta(Mazo* mazo, const int numJugadores, Ronda* ronda) {
    int filaSeleccionada = 0;
    Carta carta = mazo->tomarCarta();
    cout<<"Has robado: "<< carta.toString() << endl;

    do {
        cout << "Selecciona una fila para colocar la carta (1-" << numJugadores << "): ";
        cin >> filaSeleccionada;
    } while (!ronda->agregarCartaAFila(filaSeleccionada - 1, carta));

}


int main() {
    int numJugadores = 0;

    do {
        cout << "Bienvenido a Coloretto. Ingresa el numero de jugadores (3-5): ";
        cin >> numJugadores;
    } while (numJugadores < 3 || numJugadores > 5);

    vector<Jugador> jugadores;
    Mazo mazo;

    vector<Carta> cartas = mazo.getCards();

    for (size_t i = 0; i < cartas.size(); i++) {
        std::cout << cartas[i].obtenerTipo() << " ";  // Acceder a los elementos con vector[i]
    }

    int turno = 0;
    int numRonda = 0;

    for (int i = 0; i < numJugadores; ++i) {
        jugadores.push_back(Jugador());
    }

    Puntuacion puntuacion = Puntuacion();


    while (!mazo.estaVacio()) {
        numRonda += 1;
        cout << "Iniciamos la ronda #" << numRonda << endl;

        Ronda ronda(numJugadores);

        for (int i = 0; i < numJugadores; i++) {
            jugadores[i].cambiarEstadoRonda(true);
            jugadores[i].mostrarMano();
        }

        while (!ronda.todasFilasInactiva()) {
            Jugador& jugadorActual = jugadores[turno];

            while (!jugadorActual.estadoJugador()) {
                turno += 1;
                if (turno >= numJugadores - 1) {
                    turno = 0;
                }

                jugadorActual = jugadores[turno];
            }

            if (turno >= numJugadores - 1) {
                turno = 0;
            }
            else {
                turno += 1;
            }

            cout << "Turno de " << jugadorActual.getNombre() <<endl;
            ronda.mostrarFilas();

            if (ronda.todasFilasLlenas()) {
                cout << "Todas las filas están llenas. " << jugadorActual.getNombre() << " debe tomar una fila." << endl;
                int filaSeleccionada;
                do {
                    cout << "Selecciona una fila para tomar (1-" << numJugadores << "): ";
                    cin >> filaSeleccionada;
                } while (ronda.obtenerFila(filaSeleccionada - 1).estaVacia() || (filaSeleccionada > numJugadores || filaSeleccionada < 1));

                jugadorActual.tomarFila(ronda.obtenerFila(filaSeleccionada - 1));

            } else {
                int accion;
                cout << "Accion a realizar: (1) Jalar y colocar una carta, (2) Tomar una fila: ";
                cin >> accion;

                if (accion == 1) {
                    jalarCarta(&mazo, numJugadores, &ronda);

                } else if (accion == 2) {
                    // Tomar una fila
                    int filaSeleccionada;
                    bool filaTomada = false;

                    do {
                        do {
                            std::cout << "Selecciona una fila para tomar (1-" << numJugadores << "): ";
                            std::cin >> filaSeleccionada;
                        } while (filaSeleccionada < 1 || filaSeleccionada > numJugadores );


                        if (ronda.obtenerFila(filaSeleccionada - 1).estaVacia()) {
                            int decision;

                            cout << "La fila seleccionada esta vacia. ¿Quieres jalar y colocar una carta en vez de tomar la fila? (1: Si, 2: No)";
                            cin >> decision;

                            if (decision == 1) {
                                jalarCarta(&mazo, numJugadores, &ronda);

                            }
                        } else {
                            jugadorActual.tomarFila(ronda.obtenerFila(filaSeleccionada - 1));
                            filaTomada = true;
                        }

                    } while (!filaTomada);

                    cout << "El jugador " << jugadorActual.getNombre() << " no continuara jugando esta ronda" << endl;

                }
            }

        }
    }

    for (int i = 0; i < numJugadores; i++) {
        jugadores[i].ajustarPuntuacion(puntuacion.calcularPuntuacion(jugadores[i]));
        jugadores[i].mostrarMano();

        cout << "Puntos del jugador: " << jugadores[i].obtenerPuntuacion() << endl;
    }


    return 0;
}
