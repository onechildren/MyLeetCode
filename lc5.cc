#include<bits/stdc++.h>

// 中心扩展法
int expand(const std::string& s, int l, int r) {
    while(l >= 0 && r < s.length() && s[l] == s[r]) {
       --l;
       ++r;
    }
    // 这里需要注意边界问题处理
    return r - l - 1;
}
std::string longestPalindrome(std::string s) {
   int len = s.length();
   int m = 0, index = 0;
   for (int i = 0; i < len; ++i) {
     int l1 = expand(s, i, i);
     int l2 = expand(s, i, i + 1);
     if(std::max(l2, l1) > m) {
        index = i - (std::max(l2, l1) - 1) / 2;
	m = std::max(l2, l1);
     }
   }

   return s.substr(index, m);
}


// DP
std::string longestPalindrome_dp(std::string s) {
   int len = s.length();
   int max = 1, index = 0;
   std::vector<std::vector<std::uint8_t>> dp = std::vector<std::vector<std::uint8_t>>(len, std::vector<std::uint8_t>(len, 0)); 
   for (int i = 0; i < len; ++i) {
      dp[i][i] = 1;
      if(i + 1 < len && s[i] == s[i+1]) {
          dp[i][i+1] = 1;
	  max = 2;
	  index = i;
      }
   }

   for(int i = 3; i <= len; i++) {
      for(int j = i - 1; j < len; j++) {
          if(s[j] == s[j - i + 1] && dp[j-i+2][j-1] == 1) {
	     max = i;
	     index = j - i + 1;
             dp[j-i+1][j]=1;
	  }
      }
   }

   return s.substr(index, max);
 }

int main() {
  std::string s;
  while(std::cin >> s) {
     std::cout << longestPalindrome_dp(s) << std::endl;
     // std::cout << longestPalindrome(s) << std::endl;
  }
  return 0;
}
