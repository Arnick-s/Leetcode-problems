/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is higher than the picked number
 *			      1 if num is lower than the picked number
 *               otherwise return 0
 * int guess(int num);
 */
class Solution {
public:
    int guessNumber(int n) {
        
        long long l = 0;
        long long r = n;
        r++;
        while(r-l>1){
            int mid = l + (r-l)/2;
            int val = guess(mid);
            
            if(val == 0 || val == -1){
                r = mid;
            }
            else
                l = mid;
        }
        return r;
    }
};