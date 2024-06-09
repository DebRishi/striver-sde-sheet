#include <iostream>
#include <queue>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Codec {
public:

    string serialize(TreeNode* root) {
        string ans = "";
        if (!root)
            return ans;
        queue<TreeNode*> queue;
        queue.push(root);
        while (!queue.empty()) {
            auto node = queue.front();
            queue.pop();
            if (node == NULL)
                ans += "NULL,";
            else {
                ans += to_string(node->val) + ",";
                queue.push(node->left);
                queue.push(node->right);
            }
        }
        ans.pop_back();
        return ans;
    }

    vector<string> split(string& str, string del = " ") {
        vector<string> ans;
        int beg = 0;
        int end = str.find(del);
        while (end != -1) {
            ans.push_back(str.substr(beg, end-beg));
            beg = end + del.size();
            end = str.find(del, beg);
        }
        ans.push_back(str.substr(beg));
        return ans;
    }

    TreeNode* deserialize(string data) {
        if (data == "")
            return NULL;
        vector<string> strs = split(data, ",");
        TreeNode* root = new TreeNode(stoi(strs[0]));
        queue<TreeNode*> queue;
        queue.push(root);
        int idx = 1;
        while (idx < strs.size()) {
            TreeNode* node = queue.front();
            queue.pop();
            if (strs[idx] != "NULL") {
                TreeNode* lnode = new TreeNode(stoi(strs[idx]));
                node->left = lnode;
                queue.push(lnode);
            }
            idx++;
            if (strs[idx] != "NULL") {
                TreeNode* rnode = new TreeNode(stoi(strs[idx]));
                node->right = rnode;
                queue.push(rnode);
            }
            idx++;
        }
        return root;
    }
};