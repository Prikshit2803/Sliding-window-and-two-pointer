//TLE brute forceish

class Solution{
  public:
    int longestKSubstr(string s, int k) {
    
    map<int,int> mp;
    int maxlen=0;
    
    for(int i=0;i<s.length();i++){
        int cnt=0;
        int len=0;
        while(i<s.length() && cnt<=k){
            if(mp.find(s[i])==mp.end()){
                mp[s[i]]++;
                cnt++;
            }
            
            if(cnt<=k)
            len++;
        }
        
        if(cnt==k)
        maxlen=max(maxlen,len);
        
    }
    
    return maxlen;
    }
};

//working soln

   int longestKSubstr(string s, int k) {
    
    unordered_map<char,int> mp;
    int maxlen=-1;
    
    int l=0,r=0;
    
    int cnt=0;
        while( r<s.length()){
            
            
                mp[s[r]]++;
                
                 if(mp.size()<k)
                    r++;
                    
            else if(mp.size()==k)
            {
                maxlen=max(maxlen,r-l+1);
                r++;
            }
            
            
            else  if(mp.size()>k)
            {
                while(mp.size()>k)
                {
                    mp[s[l]]--;
                    if(mp[s[l]]==0)
                        mp.erase(s[l]);
                    l++;
                }
                r++;
            }
            
            
            
        }
        
        return maxlen;
    }
