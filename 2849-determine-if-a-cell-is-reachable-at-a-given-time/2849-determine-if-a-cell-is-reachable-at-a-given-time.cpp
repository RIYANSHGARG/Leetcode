class Solution {
public:
    bool isReachableAtTime(int sx, int sy, int fx, int fy, int t) {
        int a=abs(fx-sx),b=abs(fy-sy);
        if(sx==fx && sy==fy && t==1)    return false;
        int minTime = min(a,b)+(max(a,b) - min(a,b));
        cout<<minTime;
        return (t>=minTime);
    }
};