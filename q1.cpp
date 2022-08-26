/* Harsh Kumar Sharma
 Roll No:2010992879
 Set-05
 Q-1
 */
#include <bits/stdc++.h>
using namespace std;

int lenoflongsubarr(int nums[],int n,int x)
{
    unordered_map<int, int> sub;//unordered map
    int sum = 0, max = 0;

    for (int i = 0; i < n; i++)
    {

        sum += nums[i];

        if (sum == x)
            max = i + 1;

        if (sub.find(sum) == sub.end())
            sub[sum] = i;

        if (sub.find(sum - x) != sub.end())
        {  

            if (max < (i - sub[sum - x]))
                max = i - sub[sum - x];
        }
        
    }
    
    cout<<"The Longest subarray is {} having length "<<max<<endl;
    return 0;
}
    


int main() {
    int nums[]={5,6,-5,5,3,5,3,-2,0};
    int n = sizeof(nums) / sizeof(nums[0]);//size of nums array
    int x = 8;
    int temp;

    try//Exception Handling
    {
        temp = lenoflongsubarr(nums, n, x);
        if (!temp)
            throw("No subarray found");
    }
    catch (int error)
    {
        cout << "Error: " << error << endl;
    }

    cout << "Length = " << temp;
    
    
    
    
    
    
    
    

    return 0;
}
