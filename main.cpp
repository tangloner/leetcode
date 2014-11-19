/*********************************************************************
	* @file main.cpp
	* @author tangloner <tangloner@gmail.com>
	* @date Fir Nov 14 2015
	* @brief main file for testing leetcode questions
**********************************************************************/
#include "solution.h"
#include "minStack.h"

int main (void)
{
/*
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
*/
	Solution *sol = new Solution();
/*	vector<int> num;
	num.push_back(4);
	num.push_back(5);
	num.push_back(6);
	num.push_back(7);
	num.push_back(0);
	num.push_back(1);
	num.push_back(2);
	num.push_back(3);
	cout<<sol->findMinII(num)<<endl;
*/
//	int arr[] = {1,-2,-3,0,7,-8,-2};
//	int arr[] = {-1,-1};
//	int arr[] = {-2,0,-1};
//	int n = sizeof(arr)/sizeof(int);
//	cout<<sol->maxProduct(arr,n)<<endl;
//	string s = "the sky is blue";
//	sol->reverseWords(s);
//	cout<<s<<endl;
/*	vector<string> tokens;
	string s = "-1";
	tokens.push_back(s);
	s = "1";
	tokens.push_back(s);
	s = "*";
	tokens.push_back(s);
	s = "-1";
	tokens.push_back(s);
	s = "+";
	tokens.push_back(s);
	cout<<sol->evalRPN(tokens)<<endl;
*/
	vector<Point> points;
	Point tmp = Point(3,10);
	points.push_back(tmp);
	tmp = Point(0,2);
	points.push_back(tmp);
	tmp = Point(3,10);
	points.push_back(tmp);
	tmp = Point(0,2);
	points.push_back(tmp);
	cout<<sol->maxPoints(points)<<endl;
	return 0;
}
