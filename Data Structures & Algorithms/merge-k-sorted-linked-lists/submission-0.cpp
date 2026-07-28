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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<pair<int,ListNode*> ,vector<pair<int,ListNode*>>,greater<pair<int,ListNode*>>> pq;
        ListNode *head = new ListNode(0);
        ListNode *it=head;
        
        //inputing the initial list 
        for(int i=0;i<lists.size();i++)
        {
            if(lists[i]!=NULL)
            pq.push({lists[i]->val,lists[i]});
        }

        //maining sorted order
        while(!pq.empty())
        {
            it->next = pq.top().second;
            it=it->next;
            ListNode *x = pq.top().second;
            pq.pop();

            if(x->next != NULL)
            {
                pq.push({x->next->val,x->next});
            }

        }

        return head->next;
        
    }
};
