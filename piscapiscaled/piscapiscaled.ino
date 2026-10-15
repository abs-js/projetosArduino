/*
 * Projeto: Pisca Pisca LED
 * 
 * Feito por: Artur Bernardo
 * Github: https://github.com/abs-js/
 * Data: 15.10.2026
 * 
 * Itens necessários:
 * LEDs(Depende de quantos você quer)
 * Resístores para cada LED (Para 5V, uns 560Oms ou algo assim está ótimo)
 * Alguns fios jumper
 * Protoboard
 * E, claro, o próprio arduíno
 * 
 */

const int QUANTIDADE_LEDS = 3; // Defina quantos LEDs tem(se errar, dá erro no código)
const int PINOS_LEDS[QUANTIDADE_LEDS] = {6, 7, 8}; // Defina os pinos de cada cátodo dos LEDs.
// ALERTA: Não use os pinos 0 e 1. eles são de comunicação da sua placa ao notebook ou PC

void setup() {
  for(int pino : PINOS_LEDS) {
    pinMode(pino, OUTPUT); // Indica que cada pino é OUTPUT
  }
}

void loop() {
  // Chame as funções aqui.
  impar_par(10, 250); 
  tudoOuNada(10, 125); 
  vai_e_volta(10, 100);
}

/* Funções que fazem os LEDs acenderem e apagarem em padrões
 * vai_e_volta(): Faz um Knight Rider (vai e volta mas com LEDs).
 * impar_par(): Pisca Pisca de natal: pisca primeiro uma metade, depois a outra.
 * 
 * TODAS AS FUNÇÕES TEM DOIS ARGUMENTOS, SENDO ELES:
 * @param: q: Quantidade de vezes que é executado.
 * @param d: Delay para não ficar tão rápido
 * 
 */

void vai_e_volta(int q, int d) {
   for (int _ = 0; _ < q; _++) {
    // Ida: do primeiro ao último LED
    for (int i = 0; i < QUANTIDADE_LEDS; i++) {
      int anterior = (i == 0) // Calcula o anterior
        ? QUANTIDADE_LEDS - 1
        : i - 1;
  
      desligar(PINOS_LEDS[anterior]); // Desliga o anterior
      ligar(PINOS_LEDS[i]); // Liga o próximo
      delay(d);
    }
  
    // Volta: do penúltimo ao primeiro LED
    for (int i = QUANTIDADE_LEDS - 2; i >= 0; i--) {
      desligar(PINOS_LEDS[i + 1]); // Desliga o anterior
      ligar(PINOS_LEDS[i]); // Liga o próximo
      delay(d);
    }
  }
}

void impar_par(int q, int d) {
  for (int i = 0; i < q; i++) {
    for (int j = 0; j < QUANTIDADE_LEDS; j++) {
      if ((j + i) % 2 == 0) {
        ligar(PINOS_LEDS[j]); // Liga
      } else {
        desligar(PINOS_LEDS[j]); // Desliga
      }
    }

    delay(d);
  }

  desligarTodos();
}

void tudoOuNada(int q, int d) {
  for(int _ = 0; _ < q; _++) {
    if (_ % 2 == 0) {
      ligarTodos();
    } else {
      desligarTodos();
    }
    delay(d);
  }
}

/* FUNÇÕES AUXILIARES */

void ligar(int pino) {
  digitalWrite(pino, HIGH); // Liga
}

void desligar(int pino) {
  digitalWrite(pino, LOW); // Desliga
}

void desligarTodos() {
  for(int i = 0; i < QUANTIDADE_LEDS; i++) {
    desligar(PINOS_LEDS[i]);  // Desliga TUDO
  }
}

void ligarTodos() {
  for(int i = 0; i < QUANTIDADE_LEDS; i++) {
    ligar(PINOS_LEDS[i]);  // Liga TUDO
  }
}
