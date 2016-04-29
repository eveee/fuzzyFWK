#ifndef NARYSHADOWEXPRESSION_H_INCLUDED
#define NARYSHADOWEXPRESSION_H_INCLUDED

#include "NaryExpressionModel.h"

namespace core{

    template <class T>
    class NaryShadowExpression : public NaryExpression<T>
    {

        private :

            NaryExpression<T>* target;

        public :

            NaryShadowExpression(NaryExpression<T>*);
            virtual T evaluate(vector<Expression<T>*>*) const;
            void setTarget(const NaryExpression<T>*);
            NaryExpression<T>* getTarget() const;

    };

    template <class T>
    NaryShadowExpression<T>::NaryShadowExpression(NaryExpression<T>* _target):
        target(_target)
	{

	}

    template <class T>
    T NaryShadowExpression<T>::evaluate(vector<Expression<T>*>* operands) const
	{
        if(target != NULL){
            return target->evaluate(operands);
        }
        else
        	throw NullExpressionException("the expression is null", __LINE__);
    }

    template <class T>
    void NaryShadowExpression<T>::setTarget(const NaryExpression<T>* o)
    {
       	target = const_cast<NaryExpression<T>* >(o);
    }

    template <class T>
    NaryExpression<T>* NaryShadowExpression<T>::getTarget() const
    {
       	return target;
    }

}

#endif // NARYSHADOWEXPRESSION_H_INCLUDED
