/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
    public:
        void flatten(TreeNode* root) 
        {
            TreeNode* cur = root;
            while(cur)
            {
                if(cur->left)
                {
                    TreeNode* preNode = cur->left;
                    while(preNode->right)
                    {
                        preNode = preNode->right;
                    }
                    preNode->right = cur->right;
                    cur->right = cur->left;
                    cur->left = nullptr;
                }
                //一直right的话,就是在遍历左子树结束之后,恰好由于preNode的right是右子树的根,从而能做到把右子树也处理一下
                cur = cur->right;
            }
        }
    };