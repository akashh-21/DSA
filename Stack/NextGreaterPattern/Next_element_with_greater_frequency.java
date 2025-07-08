import java.util.*;

class Next_element_with_greater_frequency {
    public static ArrayList<Integer> findGreater(int[] arr) {
        int n = arr.length;
        
        // Initialize answer array with -1
        ArrayList<Integer> ans = new ArrayList<>(Collections.nCopies(n, -1));
        
        // Step 1: Create frequency map of all elements
        HashMap<Integer, Integer> freq = new HashMap<>();
        for (int val : arr) {
            freq.put(val, freq.getOrDefault(val, 0) + 1);
        }

        // Step 2: Stack for next greater frequency tracking
        Stack<Integer> st = new Stack<>();
        st.push(arr[n - 1]);

        // Step 3: Traverse from second-last to first element
        for (int i = n - 2; i >= 0; i--) {
            // Pop all elements whose frequency is <= current element's frequency
            while (!st.isEmpty() && freq.get(st.peek()) <= freq.get(arr[i])) {
                st.pop();
            }

            // If stack not empty, top is next greater frequency element
            if (!st.isEmpty()) {
                ans.set(i, st.peek());
            }

            // Push current element to stack
            st.push(arr[i]);
        }

        return ans;
    }
    public static void main(String[] args) {
        int arr[] = {2, 1, 1, 3, 2, 1};
        ArrayList<Integer> ans = findGreater(arr);
        System.out.println(ans);
    }
}
