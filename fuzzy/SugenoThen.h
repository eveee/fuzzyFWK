#ifndef SUGENOTHEN_H_INCLUDED
#define SUGENOTHEN_H_INCLUDED

#include "Operators.h"

using namespace core;

namespace fuzzy{

    template <class T>
    class SugenoThen : public Then<T>{
        public :
            SugenoThen();
            virtual T evaluate(Expression<T>*, Expression<T>*) const;
            T getPremiseValue() const;
        private :
            mutable T premiseValue;
    };

    template <class T>
    SugenoThen<T>::SugenoThen():
        premiseValue(0)
    {
    }

    template <class T>
    T SugenoThen<T>::evaluate(Expression<T>* l, Expression<T>* r) const{
        premiseValue = l->evaluate();
        return (premiseValue * r->evaluate());
    }

    template <class T>
    T SugenoThen<T>::getPremiseValue() const{
        return premiseValue;
    }

}


#endif // SUGENOTHEN_H_INCLUDED
