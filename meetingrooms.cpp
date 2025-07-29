int minMeetingRooms(vector<int> &start, vector<int> &end) {
        int n=start.size();
        int room=0,res=0;
        sort(start.begin(),start.end());
        sort(end.begin(),end.end());
        
        int l=0,r=0;
        while(l<start.size())
        {
            if(start[l]<end[r])
            {
                room++;
                l++;
            }
            else{
                room--;
                r++;
            }
            res=max(res,room);
        }
        return res;
    }
