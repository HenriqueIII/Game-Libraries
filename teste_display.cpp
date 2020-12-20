#include <iostream>
#include "Display.h"

char * itoa(int n){
    const int MAX_BUFF = sizeof(int)*8+1;
    static char str[MAX_BUFF];
    char * ptr = str+MAX_BUFF;

    *--ptr = 0;
    do{
        *--ptr=(n%10)+'0';
        n/=10;
    }while(n>0);
    return ptr;
}

int myStrlen(const char * str){
    char * q = (char*)str;
    while (*q++);
    return q-str-1;
}

int main(int argc, char ** argv){
    const char * msg = "Fim do programa. Carregue numa tecla para sair.";
    Display dsp;
    dsp.clear();
    dsp.write("Keep pressing keys. ESC will close.");
    dsp.refresh();
    int keyPressed;
    //std::cout << std::endl << key << std::endl;
    do{
        keyPressed=dsp.getC();
        dsp.write("\n");
        if(keyPressed>=258 && keyPressed <=275){
            dsp.write(itoa(keyPressed));
        }else{
            dsp.attributeOn(A_BOLD);
            dsp.write((char)keyPressed);
            dsp.attributeOff(A_BOLD);
        }
        dsp.refresh();
    }while(keyPressed!=27);
    dsp.clear();
    //dsp.move(dsp.getmaxY()/2, (dsp.getmaxX()-myStrlen(msg))/2);
    dsp.write(itoa(myStrlen(msg)));
    dsp.write("\t");
    dsp.write(itoa((dsp.getmaxX()-myStrlen(msg))/2));
    dsp.write(',');
    dsp.write(itoa(dsp.getmaxY()/2));
    dsp.refresh();
    dsp.getC();
    return 0;
}
