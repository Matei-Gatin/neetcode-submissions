class Solution {
    public List<List<String>> groupAnagrams(String[] strs) {
        /*
            use a map to store:
            - key: code
            - value: anagrams

            create a code with an array ok indexes of letters and then add # between the letters
        
            sorting key option -> O (n log n)

            creating a code from a int letter array would be O(n)
        */

        Map<String, List<String>> codeToString = new HashMap<>();

        for (var str : strs) {
            String code = code(str);

            codeToString.computeIfAbsent(code, k -> new ArrayList<>())
                    .add(str);
        }

        return new ArrayList<>(codeToString.values());
    }

    private String code(String str) {
        StringBuilder code = new StringBuilder(2 * str.length());

        int[] letterIds = new int[26];

        for (char c : str.toCharArray()) {
            letterIds[c - 'a']++;
        }

        for (int letterId : letterIds) {
            code.append(letterId).append("#");
        }

        return code.toString();
    }
}
