/*
Michel Maes
Pablo Fuente
MECANUINO
*/
 
#include <Wire.h>
#include <math.h>

/*Dual Motor Drivers*/
//Front motors
const int AIN1_DelanteDerecha = 46; // control Input AIN1 - right front motor 
const int AIN2_DelanteDerecha = 47; // control Input AIN2 - right front motor
const int BIN1_DelanteIzquierda = 48; // control Input BIN1 - left front motor
const int BIN2_DelanteIzquierda = 49; // control Input BIN2 - left front motor
//Rear motors
const int AIN1_AtrasDerecha = 50; // control Input AIN1 - right rear motor 
const int AIN2_AtrasDerecha = 51; // control Input AIN2 - right rear motor
const int BIN1_AtrasIzquierda = 52; // control Input BIN1 - left rear motor
const int BIN2_AtrasIzquierda = 53; // control Input BIN2 - left rear  motor

const int PWM_DelanteDerecha = 2;
const int PWM_DelanteIzquierda = 3;
const int PWM_AtrasDerecha = 4;
const int PWM_AtrasIzquierda = 5;
/*Dual Motor Drivers*/

long pwmValIzq = 255;
long pwmValDer = 255;
long VELOCITY = 255;

byte pwmChannel;
const char prevNumLimit = '<';
const char postNumLimit = '>';

void setup(){
  Serial1.begin(9600);// HC-06 canal por defecto: 9600
  Serial.begin(19200); // Terminal print

  //Setup Motor delante der
  pinMode(AIN1_DelanteDerecha, OUTPUT);
  pinMode(AIN2_DelanteDerecha, OUTPUT);

  //Setup Motor delante izq
  pinMode(BIN1_DelanteIzquierda, OUTPUT);
  pinMode(BIN2_DelanteIzquierda, OUTPUT);

  //Setup Motor atras der 
  pinMode(AIN1_AtrasDerecha, OUTPUT);
  pinMode(AIN2_AtrasDerecha, OUTPUT);

  //Setup Motor atras izq 
  pinMode(BIN1_AtrasIzquierda, OUTPUT);
  pinMode(BIN2_AtrasIzquierda, OUTPUT); 
  
  Wire.begin();
}


void loop(){
  // SOLO SI BLUETOOTH DISPONIBLE...
  if (Serial1.available()) {
    leerTecla();
  }
}


void controlMotor(String motorStr,int mdirection, int velocidad){
  int IN1;
  int IN2;
  int motorPWM;
  if (motorStr == "del_der") { // Motor delante derecha
    IN1 = AIN1_DelanteDerecha; 
    IN2 = AIN2_DelanteDerecha;
    motorPWM = PWM_DelanteDerecha;
  }   
  else if (motorStr == "del_izq") { // Motor delante izquierda
    IN1 = BIN1_DelanteIzquierda; 
    IN2 = BIN2_DelanteIzquierda;
    motorPWM = PWM_DelanteIzquierda;
  }
  else if (motorStr == "atr_der") { // Motor atrás derecha
    IN1 = AIN1_AtrasDerecha; 
    IN2 = AIN2_AtrasDerecha;
    motorPWM = PWM_AtrasDerecha;
  }
  else if (motorStr == "atr_izq") { // Motor atrás izquierda
    IN1 = BIN1_AtrasIzquierda; 
    IN2 = BIN2_AtrasIzquierda;
    motorPWM = PWM_AtrasIzquierda;
  }
  if (mdirection == 1){
    Serial.print("Hacia delante");
    digitalWrite(IN1, LOW); 
    digitalWrite(IN2, HIGH); 
  }
  else if (mdirection == -1){
    Serial.print("Hacia atrás");
    digitalWrite(IN1, HIGH); 
    digitalWrite(IN2, LOW); 
  }
  analogWrite(motorPWM, velocidad);
}

void leerTecla (){
  static long receivedNumber = 0;
  static boolean negative = false;
  byte character = Serial1.read();

  switch (character){
  case postNumLimit:
    if (negative)
      SetPWM(- receivedNumber, pwmChannel);
    else
      SetPWM(receivedNumber, pwmChannel);

  case prevNumLimit:
    receivedNumber = 0;
    negative = false;
    pwmChannel = 0;
    break;

  case 'f': // Adelante
    adelante(VELOCITY);
    Serial.println("forward");
    break;

  case 'b': // Atras
    atras(VELOCITY);
    Serial.println("backward");
    break;

  case 'r': // Derecha
    derecha(VELOCITY);
    Serial.println("right");
    break;

  case 'l': // Izquierda
    izquierda(VELOCITY);
    Serial.println("left");
    break;
    
  case 'i': // Girar horario
    girarDerecha(VELOCITY);
    Serial.println("turn right");
    break;

  case 'j': // Girar antihorario
    girarIzquierda(VELOCITY);
    Serial.println("turn left");
    break;
    
  case 'c': // Delante derecha
    delanteDerecha(VELOCITY);
    Serial.println("move right forward");
    break; 

  case 'd': // Delante izquierda
    delanteIzquierda(VELOCITY);
    Serial.println("move left forward");
    break;  

  case 'e': // Atrás derecha
    atrasDerecha(VELOCITY);
    Serial.println("move right backward");
    break; 

  case 'h': // Atrás izquierda
    atrasIzquierda(VELOCITY);
    Serial.println("move left backward");
    break;  

  case 's':
    paradaForzada();
    break;

  case 'x':
    pwmChannel = 1; // PWM_DelanteDerecha
    break;
  case 'y': // PWM_DelanteIzquierda
    pwmChannel = 2;
    break;

  case '0' ... '9':
    receivedNumber *= 10;
    receivedNumber += c - '0';
    break;

  case '-':
    negative = true;
    break;
  }
}

void SetPWM (const long pwm_num, byte pwm_channel){
  if(pwm_channel==1){ // DRIVE MOTOR
    analogWrite(PWM_DelanteDerecha, pwm_num);
    pwmValDer = pwm_num;
  }
  else if(pwm_channel==2){ // STEERING MOTOR
    analogWrite(PWM_DelanteIzquierda, pwm_num);
    pwmValIzq = pwm_num;
  }
}


/* MOVIMIENTOS */
void adelante(int velocidad){
  Serial.print("Adelante!");
  controlMotor("del_der", 1, velocidad);
  controlMotor("del_izq", 1, velocidad);
  controlMotor("atr_der", 1, velocidad);
  controlMotor("atr_izq", 1, velocidad);
}

void atras(int velocidad){
  Serial.print("Atrás!");
  controlMotor("del_der", -1, velocidad);
  controlMotor("del_izq", -1, velocidad);
  controlMotor("atr_der", -1, velocidad);
  controlMotor("atr_izq", -1, velocidad);
}

void izquierda(int velocidad){
  Serial.print("Izquierda!");
  controlMotor("del_der", 1, velocidad);
  controlMotor("del_izq", -1, velocidad);
  controlMotor("atr_der", -1, velocidad);
  controlMotor("atr_izq", 1, velocidad);
}

void derecha(int velocidad){
  Serial.print("Derecha!");
  controlMotor("del_der", -1, velocidad);
  controlMotor("del_izq", 1, velocidad);
  controlMotor("atr_der", 1, velocidad);
  controlMotor("atr_izq", -1, velocidad);
}

void delanteIzquierda(int velocidad){
  Serial.print("Delante izquierda!");
  controlMotor("del_der", 1, velocidad);
  controlMotor("del_izq", 1, 0);
  controlMotor("atr_der", 1, 0);
  controlMotor("atr_izq", 1, velocidad);
}

void delanteDerecha(int velocidad){
  Serial.print("Delante derecha!");
  controlMotor("del_der", 1, 0);
  controlMotor("del_izq", 1, velocidad);
  controlMotor("atr_der", 1, velocidad);
  controlMotor("atr_izq", 1, 0);
}

void atrasIzquierda(int velocidad){
  Serial.print("Atrás izquierda!");
  controlMotor("del_der", 1, 0);
  controlMotor("del_izq", -1, velocidad);
  controlMotor("atr_der", -1, velocidad);
  controlMotor("atr_izq", 1, 0);
}

void atrasDerecha(int velocidad){
  Serial.print("Atrás derecha!");
  controlMotor("del_der", -1, velocidad);
  controlMotor("del_izq", 1, 0);
  controlMotor("atr_der", 1, 0);
  controlMotor("atr_izq", -1, velocidad);
}

void girarDerecha(int velocidad){
  Serial.print("Giro derecha!");
  controlMotor("del_der", -1, velocidad);
  controlMotor("del_izq", 1, velocidad);
  controlMotor("atr_der", -1, velocidad);
  controlMotor("atr_izq", 1, velocidad);
}

void girarIzquierda(int velocidad){
  Serial.print("Giro izquierda!");
  controlMotor("del_der", 1, velocidad);
  controlMotor("del_izq", -1, velocidad);
  controlMotor("atr_der", 1, velocidad);
  controlMotor("atr_izq", -1, velocidad);
}

void parada(int delay_ms){
  Serial.print("PARAR");
  analogWrite(PWM_DelanteDerecha, 0);
  analogWrite(PWM_DelanteIzquierda, 0);
  analogWrite(PWM_AtrasDerecha, 0);
  analogWrite(PWM_AtrasIzquierda, 0);
  delay(delay_ms);
}

void paradaForzada(){
  Serial.print("PARAR FORZADO...");
  analogWrite(PWM_DelanteDerecha, 0);
  analogWrite(PWM_DelanteIzquierda, 0);
  analogWrite(PWM_AtrasDerecha, 0);
  analogWrite(PWM_AtrasIzquierda, 0);
}
