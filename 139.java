class Solution {
    public boolean wordBreak(String s, List<String> wordDict) {
        Set<String> set = new HashSet<>();
        set.addAll(wordDict);
        return dfs(s, set);
    }
    Map<String, Boolean> visited = new HashMap<>();
    boolean dfs(String s, Set<String> wordDict) {
        if ("".equals(s)) return true;
        if (wordDict.contains(s)) {
            return true;
        }
        if (visited.containsKey(s)) {
            return visited.get(s);
        }
        for (int i = 1 ; i < s.length() ; i++) {
            String a = s.substring(0, i);
            String b = s.substring(i, s.length());
            if (wordDict.contains(a)){
                if (dfs(b, wordDict)) {
                    visited.put(s, true);
                    return true;
                }
            }
        }
        visited.put(s, false);
        return false;
    }
}