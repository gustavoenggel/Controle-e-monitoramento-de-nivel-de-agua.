#include "hardware.h"

void controlarAtuadores() {
    // Controle da bomba com base no nível atual do reservatório:
    // liga a bomba quando o nível está baixo (≤ 1)
    // e desliga quando atinge o nível máximo (5)
    if (nivelAtual <= 1) bombaLigada = true;
    else if (nivelAtual == 5) bombaLigada = false;

    // Segurança
    segurancaLigada = (nivelAtual >= 6);

    // Controla a posição dos servos: define 90° quando ligado e 0° quando desligado para bomba e segurança
    bombaServo.write(bombaLigada ? 90 : 0);
    segurancaServo.write(segurancaLigada ? 90 : 0);

    // LEDs
    digitalWrite(ledVermelho, bombaLigada ? HIGH : LOW);
    digitalWrite(ledVerde, bombaLigada ? LOW : HIGH);
    digitalWrite(ledAmarelo, segurancaLigada ? HIGH : LOW);

    // Verifica se houve uma variação significativa no valor de litros (maior que 50 unidades)
    // Isso evita gravações excessivas na EEPROM, aumentando sua vida útil
    if (abs(litros - litrosAnterior) > 50) {
        EEPROM.put(0, litros);
        EEPROM.put(10, bombaLigada);
        litrosAnterior = litros;
    }
}
