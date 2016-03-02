#ifndef COGDEFUZZ_H_INCLUDED
#define COGDEFUZZ_H_INCLUDED

#include "MamdaniDefuzz.h"

namespace fuzzy{

    template <class T>
    class CogDefuzz : public MamdaniDefuzz<T>{
        public :
            virtual T defuzz(typename core::Evaluator<T>::Shape) const;
    };

    template <class T>
    T CogDefuzz<T>::defuzz(typename core::Evaluator<T>::Shape sh) const{
        T x_sum;
        for (unsigned int i = 0; i<sh.first.size(); i++){
            x_sum += sh.first[i];
        } return x_sum / sh.first.size();
    }


}


#endif // COGDEFUZZ_H_INCLUDED
