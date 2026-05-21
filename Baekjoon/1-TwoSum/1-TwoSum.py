# Last updated: 2026. 5. 21. 오전 11:17:31
class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        hashmap = {}
        for i in range(len(nums)):
            hashmap[nums[i]] = i
        print(hashmap)
        for i in range(len(nums)):
            complement = target-nums[i]
            if complement in hashmap and hashmap[complement] != i:
                return [i,hashmap[complement]]
        return []