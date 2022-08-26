/* Harsh Kumar Sharma
 Roll No:2010992879
 Set-05
 Q-2
 */
 
#include <bits/stdc++.h>
using namespace std;

vector<pair<int, int>> findsubarray(int arr[], int n)
{
    unordered_map<int, vector<int>> map;

    // subarray starting and ending index
    vector<pair<int, int>> out;

    int sum = 0;

    for (int i = 0; i < n; i++)
    {
        sum += arr[i];

        if (sum == 0)
            out.push_back(make_pair(0, i));

        if (map.find(sum) != map.end())
        {
            vector<int> vc = map[sum];
            for (auto it = vc.begin(); it != vc.end(); it++)
                out.push_back(make_pair(*it + 1, i));
        }

        map[sum].push_back(i);
    }

    return out;
}

void print(vector<pair<int, int>> out, int arr[])
{
    for (auto it = out.begin(); it != out.end(); it++)
    {
        for (int i = it->first; i <= it->second; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
}

// Driver code
int main()
{
    int arr[] = {3, 4, -7, 3, 1, 3, 1, -4, -2, -2};
    int n = sizeof(arr) / sizeof(arr[0]);

    vector<pair<int, int>> out;

    try
    {
        out = findsubarray(arr, n);
        if (out.size() == 0)
            throw(0);
    }
    catch (int size)
    {
        cout << "Size is " << size << endl;
    }

    if (out.size() == 0)
        cout << "No subarray exists";
    else
        print(out, arr);

    return 0;
}

