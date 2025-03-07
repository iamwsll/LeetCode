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
        ListNode* reverse(ListNode* head)
        {
            if(head==nullptr)return head;
            ListNode* pre = nullptr;
            ListNode* cur = head;
            while(cur)
            {
                ListNode* next_node  = cur->next;
                cur->next = pre;
                pre = cur;
                cur = next_node;
            }
            return pre;
        }
        bool isPalindrome(ListNode* head) 
        {
            ListNode* slow = head;
            ListNode* fast = head;
            while(slow&&fast&&fast->next)
            {
                slow = slow->next;
                fast = fast->next->next;
            }
            ListNode* newhead = reverse(slow);
            ListNode* cur = head;
            while(newhead&&cur)
            {
                if(newhead->val!=cur->val)return false;
                newhead = newhead ->next;
                cur = cur->next;
            }
            return true;
        }
    };