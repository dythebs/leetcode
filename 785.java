class Solution {
    public boolean isBipartite(int[][] graph) {
        int n = graph.length;
        int[] num = new int[n];
        int left = n;
        Arrays.fill(num, -1);
        Queue<Integer> queue = new LinkedList<>();
        while (left > 0) {
            for (int i = 0 ; i < n ; i++) {
                if (num[i] == -1) {
                    queue.add(i);
                    num[i] = 0;
                    left--;
                    break;
                }
            }
            while (!queue.isEmpty()) {
                int x = queue.poll();
                for (int i = 0 ; i < graph[x].length ; i++) {
                    if (num[graph[x][i]] != -1) {
                        if (num[graph[x][i]] + num[x] != 1) {
                            return false;
                        }
                    } else {
                        num[graph[x][i]] = 1-num[x];
                        left--;
                        queue.add(graph[x][i]);
                    }
                }
            }
        }
        return true;
    }
}