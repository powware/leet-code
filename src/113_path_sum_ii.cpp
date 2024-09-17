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
    std::vector<std::vector<int>> pathSum(TreeNode *root, int targetSum)
    {
        std::vector<std::vector<int>> result;
        if (root)
        {
            walk(root, 0, targetSum, {}, result);
        }
        return result;
    }

private:
    void walk(TreeNode *node, int sum, int target, std::vector<int> path, std::vector<std::vector<int>> &result)
    {
        sum += node->val;
        path.push_back(node->val);

        if (not node->left and not node->right)
        {
            if (sum == target)
            {
                result.push_back(std::move(path));
            }
            return;
        }

        if (node->left)
        {
            walk(node->left, sum, target, path, result);
        }

        if (node->right)
        {
            walk(node->right, sum, target, path, result);
        }
    }
};
