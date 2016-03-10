#ifndef COGDEFUZZ_H_INCLUDED
#define COGDEFUZZ_H_INCLUDED

#include "MamdaniDefuzz.h"

namespace fuzzy{

    template <class T>
    class CogDefuzz : public MamdaniDefuzz<T>{
        public :
            CogDefuzz();
            CogDefuzz(const T&, const T&, const T&);
            virtual T defuzz(typename core::Evaluator<T>::Shape) const;
        private:
            T min, max, step;
    };

    template <class T>
    CogDefuzz<T>::CogDefuzz():
        min(0), max(0), step(0)
    {

    }

    template <class T>
    CogDefuzz<T>::CogDefuzz(const T& _min, const T& _max, const T& _step):
        min(_min), max(_max), step(_step)
    {

    }

    template <class T>
    T CogDefuzz<T>::defuzz(typename core::Evaluator<T>::Shape sh) const{
        T sum_x, sum_y;
        for (unsigned int i = 0; i<sh.first.size(); i++){
            sum_x += (sh.first[i] * sh.second[i]);
            sum_y += sh.second[i];
        } return sum_x / sum_y;
    }


}


#endif // COGDEFUZZ_H_INCLUDED
