class Solution {
  public:
    int minMeetingRooms(vector<int> &start, vector<int> &end) {
        sort(start.begin(), start.end());
        sort(end.begin(), end.end());
        int s = 0, e = 0, rooms = 0, maxRooms = 0;
        int n = start.size();
        while(s < n && e < n) {
            if(start[s] < end[e]) {
                rooms++;
                s++;
            } else {
                rooms--;
                e++;
            }
            maxRooms = max(maxRooms, rooms);
        }
        return maxRooms;
    }
};
