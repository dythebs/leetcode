class Solution {
    public int[] topKFrequent(int[] nums, int k) {
        PriorityQueue<Pair<Integer, Integer>> q = new PriorityQueue<>(new Comparator<Pair<Integer, Integer>>(){
            public int compare(Pair<Integer, Integer> o1, Pair<Integer, Integer> o2) {
                return o1.getValue() - o2.getValue();
            }
        });
        Map<Integer, Integer> map = new HashMap<>();
        for (int i : nums) {
            int n = map.getOrDefault(i, 0);
            map.put(i, n+1);
        }
        for (int i : map.keySet()) {
            if (q.size() < k) {
                q.add(new Pair(i, map.get(i)));
            } else {
                if (map.get(i) > q.element().getValue()) {
                    q.remove();
                    q.add(new Pair(i, map.get(i)));
                }
            }
        }
        int[] ans = new int[k];
        for (Pair<Integer, Integer> p : q) {
            ans[--k] = p.getKey();
        }
        return ans;
    }
}