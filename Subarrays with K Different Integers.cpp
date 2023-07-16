//TLE : My approach
int subarrayCount(vector<int> &arr, int N, int k) {
        
        map<int,int> mp;
        
        int l=0,r=0;
        int cnt=0;
        
        while(l<N){
            mp.clear();
            r=l;
        while(r<N){
            
            mp[arr[r]]++;
            
            if(mp.size()<k)
            r++;
            
            else if(mp.size()==k){
                cnt++;
                r++;
            }
            
            else if(mp.size()>k){
                mp[arr[r]]--;
                if(mp[arr[r]]==0)
                mp.erase(arr[r]);
                r++;
                }
            }
           l++; 
        }
        
        return cnt;
        }

//use of map gives tle hnce use vector

/intuition being get number of subarrays with atmost k integers then subtract subarrays with atmost k-1 integers
    
    int solve(vector<int> &arr, int n, int k){
          map<int,int> mp;
        int i=0;//left pointer
        int j=0;//right pointer
        int cnt=0;
        int ans=0;
        
        while(j<n){
            if(mp[arr[j]]==0)
            cnt++;
            
            mp[arr[j]]++;
            
            while(cnt>k){
                mp[arr[i]]--;
                if(mp[arr[i]]==0){
                    cnt--;
                }
                i++;
            }
            
            ans+=(j-i+1); //gives all combinations upto k different integers
            
            j++;
        }
        return ans;
    }
    int subarrayCount(vector<int> &arr, int N, int k) {
        
      
        
        return solve(arr,N,k)-solve(arr,N,k-1);
        
        
        }

//with vector<intt>
  int solve(vector<int> &arr, int n, int k,int maxi){
          //map<int,int> mp;
           vector<int> mp (maxi,0);
        int i=0;//left pointer
        int j=0;//right pointer
        int cnt=0;
        int ans=0;
        
        while(j<n){
            if(mp[arr[j]]==0)
            cnt++;
            
            mp[arr[j]]++;
            
            while(cnt>k){
                mp[arr[i]]--;
                if(mp[arr[i]]==0){
                    cnt--;
                }
                i++;
            }
            
            ans+=(j-i+1); //gives all combinations upto k different integers
            
            j++;
        }
        return ans;
    }
    int subarrayCount(vector<int> &arr, int N, int k) {
        
      int maxi = 0;
        for(int  i = 0 ; i< N ;i++)
        {
            maxi = max(maxi,arr[i]);
        }
        
        return solve(arr,N,k,maxi+1)-solve(arr,N,k-1,maxi+1);
        
        
        }

};
