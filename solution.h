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

class Solution
{
public:
	//Find Minimum in Rotated Sorted Array 
	int findMin(vector<int> &num);

	//Find Minimum in Rotated Sorted Array II 
	int findMinII(vector<int> &num);

	//Maximum Product Subarray
	int maxProduct(int A[], int n);
};
#endif
