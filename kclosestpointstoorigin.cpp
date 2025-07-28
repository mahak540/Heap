int dis(vector<int>& points)
  {
      return points[0]*points[0] + points[1]*points[1];
  }
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        // Your code here
        priority_queue<pair<int,vector<int>>>maxheap;
        for(int i=0;i<points.size();i++)
        {
            int d=dis(points[i]);
            if(maxheap.size()<k)
            {
                maxheap.push({d,points[i]});
            }
            else{
                if(d<maxheap.top().first)
                {
                    maxheap.pop();
                    maxheap.push({d,points[i]});
                }
            }
        }
        vector<vector<int>>res;
        while(!maxheap.empty())
        {
            res.push_back(maxheap.top().second);
            maxheap.pop();
        }
        return res;
    }
