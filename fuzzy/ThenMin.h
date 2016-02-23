#ifndef THENMIN_H_INCLUDED
#define THENMIN_H_INCLUDED

#include "Operators.h"

using namespace core;

namespace fuzzy{

    template <class T>
    class ThenMin : public Then<T>{
        public :
            virtual T evaluate(Expression<T>*, Expression<T>*) const;
    };

    template <class T>
    T ThenMin<T>::evaluate(Expression<T>* l, Expression<T>* r) const{
        T left = l->evaluate();
        T right = r->evaluate();
        return ((left <= right) ? left : right);
    }

}

#endif // THENMIN_H_INCLUDED
