class Solution {
public:
    vector<int> pathInZigZagTree(int label) {
        vector<int> traversal;
        //tot possible level
        int l_height;
        for(int i = 1;i<33;i++){
            if(pow(2,i)>label){
                l_height = i;
                break;
            }    
        }
        bool even = false;
                
        while(label){
            int zigzag_label = label;
            // cout<<"label = "<<label<<' '<<"currHeight"<<l_height<<endl;
            if(even){
                int start = pow(2,l_height-1);
                int end = pow(2,l_height) -1;
                int edgeDiff = min(label - start,end - label);
                int tot = end - start + 1;
                int mirrorVal = tot - 2*edgeDiff -1;
                
                // cout<<" s = "<<start<<' '<<"end="<<end<<' '<<"edgeDiff="<<edgeDiff<<' '<<"total="<<tot<<' '<<"mirrorVal="<<mirrorVal<<endl;
                if(end - label < label - start) mirrorVal = -mirrorVal;
                
                zigzag_label += mirrorVal;
            }
            traversal.emplace_back(zigzag_label);
            label/=2;
            even = !even;
            l_height--;
        }
        reverse(traversal.begin(),traversal.end());
        return traversal;
    }
};

// dfs and bfs
// preOrder, InOrder, PostOrder
// levelOrder

//simple case
//           1
//        2     3
//      4   5  6  7
// pushing in vec while dividing by 2
// for label = 4 -> 1,2,4
// 4 -> 2 -> 1
// 4 -> 3 -> 1

// for 10 & 13 swap the level == 4 
// no of node at any level => if level = r then no_of_nodes = 2^r - 1;
// for 4th level -> noOfNodes = 2^4 - 1 = 15

// label = 20
//normal output = 20->10->5->2->1
//zigzag output = 20->13->5->3->1
//first ele label l => (2^(l-1)) -> 8 for level 4;
//start = 8 and 10 ... 13 and end = 2^(l-1) + start == 15
//end - start + 1 - min(start - label,end - label)-1 +- label