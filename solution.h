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

struct locValue
{
	int loc;
	int val;
	bool operator() (const locValue& a, const locValue& b)
	{	
		return a.val < b.val;
	}
};

struct ListNode
{
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {};
};


struct TreeNode 
{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

struct Interval
{
	int start;
	int end;
	Interval(): start(0), end(0) {}
	Interval(int s, int e): start(s), end(e) {}
};

struct compIntvl
{
	bool operator() (const Interval& a, const Interval& b)
	{
		return a.start < b.start;
	}
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
	
	// Two sum
	vector<int> twoSum(vector<int> &numbers, int target);
	
	// Sort List
	ListNode *sortList(ListNode *head);
	int countSize(ListNode* head);
	ListNode* mergeList(ListNode* a, ListNode* b);
	void halfList(ListNode *head, ListNode **a, ListNode **b);

	// insertion list
	ListNode *insertionSortList(ListNode *head);

	//postorder Traversal
	vector<int> postorderTraversal(TreeNode *root);
	void postorder(TreeNode *root, vector<int> &ret);
	void post(TreeNode *root, vector<int> &ret);

	//preorder traversal
	vector<int> preorderTraversal(TreeNode *root);
	void preorder(TreeNode *root, vector<int> &ret);

	// reorder list
	void reorderList(ListNode *head);
	ListNode* weavingList(ListNode *a, ListNode *b);
	void reverseHalf(ListNode* head, ListNode **a, ListNode **b);

	// has Cycle
	bool hasCycle(ListNode *head);
	ListNode *detectCycle(ListNode* head);
	
	//has Path Sum
	bool hasPathSum(TreeNode *root, int sum);
	// Path sum record
	vector<vector<int> > pathSum(TreeNode *root, int sum);
	void leaf_check(TreeNode *root, int sum, vector<int> tmp, vector< vector<int> > &ret);
	void treeSum(TreeNode *root, int sum, vector<int> tmp, vector< vector<int> > &ret);

	//is balanced
	bool isBalanced(TreeNode *root);
	int treeheight(TreeNode *root);

	// min depth
	int minDepth(TreeNode *root);

	// sort colors
	void sortColors(int A[], int n);
	
	//Merge Intervals
	vector<Interval> mergeInterval(vector<Interval> &intervals);
	//Insert Interval
	vector<Interval> insertInterval(vector<Interval> &intervals, Interval newInterval);
	//Single Number appeared twice
	int singleNumber(int A[], int n);
	//Single Number appeared three times
	int singleNumberII(int A[], int n);
 	//subset
	vector< vector<int> > subsets(vector<int> &S);
};
#endif
