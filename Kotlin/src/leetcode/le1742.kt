package leetcode

class le1742 {
    fun countBalls(lowLimit: Int, highLimit: Int): Int {
        val box = IntArray(100)
        var ans = 0
        for (i in lowLimit..highLimit) {
            var index = 0
            var x = i
            while (x != 0) {
                index += x % 10
                x /= 10
            }
            if (++box[index] > ans) ans = box[index]
        }
        return ans
    }
}