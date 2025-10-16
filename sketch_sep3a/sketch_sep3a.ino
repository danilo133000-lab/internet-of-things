char opt;
const int LED_ROJO = 11;
const int LED_AMARILLO = 8;
const int LED_VERDE = 7;

void setup() {
 Serial.begin(9600);
   pinMode(LED_ROJO, OUTPUT);
   pinMode(LED_AMARILLO, OUTPUT);
  pinMode(LED_VERDE, OUTPUT);
 Serial.println("::::::::::welcome:::::::::");
  Serial.println("pressa any key show menu");
 
  
}
void loop() {
 

if(Serial.available() > 0 ){
  Menu();
opt = Serial.read();      
if(opt=='1'){
  digitalWrite(LED_ROJO, HIGH);
}
if(opt=='2'){
  digitalWrite(LED_ROJO, LOW);
}
if(opt=='3'){
  digitalWrite(LED_AMARILLO, HIGH);
}
if(opt=='4'){
  digitalWrite(LED_AMARILLO, LOW);
}
if(opt=='5'){
  digitalWrite(LED_VERDE, HIGH);
}
if(opt=='6'){
  digitalWrite(LED_VERDE, LOW);
}
if(opt=='7'){
  digitalWrite(LED_ROJO, HIGH);
  digitalWrite(LED_AMARILLO, HIGH);
  digitalWrite(LED_VERDE, HIGH);
  
}
if(opt=='8'){
   digitalWrite(LED_ROJO, LOW);
  digitalWrite(LED_AMARILLO, LOW);
  digitalWrite(LED_VERDE, LOW);
}
if(opt=='9'){
    digitalWrite(LED_ROJO, HIGH);
  digitalWrite(LED_AMARILLO, HIGH);
  digitalWrite(LED_VERDE, HIGH);
  delay(450);
  digitalWrite(LED_ROJO, LOW);
  digitalWrite(LED_AMARILLO, LOW);
  digitalWrite(LED_VERDE, LOW);
  delay(450);
    digitalWrite(LED_ROJO, HIGH);
  digitalWrite(LED_AMARILLO, HIGH);
  digitalWrite(LED_VERDE, HIGH);
  delay(450);
  digitalWrite(LED_ROJO, LOW);
  digitalWrite(LED_AMARILLO, LOW);
  digitalWrite(LED_VERDE, LOW);
  delay(450);
      digitalWrite(LED_ROJO, HIGH);
  digitalWrite(LED_AMARILLO, HIGH);
  digitalWrite(LED_VERDE, HIGH);
  delay(450);
  digitalWrite(LED_ROJO, LOW);
  digitalWrite(LED_AMARILLO, LOW);
  digitalWrite(LED_VERDE, LOW);
  delay(450);
    digitalWrite(LED_ROJO, HIGH);
  digitalWrite(LED_AMARILLO, HIGH);
  digitalWrite(LED_VERDE, HIGH);
  delay(450);
  digitalWrite(LED_ROJO, LOW);
  digitalWrite(LED_AMARILLO, LOW);
  digitalWrite(LED_VERDE, LOW);
  delay(450);



}
  }
  }
  void Menu(){

 Serial.println("%%%%%%%Main Menu%%%%%%%%");
 Serial.println("1. turn on led red");
 Serial.println("2. turn off led red");
 Serial.println("3. turn on led yellow");
 Serial.println("4. turn of led yellow");
 Serial.println("5. turn on led green");
 Serial.println("6. turn off led green");
 Serial.println("7. turn on all");
 Serial.println("8. turn off all");
 Serial.println("9. internifence");
 Serial.println("press any option");

  }