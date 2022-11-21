package leetcode

class le808 {
    fun soupServings(n: Int): Double {
        // 看不明白，模仿了一下解法
        var n = n
        n = Math.ceil(n.toDouble() / 25).toInt()
        if (n >= 179) {
            return 1.0
        }
        val dp = Array(n + 1) { DoubleArray(n + 1) }
        dp[0][0] = 0.5
        for (i in 1..n) {
            dp[0][i] = 1.0
        }
        for (i in 1..n) {
            for (j in 1..n) {
                dp[i][j] =
                    (dp[Math.max(0, i - 4)][j] +
                     dp[Math.max(0, i - 3)][Math.max(0, j - 1)] +
                     dp[Math.max(0, i - 2
                )][Math.max(0, j - 2)] + dp[Math.max(0, i - 1)][Math.max(0, j - 3)]) / 4.0
            }
        }
        return dp[n][n]
    }
}