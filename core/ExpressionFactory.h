#ifndef EXPRESSIONFACTORY_H_INCLUDED
#define EXPRESSIONFACTORY_H_INCLUDED

#include "Expression.h"
#include "UnaryExpression.h"
#include "BinaryExpression.h"
#include <set>

using namespace std;

namespace core {

	template <class T>
	class ExpressionFactory {

		public :

			ExpressionFactory();
			~ExpressionFactory(){
			    typename std::set<Expression<T>* >::iterator it;
                for(it = memory.begin(); it!=memory.end(); it++){
                    delete *it;
                }
			}
			ExpressionFactory(set<Expression<T>* >);
			Expression<T>* Hold(Expression<T>*);
			Expression<T>* Value(T*);
			Expression<T>* newUnary(UnaryExpression<T>*, Expression<T>*);
			Expression<T>* newBinary(BinaryExpression<T>*, Expression<T>*, Expression<T>*);

		private :

			set<Expression<T>* > memory;

	};

	template <class T>
	ExpressionFactory<T>::ExpressionFactory()
	{

	}

	template <class T>
	ExpressionFactory<T>::ExpressionFactory(set<Expression<T>* > _memory) :
		memory(_memory)
	{}

	template <class T>
	Expression<T>* ExpressionFactory<T>::Hold(Expression<T>* ope)
	{
		memory.insert(ope);
	}

	template <class T>
	Expression<T>* ExpressionFactory<T>::Value(T* v)
	{
		return new ValueModel<T>(v);
	}

	template <class T>
	Expression<T>* ExpressionFactory<T>::newUnary(UnaryExpression<T>* ope, Expression<T>* o)
	{
		return new UnaryExpression<T>(ope, o);
	}

	template <class T>
	Expression<T>* ExpressionFactory<T>::newBinary(BinaryExpression<T>* ope, Expression<T>* l, Expression<T>* r)
	{
		return new BinaryExpression<T>(ope, l, r);
	}

}

#endif
