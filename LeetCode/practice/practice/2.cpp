#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <string>

using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) 
{
	ListNode* result = new ListNode(0);
	
	ListNode* a = l1; 
	ListNode* b = l2;
	ListNode* c = result;
	
	int s = 0;

	while (a != NULL || b != NULL)
	{
		int a_val = 0, b_val = 0;
		if (a == NULL)
			a_val = 0;
		else
			a_val = a->val;
		if (b == NULL)
			b_val = 0;
		else
			b_val = b->val;

		int k = a_val + b_val + s;
		s = k / 10;
		(c->next) = new ListNode(k % 10);
		c = c->next;

		if (a != NULL)
			a = a->next;
		if (b != NULL)
			b = b->next;
	}

	if (s > 0)
		(c->next)->val = s;

	return result->next;
}