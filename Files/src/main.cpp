#include <Arduino.h>
#include <Arduino_FreeRTOS.h>
#include <Dabble.h>
#include <Servo.h>

TaskHandle_t direcao, ataque;
Servo direito, esquerdo;

//Pinagem
static const uint8_t rodas[] = {6, 9, 10, 11};

void TarefaDirigir(void* parametros);
void TarefaAtacar(void* parametros);
void enviarSinal(const uint8_t* , int* );

void setup() {
  
  for (auto roda : rodas)
    pinMode(roda, OUTPUT);

  direito.attach(3);
  esquerdo.attach(5);

  Dabble.begin(9600, 0, 1);

  xTaskCreate(TarefaDirigir, "Dirigir", 256, NULL, 0, &direcao);
  xTaskCreate(TarefaAtacar, "Ataque", 128, NULL, 1, &ataque);

}

void TarefaDirigir(void* parametros) {

  (void) parametros;
  struct PlanoCartesiano {
    int q1, q2, q3, q4;
  };
  PlanoCartesiano quads;
  int* const aponte = (int*)&quads;
  int velocidade = 0, estercamento = 0;


  while(1) {

    digitalWrite(LED_BUILTIN, Dabble.isAppConnected());

    while(GamePad.getAngle()) {

      velocidade = GamePad.getRadius() * 8;
      velocidade = map(velocidade, 0, 56, 0, 255);
      estercamento = GamePad.getXaxisData() * 8;
      estercamento = map(estercamento, -56, 56, -255, 255);

      if(GamePad.getYaxisData() >= 0) {
        if(estercamento >= 0)
          quads = {velocidade, 0, velocidade - estercamento, 0};
        else
          quads = {velocidade + estercamento, 0, velocidade, 0};
      } else {
        if(estercamento >= 0)
          quads = {0, velocidade, 0, velocidade - estercamento};
        else
          quads = {0, velocidade + estercamento, 0, velocidade};
      }
      enviarSinal(rodas, aponte);
    }

    while(GamePad.isUpPressed()) {
      quads = {255, 0, 255, 0};
      enviarSinal(rodas, aponte);
    }
    while(GamePad.isRightPressed()) {
      quads = {255, 0, 0, 0};
      enviarSinal(rodas, aponte);
    }
    while(GamePad.isDownPressed()) {
      quads = {0, 255, 0, 255};
      enviarSinal(rodas, aponte);
    }
    while(GamePad.isLeftPressed()) {
      quads = {255, 0, 0, 0};
      enviarSinal(rodas, aponte);
    }
    for(auto r : rodas)
      analogWrite(r, 0);
  }

}
void TarefaAtacar(void* parametros) {

  TickType_t intervalo = 400 / portTICK_PERIOD_MS;

  while(1) {
    if(GamePad.isSquarePressed()) {
      esquerdo.write(180);
      vTaskDelay(intervalo);
      esquerdo.write(0);
      vTaskDelay(intervalo);
    }
    if(GamePad.isCirclePressed()) {
      direito.write(180);
      vTaskDelay(intervalo);
      direito.write(0);
      vTaskDelay(intervalo);
    }
  }
}

void enviarSinal(const uint8_t* pino, int* valores) {
  for (int8_t i = 0; i < 4; i++)
    analogWrite(pino[i], valores[i]);
}

void loop() { Dabble.processInput(); }