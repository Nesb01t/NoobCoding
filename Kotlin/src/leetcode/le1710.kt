import java.util.*

class le1710 {
    fun maximumUnits(boxTypes: Array<IntArray>, truckSize: Int): Int {
        var truckSize = truckSize
        // 根据第一位排序
        Arrays.sort(boxTypes) { a, b -> b[1] - a[1] }
        var i = 0
        var ans = 0
        while (truckSize > 0 && i < boxTypes.size) {
            val s = truckSize.coerceAtMost(boxTypes[i][0]) // 取最小值
            ans += s * boxTypes[i++][1]
            truckSize -= s
        }
        return ans
    }
}