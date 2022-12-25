package leetcode

class le799 {
    fun champagneTower(poured: Int, query_row: Int, query_glass: Int): Double {
        // poured 总杯数, query_row 杯子位置数, query_glass 行数
        var count = doubleArrayOf(poured.toDouble()) // double
        for (i in 1..query_row) {
            val arr = DoubleArray(i + 1)

            // 模拟判断
            arr[0] = 0.0.coerceAtLeast(count[0] - 1) / 2
            arr[i] = 0.0.coerceAtLeast(count[i - 1] - 1) / 2
            for (j in 1 until i) {
                arr[j] = (0.0.coerceAtLeast(count[j - 1] - 1) +
                          0.0.coerceAtLeast(count[j] - 1)) / 2
            }
            count = arr
        }
        return 1.0.coerceAtMost(count[query_glass]) // 取最大值
    }
}