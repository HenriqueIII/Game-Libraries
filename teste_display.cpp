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

int main(int argc, char ** argv){
    Display dsp;
    dsp.clear();
    dsp.write("Press F1");
    dsp.refresh();
    int key=dsp.getC();
    //std::cout << std::endl << key << std::endl;
    dsp.write(itoa(key));
    if (key == 265)
        dsp.write("\nF1 pressed");
    else{
        dsp.write("\nF1 not pressed.");
    }
    dsp.refresh();
    dsp.getC();
    return 0;
}
