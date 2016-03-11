#include <float.h>
#include "Mathf.h"


float Mathf::PI = 3.14159265358979f;
float Mathf::Deg2Rad = PI * 2 / 360.0f;
float Mathf::Rad2Deg = 360.0f / PI / 2;
float Mathf::Infinity = FLT_MAX;
float Mathf::NegativeInfinity = -FLT_MAX;

float Mathf::deg2Rad(float d)
{
	return d * Deg2Rad;
}

float Mathf::rad2Deg(float r)
{
	return r * Rad2Deg;
}

bool Mathf::isPowerOf2(int i)
{
    if (i > 0) {
        return ((i-1)&i) == 0;
    }else if(i == 0)
        return true;
    else
        return false;
}