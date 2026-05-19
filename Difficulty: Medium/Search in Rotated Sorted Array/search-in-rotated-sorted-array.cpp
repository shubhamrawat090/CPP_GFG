class Solution {
  public:
    int search(vector<int>& arr, int key) {
        // low, mid, high: leftRange = low..mid, rightRange = mid...high
        // if: low <= mid then leftRange is sorted
        // else: rightRange is sorted
        // After getting which range is sorted CHECK IF key IS INSIDE SORTED RANGE
        // EXAMPLE:
        // if leftRange sorted AND key is inside leftRange then high = mid-1; // GO LEFT
        // else: low = mid+1; // GO RIGHT
        // AND VICE VERSA
        int low = 0, high = arr.size()-1;
        while(low <= high) {
            int mid = (low + high) / 2;
            if(arr[mid] == key) return mid;
            
            // is left range sorted?
            if(arr[low] <= arr[mid]) {// LEFT RANGE SORTED
                // is key inside left range?
                if(key >= arr[low] && key <= arr[mid]) {
                    high = mid-1; // go left
                } else {
                    low = mid+1; // go right
                }
            } else {// RIGHT RANGE SORTED
                // is key inside right range?
                if(key >= arr[mid] && key <= arr[high]) {
                    low = mid+1; // go right
                } else {
                    high = mid-1; // go left
                }
            }
        }
        return -1;
    }
};