#ifndef AGGMAX_H
#define AGGMAX_H

#include "Operators.h"
#include "../core/Expression.h"

namespace fuzzy {

	template <class T>
	class AggMax : public Agg<T> {
	public:
		virtual T evaluate(core::Expression<T>*, core::Expression<T>*) const;
	};

	template <class T>
	T AggMax<T>::evaluate(core::Expression<T>* left, core::Expression<T>* right) const
	{
		T l = left->evaluate();
		T r = right->evaluate();

		return (l > r) ? l : r;
	}
}
#endif