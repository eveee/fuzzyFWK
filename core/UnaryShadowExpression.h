#ifndef UNARYSHADOWEXPRESSION_H_INCLUDED
#define UNARYSHADOWEXPRESSION_H_INCLUDED

#include "UnaryExpression.h"

namespace core{

    template <class T>
    class UnaryShadowExpression : public UnaryExpression<T>{
        private :
            UnaryExpression<T> target;

        public :
            UnaryShadowExpression(UnaryExpression<T>*);
            T evaluate(Expression<T>*);
    };

    template <class T>
    UnaryShadowExpression<T>::UnaryShadowExpression(UnaryExpression<T>* _target):
        target(_target){}

    template <class T>
    T UnaryShadowExpression<T>::evaluate(Expression<T>* operand){
        if(target != NULL)
            return target.evaluate(operand);
    }

}

#endif // UNARYSHADOWEXPRESSION_H_INCLUDED
