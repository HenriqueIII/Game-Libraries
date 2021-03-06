#include <Point.h>
#include "Random.h"
#include <iostream>
#include "Display.h"
#include "Keyboard.h"
#include "DeltaTime.h"
#include "Common.h"
#include "Rect.h"

void colorfn(){
dsp.setCursor(0,0);
    dsp.puts("Colors");
    for(int i = Display::BLACK;i <= Display::WHITE;++i){
        dsp.setCursor(5,i+1);
        dsp.setBackground(i);
        for (int j = Display::BLACK; j <= Display::WHITE;++j){
            dsp.setForeground(j);
            dsp.puts("  Color  ");
        }
    }
    dsp.setBackground(Display::BLACK);
    dsp.setForeground(Display::WHITE);
    dsp.setCursor(0,9);
    dsp.puts("Bright Colors");
    for(int i = Display::BLACK;i <= Display::WHITE;++i){
        dsp.setCursor(5,i+10);
        dsp.setBackground(i);
        for (int j = Display::BBLACK; j <= Display::BWHITE;++j){
            dsp.setForeground(j);
            dsp.puts("  Color  ");
        }
    }
    kbd.get();
}
void windowfn(){
    Rect rect(0,0,Display::MAX_X,Display::MAX_Y);
    rect.show(Display::BWHITE);
    kbd.get();
}

int main(int argc, char ** argv){
    colorfn();
    dsp.windowClear();
    dsp.resetColor();
    windowfn();
    char msg[] = "Prima uma tecla para terminar";
    Point max(Display::MAX_X-3, Display::MAX_Y-1);
    DeltaTime delta(0.013F);
    int color;
    Point pos; 
    kbd.setMode(Keyboard::VIEW);
    while(kbd.get() == KEY_NONE){
        delta.start();
        pos = Random::get(Point(1,1), max);
        color = Random::get(Display::BLACK, Display::BWHITE);
        Rect rect(pos, 2, 3);
        //Aparece
        rect.show(color);
        /*
        dsp.setForeground(color);
        dsp.setCursor(pos.getX(), pos.getY());
        dsp.puts(msg);
        */
        delta.wait();
        dsp.setCursor(pos.getX(),pos.getY());
        for (int i=0; i<30;i++)
            dsp.putc(' ');
    }
}