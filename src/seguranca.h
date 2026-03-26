#include "Servo.h"
#include "config.h"
// --- Variáveis de Estado ---
bool segurancaLigada = false;

void setupSeguranca() {
  // Configuração dos pinos
  pinMode(nivela6, INPUT);
  pinMode(ledAmarelo, OUTPUT);
  
  // Inicialização do Servo
  segurancaServo.attach(pinoSeguranca);
  
  // Garante que a bomba inicie desligada
  segurancaServo.write(0);
  digitalWrite(ledAmarelo, LOW);
}

void loopSeguranca() {
  // 1. LEITURA DO SENSOR
  // Se a água atingir o nível 6 (sobrenível), a segurança deve ser ligada
  if (digitalRead(nivela6) == HIGH) {
    segurancaLigada = true;
  } else {
    segurancaLigada = false;
  }

  // 2. CONTROLE DA BOMBA (SERVO) E LED
  if (segurancaLigada) {
    segurancaServo.write(90);       
    digitalWrite(ledAmarelo, HIGH); 
  } else {
    segurancaServo.write(0);        
    digitalWrite(ledAmarelo, LOW); 
  }

  // Pequeno atraso para estabilidade da leitura
  delay(150);
}