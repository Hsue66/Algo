class Solution {
    public int[] twoSum(int[] nums, int target) {
       int result[] = new int[2];
        HashMap<Integer, Integer> map = new HashMap<Integer, Integer>();
        int len = nums.length;
        for(int i=0; i<len; i++) {
            if(map.containsKey(nums[i])){
                result[0] = map.get(nums[i]);
                result[1] = i;
                break;
            }
            map.put(target-nums[i], i);
        }
        return result;
    }
}
