class Solution {
    public List<Integer> findSubstring(String s, String[] words) {
        List<Integer> result = new ArrayList<>();
        if (s == null || s.length() == 0 || words == null || words.length == 0) return result;
        int wordLen = words[0].length();
        int wordCount = words.length;
        int totalLen = wordLen * wordCount;
        Map<String, Integer> wordMap = new HashMap<>();
        for (String word : words) {
            wordMap.put(word, wordMap.getOrDefault(word, 0) + 1);
        }
        for (int i = 0; i <= s.length() - totalLen; i++) {
            String sub = s.substring(i, i + totalLen);
            Map<String, Integer> subMap = new HashMap<>();
            for (int j = 0; j < totalLen; j += wordLen) {
                String w = sub.substring(j, j + wordLen);
                subMap.put(w, subMap.getOrDefault(w, 0) + 1);
            }
            if (wordMap.equals(subMap)) {
                result.add(i);
            }
        }
        return result;
    }
}