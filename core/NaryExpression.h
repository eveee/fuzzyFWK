#ifndef NARYEXPRESSION_H_INCLUDED
#define NARYEXPRESSION_H_INCLUDED

#include "BinaryExpression.h"
#include <vector>

namespace core{

    template <class T>
    class NaryExpression{
        public:
            virtual T evaluate(vector<Expression<T>*>) const = 0;
    };
}

#endif // NARYEXPRESSION_H_INCLUDED
