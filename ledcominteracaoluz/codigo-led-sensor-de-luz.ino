/*
 * Projeto: LED que acende quando está escuro.
 * 
 * Feito por: Artur Bernardo
 * Github: https://github.com/abs-js/
 * Data: 14.10.2026
 * 
 * Itens necessários:
 * 1x LED
 * 1x Fotoresístor
 * 1X resístor 10K oms
 * 1x resístor 650 oms
 * Alguns fios jumper(eu usei 6)
 * Protoboard
 * E, claro, o próprio arduíno
 * 
 */

// Variáveis que podem ser modificadas como quiser.
const int Delay = 500; // Delay (em milissegundos) para não estressar o arduino.
// Possibilidades:
// Seguro e lento | 750~1250
// Normal         | 400~600
// Estressante    | <300

const int pinoLed = 9; // Pino do LED que acende.
const int pinoLeitura = A0; // Pino que lê o fotoresistor.
const int meioLigadoFator = 105; // O LED num estado "meio ligado", quando tem um pouco de luz ainda.

const int poucaLuz = 215;
const int semLuz = 100;
// Estes dois valores podem ser modificados para caso seu ambiente e seus sentidos sejam diferentes.

void setup() {
  Serial.begin(9600); // Ativa o monitor serial.
  pinMode(pinoLed, OUTPUT); // O pio do led é setado como saída.
}

void loop() {
   int leitura = analogRead(pinoLeitura); // Lê o fotoresístor.
  
   Serial.print("Luz(0-1023): ");
   Serial.println(leitura); // Debug para mostrar a leitura
   // Você pode usar o monitor serial em seu computador ou notebook para procurar algum valor que te atende.

   if (leitura < poucaLuz) { // Pouca luz
     analogWrite(pinoLed, meioLigadoFator); 
   } else if (leitura < semLuz) { // Sem luz
     digitalWrite(pinoLed, HIGH); 
   } else { // Quando tem luz - Sem isso, ao ficar escuro o LED ascende e não apaga mais nem se ficar claro denovo
     digitalWrite(pinoLed, LOW);
   }

   // Delay para não estressar o arduino
   delay(Delay);
}
