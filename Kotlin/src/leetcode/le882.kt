package leetcode

// 最短路模型, 看不明白dijkstra算法, cv模仿了一个
class le882 {
    private var g: Array<IntArray>
    private var distance: IntArray
    private var used: BooleanArray
    fun reachableNodes(edges: Array<IntArray>, maxMoves: Int, n: Int): Int {
        g = Array(n) { IntArray(n) }
        distance = IntArray(n)
        used = BooleanArray(n)
        for (i in 0 until n) {
            for (j in 0 until n) {
                if (i == j) g[i][j] = 0 else g[i][j] = Int.MAX_VALUE
            }
        }
        for (i in edges.indices) {
            g[edges[i][0]][edges[i][1]] = edges[i][2] + 1
            g[edges[i][1]][edges[i][0]] = edges[i][2] + 1
        }
        dijkstra(0)
        var res = 1
        // 遍历每一条边
        for (i in 1 until n) res += if (distance[i] <= maxMoves) 1 else 0
        for (i in edges.indices) {
            val a = edges[i][0]
            val b = edges[i][1]
            val w = edges[i][2]
            // 可以全取 a -> b
            if (distance[a] != Int.MAX_VALUE && distance[a] + w <= maxMoves || distance[b] != Int.MAX_VALUE && distance[b] + w <= maxMoves) {
                // System.out.println("i: " + i + " " + w);
                res += w
            } else {
                var x1 = 0
                var x2 = 0
                if (maxMoves > distance[a]) x1 = maxMoves - distance[a]
                if (maxMoves > distance[b]) x2 = maxMoves - distance[b]
                // System.out.println("x1: " + x1 + " " + "x2: " + x2);
                res += Math.min(w, x1 + x2)
            }
        }
        return res
    }

    fun dijkstra(start: Int) {
        val n = g.size
        // 初始化距离
        for (i in 0 until n) distance[i] = Int.MAX_VALUE
        distance[start] = 0

        // 循环n次，每次找一个元素进入集合
        for (i in 0 until n) {

            // 找到最小的距离
            var t = -1
            for (j in 0 until n) {
                if (!used[j] && (t == -1 || distance[j] < distance[t])) {
                    t = j
                }
            }

            // 拉进结合
            used[t] = true
            if (distance[t] == Int.MAX_VALUE) break

            // 更新距离
            for (k in 0 until n) {
                if (used[k] || g[t][k] == Int.MAX_VALUE) {
                    continue
                }
                distance[k] = Math.min(distance[k], distance[t] + g[t][k])
            }
        }
    }
}