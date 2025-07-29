string rearrangeString(string s) {
        int n=s.length();
        int cnt=0;
        char ch='#';
        
        unordered_map<char,int>freq;
        for(int i=0;i<n;i++)
        {
            freq[s[i]]++;
            if(freq[s[i]]>cnt){
                cnt=freq[s[i]];
                ch=s[i];
            }
        }
        if(cnt>((n+1)/2))
        return "";
        int ind=0;
        while(cnt>0)
        {
            s[ind]=ch;
            ind=ind+2;
            cnt--;
        }
        freq[ch]=0;
        for(char ch='a';ch<='z;ch++)
        {
            while(freq[ch]>0)
            {
                ind=(ind>=n)?1:ind;
                s[ind]=ch;
                ind+=2;
                freq[ch]--;
            }
        }
        return s;
}
