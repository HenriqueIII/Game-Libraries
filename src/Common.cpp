#include "Common.h"

const char * Common::itoa(int n){
    static char tmp[12];
    char * res = tmp + 11;
    *--res='\0';
    if (!n){
        *--res='0';
        return res;
    }
    while (n>0){
        *--res=(n%10)+'0';
        n/=10;
    }
    return res;
}
char * Common::strcpy(char * dest, const char * src){
    int len = strlen(src);
    for(int i=0; i<len; ++i)
        dest[i]=src[i];
    dest[len]='\0';
    return dest;
}
int Common::strlen(const char * str){
    char * q = (char*)str;
    while(*q++);
    return q-str-1;
}