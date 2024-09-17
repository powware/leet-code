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
    int maxPathSum(TreeNode *root)
    {
        std::optional<int> max;
        walk(root, max);
        return *max;
    }

private:
    int walk(TreeNode *node, std::optional<int> &max)
    {
        int left = 0, right = 0;
        if (node->right)
        {
            right = std::max(walk(node->right, max), 0);
        }
        if (node->left)
        {
            left = std::max(walk(node->left, max), 0);
        }

        int root = left + node->val + right;

        if (not max or root > *max)
        {
            max = root;
        }

        return std::max(left + node->val, node->val + right);
    }
};
