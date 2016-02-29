#ifndef BINARYEXPRESSIONMODEL_H_INCLUDED
#define BINARYEXPRESSIONMODEL_H_INCLUDED

#include "BinaryExpression.h"

namespace core{

    template <class T>
    class BinaryExpressionModel : public BinaryExpression<T>, public Expression<T>{
        private:
            BinaryExpression<T>* _operator;
            Expression<T>* left;
            Expression<T>* right;

        public:
            BinaryExpressionModel(BinaryExpression<T>*, Expression<T>*, Expression<T>*);
            virtual T evaluate() const;
            virtual T evaluate(Expression<T>*, Expression<T>*) const;
    };


    template <class T>
    BinaryExpressionModel<T>::BinaryExpressionModel(BinaryExpression<T>* __operator, Expression<T>* _left, Expression<T>* _right):
        _operator(__operator), left(_left), right(_right) {}

    template <class T>
    T BinaryExpressionModel<T>::evaluate() const{
        if(left != NULL && right != NULL)
            return evaluate(left, right);
        else
            throw string("Expression nulle.");
    }

    template <class T>
    T BinaryExpressionModel<T>::evaluate(Expression<T>* _left, Expression<T>* _right) const{
        if(_operator != NULL)
            return _operator->evaluate(_left, _right);
        else
            throw string("Expression nulle.");
    }
}

#endif // BINARYEXPRESSIONMODEL_H_INCLUDED
