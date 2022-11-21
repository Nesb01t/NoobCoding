package leetcode

import java.util.*

class le1732 {
    fun largestAltitude(gain: IntArray): Int {
        val n = gain.size // 数组长度
        val altitude = IntArray(n + 1)
        for (i in 1 until n + 1) {
            altitude[i] = altitude[i - 1] + gain[i - 1] // 存储所有海拔
        }
        return Arrays.stream(altitude).max().asInt // kotlin stl
    }
}