class Solution {
    public boolean hasDuplicate(int[] nums) {
        /*
            First approach:
            1, 2, 3, 3
            Brute force approach would be O(n2)

            Second approach:
            Time: O(n)
            Space: O(n)
        */

        Set<Integer> unique = new HashSet<>();

        for (int num : nums) {
            if (!unique.add(num)) {
                return true;
            }
        }

        return false;
    }
}