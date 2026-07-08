class Solution {
  public:
    void segregate0and1(vector<int> &arr) {
        // code here
        int n = arr.size();
        int left = 0, right = n-1;
        while(left < right) {
            if(arr[left] == 0) left++;
            else {
                swap(arr[left], arr[right]);
                right--;
            }
        }
    }
};