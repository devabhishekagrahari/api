#include<iostream> 
#include<cstdio>
#include<unordered_set>
using namespace std; 
 
int countSubStringMax(string str){

int left = 0, right = 0;
int count=0;
   unordered_set<char> window;
   int n=str.length();
   while(right<n){
      while(window.find(str[right])!= window.end()){
        window.erase(str[left]);
        left++;
      }
      window.insert(str[right]);
      count+= right- left+1;
      
      right++;
   }
   return count;
}
int main() {
    string testStr = "abcdddddddddd";
    cout << "Count of substrings with all unique characters: " << countSubStringMax(testStr) << endl;
    return 0;
}