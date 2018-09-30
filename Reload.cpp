#include <iostream>

//Kadane's Algorthim - Lineat Runtime - O(N)
//works as long as there in one postive number in the matrix
// For it to work with negative numbers - Start from 2nd item. Instead of initializing it = 0 . Set it to the first Element

int maxSubArray(int* arr, int size)
{

	int MaxTillHere = 0;
	int OverallMax = 0;

	for(int i=0;i <size ; i++)
	{
	    MaxTillHere += arr[i];

		if(MaxTillHere < 0)
			MaxTillHere = 0; //Set 0 if value is lower than 0
	
		if(OverallMax < MaxTillHere)
			OverallMax = MaxTillHere;
	
	}

	return OverallMax;



}





int main()
{

   int a[]  =  {-2, -3, 4, -1, -2, 1, 5, -3}; 
   int n = sizeof(a)/sizeof(a[0]); 
   std::cout << "Maximum Sum:" << maxSubArray(a,n);
   getchar();
   return 0;

}
