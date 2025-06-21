public class CatchThieves {

    public static int catchThieves(char[] arr, int k) {
        int n = arr.length;
        int i = 0;
        int j = 0;
        int cnt = 0;

        while (i < n && j < n) {
            // Find next policeman
            while (i < n && arr[i] != 'P') i++;

            // Find next thief
            while (j < n && arr[j] != 'T') j++;

            if (i < n && j < n) {
                if (Math.abs(i - j) <= k) {
                    // Catch thief
                    cnt++;
                    i++;
                    j++;
                } else if (i < j) {
                    i++;
                } else {
                    j++;
                }
            }
        }
        return cnt;
    }

    public static void main(String[] args) {
        char[] arr = {'P', 'T', 'T', 'P', 'T'};
        int k = 2;
        System.out.println("Maximum thieves caught: " + catchThieves(arr, k));
    }
}
