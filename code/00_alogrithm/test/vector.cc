#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
};

class Solution
{
public:
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
    {
        if (preorder.size() == 0)
            return NULL;

        TreeNode *root = new TreeNode();
        buildRoot(preorder, 0, preorder.size(), inorder, 0, inorder.size(), root);
        return root;
    }

    /**
    * 左闭右开
    **/
    void buildRoot(vector<int> &preorder, int preorder_begin, int preorder_end, vector<int> &inorder, int inorder_begin, int inorder_end, TreeNode *node)
    {
        cout << "======================\n";
        print(preorder, preorder_begin, preorder_end);
        print(inorder, inorder_begin, inorder_end);
        cout << "======================\n\n";
        if (preorder_begin == preorder_end)
            return;
        node->val = preorder[preorder_begin];
        node->left = NULL;
        node->right = NULL;
        if ((preorder_begin + 1) == preorder_end)
            return;

        int inorder_index = find(inorder.begin() + inorder_begin, inorder.begin() + inorder_end, node->val) - inorder.begin();
        if (inorder_begin != inorder_index)
        {
            TreeNode *leftNode = new TreeNode();
            node->left = leftNode;
            int val = inorder[inorder_index - 1];
            int preorder_index = find(preorder.begin() + preorder_begin, preorder.begin() + preorder_end, val) - preorder.begin();
            buildRoot(preorder, preorder_begin + 1, preorder_index + 1, inorder, inorder_begin, inorder_index, leftNode);
        }
        if ((inorder_end - 1) != inorder_index)
        {
            TreeNode *rightNode = new TreeNode();
            node->right = rightNode;
            int num = inorder_end - inorder_index - 1;
            buildRoot(preorder, preorder_end - num, preorder_end, inorder, inorder_index + 1, inorder_end, rightNode);
        }
    }

    void print(vector<int> &v, int begin, int end)
    {
        for (int i = begin; i < end; i++)
        {
            cout << v[i] << " ";
        }
        cout << endl;
    }
};

int main()
{
    vector<int> pre = {1, 2, 3};
    vector<int> ino = {3, 2, 1};
    Solution s;
    s.buildTree(pre, ino);
}