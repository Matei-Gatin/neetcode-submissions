class Solution {
    public boolean isAnagram(String s, String t) {
        // 2 anagrams must be the same length
        if (s.length() != t.length()) return false;

        int[] sCount = new int[26];

        for (char c : s.toCharArray()) {
            sCount[c - 'a']++;
        }

        for (char c : t.toCharArray()) {
            sCount[c - 'a']--;

            if (sCount[c - 'a'] < 0) {
                return false;
            }
        }

        return true;
    }
}
