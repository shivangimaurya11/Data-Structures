class Solution {
public:
    bool isPowerOfFour(int n) {
     if(n==0||n==1)
         return n;
        if(n%4!=0)
            return false;
        return isPowerOfFour(n/4);
    }
};