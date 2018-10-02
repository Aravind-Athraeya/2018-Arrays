#include <iostream>
#include <list>

#define N 4 
#define MatrixSize 3

/// First - Calculate an auxilary matrix with an additonal row and additional column-- Ref: https://www.youtube.com/watch?v=PwDqpOMwg6U
///  Fill up first row and column with zero
// Calculate the sum for the second row and second column alone
// Then use the formula to piggy pack on values from second row and column computation - Use formaule to subtract duplicates
// Use another formula to get the values
// Kadane for 1D array and preprocess for 2D array
//Tushor Roy -Reference

 int preProcess[N+1][N +1];
int a;     
int b;  
int c;     
int d;  



void SumQuery(int mat[N][N])
{
	 
	 



	    for (int i = 1; i < N+1; i++) {
	
			  for (int j = 1;j < N+1; j++) {

				 

				  preProcess[i][j] =
					  preProcess[i-1][j] +  preProcess[i][j-1] -  preProcess[i-1][j-1] + mat[i-1][j-1];
			  }

		}
	  

}

void GetMatrix()
{	 
	int sumStateTillNow = 0;
	int sumStateMaxOverall = 0;

	for(int i= N ; i >0; i--)
	{
	
				if(MatrixSize> i)
				break;

		for(int j= N ; j > 0 ; j--)
		{
			
			if(MatrixSize> j)
				break;

			// no hindrance because of additional  0's row and column in the Sum matrix

		   sumStateTillNow = preProcess[i][j] 
								- preProcess[i -MatrixSize][j]
								- preProcess[i][j - MatrixSize]
								+ preProcess[i -MatrixSize][j - MatrixSize];

			if (sumStateMaxOverall < sumStateTillNow)
			{
				sumStateMaxOverall = sumStateTillNow;
			    a = (i -MatrixSize + 1);
				b = (j - MatrixSize + 1);
				c = (i);
				d = (j);
			    

			}



		
		}
	
	}

}


int main()
{

   int mat[N][N] ={{2,0,-3,4}, {6, 3, 2, -1}, {5, 4, 7, 3}, {2, -6, 8, 1}};

    SumQuery(mat); 
	GetMatrix(); 
	std::cout << "a: " << a << "\n"  ;
	std::cout << "b: " << b << "\n"  ;
    std::cout << "c: " << c << "\n"  ;
	std::cout << "d: " << d << "\n"  ;
    getchar();
   return 0;

}
