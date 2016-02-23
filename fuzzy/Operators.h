#ifndef OPERATORS_H
#define OPERATORS_H

namespace fuzzy {

	template <class T>
	class Not : public core::UnaryExpression<T> {};

	template <class T>
	class Is : public core::UnaryExpression<T> {};

	template <class T>
	class And : public core::BinaryExpression<T> {};

	template <class T>
	class Or : public core::BinaryExpression<T> {};

	template <class T>
	class Then : public core::BinaryExpression<T> {};

	template <class T>
	class Agg : public core::BinaryExpression<T> {};

	/*template <class T>
	class MamdaniDefuzz : public core::BinaryExpression<T> {

		MamdaniDefuzz() {
			...
		}

		Mamdanidefuzz(const T&, const T&, constT&) {
			...
		}

	};

	template <class T>
	class SugenoDefuzz : public core::NaryExpression<T> {};

	template <class T>
	class SugenoConclusion : public core::NaryExpression<T> {};*/

 }

 #endif
