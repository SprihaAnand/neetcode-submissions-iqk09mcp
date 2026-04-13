class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();
        vector<int> h;
        int l = 0, r=0;
        while(l<n && r<m){
            if(nums1[l]<nums2[r]){
                h.push_back(nums1[l]);
                l++;
            }
            else {
                h.push_back(nums2[r]);
                r++;
            }
        }
        while(l<n){
            h.push_back(nums1[l]);
            l++;
        }
        while(r<m) {
            h.push_back(nums2[r]);
            r++;
        }
        int tot = m+n;
        if(tot%2==0){
            //even
            return (double)(h[(tot/2)-1]+h[(tot/2)])/2;
        }
        else {
            return h[((tot+1)/2)-1];
        }
        return -1;
    }
};