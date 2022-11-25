package leetcode

class le809 {
    fun expressiveWords(s: String, words: Array<String>): Int {
        var ans = 0
        val arr1 = s.toCharArray()
        for (word in words) ans += if (isTrue(arr1, word.toCharArray())) 1 else 0
        return ans
    }

    fun isTrue(arr1: CharArray, arr2: CharArray): Boolean {
        var p1 = 0
        var p2 = 0
        while (p1 < arr1.size && p2 < arr2.size) {
            var cnt1 = 0
            var cnt2 = 0
            val c = arr1[p1]
            while (p1 < arr1.size && arr1[p1] == c) {
                p1++
                cnt1++
            }
            while (p2 < arr2.size && arr2[p2] == c) {
                p2++
                cnt2++
            }
            if (cnt1 < cnt2 || cnt1 > cnt2 && cnt1 < 3) return false
        }
        return p1 == arr1.size && p2 == arr2.size
    }
}