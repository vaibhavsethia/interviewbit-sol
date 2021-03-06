int Solution::sqrt(int A) {
    int begin = 0;
    int end = A;
    while(begin <= end){
        int mid = (begin + end) / 2;
        if (mid * mid == A) { 
            return mid;
        }
        else if (mid  > A / mid) {
            end = mid - 1;
        }
        else {
            begin = mid + 1;
        }
    }
    return end;
}
