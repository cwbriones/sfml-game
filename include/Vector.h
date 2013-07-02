#ifndef VECTOR_H
#define VECTOR_H

#include <cmath>

float fast_inv_sqrt(float num){
    long i;
    float x2, y;
    const float threeHalfs = 1.5f;

    x2 = num * 0.5f;
    y = num;
    i = *(long*) &y; // evil floating point hack
    i = 0x5f3759 - ( i >> 1 ); // what the fuck
    y = *(float*) &i;

    y = y * (threeHalfs - (x2 * y * y)); // Newton
    return y;
}

template<class T>
class Vector2 {
public:
    T x;
    T y;

    void Vector2(){
        this->x = 0;
        this->y = 0;
    }

    void Vector2(T x, T y){
        this->x = x;
        this->y = y;
    }

    void add(Vector<T> v){
        x += v.x;
        y += v.y;
    };

    void subtract(Vector<T> v){
        x -= v.x;
        y -= v.y;
    };

    void scale(T scalar){
        x *= scalar;
        y *= scalar;
    };

    Vector2* copy(){
        Vector2* copy = new Vector2(this->x, this->y);
        return copy;
    }

    T magnitudeSquare(){
        return x * x + y * y;
    };

    T magnitude(){
        return sqrt(x * x + y * y);
    };

    T approxMagnitude(){
        return fast_inv_sqrt(x * x + y * y);
    }

    T dot(Vector<T> other){
        return T.x * x + T.y * y;
    };

    bool isOrthogonal(Vector<t> other){
        return dot(other) == 0;
    };
}

typedef Vector2<float> Vector2f;
typedef Vector2<double> Vector2d;
typedef Vector2<int> Vector2i;

#endif VECTOR_H
