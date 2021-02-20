#include "DeltaTime.h"

DeltaTime::DeltaTime (float sec){
    setDelta(sec);
}
// Converte os segundos em ticks de clock.
void DeltaTime::setDelta(float sec){
    delta = CLOCKS_PER_SEC * sec;
}
void DeltaTime::start(){
    init = clock();
}
bool DeltaTime::dttimeout(){
    return clock() - init >= delta; 
}
void DeltaTime::wait(){
    while ( ! dttimeout());
}