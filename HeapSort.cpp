class Solution {
public:
    void heapify(vector<int> &nums,int i, int sz){
        int largest = i;
        int left = 2*i+1;
        int right = 2*i+2;
        if(left<sz and nums[left]>nums[largest]) largest = left;
        if(right<sz and nums[right]>nums[largest])   largest = right;
        if(largest!=i){
            swap(nums[i],nums[largest]);
            heapify(nums,largest,sz);
        }
    }
    vector<int> sortArray(vector<int>& nums) {
        int n = nums.size();

        for(int i=n/2-1;i>=0;i--){
            heapify(nums,i,n);
        }

        int sz = n;

        for(int i=n-1;i>0;i--){
            swap(nums[i],nums[0]);
            sz--;
            heapify(nums,0,sz);
        }

        // reverse(nums.begin(),nums.end());
        return nums;
    }
};
