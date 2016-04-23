#ifndef SUGENODEFUZZ_H_INCLUDED
#define SUGENODEFUZZ_H_INCLUDED

#include "../core/NaryExpression.h"

namespace fuzzy{

    template <class T>
    class SugenoDefuzz{
        public :
            virtual T evaluate(Expression<T>*[]) const;
    };

    template <class T>
    T SugenoDefuzz<T>::evaluate(Expression<T>*[] operands) const{
        T denum = 0; T num = 0;
        BinaryExpressionModel<T> *bem;
        BinaryShadowExpression<T> *bse;
        SugenoThen<T> *st;

        for(int i = 0; i < ; i++){ //changer tableau en vector pour avoir la size, dans sugenoconclusion aussi
            bem = (binaryexpressionmodel) (operands.at(i));
            bse = (binaryshadowexpression) (bem->getOperator());
            st = (sugenothen) (bse-> getTarget());
            denum += st->getPremiseValue();
            num += operands.at(i);
        }
        return (denum == 0 ? 0 : num/denum);
    }

}

#endif // SUGENODEFUZZ_H_INCLUDED
