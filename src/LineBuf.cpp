#include "LineBuf.h"

LineBuf::LineBuf(){
        for(int i=0; i<MAX_BUF; ++i)
            mem[i]=FILL_CHAR;
        mem[MAX_BUF]=0;
}
void LineBuf::set (int idx, wint_t val){
        mem[idx] = val;
    }
wint_t * LineBuf::getPtr(){
        return mem;
}