class Solution {

    List<List<String>> res = new ArrayList<>();

    public List<List<String>> partition(String s) {
        backtrack(s, new ArrayList<>());
        return res;
    }

    private void backtrack(String s, List<String> currentPartitions) {

        if (s.isEmpty()) {
            res.add(new ArrayList<>(currentPartitions));
            return;
        }

        for (int partition = 1; partition <= s.length(); partition++) {
            String prefix = s.substring(0, partition);
            String remaining = s.substring(partition);

            if (isPalindrome(prefix, 0, prefix.length() - 1)) {
                currentPartitions.add(prefix);
                backtrack(remaining, currentPartitions);
                currentPartitions.removeLast();
            }
        }
    }

    private boolean isPalindrome(String s, int left, int right) {
        while (left < right) {
            if (s.charAt(left) != s.charAt(right))
                return false;

            left++;
            right--;
        }

        return true;
    }
}