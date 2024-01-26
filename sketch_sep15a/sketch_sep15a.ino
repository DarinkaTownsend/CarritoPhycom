#include <Servo.h>
#include <Arduino.h>


const int SERVOPIN = 12;
int valueX=0;
int valueY=0;
int angle = 0;
Servo servo1;


// Configuración de pines
const int botonPin = 10;
const int buzzerPin = 11;
const int segments[7] = {2, 3, 4, 5, 6, 7, 8}; // Pines para los segmentos (a, b, c, d, e, f, g)
const int numSegments = 7;
int botonEstado;
bool contadorActivo = false; // Indicador del estado del contador
int contador = 0; // Variable para almacenar el contador

// Matriz de dígitos para mostrar números del 0 al 9 en el display
const byte digitos[10] = {
  B11111100, // 0
  B01100000, // 1
  B11011010, // 2
  B11110010, // 3
  B01100110, // 4
  B10110110, // 5
  B10111110, // 6
  B11100000, // 7
  B11111110, // 8
  B11110110  // 9
};




void setup() {
  

  pinMode(botonPin, INPUT_PULLUP); // Botón con resistencia pull-up
  pinMode(buzzerPin, OUTPUT);
  
  // Configurar pines de los segmentos como salidas
  for (int i = 0; i < numSegments; i++) {
    pinMode(segments[i], OUTPUT);
  }
  
  // Inicializar display
  apagarDisplay();
  digitalWrite(buzzerPin, LOW);
}



void apagarDisplay() {
  // Apagar todos los segmentos
  for (int i = 0; i < numSegments; i++) {
    digitalWrite(segments[i], LOW);
  }
}



void loop() {
  
  botonEstado = digitalRead(botonPin);
  
  if (botonEstado == LOW && !contadorActivo) {
    // Si el pulsador se presiona y el contador no está activo, iniciar el contador
    contadorActivo = true;
    contador = 0;
  }

  if (contadorActivo) {
    // Mostrar el contador en el display
    mostrarNumero(contador);
    
    // Incrementar el contador
    contador++;
    
    // Si el contador llega a 10, reiniciar a 0
    if (contador >= 10) {
      contador = 0;
    }
  } else {
    // Si el contador no está activo, apagar el display
    apagarDisplay();
    digitalWrite(buzzerPin, LOW);

  }
  
  
  
  
}

void sonidoCorto() {
  // Hacer sonar el buzzer durante 1000 microsegundos (1 milisegundo)
  digitalWrite(buzzerPin, HIGH);
  
}
void mostrarNumero0() {
  digitalWrite(segments[0], HIGH); // Segmento "a"
  digitalWrite(segments[1], HIGH); // Segmento "b"
  digitalWrite(segments[2], HIGH); // Segmento "c"
  digitalWrite(segments[3], HIGH); // Segmento "d"
  digitalWrite(segments[4], HIGH); // Segmento "e"
  digitalWrite(segments[5], HIGH); // Segmento "f"
  digitalWrite(segments[6], LOW); // Segmento "g"
}

void mostrarNumero1() {
  digitalWrite(segments[0], LOW); // Segmento "a"
  digitalWrite(segments[1], HIGH); // Segmento "b"
  digitalWrite(segments[2], HIGH); // Segmento "c"
  digitalWrite(segments[3], LOW); // Segmento "d"
  digitalWrite(segments[4], LOW); // Segmento "e"
  digitalWrite(segments[5], LOW); // Segmento "f"
  digitalWrite(segments[6], LOW); // Segmento "g"
}

void mostrarNumero2() {
  digitalWrite(segments[0], HIGH); // Segmento "a"
  digitalWrite(segments[1], HIGH); // Segmento "b"
  digitalWrite(segments[2], LOW); // Segmento "c"
  digitalWrite(segments[3], HIGH); // Segmento "d"
  digitalWrite(segments[4], HIGH); // Segmento "e"
  digitalWrite(segments[5], LOW); // Segmento "f"
  digitalWrite(segments[6], HIGH); // Segmento "g"
}

void mostrarNumero3() {
  digitalWrite(segments[0], HIGH); // Segmento "a"
  digitalWrite(segments[1], HIGH); // Segmento "b"
  digitalWrite(segments[2], HIGH); // Segmento "c"
  digitalWrite(segments[3], HIGH); // Segmento "d"
  digitalWrite(segments[4], LOW); // Segmento "e"
  digitalWrite(segments[5], LOW); // Segmento "f"
  digitalWrite(segments[6], HIGH); // Segmento "g"
}

void mostrarNumero4() {
  digitalWrite(segments[0], LOW); // Segmento "a"
  digitalWrite(segments[1], HIGH); // Segmento "b"
  digitalWrite(segments[2], HIGH); // Segmento "c"
  digitalWrite(segments[3], LOW); // Segmento "d"
  digitalWrite(segments[4], LOW); // Segmento "e"
  digitalWrite(segments[5], HIGH); // Segmento "f"
  digitalWrite(segments[6], HIGH); // Segmento "g"
}

void mostrarNumero5() {
  digitalWrite(segments[0], HIGH); // Segmento "a"
  digitalWrite(segments[1], LOW); // Segmento "b"
  digitalWrite(segments[2], HIGH); // Segmento "c"
  digitalWrite(segments[3], HIGH); // Segmento "d"
  digitalWrite(segments[4], LOW); // Segmento "e"
  digitalWrite(segments[5], HIGH); // Segmento "f"
  digitalWrite(segments[6], HIGH); // Segmento "g"
}

void mostrarNumero6() {
  digitalWrite(segments[0], HIGH); // Segmento "a"
  digitalWrite(segments[1], LOW); // Segmento "b"
  digitalWrite(segments[2], HIGH); // Segmento "c"
  digitalWrite(segments[3], HIGH); // Segmento "d"
  digitalWrite(segments[4], HIGH); // Segmento "e"
  digitalWrite(segments[5], HIGH); // Segmento "f"
  digitalWrite(segments[6], HIGH); // Segmento "g"
}

void mostrarNumero7() {
  digitalWrite(segments[0], HIGH); // Segmento "a"
  digitalWrite(segments[1], HIGH); // Segmento "b"
  digitalWrite(segments[2], HIGH); // Segmento "c"
  digitalWrite(segments[3], LOW); // Segmento "d"
  digitalWrite(segments[4], LOW); // Segmento "e"
  digitalWrite(segments[5], LOW); // Segmento "f"
  digitalWrite(segments[6], LOW); // Segmento "g"
}

void mostrarNumero8() {
  digitalWrite(segments[0], HIGH); // Segmento "a"
  digitalWrite(segments[1], HIGH); // Segmento "b"
  digitalWrite(segments[2], HIGH); // Segmento "c"
  digitalWrite(segments[3], HIGH); // Segmento "d"
  digitalWrite(segments[4], HIGH); // Segmento "e"
  digitalWrite(segments[5], HIGH); // Segmento "f"
  digitalWrite(segments[6], HIGH); // Segmento "g"
}

void mostrarNumero9() {
  digitalWrite(segments[0], HIGH); // Segmento "a"
  digitalWrite(segments[1], HIGH); // Segmento "b"
  digitalWrite(segments[2], HIGH); // Segmento "c"
  digitalWrite(segments[3], LOW); // Segmento "d"
  digitalWrite(segments[4], LOW); // Segmento "e"
  digitalWrite(segments[5], HIGH); // Segmento "f"
  digitalWrite(segments[6], HIGH); // Segmento "g"
}

void mostrarNumero(int opcion){
  switch (opcion) {
    case 0:
      mostrarNumero0();
      sonidoCorto();
      delay(200);
      digitalWrite(buzzerPin, LOW);
      delay(2000);
      break; // Salir del switch case
    case 1:
      mostrarNumero1();
      sonidoCorto();
      delay(200);
      digitalWrite(buzzerPin, LOW);
      delay(2000);
      break; // Salir del switch case

    case 2:
      mostrarNumero2();
      sonidoCorto();
      delay(200);
      digitalWrite(buzzerPin, LOW);
      delay(2000);    
      break; // Salir del switch case

    case 3:
      mostrarNumero3();
      sonidoCorto();
      delay(200);
      digitalWrite(buzzerPin, LOW);
      delay(2000);    
      break; // Salir del switch case

    case 4:
      mostrarNumero4();
      sonidoCorto();
      delay(200);
      digitalWrite(buzzerPin, LOW);
      delay(2000);  
      break; // Salir del switch case

    case 5:
      mostrarNumero5();
      sonidoCorto();
      delay(200);
      digitalWrite(buzzerPin, LOW);
      delay(2000);    
      break; // Salir del switch case

    case 6:
      mostrarNumero6();
      sonidoCorto();
      delay(200);
      digitalWrite(buzzerPin, LOW);
      delay(2000);   
      break; // Salir del switch case
    case 7:
      mostrarNumero7();
      sonidoCorto();
      delay(200);
      digitalWrite(buzzerPin, LOW);
      delay(2000);    
      break; // Salir del switch case

    case 8:
      mostrarNumero8();
      sonidoCorto();
      delay(200);
      digitalWrite(buzzerPin, LOW);
      delay(2000);  
      break; // Salir del switch case

    case 9:
      mostrarNumero9();
      digitalWrite(buzzerPin, HIGH);
      delay(1000);
      digitalWrite(buzzerPin, LOW);
      contadorActivo = false;
      apagarDisplay();

      break; // Salir del switch case

  
  }
}



  









