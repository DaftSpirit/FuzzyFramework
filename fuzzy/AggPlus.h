#ifndef AGGPLUS_H
#define AGGPLUS_H

#include "Operators.h"
#include "../core/Expression.h"

namespace fuzzy {

	template <class T>
	class AggPlus : public Agg<T> {
	public:
		virtual T evaluate(core::Expression<T>*, core::Expression<T>*) const;
	};

	template <class T>
	T AggPlus<T>::evaluate(core::Expression<T>* left, core::Expression<T>* right) const
	{
		T l = left->evaluate();
		T r = right->evaluate();

		return l + r;
	}
}
#endif