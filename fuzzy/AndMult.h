#ifndef ANDMULT_H_INCLUDED
#define ANDMULT_H_INCLUDED

#include "Operators.h"

using namespace core;

namespace fuzzy{

    template <class T>
    class AndMult : public And<T>{
        public :
            virtual T evaluate(Expression<T>*, Expression<T>*) const;
    };

    template <class T>
    T AndMult<T>::evaluate(Expression<T>* l, Expression<T>* r) const{
        T left = l->evaluate();
        T right = r->evaluate();
        return (left*right);
    }

}

#endif // ANDMULT_H_INCLUDED
