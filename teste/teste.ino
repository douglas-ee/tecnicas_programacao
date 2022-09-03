#include <bracorobot.h>
braco teste;
void setup()
{
}
void loop()
{
  teste.leitura(5, 2, 4, 3);
  teste.mostraestado();
  teste.botao(6, 7);
}
