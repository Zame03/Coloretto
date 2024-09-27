#ifndef CARTA_H
#define CARTA_H

#include <string>

class Carta {
private:
    std::string color;
    std::string tipo; // Puede ser "color", "comodin", "+2", "ultimaRonda"

public:
    Carta(std::string c, std::string t = "color") : color(c), tipo(t) {}

    std::string obtenerColor() const {
        return color;
    }

    std::string obtenerTipo() const {
        return tipo;
    }

    std::string toString() const {
        if (tipo == "color") {
            return "Color (" + color + ")";
        } else if (tipo == "+2") {
            return "+2";
        } else if (tipo == "comodin") {
            return "Comodín";
        } else if (tipo == "ultimaRonda") {
            return "Última Ronda";
        }
        return "";
    }
};

#endif
