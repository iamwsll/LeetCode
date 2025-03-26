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
        //cursum:从root到当前节点(包括当前节点)路径上的总和.
        //sum:sum[i]表示,在root到当前节点上的所有点中,cursum为i的节点数目.
        //ret:以当前节点/当前节点子树的节点 为结尾的路径 和等于targetsum
        unordered_map<long long ,int > sum;
        int dfs(TreeNode* root,long long curSum,int targetSum)
        {
            if(!root)return 0;
    
            int ret = 0;
            curSum+=root->val;
            if(sum.contains(curSum-targetSum))
            {
                ret+=sum[curSum-targetSum];
            }
            sum[curSum]++;
            ret+=dfs(root->left,curSum,targetSum);
            ret+=dfs(root->right,curSum,targetSum);
            sum[curSum]--;
            return ret;
        }
        int pathSum(TreeNode* root, int targetSum) 
        {
            sum[0] = 1;
            return dfs(root,0,targetSum);   
        }   
    };