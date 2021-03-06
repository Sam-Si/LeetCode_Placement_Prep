// https://leetcode.com/problems/counting-bits/#/description
/*

Given a non negative integer number num. For every numbers i in the range 0 ≤ i ≤ num calculate the number of 1's in their binary representation and return them as an array.

Example:
For num = 5 you should return [0,1,1,2,1,2].

Follow up:

It is very easy to come up with a solution with run time O(n*sizeof(integer)). But can you do it in linear time O(n) /possibly in a single pass?
Space complexity should be O(n).
Can you do it like a boss? Do it without using any builtin function like __builtin_popcount in c++ or in any other language.

*/

// Brute Force Solution
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


// DP Solution
class Solution {
public:

    vector<int> countBits(int num) {
        vector<int> solution(num+1,0);
        for(int i = 0;i <= num;i++){
            solution[i] = solution[i>>1] + i%2;
        }
        return solution;
    }
};
