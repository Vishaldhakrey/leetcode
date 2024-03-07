class Solution {
public:
    int partition(std::vector<int>& nums, int low, int high) {
        srand(time(0)); // Seed the random number generator with current time
        int pivotIndex = low + rand() % (high - low + 1);
        
        // Swap the element at pivotIndex with the element at low position
        std::swap(nums[low], nums[pivotIndex]);
        int pivot = nums[low];
        int i = low;
        int j = high;

        while (i < j) {
            while (i <= high && nums[i] <= pivot) {
                i++;
            }

            while (j >= low && nums[j] > pivot) {
                j--;
            }
            if (i < j) {
                std::swap(nums[i], nums[j]);
            }
        }
        std::swap(nums[low], nums[j]);
        return j;
    }

    void quickSort(std::vector<int>& nums, int low, int high) {
        while (low < high) {
            int partIndex = partition(nums, low, high);
            quickSort(nums, low, partIndex - 1);
            low = partIndex + 1;
        }
    }

    std::vector<int> sortArray(std::vector<int>& nums) {
        quickSort(nums, 0, nums.size() - 1);
        return nums;
    }
};