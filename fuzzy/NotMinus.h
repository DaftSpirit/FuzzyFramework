#ifndef NOT_MINUS_H
#define NOT_MINUS_H

#include "Operators.h"
#include "../core/Expression.h"

namespace fuzzy {
	
	template <class T>
	class NotMinus : public Not<T> {
		public : 
			virtual T evaluate(core::Expression<T>*)const;
	};

	template <class T>
	T NotMinus<T>::evaluate(core::Expression<T>* operand)const
	{
		T op = operand->evaluate();

		return 1 - op;
	}
}

#endif