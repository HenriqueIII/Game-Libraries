#include "Rect.h"
#include "Display.h"
#include "LineBuf.h"

Rect::Rect(int l, int t, int r, int b){
    left=l;
    top=t;
    right=r;
    bottom=b;
}
Rect::Rect(Point lt, Point rb){
    left = lt.getX();
    top = lt.getY();
    right = rb.getX();
    bottom = rb.getY();
}
Rect::Rect(Point center, int height, int width){
    right = center.getX() + width/2;
    left = right-width + 1;
    top = center.getY() + height/2;
    bottom = top + height -1;
}
Point Rect::getCenter(){
    return Point((left+right)/2, (top+bottom)/2);
}
void Rect::show(int color) const{
    dsp.setForeground(color);
    dsp.setBackground(color);
    LineBuf buffer;
    buffer.set(right+1,0);
    for (int column = top; column <= bottom; ++column){
        dsp.setCursor(left, column);
        dsp.puts(buffer.getPtr());
    }    
    buffer.set(right+1,FILL_CHAR);
    dsp.resetColor();
}
Rect Rect::intersect(const Rect &r) const{

}
Rect Rect::intersectNot(const Rect &r) const{

}
const Rect & Rect::addEqual(Point delta){

}