// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


 // } Driver Code Ends
class Solution{
    public:
     void TOH(int n, int s, int d, int h, long long &cnt){
       if(n==0){
           return;
       }
       TOH(n-1,s,h,d,cnt);
       cout<<"move disk "<<n<<" from rod "<<s<<" to rod "<<d<<endl;
       cnt++;
       TOH(n-1,h,d,s,cnt);
   }
   
   long long toh(int N, int from, int to, int aux) {
       long long cnt = 0;
       TOH(N,from,to,aux,cnt);
       return cnt;
   }

};

// { Driver Code Starts.

int main() {

    int T;
    cin >> T;//testcases
    while (T--) {
        
        int N;
        cin >> N;//taking input N
        
        //calling toh() function
        Solution ob;
        
        cout << ob.toh(N, 1, 3, 2) << endl;
    }
    return 0;
}


//Position this line where user code will be pasted.  // } Driver Code Ends