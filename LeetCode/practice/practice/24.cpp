#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <string>
#include <cmath>
#include <climits>

using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* swap(ListNode* a, ListNode* b)
{
	a->next = b->next;
	b->next = a;
	return b;
}

ListNode* swapPairs(ListNode* head)
{
	//0, 1개만 있는 경우 제외 
	if (head == NULL)
		return head;
	if (head->next == NULL)
		return head;

	ListNode* start = head->next;
	//head->next = (head->next)->next;
	//head->next = head;
	ListNode* preNode = NULL;

	while (head != NULL && head->next != NULL)
	{
		ListNode* k = swap(head, head->next);
		if (preNode == NULL)
		{
			preNode = k;
			preNode = preNode->next;
		}
		else
		{
			preNode->next = k;
			preNode = preNode->next->next;
		}
		head = k->next->next;
	}

	return start;
}

int main()
{
	int n = 6;
	ListNode* l1 = new ListNode(1);
	ListNode* start = l1;

	for (int i = 1; i < n; ++i)
	{
		ListNode* temp = new ListNode(i + 1);
		l1->next = temp;
		l1 = l1->next;
	}

	ListNode* t = swapPairs(start);
	while (t != NULL)
	{
		cout << t->val << " ";
		t = t->next;
	}
	cout << endl;
}