package leetcode

import java.util.*

class le891 {
    var mod = 1e9.toInt() + 7
    fun sumSubseqWidths(nums: IntArray): Int {
        Arrays.sort(nums) // 排序后方便取左右边界
        val len = nums.size
        var ans: Long = 0
        var pow: Long = 1 // index 位置的幕
        for (index in 0 until len) {
            ans = (ans + pow * (nums[index] - nums[len - 1 - index] + mod)) % mod
            pow = pow * 2 % mod
        }
        return ans.toInt()
    }
}