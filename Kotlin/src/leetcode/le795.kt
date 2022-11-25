package leetcode

class le795 {
    fun numSubarrayBoundedMax(nums: IntArray, left: Int, right: Int): Int {
        var j = -1
        var tmp = 0
        var ans = 0
        for (i in nums.indices) {
            if (nums[i] > right) j = i
            if (nums[i] >= left) tmp = i - j
            ans += tmp
        }
        return ans
    }
}