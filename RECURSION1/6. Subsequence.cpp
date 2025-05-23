//Print all possible subsequences
#include <bits/stdc++.h>
using namespace std;
void allSubsequence(int ind, vector<int>& ds,int n, int arr[])
{
    if (ind == n)
    {
        for (auto it : ds)
        {
            cout << it << " ";
        }
        if (ds.size() == 0)
        {
            cout << "{}";
        }
        cout << endl;
        return;
    }
    
    ds.push_back(arr[ind]);
    allSubsequence(ind+1,ds,n,arr);
    ds.pop_back();
    allSubsequence(ind+1,ds,n,arr);
}

int main() {
	int arr[] = {3,2,1};
	int n = 3;
	vector<int>ds;
    allSubsequence(0,ds,n,arr);
}


//TC : O(n*2^n)
//SC : O(n)


//Printing the subsequences that are equal to the target
void allSubsequence(int ind, vector<int>& ds,int s, int sum, int arr[], int n)
{
    if (ind == n)
    {
        if (s == sum)
        {
            for (auto it : ds)
            {
                cout << it << " ";
            }
            cout << endl;
        }
        return;
    }
    
    ds.push_back(arr[ind]);
    s += arr[ind];
    
    allSubsequence(ind+1,ds,s,sum,arr,n);
    
    s -= arr[ind];
    ds.pop_back();
    
    allSubsequence(ind+1,ds,s,sum,arr,n);
}

int main() {
	int arr[] = {1,2,1};
	int n = 3;
	int sum = 2;
	vector<int>ds;
    allSubsequence(0,ds,0,sum,arr,n);
}

//Printing any 1 subsequence that is equal to the target

//avoiding future recursion calls by using the bool func

#include <bits/stdc++.h>
using namespace std;
bool allSubsequence(int ind, vector<int>&ds,int s, int sum, int arr[], int n)
{
    if (ind == n)
    {
        //condition satisfied
        if (s == sum)
        {
            for (auto it : ds)
            {
                cout << it << " ";
            }
            cout << endl;
            return true;
        }
        //condition not satisfied
        return false;
    }
    
    ds.push_back(arr[ind]);
    s += arr[ind];
    
    if (allSubsequence(ind+1,ds,s,sum,arr,n) == true) return true ;

    s -= arr[ind];
    ds.pop_back();
    
    if (allSubsequence(ind+1,ds,s,sum,arr,n) == true) return true ;
    
    return false;
}

int main() {
	int arr[] = {1,2,1};
	int n = 3;
	int sum = 2;
	vector<int>ds;
	 allSubsequence(0,ds,0,sum,arr,n);
}


//Count the no of subsets with sum = target
#include <bits/stdc++.h>
using namespace std;
int allSubsequence(int ind, int s, int sum, int arr[], int n)
{
    if (ind == n)
    {
        //condition satisfied
        if (s == sum)
        {
            return 1;
        }
        //condition not satisfied
        return 0;
    }
    
    s += arr[ind];
    
    int l = allSubsequence(ind+1,s,sum,arr,n) ;

    s -= arr[ind];

    int r = allSubsequence(ind+1,s,sum,arr,n) ;
    
    return l+r;
}

int main() {
	int arr[] = {1,2,1};
	int n = 3;
	int sum = 2;
    cout << allSubsequence(0,0,sum,arr,n);
}
