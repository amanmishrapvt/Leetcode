class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) 
    {
        int n = piles.size();
        int ans = 0;
        priority_queue<int>pq;
        for(int i=0;i<n;i++)
        {
            pq.push(piles[i]);
        }
        while(k>0)
        {
            int x = pq.top();
            if(x%2==0) x=x/2;
            else 
            {
                x=x/2;
                x+=1;
            }
            pq.pop();
            pq.push(x);
            k--;
        }
        while(!pq.empty())
        {
            ans+=pq.top();
            pq.pop();
        }
        return ans;
    }
//please upvote...
};