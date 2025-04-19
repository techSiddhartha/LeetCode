class Solution {
public:
    int numDecodings(string s) {
       if(s.empty()|| s[0]=='0') return 0;

       int n=s.size();
       vector<int> dp(n+1,0);
       dp[0]=1;
       dp[1]=1;

       for(int i=2;i<=n;i++){

        int Onenum = s[i-1]-'0';
        if(Onenum!=0) dp[i]+=dp[i-1];

        int Twonum=stoi(s.substr(i-2,2));
        if(Twonum>=10&&Twonum<=26)  dp[i]+=dp[i-2];
       }
       return dp[n];
    }
};