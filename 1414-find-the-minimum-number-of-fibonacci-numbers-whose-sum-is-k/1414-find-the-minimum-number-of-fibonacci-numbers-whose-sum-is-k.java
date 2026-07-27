class Solution {
    public int findMinFibonacciNumbers(int k) {
        List<Integer> arr = new ArrayList<>();
        arr.add(0);
        arr.add(1);
        int n = arr.size();
        while (arr.get(n - 1) <= k) {
            arr.add(arr.get(n - 1) + arr.get(n - 2));
            n++;
        }
        int ans = 0;
        while (k > 0) {
            if (k - arr.get(n - 1) >= 0) {
                k -= arr.get(n - 1);
                ans++;
            } else
                n--;
        }
        return ans;
    }
}