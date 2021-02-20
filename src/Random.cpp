#include <cstdlib>
#include <ctime>
#include "Point.h"
#include "Random.h"

void Random::init (unsigned s){
    srand(s);
}
void Random::init (){
    srand((unsigned) time(NULL));
}
unsigned Random::get (unsigned max){
    //RAND_MAX é o máximo valor retornado por rand().
    return (int) (((long)rand()*max)/RAND_MAX +1);
}
unsigned Random::get (unsigned min, unsigned max){
    return get(max - min +1) + min;
}
Point Random::get(Point min, Point max){
    return Point(get(min.getX(), max.getX()), get(min.getY(), max.getY()));
}