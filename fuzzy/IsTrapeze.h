#ifndef ISTRAPEZE_H
#define ISTRAPEZE_H

#include "Operators.h"
#include "../core/Expression.h"

namespace fuzzy {
	template <class T>
	class IsTrapeze : public Is<T> {
		private :
			T min;
			T mid1;
			T mid2;
			T max;
		public :
			IsTrapeze(T, T, T, T);
			virtual T evaluate(core::Expression<T>*) const;
	};

	template <class T>
	IsTrapeze<T>::IsTrapeze(T _min, T _mid1, T _mid2, T _max) :
		min(_min), mid1(_mid1), mid2(_mid2), max(_max)
	{}

	template <class T>
	T IsTrapeze<T>::evaluate(core::Expression<T>* e)const
	{
		T o = e->evaluate();
		if (o <= min || o >= max)
			return 0;
		else if (o >= midmin && o <= midmax)
			return 1;
		return (o <= midmin) ? ((o - min) / (midmin - min)) : ((max - o) / (max - midmax));
	}
}

#endif