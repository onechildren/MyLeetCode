#include<bits/stdc++.h>
int reverse(int x) {
  bool flag = false;
  if(x < 0) {
     flag = true;
  }

  std::string data = std::to_string(x);
  std::string max = std::to_string(INT_MAX);

  std::reverse(data.begin(), data.end());
  // 删除符号
  if(flag) data.pop_back();
  if(data.length() == max.length() && max < data) return 0;
  return flag ? 0 - std::atoi(data.c_str()) : std::atoi(data.c_str());
}

int main() {
   int data;
   while(std::cin >> data) {
       std::cout << reverse(data) << std::endl;
   }
   return 0;
}
