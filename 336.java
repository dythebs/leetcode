class Solution {
    public List<List<Integer>> palindromePairs(String[] words) {
        Map<String, Integer> map = new HashMap<>();
        for (int i = 0 ; i < words.length ; i++) {
            map.put(words[i], i);
        }
        for (int i = 0 ; i < words.length ; i++) {
            String s = words[i];
            String rs = new StringBuilder(s).reverse().toString();
            if (!rs.equals(s) && map.containsKey(rs)) {
                ans.add(Arrays.asList(i, map.get(rs)));
            }
            for (int l = 0 ; l < s.length() ; l++) {
                if (valid(s, 0, s.length()-l-1)) {
                    String r = new StringBuilder(s.substring(s.length()-l)).reverse().toString();
                    if (map.containsKey(r)) {
                        ans.add(Arrays.asList(map.get(r), i));
                    }
                }
                if (valid(s, l, s.length()-1)) {
                    String r = new StringBuilder(s.substring(0, l)).reverse().toString();
                    if (map.containsKey(r)) {
                        ans.add(Arrays.asList(i, map.get(r)));
                    }
                }
            }
        }
        return ans;
    }
    private boolean valid(String s, int l, int r) {
        int len = r - l + 1;
        for (int i = 0 ; i < len/2 ; i++) {
            if (s.charAt(l+i) != s.charAt(l+len-1-i)) {
                return false;
            }
        }
        return true;
    }
    List<List<Integer>> ans = new ArrayList<>();
}