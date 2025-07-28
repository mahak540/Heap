 vector<int> kLargest(vector<int>& arr, int k) {
        // Your code here
        priority_queue<int,vector<int>,greater<int>>minH(arr.begin(),arr.begin()+k);
        for(int i=k;i<arr.size();i++)
        {
            if(minH.top()<arr[i])
            {
                minH.pop();
                minH.push(arr[i]);
            }
        }
        vector<int>res;
        while(!minH.empty())
        {
            res.push_back(minH.top());
            minH.pop();
        }
        reverse(res.begin(),res.end());
        return res;
    }
