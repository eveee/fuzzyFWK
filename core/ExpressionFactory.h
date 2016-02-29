#ifndef EXPRESSIONFACTORY_H_INCLUDED
#define EXPRESSIONFACTORY_H_INCLUDED

#include "Expression.h"

namespace core{

    template <class T>
    class ExpressionFactory : public Expression<T>{
        private:
            Expression<T>* memory = new Expression<T>();
        public:
            Expression<T> hold(Expression<T>);
            Expression<T> newUnary(UnaryExpression<T>, Expression<T>);
            Expression<T> newBinary(BinaryExpression<T>, Expression<T>, Expression<T>);
    };

}

#endif // EXPRESSIONFACTORY_H_INCLUDED
