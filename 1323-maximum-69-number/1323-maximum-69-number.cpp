class Solution {
public:
    int maximum69Number (int num) {
        
        int copy_num = num;
        int i = 1;
        int idx = -1;
        
        while(num){
            
            int rem = num%10;
            num /= 10;
            
            if(rem == 6){
                idx = i;   
            }
            i++;
        }
        
        if(idx == -1)return copy_num;
        
        return copy_num+3*pow(10,idx-1);
    }
};
//9 6 6 9
//  <-
//while
//count i from back
//update pair
//if()