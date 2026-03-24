#include "hardware.h"

// Instanciação das variáveis (definidas como extern no .h)
LiquidCrystal_I2C lcd(0x27, 16, 2);
Servo bombaServo;
Servo segurancaServo;

int nivelAtual = 0;
String nivelTexto = "Nivel 0: 0%";
long litros = 0;
long litrosAnterior = -1;
bool bombaLigada = false;
bool segurancaLigada = false;

void setup() {
    pinMode(ledVermelho, OUTPUT);
    pinMode(ledVerde, OUTPUT);
    pinMode(ledAmarelo, OUTPUT);
    pinMode(nivela1, INPUT);
    pinMode(nivela2, INPUT);
    pinMode(nivela3, INPUT);
    pinMode(nivela4, INPUT);
    pinMode(nivela5, INPUT);
    pinMode(nivela6, INPUT);
    
    bombaServo.attach(pinoServo);
    segurancaServo.attach(pinoSeguranca);
    
    lcd.init();
    lcd.backlight();

    EEPROM.get(0, litros);

    lcd.setCursor(0,0);
    lcd.print("Ultimo valor:");
    lcd.setCursor(0,1);
    lcd.print(litros);
    lcd.print(" L");
    delay(2000);
    lcd.clear();
}

void loop() {
    lerSensores();
    processarLogicaNivel();
    controlarAtuadores();
    atualizarInterface();
    delay(150);
}