#ifndef HARDWARE_H
#define HARDWARE_H

#include <Arduino.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <EEPROM.h>
#include <Servo.h>

// Definições de Pinos
#define nivela1 13
#define nivela2 2
#define nivela3 5
#define nivela4 6
#define nivela5 8
#define nivela6 9
#define ledVermelho 4
#define ledVerde 3
#define ledAmarelo 7
#define pinoServo 11
#define pinoSeguranca 12

// Objetos Globais
extern LiquidCrystal_I2C lcd;
extern Servo bombaServo;
extern Servo segurancaServo;

// Variáveis Globais
extern int nivelAtual;
extern String nivelTexto;
extern long litros;
extern long litrosAnterior;
extern bool bombaLigada;
extern bool segurancaLigada;

// Protótipos das Funções
void lerSensores();
void processarLogicaNivel();
void controlarAtuadores();
void atualizarInterface();

#endif