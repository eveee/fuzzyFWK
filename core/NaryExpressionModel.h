#ifndef NARYEXPRESSIONMODEL_H_INCLUDED
#define NARYEXPRESSIONMODEL_H_INCLUDED

#include "NaryExpression.h"

namespace core{

    template <class T>
    class NaryExpressionModel : public NaryExpression<T>, public Expression<T>{
        private:
            NaryExpression<T>* operator;
            vector<Expression<T>*> operands;

        public:
            NaryExpressionModel(NaryExpression<T>*, vector<Expression<T>*>);
            virtual T evaluate() const;
            virtual T evaluate(vector<Expression<T>*>) const;
    };


    template <class T>
    NaryExpressionModel<T>::NaryExpressionModel(NaryExpression<T>* __operator, vector<Expression<T>*> _operands):
        _operator(__operator), operands(_operands) {}

    template <class T>
    T NaryExpressionModel<T>::evaluate() const{
        if(left != NULL && right != NULL)
            return evaluate(operands);
        else
            throw string("Expression nulle.");
    }

    template <class T>
    T NaryExpressionModel<T>::evaluate(vector<Expression<T>*> _operands) const{
        if(_operator != NULL)
            return _operator->evaluate(_operands);
        else
            throw string("Expression nulle.");
    }
}

#endif // NARYEXPRESSIONMODEL_H_INCLUDED
