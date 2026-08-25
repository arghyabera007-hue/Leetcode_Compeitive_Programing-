import java.util.*;

class Solution {
    public int[] maxSlidingWindow(int[] nums, int k) {
        if (nums == null || nums.length == 0) return new int[0];
        
        int n = nums.length;
        int[] result = new int[n - k + 1];
        int ri = 0; // index for result array
        
        // Deque will store indices
        Deque<Integer> dq = new ArrayDeque<>();

        for (int i = 0; i < nums.length; i++) {
            // 1. Remove indices that are out of the current window range
            if (!dq.isEmpty() && dq.peekFirst() <= i - k) {
                dq.pollFirst();
            }

            // 2. Remove indices of all elements smaller than the current element
            // (Maintaining the monotonic decreasing order)
            while (!dq.isEmpty() && nums[dq.peekLast()] <= nums[i]) {
                dq.pollLast();
            }

            // 3. Add current element's index
            dq.addLast(i);

            // 4. Once we've hit the first window size, start adding to results
            if (i >= k - 1) {
                result[ri++] = nums[dq.peekFirst()];
            }
        }

        return result;
    }
}