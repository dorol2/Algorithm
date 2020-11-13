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

ListNode* mergeKLists(vector<ListNode*>& lists) 
{
	if(lists.size() == 0)
		return NULL;

	ListNode* save = new ListNode(0);
	ListNode* start = save;
	save->next = lists[0];
	//앞에 2개 비교해서 저장, 저장한 것과 다음 것 비교해서 저장
	for (int i = 1; i < lists.size(); ++i)
	{
		save = start->next;
		while (lists[i] != NULL && save != NULL)
		{
			if (lists[i]->val >= save->val)
			{
				while (save->next != NULL)
				{
					if (save->next->val > lists[i]->val)
						break;
					else
						save = save->next;
				}

				ListNode* temp = save->next;
				save->next = lists[i];
				lists[i] = lists[i]->next;
				save = save->next;
				save->next = temp;
			}
			else
			{
				if (save == start->next)
					start->next = lists[i];
				
				ListNode* temp = save;
				save = lists[i];
				lists[i] = temp;
			}
		}

		if (save == NULL)
		{
			if (save == start->next)
				start->next = lists[i];
			
			save = lists[i];
		}
	}
	return start->next;
}


int main()
{
	vector<int> v1 = { 1, 4, 5 };
	vector<int> v2 = { 1, 3, 4 };
	vector<int> v3 = { 2, 6 };
	vector<vector<int>> vi= { v1, v2, v3 };

	ListNode* l1 = new ListNode(v1[0]);
	ListNode* l2 = new ListNode(v2[0]);
	ListNode* l3 = new ListNode(v3[0]);
	vector<ListNode*> vl = { l1, l2, l3 };

	for (int i = 0; i < vi.size(); ++i)
	{
		for (int j = 1; j < vi[i].size(); ++j)
		{
			vl[i]->next = new ListNode(vi[i][j]);
			vl[i] = vl[i]->next;
		}
	}

	vl = { NULL, l2, NULL };
	
	ListNode* t = mergeKLists(vl);
	while (t != NULL)
	{
		cout << t->val << " ";
		t = t->next;
	}
	cout << endl;
}