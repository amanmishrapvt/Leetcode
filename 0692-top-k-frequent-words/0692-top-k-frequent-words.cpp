class Solution {
public:
    struct compare {
        // compare(a, b) == true , means a has lower priority than b.
        bool operator()(const pair<int,string>& a , const pair<int,string>& b){
        //let a = {2,a} , b = {2,b} so (b priority should higher bcz we want to pop b first)
            if( a.first == b.first ){ 
                return a.second < b.second;
            }
            return a.first > b.first;
        }
    };
    vector<string> topKFrequent(vector<string>& words, int k) {
        // minheap to store the low freq element at the top , also use comparator 
        priority_queue< pair<int,string> , vector<pair<int,string>> , compare > minheap;
        unordered_map<string,int> mp; // store pair of [word,freq]

        for(auto word: words){
            mp[word]++;
        }

        for(auto [word,freq] : mp){
            minheap.push({freq,word});
            if(minheap.size() > k ){ // if size exceed k than remove low priority candidate
                minheap.pop();
            }
        }

        vector<string> ans(k); 
        int i = k;
        while(!minheap.empty()){ // store the answer from the back to maintain order
            ans[i-1] = minheap.top().second;
            minheap.pop();
            i--;
        }

        return ans;
    }
};