class Solution {
    public int expressiveWords(String S, String[] words) {
        int ans = 0;
        List<Pair<Character, Integer>> sArray = toArray(S);
        start:
        for (String word : words) {
            if (word.length() > S.length()) continue;
            List<Pair<Character, Integer>> wordArray = toArray(word);
            if (wordArray.size() != sArray.size()) continue;
            for (int i = 0 ; i < wordArray.size() ; i++) {
                Pair<Character, Integer> sPair = sArray.get(i);
                Pair<Character, Integer> wordPair = wordArray.get(i);
                if (sPair.getKey() != wordPair.getKey()) {
                    continue start;
                }
                if (sPair.getValue() < wordPair.getValue()) {
                    continue start;
                }
                if (sPair.getValue() > wordPair.getValue() && sPair.getValue() < 3) {
                    continue start;
                }
            }
            ans++;
        }
        return ans;
    }
    private List<Pair<Character, Integer>> toArray(String s) {
        List<Pair<Character, Integer>> array = new ArrayList<>();
        char c = s.charAt(0);
        int count = 1;
        for (int i = 1 ; i < s.length() ; i++) {
            if (s.charAt(i) == c) {
                count++;
            } else {
                array.add(new Pair(c, count));
                c = s.charAt(i);
                count = 1;
            }
        }
        array.add(new Pair(c, count));
        return array;
    }
}