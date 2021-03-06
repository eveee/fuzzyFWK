#ifndef AGGMAX_H_INCLUDED
#define AGGMAX_H_INCLUDED

#include "Operators.h"

using namespace core;

namespace fuzzy{

    template <class T>
    class AggMax : public Agg<T>{
        public :
            virtual T evaluate(Expression<T>*, Expression<T>*) const;
    };


    template <class T>
    T AggMax<T>::evaluate(Expression<T>* l, Expression<T>* r) const{
        T left = l->evaluate();
        T right = r->evaluate();
        return ((left >= right) ? left : right);
    }

}

#endif // AGGMAX_H_INCLUDED
