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

//Reverse Words in a String
void Solution::reverseWords(string &s)
{
/*
	stringstream scin(s);
	string word, res;
	while(scin >> word)
	{
		if(res.length() !=0 )
			word += " ";
		res = word + res;
	}
	s = res;
*/
	string res;
	int j = s.length();
	for(int i = s.length()-1; i>=0; i--)
	{
		if(s[i]==' ')
			j = i;
		else if(i==0 || s[i-1] == ' ')
		{
			if(res.length()!=0)
				res +=' ';
			for(int k=i; k<j; k++)
				res += s[k];
		}
	}
	s = res;
}

//Evaluate Reverse Polish Notation
int Solution::evalRPN(vector<string> &tokens)
{
	int ret=0;
	stack<int> operand;
	int a, b;
	char ops;
	for(int i=0; i<tokens.size(); i++)
	{
		ops = tokens[i][0];
		if((ops=='+'||ops=='-'||ops=='*'||ops=='/')&&tokens[i].length()==1)
		{
			a = operand.top();
			operand.pop();
			b = operand.top();
			operand.pop();
			if(ops=='+')
				ret = b + a;
			else if(ops=='-')
				ret = b - a;
			else if(ops=='*')
				ret = b * a;
			else if(ops=='/')
				ret = b/a;
			operand.push(ret); 
		}
		else
		{
			operand.push(atoi(tokens[i].c_str()));
		}
	}	
	if(operand.size()==1)
		return operand.top();
}





