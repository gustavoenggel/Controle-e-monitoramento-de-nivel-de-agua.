#include "hardware.h"

void lerSensores() {
    if (digitalRead(nivela6) == HIGH) litros = 10000;
    else if (digitalRead(nivela5) == HIGH) litros = 9000;
    else if (digitalRead(nivela4) == HIGH) litros = 7000;
    else if (digitalRead(nivela3) == HIGH) litros = 5000;
    else if (digitalRead(nivela2) == HIGH) litros = 3000;
    else if (digitalRead(nivela1) == HIGH) litros = 1000;
    else litros = 0;
}

void processarLogicaNivel() {
    if(litros >= 9500){
        nivelAtual = 6;
        nivelTexto = "SOBRENIVEL";
    } else if (litros >= 9000) {
        nivelAtual = 5;
        nivelTexto = "Nivel 5: 90%";
    } else if (litros >= 7000) {
        nivelAtual = 4;
        nivelTexto = "Nivel 4: 70%";
    } else if (litros >= 5000) {
        nivelAtual = 3;
        nivelTexto = "Nivel 3: 50%";
    } else if (litros >= 3000) {
        nivelAtual = 2;
        nivelTexto = "Nivel 2: 30%";
    } else if (litros >= 1000) {
        nivelAtual = 1;
        nivelTexto = "Nivel 1: 10%";
    } else {
        nivelAtual = 0;
        nivelTexto = "Nivel 0: 0%";
    }
}