#include<bits/stdc++.h>
int lengthOfLongestSubstring(std::string s) {
   int l = 0, r = 0;
   int trans = 0;
   std::map<char, int> vec;
   int ans = 0;
   while(trans < s.length()) {
      while(trans < s.length() && vec[s[trans]] == 0) {
          trans++;
	  vec[s[trans - 1]] = trans;
	  r = trans;
      }
      ans = ans > r - l ? ans : r - l;
      
      while(l < r && s[l] != s[trans]) {
         vec[s[l]] = 0;
	 l++;
      }

      if(s[l] == s[trans]) {
         vec[s[l]] = 0;
	 l++;
      }
   } 
   return ans;
}
int main() {
   std::string s;
   while(std::cin >> s) {
      std::cout << s << " : " << lengthOfLongestSubstring(s) << std::endl;
   }
   return 0;
}
