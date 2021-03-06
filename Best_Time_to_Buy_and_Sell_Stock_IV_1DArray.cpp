#include <iostream>
#include <vector>
#include <limits>
#include <algorithm>

using namespace std;


class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {

       if(prices.size()<2||k<=0) return 0;
       if(k>prices.size()) return maxProfitLarge(k,prices);
       int* local=new int[k+1]();
       int* global=new int[k+1]();
       for(int i=0;i<prices.size()-1;i++)
       {
           int diff=prices[i+1]-prices[i];
           for(int j=k;j>=1;j--)
           {
               local[j]=max(global[j-1]+max(diff,0),local[j]+diff);
               global[j]=max(local[j],global[j]);
           }
       }
       return global[k];
    }

    int maxProfitLarge(int k, vector<int>& prices){
        if(prices.size()<2||k<=0) return 0;
        int sum=0;
        for(int i=0;i<prices.size()-1;i++)
        {
            if(prices[i+1]-prices[i]>0)
            {
                sum=sum+prices[i+1]-prices[i];
            }
        }
        return sum;
    }
};
int main(){

    Solution s;
    vector<int> prices={1,2};
    cout<<s.maxProfit(1,prices)<<endl;
    return 0;
}
