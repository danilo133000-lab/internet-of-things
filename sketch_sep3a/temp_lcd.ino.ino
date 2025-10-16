#include <LiquidCrystal.h>

// --- Configuración del LCD ---
LiquidCrystal lcd_1(12, 11, 5, 4, 3, 2);

// --- Pines del sistema ---
const int sensorPin = A0;    // Sensor TMP36
const int ledPin = 13;        // LED rojo
const int motorPin = 10;      // Motor de CC (controlado con transistor)

void setup() {
  lcd_1.begin(16, 2);        // Inicializa el LCD con 16 columnas y 2 filas
  pinMode(ledPin, OUTPUT);
  pinMode(motorPin, OUTPUT);
  lcd_1.print("Monitoreando...");
  delay(2000);
  lcd_1.clear();
}

void loop() {
  // --- Lectura del sensor TMP36 ---
  int sensorValue = analogRead(sensorPin);        // Lee el valor analógico (0-1023)
  float voltage = sensorValue * (5.0 / 1023.0);   // Convierte a voltaje (0-5V)
  float temperatureC = (voltage - 0.5) * 100.0;   // Convierte a °C (fórmula TMP36)

  // --- Mostrar temperatura en LCD ---
  lcd_1.setCursor(0, 0);
  lcd_1.print("Temp: ");
  lcd_1.print(temperatureC);
  lcd_1.print(" C   ");

  // --- Validaciones de temperatura ---
  if (temperatureC <= 10) {
    // LED parpadea y motor apagado
    digitalWrite(motorPin, LOW);
    digitalWrite(ledPin, HIGH);
    delay(500);
    digitalWrite(ledPin, LOW);
    delay(500);
  }
  else if (temperatureC >= 11 && temperatureC < 25) {
    // LED y motor apagados
    digitalWrite(ledPin, LOW);
    digitalWrite(motorPin, LOW);
    delay(1000);
  }
  else if (temperatureC >= 26) {
    // LED encendido fijo y motor encendido
    digitalWrite(ledPin, HIGH);
    digitalWrite(motorPin, HIGH);
    delay(1000);
  }
}