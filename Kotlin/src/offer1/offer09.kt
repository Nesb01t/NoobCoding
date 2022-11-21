package offer1

import java.util.*

class CQueue() {
    // 我可能是傻子，读不懂题

    // 构建第一个栈
    val stackFist = Stack<Int>()

    // 构建第二个栈
    val stackSecond = Stack<Int>()

    fun appendTail(value: Int) {
        // 加入到第一个栈
        stackFist.push(value)
    }

    fun deleteHead(): Int {
        // 判定第二个栈是否为空
        return if (stackSecond.isNotEmpty()) {
            // 不为空，则弹出即可
            stackSecond.pop()
        } else {
            // 为空，则需要将第一个栈元素全部移到第二个栈
            while (stackFist.isNotEmpty()) {
                stackSecond.push(stackFist.pop())
            }
            // 为空保护
            if (stackSecond.isNotEmpty()) {
                stackSecond.pop()
            } else {
                -1
            }
        }
    }
}