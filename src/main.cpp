#include <Point.h>
#include "Random.h"
#include <iostream>
#include "Display.h"
#include "Keyboard.h"
#include "DeltaTime.h"
#include "Common.h"

int main(int argc, char ** argv){
    char msg[] = "Prima uma tecla para terminar";
    Point max(Display::MAX_X - sizeof(msg), Display::MAX_Y);
    DeltaTime delta(2);
    int color;
    Point pos; 
    kbd.setMode(Keyboard::VIEW);
    while(kbd.get() == KEY_NONE){
        delta.start();
        pos = Random::get(Point(0,0), max);
        color = Random::get(Display::BLACK, Display::WHITE);
        //Aparece
        dsp.setForeground(color);
        dsp.setCursor(pos.getX(), pos.getY());
        dsp.puts(msg);
        delta.wait();
        dsp.setCursor(pos.getX(),pos.getY());
        for (int i=0; i<30;i++)
            dsp.putc(' ');
    }
}