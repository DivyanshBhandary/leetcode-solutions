class Solution {
  public:

    bool is_valid(long long mid, vector<int> &arr, int k) {
        int cnt = 1;
        long long curr = 0;

        for (int i = 0; i < arr.size(); i++) {

            if (curr + arr[i] > mid) {
                cnt++;
                curr = arr[i];
            }
            else {
                curr += arr[i];
            }

            if (cnt > k)
                return false;
        }

        return true;
    }

    int shipWithinDays(vector<int> &arr, int k) {

        int n = arr.size();

        if (k > n)
            return -1;

        long long low = 0;
        long long high = 0;

        for (int i = 0; i < n; i++) {
            low = max(low, (long long)arr[i]);
            high += arr[i];
        }

        long long ans = -1;

        while (low <= high) {

            long long mid = low + (high - low) / 2;

            if (is_valid(mid, arr, k)) {
                ans = mid;
                high = mid - 1;
            }
            else {
                low = mid + 1;
            }
        }

        return (int)ans;
    }
};