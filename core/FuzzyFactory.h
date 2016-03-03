#ifndef CORE_FUZZYFACTORY_H_
#define CORE_FUZZYFACTORY_H_

#include "ExpressionFactory.h"
#include "../fuzzy/Operators.h"
#include "../fuzzy/MamdaniDefuzz.h"


namespace core {

	template <class T>
	class FuzzyFactory : public ExpressionFactory<T> {

		public :

		    FuzzyFactory(fuzzy::Not<T>*, fuzzy::And<T>*, fuzzy::Or<T>*, fuzzy::Then<T>*, fuzzy::Agg<T>*, fuzzy::MamdaniDefuzz<T>*);

			Expression<T>* newNot(Expression<T>*) const;
			Expression<T>* newIs(fuzzy::Is<T>*, Expression<T>*) const;
			Expression<T>* newAnd(Expression<T>*, Expression<T>*) const;
			Expression<T>* newOr(Expression<T>*, Expression<T>*) const;
			Expression<T>* newThen(Expression<T>*, Expression<T>*) const;
			Expression<T>* newAgg(Expression<T>*, Expression<T>*) const;
			Expression<T>* newDefuzz(Expression<T>*, Expression<T>*, const T& min, const T& max, const T& step) const;

			void changeNot(fuzzy::Not<T>*);
			void changeAnd(fuzzy::And<T>*);
			void changeOr(fuzzy::Or<T>*);
			void changeThen(fuzzy::Then<T>*);
			void changeAgg(fuzzy::Agg<T>*);
			void changeDefuzz(fuzzy::MamdaniDefuzz<T>*);

		private :

			UnaryShadowExpression<T>* _not;
			BinaryShadowExpression<T>* _and;
			BinaryShadowExpression<T>* _or;
			BinaryShadowExpression<T>* _then;
			BinaryShadowExpression<T>* _agg;
			BinaryShadowExpression<T>* _defuzz;

	};

	template <class T>
	FuzzyFactory<T>::FuzzyFactory(fuzzy::Not<T>* __not,
                               fuzzy::And<T>* __and,
                               fuzzy::Or<T>* __or,
                               fuzzy::Then<T>* __then,
                               fuzzy::Agg<T>* __agg,
                               fuzzy::MamdaniDefuzz<T>* __defuzz):
	    _not(new UnaryShadowExpression<T>(__not)),
	    _and(new BinaryShadowExpression<T>(__and)),
	    _or(new BinaryShadowExpression<T>(__or)),
	    _then(new BinaryShadowExpression<T>(__then)),
	    _agg(new BinaryShadowExpression<T>(__agg)),
	    _defuzz(new BinaryShadowExpression<T>(__defuzz))
    {
    }

	template <class T>
	Expression<T>* FuzzyFactory<T>::newNot(Expression<T>* o) const
	{
		return ExpressionFactory<T>::newUnary(_not, o);
	}

	template <class T>
	Expression<T>* FuzzyFactory<T>::newIs(fuzzy::Is<T>* _is, Expression<T>* o) const
	{
		return ExpressionFactory<T>::newUnary(_is, o);
	}

	template <class T>
	Expression<T>* FuzzyFactory<T>::newAnd(Expression<T>* l, Expression<T>* r) const
	{
		return ExpressionFactory<T>::newBinary(_and, l, r);
	}

	template <class T>
	Expression<T>* FuzzyFactory<T>::newOr(Expression<T>* l, Expression<T>* r) const
	{
		return ExpressionFactory<T>::newBinary(_or, l, r);
	}

	template <class T>
	Expression<T>* FuzzyFactory<T>::newThen(Expression<T>* l, Expression<T>* r) const
	{
		return ExpressionFactory<T>::newBinary(_then, l, r);
	}

	template <class T>
	Expression<T>* FuzzyFactory<T>::newAgg(Expression<T>* l, Expression<T>* r) const
	{
		return ExpressionFactory<T>::newBinary(_agg, l, r);
	}

	template <class T>
	Expression<T>* FuzzyFactory<T>::newDefuzz(Expression<T>* l, Expression<T>* r, const T& min, const T& max, const T& step) const
	{
        fuzzy::MamdaniDefuzz<T>* target = (fuzzy::MamdaniDefuzz<T>*) _defuzz->getTarget();
		target->setMin(min);
		target->setMax(max);
		target->setStep(step);

		return ExpressionFactory<T>::newBinary(_defuzz, l, r);
	}

	template <class T>
	void FuzzyFactory<T>::changeNot(fuzzy::Not<T>* __not)
	{
		_not->setTarget(__not);
	}

	template <class T>
	void FuzzyFactory<T>::changeAnd(fuzzy::And<T>* __and)
	{
		_and->setTarget(__and);
	}

	template <class T>
	void FuzzyFactory<T>::changeOr(fuzzy::Or<T>* __or)
	{
		_or->setTarget(__or);
	}

	template <class T>
	void FuzzyFactory<T>::changeThen(fuzzy::Then<T>* __then)
	{
		_then->setTarget(__then);
	}

	template <class T>
	void FuzzyFactory<T>::changeAgg(fuzzy::Agg<T>* __agg)
	{
		_agg->setTarget(__agg);
	}

	template <class T>
	void FuzzyFactory<T>::changeDefuzz(fuzzy::MamdaniDefuzz<T>* __defuzz)
	{
		_defuzz->setTarget(__defuzz);
	}

}

#endif
