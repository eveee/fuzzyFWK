#ifndef ISBELL_H_INCLUDED
#define ISBELL_H_INCLUDED

#include "Operators.h"

using namespace core;

namespace fuzzy {

    template <class T>
    class IsBell : public Is<T> {

        private:

            T min;
            T center;
            T mid;

        public :

            IsBell(const T&, const T&, const T&);
            virtual T evaluate(Expression<T>*) const;
            T getMin() const;
            T getMid() const;
            T getCenter() const;

    };

    template <class T>
    IsBell<T>::IsBell(const T& _min, const T& _mid, const T& _center):
        min(_min), mid(_mid), center(_center)
	{

	}

    template <class T>
    T IsBell<T>::evaluate(Expression<T>* operand) const
	{
        T value = operand->evaluate();
        if (value <= min || value >= 2*(center - min)+ min)
            return 0;
        T denum = 1;
        T a;
        if ((a = (value - center) / min ) >= 0)
            for (T i = 0; i < 2*mid; i++)
                denum *= a;
        else
            for (T i = 0; i < 2*mid; i++)
                denum *= - a;
        return 1 / (1 + denum);
    }

    template <class T>
    T IsBell<T>::getMin() const
	{
        return min;
    }

    template <class T>
    T IsBell<T>::getMid() const
	{
        return mid;
    }

    template <class T>
    T IsBell<T>::getCenter() const
	{
        return center;
    }

}


#endif // ISBELL_H_INCLUDED
