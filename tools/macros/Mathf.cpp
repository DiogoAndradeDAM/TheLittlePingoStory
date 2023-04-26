#include "Mathf.hpp"

int Mathf::Clamp(int value, int max, int min)
{
    if(value > max){
        value = max;
    }else if(value < min){
        value = min;
    }
    return value;
}