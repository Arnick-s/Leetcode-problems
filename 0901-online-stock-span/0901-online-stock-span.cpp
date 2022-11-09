class StockSpanner {
public:
    vector<int> vec;
    StockSpanner() {
        
    }
    
    int next(int price) {
        
        int ptr = vec.size() -1;
        while(ptr>-1 && vec[ptr]<=price){
            ptr--;
        }
        
        vec.emplace_back(price);
        return vec.size()-1 - ptr;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */