![](http://i.imgur.com/EgJctA1.jpg)

class Solution {
public:
    int helper(int num){
        int count = 0;
        while(num > 0){
            count++;
            num = (num)&(num-1);
        }
        return count;
    }
    vector<int> countBits(int num) {
        vector<int> solution;
        for(int i = 0;i <= num;i++){
            int temp;
            temp = helper(i);
            solution.push_back(temp);
        }
        return solution;
    }
};
