#include <vector>
#include <map>

#include <gtest/gtest.h>

class Node
{
public:
    int val;
    std::vector<Node *> neighbors;
    Node()
    {
        val = 0;
        neighbors = std::vector<Node *>();
    }
    Node(int _val)
    {
        val = _val;
        neighbors = std::vector<Node *>();
    }
    Node(int _val, std::vector<Node *> _neighbors)
    {
        val = _val;
        neighbors = _neighbors;
    }
};

class Solution
{
public:
    Node *cloneGraph(Node *node)
    {
        std::map<int, Node *> clones;
        return CloneNode(node, clones);
    }

private:
    Node *CloneNode(Node *node, std::map<int, Node *> &clones)
    {
        if (!node)
        {
            return nullptr;
        }

        auto clone = new Node(node->val);
        clones[clone->val] = clone;
        for (auto neighbor : node->neighbors)
        {
            auto cache = clones[neighbor->val];
            if (cache)
            {
                clone->neighbors.push_back(cache);
            }
            else
            {

                clone->neighbors.push_back(CloneNode(neighbor, clones));
            }
        }

        return clone;
    }
};