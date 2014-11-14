#include "minStack.h"

int main (void)
{
	minStack *sol = new minStack();
	sol->push(2147483646);
	sol->push(2147483646);
	sol->push(2147483647);
	cout<<sol->top()<<endl;
	sol->pop();
	cout<<sol->getMin()<<endl;
	sol->pop();
	cout<<sol->getMin()<<endl;
	sol->pop();
	sol->push(2147483647);
	cout<<sol->top()<<endl;
	cout<<sol->getMin()<<endl;
	sol->push(-2147483648);
	cout<<sol->top()<<endl;
	cout<<sol->getMin()<<endl;
	sol->pop();
	cout<<sol->getMin()<<endl;
	return 0;
}
