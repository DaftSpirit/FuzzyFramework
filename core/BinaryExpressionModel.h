#ifndef BINARY_EXPRESSION_MODEL_H
#define BINARY_EXPRESSION_MODEL_H

#include "BinaryExpression.h"
#include "Expression.h"
#include "NullExpressionException.h"

namespace core {
	template <class T>
	class BinaryExpressionModel : public BinaryExpression<T>, public Expression<T> {
		private :
			BinaryExpression<T>* op;
			Expression<T>* left;
			Expression<T>* right;
		public :
			BinaryExpressionModel();
			BinaryExpressionModel(Expression<T>*, Expression<T>*, BinaryExpression<T>*);
			virtual T evaluate()const;
			virtual T evaluate( Expression<T>*, Expression<T>*) const;
	};

	template <class T>
	BinaryExpressionModel<T>::BinaryExpressionModel() :
	op(), left(), right()
	{}

	template <class T>
	BinaryExpressionModel<T>::BinaryExpressionModel(Expression<T>* l, Expression<T>* r, BinaryExpression<T>* _op) :
	op(_op), left(l), right(r)
	{}

	template <class T>
	T BinaryExpressionModel<T>::evaluate()const{
		if (left == nullptr)
		{
			throw core::NullExpressionException("Left operand is missing !");
		}
		if (right == nullptr)
		{
			throw core::NullExpressionException("Right operand is missing !");
		}
		return evaluate(left, right);
	}

	template <class T>
	T BinaryExpressionModel<T>::evaluate(Expression<T>* l, Expression<T>* r)const
	{
		if (op != nullptr)
		{
			return op->evaluate(l, r);
		}
		else
		{
			throw core::NullExpressionException("Operator is missing !");
		}
	}
}

#endif