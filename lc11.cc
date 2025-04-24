#include <bits/stdc++.h>

int maxArea(std::vector<int>& height) {
  int l = 0, r = height.size() - 1;
  int ans = 0;

  while(l < r) {
     // 不是动左边就是动右边
     ans = height[l] > height[r] ?
     std::max(ans, (r - l) * height[r--]):
     std::max(ans, (r - l) * height[l++]);
  }
  return ans;
}


int main() {
   while(true) {
     int num, d;
     std::cin >> num;
     std::vector<int> vec;
     while(num--) {
       std::cin >> d;
       vec.emplace_back(d);
     }

     std::cout <<  maxArea(vec);
   }
   return 0;
}
