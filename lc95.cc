#include <bits/stdc++.h>
/*
利用二叉搜索树特點进行分治递归
*/
class Solution {
    public:
        vector<TreeNode*> myfunc(int start, int end) {
            vector<TreeNode*> ans;
            if(start == end) {
                TreeNode* root = new TreeNode(start);
                ans.push_back(root);
                return ans;
            }
    
            for(int i = start; i <= end; ++i) {
                vector<TreeNode*> left = myfunc(start, i - 1);
                vector<TreeNode*> right = myfunc(i + 1, end);
                if(left.empty()) {
                    for(TreeNode* it : right) {
                        TreeNode* root = new TreeNode(i);
                        root->right = it;
                        ans.push_back(root);
                     }
                } else if (right.empty()) {
                    for(TreeNode* it : left) {
                        TreeNode* root = new TreeNode(i);
                        root->left = it;
                        ans.push_back(root);
                    }
                } else {
                    for(int p = 0; p < left.size(); ++p) {
                        for(int j = 0; j < right.size(); ++j) {
                            TreeNode* root = new TreeNode(i);
                            root->left = left[p];
                            root->right = right[j];
                            ans.push_back(root);
                        }
                    }
                }
             }
        return ans;
    }

    vector<TreeNode*> generateTrees(int n) {
        return myfunc(1, n);
    }
    };