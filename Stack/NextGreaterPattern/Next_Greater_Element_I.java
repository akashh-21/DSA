import java.util.*;
public class Next_Greater_Element_I {
    public static ArrayList<Integer> nextGreaterElement(int[] nums1, int[] nums2) {
        Stack<Integer> st = new Stack<>();
        int n = nums2.length;
        HashMap<Integer,Integer> m = new HashMap<>();
        m.put(nums2[n-1],-1);
        st.push(nums2[n-1]);
        for(int i=n-2;i>=0;i--){
            while(st.size()>0 && st.peek()<=nums2[i]) st.pop();
            if(st.size()==0) m.put(nums2[i],-1);
            else m.put(nums2[i],st.peek());
            st.push(nums2[i]);
        }
        ArrayList<Integer> ans = new ArrayList<>();
        for(int val:nums1){
            ans.add(m.get(val));
        }
        return ans;
    }
    public static void main(String[] args) {
        int[] nums1 = {4,1,2};
        int[] nums2 = {1,3,4,2};
        ArrayList<Integer> res = nextGreaterElement(nums1, nums2);
        System.out.println(res);
    }
}
