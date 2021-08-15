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
