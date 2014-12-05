/*======================================
	@ tangloner <tangloner@gmail.com>
	@ LRU Cache
`	@ Qustion "LRU Cache" in Leetcode
======================================*/

#include "header.h"

#ifndef LRUCACHE_H
#define LRUCACHE_H
struct Node
{
	int key;
	int value;
	Node* prev;
	Node* next;
};

class LRUCache
{
public:
	LRUCache(int capacity);
	int get(int key);
	void set(int key, int value);
private:
	void detach(Node* n);
	void attach(Node* n);
	map<int, Node*> cachemap;
	Node *head, *tail;
	int Size; 
};
#endif 

