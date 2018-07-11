enum state { REDUCE_PAGES, SUCCESS, INCREASE_PAGES };

state simulateAllocation(vector<int>& books, int nStudents, int maxPages){
    int curStudent = 1;
    int pagesAllocatedSoFar = 0;
    
    for(int i = 0; i < books.size(); ++i){
        int pagesInCurrentBook = books[i];
        if (pagesInCurrentBook + pagesAllocatedSoFar <= maxPages){
            pagesAllocatedSoFar += pagesInCurrentBook;
        }
        else {
            if (pagesInCurrentBook > maxPages) return INCREASE_PAGES;
            curStudent++;
            pagesAllocatedSoFar = pagesInCurrentBook;
            if (curStudent > nStudents){
                return INCREASE_PAGES;
            }
        }
    }

    if (curStudent < nStudents){ return REDUCE_PAGES; }
    return SUCCESS;
}


int Solution::books(vector<int> &A, int nStudents) {
    if (nStudents > A.size()) return -1;

    int minVal = 0;
    int maxVal = accumulate(A.begin(), A.end(), 0);
    int bestAns = -1;

    while(minVal <= maxVal){
        int guess = (minVal + maxVal) / 2;

        state status = simulateAllocation(A, nStudents, guess);

        if (status == SUCCESS){
            bestAns = guess;
            maxVal = guess - 1;
        }
        else if (status == INCREASE_PAGES){
            minVal = guess + 1;
        }
        else if (status == REDUCE_PAGES){
            bestAns = guess;
            maxVal = guess - 1;
        }
    }
    return bestAns;
}
