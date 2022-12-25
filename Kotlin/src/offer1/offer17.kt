package offer1

object offer17 {
    fun printNumbers(n: Int): IntArray {
        var sum = 1
        for (i in 0 until  n) {
            sum *= 10
        }

        val list = arrayListOf<Int>()
        for (i in 1 until sum) {
            list.add(i)
        }
        return list.toIntArray()
    }
}