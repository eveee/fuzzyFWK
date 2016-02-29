#ifndef BINARYSHADOWEXPRESSION_H_INCLUDED
#define BINARYSHADOWEXPRESSION_H_INCLUDED

#include "BinaryExpression.h"
using namespace std;

namespace core{

    template <class T>
    class BinaryShadowExpression : public BinaryExpression<T>{
        private :
            BinaryExpression<T> target;

        public :
            BinaryShadowExpression(BinaryExpression<T>*);
            T evaluate(Expression<T>*, Expression<T>*);
    };

    template <class T>
    BinaryShadowExpression<T>::BinaryShadowExpression(BinaryExpression<T>* _target):
        target(_target){}

    template <class T>
    T BinaryShadowExpression<T>::evaluate(Expression<T>* left, Expression<T>* right){
        if(target != NULL)
            return target.evaluate(left, right);
		else
			throw string("Erreur d'op�rateur.");
    }

}
#endif // BINARYSHADOWEXPRESSION_H_INCLUDED
