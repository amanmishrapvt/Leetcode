class Solution {
    public int getLucky(String s, int k) {
        int sum = 0;
        for(char ch : s.toCharArray()){
            int n = (ch-'a'+1);
            if(n<10){
                sum += n;
            }
            else{
                sum += n%10;
                sum += n/10;
            }
        }
        int i = 1;
        while(i<k){
            int temp = sum;
            sum = 0;
            while(temp>0){
                sum += temp%10;
                temp /= 10;
            }
            i++;
        }
        return sum;
    }
}