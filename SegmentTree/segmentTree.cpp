//307. Range Sum Query - Mutable -Leetcode Question

class NumArray {
private:
    int maxN;
    vector<int> seg;
    void seg_build(int i, int low, int high, vector<int> &nums) {
        if(low == high) {
            seg[i] = nums[low];
            return;
        }
        int mid = low + (high - low) / 2;
        seg_build(2 * i + 1, low, mid, nums);
        seg_build(2 * i + 2, mid + 1, high, nums);
        seg[i] = seg[2 * i + 1] + seg[2 * i + 2];
    }
    void seg_update(int i, int low, int high, int node, int val) {
        if(low == high) {
            seg[i] = val;
            return;
        }
        int mid = low + (high - low) / 2;
        if(node <= mid) {
            seg_update(2 * i + 1, low, mid, node, val);
        } else {
            seg_update(2 * i + 2, mid + 1, high, node, val);
        }
        seg[i] = seg[2 * i + 1] + seg[2 * i + 2];
    }
    int seg_query(int i, int low, int high, int l, int r) {
        if(low > r || high < l) {
            return 0;
        }
        if(low >= l && high <= r) {
            return seg[i];
        }
        int mid = low + (high - low) / 2;
        int ll = seg_query(2 * i + 1, low, mid, l, r);
        int rr = seg_query(2 * i + 2, mid + 1, high, l, r);
        return ll + rr;
    }
public:
    NumArray(vector<int>& nums) {
        maxN = nums.size();
        seg.resize(maxN * 4 + 10, 0);
        seg_build(0, 0, maxN - 1, nums);
    }
    void update(int index, int val) {
        seg_update(0, 0, maxN - 1, index, val);
    }
    int sumRange(int l, int r) {
        return seg_query(0, 0, maxN - 1, l, r);
    }
};