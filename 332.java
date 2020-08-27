class Solution {
    public List<String> findItinerary(List<List<String>> tickets) {

        Map<String, List<String>> map = new HashMap<>();

        for (List<String> ticket : tickets) {
            List<String> toList = map.getOrDefault(ticket.get(0), new ArrayList<>());
            toList.add(ticket.get(1));
            map.put(ticket.get(0), toList);
        }
        
        for (String from : map.keySet()) {
            List<String> toList = map.get(from);
            Collections.sort(toList);
        }
        
        ans.add("JFK");
        dfs("JFK", tickets, map);

        return ans;
    }

    List<String> ans = new ArrayList<>();

    boolean dfs(String from, List<List<String>> tickets, Map<String, List<String>> map) {

        if (ans.size() == tickets.size() + 1) {
            return true;
        }

        List<String> toList = map.get(from);

        if (toList == null || toList.isEmpty()) {
            return false;
        }

        for (int i = 0 ; i < toList.size() ; i++) {
            String to = toList.get(i);
            if (to.charAt(0) == '#') continue;
            toList.set(i, "#" + to);
            ans.add(to);
            if (dfs(to, tickets, map)) {
                return true;
            }
            toList.set(i, to);
            ans.remove(ans.size()-1);
        }
        
        return false;
    }
}