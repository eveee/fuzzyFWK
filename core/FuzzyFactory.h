#ifndef CORE_FUZZYFACTORY_H_
#define CORE_FUZZYFACTORY_H_

#include "ExpressionFactory.h"
#include "../fuzzy/Operators.h"


namespace core {

	template <class T>
	class FuzzyFactory : public ExpressionFactory<T> {

		public :

			Expression<T>* newNot(Expression<T>*) const;
			Expression<T>* newIs(fuzzy::Is<T>*, Expression<T>*) const;
			Expression<T>* newAnd(Expression<T>*, Expression<T>*) const;
			Expression<T>* newOr(Expression<T>*, Expression<T>*) const;
			Expression<T>* newThen(Expression<T>*, Expression<T>*) const;
			Expression<T>* newAgg(Expression<T>*, Expression<T>*) const;
			Expression<T>* newDefuzz(Expression<T>*, Expression<T>*) const;

			void changeNot(fuzzy::Not<T>*);
			void changeAnd(fuzzy::And<T>*);
			void changeOr(fuzzy::Or<T>*);
			void changeThen(fuzzy::Then<T>*);
			void changeAgg(fuzzy::Agg<T>*);
			void changeDefuzz(fuzzy::MamdaniDefuzz<T>*);

		private :

			UnaryShadowExpression<T> _not;
			BinaryShadowExpression<T> _and;
			BinaryShadowExpression<T> _or;
			BinaryShadowExpression<T> _then;
			BinaryShadowExpression<T> _agg;
			BinaryShadowExpression<T> _defuzz;

	};

	template <class T>
	Expression<T>* FuzzyFactory<T>::newNot(Expression<T>* o) const
	{
		return new UnaryExpressionModel<T>(_not, o);
	}

	template <class T>
	Expression<T>* FuzzyFactory<T>::newIs(fuzzy::Is<T>* is, Expression<T>* o) const
	{
		return new UnaryExpressionModel<T>(is, o);
	}

	template <class T>
	Expression<T>* FuzzyFactory<T>::newAnd(Expression<T>* l, Expression<T>* r) const
	{
		return new BinaryExpressionModel<T>(_and, l, r);
	}

	template <class T>
	Expression<T>* FuzzyFactory<T>::newOr(Expression<T>* l, Expression<T>* r) const
	{
		return new BinaryExpressionModel<T>(_or, l, r);
	}

	template <class T>
	Expression<T>* FuzzyFactory<T>::newThen(Expression<T>* l, Expression<T>* r) const
	{
		return new BinaryExpressionModel<T>(_then, l, r);
	}

	template <class T>
	Expression<T>* FuzzyFactory<T>::newAgg(Expression<T>* l, Expression<T>* r) const
	{
		return new BinaryExpressionModel<T>(_agg, l, r);
	}

	template <class T>
	Expression<T>* FuzzyFactory<T>::newDefuzz(Expression<T>* l, Expression<T>* r) const
	{
		return new BinaryExpressionModel<T>(_defuzz, l, r);
	}

	template <class T>
	void FuzzyFactory<T>::changeNot(fuzzy::Not<T>* __not)
	{
		_not.setTarget(__not);
	}

	template <class T>
	void FuzzyFactory<T>::changeAnd(fuzzy::And<T>* __and)
	{
		_and.setTarget(__and);
	}

	template <class T>
	void FuzzyFactory<T>::changeOr(fuzzy::Or<T>* __or)
	{
		_or.setTarget(__or);
	}

	template <class T>
	void FuzzyFactory<T>::changeThen(fuzzy::Then<T>* __then)
	{
		_then.setTarget(__then);
	}

	template <class T>
	void FuzzyFactory<T>::changeAgg(fuzzy::Agg<T>* __agg)
	{
		_agg.setTarget(__agg);
	}

	template <class T>
	void FuzzyFactory<T>::changeDefuzz(fuzzy::MamdaniDefuzz<T>* __defuzz)
	{
		_defuzz.setTarget(__defuzz);
	}

}

#endif
