import java.util.*;
class Next_Greater_Element_in_Circular_Array{
    public static ArrayList<Integer> nextLargerElement(int arr[]){
        int n = arr.length;
        ArrayList<Integer> ans = new ArrayList<>(Collections.nCopies(n,-1)); // used to intialize the array with -1
        Stack<Integer> st = new Stack<>();
        st.push(arr[n-1]);
        for(int i=2*n-1;i>=0;i--){
            while(st.size()>0 && st.peek()<=arr[i%n]) st.pop();
            if(i<n && !st.isEmpty()) ans.set(i,st.peek());
            st.push(arr[i%n]);
        }
        return ans;
    }
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] arr = new int[n];
        for(int i=0;i<n;i++){
            arr[i] = sc.nextInt();
        }
        ArrayList<Integer> res = nextLargerElement(arr);
        System.out.println(res);
        sc.close();
    }
}