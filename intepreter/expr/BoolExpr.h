#ifndef BOOL_EXPR_H
#define BOOL_EXPR_H

class BoolExpr {
	public:
    BoolExpr(int line) : line(line) {}
		virtual ~BoolExpr() {}

		int getLine() const { return line; }
		virtual bool expr() = 0;		

	private:
		int line;

};

#endif