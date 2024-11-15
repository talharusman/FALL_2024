#include <iostream>
#include <vector>
#include <queue>
using namespace std;

#include <iostream>

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Tree {
    
    TreeNode* root;

    // Helper function to insert a node
    void insertNode(TreeNode*& node, int val) {
        if (node == NULL) {
            node = new TreeNode(val);
        } else if (val < node->val) {
            insertNode(node->left, val);
        } else {
            insertNode(node->right, val);
        }
    }
    public:
    Tree() : root(NULL) {}

    void insert(int val) {
        insertNode(root, val);
    }
    void inOrderTraversal(TreeNode* node) {
        if (node != NULL) {
            inOrderTraversal(node->left);
            std::cout << node->val << " ";
            inOrderTraversal(node->right);
        }
    }
    void printInOrder() {
        inOrderTraversal(root);
        std::cout << std::endl;
    }

    TreeNode* getRoot(){
        return root;
    }

    void friend zigzagLevelOrder(TreeNode* root);

};



void zigzagLevelOrder(TreeNode* root) {
    if (!root) return;

    queue<TreeNode*> q;
    q.push(root);
    bool flag = true; 

    while (!q.empty()) {
        int size = q.size();
        vector<int> level;

        for (int i = 0; i < size; i++) {
            TreeNode* node = q.front();
            q.pop();
            if (flag) {
                level.push_back(node->val);
            } else {
                level.insert(level.begin(), node->val); 
            }

            if (node->left) q.push(node->left);
            if (node->right) q.push(node->right);
        }

        for (int val : level) {
            cout << val << " ";
        }
        cout << endl;
        flag = !flag;
    }
}

int main() {
    Tree tree;
    tree.insert(10);
    tree.insert(5);
    tree.insert(15);
    tree.insert(3);
    tree.insert(7);
    tree.insert(12);
    tree.insert(18);

    zigzagLevelOrder(tree.getRoot());




    return 0;
}
