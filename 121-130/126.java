class Solution {
    public List<List<String>> findLadders(String beginWord, String endWord, List<String> wordList) {
        List<List<String>> ans = new ArrayList<>();
        if (!wordList.contains(endWord)) return ans;
        Map<String, Set<String>> wordMap = new HashMap();
        for (String word : wordList) {
            for (int i = 0 ; i < word.length() ; i++) {
                String tempWord = word.substring(0, i) + "*" + word.substring(i+1, word.length());
                Set<String> set = wordMap.getOrDefault(tempWord, new HashSet<String>());
                set.add(word);
                wordMap.put(tempWord, set);
            }
        }
        Queue<List<String>> queue = new LinkedList<>();
        Set<String> visited = new HashSet<>();
        queue.add(new ArrayList(Arrays.asList(beginWord)));
        visited.add(beginWord);
        while (!queue.isEmpty() && ans.isEmpty()) {
            Set<String> levelVisited = new HashSet<>();
            int n = queue.size();
            for (int j = 0 ; j < n ; j++) {
                List<String> tempAns = queue.remove();
                String word = tempAns.get(tempAns.size()-1);
                for (int i = 0 ; i < word.length() ; i++) {
                    String tempWord = word.substring(0, i) + "*" + word.substring(i+1, word.length());
                    Set<String> set = wordMap.getOrDefault(tempWord, new HashSet<String>());
                    for (String toWord : set) {
                        if (toWord.equals(endWord)) {
                            tempAns.add(endWord);
                            ans.add(tempAns);
                            break;
                        }
                        if (visited.contains(toWord)) continue;
                        List<String> toWordTempAns = new ArrayList<>(tempAns);
                        toWordTempAns.add(toWord);
                        queue.add(toWordTempAns);
                        levelVisited.add(toWord);
                    }
                }
            }
            visited.addAll(levelVisited);
        }
        return ans;
    }
}