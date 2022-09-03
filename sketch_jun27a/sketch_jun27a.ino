#define potpin1  0
#define potpin2  1
#define potpin3  2
#define potpin4  3

//////////////////////////////////////////////////////////////////////////////////////////

                              //C++
#include <Servo.h>

//CRIANDO OS OBJETOS DA BIBLIOTECA SERVO
Servo Servo1; //Objeto servo para controlar a base 
Servo Servo2; //Objeto servBracoo para controlar a garra
Servo Servo3; //Objeto servo para controlar a altura do braço
Servo Servo4; //Objeto servo para profundidade a altura do braço

//CRIANDO AS VARIAVEIS 
int val1;
int val2;
int val3;
int val4;

int but1 = 6;
int but2 = 7;

int p;
int i;

//CONFIGURANDO O MOSTRADOR SERIAL
unsigned long mostradorTimer = 1;
const unsigned long intervaloMostrador = 1000;

///////////////////////////////////////////////////////////////////////////////////////
                            //ARDUINO

//FUNÃO SETUP QUE INSTANCIA AS VARIAVEIS PRO ARDUINO
void setup() {
  //INICIA O SERIAL
  Serial.begin(9600);
  //ASSOCIA CADA MOTOR SERVO A UM PINO pwm
  Servo1.attach(5);
  Servo2.attach(2);
  Servo3.attach(4);
  Servo4.attach(3);

  //INSTANCIA OS BOTÕES DISPONIVEIS COMO INPUT
  pinMode(but1,INPUT);
  pinMode(but2,INPUT);
}

//FUNÇÃO LOOP RESPONSAVEL PELO FUNCIONAMENTO DO CODIGO
void loop()
{
  //PASSA OS VALORES CONVERTIDO DO POTENCIOMETRO QUE VAI DE 0 - 1023 PARA OS SERVO QUE RESISTEM DE 0 - 180.
  val1 = map(analogRead(potpin1), 0, 1023, 20, 130);    
  Servo1.write(val1);            
  val2 = map(analogRead(potpin2), 0, 1023, 0, 30);     
  Servo2.write(val2);                
  val3 = map(analogRead(potpin3), 0, 1023, 90, 165);    
  Servo3.write(val3);                 
  val4 = map(analogRead(potpin4), 0, 1023, 50, 170);     
  Servo4.write(val4); 

  delay(10);

    //IF RESPONSAVEL POR PASSAR UNS ESTADOS DE MOVIMENTO DO BOTÃO 2
    if (digitalRead(but2) == HIGH)
    {
     delay(500);
     Servo1.write(70); 
     Servo2.write(25); //GARRA
     Servo3.write(120);
     Servo4.write(90); //BASE
     for(p = 80; p <= 150; p--)
     Servo4.write(p);
     delay(500);
   };

    //IF RESPONSAVEL POR PASSAR UNS ESTADOS DE MOVIMENTO DO BOTÃO 2
    if (digitalRead(but1) == HIGH)
    {
     delay(500);
     Servo1.write(25);
     Servo2.write(5); //GARRA
     Servo3.write(100);
     Servo4.write(60);
     for(p = 60; p <= 150; p--)
     Servo4.write(p);
     delay(500);
   };

  
  if ((millis() - mostradorTimer) >= intervaloMostrador) 
  {
  // envio para o monitor serial do posicionamentos dos motores
  Serial.println("****************");
  
//  Serial.print("Pot1:");
  Serial.print(analogRead(potpin1)); //GARRA
  Serial.print(" Angulo Motor1:");
  Serial.println(val1);

//  Serial.print("Pot2:");
  Serial.print(analogRead(potpin2)); //BASE
  Serial.print(" Angulo Motor2:");
  Serial.println(val2);

 // Serial.print("Pot3:");
  Serial.print(analogRead(potpin3)); //ALTURA
  Serial.print(" Angulo Motor3:");
  Serial.println(val3);

//  Serial.print("Pot4:");
  Serial.print(analogRead(potpin4)); //PROFUNDIDADE
  Serial.print(" Angulo Motor4:");
  Serial.println(val4);
//  Serial.println(but1);

  mostradorTimer = millis();
  }
  
}
