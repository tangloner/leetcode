#include "minStack.h"

void minStack::push(int x)
{
	st.push_back(x);
	if(mi.empty()||x<=mi.back())
		mi.push_back(x);
//	cout<<"push: "<<st.size()<<endl;
}

void minStack::pop()
{
	if(st.back()==mi.back())
		mi.pop_back();
	st.pop_back();
//	cout<<"pop: "<<st.size()<<endl;
}

int minStack::top()
{
	int ret;
	if(st.empty())
		ret = -1;
	ret = st.back();
	return ret;
}

int minStack::getMin()
{
	int ret;
	if(mi.empty())
		ret = -1;
	ret = mi.back();
	return ret;
}
