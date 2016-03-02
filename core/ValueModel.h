#ifndef VALUEMODEL_H_INCLUDED
#define VALUEMODEL_H_INCLUDED

#include "Expression.h"

namespace core{

    template <class T>
    class ValueModel : public Expression<T>{
        private:
            T value;

        public:
			ValueModel();
            ValueModel(const T&);
			virtual ~ValueModel() {};
            virtual T evaluate() const;
            void setValue(const T&);
    };

    template <class T>
    ValueModel<T>::ValueModel():
        value(0) {} // value(T(0))

    template <class T>
    ValueModel<T>::ValueModel(const T& _value):
        value(_value) {}

    template <class T>
    T ValueModel<T>::evaluate() const{
        return value;
    }

    template <class T>
    void ValueModel<T>::setValue(const T& _value){
        value = _value;
    }

}
#endif // VALUEMODEL_H_INCLUDED
