package offer1

object offer06 {
    fun reversePrint(head: ListNode?): IntArray {
        var nowHead = head
        val array = mutableListOf<Int>()
        while (nowHead != null) {
            array.add(nowHead.`val`)
            nowHead = nowHead.next
        }
        array.reverse()
        return array.toTypedArray().toIntArray()
    }
}

class ListNode(var `val`: Int) {
    var next: ListNode? = null
}