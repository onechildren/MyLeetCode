#include <bits/stdc++.h>

std::vector<int> twoSum(std::vector<int>& nums, int target) {
   // key, index
   std::unordered_map<int, int> map;
   for(int i = 0; i < nums.size(); ++i) {
       if(0 != map[target - nums[i]]) {
           return std::vector<int>{map[target -nums[i]] - 1, i};
       }

       map[nums[i]] = i + 1;
   }

   return std::vector<int>{};
}

int main() 
{
   std::vector<int> vec;
   int n,data,sum;
   while(true) {
	   std::cin >> n;
	   while(n-- && std::cin >> data) vec.emplace_back(data);
	   std::cin >> sum;
	   auto b = twoSum(vec, sum);
	   if(b.size() == 0) {
	      std::cout << "no data" << std::endl;
	      return 0;
	   }
	   for(auto i: b) {
	      std::cout << i << " ";
	   }
	   std::cout << std::endl;
   }
}
