# include<stdio.h>
#include<stdlib.h>
void swap(float*x, float *y)
{
    float t=*x;
    *x=*y;
    *y=t;
}
void knapsack(int n, float weight[], float profit[], float capacity) {
   float temp[25], pf=0;
   int i,j,u;
   u=capacity;

   for (i=0; i<n;i++)
      temp[i] = 0.0;

   for (i=0; i<n;i++) {
      if (weight[i]>u)
         break;
      else {
         temp[i]=1.0;
         pf=pf+profit[i];
         u=u-weight[i];
      }
   }

   if (i<n){
      temp[i]=u/weight[i];
      }

   pf=pf+(temp[i] * profit[i]);

   printf("\nPercentage taken for objects: ");
   printf("\n");
   for (i=0;i<n;i++)
   {
       printf("Object no %d: ",i+1);
       printf("%f\n", temp[i]);
   }
 printf("\nMaximum profit is: %f", pf);

}

int main() {
   float w[25], p[25], capacity;
   int num, i, j;
   float r[20], temp;
    FILE *fp;
    if ((fp = fopen("file.txt","r")) == NULL){
        printf("File Not Found");
       exit(1);
    }
   //printf("Enter number of objects: ");
   fscanf(fp,"%d %f",&num, &capacity);
   //printf("\nEnter the capacity of knapsack: ");

   //printf("\nEnter the weights and profits for each object: ");
   //printf("\n");

   for (i=0;i<num;i++) {
        //printf("Object %d: ",i+1);
      fscanf(fp,"%f", &w[i]);
   }
    for (i=0;i<num;i++) {
        //printf("Object %d: ",i+1);
      fscanf(fp,"%f", &p[i]);
   }

   for (i=0;i<num;i++) {
      r[i]=p[i]/w[i];
   }

   for (i=0;i<num;i++) {
      for (j=i+1;j<num;j++) {
         if (r[i]<r[j]) {
            swap(&p[j],&p[j+1]);
                  swap(&w[j],&w[j+1]);
                  swap(&r[j],&r[j+1]);
         }
      }
   }

   knapsack(num, w, p ,capacity);
}

