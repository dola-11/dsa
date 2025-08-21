//My brute force

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) 
    {
        int n = nums.size();

        if (n==1)
        {
            return nums;
        }

        if (n == 2)
        {
            if (nums[0] == nums[1])
            {
                return {nums[0]};
            }
            else
            {
                return nums;
            }
        }
        int reqNo = n/3;
        vector<int>ans;
        int cnt = 1;

        sort(nums.begin(),nums.end());
        for (int i=1; i<n; i++)
        {
            if (nums[i] == nums[i-1])
            {
                cnt++;
                if (cnt == reqNo+1)
                {
                    ans.push_back(nums[i]);
                }
            }
            else
            {
                cnt = 1;
            }
        }
        return ans;
    }
};
//TC : O(nlogn) + O(n)
//SC : O(logn) (sort stack)
//At most 2 elements can appear more than ⌊n/3⌋ times (pigeonhole principle).
//So ans has size O(1), not dependent on n.

//approach 2:
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) 
    {
        vector<int>ans;
        int n = nums.size();
        int mini = (n/3) + 1;
        map<int,int>mpp;

        for (int i=0; i<n;i++)
        {
            mpp[nums[i]]++;
            if (mpp[nums[i]] == mini)
            {
                ans.push_back(nums[i]);
            }
            if (ans.size() == 2)
            {
                    break;
            }
        }
        return ans;
    }
};

//TC : O(N*logN)
//SC : O(N)

//Moore's voting algorithm
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums)
    {
        int n = nums.size();
        int cnt1 = 0;
        int cnt2 = 0;
        int el1 = INT_MIN;
        int el2 = INT_MIN;

        for (int i=0; i<n; i++)
        {
            if (cnt1 == 0 && nums[i] != el2)
            {
                cnt1 = 1;
                el1 = nums[i];
            }
            else if (cnt2 == 0 && nums[i] != el1)
            {
                cnt2 = 1;
                el2 = nums[i];
            }
            else if (el1 == nums[i]) cnt1++;
            else if (el2 == nums[i]) cnt2++;
            else
            {
                cnt1--;
                cnt2--;
            }
        }

        cnt1 = cnt2 = 0;
        for (int num : nums)
        {
            if (num == el1) cnt1++;
            else if (num == el2) cnt2++;
        }

        vector<int>ans;
        int mini = n/3 + 1;
        if (cnt1 >= mini) ans.push_back(el1);
        if (cnt2 >= mini) ans.push_back(el2);
        
        return ans;
    }
};

//Time: O(n) → one pass to find candidates + one pass to verify.
//Space : O(1)
