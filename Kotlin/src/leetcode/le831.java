package leetcode;

public class le831 {
    double[][] cache;

    public double largestSumOfAverages(int[] A, int K) {
        this.cache = new double[A.length + 1][K + 1];
        return calc(A, 0, K);
    }

    private double calc(int A[], int index, int K) {
        if (K == 0) {
            return 0.0;
        }
        if (cache[index][K] != 0.0) return cache[index][K];
        if (K == 1) {
            int sum = 0;
            for (int i = index; i < A.length; i++) {
                sum += A[i];
            }
            cache[index][K] = (double) sum / (A.length - index);
            return cache[index][K];
        }
        double sum = 0.0;
        double res = 0.0;
        for (int i = index; i <= A.length - K; i++) {
            sum += A[i];
            double avage = sum / (i - index + 1);
            cache[i + 1][K - 1] = calc(A, i + 1, K - 1);
            res = Math.max(res, avage + cache[i + 1][K - 1]);
        }
        cache[index][K] = res;
        return (double) res;
    }
}