#ifndef AGGPLUS_H_INCLUDED
#define AGGPLUS_H_INCLUDED

#include "Operators.h"

using namespace core;

namespace fuzzy{

    template <class T>
    class AggPlus : public Agg<T>{
        public :
            virtual T evaluate(Expression<T>*, Expression<T>*) const;
    };


    template <class T>
    T AggPlus<T>::evaluate(Expression<T>* l, Expression<T>* r) const{
        T left = l->evaluate();
        T right = r->evaluate();
        return (left+right);
    }

}

#endif // AGGPLUS_H_INCLUDED
