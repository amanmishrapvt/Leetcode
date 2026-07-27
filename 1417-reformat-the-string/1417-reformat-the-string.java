class Solution {
    public String reformat(String s) {
        StringBuilder digits = new StringBuilder();
        StringBuilder letters = new StringBuilder();
        for (char c : s.toCharArray()) {
            if (Character.isDigit(c)) digits.append(c);
            else letters.append(c);
        }
        if (Math.abs(digits.length() - letters.length()) >= 2) return "";
        StringBuilder ans = new StringBuilder();
        boolean digitFirst = digits.length() > letters.length();
        int d = 0, l = 0;
        for (int i = 0; i < s.length(); i++) {
            if ((digitFirst && i % 2 == 0) || (!digitFirst && i % 2 == 1)) {
                ans.append(digits.charAt(d++));
            } else {
                ans.append(letters.charAt(l++));
            }
        }
        return ans.toString();
    }
}