class Solution {
    public int[] topKFrequent(int[] nums, int k) {
        // create an array of size nums (n)
        // do bucker sort
        // loop in reves

        int len = nums.length;   

        Map<Integer, Integer> count = new HashMap<>();
        
        for (int n : nums) count.merge(n, 1, Integer::sum);
        
        List<Integer>[] buckets =  new ArrayList[len + 1];

        for (int i = 0; i < len + 1; i++) {
            buckets[i] = new ArrayList<>();
        }

        for (var entry : count.entrySet()) {
            int n = entry.getKey();
            int c = entry.getValue();
            
            buckets[c].add(n);
        }

        int[] res = new int[k];
        int counter = 0;
        for (int i = buckets.length - 1; i >= 0; i--) {
            var currentBucket = buckets[i];

            for (var item : currentBucket) {
                res[counter] = item;
                counter++;
                
                if (counter == k) return res;
            }
        }

        return res;
    }
}
