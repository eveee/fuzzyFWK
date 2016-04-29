#ifndef ORPLUS_H_INCLUDED
#define ORPLUS_H_INCLUDED

#include "Operators.h"

using namespace core;

namespace fuzzy{

    template <class T>
    class OrPlus : public Or<T>{
        public :
            virtual T evaluate(Expression<T>*, Expression<T>*) const;
    };

    template <class T>
    T OrPlus<T>::evaluate(Expression<T>* l, Expression<T>* r) const{
        T left = l->evaluate();
        T right = r->evaluate();
        return (left+right);
    }

}

#endif // ORPLUS_H_INCLUDED
