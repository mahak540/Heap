vector<int> sortArray(vector<int>& nums) {
        priority_queue<int,vector<int>,greater<int>>pq;
        for(int i:nums)
        {
            pq.push(i);
        }
        vector<int>res;
        while(!pq.empty())
        {
            res.push_back(pq.top());
            pq.pop();
        }
        return res;
    }
