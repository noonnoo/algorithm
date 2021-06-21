#include <algorithm>
using namespace std;
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
    int max_depth = 0;
    
    int maxDepth(TreeNode* root) {
        if(root != NULL)
            DFS(root, 1);
        
        return max_depth;
    }
    
    void DFS(TreeNode* cur, int depth){
        max_depth = max(depth, max_depth);
        
        if(cur->left != NULL)
            DFS(cur->left, depth+1);
        if(cur->right != NULL)
            DFS(cur->right, depth+1);
    }
};
