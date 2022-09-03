#ifndef bracorobot_h
#define bracorobot_h

#include "Arduino.h"
#include <Servo.h>

//CLASS BRA«A ------ SERVO
class braco : public Servo
{
private:
	//CRIANDO OS OBJETOS DA BIBLIOTECA SERVO
	Servo Servo1; //Objeto servo para controlar a base
	Servo Servo2; //Objeto servBracoo para controlar a garra
	Servo Servo3; //Objeto servo para controlar a altura do bra√ßo
	Servo Servo4; //Objeto servo para profundidade a altura do bra√ßo
	//ATRIBUTOS DA CLASSE BRA«O
	int A, B, C, D, BUT1, BUT2, val1, val2, val3, val4;
public:
	//CONSTRUTOR
	braco();
	//FUN«’ES METODOS
	void leitura(int, int , int , int); //RESPONSAVEL POR FAZER AS LEITURAS ENTRE OS MOTORES E POTENCIOMETROS
	void botao(int, int);				//RESPONSAVEL POR FAZER O CODIGO DOS BOTOES E SEUS RESPECTIVOS MOVIMENTOS
	void mostraestado();				//ELE … RESPONSAVEL POR MOSTRAR NUMA TELA OS VALORES DAS VARIAVEIS
};

#endif
