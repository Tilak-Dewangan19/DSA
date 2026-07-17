class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int totgas = 0;
        int totcost = 0;
        for(int val : gas){
            totgas += val;
        }
        for(int val : cost){
            totcost += val;
        }
        if(totgas< totcost) return -1;
         int curgas =0; int start = 0;
        for(int i =0; i< gas.size(); i++){
           
            curgas = curgas+(gas[i] - cost[i]);
            if(curgas < 0) {
                    start = i+1;
                    curgas = 0;
            }
        }
        return start;
    }
};