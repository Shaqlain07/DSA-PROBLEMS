import math


class Solution:
    def subarrayGCD(self, nums: List[int], k: int) -> int:
        sol = 0
        for i in range(len(nums)):
            curr = 0
            for j in range(i, len(nums)):
                curr = math.gcd(curr, nums[j])
                sol += curr == k

        return sol
