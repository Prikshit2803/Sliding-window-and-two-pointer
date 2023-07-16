 string smallestWindow (string s, string p)
    {
        if(s.length()<p.length())
        return "-1";
        
        if(s==p)
        return s;
        
        vector<int> mp(26,0); //as hash-map can give TLE
        
        int l=0,r=0,cnt=0,minlen=INT_MAX,start=0;
        
        for(int i=0;i<p.length();i++){
            if(mp[p[i]-'a']==0) //only once cnt increases for a character
            cnt++;
            
            mp[p[i]-'a']++;
        }
        
        
        while(r<s.length()){
            mp[s[r]-'a']--;
            
            if(mp[s[r]-'a']==0)
            cnt--; 
            
            
            if(cnt==0){ //it indicates that all characters from p are there between r and l
                while(cnt==0){
                    if(r-l+1<minlen){
                        start=l;
                        minlen=r-l+1;
                    }
                    
                    mp[s[l]-'a']++;
                    
                    if(mp[s[l]-'a']==1) cnt++; //it means that a character from p is no more between l and r 
                    l++;
                }
            }
            
            r++;
        }
        
        if(minlen==INT_MAX)
        return "-1";
        
        else
        return s.substr(start,minlen);
    }
