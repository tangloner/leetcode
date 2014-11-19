/*********************************************************************
	* @file solution.h
	* @author tangloner <tangloner@gmail.com>
	* @date Fir Nov 14 2015
	* @brief solution header file for leetcode questions which only 
	need implement signal function
**********************************************************************/
#include "header.h"


#ifndef SOLUTION_H
#define SOLUTION_H
struct Point
{
	int x;
	int y;
	Point(): x(0),y(0) {}
	Point(int a, int b) : x(a), y(b){}
};

class Solution
{
public:
	//Find Minimum in Rotated Sorted Array 
	int findMin(vector<int> &num);

	//Find Minimum in Rotated Sorted Array II 
	int findMinII(vector<int> &num);

	//Maximum Product Subarray
	int maxProduct(int A[], int n);
	
	//Reverse Words in a string
	void reverseWords(string &s);

	//Evaluate Reverse Polish Notation
	int evalRPN(vector<string> &tokens);

	//Max Points on a line
	int maxPoints(vector<Point> &points);
};
#endif
