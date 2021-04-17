#ifndef LINEBUF_H
#define LINEBUF_H

#include <cstring>
#include "Display.h"

// Caracter Bloco
static const wint_t FILL_CHAR = L'\u2588';

class LineBuf{
    enum{MAX_BUF = Display::MAX_X - Display::MIN_X + 1};
    wint_t mem[MAX_BUF+1];
public:
    LineBuf(){
        for(int i=0; i<MAX_BUF; ++i)
            mem[i]=FILL_CHAR;
        mem[MAX_BUF]=0;
    }
    void set (int idx, wint_t val){
        mem[idx] = val;
    }
    wint_t * getPtr(){
        return mem;
    }
};

#endif