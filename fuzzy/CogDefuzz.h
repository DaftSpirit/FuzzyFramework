#ifndef COGDEFUZZ_H
#define COGDEFUZZ_H

#include "MandaniDefuzz.h"
#include "../core/Evaluator.h"
#include "../core/Expression.h"

namespace fuzzy {

	template <class T>
	class CogDefuzz : public MandaniDefuzz<T> {
		public : 
			virtual T defuzz(typename core::Evaluator<T>::shape&)const;

			CogDefuzz(const T&, const T&, const T&);
	};

	template <class T>
	CogDefuzz<T>::CogDefuzz(const T& _min, const T& _max, const T& _step) :
		MandaniDefuzz(_min, _max, _step)
	{}

	template <class T>
	T CogDefuzz<T>::defuzz(typename core::Evaluator<T>::shape& s) const
	{
		T den = 0;
		T num = 0;
		T x, y;
		core::Evaluator<T>::printShape(s, std::cout);
		for (unsigned int i = 0; i < s.first.size() - 1; i++)
		{
			x = s.first.at(i);
			y = s.second.at(i);
			/* FOR DEBUG USE ONLY
			std::cout << x << " , " << y << std::endl;*/
			den += y;
			num += (x * y);
		}
		/* FOR DEBUG USE ONLY
		std::cout << "num = " << num << ", den  = " << den << std::endl;*/
		return (num / den);
	}
}

#endif