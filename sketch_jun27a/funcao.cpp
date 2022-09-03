#include "funcao.h"

funcao_1::funcao_1(){
    but1 = LOW;
};

void funcao_1::Estado_inicial(int ){
    if (digitalRead(but1) == HIGH)
    {
    delay(10);

     serv1.write(22);
     serv2.write(94);
     serv3.write(85);
     serv4.write(67);

     for(p = 67; p <= 15; p--)
      serv4.write(p);
    };
}
