#include "Point.h"

Point::Point(int xT, int yT){
    x = xT;
    y = yT;
}
Point::Point(){
    /* Corpo Vazio */
}
Point Point::add(const Point & p) const{
    return Point ( x+p.x, y+p.y);
}
Point & Point::addEqual(const Point & p){
    x += p.x;
    y += p.y;
    return *this;
}
Point Point::sub(const Point & p) const{
    return Point(x-p.x, y-p.y);
}
int Point::getX() const{
    return x;
}
int Point::getY() const{
    return y;
}
bool Point::isEqual(const Point & p) const{
    return x == p.x && y == p.y;
}
Point & Point::rotateRight(){
    int aux = x;
    x=y;
    y = -aux;
    return *this;
}