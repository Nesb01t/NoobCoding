package leetcode

import kotlin.math.abs

class le775 {
    fun isIdealPermutation(nums: IntArray): Boolean {
        for (i in nums.indices) { // Kotlin 遍历int数组
            if (abs(nums[i] - i) > 1) { // 核心代码, 判断是否有连续2次倒置情况出现即可
                return false
            }
        }
        return true
    }
}