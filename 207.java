class Solution {
    public boolean canFinish(int numCourses, int[][] prerequisites) {
        int[] in = new int[numCourses];
        int[] vis = new int[numCourses];
        Map<Integer, List<Integer>> map = new HashMap<>();
        for (int[] edge : prerequisites) {
            List<Integer> to = map.getOrDefault(edge[0], new ArrayList<>());
            to.add(edge[1]);
            map.put(edge[0], to);
            in[edge[1]]++;
        }
        int finish = 0;
        while (finish < numCourses) {
            int source = -1;
            for (int i = 0 ; i < numCourses ; i++) {
                if (vis[i] == 0 && in[i] == 0) {
                    source = i;
                    vis[i] = 1;
                    break;
                }
            }
            if (source == -1) {
                return false;
            }
            finish++;
            for (int to : map.getOrDefault(source, new ArrayList<>())) {
                in[to]--;
            }
        }
        return true;
    }
}