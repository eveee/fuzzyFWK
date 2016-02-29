#ifndef BINARYSHADOWEXPRESSION_H_INCLUDED
#define BINARYSHADOWEXPRESSION_H_INCLUDED

#include "BinaryExpression.h"

namespace core{

    template <class T>
    class BinaryShadowExpression : public BinaryExpression<T>
    {

        private :

            BinaryExpressionModel<T> target;

        public :

            BinaryShadowExpression(BinaryExpression<T>*);
            virtual T evaluate(Expression<T>*, Expression<T>*) const;
            void setTarget(BinaryExpression<T>*);

    };

    template <class T>
    BinaryShadowExpression<T>::BinaryShadowExpression(BinaryExpression<T>* _target):
        target(_target)
	{

	}

    template <class T>
    T BinaryShadowExpression<T>::evaluate(Expression<T>* left, Expression<T>* right) const
	{
        if(target != NULL)
            return target.evaluate(left, right);
        else
        	throw NullExpressionException("the expression is null", __LINE__);
    }

    template <class T>
    void BinaryShadowExpression<T>::setTarget(BinaryExpression<T>* o)
    {
       	target = o;
    }

}

#endif
