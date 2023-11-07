class Solution {
public:
    int eliminateMaximum(vector<int>& dist, vector<int>& speed) {
//         if(dist.size()==1)  return 1;
//         int ans=0;
        
//         for(int i=0;i<dist.size();i++){
//             sort(dist.begin()+i+1 , dist.end());
//             if(dist[i]==0)  return ans;
//             for(int j=i+1;j<dist.size();j++){
//                 if(dist[j]-speed[j] <= 0)   dist[j]=0;
//                 else    dist[j]=dist[j]-speed[j];
//             }
//             ans++;
//         }
//         return ans;
        
        vector<double> temp;
        for(int i=0;i<dist.size();i++){
            temp.push_back(  ceil(1.0*dist[i]/speed[i]) );
        }
        sort(temp.begin(),temp.end());
        int time=1;
        for(int i=0;i<temp.size();i++){
            if(time>temp[i])    return i;
            time++;
        }
        return temp.size();
    }
};