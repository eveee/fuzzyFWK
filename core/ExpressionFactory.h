#ifndef EXPRESSIONFACTORY_H_INCLUDED
#define EXPRESSIONFACTORY_H_INCLUDED

#include "Expression.h"
#include "UnaryExpressionModel.h"
#include "BinaryExpressionModel.h"
#include "NaryExpressionModel.h"
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
			Expression<T>* newUnary(UnaryExpression<T>*, Expression<T>*) const;
			Expression<T>* newBinary(BinaryExpression<T>*, Expression<T>*, Expression<T>*) const;
			Expression<T>* newNary(NaryExpression<T>*, vector<Expression<T>*>*) const;

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
		return ope;
	}

	template <class T>
	Expression<T>* ExpressionFactory<T>::newUnary(UnaryExpression<T>* ope, Expression<T>* o) const
	{
		return new UnaryExpressionModel<T>(ope, o);
	}

	template <class T>
	Expression<T>* ExpressionFactory<T>::newBinary(BinaryExpression<T>* ope, Expression<T>* l, Expression<T>* r) const
	{
		return new BinaryExpressionModel<T>(ope, l, r);
	}

	template <class T>
	Expression<T>* ExpressionFactory<T>::newNary(NaryExpression<T>* operator_, vector<Expression<T>*>* operands) const
	{
		return new NaryExpressionModel<T>(operator_, operands);
	}

}

#endif
