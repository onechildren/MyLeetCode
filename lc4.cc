#include <bits/stdc++.h>
// 时间复杂度O(n)，代码看起来比较复杂，O(nlog(n))复杂度的代码可能就4、5行
double findMedianSortedArrays(std::vector<int>& nums1, std::vector<int>& nums2) {
    
    int size = nums1.size() + nums2.size();
    int num = size / 2;
    if((size & 0x1) == 0) {
       num--;
    }
    double ans = 0;
    int trans1 = 0, trans2 = 0;
    while(trans1 < nums1.size() && trans2 < nums2.size()) {
	if (num == 0) {
	   break;
	}
        if(nums1[trans1] < nums2[trans2]) {
	    trans1++;
	} else {
	    trans2++;
	}

	num--;
	if (num == 0) {
	   break;
	}
    }

    while(trans1 < nums1.size()) {
	if(num == 0) break;
	trans1++;
	num--;
	if(num == 0) break;
    }

    while(trans2 < nums2.size()) {
        if(num == 0) break;
	trans2++;
	num--;
	if(num == 0) break;
    }
    // 下面是根据数组的奇偶进一步获取最后结果
    if(trans1 < nums1.size() && trans2 < nums2.size()) {
       if((size & 0x1) == 1) {
          ans = nums1[trans1] < nums2[trans2] ? nums1[trans1] : nums2[trans2];
       } else {
	  // 这里需要注意，要从两个数组的前面4个数选择
	  int d1,d2;
	  if(nums1[trans1] < nums2[trans2]) {
	    d1 = nums1[trans1];
	    trans1++;
	    if(trans1 < nums1.size()) {
	       d2 = nums1[trans1] < nums2[trans2] ? nums1[trans1] : nums2[trans2];
	    } else {
	       d2 = nums2[trans2];
	    }
	  } else {
	    d1 = nums2[trans2];
	    trans2++;
	    if(trans2 < nums2.size()) {
	       d2 = nums1[trans1] < nums2[trans2] ? nums1[trans1] : nums2[trans2];
	    } else {
	       d2 = nums1[trans1];
	    }
	  }
   
	  ans = (d1 + d2) * 1.0 / 2;
       }
    } else if(trans1 < nums1.size()) {
       if((size & 0x1) == 1) {
          ans = nums1[trans1];
       } else {
	  ans = (nums1[trans1] + nums1[trans1 + 1]) * 1.0 / 2;
       }
       
    } else {
       if((size & 0x1) == 1) {
          ans = nums2[trans2];
       } else {
	  ans = (nums2[trans2] + nums2[trans2 + 1]) * 1.0 / 2;
       }
    }

    return ans;
}

int main() {
  int n,m;
  std::vector<int> vec1,vec2;
  while(std::cin >> n >> m) {
     while(n--) {
        int d;
	std::cin >> d;
	vec1.emplace_back(d);
     }
     while(m--) {
        int d;
	std::cin >> d;
	vec2.emplace_back(d);
     }
     std::cout << findMedianSortedArrays(vec1, vec2) << std::endl;
  }  
  return 0;
}	
