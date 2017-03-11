#ifndef UNARY_SHADOW_EXPRESSION_H
#define UNARY_SHADOW_EXPRESSION_H

#include "UnaryExpression.h"
#include "NullExpressionException.h"

namespace core {

	template <class T>
	class UnaryShadowExpression : public UnaryExpression<T> {
	private:
		UnaryExpression<T>* target;
	public:
		UnaryShadowExpression(UnaryExpression<T>*);
		virtual ~UnaryShadowExpression();

		virtual T evaluate(Expression<T>*)const;
		virtual void setTarget(UnaryExpression<T>*);
	};

	template <class T>
	UnaryShadowExpression<T>::UnaryShadowExpression(UnaryExpression<T>* _target) :
		target(_target)
	{}

	template <class T>
	UnaryShadowExpression<T>::~UnaryShadowExpression()
	{
		//delete  target;
	}

	template <class T>
	T UnaryShadowExpression<T>::evaluate(Expression<T>* o) const
	{
		if (target != nullptr)
		{
			return target->evaluate(o);
		}
		else
		{
			// throw an exception
		}
	}

	template <class T>
	void UnaryShadowExpression<T>::setTarget(UnaryExpression<T>* _target)
	{
		target = _target;
	}
}
#endif