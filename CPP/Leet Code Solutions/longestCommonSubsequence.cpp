int longestCommonSubsequence(string ta, string tb) {
        int dp[1001][1001];
        for(int i=1; i<=ta.length(); i++) {
            for(int j=1; j<=tb.length(); j++) {
                if(ta[i-1] == tb[j-1]) {
                    dp[i][j] = dp[i-1][j-1]+1;
                } else {
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                }
            }
        }
        return dp[ta.length()][tb.length()];
    }
