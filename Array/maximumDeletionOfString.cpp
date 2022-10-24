class Solution:
    def deleteString(self, s: str) -> int:
        dp = [1] * (len(s) + 1)
        for start in reversed(range(len(s))):
            for end in range(start + 1, len(s)):
                if s[start:end] == s[end:end + (end - start)]:
                    dp[start] = max(dp[start], dp[end] + 1)
        return dp[0]
