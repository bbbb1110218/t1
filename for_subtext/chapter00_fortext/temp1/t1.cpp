#include <iostream>
#include<vector>
#include <memory>
#include <hashtable>

using namespace std;


class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {

       
        int a=nums.size();
        for(int i=0;i<a;i++)
        {
            for(int ii=0;ii<i+1;ii++){
                if (nums[i]+nums[ii]==target)
                {
                    return {i,ii};
                }
            }
        }
        return {};
        
        
        
    }
};

class Solution1 {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> hashtable;
        for (int i = 0; i < nums.size(); ++i) {
            auto it = hashtable.find(target - nums[i]);
            if (it != hashtable.end()) {
                return {it->second, i};
            }
            hashtable[nums[i]] = i;
        }
        return {};
    }
};





int main(){

	Solution1 s;
	vector<int> vi;
	for (int i=0;i<100;i++){
		vi.push_back(i);
	}

	vector<int> result=s.twoSum(vi,19);

	for(int i=0;i<result.size();i++){
		cout << result[i] << "- >";
	}


	return 0;
}