package offer1

object offer03 {
    fun findRepeatNumber(nums: IntArray): Int {
        val numSet = mutableSetOf<Int>()
        for (i in nums) {
            if (!numSet.add(i)) return i else numSet.add(i)
        }
        return 0
    }
    fun old_findRepeatNumber(nums: IntArray): Int {
        for (i in nums.indices) {
            for (j in i + 1..nums.size) {
                if (nums[i] == nums[j]) return nums[i]
            }
        }
        return 0
    }
}