int Solution::searchMatrix(vector<vector<int> > &A, int B) {
    int colSize = A[0].size();
    int rowSize = A.size();

    int row = 0;
    while(row < rowSize) {
        if (A[row][colSize-1] >= B) break;
        ++row;
    }
    
    if (row == rowSize) return 0;
    return  binary_search(A[row].begin(), A[row].end(), B);
}
