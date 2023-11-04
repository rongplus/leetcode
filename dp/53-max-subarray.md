int maxSubArray(vector<int>& nums) {
        int local_max = 0;
        int global_max = INT_MIN;
        for (auto& v: nums)
        {
            local_max = max(v,v+local_max);
            if (local_max > global_max)
            global_max = local_max;
        }
        return global_max;
        }


        // kadane argritham