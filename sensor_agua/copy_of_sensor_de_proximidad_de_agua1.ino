// ============================================================
// Laboratorio N°6 - Detección de proximidad del agua
// Ingeniería de Sistemas - IoT
// ============================================================

// Definición de pines
#define TRIG 2
#define ECHO 3
#define LED_VERDE 4
#define LED_AMARILLO 8
#define LED_ROJO 13

// Variables
long duracion;
int distancia;

void setup() {
  Serial.begin(9600); // Comunicación serial para ver lecturas

  pinMode(TRIG, OUTPUT);
  pinMode(ECHO, INPUT);

  pinMode(LED_VERDE, OUTPUT);
  pinMode(LED_AMARILLO, OUTPUT);
  pinMode(LED_ROJO, OUTPUT);

  Serial.println("Sistema de detección de nivel de agua iniciado...");
}

void loop() {
  // Enviar pulso ultrasónico
  digitalWrite(TRIG, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG, LOW);

  // Medir la duración del eco
  duracion = pulseIn(ECHO, HIGH, 30000); // 30ms máximo para evitar bloqueos

  // Calcular distancia (en cm)
  distancia = duracion * 0.034 / 2;

  // Mostrar distancia en monitor serial
  Serial.print("Distancia medida: ");
  Serial.print(distancia);
  Serial.println(" cm");

  // Manejar medidas fuera de rango
  if (distancia <= 0 || distancia > 200) {
    Serial.println("Fuera de rango");
    digitalWrite(LED_VERDE, LOW);
    digitalWrite(LED_AMARILLO, LOW);
    digitalWrite(LED_ROJO, LOW);
  }
  else if (distancia > 100) {
    // Nivel normal
    digitalWrite(LED_VERDE, HIGH);
    digitalWrite(LED_AMARILLO, LOW);
    digitalWrite(LED_ROJO, LOW);
  }
  else if (distancia <= 100 && distancia > 50) {
    // Nivel medio
    digitalWrite(LED_VERDE, LOW);
    digitalWrite(LED_AMARILLO, HIGH);
    digitalWrite(LED_ROJO, LOW);
  }
 else if (distancia < 50) {
    // Nivel medio
    digitalWrite(LED_VERDE, LOW);
    digitalWrite(LED_AMARILLO, LOW);
    digitalWrite(LED_ROJO, HIGH);
  }

  delay(500); // Pequeña pausa antes de la siguiente medición
}


