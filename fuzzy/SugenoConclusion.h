#ifndef SUGENOCONCLUSION_H_INCLUDED
#define SUGENOCONCLUSION_H_INCLUDED

#include "../core/NaryExpression.h"

namespace fuzzy{
    template <class T>
    class SugenoConclusion : public NaryExpression<T>{
        public:
            SugenoConclusion(vector<T>*);
            virtual T evaluate(vector<Expression<T>*>*) const;
        private:
            vector<T>* coeff;
    };

    template <class T>
    SugenoConclusion<T>::SugenoConclusion(vector<T>* _coeff):
        coeff(_coeff)
    {}

    template <class T>
    T SugenoConclusion<T>::evaluate(vector<Expression<T>*>* operands) const{
        T z = 0;
        for(int i = 0; i < coeff->size()-1; i++){
            z += coeff->at(i) * operands->at(i)->evaluate();
        }
        z += coeff->at(coeff->size() - 1);
        return z;
    }
}




#endif // SUGENOCONCLUSION_H_INCLUDED
