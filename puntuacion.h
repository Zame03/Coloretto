#ifndef PUNTUACION_H
#define PUNTUACION_H

#include <map>

class Puntuacion {
private:
    std::map<int, int> puntuacion;

public:
    Puntuacion() {
        int lado;

        do {
            cout << "¿Con que puntuación deseas jugar? (1. Marron 2. Morada" << endl;
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
};

#endif //PUNTUACION_H
