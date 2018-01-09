#include <Timing.h>
 
//Definição dos pinos dos LEDs
#define greenLed 5
#define yellowLed 6
#define redLed 7
 
// Um timer para cada LED e um para o contador
Timing timerGreen;
Timing timerYellow;
Timing timerRed;
Timing timerContador;
int contador = 11;
 
void setup(void) {
  //Inicializações
  pinMode(greenLed,OUTPUT);
  pinMode(yellowLed,OUTPUT);
  pinMode(redLed,OUTPUT);
  timerGreen.begin(0); 
  timerYellow.begin(0); 
  timerRed.begin(0); 
  timerContador.begin(0);
  Serial.begin(9600);
}
  
 
void loop(void) {
  
  if (timerGreen.onTimeout(2000)) { // Acende/Apaga led Verde a cada 2 segundos
    digitalWrite(greenLed,!digitalRead(greenLed));
  }
 
  if (timerYellow.onTimeout(4000)) { // Acende/Apaga led Amarelo a cada 4 segundos
    digitalWrite(yellowLed,!digitalRead(yellowLed));
  }
 
  if (timerRed.onTimeout(10000)) { // Acende/Apaga led Vermelho a cada 10 segundos
    digitalWrite(redLed,!digitalRead(redLed));
  }
  
  if (timerContador.onTimeout(1000)) { //Imprime a contagem regressiva no monitor serial a cada 1 segundo 
    Serial.println((contador > 1) ? --contador : contador = 10);
  }
 
}
