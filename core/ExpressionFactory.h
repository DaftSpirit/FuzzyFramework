#ifndef EXPRESSION_FACTORY_H
#define EXPRESSION_FACTORY_H

#include "Expression.h"
#include "BinaryExpression.h"
#include "BinaryExpressionModel.h"
#include "UnaryExpression.h"
#include "UnaryExpressionModel.h"
#include <iostream>
#include <set>

namespace core {

	template <class T>
	class ExpressionFactory
	{
		private :
			std::set<Expression<T>*> memory;
		public :
			ExpressionFactory();
			virtual ~ExpressionFactory();
			virtual Expression<T>* hold(Expression<T>*);
			virtual Expression<T>* newUnary(UnaryExpression<T>*, Expression<T>*);
			virtual Expression<T>* newBinary(BinaryExpression<T>*, Expression<T>*, Expression<T>*);
	};

	template <class T>
	ExpressionFactory<T>::ExpressionFactory() :
	memory()
	{}

	template <class T>
	ExpressionFactory<T>::~ExpressionFactory()
	{
		std::set<Expression<T>*>::iterator it = memory.begin();
		for (; it != memory.end(); ++it)
		{
			//delete *it;
		}
	}

	template <class T>
	Expression<T>* ExpressionFactory<T>::hold(Expression<T>* exp){
		memory.insert(exp);
		return exp;
	}

	template <class T>
	Expression<T>* ExpressionFactory<T>::newUnary(UnaryExpression<T>* ope, Expression<T>* o)
	{
		return hold(new UnaryExpressionModel<T>(o, ope));
	}

	template <class T>
	Expression<T>* ExpressionFactory<T>::newBinary(BinaryExpression<T>* ope, Expression<T>* l, Expression<T>* r)
	{
		return hold(new BinaryExpressionModel<T>(l, r, ope));
	}
}

#endif