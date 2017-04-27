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
    for(count=0;count<=degree;count++){
        printf("Enter x%d. value : ",count);
        scanf("%f",&input);
        lagrange[count]=input;
    }
    /*x0,x1,x2,x3 are taken from user*/
    for(mainCount=0;mainCount<=degree;mainCount++){
        printf("\n\nL[%d,%d]=",degree,mainCount);
        for(count=0;count<=degree;count++){
            /*Writing numerator 1 time for do not write again every loop*/ 
            if(count==0){
                for(count=0;count<=degree;count++){
                    if(count!=mainCount){
                        printf("(%.3f-%.3f)",x,lagrange[count]);
                        /*Calculate numerator*/
                        temp1=(x-lagrange[count])*temp1;
                    }
                }
                count=mainCount;
            }
            if(count==degree){
                printf("/");
                for(count=0;count<=degree;count++){
                    /*Numerator must equal to 0*/
                    if(count!=mainCount){
                        printf("(%.3f-%.3f)",lagrange[mainCount],lagrange[count]);
                        /*Calculate denominator*/
                        temp2=(lagrange[mainCount]-lagrange[count])*temp2;
                    }
                }
            }
        }
        printf("\nL[%d,%d]=(%.3f/%.3f)=%.3f",degree-1,mainCount,temp1,temp2,temp1/temp2);
        /*For clean result*/
        temp1=1,temp2=1;
    }
    return 0;
}
