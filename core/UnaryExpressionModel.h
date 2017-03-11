#ifndef UNARY_EXPRESSION_MODEL_H
#define UNARY_EXPRESSION_MODEL_H

#include "UnaryExpression.h"
#include "Expression.h"
#include "NullExpressionException.h"

namespace core {

	template <class T>
	class UnaryExpressionModel : public UnaryExpression<T>, public Expression<T> {
	public:

		UnaryExpressionModel();
		UnaryExpressionModel(Expression<T>*, UnaryExpression<T>*);
		virtual ~UnaryExpressionModel(){};

		virtual T evaluate(Expression<T> *)const;
		virtual T evaluate()const;
	private:
		Expression<T>* operand;
		UnaryExpression<T>* op;
	};

	template <class T>
	UnaryExpressionModel<T>::UnaryExpressionModel() :
	op(), operand()
	{}

	template <class T>
	UnaryExpressionModel<T>::UnaryExpressionModel(Expression<T>* _operand, UnaryExpression<T>* _op) :
		op(_op), operand(_operand)
	{}

	template <class T>
	T UnaryExpressionModel<T>::evaluate()const {
		if (operand != nullptr)
		{
			return evaluate(operand);
		}
		else
		{
			throw core::NullExpressionException("Operand is missing !");
		}
	}

	template <class T>
	T UnaryExpressionModel<T>::evaluate(Expression<T>* exp)const
	{
		if (op != nullptr)
		{
			return op->evaluate(exp);
		}
		else
		{
			throw core::NullExpressionException("Operator is missing !");
		}
	}

}

#endif