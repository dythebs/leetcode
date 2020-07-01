class Solution {
    public int findLength(int[] A, int[] B) {
        int l = 0, r = Math.min(A.length, B.length);
        while (l < r) {
            int mid = (l + r + 1) / 2;  //1100
            if (judge(mid, A, B)) {
                l = mid;
            } else {
                r = mid - 1;
            }
        }
        return l;
    }

    private final int MOD = 10000007;
    private final int BASE = 13;

    private boolean judge(int x, int[] A, int[] B) {
        Map<Long, List<Integer>> map = new HashMap<>();
        long ahash = 0;
        for (int i = 0 ; i < x ; i++) {
            ahash *= BASE;
            ahash %= MOD;
            ahash += A[i];
            ahash %= MOD;
        }
        add(map, ahash, 0);
        long mult = qPow(BASE, x-1);
        for (int i = 1 ; i + x - 1 < A.length ; i++) {
            ahash = (ahash - (mult * A[i-1]) % MOD) % MOD;
            ahash = (ahash + MOD) % MOD;
            ahash = (ahash * BASE) % MOD;
            ahash = (ahash + A[i+x-1]) % MOD;
            add(map, ahash, i);
        }
        long bhash = 0;
        for (int i = 0 ; i < x ; i++) {
            bhash *= BASE;
            ahash %= MOD;
            bhash += B[i];
            bhash %= MOD;
        }
        if (check(A, B, map, bhash, 0, x)) {
            return true;
        }
        for (int i = 1 ; i + x - 1 < B.length ; i++) {
            bhash = (bhash - (mult * B[i-1]) % MOD) % MOD;
            bhash = (bhash + MOD) % MOD;
            bhash = (bhash * BASE) % MOD;
            bhash = (bhash + B[i+x-1]) % MOD;
            if (check(A, B, map, bhash, i, x)) {
                return true;
            }
        }
        return false;
    }

    private boolean check(int[] A, int[] B, Map<Long, List<Integer>> map, long hash, int i, int x) {
        if (map.containsKey(hash)) {
            List<Integer> arr = map.get(hash);
            for (int astart : arr) {
                boolean flag = true;
                for (int j = 0 ; j < x ; j++) {
                    if (A[j + astart] != B[j + i]) {
                        flag = false;
                        break;
                    }
                }
                if (flag) return true;
            }
        }
        return false;
    }

    private void add(Map<Long, List<Integer>> map, long k, int v) {
        List<Integer> arr = map.getOrDefault(k, new ArrayList<>());
        arr.add(v);
        map.put(k, arr);
    }

    private long qPow(long x, long n) {
        long ans = 1;
        while (n > 0) {
            if ((n & 1) > 0) {
                ans = (ans * x) % MOD;
            }
            x = (x * x) % MOD;
            n >>= 1;
        }
        return ans;
    }
}