#include "Rect.h"
#include "Display.h"
#include "LineBuf.h"

namespace Common{
    static inline int min(int a, int b){
        return a<b?a:b;
    }

    static inline int max(int a, int b){
        return a>b?a:b;
    }

    static inline bool between( int a, int v, int b ){
        return a<v && v<b;
    }
};

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
    buffer.set(right-left+1,0);
    for (int column = top; column <= bottom; ++column){
        dsp.setCursor(left, column);
        dsp.puts(buffer.getPtr());
    }    
    buffer.set(right-left+1,FILL_CHAR);
    dsp.resetColor();
}
Rect Rect::intersect(const Rect &r) const{
    if(right < r.left && bottom < r.top)
        return Rect(0,0,0,0);
    return Rect(Common::max(left, r.left), Common::max(top, r.top), Common::min(right, r.right), Common::min(bottom, r.bottom));
}
Rect Rect::intersectNot( const Rect &r ) const{
    return Rect(
        Common::between( left, r.right, right ) ? r.right+1 : left,
        Common::between( top, r.top, bottom ) ? r.top+1 : top,
        Common::between( left, r.left, right ) ? r.left-1 : right,
        Common::between( top, r.bottom, bottom ) ? r.bottom-1 : bottom
    );
}
const Rect & Rect::addEqual(Point delta){

}