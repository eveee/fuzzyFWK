#ifndef ISTRAPEZERIGHT_H_INCLUDED
#define ISTRAPEZERIGHT_H_INCLUDED

#include "Operators.h"

using namespace core;

namespace fuzzy {

    template <class T>
    class IsTrapezeRight : public Is<T> {

        private:

            T min;
            T max;

        public :

            IsTrapezeRight(const T&, const T&);
            virtual T evaluate(Expression<T>*) const;
            T getMin() const;
            T getMax() const;

    };

    template <class T>
    IsTrapezeRight<T>::IsTrapezeRight(const T& _min, const T& _max):
        min(_min), max(_max)
	{

	}

    template <class T>
    T IsTrapezeRight<T>::evaluate(Expression<T>* operand) const
	{
        T value = operand->evaluate();
        if (value <= min)
            return 0;
        else if (value >= max)
        	return 1;

        return (value - min)/(max - min);
    }

    template <class T>
    T IsTrapezeRight<T>::getMin() const
	{
        return min;
    }


    template <class T>
    T IsTrapezeRight<T>::getMax() const
	{
        return max;
    }

}

#endif // ISTRAPEZERIGHT_H_INCLUDED
