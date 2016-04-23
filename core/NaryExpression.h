#ifndef NARYEXPRESSION_H_INCLUDED
#define NARYEXPRESSION_H_INCLUDED

#include "BinaryExpression.h"

namespace core{

    template <class T>
    class NaryExpression{
        public:
            virtual T evaluate(Expression<T>*[]) const = 0;
    };
}

#endif // NARYEXPRESSION_H_INCLUDED
