#ifndef NOTMINUS1_H_INCLUDED
#define NOTMINUS1_H_INCLUDED

#include "Operators.h"
using namespace core;

namespace fuzzy{

    template <class T>
    class NotMinus1 : public Not<T>{
        public :
            virtual T evaluate(Expression<T>*) const;

    };

    template <class T>
    T NotMinus1<T>::evaluate(Expression<T>* operand) const{
        return 1-operand->evaluate();
    }

}

#endif // NOTMINUS1_H_INCLUDED
