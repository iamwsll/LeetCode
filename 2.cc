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
        ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) 
        {
            ListNode* head = new ListNode();
    
            ListNode* pre = head;
            int t = 0;
            while(l1&&l2)
            {
                int s = l1->val+l2->val+t;
                ListNode* cur = new ListNode(s%10);
                pre->next = cur;
                cur->next = nullptr;
                pre = cur;
                t = s/10;
                l1 = l1->next;
                l2 = l2->next;
            }
            while(l1)
            {
                int s = l1->val+t;
                ListNode* cur = new ListNode(s%10);
                pre->next = cur;
                cur->next = nullptr;
                pre = cur;
                t = s/10;
                l1 = l1->next;
            }
            while(l2)
            {
                int s = l2->val+t;
                ListNode* cur = new ListNode(s%10);
                pre->next = cur;
                cur->next = nullptr;
                pre = cur;
                t = s/10;
                l2 = l2->next;
            }
            if(t)pre->next = new ListNode(t);
            auto trueHead = head->next;
            delete head;
            return trueHead;
        }
    };