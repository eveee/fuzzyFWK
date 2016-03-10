#ifndef ISTRAPEZELEFT_H_INCLUDED
#define ISTRAPEZELEFT_H_INCLUDED

#include "Operators.h"

using namespace core;

namespace fuzzy {

    template <class T>
    class IsTrapezeLeft : public Is<T> {

        private:

            T min;
            T max;

        public :

            IsTrapezeLeft(const T&, const T&);
            virtual T evaluate(Expression<T>*) const;
            T getMin() const;
            T getMax() const;

    };

    template <class T>
    IsTrapezeLeft<T>::IsTrapezeLeft(const T& _min, const T& _max):
        min(_min), max(_max)
	{

	}

    template <class T>
    T IsTrapezeLeft<T>::evaluate(Expression<T>* operand) const
	{
        T value = operand->evaluate();
        if (value <= min)
            return 1;
        else if (value >= max)
        	return 0;

        return (max - value)/(max - min);
    }

    template <class T>
    T IsTrapezeLeft<T>::getMin() const
	{
        return min;
    }


    template <class T>
    T IsTrapezeLeft<T>::getMax() const
	{
        return max;
    }

}


#endif // ISTRAPEZELEFT_H_INCLUDED
