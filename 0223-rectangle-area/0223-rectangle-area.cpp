class Solution {
public:
        
        int get_area(int&ax1,int&ay1,int&ax2,int&ay2){
                return abs(ay2 - ay1)*abs(ax2 - ax1);
        }       
        bool checkPoints(pair<int,int>&pt,int&bx1,int&by1,int&bx2,int&by2){
                if(pt.first<=bx2 && pt.first>=bx1 && pt.second<=by2 && pt.second>=by1)
                        return true;
                return false;
        }
        int noOfPointLiesInside(int&ax1,int&ay1,int&ax2,int&ay2,int&bx1,int&by1,int&bx2,int&by2,vector<pair<int,int>>&rec){
                //points of a with respect to b;
                vector<pair<int,int>>points(4);
                points[0] = {ax1,ay1};
                points[1] = {ax1,ay2};
                points[2] = {ax2,ay1};
                points[3] = {ax2,ay2};
                
                int cnt = 0;
                
                for(int i = 0;i<4;i++){
                        if(checkPoints(points[i],bx1,by1,bx2,by2))
                        {
                                cnt++;
                                rec.push_back(points[i]);
                        }
                }
                
                return cnt;
        }
        int computeArea(int ax1, int ay1, int ax2, int ay2, int bx1, int by1, int bx2, int by2) {
                
                vector<pair<int,int>>reca;
                vector<pair<int,int>>recb;
                int a_points_in_b = noOfPointLiesInside(ax1,ay1,ax2,ay2,bx1,by1,bx2,by2,reca);
                int b_points_in_a = noOfPointLiesInside(bx1,by1,bx2,by2,ax1,ay1,ax2,ay2,recb);
                
                // cout<<"a in b "<<a_points_in_b<<" b in a "<<b_points_in_a<<endl;
                
                int total_area = get_area(ax1,ay1,ax2,ay2) + get_area(bx1,by1,bx2,by2);
                
                 if(a_points_in_b == b_points_in_a && a_points_in_b == 0)
                 {
                         if(bx1<=ax1 && ax2<=bx2 && ay1<=by1 && by2<=ay2)
                         {
                                 return total_area - (ax2 - ax1)*(by2 - by1);
                         }else if(by1<=ay1 && ay2<=by2 && ax1<=bx1 && bx2<=ax2){
                                 return total_area - (ay2 - ay1)*(bx2 - bx1);
                         }else{
                                 return total_area;
                         }
                                 
                 }
                else if(a_points_in_b == 4 || b_points_in_a == 4){
                        
                        if(a_points_in_b == 4){
                                return total_area - get_area(ax1,ay1,ax2,ay2);
                        }else{
                                return total_area - get_area(bx1,by1,bx2,by2);
                        }
                        
                }
                else if(a_points_in_b == 2 || b_points_in_a == 2){
                        
                        if(a_points_in_b == 2){
                                
                                bool x = (reca[0].first == reca[1].first) ? true : false;
                                
                                if(x){
                                        if(reca[0].first == ax1)
                                                return total_area - get_area(ax1,ay1,bx2,ay2);
                                        else return total_area - get_area(bx1,ay1,ax2,ay2);
                                }else{
                                        if(reca[0].second == ay1){
                                                return total_area - get_area(ax1,ay1,ax2,by2);
                                        }else return total_area - get_area(ax1,by1,ax2,ay2);
                                }
                        }else{
                                
                                bool x = (recb[0].first == recb[1].first) ? true : false;
                                
                                if(x){
                                        if(recb[0].first == bx1)
                                                return total_area - get_area(bx1,by1,ax2,by2);
                                        else return total_area - get_area(ax1,by1,bx2,by2);
                                }else{
                                        
                                        if(recb[0].second == by1){
                                                return total_area - get_area(bx1,by1,bx2,ay2);
                                        }else return total_area - get_area(bx1,ay1,bx2,by2);
                                }
                                
                        }
                }else if(a_points_in_b == 1 && b_points_in_a == 1){
                        return total_area - abs(reca[0].first - recb[0].first)*abs(reca[0].second - recb[0].second);
                        
                }
                return 0;
        }
};