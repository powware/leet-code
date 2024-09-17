#include <vector>
#include <queue>

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
    std::vector<std::vector<int>> levelOrder(TreeNode *root)
    {
        std::vector<std::vector<int>> result;
        std::queue<std::pair<std::size_t, TreeNode *>> next;

        if (root)
        {
            next.emplace(0, root);
        }

        while (not next.empty())
        {
            auto [level, node] = next.front();
            next.pop();
            if (level >= result.size())
            {
                result.push_back({node->val});
            }
            else
            {
                result[level].push_back(node->val);
            }

            ++level;

            if (node->left)
            {
                next.emplace(level, node->left);
            }
            if (node->right)
            {
                next.emplace(level, node->right);
            }
        }

        return result;
    }
};
