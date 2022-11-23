package offer1

object offer18 {
    fun deleteNode(head: ListNode?, `val`: Int): ListNode? {
        var nowHead = head
        if (nowHead?.`val` == `val`) {
            return head?.next
        }
        while (nowHead != null) {
            if(nowHead.next?.`val` == `val`) {
                nowHead.next = nowHead.next?.next
            }
            nowHead = nowHead.next
        }
        return head
    }
}
