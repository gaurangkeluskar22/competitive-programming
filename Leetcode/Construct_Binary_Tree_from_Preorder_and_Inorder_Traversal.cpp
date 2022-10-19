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
    int index = 0;
    TreeNode* construct(vector<int>& preorder, vector<int>& inorder, int inOrderStart, int inOrderEnd){
        
        // Base case
        if(index >= preorder.size() || inOrderStart > inOrderEnd){
            return NULL;
        }
        
        int element = preorder[index++];
        TreeNode *root = new TreeNode(element);
        int pos = find(inorder.begin(), inorder.end(), element) - inorder.begin(); 
        
        // Recursion
        root->left = construct(preorder, inorder, inOrderStart, pos-1);
        root->right = construct(preorder, inorder, pos+1, inOrderEnd);
        
        return root;
    }
    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        TreeNode* tree = construct(preorder, inorder, 0, preorder.size()-1);
        return tree;
    }
};
