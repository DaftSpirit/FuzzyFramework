#ifndef EXPRESSION_H
#define EXPRESSION_H

namespace core {
	template <class T>
	class Expression {
		public:
			virtual T evaluate() const = 0;
	};
}
#endif