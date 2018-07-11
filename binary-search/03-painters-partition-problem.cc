bool allocateBoards(vector<int>& boards, int nPainters, int maxBoardLength){
    int curPainter = 1;
    int curBoardLength = 0;

    for(int i = 0; i < boards.size(); ++i){
        int curLen = boards[i];
        if (curBoardLength + curLen <= maxBoardLength){
            curBoardLength += curLen;
        }
        else {
            if (curLen > maxBoardLength) return false;
            ++curPainter;
            if (curPainter > nPainters) return false;
        }
    }
    return true;
}
int Solution::paint(int K, int T, vector<int> &C) {
    int minBoardsToPaint = 0;
    int maxBoardsToPaint = accumulate(C.begin(), C.end(), 0);
    long long int bestAns = INT_MAX;

    while (minBoardsToPaint <= maxBoardsToPaint) {
        int guess = (minBoardsToPaint + maxBoardsToPaint) / 2;
        bool success = allocateBoards(C, K, guess);
        if (success) {
            bestAns = guess;
            maxBoardsToPaint = guess - 1;
        }
        else {
            minBoardsToPaint = guess + 1;
        }
    }
    const int mod = 10000003;
    bestAns = ((bestAns % mod) * (T % mod)) % mod;
    return bestAns;
}
