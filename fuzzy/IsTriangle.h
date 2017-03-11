#ifndef ISTRIANGLE_H
#define ISTRIANGLE_H

#include "Operators.h"
#include "../core/Expression.h"

namespace fuzzy {
	template <class T>
	class IsTriangle : public Is<T> {
		private :
			T min;
			T max;
			T mid;
		public :
			IsTriangle(T, T, T);
			virtual T evaluate(core::Expression<T>*) const;
	};

	template <class T>
	IsTriangle<T>::IsTriangle(T _min, T _mid, T _max) :
		min(_min), mid(_mid), max(_max)
	{}

	template <class T>
	T IsTriangle<T>::evaluate(core::Expression<T>* e) const
	{
		T o = e->evaluate();
		if (o <= min || o >= max)
			return 0;
		return (o <= mid) ? ((o - min) / (mid - min)) : ((max - o) / (max - mid));
	}
}

#endif