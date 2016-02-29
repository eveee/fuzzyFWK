#ifndef FUZZYFACTORY_H
#define FUZZYFACTORY_H

#include "ExpressionFactory"

using namespace core;

namespace fuzzy{

    template <class T>
    class FuzzyFactory {

        private :

            And and;
            Or or;
            Then then;
            Agg agg;
            Defuzz defuzz;
            Not not;
            Is is;

        public :

            Expression newAnd(Expression, Expression);
            Expression newOr(Expression, Expression);
            Expression newThen(Expression, Expression);
            Expression newAgg(Expression, Expression);
            Expression newDefuzz(Expression, Expression);
            ExpressionModel newNot(Expression);
            Expression newIs(Is, Expression);

            void changeAnd(And);
            void changeAnd(Or);
            void changeAnd(Then);
            void changeAnd(Agg);
            void changeAnd(Defuzz);
            void changeAnd(Not);
            void changeAnd(Is);

    };
}

template <class T>
Expression FuzzyFactory<T>::newAnd(Expression left, Expression right) {
    return new BinaryShadowExpression(and, left, right);
}

template <class T>
void FuzzyFactory<T>::changeAnd(And _and) {
    and.setTarget(_and);
}

#endif FUZZYFACORY_H
