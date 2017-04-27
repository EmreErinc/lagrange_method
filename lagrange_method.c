#include <stdio.h>


int main()
{
    int degree,mainCount,count;
    float x,input,*lagrange,temp1=1,temp2=1;
    printf("Enter degree of function : ");
    scanf("%d",&degree);
    printf("Enter x value : ");
    scanf("%f",&x);
    lagrange=(float*)malloc(sizeof(float)*degree);  /*Gerekli RAM ayrýldý*/
    degree++;   /*dereceye kadar deðer almak için artýrýldý*/
    for(count=0;count<degree;count++){
        printf("Enter x%d. value : ",count);
        scanf("%f",&input);
        lagrange[count]=input;
    }
    for(mainCount=0;mainCount<degree;mainCount++){  /*sýrasýyla x0,x1,x2,x3 deðerleri sayýldý*/
        printf("\n\nL[%d,%d]=",degree-1,mainCount);
        for(count=0;count<degree;count++){
            if(count==0){   /*her döngüde tekrar yazýlmamasý için ilk deðerde pay 1 defaya mahsus yazdýrýldý*/
                for(count=0;count<degree;count++){
                    if(count!=mainCount){
                        printf("(%.3f-%.3f)",x,lagrange[count]);
                        temp1=(x-lagrange[count])*temp1;    /*payýn deðeri hesaplandý*/
                    }
                }
                count=mainCount;
            }
            if(count==degree-1){
                printf("/");
                for(count=0;count<degree;count++){
                    if(count!=mainCount){   /*kural gereði paydanýn 0 olmamasý gerekli*/
                        printf("(%.3f-%.3f)",lagrange[mainCount],lagrange[count]);
                        temp2=(lagrange[mainCount]-lagrange[count])*temp2;  /*paydanýn deðeri hesaplandý*/
                    }
                }
            }
        }
        printf("\nL[%d,%d]=(%.3f/%.3f)=%.3f",degree-1,mainCount,temp1,temp2,temp1/temp2);
        temp1=1,temp2=1;    /*her seferinde temiz sonuç çýkmasý için 1 e eþitlendi*/
    }
    return 0;
}
