#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <string>
#include <cmath>
#include <climits>
#include <queue>

using namespace std;

struct ListNode
{
	int val;
	ListNode *next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode *next) : val(x), next(next) {}

};

ListNode* removeNthFromEnd(ListNode* head, int n) 
{
	queue<ListNode*> q;
	int queueNum = 0;
	ListNode* node = head;

	while (node != NULL)
	{
		++queueNum;
		if (q.size() < n + 1)
		{
			q.push(node);
		}
		else
		{
			q.pop();
			q.push(node);
		}
		node = node->next;
	}

	if (queueNum == 1 && n == 1)
		return NULL;

	if (queueNum == n)
	{
		q.pop();
		return q.front();
	}
	ListNode* a = q.front();
	q.pop();
	ListNode* b = q.front();
	a->next = b->next;
	return head;
}

