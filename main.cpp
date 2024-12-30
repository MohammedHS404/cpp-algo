#include <iostream>
#include "queue"


struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
    TreeNode *CreateBinaryTree(int arr[], int n);
    void PrintTree(TreeNode *root);
};


main()
{
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);
    root->left->left->left = new TreeNode(8);
    root->left->left->right = new TreeNode(9);

    std::queue<TreeNode *> q;

    q.push(root);

    while (q.size() > 0)
    {
        int stackSize = q.size();

        for (int i = 0; i < stackSize; i++)
        {
            TreeNode *current = q.front();
            q.pop();

            std::cout << current->val << " ";

            if (current->left != nullptr)
            {
                q.push(current->left);
            }

            if (current->right != nullptr)
            {
                q.push(current->right);
            }
        }

        std::cout << std::endl;
    }

    return 0;
}