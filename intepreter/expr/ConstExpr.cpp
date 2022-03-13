#include "ConstExpr.h"

ConstExpr::ConstExpr(int line, Type* value)
	: Expr(line), value(value) {
}

ConstExpr::~ConstExpr() {
}

Type* ConstExpr::expr() {
	return value;
}