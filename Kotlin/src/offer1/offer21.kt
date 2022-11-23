package offer1

object offer21 {
    fun exchange(nums: IntArray): IntArray {
        var list = mutableListOf<Int>()
        var otherList = mutableListOf<Int>()
        for (i in nums) {
            if (i % 2 == 1) {
                list.add(i)
            } else {
                otherList.add(i)
            }
        }
        for (i in otherList) {
            list.add(i)
        }
        return list.toIntArray()
    }
}