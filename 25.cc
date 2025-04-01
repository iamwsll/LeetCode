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
        pair<ListNode*,ListNode*> reverse(ListNode* head,ListNode*tail)
        {
            assert(tail);
            ListNode* preHead = new ListNode(0);
            preHead->next = head;
            ListNode* pre = preHead;
            ListNode* cur = head;
            while(pre!=tail)
            {
                ListNode* nextNode = cur->next;
                cur->next = pre;
                pre = cur;
                cur = nextNode;
            }
            head->next = nullptr;
            delete preHead;
            return {tail,head};
        }
        ListNode* reverseKGroup(ListNode* head, int k) {
            ListNode* hair = new ListNode(0);
            ListNode* preHead = hair;
            preHead->next = head;
            ListNode* pre = preHead;
            ListNode* cur = head;
            while(cur)
            {
                int cnt = 1;
                ListNode* reverseHead = cur;
                ListNode* reverseTail = cur;
                while(reverseTail)
                {
                    reverseTail = reverseTail->next;
                    cnt++;
                    if(cnt==k)
                    {
                        break;
                    }
                }
                // std::cout<<"cnt= "<<cnt<<endl;
                if(!reverseTail)
                {
                    preHead->next = reverseHead;
                    return hair->next;//good design 
                }
                ListNode* nextNode = reverseTail->next;
                // std::cout<<reverseHead->val<<' '<<reverseTail->val<<endl;
                auto [newHead,newTail] = reverse(reverseHead,reverseTail);
                preHead->next = newHead;
                newTail->next = nextNode;
                preHead = newTail;
                cur = nextNode;
            }
            return hair->next;
        }
    };