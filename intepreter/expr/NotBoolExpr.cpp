#include "NotBoolExpr.h"

NotBoolExpr::NotBoolExpr(int line, BoolExpr* expr)
	: BoolExpr(line), _expr(expr) {
}

NotBoolExpr::~NotBoolExpr() {
	delete _expr;
}

bool NotBoolExpr::expr() {
	return !(_expr->expr());
}