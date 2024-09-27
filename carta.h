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
                resultado = colorize("Color (" + color + ")", RED);
            } else if (color == "verde") {
                resultado = colorize("Color (" + color + ")", LGREEN);
            } else if (color == "amarillo") {
                resultado = colorize("Color (" + color + ")", YELLOW);
            } else if (color == "azul") {
                resultado = colorize("Color (" + color + ")", LBLUE);
            }else if (color == "morado") {
                resultado = colorize("Color (" + color + ")", MAGENTA);
            }else if (color == "marron"){
                resultado = colorize("Color (" + color +")", BROWN);
            }else if (color == "naranja"){
                resultado = colorize("Color (" + color + ")", ORANGE);
            } else {
                resultado = "Color (" + color + ")";
            }
        } else if (tipo == "+2") {
            resultado = colorize("+2", BG_CYAN);
        } else if (tipo == "comodin") {
            resultado = colorize("Comodín", BG_YELLOW);
        } else if (tipo == "ultimaRonda") {
            resultado = colorize("Última Ronda", BG_RED);
        }
        return resultado;
    }
};

#endif
