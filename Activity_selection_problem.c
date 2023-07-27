#include<stdio.h>
#include<stdlib.h>
void swap(int* a,int* b)
{
                int temp=*a;
                  *a=*b;
                *b=temp;
}
int main()
{
    printf("Press any key to start the program.");
    int s[20],f[20],a[20],i,n,j, k=0;
   FILE *fp;
    if ((fp = fopen("input.txt","r")) == NULL){
        printf("File Not Found");
       exit(1);
    }
    fscanf(fp,"%d", &n);
    for(i=0;i<n;i++){
        a[i]=i+1;
        fscanf(fp,"%d", &s[i]);
    }
        scanf("%d",&f[i]);
     for (int i = 0; i < n; i++)
    {

        fscanf(fp,"%d", &f[i]);

    }

    fclose(fp);

    for(i=0;i<n;i++){
        for(j=0;j<n-1;j++){
            if(f[j]>f[j+1]){
                swap(&f[j],&f[j+1]);
                swap(&s[j],&s[j+1]);
                swap(&a[j],&a[j+1]);
            }
        }
    }
    printf("The selected activities are: \n");
    printf("Activity %d which started at %d and ended at %d\n",a[0],s[0],f[0]);
    for(i=0;i<n;i++){
        if(s[i]>=f[k]){
            printf("Activity %d which started at %d and ended at %d\n",a[i], s[i],f[i]);
            k=i;
        }

    }
    printf("\n");
}

