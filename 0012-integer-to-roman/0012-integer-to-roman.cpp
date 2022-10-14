class Solution {
public:
    string intToRoman(int nums) {
        map<int,string>hash;
        hash[1] = "I";
        hash[4] = "IV";
        hash[5] = "V";
        hash[9] = "IX";
        hash[10] = "X";
        hash[40] = "XL";
        hash[50] = "L";
        hash[90] = "XC";
        hash[100] = "C";
        hash[400] = "CD";
        hash[500] = "D";
        hash[900] = "CM";
        hash[1000] = "M";
        
        string res = "";
        int rem = 0;
        int place = 1;
        while(nums>0){
            if(rem == 0){
                rem = nums%10 * place;
                place*=10;
                nums/=10;
                string temp = "";
                while(rem>0){
                    auto it = hash.upper_bound(rem);
                    it--;
                    temp += it->second;
                    rem -= it->first;
                }
                res = temp + res;
            }
            
        }
        return res;
    }
};
        // hash['I' - 'A'] = 1;
        // hash['V' - 'A'] = 5;
        // hash['X' - 'A'] = 10;
        // hash['L' - 'A'] = 50;
        // hash['C' - 'A'] = 100;
        // hash['D' - 'A'] = 500;
        // hash['M' - 'M'] = 1000;