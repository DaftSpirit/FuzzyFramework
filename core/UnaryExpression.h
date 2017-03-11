#ifndef UNARY_EXPRESSION_H
#define UNARY_EXPRESSION_H

#include "Expression.h"

namespace core {
	template <class T>
	class UnaryExpression {
		public:
			virtual T evaluate(Expression<T> *) const = 0;
	};
}
#endif