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
        ListNode* mergeKLists(vector<ListNode*>& lists) 
        {
            class cmp
            {
            public:
                bool operator()(ListNode* node1,ListNode*node2)
                {
                    return node1->val>node2->val;
                }
            };
            priority_queue<ListNode*, vector<ListNode*>,cmp> pq;
            for(auto node:lists)
            {
                if(node!=nullptr)
                {
                    pq.push(node);
                    // std::cout<<node->val<<' ';
                }
                
            }
            // std::cout<<endl;
            ListNode* head = new ListNode(0);
            ListNode* pre = head;
            while(!pq.empty())
            {
                auto top = pq.top();
                pq.pop();
                // std::cout<<top->val<<' ';
                pre->next = top;
                pre = top;
                if(top->next!=nullptr)
                {
                    pq.push(top->next);
                }
            }
            return head->next;
        }
    };