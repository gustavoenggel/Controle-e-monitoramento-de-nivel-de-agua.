#pragma once
#include <Arduino.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <EEPROM.h>
#include <Servo.h>

// Pinos
const int pinoPotenciometro = A0;
const int ledVermelho = 4;
const int ledVerde = 3;
const int pinoServo = 11;
const int nivela6 = 9;         
const int ledAmarelo = 7;      
const int pinoSeguranca = 12;  
// Declaração de objetos (o "extern" avisa que eles serão criados no main.cpp)
extern LiquidCrystal_I2C lcd;
extern Servo bombaServo;
extern Servo segurancaServo;

// Variáveis Globais
extern int nivelAtual;
extern String nivelTexto;
extern long litros;
extern long litrosAnterior;
extern bool bombaLigada;
