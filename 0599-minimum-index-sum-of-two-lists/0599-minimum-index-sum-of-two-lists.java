class Solution {
    public String[] findRestaurant(String[] list1, String[] list2) {

        HashMap<String, Integer> mp = new HashMap<>();

        mp.put(list1[0], Integer.MIN_VALUE);

        for (int i = 1; i < list1.length; i++) {
            mp.put(list1[i], -i);
        }

        if (!mp.containsKey(list2[0])) {
            mp.put(list2[0], Integer.MIN_VALUE);
        } else {
            if (mp.get(list2[0]) != Integer.MIN_VALUE)
                mp.put(list2[0], Math.abs(mp.get(list2[0])));
            else
                mp.put(list2[0], 0);
        }

        for (int i = 1; i < list2.length; i++) {
            if (mp.containsKey(list2[i])) {
                if (mp.get(list2[i]) != Integer.MIN_VALUE)
                    mp.put(list2[i], Math.abs(mp.get(list2[i])) + i);
                else
                    mp.put(list2[i], i);
            } else {
                mp.put(list2[i], -i);
            }
        }

        int minVal = Integer.MAX_VALUE;

        for (int val : mp.values()) {
            if (val >= 0) {
                minVal = Math.min(minVal, val);
            }
        }

        ArrayList<String> ans = new ArrayList<>();

        for (String key : mp.keySet()) {
            if (mp.get(key) >= 0 && mp.get(key) == minVal) {
                ans.add(key);
            }
        }

        return ans.toArray(new String[0]);
    }
}