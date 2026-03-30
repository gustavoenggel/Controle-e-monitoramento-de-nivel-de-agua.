#include "hardware.h" // Inclui as configurações de pinos e variáveis do hardware

void lerSensores() {
    // Lendo o estado de todos os pinos primeiro para facilitar a lógica
    // Salva o estado atual (se a água está tocando ou não) de cada sensor do tanque
    bool n1 = digitalRead(nivela1) == HIGH; // n1 é o sensor mais baixo (fundo)
    bool n2 = digitalRead(nivela2) == HIGH;
    bool n3 = digitalRead(nivela3) == HIGH;
    bool n4 = digitalRead(nivela4) == HIGH;
    bool n5 = digitalRead(nivela5) == HIGH;
    bool n6 = digitalRead(nivela6) == HIGH; // n6 é o sensor mais alto (topo)

    // Verificação em cascata: O nível X só é ativado se ele e TODOS abaixo dele estiverem HIGH
    // Isso é uma excelente proteção: evita falsas leituras caso um sensor de cima trave ativado ou molhe por engano
    if (n6 && n5 && n4 && n3 && n2 && n1) {
        litros = 10000; // 100% (Sobrenível) - Todos os sensores estão debaixo d'água
    } 
    else if (n5 && n4 && n3 && n2 && n1) {
        litros = 9000;  // 90% - Água chegou no sensor 5, mas o 6 está seco
    } 
    else if (n4 && n3 && n2 && n1) {
        litros = 7000;  // 70% - Água chegou no sensor 4
    } 
    else if (n3 && n2 && n1) {
        litros = 5000;  // 50% - Água chegou no sensor 3 (metade do tanque)
    } 
    else if (n2 && n1) {
        litros = 3000;  // 30% - Água chegou no sensor 2
    } 
    else if (n1) {
        litros = 1000;  // 10% - Apenas o sensor do fundo tem água (nível crítico)
    } 
    else {

        litros = 0;     // 0% - Nenhum sensor ativado, tanque completamente seco
    }
}

// Esta função pega o valor de litros calculado acima e prepara para mostrar no display ou sistema
void processarLogicaNivel() {
    // Testa os valores do maior para o menor para garantir que caia na condição correta
    if(litros >= 9500){
        nivelAtual = 6;
        nivelTexto = "SOBRENIVEL"; // Acima do limite normal, alerta de transbordamento
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
        // Se cair aqui, litros é 0 (ou menor que 1000)
        nivelAtual = 0;
        nivelTexto = "Nivel 0: 0%";
    }
}
