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
    std::vector<std::string> binaryTreePaths(TreeNode *root)
    {
        std::vector<std::string> result;

        walk(root, {}, result);

        return result;
    }

private:
    void walk(TreeNode *node, std::string path, std::vector<std::string> &result)
    {
        path += std::to_string(node->val);

        if (not node->left and not node->right)
        {
            result.push_back(std::move(path));
            return;
        }

        path += "->";

        if (node->left)
        {
            walk(node->left, path, result);
        }

        if (node->right)
        {
            walk(node->right, path, result);
        }
    }
};
