package leetcode

class le878 {
    fun nthMagicalNumber(n: Int, a: Int, b: Int): Int {
        if (a % b == 0) return (n.toLong() * b % 1000000007).toInt()
        if (b % a == 0) return (n.toLong() * a % 1000000007).toInt()

        // 取最大公倍数
        var p = a
        var i = 1
        while (p * i % b != 0) i++
        p *= i

        // 二分答案
        var l: Long = 1
        var r = n.toLong() * Math.min(a, b)
        while (l <= r) {
            var m = l + (r - l) / 2
            // m 之前的神奇数字 -> a的倍数+b的倍数-a和b的公倍数
            if (m / a + m / b - m / p >= n) r = --m else l = ++m
        }
        return (l % 1000000007).toInt()
    }
}