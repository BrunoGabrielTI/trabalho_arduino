const int botaoFome = 2;     // Pino do botão para fome
const int botaoLevantar = 3; // Pino do botão para levantar
const int botaoSede = 4;     // Pino do botão para sede
const int buzzer = 9;        // Pino do buzzer

void setup() {
    pinMode(botaoFome, INPUT_PULLUP);
    pinMode(botaoLevantar, INPUT_PULLUP);
    pinMode(botaoSede, INPUT_PULLUP);
    pinMode(buzzer, OUTPUT);
}

void loop() {
    if (digitalRead(botaoFome) == LOW) {  // Se apertar o botão de fome
        tone(buzzer, 500);  // Som grave para fome
        delay(500);
        noTone(buzzer);
    } 
    else if (digitalRead(botaoLevantar) == LOW) {  // Se apertar o botão de levantar
        tone(buzzer, 1000); // Som médio para levantar
        delay(500);
        noTone(buzzer);
    } 
    else if (digitalRead(botaoSede) == LOW) {  // Se apertar o botão de sede
        tone(buzzer, 1500); // Som agudo para sede
        delay(500);
        noTone(buzzer);
    }
}