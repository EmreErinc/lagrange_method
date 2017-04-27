#include <stdio.h>

int main()
{
    int degree,mainCount,count;
    float x,input,*lagrange,temp1=1,temp2=1;
    printf("Enter degree of function : ");
    scanf("%d",&degree);
    printf("Enter x value : ");
    scanf("%f",&x);
    /*Required RAM left*/
    lagrange=(float*)malloc(sizeof(float)*degree);
    /*x0,x1,x2,x3 are taken from user*/
    for(count=0;count<=degree;count++){
        printf("Enter x%d. value : ",count);
        scanf("%f",&input);
        lagrange[count]=input;
    }
    /*Counting x0,x1,x2,x3 values*/
    for(mainCount=0;mainCount<=degree;mainCount++){
        for(count=0;count<=degree;count++){
            if(count!=mainCount){
                /*Calculate numerator*/
                temp1=(x-lagrange[count])*temp1;
                /*Calculate denominator*/
                temp2=(lagrange[mainCount]-lagrange[count])*temp2;
            }
        }
        printf("\nL[%d,%d]=(%.3f/%.3f)=%.3f",degree,mainCount,temp1,temp2,temp1/temp2);
        /*For clean result*/
        temp1=1,temp2=1;
    }
    return 0;
}
