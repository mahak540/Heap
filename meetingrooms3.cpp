 int mostBooked(int n, vector<vector<int>> &meetings) {
        // code here
        vector<int>cnt(n,0);
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        priority_queue<int,vector<int>,greater<int>>avail;
        
        for(int i=0;i<n;i++)
        avail.push(i);
        sort(meetings.begin(),meetings.end());
        for(auto& m : meetings)
        {
            int s=m[0],e=m[1];
            while(!pq.empty() && pq.top().first<=s)
            {
                avail.push(pq.top().second);
                pq.pop();
            }
            if(!avail.empty())
            {
                int room=avail.top();
                avail.pop();
                pq.push({e,room});
                cnt[room]++;
            }
            else{
                int endtime=pq.top().first;
                int room=pq.top().second;
                pq.pop();
                pq.push({endtime+(e-s),room});
                cnt[room]++;
            }
        }
        int maxcnt=0,res=0;
        for(int i=0;i<n;i++)
        {
            if(cnt[i]>maxcnt)
            {
                maxcnt=cnt[i];
                res=i;
            }
        }
        return res;
    }
