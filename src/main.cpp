#include <Point.h>
#include "Random.h"
#include <iostream>
#include "Display.h"
#include "Keyboard.h"
#include "DeltaTime.h"
#include "Common.h"
#include "Rect.h"

class Post{
    Rect r;
public:
    Post(int num):
    r(num, 2, num, 20){
        /* Corpo Vazio */
    }
    void show(){
        r.show(dsp.CYAN);
    }
};

class Game{
    Post postA;
public:
    Game(int n):
    postA(n){

    }
    void run(){
        postA.show();
    }
};


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
    Game game(13);
    Rect rectwindow(0,0,Display::MAX_X,Display::MAX_Y);
    rectwindow.show(Display::BWHITE);
    game.run();
    kbd.get();
}

void rectfn(){
    DeltaTime timer(1);
    Rect a( 2, 3, 9, 6 );
    a.show( Display::BWHITE );
    timer.start();
    timer.wait();
    Rect b( 4, 2, 10, 8 );
    b.show( Display::BGREEN );
    timer.start();
    timer.wait();
    Rect c = a.intersectNot( b );
    c.show( Display::BMAGENTA);
    Rect d(13, 1, 13, 20);
    d.show(Display::BCYAN);
    kbd.get();
}

int main(int argc, char ** argv){
    colorfn();
    dsp.windowClear();
    dsp.resetColor();
    windowfn();
    char msg[] = "Prima uma tecla para terminar";
    Point max(Display::MAX_X-sizeof(msg), Display::MAX_Y-1);
    DeltaTime delta(0.5F);
    int color;
    Point pos; 
    dsp.windowClear();
    rectfn();
    dsp.windowClear();
    kbd.setMode(Keyboard::VIEW);
    while(kbd.get() == KEY_NONE){
        delta.start();
        pos = Random::get(Point(1,1), max);
        color = Random::get(Display::BLACK, Display::BWHITE);
        dsp.setForeground(color);
        dsp.setCursor(pos.getX(), pos.getY());
        dsp.puts(msg);
        dsp.resetColor();
        delta.wait();
        dsp.setCursor(pos.getX(),pos.getY());
        for (int i=0; i<30;i++)
            dsp.putc(' ');
    }
}