class Solution {
public:
    long long waysToBuyPensPencils(int total, int cost1, int cost2) {
        long long loop=total/cost1;
        long long count=0;
        for(long i=0;i<=loop;i++)
        {
            if(i==0)
                count+=(total/cost2)+1;
            else
            {
                int rem=total-(i*cost1);
                count+=rem/cost2+1;
            }
        }
        return count;
    }
};