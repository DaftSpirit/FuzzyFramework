#ifndef NULL_EXPRESSION_EXCEPTION_H
#define NULL_EXPRESSION_EXCEPTION_H

#include <iostream>
#include <string>
#include <stdexcept>



namespace core {

	class NullExpressionException : public std::invalid_argument {
		public :
			NullExpressionException(std::string);
			virtual std::string getMessage() const;
		private :
			std::string mes;
	};

}
#endif