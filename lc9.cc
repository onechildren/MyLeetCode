#include<bits/stdc++.h>

bool isPalindrome(int x) {
  std::string s = to_string(x);
  int l = 0, r = s.length() - 1;
  while(l < r) {
      if(s[l] != s[r]) {
          return false;
      }
      ++l;
      --r;
  }
  return true;
}

int main() {
  int d;
  while(std::cin >> d) {
     if(isPalindrome(d)) {
       std::cout << "这是回文串"  << std::endl;
     } else {
       std::cout << "这不是回文串"  << std::endl;
     }
  }
}
