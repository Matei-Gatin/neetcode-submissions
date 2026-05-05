class Solution {
    public boolean hasDuplicate(int[] nums) {
        HashSet<Integer> seen = new HashSet<>();

        for (int n : nums) {
            if (!seen.add(n)) { // return a bool if it added or not
                return true;
            }
        }

        return false;
    }
}