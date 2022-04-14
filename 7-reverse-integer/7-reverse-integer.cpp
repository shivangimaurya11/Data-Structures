class Solution {
public:
    int reverse(int x) {
        long long num=abs(x);
        long long rev=0;
        while(num!=0)
        {
            if(rev>INT_MAX/10 || rev<INT_MIN/10)
                return 0;
            int d=num%10;
            rev=rev*10+d;
            num=num/10;
        }
        if(x>0)
            return rev;
        else
            return -rev;
    }
};