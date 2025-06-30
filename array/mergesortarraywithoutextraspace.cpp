#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i=m-1;
        int j=0;
        while(i>=0&&j<n){
            if(nums1[i]>nums2[j]){
                swap(nums1[i],nums2[j]);
                i--,j++;
            }
            else{
                break;
            }
        }
        sort(nums1.begin(),nums1.end()); 
        sort(nums2.begin(),nums2.end());
        nums1.insert(nums1.end(), nums2.begin(), nums2.end());
    }
};
int main() {
    Solution solution;
    vector<int> nums1 = {1, 3, 5, 7};
    vector<int> nums2 = {2, 4, 6, 8};
    int m = nums1.size();
    int n = nums2.size();
    
    solution.merge(nums1, m, nums2, n);
    
    for (int num : nums1) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}