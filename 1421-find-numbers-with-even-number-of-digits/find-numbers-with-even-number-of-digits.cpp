class Solution {
public:
    int findNumbers(vector<int>& nums) 
    {
        int count=0;
        for (int i =0; i<nums.size(); i++)
        {
          int num= nums[i];
          int digit=0;
          while( num > 0)
          {
            digit++;
            num/=10;
          }
          if (digit%2==0)
          {
            count++;
          }
        }
        return count;
    }
};