/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode *head = new ListNode();
        ListNode *it = head;

        ListNode *it1 = list1;
        ListNode *it2 =list2;

        while((it1 != NULL) && (it2 !=NULL) )
        {
            if(it1->val<=it2->val)
            {
                it->next = it1;
                it1=it1->next;
                it = it->next;
            }
            else{
                it->next = it2;
                it2=it2->next;
                it = it->next;
            }
        }
        
        while(it1 != NULL)
        {
            it->next = it1;
            it1=it1->next;
            it = it->next;
        }

        while(it2 != NULL)
        {
            it->next = it2;
            it2=it2->next;
            it = it->next;
        }

        return head->next;
    }
};
