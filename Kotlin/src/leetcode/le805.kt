import java.util.*

class le805 {
    var sumA = 0
    var lenA = 0
    var avg = 0.0
    var Edavg = 0.0

    fun splitArraySameAverage(nums: IntArray): Boolean {
        Arrays.sort(nums) // sort
        val sum = Arrays.stream(nums).sum()
        Edavg = sum.toDouble() / nums.size
        for (i in nums.size / 2 downTo 1) {
            if (sum * i % nums.size == 0) {
                if (sp_dfs(nums, i, 0, sum, nums.size, 0, 0)) {
                    return true
                }
            }
        }
        return false
    }

    // dfs
    fun sp_dfs(nums: IntArray, k: Int, start: Int, sum: Int, len: Int, sum1: Int, len1: Int): Boolean {
        if (len1 == k) {
            avg = sum1.toDouble() / len1
            if (Edavg != avg) return false
            if (avg == sum.toDouble() / len) {
                return true
            }
        }
        var i = start
        while (i < nums.size) {
            sumA += nums[i]
            lenA += 1
            if (sp_dfs(nums, k, i + 1, sum - nums[i], len - 1, sumA, lenA)) {
                return true
            }
            sumA -= nums[i]
            lenA--
            if (lenA == k - 1) {
                if ((sumA + nums[nums.size - 1]).toDouble() / (lenA + 1) < Edavg) {
                    i = nums.size - 1
                    i++
                    continue
                }
                while (i + 1 < nums.size && (sumA + nums[i + 1]).toDouble() / (lenA + 1) != Edavg) {
                    i++
                }
            }
            while (i + 1 < nums.size && nums[i] == nums[i + 1]) {
                i++
            }
            i++
        }
        return false
    }
}