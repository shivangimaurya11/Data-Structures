class Solution {
public:
    bool isPalindrome(int x) {
        long rev=0;
        long n=x;
        if(x<0)
            return false;
            while(n!=0)
        {
            int d=n%10;
            n=n/10;
            rev=rev*10+d;
            
        }
        if(rev==x)
            return true;
        else
            return false;
    }
};