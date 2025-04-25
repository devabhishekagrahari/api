#include <vector>
#include<iostream>
#include <cstdio>
#include <unordered_map>
using namespace std;

vector<vector<int>> twoSum(vector<int>& nums, int target) {
    unordered_map<int, int> mp;
    vector<vector<int>> res;  // value -> index
    for (int i = 0; i < nums.size(); i++) {
        int diff = target - nums[i];
        if (mp.find(diff) != mp.end()) {
            res.push_back({mp[diff], i});
        }
        mp[nums[i]] = i;
    }
    return res; // No solution found
}

int main(){
    vector<int> nums={1,1,1,2,2,3,3,4,5};
    int target=6;
    vector<vector<int>> result=twoSum(nums,target);
    for (const auto& pair : result){
        cout<< "{"<<pair[0]<< pair[1]<<"}"<<endl;
    }
}