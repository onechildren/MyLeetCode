#include<bits/stdc++.h>

std::string convert(std::string s, int numRows) {
    int len = s.length();
    std::vector<std::string> vec(numRows);
    int j = 0, row = 0;
    while(j < len) {
        while(j < len && row < numRows) {
        vec[row].push_back(s[j++]);
        row++;
        }
        row = numRows - 2;
        while(j < len && row > 0) {
        vec[row].push_back(s[j++]);
        row--;
        }
        row = 0;
    }
    std::string ans;
    for(const auto & d : vec) {
        ans += d;
    }
    return ans;
}

int main() {  
  std::string s;
  int n;
  while(std::cin >> n >> s) {
      std::cout << convert(s, n);
  }

}
