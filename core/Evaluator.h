#ifndef EVALUATOR_H
#define EVALUATOR_H

#include <iostream>
#include <vector>
#include "ValueModel.h"
#include "Expression.h"

namespace core {
	template <class T>
	class Evaluator {
		public :
			typedef std::pair<std::vector<T>, std::vector<T> > shape;
			
			static shape buildShape(const T&, const T&, const T&, ValueModel<T>*, Expression<T>*);
			static std::ostream& printShape(const shape&, std::ostream&);
	};

	template <class T>
	typename Evaluator<T>::shape Evaluator<T>::buildShape(const T& min, const T& max, const T& step, ValueModel<T>* v, Expression<T>* e)
	{
		std::vector<T> x, y;

		T mem = v->evaluate();
		for (T i = min; i <= max; i += step)
		{
			v->setValue(i);
			x.push_back(i);
			y.push_back(e->evaluate());
		}
		v->setValue(mem);
		return shape(x, y);
	}

	template <class T>
	std::ostream& Evaluator<T>::printShape(const typename Evaluator<T>::shape& s, std::ostream& os)
	{
		os << "[ ";
		std::vector<T>::const_iterator it = s.first.begin();
		for (; it != s.first.end(); ++it)
		{
			os << *it << " ";
		}
		os << " ]" << std::endl;

		it = s.second.begin();
		os << std::endl << "[ ";
		for (; it != s.second.end(); ++it)
		{
			os << *it << " ";
		}
		os << " ]" << std::endl;
		return os;
	}
}
#endif