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
        //SugenoConclusion *sgc = new SugenoConclusion({a, b, c})->evaluate(operands);
    }


}

#endif // SUGENODEFUZZ_H_INCLUDED
