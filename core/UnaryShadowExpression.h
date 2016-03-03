#ifndef UNARYSHADOWEXPRESSION_H_INCLUDED
#define UNARYSHADOWEXPRESSION_H_INCLUDED

#include "UnaryExpression.h"
#include "NullExpressionException.h"

namespace core {

    template <class T>
    class UnaryShadowExpression : public UnaryExpression<T> {

        private :

            UnaryExpression<T>* target;

        public :

            UnaryShadowExpression(UnaryExpression<T>*);
            virtual T evaluate(Expression<T>*) const;
            void setTarget(UnaryExpression<T>*);
            UnaryExpression<T>* getTarget() const;

    };

    template <class T>
    UnaryShadowExpression<T>::UnaryShadowExpression(UnaryExpression<T>* _target):
        target(_target)
	{

	}

    template <class T>
    T UnaryShadowExpression<T>::evaluate(Expression<T>* operand) const
	{
        if(target != NULL)
            return target->evaluate(operand);
        else
        	throw NullExpressionException("the expression is null", __LINE__);
    }

    template <class T>
    void UnaryShadowExpression<T>::setTarget(UnaryExpression<T>* o)
	{
    	target = const_cast<BinaryExpression<T>* >(o);
    }

    template <class T>
    UnaryExpression<T>* UnaryShadowExpression<T>::getTarget() const
    {
       	return target;
    }

}

#endif
