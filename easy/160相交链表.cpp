/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
		//暴力法
		ListNode *cur_a=headA;
		while(cur_a)
		{
			ListNode *cur_b=headB;
			while(cur_b)
			{
				if(cur_a=cur_b)
				{
					return cur_b;
				}
				cur_b=cur_b->next;
			}
			cur_a=cur_a->next;
		}
        return nullptr;
		
		//建立哈希表
		std::unordered_set<ListNode*>set;
		while(headA)
		{
			set.insert(headA);
			headA=headA->next;
		}
		
		while(headB)
		{
			if(set.find(headB)!=set.end())
			{
				return headB;
			}
			headB=headB->next;
		}
		return nullptr;
		
		
		//双指针
		if(headA==nullptr||headB==nullptr)
		return nullptr;
		
		ListNode* cur_a=headA;
		ListNode* cur_b=headB;
		
		while(cur_a!=cur_b)
		{
			cur_a = (cur_a = nullptr ? headB : cur_a->next);
			cur_b = (cur_b = nullptr ? headA : cur_b->next);
		}
		return cur_a;
	}
};