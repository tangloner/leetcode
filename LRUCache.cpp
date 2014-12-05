/*======================================
	@ tangloner <tangloner@gmail.com>
	@ LRUCache.cpp
`	@ Qustion "LRU Cache" in Leetcode
======================================*/

#include "LRUCache.h"

LRUCache::LRUCache(int capacity)
{
	Size = capacity;
	head = new Node;
	tail = new Node;
	head->next = tail;
	head->prev = NULL;
	tail->prev = head;
	tail->next = NULL;
}

void LRUCache::detach(Node* n)
{
	n->prev->next = n->next;
	n->next->prev = n->prev;
}

void LRUCache::attach(Node* n)
{
	n->next = head->next;
	n->prev = head;
	head->next = n;
	n->next->prev = n;
}

int LRUCache::get(int k)
{
	map<int, Node*>::iterator ret;
	ret = cachemap.find(k);
	if(ret != cachemap.end())
	{
		detach(ret->second);
		attach(ret->second);
		return ret->second->value;
	}	
	return -1;
}

void LRUCache::set(int key, int value)
{
	Node* tmp;
	int pkey;
	map<int, Node*>::iterator it = cachemap.find(key);
	if(it!=cachemap.end())
	{
		it->second->value = value;
		detach(it->second);
		attach(it->second);
	}
	else if(cachemap.size() < Size)
	{
		tmp = new Node;
		tmp->value = value;
		tmp->key = key;
		cachemap[key] = tmp;
		attach(tmp);
	}
	else
	{
		tmp = tail->prev;
		pkey = tmp->key;
		detach(tmp);
		tmp->key = key;
		tmp->value = value;
		cachemap.erase(pkey);
		cachemap[key] = tmp;
		attach(tmp);
	}
}
