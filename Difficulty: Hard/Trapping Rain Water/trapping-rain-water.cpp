class Solution {
  public:
    int maxWater(vector<int> &height) {
        // code here
        int l = 0;
        int r = height.size() - 1;
        int lmax = 0;
        int rmax = 0;
        int ans = 0;
        while (l < r) {

            if (height[l] < height[r]) {
                lmax = max(lmax, height[l]);

                ans += (lmax - height[l]);
                l++;
            } else {
                rmax = max(rmax, height[r]);
                ans += (rmax - height[r]);
                r--;
            }
        }
        return ans;
    }
};