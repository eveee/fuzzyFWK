#ifndef ORMAX_H_INCLUDED
#define ORMAX_H_INCLUDED

#include "Operators.h"
using namespace core;

namespace fuzzy{

    template <class T>
    class OrMax : public Or<T>{
        public :
            virtual T evaluate(Expression<T>*, Expression<T>*) const;
    };

    template <class T>
    T OrMax<T>::evaluate(Expression<T>* l, Expression<T>* r) const{
        T left = l->evaluate();
        T right = r->evaluate();
        return ((left >= right) ? left : right);
    }

}

#endif // ORMAX_H_INCLUDED
