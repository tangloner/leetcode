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

int Solution::minDepth(TreeNode *root) 
{
	if(root==NULL)
		return 0;
	if(root->left==NULL&&root->right==NULL)
		return 1;
	if(root->left==NULL&&root->right!=NULL)
		return 1+minDepth(root->right);
	if(root->left!=NULL&&root->right==NULL)
		return 1+minDepth(root->left);
	else
		return min(minDepth(root->left)+1,minDepth(root->right)+1);
}

int Solution::maxDepth(TreeNode *root) 
{
	if(root==NULL)
		return 0;
	if(root->left==NULL&&root->right==NULL)
		return 1;
	if(root->left==NULL&&root->right!=NULL)
		return 1+maxDepth(root->right);
	if(root->left!=NULL&&root->right==NULL)
		return 1+maxDepth(root->left);
	else
		return max(maxDepth(root->left)+1,maxDepth(root->right)+1);
}

void Solution::sortColors(int A[], int n)
{
	int start = 0;
	int end = n - 1;
	for(int i = 0; i <= end; i++)
	{
		if(A[i] == 0 && i != start)
		{
			swap(A[i], A[start]);
			start++;
			i--;
		}
		else if(A[i] == 2 && i != end)
		{
			swap(A[i], A[end]);
			end--;
			i--;
		}
	}
}

vector<Interval> Solution::mergeInterval(vector<Interval> &intervals) 
{
	if(intervals.size()==0||intervals.size()==1)
		return intervals;
	sort(intervals.begin(),intervals.end(),compIntvl());
	vector<Interval> ret;
	Interval tmp = intervals[0];
	for(int i=0; i<intervals.size(); i++)
	{
		if(tmp.start<=intervals[i].start&&tmp.end>=intervals[i].start)
		{
			if(tmp.end<intervals[i].end)
				tmp.end = intervals[i].end;
		}
		else if(tmp.end<intervals[i].start)
		{
			ret.push_back(tmp);
			tmp = intervals[i];
		}
	}
	ret.push_back(tmp);
	return ret;
}


vector<Interval> Solution::insertInterval(vector<Interval> &intervals, Interval newInterval)
{
	vector<Interval> ret;
	if(intervals.size()==0)
	{
		ret.push_back(newInterval);
		return ret;
	}
	bool flag = false;
	sort(intervals.begin(), intervals.end(), compIntvl());
	for(int i=0; i<intervals.size(); i++)
	{
		if(intervals[i].end<newInterval.start)
			ret.push_back(intervals[i]);
		else if(intervals[i].start<=newInterval.start&&intervals[i].end>=newInterval.start)
		{
			if(intervals[i].start<newInterval.start)
				newInterval.start = intervals[i].start;
			if(intervals[i].end>newInterval.end)
				newInterval.end = intervals[i].end;
		}
		else if(intervals[i].start>=newInterval.start&&intervals[i].end<=newInterval.end)
			;
		else if(intervals[i].start>=newInterval.start&&intervals[i].start<=newInterval.end&&intervals[i].end>=newInterval.end)
		{
			newInterval.end = intervals[i].end;
		}
		else if(intervals[i].start>newInterval.end&&flag==false)
		{
			ret.push_back(newInterval);
			ret.push_back(intervals[i]);
			flag=true;
		}
		else if(intervals[i].start>newInterval.end&&flag==true)
			ret.push_back(intervals[i]);
	}
	if(flag==false)
		ret.push_back(newInterval);
	return ret;
}


int Solution::singleNumber(int A[], int n)
{
/*	map< int, vector<int> > valMap;
	for(int i=0; i<n; i++)
	{
		if(valMap.find(A[i])==valMap.end())
		{
			vector<int> tmp;
			tmp.push_back(i);
			valMap[A[i]] = tmp;
		}    
		else
			valMap.erase(A[i]);
	}
	return valMap.begin()->first;
*/
	for(int i = 1; i < n; ++i)
		A[0] ^= A[i];
	return A[0];
}

int Solution::singleNumberII(int A[], int n) 
{
	int ec1=0, ec2=0, ec3=0;
	for(int i=0; i<n; i++)
	{
		ec3 = ec2 & A[i];
		ec2 = (ec2|(ec1&A[i]))&(~ec3);
		ec1 = (ec1|A[i])&(~ec3);
	}
	return ec1;
}

vector<vector<int> > Solution::subsets(vector<int> &S) 
{
	sort(S.begin(),S.end());
	int elem_num = S.size();
	int subset_num = pow(2, elem_num);
	vector< vector<int> > ret(subset_num,vector<int>());
	for(int i=0; i<elem_num; i++)
	{
		for(int j=0; j<subset_num; j++)
		{
			if((j>>i)&1)
				ret[j].push_back(S[i]);
		}
	}
	return ret;
}

bool Solution::isSymmetric(TreeNode *root) 
{
	if(root==NULL||(root->left==NULL&&root->right==NULL))
		return true;
	else
		return twotreeSymmetric(root->left, root->right);
}

bool Solution::twotreeSymmetric(TreeNode *tleft, TreeNode *tright)
{
	if(tleft==NULL&&tright==NULL)
		return true;
	else if((tleft==NULL&&tright!=NULL)||(tleft!=NULL&&tright==NULL))
		return false;
	else if(tleft->val==tright->val)
	{
		if(tleft->left==NULL&&tleft->right==NULL&&tright->left==NULL&&tright->right==NULL)
			return true;
		else if((tleft->left==NULL&&tright->right!=NULL)||(tleft->left!=NULL&&tright->right==NULL))
			return false;
		else if((tleft->right==NULL&&tright->left!=NULL)||(tleft->right!=NULL&&tright->left==NULL))
			return false;
		else
			return twotreeSymmetric(tleft->left,tright->right) && twotreeSymmetric(tleft->right,tright->left);
	}
	else 
		return false;
}

bool Solution::isValidBST(TreeNode *root)
{
	return checkBST(root,INT_MIN, INT_MAX);
}

bool Solution::checkBST(TreeNode* root, int min, int max)
{
	if(root==NULL)
		return true;
	else if(root->val<min||root->val>max)
	{
		return false;
	}
	else
	{
		if(root->left!=NULL&&root->left->val==root->val)
			return false;
		else if(root->right!=NULL&&root->right->val==root->val)
			return false;
		if(root->val==INT_MIN)
		{
			return checkBST(root->left,min,root->val) && checkBST(root->right,root->val+1,max);
		}
		else if(root->val==INT_MAX)
		{
			return checkBST(root->left,min,root->val-1) && checkBST(root->right,root->val,max);
		}
		else
		{
			return checkBST(root->left,min,root->val-1) && checkBST(root->right,root->val+1,max);
		}
	}
}

int Solution::numTrees(int n)
{
	int dp[n+1];
	dp[0] = dp[1] = 1;
	for(int i=2; i<=n; i++)
	{
		dp[i]=0;
		for(int j=1; j<=i;j++)
		{
			dp[i] += dp[j-1]*dp[i-j];
		}
	}
	return dp[n];
}

vector<TreeNode *> Solution::generateTrees(int n)
{
   return generateTree(1,n);
}

vector<TreeNode *> Solution::generateTree(int from, int to)
{
	vector<TreeNode *> ret;
	if(to-from < 0)
	{
		TreeNode* tmp = NULL;
		ret.push_back(tmp);
	}
	else if(to-from==0)
	{
		TreeNode* tmp = new TreeNode(from);
		ret.push_back(tmp);
	}
	else if(to-from > 0)
	{
		for(int i=from; i<=to; i++)
		{
			vector<TreeNode*> l = generateTree(from,i-1);
			vector<TreeNode*> r = generateTree(i+1,to);
			for(int j=0; j<l.size(); j++)
			{
				for(int k=0; k<r.size(); k++)
				{
					TreeNode* h = new TreeNode(i);
					h->left = l[j];
					h->right = r[k];
					ret.push_back(h);
				}
			}
		}
	}
	return ret;
}

int Solution::sumNumbers(TreeNode *root)
{
	if(root==NULL)
		return 0;
	else
	{
		vector<int> pathVal;
		int val = 0;
		pathNum(root,val,pathVal);
		for(int i=0; i<pathVal.size(); i++)
		{
			val += pathVal[i];
		}
		return val;
	}
}

void Solution::pathNum(TreeNode *root, int val, vector<int> &pathVal)
{
	if(root==NULL)
	{
		;
	}
	else if(root->left==NULL&&root->right==NULL)
	{
		pathVal.push_back(val*10+root->val);
	}
	else
	{
		val = val*10 + root->val;
		pathNum(root->left,val,pathVal);
		pathNum(root->right,val,pathVal);
	}
}


void Solution::recoverTree(TreeNode *root)
{
	if(!root)
		return ;
	TreeNode *a=NULL, *b=NULL;
	TreeNode *pre = new TreeNode(INT_MIN);
	recover(root,pre,a,b);
	if(a&&b)
		swap(a->val, b->val);
}

void Solution::recover(TreeNode *root, TreeNode* &pre, TreeNode* &a, TreeNode* &b)
{
	if(root)
	{
		recover(root->left,pre,a,b);
		if(root->val < pre->val)
		{
			if(!a) 
				a=pre;
			b = root;
		}
		pre = root;
		recover(root->right,pre,a,b);
	}
}

void Solution::connectTreeNodes(TreeLinkNode *root)
{
	if(root==NULL||(root->left==NULL&&root->right==NULL))
		;
	else
	{
		queue<TreeLinkNode *> level;
		TreeLinkNode* tmp;
		int height = 0;
		int count = 1;
		level.push(root);
		while(!level.empty())
		{
			tmp = level.front();
			level.pop();
			if(tmp->left!=NULL)
				level.push(tmp->left);
			if(tmp->right!=NULL)
				level.push(tmp->right);
			if(count < pow(2,height))
			{
				tmp->next = level.front();
				count++;
			}
			else
			{
				count = 1;
				tmp->next = NULL;
				height++;
			}
		}
	}
}

void Solution::connectTreeNodesII(TreeLinkNode *root) 
{
	if(root==NULL||(root->left==NULL&&root->right==NULL))
		;
	else
	{
		queue< pair<TreeLinkNode *, int> > level;
		pair<TreeLinkNode*, int> tmp;
		pair<TreeLinkNode*, int> ptmp;
		ptmp.first = root;
		ptmp.second = 0;
		level.push(ptmp);
		while(!level.empty())
		{
			tmp = level.front();
			level.pop();
			if(tmp.first->left!=NULL)
			{
				ptmp.first = tmp.first->left;
				ptmp.second = tmp.second+1;
				level.push(ptmp);
			}
			if(tmp.first->right!=NULL)
			{
				ptmp.first = tmp.first->right;
				ptmp.second = tmp.second+1;
				level.push(ptmp);
			}
			
			if(level.empty())
				tmp.first->next = NULL;
			else if(level.front().second==tmp.second)
				tmp.first->next = level.front().first;
			else
				tmp.first->next = NULL;
		}
	}
}

vector<int> Solution::inorderTraversal(TreeNode *root)
{
	vector<int> ret;
	if(root==NULL)
		return ret;
	else
	{
		inorder(root->left, ret);
		ret.push_back(root->val);
		inorder(root->right,ret);
	}
	return ret;
}

void Solution::inorder(TreeNode *root, vector<int> &ret)
{
	if(root==NULL)
		;
	else
	{
		inorder(root->left, ret);
		ret.push_back(root->val);
		inorder(root->right,ret);
	}
}


vector<vector<int> > Solution::levelOrder(TreeNode *root)
{
	vector< vector<int> > ret;
	if(root==NULL)
		return ret;
	else
	{
		queue< pair<TreeNode *, int> > level;
		vector< pair<TreeNode *, int> > all;
		pair<TreeNode*, int> tmp;
		pair<TreeNode*, int> ptmp;
		ptmp.first = root;
		ptmp.second = 1;
		level.push(ptmp);
		all.push_back(ptmp);
		while(!level.empty())
		{
			tmp = level.front();
			level.pop();
			if(tmp.first->left!=NULL)
			{
				ptmp.first = tmp.first->left;
				ptmp.second = tmp.second+1;
				level.push(ptmp);
				all.push_back(ptmp);
			}
			if(tmp.first->right!=NULL)
			{
				ptmp.first = tmp.first->right;
				ptmp.second = tmp.second+1;
				level.push(ptmp);
				all.push_back(ptmp);
			}
		}
		for(int i=0; i<all.size(); i++)
		{
			if(all[i].second > ret.size())
			{
				vector<int> vtmp;
				ret.push_back(vtmp);
			}
			ret[all[i].second-1].push_back(all[i].first->val);
		}
		return ret;
	}
}

vector<vector<int> > Solution::levelOrderBottom(TreeNode *root) 
{
	vector< vector<int> > ret;
	if(root==NULL)
		return ret;
	else
	{
		queue< pair<TreeNode *, int> > level;
		vector< pair<TreeNode *, int> > all;
		pair<TreeNode*, int> tmp;
		pair<TreeNode*, int> ptmp;
		ptmp.first = root;
		ptmp.second = 1;
		level.push(ptmp);
		all.push_back(ptmp);
		while(!level.empty())
		{
			tmp = level.front();
			level.pop();
			if(tmp.first->left!=NULL)
			{
				ptmp.first = tmp.first->left;
				ptmp.second = tmp.second+1;
				level.push(ptmp);
				all.push_back(ptmp);
			}
			if(tmp.first->right!=NULL)
			{
				ptmp.first = tmp.first->right;
				ptmp.second = tmp.second+1;
				level.push(ptmp);
				all.push_back(ptmp);
			}
		}
		int height = all[all.size()-1].second;
		for(int i=all.size()-1; i>=0; i--)
		{
			if((height-all[i].second+1) > ret.size())
			{
				vector<int> vtmp;
				ret.push_back(vtmp);
			}
			ret[height-all[i].second].push_back(all[i].first->val);
		}
		vector< vector<int> > result;
		for(int i=0; i<ret.size(); i++)
		{
			vector<int> rtmp;
			rtmp.insert(rtmp.begin(),ret[i].rbegin(),ret[i].rend());
			result.push_back(rtmp);
		}
		return result;
	}
}


int Solution::maxPathSum(TreeNode *root)
{
	int sum = INT_MIN;
	maxSum(root,sum);
	return sum;
}

int Solution::maxSum(TreeNode* root, int& sum)
{
	if(root==NULL)
		return 0;
	else
	{
		int l = maxSum(root->left,sum);
		int r = maxSum(root->right,sum);
		if(l<0)
			l=0;
		if(r<0)
			r=0;
		if(l+r+root->val > sum)
			sum = l+r+root->val;
		return root->val += max(l,r);
	}
}

//Flatten Binary Tree to Linked List 
void Solution::flatten(TreeNode *root) 
{
	if(root==NULL||(root->left==NULL&&root->right==NULL))
		return ;
	if(root->left==NULL)
	{
		flatten(root->right);
		return ;
	}
	TreeNode* rNode = root->right;
	root->right = root->left;
	root->left = NULL;
	flatten(root->right);  
	TreeNode* pNode = root;
	while(pNode->right!=NULL)
		pNode = pNode->right;
	pNode->right = rNode;
	flatten(rNode);
}

TreeNode* Solution::sortedArrayToBST(vector<int> &num)
{
	if(num.size()==0)
		return NULL;
	else
		return constructBST(num,0,num.size()-1);
}

TreeNode* Solution::constructBST(vector<int> num,int start, int end)
{
	int mid = start + (end-start)/2;
	TreeNode* root = new TreeNode(num[mid]);
	if(mid>start)
		root->left = constructBST(num,start,mid-1);
	if(mid<end)
		root->right = constructBST(num,mid+1,end);
	return root;
}


TreeNode* Solution::buildTree(vector<int> &pre, vector<int> &in) 
{
	if(pre.size()==0)
		return NULL;
	int ppre=0, pin = 0;
	TreeNode *root = new TreeNode(pre.at(ppre++));
	TreeNode *p = NULL;
	stack<TreeNode *> roots;
	roots.push(root);
	while(true)
	{
		if(in.at(pin)==roots.top()->val)
		{
			p = roots.top();
			roots.pop();
			pin++;
			if(pin==in.size())
				break;
			if(roots.size() && in.at(pin)==roots.top()->val)
				continue;
			p->right = new TreeNode(pre.at(ppre));
			ppre++;
			roots.push(p->right);
		}
		else
		{
			p = new TreeNode(pre.at(ppre));
			ppre++;
			roots.top()->left = p;
			roots.push(p);
		}
	}
	return root;
}

TreeNode* Solution::buildTreeII(vector<int> &inorder, vector<int> &postorder) 
{
	return buildTree3(inorder, postorder, 0, inorder.size()-1, 0, postorder.size()-1);
}

TreeNode* Solution::buildTree3(vector<int> &inorder, vector<int> &postorder, int is, int ie, int ps, int pe)
{

	if(ps > pe)
		return NULL;
	TreeNode* root = new TreeNode(postorder[pe]);
	int pos;
	for(int i=is; i<=ie; i++)
	{
		if(inorder[i]==root->val)
		{
			pos = i;
			break;
		}
	}
	root->left = buildTree3(inorder, postorder, is, pos-1, ps, ps+pos-is-1);
	root->right = buildTree3(inorder, postorder, pos+1, ie, pe-ie+pos, pe-1);
	return root;
}

vector<vector<int> > Solution::zigzagLevelOrder(TreeNode *root) 
{
	vector< vector<int> > ret;
	if(root==NULL)
		return ret;
	else
	{
		queue< pair<TreeNode *, int> > level;
		vector< pair<TreeNode *, int> > all;
		pair<TreeNode*, int> tmp;
		pair<TreeNode*, int> ptmp;
		ptmp.first = root;
		ptmp.second = 1;
		level.push(ptmp);
		all.push_back(ptmp);
		while(!level.empty())
		{
			tmp = level.front();
			level.pop();
			if(tmp.first->left!=NULL)
			{
				ptmp.first = tmp.first->left;
				ptmp.second = tmp.second+1;
				level.push(ptmp);
				all.push_back(ptmp);
			}
			if(tmp.first->right!=NULL)
			{
				ptmp.first = tmp.first->right;
				ptmp.second = tmp.second+1;
				level.push(ptmp);
				all.push_back(ptmp);
			}
		}
		for(int i=0; i<all.size(); i++)
		{
			if(all[i].second > ret.size())
			{
				vector<int> vtmp;
				ret.push_back(vtmp);
			}
			ret[all[i].second-1].push_back(all[i].first->val);
		}
		vector< vector<int> > result;
		for(int i=0; i<ret.size(); i++)
		{
			vector<int> rtmp;
			if(i%2==1)
			{
				rtmp.insert(rtmp.begin(),ret[i].rbegin(),ret[i].rend());
			}
			else
			{
				rtmp.insert(rtmp.begin(),ret[i].begin(),ret[i].end());
			}
			result.push_back(rtmp);
		}
		return result;
	}
}
