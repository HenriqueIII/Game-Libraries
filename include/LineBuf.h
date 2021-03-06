#ifndef LINEBUF_H
#define LINEBUF_H

#include <cstring>
#include "Display.h"

// Caracter Bloco
static const char FILL_CHAR=ACS_BLOCK;

class LineBuf{
    enum{MAX_BUF = Display::MAX_X - Display::MAX_Y + 1};
    char mem[MAX_BUF];
public:
    LineBuf(){
        for(int i=0; i<MAX_BUF-1; ++i)
            mem[i]=FILL_CHAR;
        mem[MAX_BUF-1]=0;
    }
    void set (int idx, int val){
        mem[idx] = char(val);
    }
    char * getPtr(){
        return mem;
    }
};

#endif