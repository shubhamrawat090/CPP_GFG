class Solution {
  public:
    void segregate0and1(vector<int> &arr) {
        // code here
        int n = arr.size();
        int zero = 0, one = n-1;
        while(zero <= one) {
            if(arr[zero] == 0) {
                zero++;
            } else {
                swap(arr[zero], arr[one]);
                one--;
            }
        }
    }
};