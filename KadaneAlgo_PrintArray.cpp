#include <iostream>
#include <list>

//Kadane's Algorthim - Linear Runtime - O(N)
//works as long as there in one postive number in the matrix
// For it to work with negative numbers - Start from 2nd item. Instead of initializing it = 0 . Set it to the first Element

int maxSubArray(int arr[], int size)
{

	int MaxTillHere = 0;
	int OverallMax = 0;
	int TempBeginIndex = 0;
	int FinalBeginIndex = 0;
	int endIndex = 0;
	bool IsNMinusOneZer0 = false;


	for(int i=0;i <size ; i++)
	{
	    MaxTillHere += arr[i];
		
	
		if(IsNMinusOneZer0 && MaxTillHere > 0 )
		{
		   TempBeginIndex = i;
		   IsNMinusOneZer0 =false;
		}
		else if(MaxTillHere < 0)
		{
			MaxTillHere = 0; //Set 0 if value is lower than 0
			IsNMinusOneZer0 = true;
		}
	
	
		if(OverallMax < MaxTillHere)
		{
			endIndex = i;
			FinalBeginIndex = TempBeginIndex;
			OverallMax = MaxTillHere;
		}
	
	}

	for(int i=FinalBeginIndex;i <=endIndex ; i++)
	{
	  std::cout << "The Sub Array:" << arr[i] << "\n";
	}

	return OverallMax;



}





int main()
{

   int a[]  =  {-2, -3, 4, -1, -2, 12, 5, -3, 18, -57 ,4, -1, -2, 12, 5, -3, 11}; 

   int n = sizeof(a)/sizeof(a[0]); 
   std::cout << "Maximum Sum:" << maxSubArray(a,n);
   getchar();
   return 0;

}
