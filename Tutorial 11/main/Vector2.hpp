#ifndef _VECTOR2_HPP_
#define _VECTOR2_HPP_

#include <cmath>

namespace Maths
{

    template<class T>
    class Vector2
    {
    private:

        T vec[2]; //member vector

    public:

        inline Vector2()
        {
            //Deliberately empty default ctor
        }

        inline Vector2(const Vector2<T>& original)
        {
            vec[0] = original.vec[0];
            vec[1] = original.vec[1];
        }

        inline Vector2(T v0, T v1)
        {
            vec[0] = v0;
            vec[1] = v1;
        }

        inline Vector2(T v[])
        {
            vec[0] = v[0];
            vec[1] = v[1];
        }

        //
        //Access
        //

        // Setters
        void x(T& newX) { vec[0] = newX; };
        void y(T& newY) { vec[1] = newY; };
        void x(const T newX) { vec[0] = newX; };
        void y(const T newY) { vec[1] = newY; };

        // Getters 
        T& x() { return vec[0]; };
        T& y() { return vec[1]; };
        T x() const { return vec[0]; };
        T y() const { return vec[1]; };

        T& operator[](int element)
        {
            return vec[element];
        }

        T operator[](int element) const
        {
            return vec[element];
        }

        //
        //Arithmetic.
        //

                //Addition and Subtraction

        void operator=(const Vector2<T>& v)
        {
            vec[0] = v.x();
            vec[1] = v.y();
        }

        Vector2<T> operator+=(const Vector2<T>& v)
        {
            vec[0] += v[0];
            vec[1] += v[1];
            return *this;
        }

        Vector2<T> operator+(const Vector2<T>& v) const
        {
            Vector2 acc(*this);
            return acc += v;
        }

        Vector2<T> operator-=(const Vector2<T>& v)
        {
            vec[0] -= v[0];
            vec[1] -= v[1];
            return *this;
        }

        Vector2<T> operator-(const Vector2<T>& v) const
        {
            Vector2 acc(*this);
            return acc -= v;
        }

        const Vector2<T> operator-() const
        {
            vec[0] = -vec[0];
            vec[1] = -vec[1];
            return *this;
        }

        //Note: These are defined as friends, i.e. they are outside of the class
        //The reason for this is that we want to allow the paramters to be in either direciton
        //i.e. vec * s or s * vec.  If we overload * inside the class the first parameter is
        //automatically the 'this' I'm not so sure it needs to be done for both however.
        friend Vector2<T> operator*(T s, const Vector2<T>& v)
        {
            return s * v;
        }

        friend Vector2<T> operator*(const Vector2<T>& v, T s)
        {
            Vector2<T> ret(v);
            return ret *= s;
        }

        Vector2<T> operator*=(T s)
        {
            vec[0] *= s;
            vec[1] *= s;
            return *this;
        }

        //Dot Product
        T operator*(const Vector2<T>& v) const
        {
            return (vec[0] * v[0]) + (vec[1] * v[1]);
        }

        Vector2<T> operator/=(T divisor)
        {
            vec[0] /= divisor;
            vec[1] /= divisor;
            return *this;
        }

        T lengthSquared() const
        {
            return (vec[0] * vec[0]) + (vec[1] * vec[1]);
        }

        double length() const
        {
            return sqrt(this->lengthSquared());
        }

        float lengthf() const
        {
            return sqrt(this->lengthSquared());
        }

        Vector2<T> normalised() const
        {
            Vector2 another(this);
            another.normalise();
            return another;
        }

        void normalise()
        {
            if (this->length() > 0)
            {
                (*this) /= this->length();
            }
        }

        T normalise(Vector2<T>* const pvUnit) const
        {
            auto lengthOf = this->length();

            if (lengthOf > 0)
            {
                (*pvUnit) /= this->length();
            }
        }

        const float EPSILON = 0.0001f;

        bool operator==(const Vector2<T>& v) const
        {
            Vector2 delta(this);
            delta = -v;

            if (fabs(delta[0]) < EPSILON)
            {
                if (fabs(delta[1]) < EPSILON)
                    return true;
            }

            return false;
        }

        static bool isLonger(const Vector2<T>& v1, const Vector2<T>& v2)
        {
            if (v1.length() > v2.length())
                return true;
            else
                return false;
        }
    };
}
#endif // _VECTOR2_HPP_