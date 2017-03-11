#include "stdafx.h"
#include "core/NullExpressionException.h"

namespace core {
	NullExpressionException::NullExpressionException(std::string s) :
		invalid_argument(s), mes(s)
	{
	}

	std::string NullExpressionException::getMessage()const
	{
		return mes;
	}
}