#ifndef CARTA_H
#define CARTA_H

#include <string>
#include "colors.h"

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

    std::string colorize(const std::string& text, const std::string& colorCode) const {
        return colorCode + text + RESET;
    }

    std::string toString() const {
        std::string resultado;
        if (tipo == "color") {
            if (color == "rojo") {
                resultado = colorize((color), RED);
            } else if (color == "verde") {
                resultado = colorize((color), LGREEN);
            } else if (color == "amarillo") {
                resultado = colorize((color), YELLOW);
            } else if (color == "azul") {
                resultado = colorize((color), LBLUE);
            }else if (color == "morado") {
                resultado = colorize((color), MAGENTA);
            }else if (color == "marron"){
                resultado = colorize((color), BROWN);
            }else if (color == "naranja"){
                resultado = colorize((color), ORANGE);
            } else {
                resultado = "Color (" + color + ")";
            }
        } else if (tipo == "+2") {
            resultado = colorize("+2", BG_CYAN);
        } else if (tipo == "comodin") {
            resultado = colorize("Comodín", BG_GREEN);
        } else if (tipo == "ultimaRonda") {
            resultado = colorize("Última Ronda", BG_RED);
        }
        else if (tipo == "comodinDorado") {
            resultado = colorize("Comodin Dorado", BG_YELLOW);
        }
        return resultado;
    }
};

#endif
