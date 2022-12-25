package offer1

object offer10 {
    fun fib(n: Int): Int {
        val nums = mutableListOf<Int>(0, 1)
        if (n < 2) return nums[n]
        while (nums.size != n + 1) {
            nums.add((nums[nums.size - 2]+nums[nums.size - 1]) % (1000000007))
        }
        return nums[n]
    }
}