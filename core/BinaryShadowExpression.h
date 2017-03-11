#ifndef BINARY_SHADOW_EXPRESSION_H
#define BINARY_SHADOW_EXPRESSION_H

#include "BinaryExpression.h"
#include "NullExpressionException.h"

namespace core {

	template <class T>
	class BinaryShadowExpression : public BinaryExpression<T> {
		private :
			BinaryExpression<T>* target;
		public :
			BinaryShadowExpression(BinaryExpression<T>*);
			virtual ~BinaryShadowExpression();

			virtual T evaluate(Expression<T>*, Expression<T>*) const;
			virtual void setTarget(BinaryExpression<T>*);
	};

	template <class T>
	BinaryShadowExpression<T>::BinaryShadowExpression(BinaryExpression<T>* _target) : 
		target(_target)
	{}

	template <class T>
	BinaryShadowExpression<T>::~BinaryShadowExpression()
	{
		//delete  target;
	}

	template <class T>
	T BinaryShadowExpression<T>::evaluate(Expression<T>* l, Expression<T>* r) const
	{
		if (target != nullptr)
		{
			return target->evaluate(l, r);
		}
		else
		{
			throw core::NullExpressionException("Operand is missing !");
		}
	}

	template <class T>
	void BinaryShadowExpression<T>::setTarget(BinaryExpression<T>* _target)
	{
		target = _target;
	}
}
#endif