#ifndef UNARYEXPRESSIONMODEL_H_INCLUDED
#define UNARYEXPRESSIONMODEL_H_INCLUDED

#include "UnaryExpression.h"

namespace core{

    template <class T>
    class UnaryExpressionModel : public UnaryExpression<T>, public Expression<T>{
        private:
            UnaryExpression<T>* _operator;
            Expression<T>* operand;

        public:
            UnaryExpressionModel(UnaryExpression<T>*, Expression<T>*);
            virtual T evaluate() const;
            virtual T evaluate(Expression<T>*) const;

			virtual Expression<T>* getOperand() const;
			virtual UnaryExpression<T>* getOperator() const;
			virtual void setOperand(Expression<T>*);
			virtual void setOperator(UnaryExpression<T>*);
    };


    template <class T>
    UnaryExpressionModel<T>::UnaryExpressionModel(UnaryExpression<T>* __operator, Expression<T>* _operand):
        _operator(__operator), operand(_operand) {}

    template <class T>
    T UnaryExpressionModel<T>::evaluate() const{
        if(operand != NULL)
            return evaluate(operand);
    }

    template <class T>
    T UnaryExpressionModel<T>::evaluate(Expression<T>* _operand) const{
        if(_operator != NULL)
            return _operator->evaluate(_operand);
    }

    template <class T>
    Expression<T>* UnaryExpressionModel<T>::getOperand() const{
        return operand;
    }

    template <class T>
    UnaryExpression<T>* UnaryExpressionModel<T>::getOperator() const{
        return _operator;
    }

    template <class T>
    void UnaryExpressionModel<T>::setOperand(Expression<T>* _operand){
        operand = _operand;
    }

    template <class T>
    void UnaryExpressionModel<T>::setOperator(UnaryExpression<T>* __operator){
        _operator =  __operator;
    }

}

#endif // UNARYEXPRESSIONMODEL_H_INCLUDED
