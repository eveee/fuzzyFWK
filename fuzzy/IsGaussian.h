#ifndef ISGAUSSIAN_H_INCLUDED
#define ISGAUSSIAN_H_INCLUDED

#include <cmath>
#include <ctgmath>

#include "Operators.h"

using namespace core;

namespace fuzzy {

    template <class T>
    class IsGaussian : public Is<T> {

        private:

            T center;
            T sig;

        public :

            IsGaussian(const T&, const T&);
            virtual T evaluate(Expression<T>*) const;
            T getSig() const;
            T getCenter() const;

    };

    template <class T>
    IsGaussian<T>::IsGaussian(const T& _center, const T& _sig):
        center(_center),sig(_sig)
	{

	}

    template <class T>
    T IsGaussian<T>::evaluate(Expression<T>* operand) const
	{
        T value = operand->evaluate();
        T n = ((value - center) / sig)*((value - center) / sig);
        return (T) exp(-0.5 * n);

    }

    template <class T>
    T IsGaussian<T>::getSig() const
	{
        return sig;
    }

    template <class T>
    T IsGaussian<T>::getCenter() const
	{
        return center;
    }

}

#endif // ISGAUSSIAN_H_INCLUDED
