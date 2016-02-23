#ifndef THENMULT_H_INCLUDED
#define THENMULT_H_INCLUDED

#include "Operators.h"

using namespace core;

namespace fuzzy{

    template <class T>
    class ThenMult : public Then<T>{
        public :
            virtual T evaluate(Expression<T>*, Expression<T>*) const;
    };

    template <class T>
    T ThenMult<T>::evaluate(Expression<T>* l, Expression<T>* r) const{
        T left = l->evaluate();
        T right = r->evaluate();
        return (left*right);
    }

}

#endif // THENMULT_H_INCLUDED
