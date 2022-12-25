class le792 {
    fun numMatchingSubseq(s: String, words: Array<String>): Int {
        var res = 0
        var succSet = HashSet<String>()
        var failSet = HashSet<String>()
        // 直接暴力超时, 加入 HashSet 去重
        for (word in words) {
            var n = word.length
            // 判断简单情况
            if (n > s.length) continue
            if (succSet.contains(word)) {
                res++
                continue
            }
            if (failSet.contains(word)) {
                continue
            }

            // 双指针暴力查找
            var indexL = 0
            var indexR = 0
            while (indexR < s.length) {
                if (s[indexR] == word[indexL]) {
                    indexL++
                }
                if (indexL == n) {
                    res++
                    succSet.add(word)
                    break
                }
                indexR++
            }
            failSet.add(word) // 关键去重
        }
        return res
    }
}