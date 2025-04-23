#include <bits/stdc++.h>
#include <regex>

// 去除左侧空格
inline void ltrim(std::string &s) {
    s.erase(s.begin(), std::find_if(s.begin(), s.end(), [](unsigned char ch) {
        return !std::isspace(ch);
    }));
}

// 去除右侧空格
inline void rtrim(std::string &s) {
    s.erase(std::find_if(s.rbegin(), s.rend(), [](unsigned char ch) {
        return !std::isspace(ch);
    }).base(), s.end());
}

// 去除两端空格
inline void trim(std::string &s) {
    ltrim(s);
    rtrim(s);
}
// 不使用long，使用正则表达式
int myAtoi(std::string s) {
   std::regex pattern(R"(^[ ]*([-+])?[0]*([1-9]+[0-9]*))");
   std::smatch match;
   std::regex_search(s, match, pattern);
   std::string flag = match[1].str();
   bool judge = false;
   if(flag.length() != 0 && flag[0] == '-') judge = true;

   std::string max = std::to_string(INT_MAX);
   std::string num = match[2].str();
   if(judge) {
      if(num.length() > max.length()) {
         return INT_MIN;
      } else if(num.length() == max.length()) {
         if(max < num) {
           return INT_MIN;
         }
      }
   } else if (!judge && max.length() <= num.length()) {
     if(max <= num || max.length() < num.length()) {
        return INT_MAX;
     }
   }
   if(judge) num = "-" + num;
   return std::atoi(num.c_str());
}

// 使用long
int myAtoi_backup(string str) {
	int len = str.length();
	int fuhao = ' ';
	int i = 0;
	long num = 0;
	int weishu = 0;
	while(i < len){
	    if(str[i] != ' ')
		break;
	    i++;
	}
	if(i == len) return 0;
	if(str[i] == '+' || str[i] == '-'){
	    fuhao = str[i];
	    i++;
	}else if(str[i] < '0' || str[i] > '9'){
	    return 0;
	}

	while(i < len){
	    if(str[i] != '0') break;
	    i++;
	}

	while(i < len){
	    if(str[i] >= '0' && str[i] <= '9'){
		weishu++;
		num = num * 10 + (int)(str[i] - 48);
		i++;
	    }else{
		break;
	    }
	    if(weishu > 10) break;
	}
	if(fuhao == '-') num = 0 - num;
	if(num > INT_MAX) return  INT_MAX;
	if(num < INT_MIN) return  INT_MIN;
	return num;
}

int main() {
  std::string s;
  while(std::cin >> s) {
     std::cout << myAtoi(s) << std::endl;
  }

  return 0;
}
