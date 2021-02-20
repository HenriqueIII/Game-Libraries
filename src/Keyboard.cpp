#include "Keyboard.h"
#include "Display.h"
#include <ncurses.h>

Keyboard kbd;

Keyboard::Keyboard(){
    setMode(WAIT);
    keypad(dsp.getWindow(), TRUE);
}
void Keyboard::setMode(KeyAcess m){
    mode = m;

    if(mode == WAIT)
        nodelay(dsp.getWindow(), FALSE);
    
    if(mode == VIEW)
        nodelay(dsp.getWindow(), TRUE);
}
int Keyboard::getLast(){
    return last;
}
int Keyboard::get(){
    int keypress;
    if((keypress=wgetch(dsp.getWindow()))==ERR)
        return KEY_NONE;
    last = keypress;
    return keypress;
}