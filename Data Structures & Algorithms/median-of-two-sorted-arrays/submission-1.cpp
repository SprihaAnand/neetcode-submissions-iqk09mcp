class Solution {
public:
    double findMedianSortedArrays(vector<int>& a, vector<int>& b) {
        if(a.size()<b.size()) swap(a,b);
        int l = -1;
        int r = b.size()-1;
        int tot = a.size()+b.size();
        int half = tot/2;
        while(true){
            int i = (l+r)/2;
            int j = half-i-2;

            int bleft = (i>=0)? b[i]:INT_MIN;
            int bright = (i+1<b.size())? b[i+1]:INT_MAX;
            int aleft = (j>=0)? a[j]:INT_MIN;
            int aright = (j+1<a.size())? a[j+1]:INT_MAX;

            if(aleft<=bright && bleft<=aright){
                if(tot%2==0){
                    return (double)(max(aleft, bleft)+min(aright, bright))/2.0;
                }
                else {
                    return (min(aright, bright));
                }
            }
            else if(aleft>bright){
                l = i+1;
            }
            else {
                r = i-1;
            }
        }
        return -1;
    }
};
