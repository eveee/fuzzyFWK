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
        typename std::vector<Expression<T>*>::iterator itop = operands->begin();
        typename std::vector<T>::iterator it = coeff->begin();
        for(; it != coeff->end() && itop != operands->end(); it++, itop++){
            z += (*it) * (*itop)->evaluate();
        }
        return z;
    }
}




#endif // SUGENOCONCLUSION_H_INCLUDED
