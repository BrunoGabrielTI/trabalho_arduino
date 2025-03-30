# Projeto de Controle de Buzzer com Botões

## Descrição

Este projeto utiliza a plataforma **Arduino** para criar um sistema simples de interação com botões. O sistema consiste em três botões e um buzzer, com o objetivo de emitir diferentes sons dependendo do botão pressionado. O código foi desenvolvido para simular as reações a ações como "fome", "levantar" e "sede", com cada botão correspondendo a um som específico.

### Componentes Utilizados:
- 3 Botões
- 1 Buzzer
- 1 Arduino Uno (ou qualquer placa Arduino compatível)

## Funcionamento

O código configura três botões e um buzzer no Arduino. Cada botão está associado a uma ação específica:

- **Botão de Fome** (Pino 2): Quando pressionado, emite um som grave (500 Hz) no buzzer.
- **Botão de Levantar** (Pino 3): Quando pressionado, emite um som médio (1000 Hz) no buzzer.
- **Botão de Sede** (Pino 4): Quando pressionado, emite um som agudo (1500 Hz) no buzzer.

O código utiliza **INPUT_PULLUP** para os botões, o que significa que, por padrão, os botões estarão em estado **HIGH**, e o pressionamento dos botões irá conectá-los ao **GND**, fazendo o sinal ficar **LOW**.

## Código

```cpp

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

```

## Conexões dos Componentes

### Botões:
- **Botão Fome**: Pino 2 (com uma extremidade conectada ao GND).
- **Botão Levantar**: Pino 3 (com uma extremidade conectada ao GND).
- **Botão Sede**: Pino 4 (com uma extremidade conectada ao GND).

### Buzzer:
- **Pino 9 do Arduino** conectado ao **positivo** do buzzer.
- O **negativo** do buzzer deve ser conectado ao **GND**.

## Como Funciona

O código começa configurando os pinos para os botões como **INPUT_PULLUP**, utilizando resistores internos de pull-up. Isso significa que, por padrão, os pinos estarão em **HIGH**, e o pressionamento dos botões os levará a **LOW**.

A função `loop()` é executada continuamente. A cada ciclo:

- Verifica se o botão de **fome** foi pressionado (estado **LOW**).
- Se o botão de **fome** for pressionado, o buzzer emite um som grave.
- Da mesma forma, se o botão de **levantar** ou **sede** for pressionado, um som médio ou agudo é emitido, respectivamente.
- O comando `tone(buzzer, frequência)` faz o buzzer emitir um som na frequência especificada, enquanto `noTone(buzzer)` desliga o som.
- O `delay(500)` cria uma pausa de meio segundo após cada acionamento do buzzer, evitando que o som seja repetido rapidamente.

## Observações

- **Debounce**: O código atual não implementa uma lógica de **debounce** para os botões, o que pode resultar em múltiplas leituras do mesmo pressionamento de botão. Caso deseje melhorar a resposta, é possível adicionar uma lógica de debounce usando a função `millis()`.
  
- **Expansão**: Este código pode ser expandido para incluir mais botões, buzzer com controle de duração do som, ou até mesmo interação com LEDs.

## Como Carregar o Código

### Arduino IDE:
1. Abra a **Arduino IDE**.
2. Copie e cole o código acima na janela de código.
3. Selecione a sua placa Arduino e a porta correta.
4. Clique em **Upload** para carregar o código no seu Arduino.

### Tinkercad:
1. Crie um circuito no **Tinkercad**.
2. Insira o código na seção de código.
3. Clique em **Start Simulation** para testar o código.

## Licença
Este código está disponível sob a **Licença MIT**.
