class Solution {
public:
    int thirdMax(vector<int>& nums) {
        long long largest = LLONG_MIN;
        long long second = LLONG_MIN;
        long long third = LLONG_MIN;
        
        for(int i:nums){
            if(i>largest){
                third=second;
                second=largest;
                largest=i;
            }
            else if(i>second && i!=largest){
                third=second;
                second=i;
            }
            else if(i>third && i!=second && i!=largest){
                third=i;
            }
        }
        if (third == LLONG_MIN)
            return largest;

        return third;
    }
};