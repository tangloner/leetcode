/*********************************************************************
	* @file solution.h
	* @author tangloner <tangloner@gmail.com>
	* @date Fir Nov 14 2015
	* @brief solution source file for leetcode questions which only 
	need implement signal function
**********************************************************************/
#include "solution.h"

//Find Minimum in Rotated Sorted Array 
int Solution::findMin(vector<int> &num)
{
	// O(log(n))
	int lo = 0, hi = num.size()-1;
	int mid;
	while(lo < hi)
	{
		mid = (lo+hi)/2;
		if(num[mid] > num[hi])
			lo = mid+1;
		else
			hi = mid;
	}
	return num[lo];
/*	// O(n)
	int i, ret=num[0];
	for(i=1; i<num.size(); i++)
	{
		ret = (ret<num[i])?ret:num[i];
	}
	return ret;
*/
}	

//Find Minimum in Rotated Sorted Array II 
int Solution::findMinII(vector<int> &num)
{
	int lo = 0, hi = num.size()-1;
	int mid;
	while(lo < hi && num[lo] >= num[hi])
	{
		mid = (lo+hi)/2;
		if(num[mid] > num[hi])
			lo = mid+1;
		else if(num[mid] < num[lo])
			hi = mid;
		else	
			lo++;
	}
	return num[lo];

}

//Maximum Product Subarray
int Solution::maxProduct(int A[], int n)
{
	int res = A[0], imax = res, imin = res;
	for(int i=1; i<n; i++)
	{
		if(A[i] < 0)
			swap(imax,imin);
		imax = max(A[i],imax*A[i]);
		imin = min(A[i],imin*A[i]);
		res = max(res, imax);
	}
	return res;
}
