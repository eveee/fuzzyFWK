#ifndef SUGENOCONCLUSION_H_INCLUDED
#define SUGENOCONCLUSION_H_INCLUDED

#include "../core/NaryExpression.h"
#include <vector>

namespace fuzzy{
    template <class T>
    class SugenoConclusion{
        public:
            SugenoConclusion(const vector<T>&);
            virtual T evaluate(Expression<T>*[]) const;
        private:
            vector<T> coeff;
    };

    template <class T>
    SugenoConclusion<T>::SugenoConclusion(const vector<T>& _coeff):
        coeff(_coeff)
    {}

    template <class T>
    T SugenoConclusion<T>::evaluate(Expression<T>* operands[]) const{
        T z = 0;
        for(int i = 0; i < coeff.size()-1; i++){
            z += coeff.at(i) * operands[i]->evaluate();
        }
        z += coeff.at(coeff.size() - 1);
        return z;
    }
}




#endif // SUGENOCONCLUSION_H_INCLUDED
