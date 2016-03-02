#ifndef MAMDANIDEFUZZ_H_INCLUDED
#define MAMDANIDEFUZZ_H_INCLUDED

#include "../core/BinaryExpression.h"
#include "../core/Evaluator.h"
using namespace core;

namespace fuzzy{

    template <class T>
    class MamdaniDefuzz : public BinaryExpression<T>{
        private:
            T min, max, step;
        public:
            MamdaniDefuzz();
            MamdaniDefuzz(const T&, const T&, const T&);
            virtual T evaluate(Expression<T>*, Expression<T>*) const;
            T getMin();
            void setMin(const T&);
            T getMax();
            void setMax(const T&);
            T getStep();
            void setStep(const T&);

        protected:
            typename Evaluator<T>::Shape buildShape(Expression<T>*, Expression<T>*) const;
            virtual T defuzz(typename Evaluator<T>::Shape) const = 0;
    };

    template <class T>
    MamdaniDefuzz<T>::MamdaniDefuzz():
        min(0), max(0), step(0)
    {}

    template <class T>
    MamdaniDefuzz<T>::MamdaniDefuzz(const T& _min, const T& _max, const T& _step):
        min(_min), max(_max), step(_step)
    {}

    template <class T>
    typename Evaluator<T>::Shape MamdaniDefuzz<T>::buildShape(Expression<T>* l, Expression<T>* r) const{
        return Evaluator<T>::BuildShape(min, max, step, (ValueModel<T>*) l, r);
    }

    template <class T>
    T MamdaniDefuzz<T>::evaluate(Expression<T>* l, Expression<T>* r) const{
        return defuzz(buildShape(l, r));
    }

    template <class T>
    T MamdaniDefuzz<T>::getMin(){
        return min;
    }

    template <class T>
    void MamdaniDefuzz<T>::setMin(const T& _min){
        min = _min;
    }

    template <class T>
    T MamdaniDefuzz<T>::getMax(){
        return max;
    }

    template <class T>
    void MamdaniDefuzz<T>::setMax(const T& _max){
        max = _max;
    }

    template <class T>
    T MamdaniDefuzz<T>::getStep(){
        return step;
    }

    template <class T>
    void MamdaniDefuzz<T>::setStep(const T& _step){
        step = _step;
    }

    //variable de sortie -> univers de discours
    /*
        système de type mamdani : à partir d'une forme obtenir une variable réelle (sous classes) + construire la forme à partir des aggrégations (commun à tous les opérateurs de défuzzification)


    */

}

#endif // MAMDANIDEFUZZ_H_INCLUDED
