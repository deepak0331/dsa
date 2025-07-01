#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
       int hare=0;
       int tortoise=0;
       do{
        hare=nums[nums[hare]];
        tortoise=nums[tortoise];
       }while(tortoise!=hare);
       int intersection=hare;
       int start=0;
       while(start!=intersection){
        start=nums[start];
        intersection=nums[intersection];
       }
       return intersection;
    }
};

int main() {
    Solution solution;
    vector<int> nums = {1, 3, 4, 3,2}; // Example input with a duplicate
    int duplicate = solution.findDuplicate(nums);
    
    cout << "The duplicate number is: " << duplicate << endl; // Output the result
    
    return 0;
}