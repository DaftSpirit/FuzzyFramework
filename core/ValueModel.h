#ifndef VALUE_MODEL_H
#define VALUE_MODEL_H

#include "Expression.h"

namespace core {

	template <class T>
	class ValueModel : public Expression<T> {
		private:
			T value;
		public:
			ValueModel();
			ValueModel(const T&);
			virtual ~ValueModel();
			virtual T evaluate() const;
			virtual void setValue(T);
	};

	template <class T>
	ValueModel<T>::ValueModel() :
	value()
	{}

	template <class T>
	ValueModel<T>::~ValueModel()
	{}

	template <class T>
	ValueModel<T>::ValueModel(const T& v) :
	value(v)
	{}

	template <class T>
	T ValueModel<T>::evaluate() const {
		return value;
	}

	template <class T>
	void ValueModel<T>::setValue(T v) {
		value = v;
	}
}
#endif