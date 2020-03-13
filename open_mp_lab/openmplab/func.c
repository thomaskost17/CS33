#include "func.h"
#include "util.h"
#include "omp.h"
void func0(double *weights, double *arrayX, double *arrayY, int xr, int yr, int n)
{
	int i;
	const double m =  1/((double)(n));
//	omp_set_num_threads(64);
	#pragma omp parallel for num_threads(64)
	for(i = 0; i < n; i++){
		weights[i] = m ;
		arrayX[i] = xr;
		arrayY[i] = yr;
	}
}

void func1(int *seed, int *array, double *arrayX, double *arrayY,
			double *probability, double *objxy, int *index,
			int Ones, int iter, int X, int Y, int Z, int n)
{
	int i, j, jx2;
   	int index_X, index_Y;
	int max_size = X*Y*Z;

   //	for(i = 0; i < n; i++){
   //		arrayX[i] += 1 + 5*rand2(seed, i);
   //		arrayY[i] += -2 + 2*rand2(seed, i);
   //	
   //	}
  // 	omp_set_num_threads(64);
	#pragma omp parallel for default(shared) private(j, index_X, index_Y) num_threads(64)
   	for(i = 0; i<n; i++){
   		arrayX[i] += 1 + 5*rand2(seed, i);
   		arrayY[i] += -2 + 2*rand2(seed, i);
				
   		for(j = 0; j < Ones; j++){
			jx2 = j*2;			
   			index_X = round(arrayX[i]) + objxy[jx2 + 1];
   			index_Y = round(arrayY[i]) + objxy[jx2];
   			index[Ones*i + j] = fabs(index_X*Y*Z + index_Y*Z + iter);
   			if(index[Ones*i + j] >= max_size)
   				index[Ones*i + j] = 0;
   		}
   		probability[i] =0;
		
   		for(j = 0; j < Ones; j++) {
   			probability[i]  += (pow((array[index[i*Ones + j]] - 100),2) -
   							  pow((array[index[i*Ones + j]]-228),2))/50.0;
   		}
   		probability[i] = probability[i]/((double) Ones);
   	}
}

void func2(double *weights, double *probability, int n)
{
	int i;
	double sumWeights=0;
//	omp_set_num_threads(64);
//	#pragma omp parallel for private(sumWeights)
	for(i = 0; i < n; i++){
   		weights[i] = weights[i] * exp(probability[i]);
		sumWeights += weights[i];
	}
   //	for(i = 0; i < n; i++)
   //		sumWeights += weights[i];

	for(i = 0; i < n; i++)
   		weights[i] = weights[i]/sumWeights;
}

void func3(double *arrayX, double *arrayY, double *weights, double *x_e, double *y_e, int n)
{
	double estimate_x=0.0;
	double estimate_y=0.0;
    int i,j;
	for(i = 0; i < n; i+=2){
		j=i+1;
   		estimate_x += arrayX[i] * weights[i]+ arrayX[j]*weights[j];
   		estimate_y += arrayY[i] * weights[i]+ arrayY[j]*weights[j];
   	}

	*x_e = estimate_x;
	*y_e = estimate_y;

}

void func4(double *u, double u1, int n)
{
	int i;

	for(i = 0; i < n; i++){
   		u[i] = u1 + i/((double)(n));
   	}
}

void func5(double *x_j, double *y_j, double *arrayX, double *arrayY, double *weights, double *cfd, double *u, int n)
{
	int i, j;

//	omp_set_num_threads(64);
	#pragma omp parallel for shared(cfd,x_j, y_j, arrayX, arrayY) private(i) num_threads(64)
	for(j = 0; j < n; j++){
   		//i = findIndex(cfd, n, u[j]);
   		i = findIndexBin(cfd, 0, n, u[j]);
   		if(i == -1)
   			i = n-1;
   		x_j[j] = arrayX[i];
   		y_j[j] = arrayY[i];
   	}
//	omp_set_num_threads(64);
	#pragma omp parallel for shared(x_j, y_j, arrayX, arrayY, weights) num_threads(64)
	for(i = 0; i < n; i++){
		arrayX[i] = x_j[i];
		arrayY[i] = y_j[i];
		weights[i] =1/ ((double)(n));
	}
}
