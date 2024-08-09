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
    int zigzag_length=0;

    void dfs(TreeNode* current, bool isLeft, int length){
        if(current == nullptr) return;

        zigzag_length = max(zigzag_length, length);

        if(isLeft){
            dfs(current->left, false, length + 1);

            dfs(current->right, true, 1);

        }
        else{
            dfs(current->right, true, length+1);
            dfs(current->left, false, 1);
        }

    }
    int longestZigZag(TreeNode* root) {
        dfs(root, true, 0);
        dfs(root, false, 0);
        return zigzag_length;
    }
};