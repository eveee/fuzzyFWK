#ifndef SUGENODEFUZZ_H_INCLUDED
#define SUGENODEFUZZ_H_INCLUDED

#include "../core/NaryExpression.h"
#include "SugenoThen.h"

namespace fuzzy{

    template <class T>
    class SugenoDefuzz{
        public :
            virtual T evaluate(vector<Expression<T>*>*) const;
    };

    template <class T>
    T SugenoDefuzz<T>::evaluate(vector<Expression<T>*>* operands) const{
        T denum = 0; T num = 0;
        BinaryExpressionModel<T> *bem;
        BinaryShadowExpression<T> *bse;
        SugenoThen<T> *st;

        for(int i = 0; i < operands->size(); i++){
            bem = (BinaryExpressionModel<T>) operands.at(i);
            bse = (BinaryShadowExpression<T>) (bem->getOperator());

            st = (SugenoThen<T>) (bse -> getTarget());

            denum += st->getPremiseValue();
            num += operands.at(i);
        }
        return (denum == 0 ? 0 : num/denum);
    }

}

#endif // SUGENODEFUZZ_H_INCLUDED
