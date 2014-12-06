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
	int size = tokens.size();
	for(int i=0; i<size; i++)
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

//Max Points on a line
int Solution::maxPoints(vector<Point> &points)
{
	int size = points.size();
	if(size<3)
		return size;

	int ret = 0, tmp = 0;
	double k, b;

	for(int i=0; i<size; i++)	
	{
		tmp = 1;
		for(int j=i+1; j<size; j++)
		{
			if(points[i].x==points[j].x&&points[i].y==points[j].y)
			{
				tmp += 1;
				continue;
			}
			else if(points[i].x==points[j].x)
			{
				tmp += 1;
				for(int l=j+1; l<size; l++)
				{
					if(points[l].x == points[j].x)
						tmp += 1;
				}
				if(tmp > ret)
					ret = tmp;
				tmp = 1;
			}
			else
			{
				tmp += 1;
				k= 1.0*(points[i].y-points[j].y)/(points[i].x-points[j].x);
				b= 1.0*(points[i].x*points[j].y-points[i].y*points[j].x)/(points[i].x-points[j].x);
				for(int l=j+1; l<size; l++)
				{
					if(points[l].y==(points[l].x*k+b))
						tmp += 1;
				}
				if(tmp > ret)
					ret = tmp;
				tmp = 1;
			}
		}
		if(tmp > ret)
			ret = tmp;
		tmp = 1;
	}
	return ret;
}

vector<int> Solution::twoSum(vector<int> &numbers, int target)
{
	vector<int> ret;
/*	vector<locValue> unSort;
	locValue tmp;
	int sum=0;
	for(int i=0; i<numbers.size(); i++)
	{
		tmp.loc = i;
		tmp.val = numbers[i];
		unSort.push_back(tmp);
	}
	sort(unSort.begin(), unSort.end(), locValue());
	for(int i=0, j=unSort.size()-1; i<j; )
	{
		sum = unSort[i].val + unSort[j].val;
//		cout<<sum<<endl;
		if(sum < target)
			i++;
		else if(sum > target)
			j--;
		else
		{
			if(unSort[i].loc <= unSort[j].loc)
			{
				ret.push_back(unSort[i].loc+1);
				ret.push_back(unSort[j].loc+1);
			}
			else
			{
				ret.push_back(unSort[j].loc+1);
				ret.push_back(unSort[i].loc+1);
			}
			break;
		}
	}
*/
	map<int, int> locmap;
	int tmp;
	for(int i=0; i<numbers.size(); i++)
	{
		locmap[numbers[i]] = i;
//		cout<<numbers[i]<<"\t"<<locmap[numbers[i]]<<endl;
	}
	for(int i=0; i<numbers.size(); i++)
	{
		tmp=target-numbers[i];
		if(locmap.find(tmp)!=locmap.end())
		{
			if(i!=locmap[tmp])
			{
				ret.push_back(i+1);
				ret.push_back(locmap[tmp]+1);
//				cout<<locmap[tmp]<<endl;
			}
		}
	}
	return ret;
}

int Solution::countSize(ListNode* head)
{
	int n=0;
	while(head!=NULL)
	{
		cout<<head->val<<"\t";
		head = head->next;
		++n;
	}
	cout<<endl;
//	cout<<n<<endl;
	return n;
}

ListNode* Solution::mergeList(ListNode* a, ListNode* b)
{
	ListNode* temp;
	if(!a)
		return b;
	if(!b)
		return a;
	if(a->val < b->val)
	{
		temp = a;
		temp->next = mergeList(a->next,b);
	}
	else
	{
		temp = b;
		temp->next = mergeList(a,b->next);
	}
	return temp;
}

void Solution::halfList(ListNode *head, ListNode **a, ListNode **b)
{

	int n = countSize(head);
	*a = head;
	ListNode* prev = NULL;
	for(int i=0; i<n/2; i++)
	{
		prev = head;
		head = head->next;
	}
	prev->next = NULL;
	*b = head;
/*
	ListNode *fast, *slow, *prev;
	slow = fast = head;
	while(fast && fast->next)
	{
		prev = slow;
		slow = slow->next;
		fast = fast->next->next;
	}
	*a = head;
	*b = slow;
	prev->next = NULL;
*/
}

ListNode* Solution::sortList(ListNode *head)
{
	if(!head)
		return NULL;
	if(!head->next)
		return head;
	ListNode *a, *b;
	halfList(head,&a,&b);
	a = sortList(a);
	b = sortList(b);
	return mergeList(a,b);	
}

ListNode* Solution::insertionSortList(ListNode *head)
{
	if(!head)
		return NULL;
	ListNode* ret = head;
	head = head->next;
	ret->next = NULL;

	while(head)
	{
		ListNode* toInsert = head;
		head = head->next;
		if(toInsert->val < ret->val)
		{
			toInsert->next = ret;
			ret = toInsert;
		}
		else
		{
			ListNode* current = ret;
			while((current->next)&&(current->next->val) < toInsert->val)
				current = current->next;
			toInsert->next = current->next;
			current->next  = toInsert;
		}
	}
	return ret;
}

vector<int> Solution::postorderTraversal(TreeNode *root)
{
	vector<int> ret;
	if(root==NULL)
		return ret;
	if(root->left!=NULL)
		postorder(root->left, ret);
	if(root->right!=NULL)
		postorder(root->right,ret);
	post(root,ret);
	return ret;
}

void Solution::postorder(TreeNode *root, vector<int> &ret)
{
	if(root->left==NULL&&root->right==NULL)
		post(root,ret);
	else if(root->left==NULL&&root->right!=NULL)
	{
		postorder(root->right,ret);
		post(root,ret);
	}

	else if(root->right==NULL&&root->left!=NULL)
	{
		postorder(root->left,ret);
		post(root,ret);
	}
	else
	{
		postorder(root->left, ret);
		postorder(root->right,ret);
		post(root,ret);
	}
}

void Solution::post(TreeNode *root, vector<int> &ret)
{
	ret.push_back(root->val);
}


vector<int> Solution::preorderTraversal(TreeNode *root) 
{
	vector<int> ret;
	if(root==NULL)
		return ret;
	post(root,ret);
	if(root->left!=NULL)
		preorder(root->left, ret);
	if(root->right!=NULL)
		preorder(root->right,ret);
	return ret;
}

void Solution::preorder(TreeNode *root, vector<int> &ret)
{
	if(root->left==NULL&&root->right==NULL)
		post(root,ret);
	else if(root->left==NULL&&root->right!=NULL)
	{
		post(root,ret);
		preorder(root->right,ret);
	}
	else if(root->right==NULL&&root->left!=NULL)
	{
		post(root,ret);
		preorder(root->left,ret);
	}
	else
	{
		post(root,ret);
		preorder(root->left, ret);
		preorder(root->right,ret);
	}
}

void Solution::reorderList(ListNode *head)
{
	if(!head||!head->next||!head->next->next)
		return;
	ListNode *a, *b;
	reverseHalf(head,&a, &b);
	head = NULL;
	head = weavingList(a,b);
	countSize(head);
}

ListNode* Solution::weavingList(ListNode *a, ListNode *b)
{
	if(a==NULL&&b==NULL)
		return NULL;
	if(a==NULL)
		return b;
	if(b==NULL)
		return a;
	else
	{
		ListNode *temp, *nexta, *nextb;
		nexta = a->next;
		a->next = NULL;
		nextb = b->next;
		b->next = NULL;
		temp = a;
		temp->next = b;
		temp->next->next = weavingList(nexta, nextb);
		return temp;
	}
}

void Solution::reverseHalf(ListNode* head, ListNode **a, ListNode **b)
{
	int n = countSize(head);
	*a = head;
	ListNode* prev = NULL;
	for(int i=0; i<n/2; i++)
	{
		prev = head;
		head = head->next;
	}
	prev->next = NULL;
//	countSize(*a);
	prev = NULL;
	ListNode* t1;
	while(head!=NULL)
	{
		t1 = head->next;
		head->next = prev;
		prev = head;
		head = t1;
	}
	*b = prev;
//	countSize(*b);
}

bool Solution::hasCycle(ListNode *head)
{
	if(head==NULL)
		return false;
	map<ListNode*,int> listmap;
	int i=0;
	while(head!=NULL)
	{
		if(listmap.find(head)!=listmap.end())
			return true;
		else
		{
			listmap[head] = i;
			i++;
			head = head->next;
		}
	}
	return false;
}

ListNode* Solution::detectCycle(ListNode* head)
{
	if(head==NULL)
		return NULL;
	map<ListNode*,int> listmap;
	int i=0;
	while(head!=NULL)
	{
		if(listmap.find(head)!=listmap.end())
			return head;
		else
		{
			listmap[head] = i;
			i++;
			head = head->next;
		}
	}
	return NULL;
}

bool Solution::hasPathSum(TreeNode *root, int sum) 
{
	bool ret = false;
	if(root==NULL)
		;
	else if(root->left==NULL&&root->right==NULL)
	{
		if(root->val == sum)
			ret = true;
	}
	else if(root->left==NULL&&root->right != NULL)
	{
		sum -= root->val;
		if(ret==false)
			ret = hasPathSum(root->right,sum);
	}
	else if(root->left!=NULL&&root->right == NULL)
	{
		sum -= root->val;
		if(ret==false)
			ret = hasPathSum(root->left,sum);
	}
	else
	{
		sum -= root->val;
		if(ret==false)
			ret = hasPathSum(root->right,sum);
		if(ret==false)
			ret = hasPathSum(root->left,sum);
	}
	return ret;
}

vector<vector<int> > Solution::pathSum(TreeNode *root, int sum) 
{
	vector< vector<int> > ret;
	vector<int> tmp;
	treeSum(root,sum,tmp,ret);
	return ret;
}

void Solution::leaf_check(TreeNode *root, int sum, vector<int> tmp, vector< vector<int> > &ret)
{
	if(root->val == sum)
	{
		tmp.push_back(root->val);
		ret.push_back(tmp);
	}
}

void Solution::treeSum(TreeNode *root, int sum, vector<int> tmp, vector< vector<int> > &ret)
{
	if(root==NULL)
		;
	else if(root->left==NULL && root->right==NULL)
		leaf_check(root,sum,tmp,ret);
	else if(root->left!=NULL && root->right==NULL)
	{
		sum -= root->val;
		tmp.push_back(root->val);
		treeSum(root->left, sum, tmp, ret);
	}
	else if(root->left==NULL && root->right!=NULL)
	{
		sum -= root->val;
		tmp.push_back(root->val);
		treeSum(root->right, sum, tmp, ret);
	}
	else
	{
		sum -= root->val;
		tmp.push_back(root->val);
		treeSum(root->left, sum, tmp, ret);
		treeSum(root->right, sum, tmp, ret);
	}
}

bool Solution::isBalanced(TreeNode *root)
{
   if(root==NULL)
		return true;
	if(abs(treeheight(root->left)-treeheight(root->right))>1)
		return false;
	return isBalanced(root->left) && isBalanced(root->right);
}

int Solution::treeheight(TreeNode *root)
{
	if(root==NULL)
		return 0;
	return max(treeheight(root->left),treeheight(root->right))+1;
}
