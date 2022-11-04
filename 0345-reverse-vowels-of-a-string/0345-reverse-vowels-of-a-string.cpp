class Solution {
public:
    string reverseVowels(string s) {
        
        int n = s.length();
        //two ptr
        int ptr1 = 0;
        int ptr2 = n-1;
        
        while(ptr1 <= ptr2){
            
            //searching valid ptr1
            char lower_ptr1 = tolower(s[ptr1]);
            while(lower_ptr1!='a' && lower_ptr1!='e' && lower_ptr1!='i' && lower_ptr1!= 'o' && lower_ptr1!='u')
            {
                ptr1++;
                if(ptr1 == n)break;
                lower_ptr1 = tolower(s[ptr1]);
            }

            //searching valid ptr2
            char lower_ptr2 = tolower(s[ptr2]);
            while(tolower(s[ptr2])!='a' && tolower(s[ptr2])!='e' && tolower(s[ptr2])!='i' && tolower(s[ptr2])!= 'o' && tolower(s[ptr2])!='u')
            {
                ptr2--;
                if(ptr2 == -1)break;
                lower_ptr2 = tolower(s[ptr2]);
            }
            
            //handling ptr1 >= n && ptr2 < 0
            if(ptr1 >= n || ptr2 < 0 || ptr1 > ptr2){
                break;
            }
            
            //now I have both valid ptr1 and ptr2
            swap(s[ptr1],s[ptr2]);
            ptr1++,ptr2--;
        }
        return s;
    }
};
//0 1 2 3 4 5 6 7 8 9
//a b c d e f g h i j  intput
//i b c d e f g h a j  output
//traverse from both the side and need to swap;
//two pointer approach
//if they have crossed each other then I have to stop