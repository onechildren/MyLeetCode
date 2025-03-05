#include <bits/stdc++.h>
/*
主要思路就是根据二进制的特点，根据二进制的位数+1
*/
class Solution {
    public:
        std::vector<int> grayCode(int n) {
            std::vector<int> ans{0};
            int i = 1;
    
            while(i <= n) {
                for(int j = ans.size() - 1; j >= 0; --j) {
                    ans.push_back((1u << (i - 1)) | ans[j]);
                }
                i++;
            }
            return ans;
    
        }
    };