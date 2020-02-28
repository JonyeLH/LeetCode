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
    ListNode* reverseList(ListNode* head) {
	//头插法
	ListNode* p = new ListNode(-1);
	p->next = NULL;
	ListNode* t = head;
	ListNode* s	
	while(t)
	{
		s = t;
		t = t->next;
		s->next = p->next;
		p->next = s;
	}
	return p->next;
	
	//双指针
	ListNode* cur = NULL, *pre = head;
    while (pre != NULL) 
	{
        ListNode* t = pre->next;
        pre->next = cur;
        cur = pre;
        pre = t;
    }
    return cur;
		
	//递归
	if (head == NULL || head->next == NULL) 
	{
        return head;
    }
    ListNode* ret = reverseList(head->next);
    head->next->next = head;
    head->next = NULL;
    return ret;
	
    }
};