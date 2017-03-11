#include <iostream>
#include "core\Expression.h"
#include "core\ValueModel.h"
#include "core\BinaryExpression.h"
#include "core\BinaryExpressionModel.h"
#include "core\BinaryShadowExpression.h"
#include "core\UnaryExpression.h"
#include "core\UnaryExpressionModel.h"
#include "core\UnaryShadowExpression.h"
#include "core\ExpressionFactory.h"
#include "fuzzy\Operators.h"
#include "fuzzy\AggMax.h"
#include "fuzzy\AggPlus.h"
#include "fuzzy\AndProd.h"
#include "fuzzy\AndMin.h"
#include "fuzzy\OrMax.h"
#include "fuzzy\OrPlus.h"
#include "fuzzy\ThenMin.h"
#include "fuzzy\ThenProd.h"
#include "fuzzy\NotMinus.h"
#include "fuzzy\FuzzyFactory.h"
#include "fuzzy\IsTrapeze.h"
#include "fuzzy\IsTrapezeLeft.h"
#include "fuzzy\IsTrapezeRight.h"
#include "fuzzy\IsTriangle.h"
#include "fuzzy\MandaniDefuzz.h"
#include "fuzzy\CogDefuzz.h"
#include "core\NullExpressionException.h"

#define TYPE double


typedef fuzzy::NotMinus<TYPE> NotMinus;
typedef fuzzy::AndMin<TYPE> AndMin;
typedef fuzzy::OrMax<TYPE> OrMax;
typedef fuzzy::ThenMin<TYPE> ThenMin;
typedef fuzzy::CogDefuzz<TYPE> CogDefuzz;
typedef fuzzy::AggMax<TYPE> AggMax;

typedef fuzzy::FuzzyFactory<TYPE> Factory;

typedef fuzzy::IsTriangle<TYPE> IsTriangle;
typedef fuzzy::IsTrapezeLeft<TYPE> IsTrapezeLeft;

typedef core::ValueModel<TYPE> Value;

typedef core::Expression<TYPE> Expression;