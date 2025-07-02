#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> st;
        int longest=0;
        for(auto i: nums){
            st.insert(i);
        }
        for(auto i: st){
            if(st.find(i-1)==st.end()){
                int count=1;
                int x=i;
                while(st.find(x+1)!=st.end()){
                    x=x+1;
                    count+=1;
                }
                longest=max(longest,count);

            }
        }
        return longest;
    }
};
int main() {
    Solution solution;
    vector<int> nums = {100, 4, 200, 1, 3, 2}; // Example input
    int longestSequence = solution.longestConsecutive(nums);
    
    cout << "The length of the longest consecutive sequence is: " << longestSequence << endl; // Output the result
    
    return 0;
}