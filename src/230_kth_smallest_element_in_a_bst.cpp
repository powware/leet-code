#include <vector>
#include <string>

#include <gtest/gtest.h>

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
public:
    int kthSmallest(TreeNode *root, int k)
    {
        int result = -1;
        walk(root, k, result);
        return result;
    }

private:
    void walk(TreeNode *node, int &k, int &result)
    {
        if (not node->left)
        {
            if (--k == 0)
            {
                result = node->val;
                return;
            }
        }
        else
        {
            walk(node->left, k, result);
            if (--k == 0)
            {
                result = node->val;
                return;
            }
        }

        if (node->right)
        {
            walk(node->right, k, result);
        }
    }
};
