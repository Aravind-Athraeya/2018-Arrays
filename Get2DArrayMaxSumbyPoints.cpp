#include <iostream>
#include <list>

#define N 4 

/// First - Calculate an auxilary matrix with an additonal row and additional column-- Ref: https://www.youtube.com/watch?v=PwDqpOMwg6U
///  Fill up first row and column with zero
// Calculate the sum for the second row and second column alone
// Then use the formula to piggy pack on values from second row and column computation - Use formaule to subtract duplicates
// Use another formula to get the values
// Kadane for 1D array and preprocess for 2D array
//Tushor Roy -Reference

 int preProcess[N+1][N +1];

void SumQuery(int mat[N][N])
{
	 
	 



	    for (int i = 1; i < N+1; i++) {
	
			  for (int j = 1;j < N+1; j++) {

				 

				  preProcess[i][j] =
					  preProcess[i-1][j] +  preProcess[i][j-1] -  preProcess[i-1][j-1] + mat[i-1][j-1];
			  }

		}
	  

}

int GetQuery(int a, int b,int c, int d)
{	 

	a++;b++; c++; d++;
	return preProcess[c][d] - preProcess[c][b -1] - preProcess[a-1][d] + preProcess[a-1][b-1];

}


int main()
{

   int mat[N][N] ={{2,0,-3,4}, {6, 3, 2, -1}, {5, 4, 7, 3}, {2, -6, 8, 1}};

    SumQuery(mat); 
	int result = GetQuery(1,1,2,2); 
   getchar();
   return 0;

}
