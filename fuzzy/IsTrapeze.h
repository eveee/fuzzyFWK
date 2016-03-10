#ifndef ISTRAPEZE_H_INCLUDED
#define ISTRAPEZE_H_INCLUDED

#include "Operators.h"

using namespace core;

namespace fuzzy {

    template <class T>
    class IsTrapeze : public Is<T> {

        private:

            T min;
            T midOne;
            T midTwo;
            T max;

        public :

            IsTrapeze(const T&, const T&, const T&, const T&);
            virtual T evaluate(Expression<T>*) const;
            T getMin() const;
            T getMidOne() const;
            T getMidTwo() const;
            T getMax() const;

    };

    template <class T>
    IsTrapeze<T>::IsTrapeze(const T& _min, const T& _midOne, const T& _midTwo, const T& _max):
        min(_min), midOne(_midOne), midTwo(_midTwo), max(_max)
	{

	}

    template <class T>
    T IsTrapeze<T>::evaluate(Expression<T>* operand) const
	{
        T value = operand->evaluate();
        if (value <= min || value >= max)
            return 0;
        else if (value >= midOne || value <= midTwo)
        	return 1;

        return ((value <= midOne) ?
                    (value - min)/(midOne - min) :
                    (max - value)/(max - midTwo));
    }

    template <class T>
    T IsTrapeze<T>::getMin() const
	{
        return min;
    }

    template <class T>
    T IsTrapeze<T>::getMidOne() const
	{
        return midOne;
    }

    template <class T>
    T IsTrapeze<T>::getMidTwo() const
   	{
        return midTwo;
    }

    template <class T>
    T IsTrapeze<T>::getMax() const
	{
        return max;
    }

}

#endif //ISTRAPEZE_H_INCLUDED
