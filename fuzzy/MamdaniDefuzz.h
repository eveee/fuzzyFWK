#ifndef MAMDANIDEFUZZ_H_INCLUDED
#define MAMDANIDEFUZZ_H_INCLUDED

#include "../core/BinaryExpression.h"
using namespace core;

namespace fuzzy{

    template <class T>
    class MamdaniDefuzz : public BinaryExpression<T>{
        private:

        public:
            MamdaniDefuzz();
            MamdaniDefuzz(const T&, const T&, constT&)
            T evaluate(Expression<T>*, Expression<T>*);
        protected:
            Shape buildShape(Expression<T>*, Expression<T>*);
            virtual float defuzz(Shape);
    };


    template <class T>
    T MamdaniDefuzz<T>::evaluate(Expression<T>* l, Expression<T>* r){
        return defuzz(buildShape(l, r);
    }

    //variable de sortie -> univers de discours
    /*
        système de type mamdani : à partir d'une forme obtenir une variable réelle (sous classes) + construire la forme à partir des aggrégations (commun à tous les opérateurs de défuzzification)


    */

}

#endif // MAMDANIDEFUZZ_H_INCLUDED
