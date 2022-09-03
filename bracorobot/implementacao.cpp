#include "Arduino.h"
#include <Servo.h>
#include "bracorobot.h"

//ZERANDO OS ATRIBUTOS
braco::braco()
{
	A = B = C = D = val1 = val2 = val3 = val4 = 0;
}
//FUNÇÃO DA LEITURA
void braco::leitura(int a, int b, int c, int d)
{
	//PASSANDO OS VALORES POR PARAMETRO PEGOS DO ARQUIVO.ino
	A = a;
	B = b;
	C = c;
	D = d;

	//ATRIBUINDO O PINO DO ARDUINO A CADA SERVO
	Servo1.attach(A);	//ALTURA
	Servo2.attach(B);	//GARRA
	Servo3.attach(C);	//PROFUNDIDADE
	Servo4.attach(D);	//LONJURA

	//PASSA OS VALORES CONVERTIDO DO POTENCIOMETRO QUE VAI DE 0 - 1023 PARA OS SERVO QUE RESISTEM DE 0 - 180.
	val1 = map(analogRead(A1), 0, 1023, 20, 130);    //LIMITES
	Servo1.write(val1);
	val2 = map(analogRead(A0), 0, 1023, 0, 30);     //LIMITES
	Servo2.write(val2);
	val3 = map(analogRead(A2), 0, 1023, 90, 165);    //LIMITES
	Servo3.write(val3);
	val4 = map(analogRead(A3), 0, 1023, 50, 170);     //LIMITES
	Servo4.write(val4);
	delay(100);
}
//FUNÇÃO BOTÃO
int braco::botao(int butt1, int butt2)
{
	//PASSANDO OS VALORES POR PARAMETRO PEGOS DO ARQUIVO.ino
	BUT1 = butt1;
	BUT2 = butt2;
	//PASSANDO QUE OS BOTÕES SERÃO VARIAVEIS DE ENTRADA - INPUT
	pinMode(BUT1, INPUT_PULLUP);
	pinMode(BUT2, INPUT_PULLUP);
	//IF RESPONSAVEL POR PASSAR UNS ESTADOS DE MOVIMENTO DO BOTOES
	if (digitalRead(butt2) == HIGH)
	{
		delay(500);
		Servo1.write(70); //POSIÇÕES DIFERENTES DE CADA SERVO
		Servo2.write(25);
		Servo3.write(120);
		Servo4.write(90);
		for(p = 80; p <= 150; p++)
			Servo4.write(p);
		delay(500);
	};
	if (digitalRead(butt1) == HIGH)
	{
		delay(500);
		Servo1.write(25); //POSIÇÕES DIFERENTES DE CADA SERVO
		Servo2.write(5);
		Servo3.write(100);
		Servo4.write(60);
		for(p = 60; p <= 150; p++)
			Servo4.write(p);
		delay(500);
	};
}
//FUNÇÃO QUE MOSTRA NA TELA OS VALORES
void braco::mostraestado()
{
	//INICIANDO O SERIAL
	Serial.begin(9600);
	//COLOCANDO LIMITES DE TEMPO
	unsigned long mostradorTimer = 1;
	const unsigned long intervaloMostrador = 1000;
	if ((millis() - mostradorTimer) >= intervaloMostrador)
	{
		Serial.print("*********GARRA***************");
		Serial.print(analogRead(potpin1)); //GARRA
		Serial.print(" Angulo Motor1:   ");
		Serial.println(val1);
		Serial.print("*****************************");

		Serial.print("**********BASE***************");
		Serial.print(analogRead(potpin2)); //BASE
		Serial.print(" Angulo Motor2:   ");
		Serial.println(val2);
		Serial.print("****************************");

		Serial.print("*********ALTURA*************");
		Serial.print(analogRead(potpin3)); //ALTURA
		Serial.print(" Angulo Motor3:   ");
		Serial.println(val3);
		Serial.print("****************************");

		Serial.print("****************************");
		Serial.print(analogRead(potpin4)); //PROFUNDIDADE
		Serial.print(" Angulo Motor4:   ");
		Serial.println(val4);
		Serial.print("****************************");

		mostradorTimer = millis();
	}
}
