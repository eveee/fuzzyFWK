#ifndef ISTRIANGLE_H_INCLUDED
#define ISTRIANGLE_H_INCLUDED

#include "Operators.h"

using namespace core;

namespace fuzzy{

    template <class T>
    class IsTriangle : public Is<T>{
        private:
            T min;
            T mid;
            T max;
        public :
            IsTriangle(const T&, const T&, const T&);
            virtual T evaluate(Expression<T>*) const;
            T getMin() const;
            T getMid() const;
            T getMax() const;

    };

    template <class T>
    IsTriangle<T>::IsTriangle(const T& _min, const T& _mid, const T& _max):
        min(_min), mid(_mid), max(_max){}

    template <class T>
    T IsTriangle<T>::evaluate(Expression<T>* operand) const{
        T value = operand->evaluate();
        if (value <= min || value >= max)
            return 0;

        return ((value <= mid) ?
                    (value - min)/(mid - min) :
                    (max - value)/(max - mid));
    }

    template <class T>
    T IsTriangle<T>::getMin() const{
        return min;
    }

    template <class T>
    T IsTriangle<T>::getMid() const{
        return mid;
    }

    template <class T>
    T IsTriangle<T>::getMax() const{
        return max;
    }

}

#endif // ISTRIANGLE_H_INCLUDED
