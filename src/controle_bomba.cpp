#include "hardware.h"

void controlarAtuadores() {
    // Lógica da Bomba
    if (nivelAtual <= 1) bombaLigada = true;
    else if (nivelAtual == 5) bombaLigada = false;

    // Segurança
    segurancaLigada = (nivelAtual >= 6);

    // Servos
    bombaServo.write(bombaLigada ? 90 : 0);
    segurancaServo.write(segurancaLigada ? 90 : 0);

    // LEDs
    digitalWrite(ledVermelho, bombaLigada ? HIGH : LOW);
    digitalWrite(ledVerde, bombaLigada ? LOW : HIGH);
    digitalWrite(ledAmarelo, segurancaLigada ? HIGH : LOW);

    // EEPROM
    if (abs(litros - litrosAnterior) > 50) {
        EEPROM.put(0, litros);
        EEPROM.put(10, bombaLigada);
        litrosAnterior = litros;
    }
}