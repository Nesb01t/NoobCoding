class le792 {
    fun numMatchingSubseq(s: String, words: Array<String>): Int {
        var res = 0
        val sucSet = HashSet<String>()
        val failSet = HashSet<String>()
        for (word in words) {
            val n = word.length
            if (n > s.length) {
                continue
            }
            if (sucSet.contains(word)) {
                res++
                continue
            }
            if (failSet.contains(word)) {
                continue
            }
            var indexW = 0
            var indexS = 0
            while (indexS < s.length) {
                if (s[indexS] == word[indexW]) {
                    indexW++
                }
                if (indexW == n) {
                    res++
                    sucSet.add(word)
                    break
                }
                indexS++
            }
            failSet.add(word)
        }
        return res
    }
}