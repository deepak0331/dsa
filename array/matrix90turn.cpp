#include<bits/stdc++.h>
using namespace std;
#include<vector>
void rotatematrix(vector<vector<int>>& matrix) {
    int n = matrix.size();
    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            swap(matrix[i][j], matrix[j][i]);
        }
    }
    for(int i=0;i<n;i++){
        reverse(matrix[i].begin(), matrix[i].end());
    }
}


int main() {
    vector<vector<int>> matrix = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };
    
    rotatematrix(matrix);
    
    for(const auto& row : matrix) {
        for(int val : row) {
            cout << val << " ";
        }
        cout << endl;
    }
    
    return 0;
}