# Projeto: LED que acende quando está escuro.
Como montar:
 * Itens necessários:
 * 1x LED
 * 1x Fotoresístor
 * 1X resístor 10K oms
 * 1x resístor 650 oms
 * Alguns fios jumper(eu usei 6)
 * Protoboard
 * E, claro, o próprio arduíno

1. Pega o que precisa.
2. Conecte o GND/terra/negativo do seu arduíno na barra com um "-" em sua protoboard.
3. na mesma barra, pega um jumper e coloca em algum lugar.
4. Coloque um dos terminais do resístor de 10K ali.
5. Conecte o outro terminal dele em um dos terminais do fotoresístor(qualquer um).
6. O outro lado deve ser conectado ao VCC(5V) do arduíno.
7. No ponto de encontro entre o terminal anterior do fotoresístor e no resístor de 10K oms, puxe um fio até o A0 do seu arduíno.
8. Agora, faz um pequeno circuito de acender LED com o que sobrou, mas com o VCC conectado ao pino definido pelo código(padrão: 9).
9. Agora, conecte seu arduíno ao seu computador e empurre meu código:
> [!IMPORTANT]
> Você precisa do arduino IDE para empurrar o código.
> Caso não tenha, podes instalar ou usar o site: https://app.arduino.cc/

Depois de empurrar corretamente, veja o LED acendendo e apagando por causa do sensor de luz.
> [!TIP]
> Podes usar a própria mão para cobrir o fotoresístor.
