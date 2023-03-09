#include "basic.h"
#include <cmath>


class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {

        int n=nums.size();
        int result=0;
        int temp;

        int TempResult;
        int TempResultPlus;

        for(int i=0;i<n-2;i++){
            for(int i2=i+1;i2<n-1;i2++){
                for(int i3=i2+1;i3<n;i3++){
                    TempResult=nums[i]+nums[i2]+nums[i3];

                    if (TempResult>=0){
                        result = abs(TempResult - target ) < abs(temp-target) ? TempResult : temp;
                        temp=TempResult;

                    }




                }
            }
        }

        return result;

    }
};


int main(){

    Solution s;
    vector<int> vi;
    vi.push_back(-1);
    vi.push_back(2);
    vi.push_back(1);
    vi.push_back(-4);

    int result=s.threeSumClosest(vi,1);
    cout << result << endl;




    return 0;
}