package leetcode

class le1752 {
    fun check(nums: IntArray): Boolean {
        // 阅读理解题
        var count = 0
        for (i in nums.indices) {
            if (nums[i] > nums[(i + 1) % nums.size]) {
                count++
            }
        }
        return count <= 1
    }
}