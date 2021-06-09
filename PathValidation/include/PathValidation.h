#ifndef _PATHVALIDATION_H_
#define _PATHVALIDATION_H_

#include <string>

#include "z3++.h"

using namespace z3;
using namespace std;

class ConstraintVar {
private:
	expr *e;
	int bit_width;
public:
	expr *getExpr();
	ConstraintVar(int val, int bit_width, context &ctx);
	ConstraintVar(string &name, int bit_width, context &ctx);
};

class PathValidation {
private:
	context ctx;
	solver s;
public:
	void addAdd(ConstraintVar ret, 
							ConstraintVar var1, ConstraintVar var2);
	void addFAdd(ConstraintVar ret, 
							ConstraintVar var1, ConstraintVar var2);
	void addSub(ConstraintVar ret, 
							ConstraintVar var1, ConstraintVar var2);
	void addFSub(ConstraintVar ret, 
							ConstraintVar var1, ConstraintVar var2);
	void addMul(ConstraintVar ret, 
							ConstraintVar var1, ConstraintVar var2);
	void addFMul(ConstraintVar ret, 
							ConstraintVar var1, ConstraintVar var2);
	void addUDiv(ConstraintVar ret, 
							ConstraintVar var1, ConstraintVar var2);
	void addSDiv(ConstraintVar ret, 
							ConstraintVar var1, ConstraintVar var2);
	void addFDiv(ConstraintVar ret, 
							ConstraintVar var1, ConstraintVar var2);
	void addURem(ConstraintVar ret, 
							ConstraintVar var1, ConstraintVar var2);
	void addSRem(ConstraintVar ret, 
							ConstraintVar var1, ConstraintVar var2);
	void addFRem(ConstraintVar ret, 
							ConstraintVar var1, ConstraintVar var2);
	void addShl(ConstraintVar ret, 
							ConstraintVar var1, ConstraintVar var2);
	void addLShr(ConstraintVar ret, 
							ConstraintVar var1, ConstraintVar var2);
	void addAShr(ConstraintVar ret, 
							ConstraintVar var1, ConstraintVar var2);
	void addAnd(ConstraintVar ret, 
							ConstraintVar var1, ConstraintVar var2);
	void addOr(ConstraintVar ret, 
							ConstraintVar var1, ConstraintVar var2);
	void addXor(ConstraintVar ret, 
							ConstraintVar var1, ConstraintVar var2);
	void addTrunc(ConstraintVar ret, 
							ConstraintVar var1, ConstraintVar var2);
	void addZExt(ConstraintVar ret, 
							ConstraintVar var1, ConstraintVar var2);
	void addIntToPtr(ConstraintVar ret, 
							ConstraintVar var1, ConstraintVar var2);
	void addBitCast(ConstraintVar ret, 
							ConstraintVar var1, ConstraintVar var2);
	void addICmpEQ(ConstraintVar ret, 
							ConstraintVar var1, ConstraintVar var2);
	void addICmpNE(ConstraintVar ret, 
							ConstraintVar var1, ConstraintVar var2);
	void addICmpGT(ConstraintVar ret, 
							ConstraintVar var1, ConstraintVar var2);
	void addICmpGE(ConstraintVar ret, 
							ConstraintVar var1, ConstraintVar var2);
	void addICmpLT(ConstraintVar ret, 
							ConstraintVar var1, ConstraintVar var2);
	void addICmpLE(ConstraintVar ret, 
							ConstraintVar var1, ConstraintVar var2);
	void addFCmpEQ(ConstraintVar ret, 
							ConstraintVar var1, ConstraintVar var2);
	void addFCmpNE(ConstraintVar ret, 
							ConstraintVar var1, ConstraintVar var2);
	void addFCmpGT(ConstraintVar ret, 
							ConstraintVar var1, ConstraintVar var2);
	void addFCmpGE(ConstraintVar ret, 
							ConstraintVar var1, ConstraintVar var2);
	void addFCmpLT(ConstraintVar ret, 
							ConstraintVar var1, ConstraintVar var2);
	void addFCmpLE(ConstraintVar ret, 
							ConstraintVar var1, ConstraintVar var2);
	void addSelect(); // TODO

};

#endif
