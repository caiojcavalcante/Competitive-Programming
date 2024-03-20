#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    int removeElement(vector<int> &nums, int val)
    {
        int last = nums.size();
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] == val)
            {
                nums[i--] = nums[--last];
                nums.pop_back();
            }
        }
        return nums.size() - last;
    }
};

int main()
{
    Solution s;
    s.removeElement(vector<int>{3, 2, 2, 3}, 3);
    return 0;
}