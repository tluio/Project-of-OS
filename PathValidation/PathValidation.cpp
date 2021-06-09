#include "include/PathValidation.h"

ConstraintVar::ConstraintVar(int val, 
							int bit_width, context &ctx) {
	this->bit_width = bit_width;
	e = new expr(ctx);
	*e = ctx.bv_val(val, bit_width);
}

ConstraintVar::ConstraintVar(string &name, 
							int bit_width, context &ctx) {
	this->bit_width = bit_width;
	e = new expr(ctx);
	*e = ctx.bv_const(name.c_str(), bit_width);
}

expr *ConstraintVar::getExpr() {
	return e;
}

void PathValidation::addAdd(ConstraintVar ret,
					ConstraintVar var1, ConstraintVar var2) {
	expr *ret_expr = ret.getExpr();
	expr *expr1 = var1.getExpr();
	expr *expr2 = var2.getExpr();
	s.add(*ret_expr == *expr1 + *expr2);
}

void PathValidation::addFAdd(ConstraintVar ret, 
					ConstraintVar var1, ConstraintVar var2) {
// TODO: support for float
	addAdd(ret, var1, var2);
}

void PathValidation::addSub(ConstraintVar ret,
					ConstraintVar var1, ConstraintVar var2) {
	expr *ret_expr = ret.getExpr();
	expr *expr1 = var1.getExpr();
	expr *expr2 = var2.getExpr();
	s.add(*ret_expr == *expr1 - *expr2);
}

void PathValidation::addFSub(ConstraintVar ret, 
					ConstraintVar var1, ConstraintVar var2) {
// TODO: support for float
	addSub(ret, var1, var2);
}

void PathValidation::addMul(ConstraintVar ret,
					ConstraintVar var1, ConstraintVar var2) {
	expr *ret_expr = ret.getExpr();
	expr *expr1 = var1.getExpr();
	expr *expr2 = var2.getExpr();
	s.add(*ret_expr == *expr1 * *expr2);
}

void PathValidation::addFMul(ConstraintVar ret, 
					ConstraintVar var1, ConstraintVar var2) {
// TODO: support for float
	addMul(ret, var1, var2);
}

void PathValidation::addUDiv(ConstraintVar ret, 
					ConstraintVar var1, ConstraintVar var2) {
// TODO: split udiv and sdiv
	expr *ret_expr = ret.getExpr();
	expr *expr1 = var1.getExpr();
	expr *expr2 = var2.getExpr();
	s.add(*ret_expr == *expr1 / *expr2);
}

void PathValidation::addSDiv(ConstraintVar ret,
					ConstraintVar var1, ConstraintVar var2) {
// TODO: split udiv and sdiv
	addUDiv(ret, var1, var2);
}

void PathValidation::addFDiv(ConstraintVar ret,
					ConstraintVar var1, ConstraintVar var2) {
// TODO: support for float
	addUDiv(ret, var1, var2);
}

void PathValidation::addURem(ConstraintVar ret,
					ConstraintVar var1, ConstraintVar var2) {
	expr *ret_expr = ret.getExpr();
	expr *expr1 = var1.getExpr();
	expr *expr2 = var2.getExpr();
	s.add(*ret_expr == urem(*expr1, *expr2));
}

void PathValidation::addSRem(ConstraintVar ret,
					ConstraintVar var1, ConstraintVar var2) {
	expr *ret_expr = ret.getExpr();
	expr *expr1 = var1.getExpr();
	expr *expr2 = var2.getExpr();
	s.add(*ret_expr == srem(*expr1, *expr2));
}

void PathValidation::addFRem(ConstraintVar ret, 
					ConstraintVar var1, ConstraintVar var2) {
// TODO: support for float
	addSRem(ret, var1, var2);
}

void PathValidation::addShl(ConstraintVar ret, 
					ConstraintVar var1, ConstraintVar var2) {
	expr *ret_expr = ret.getExpr();
	expr *expr1 = var1.getExpr();
	expr *expr2 = var2.getExpr();
	s.add(*ret_expr == shl(*expr1, *expr2));
}

void PathValidation::addLShr(ConstraintVar ret,
					ConstraintVar var1, ConstraintVar var2) {
	expr *ret_expr = ret.getExpr();
	expr *expr1 = var1.getExpr();
	expr *expr2 = var2.getExpr();
	s.add(*ret_expr == lshr(*expr1, *expr2));
}

void PathValidation::addAShr(ConstraintVar ret,
					ConstraintVar var1, ConstraintVar var2) {
	expr *ret_expr = ret.getExpr();
	expr *expr1 = var1.getExpr();
	expr *expr2 = var2.getExpr();
	s.add(*ret_expr == ashr(*expr1, *expr2));
}

void PathValidation::addAnd(ConstraintVar ret,
					ConstraintVar var1, ConstraintVar var2) {
	expr *ret_expr = ret.getExpr();
	expr *expr1 = var1.getExpr();
	expr *expr2 = var2.getExpr();
	s.add(*ret_expr == (*expr1 & *expr2));
}

void PathValidation::addOr(ConstraintVar ret,
					ConstraintVar var1, ConstraintVar var2) {
	expr *ret_expr = ret.getExpr();
	expr *expr1 = var1.getExpr();
	expr *expr2 = var2.getExpr();
	s.add(*ret_expr == (*expr1 | *expr2));
}

void PathValidation::addXor(ConstraintVar ret,
					ConstraintVar var1, ConstraintVar var2) {
	expr *ret_expr = ret.getExpr();
	expr *expr1 = var1.getExpr();
	expr *expr2 = var2.getExpr();
	s.add(*ret_expr == (*expr1 ^ *expr2));
}

void PathValidation::addTrunc(ConstraintVar ret,
					ConstraintVar var1, ConstraintVar var2) {
// TODO: build constraint for trunc
}

void PathValidation::addZExt(ConstraintVar ret,
					ConstraintVar var1, ConstraintVar var2) {
// TODO: build constraint for zexit
}

void PathValidation::addIntToPtr(ConstraintVar ret,
					ConstraintVar var1, ConstraintVar var2) {
// TODO: build constraint for int2ptr
}

void PathValidation::addBitCast(ConstraintVar ret,
					ConstraintVar var1, ConstraintVar var2) {
// TODO: build constraint for bitcast
}

void PathValidation::addICmpEQ(ConstraintVar ret,
					ConstraintVar var1, ConstraintVar var2) {
	expr *ret_expr = ret.getExpr();
	expr *expr1 = var1.getExpr();
	expr *expr2 = var2.getExpr();
	s.add(z3::ite(*expr1 == *expr2, *ret_expr != 0, *ret_expr == 0));
}

void PathValidation::addICmpNE(ConstraintVar ret,
					ConstraintVar var1, ConstraintVar var2) {
	expr *ret_expr = ret.getExpr();
	expr *expr1 = var1.getExpr();
	expr *expr2 = var2.getExpr();
	s.add(z3::ite(*expr1 != *expr2, *ret_expr != 0, *ret_expr == 0));
}

void PathValidation::addICmpGT(ConstraintVar ret,
					ConstraintVar var1, ConstraintVar var2) {
	expr *ret_expr = ret.getExpr();
	expr *expr1 = var1.getExpr();
	expr *expr2 = var2.getExpr();
	s.add(z3::ite(*expr1 > *expr2, *ret_expr != 0, *ret_expr == 0));
}

void PathValidation::addICmpGE(ConstraintVar ret,
					ConstraintVar var1, ConstraintVar var2) {
	expr *ret_expr = ret.getExpr();
	expr *expr1 = var1.getExpr();
	expr *expr2 = var2.getExpr();
	s.add(z3::ite(*expr1 >= *expr2, *ret_expr != 0, *ret_expr == 0));
}

void PathValidation::addICmpLT(ConstraintVar ret,
					ConstraintVar var1, ConstraintVar var2) {
	expr *ret_expr = ret.getExpr();
	expr *expr1 = var1.getExpr();
	expr *expr2 = var2.getExpr();
	s.add(z3::ite(*expr1 < *expr2, *ret_expr != 0, *ret_expr == 0));
}

void PathValidation::addICmpLE(ConstraintVar ret,
					ConstraintVar var1, ConstraintVar var2) {
	expr *ret_expr = ret.getExpr();
	expr *expr1 = var1.getExpr();
	expr *expr2 = var2.getExpr();
	s.add(z3::ite(*expr1 <= *expr2, *ret_expr != 0, *ret_expr == 0));
}

void PathValidation::addFCmpEQ(ConstraintVar ret,
					ConstraintVar var1, ConstraintVar var2) {
// TODO: support for float
	addICmpEQ(ret, var1, var2);
}

void PathValidation::addFCmpNE(ConstraintVar ret,
					ConstraintVar var1, ConstraintVar var2) {
// TODO: support for float
	addICmpNE(ret, var1, var2);
}

void PathValidation::addFCmpGT(ConstraintVar ret,
					ConstraintVar var1, ConstraintVar var2) {
// TODO: support for float
	addICmpGT(ret, var1, var2);
}

void PathValidation::addFCmpGE(ConstraintVar ret,
					ConstraintVar var1, ConstraintVar var2) {
// TODO: support for float
	addICmpGE(ret, var1, var2);
}

void PathValidation::addFCmpLT(ConstraintVar ret,
					ConstraintVar var1, ConstraintVar var2) {
// TODO: support for float
	addICmpLT(ret, var1, var2);
}

void PathValidation::addFCmpLE(ConstraintVar ret,
					ConstraintVar var1, ConstraintVar var2) {
// TODO: support for float
	addICmpLE(ret, var1, var2);
}

// TODO: support for select
void PathValidation::addSelect() {

}
