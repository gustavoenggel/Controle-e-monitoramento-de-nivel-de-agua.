#include "hardware.h"

void atualizarInterface() {
    lcd.setCursor(0, 0);
    lcd.print("Vol: ");
    lcd.print(litros);
    lcd.print(" L    "); 

    lcd.setCursor(0, 1);
    lcd.print(nivelTexto);
    lcd.print("    ");
}
