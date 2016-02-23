#ifndef ANDMIN_H_INCLUDED
#define ANDMIN_H_INCLUDED

#include "Operators.h"

using namespace core;

namespace fuzzy{

    template <class T>
    class AndMin : public And<T>{
        public :
            virtual T evaluate(Expression<T>*, Expression<T>*) const;
    };


    template <class T>
    T AndMin<T>::evaluate(Expression<T>* l, Expression<T>* r) const{
        T left = l->evaluate();
        T right = r->evaluate();
        return ((left <= right) ? left : right);
    }

}

#endif // ANDMIN_H_INCLUDED
