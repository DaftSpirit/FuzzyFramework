#ifndef ISTRAPEZERIGHT_H
#define ISTRAPEZERIGHT_H

#include "Operators.h"
#include "../core/Expression.h"

namespace fuzzy {
	template <class T>
	class IsTrapezeRight : public Is<T> {
		private :
			T min;
			T mid;
			T max;
		public :
			IsTrapezeRight(T&, T&, T&);
			virtual T evaluate(core::Expression<T>*) const;
	};

	template <class T>
	IsTrapezeRight<T>::IsTrapezeRight(T& _min, T& _mid, T& _max) :
		min(_min), mid(_mid), max(_max)
	{}

	template <class T>
	T IsTrapezeRight<T>::evaluate(core::Expression<T>* e) const
	{
		T o = e->evaluate();
		if (o <= min || o >= max)
			return 0;
		return (o >= mid) ? 1 : ((o - min) / (mid - min));
	}
}

#endif