#ifndef COGDEFUZZ_H_INCLUDED
#define COGDEFUZZ_H_INCLUDED

#include "MamdaniDefuzz.h"

namespace fuzzy{
    template class<T>
    class CogDefuzz : public MamdaniDefuzz<T>{
    public :
        virtual float defuzz(Evaluator::Shape);
    };

    float CogDefuzz<T>::defuzz(Evaluator::Shape){

    }


}


#endif // COGDEFUZZ_H_INCLUDED
