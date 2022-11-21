package offer1

object offer11 {
    fun minArray(numbers: IntArray): Int {
        for (i in 1 until numbers.size) {
            if (numbers[i-1] > numbers[i]) return numbers[i]
        }
        return numbers[0]
    }
}