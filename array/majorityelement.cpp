#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int majority=0;
        int count=0;
        for(auto i: nums){
            if(!count){
                majority=i;
                count++;
            }
            else{
                if(majority==i){
                    count++;
                }
                else{
                    count--;
                }
            }
        }
        return majority;
    }
};
int main() {
    Solution solution;
    vector<int> nums = {3, 2, 3}; // Example input
    int majority = solution.majorityElement(nums);
    
    cout << "The majority element is: " << majority << endl; // Output the result
    
    return 0;
}
