/*1st approach
Time Complexity - O(n^3)*/
class Solution{
public:
	bool recreationalSpot(int arr[], int n)
	{
		// Your code goes here 
		for(int i = 0; i < n-2; ++i)
		{
		    for(int j = i+1; j < n-1; ++j)
		    {
		        for(int k = j+1; k < n; ++k)
		        {
		            if(arr[i] < arr[k] && arr[j] > arr[k])
		                return true;
		        }
		    }
		}                      
		return false;
	}
};


/*2nd approach
Time Complexity - O(n^2)*/
class Solution{
public:
	bool recreationalSpot(int arr[], int n)
	{
		// Your code goes here 
		int leftmin = arr[0];
		for(int j = 1; j < n-1; ++j)
		{
		    for(int k = j+1; k < n; ++k)
		    {
		        if(arr[k] > leftmin && arr[k] < arr[j])
		            return true;
		    }
		    leftmin = min(leftmin,arr[j]);
		}
		return false;
	}
};
