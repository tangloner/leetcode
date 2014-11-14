/*======================================
	@ tangloner <tangloner@gmail.com>
	@ minStack.cpp
`	@ Qustion "Min Stack" in Leetcode
======================================*/

#include "header.h"

#ifndef MIN_STACK_H
#define MIN_STACK_H

class minStack
{
public:
	void push(int x);
	void pop();
	int top();
	int getMin();
private:
	deque<int> st;
	deque<int> mi;
};

#endif
