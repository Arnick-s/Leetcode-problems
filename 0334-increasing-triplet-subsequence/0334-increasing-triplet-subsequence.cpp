#include "bits/stdc++.h"
class Solution {
public:
    void conquer(vector<pair<int,int>>&nums,int& si,int& mid, int& ei,set<pair<int,int>>& fir,set<pair<int,int>>&sec,bool & ans){
        vector<pair<int,int>> temp(ei - si + 1);
        
        int x = 0;
        int idx1 = si;
        int idx2 = mid + 1 ;
        
        while(idx1 <= mid && idx2 <= ei){
            if(nums[idx1].first<nums[idx2].first){
                temp[x] = nums[idx1];
                auto itFir = fir.find(nums[idx2]);
                auto itSec = sec.find(nums[idx1]);
                
                if( itFir== fir.end() && itSec == sec.end())
                {
                    fir.insert(nums[idx1]);
                    sec.insert(nums[idx2]);
                }else{
                    ans = true;
                    return;
                }
                
                x++,idx1++;
            }else{
                temp[x] = nums[idx2];
                x++,idx2++;
            }
        }
        while(idx1<=mid)
        {
            temp[x] = nums[idx1];
            x++,idx1++;
        }
        while(idx2<=ei){
            temp[x] = nums[idx2];
                x++,idx2++;
        }
        
        for(int i = 0,j = si;i<temp.size();i++,j++){
            nums[j] = temp[i];
        }
        return;
        
    }
    
    void divide(vector<pair<int,int>>&nums,int si,int ei,set<pair<int,int>> &fir,set<pair<int,int>>&sec,bool& ans){
        if(si == ei)return;
        
        int mid = si + (ei-si)/2;
        
        if(ans == false)
            divide(nums,si,mid,fir,sec,ans);
        if(ans == false)
            divide(nums,mid+1,ei,fir,sec,ans);
        
        if(ans == true) return;
        conquer(nums,si,mid,ei,fir,sec,ans);
        // inplace_merge(nums.begin()+si,nums.begin()+mid+1,nums.begin()+ei+1);
    }
    
    bool increasingTriplet(vector<int>& nums) {
        int n = nums.size();
        set<pair<int,int>> first,second;
        bool ans = false;
        vector<pair<int,int>> numIdx(n);
        for(int i = 0;i<n;i++){
            numIdx[i] = {nums[i],i};
        }
        divide(numIdx,0,n-1,first,second,ans);
        
        return ans;
    }
};