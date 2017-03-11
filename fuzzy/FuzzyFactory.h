#ifndef FUZZY_FACTORY_H
#define FUZZY_FACTORY_H

#include "../core/ExpressionFactory.h"
#include "../core/Expression.h"
#include "../core/BinaryExpression.h"
#include "../core/BinaryExpressionModel.h"
#include "../core/UnaryExpression.h"
#include "../core/BinaryShadowExpression.h"
#include "../core/UnaryShadowExpression.h"
#include "Operators.h"

namespace fuzzy 
{
	template <class T>
	class FuzzyFactory : public core::ExpressionFactory<T> {

	private:
		core::BinaryShadowExpression<T> and, or, then, agg, defuzz;
		core::UnaryShadowExpression<T> not; 

	public:
		FuzzyFactory(And<T>*, Or<T>*, Then<T>*, Agg<T>*, Defuzz<T>*, Not<T>*);
		~FuzzyFactory() {};

		core::Expression<T>* newAnd(core::Expression<T>*, core::Expression<T>*);
		core::Expression<T>* newOr(core::Expression<T>*, core::Expression<T>*);
		core::Expression<T>* newThen(core::Expression<T>*, core::Expression<T>*);
		core::Expression<T>* newAgg(core::Expression<T>*, core::Expression<T>*);
		core::Expression<T>* newDefuzz(core::Expression<T>*, core::Expression<T>*);

		core::Expression<T>* newNot(core::Expression<T>*);
		core::Expression<T>* newIs(core::Expression<T>*, Is<T>*);


		void changeAnd(And<T>*);
		void changeOr(Or<T>*);
		void changeThen(Then<T>*);
		void changeAgg(Agg<T>*);
		void changeDefuzz(Defuzz<T>*);

		void changeNot(Not<T>*);
	};

	template <class T>
	FuzzyFactory<T>::FuzzyFactory(And<T>* _and, Or<T>* _or, Then<T>* _then, Agg<T>* _agg, Defuzz<T>* _defuzz, Not<T>* _not) :
		and(_and), or(_or), then(_then), agg(_agg), defuzz(_defuzz), not(_not)
	{}

	template <class T>
	core::Expression<T>* FuzzyFactory<T>::newAnd(core::Expression<T>* left, core::Expression<T>* right)
	{
		return newBinary(&and, left, right);
	}

	template <class T>
	core::Expression<T>* FuzzyFactory<T>::newOr(core::Expression<T>* left, core::Expression<T>* right)
	{
		return newBinary(&or, left, right);
	}

	template <class T>
	core::Expression<T>* FuzzyFactory<T>::newThen(core::Expression<T>* left, core::Expression<T>* right)
	{
		return newBinary(&then, left, right);
	}

	template <class T>
	core::Expression<T>* FuzzyFactory<T>::newAgg(core::Expression<T>* left, core::Expression<T>* right)
	{
		return newBinary(&agg, left, right);
	}

	template <class T>
	core::Expression<T>* FuzzyFactory<T>::newDefuzz(core::Expression<T>* left, core::Expression<T>* right)
	{
		return newBinary(&defuzz, left, right);
	}

	template <class T>
	core::Expression<T>* FuzzyFactory<T>::newNot(core::Expression<T>* o)
	{
		return newUnary(&not, o);
	}

	template <class T>
	core::Expression<T>* FuzzyFactory<T>::newIs(core::Expression<T>* o, Is<T>* s)
	{
		return newUnary(s, o);
	}


	template <class T>
	void FuzzyFactory<T>::changeAnd(And<T>* _and)
	{
		and.setTarget(_and);
	}

	template <class T>
	void FuzzyFactory<T>::changeOr(Or<T>* _or)
	{
		or.setTarget(_or);
	}

	template <class T>
	void FuzzyFactory<T>::changeThen(Then<T>* _then)
	{
		then.setTarget(_then);
	}

	template <class T>
	void FuzzyFactory<T>::changeAgg(Agg<T>* _agg)
	{
		agg.setTarget(_agg);
	}

	template <class T>
	void FuzzyFactory<T>::changeDefuzz(Defuzz<T>* _defuzz)
	{
		defuzz.setTarget(_defuzz);
	}

	template <class T>
	void FuzzyFactory<T>::changeNot(Not<T>* _not)
	{
		not.setTarget(_not);
	}
}
#endif