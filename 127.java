class Solution {
    public int ladderLength(String beginWord, String endWord, List<String> wordList) {
        if (!wordList.contains(endWord)) return 0;
        Map<String, List<String>> wordMap = new HashMap<>();
        wordList.forEach(
            word -> {
                for (int i = 0 ; i < word.length() ; i++) {
                    String tempWord = word.substring(0, i) + "*" + word.substring(i+1, word.length());
                    List<String> list = wordMap.getOrDefault(tempWord, new ArrayList<>());
                    list.add(word);
                    wordMap.put(tempWord, list);
                }
            }
        );
        Queue<String> queueBegin = new LinkedList<>();
        queueBegin.add(beginWord);
        Queue<String> queueEnd = new LinkedList<>();
        queueEnd.add(endWord);
        Map<String, Integer> visitedBegin = new HashMap<>();
        visitedBegin.put(beginWord, 1);
        Map<String, Integer> visitedEnd = new HashMap<>();
        visitedEnd.put(endWord, 1);
        while (!queueBegin.isEmpty() && !queueEnd.isEmpty()) {
            int ans = visit(queueBegin, visitedBegin, visitedEnd, wordMap);
            if (ans > -1) return ans;
            ans = visit(queueEnd, visitedEnd, visitedBegin, wordMap);
            if (ans > -1) return ans;
        }
        return 0;
    }

    private int visit(Queue<String> queue, 
                        Map<String, Integer> visited, 
                        Map<String, Integer> otherVisited, 
                        Map<String, List<String>> wordMap) {
        String word =  queue.remove();
        for (int i = 0 ; i < word.length() ; i++) {
            String tempWord = word.substring(0, i) + "*" + word.substring(i+1, word.length());
            if (wordMap.containsKey(tempWord)) {
                List<String> list = wordMap.get(tempWord);
                for(String toWord : list) {
                    if (otherVisited.containsKey(toWord)) {
                        return visited.get(word) + otherVisited.get(toWord);
                    }
                    if (visited.containsKey(toWord) || word.equals(toWord)) continue;
                    queue.add(toWord);
                    visited.put(toWord, visited.get(word)+1);
                }
            }
        }
        return -1;
    }
}