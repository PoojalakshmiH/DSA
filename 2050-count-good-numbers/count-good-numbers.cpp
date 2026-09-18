class Solution {
public:
     long long mod=1000000007;
    long long power(long long x,long long power)
    {
        long long binform=power;
        long long ans=1;

        while(binform>0)
        {
            if(binform%2==1)
            {
                ans=(ans*x)%mod;
            }
            x=(x*x)%mod;
            binform/=2;
        }
        return ans;
    }
    int countGoodNumbers(long long n) {
        
        long long evenpos=(n+1)/2;
        long long oddpos=n/2;

        long long evenstring=power(5,evenpos)%mod;
        long long oddstring=power(4,oddpos)%mod;

        int ans=(evenstring*oddstring)%mod;
        return ans;
    }
};