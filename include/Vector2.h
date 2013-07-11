#ifndef DEMO_VECTOR2_H
#define DEMO_VECTOR2_H

#include <cmath>

namespace demo {

    const float PI = 3.1415926535;

    float fdemo_inv_sqrt(float num){
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
            x = 0;
            y = 0;
        }

        void Vector2(T x, T y){
            this->x = x;
            this->y = y;
        }

        void add(Vector2 v){
            x += v.x;
            y += v.y;
        };

        void subtract(Vector2 v){
            x -= v.x;
            y -= v.y;
        };

        void scale(T scalar){
            x *= scalar;
            y *= scalar;
        };

        T magnitudeSquare(){
            return x * x + y * y;
        };

        T magnitude(){
            return sqrt(x * x + y * y);
        };

        T approxMagnitude(){
            return fdemo_inv_sqrt(x * x + y * y);
        }

        T dot(Vector2 other){
            return this->x * x + this->y * y;
        };

        float angle(){
            return atan2(y, x) + PI;
        }

        void rotate(float angle){
            T rotx =  cos(angle) * x + sin(angle) * y;
            T roty = -sin(angle) * x + cos(angle) * y;

            x = rotx;
            y = roty;
        }

        Vector2 perp(){
            return Vector2(-this->y, this->x);
        }

        bool orthogonalTo(Vector2 other){
            return dot(other) == 0;
        };

        Vector2 unit(){
            Vector2 norm = *this;
            norm.normalize();
            return norm;
        }

        void normalize(){
            T mag = magnitude();
            x /= mag;
            y /= mag;
        }

        friend Vector2& operator+=(Vector2& lhs, Vector2& rhs);
        friend Vector2& operator-=(Vector2& lhs, Vector2& rhs);
    }

    typedef Vector2<int>            Vector2i;
    typedef Vector2<float>          Vector2f;
    typedef Vector2<double>         Vector2d;
    typedef Vector2<unsigned int>   Vector2u;

    template <typename T>
    Vector2<T>& operator+=(Vector2<T>& lhs, Vector2<T>& rhs){
        lhs.add(rhs);
        return lhs;
    }

    template <typename T>
    Vector2<T>& operator-=(Vector2<T>& lhs, Vector2<T>& rhs){
        lhs.subtract(rhs);
        return lhs;
    }
} // namespace demo

#endif DEMO_VECTOR_H
