#include "hardware.h"

void lerSensores() {
    // Lendo o estado de todos os pinos primeiro para facilitar a lógica
    bool n1 = digitalRead(nivela1) == HIGH;
    bool n2 = digitalRead(nivela2) == HIGH;
    bool n3 = digitalRead(nivela3) == HIGH;
    bool n4 = digitalRead(nivela4) == HIGH;
    bool n5 = digitalRead(nivela5) == HIGH;
    bool n6 = digitalRead(nivela6) == HIGH;

    // Verificação em cascata: O nível X só é ativado se ele e TODOS abaixo dele estiverem HIGH
    if (n6 && n5 && n4 && n3 && n2 && n1) {
        litros = 10000; // 100% (Sobrenível)
    } 
    else if (n5 && n4 && n3 && n2 && n1) {
        litros = 9000;  // 90%
    } 
    else if (n4 && n3 && n2 && n1) {
        litros = 7000;  // 70%
    } 
    else if (n3 && n2 && n1) {
        litros = 5000;  // 50%
    } 
    else if (n2 && n1) {
        litros = 3000;  // 30%
    } 
    else if (n1) {
        litros = 1000;  // 10%
    } 
    else {

        litros = 0;     // 0% 
    }
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