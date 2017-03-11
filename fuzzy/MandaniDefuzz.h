#ifndef MANDANIDEFUZZ_H
#define MANDANIDEFUZZ_H

#include "Operators.h"
#include "../core/Evaluator.h"
#include "../core/Expression.h"
#include "../core/ValueModel.h"

namespace fuzzy {
	template <class T>
	class MandaniDefuzz : public Defuzz<T> {
		public :
			MandaniDefuzz(const T&, const T&, const T&);

			virtual T defuzz(typename core::Evaluator<T>::shape&)const = 0;
			virtual T evaluate(core::Expression<T>*, core::Expression<T>*) const;
		private :
			T min;
			T max;
			T step;
	};

	template <class T>
	MandaniDefuzz<T>::MandaniDefuzz(const T& _min, const T& _max, const T& _step) :
		min(_min), max(_max), step(_step)
	{}

	template <class T>
	T MandaniDefuzz<T>::evaluate(core::Expression<T>* l, core::Expression<T>* var) const
	{
		return defuzz(core::Evaluator<T>::buildShape(min, max, step, (core::ValueModel<T>*)l, var));
	}

}
#endif