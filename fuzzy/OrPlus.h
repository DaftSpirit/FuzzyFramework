#ifndef OR_PLUS_H
#define OR_PLUS_H

#include "Operators.h"
#include "../core/Expression.h"

namespace fuzzy {
	template <class T>
	class OrPlus : public Or<T> {
	public:
		virtual T evaluate(core::Expression<T>*, core::Expression<T>*) const;
	};

	template <class T>
	T OrPlus<T>::evaluate(core::Expression<T>* left, core::Expression<T>* right) const
	{
		T l = left->evaluate();
		T r = right->evaluate();

		return l + r;
	}

}
#endif