#include <stdio.h>


int main()
{
    int degree,mainCount,count;
    float x,input,*lagrange,temp1=1,temp2=1;
    printf("Enter degree of function : ");
    scanf("%d",&degree);
    printf("Enter x value : ");
    scanf("%f",&x);
    lagrange=(float*)malloc(sizeof(float)*degree);  /*Gerekli RAM ayr�ld�*/
    degree++;   /*dereceye kadar de�er almak i�in art�r�ld�*/
    for(count=0;count<degree;count++){
        printf("Enter x%d. value : ",count);
        scanf("%f",&input);
        lagrange[count]=input;
    }
    for(mainCount=0;mainCount<degree;mainCount++){  /*s�ras�yla x0,x1,x2,x3 de�erleri say�ld�*/
        printf("\n\nL[%d,%d]=",degree-1,mainCount);
        for(count=0;count<degree;count++){
            if(count==0){   /*her d�ng�de tekrar yaz�lmamas� i�in ilk de�erde pay 1 defaya mahsus yazd�r�ld�*/
                for(count=0;count<degree;count++){
                    if(count!=mainCount){
                        printf("(%.3f-%.3f)",x,lagrange[count]);
                        temp1=(x-lagrange[count])*temp1;    /*pay�n de�eri hesapland�*/
                    }
                }
                count=mainCount;
            }
            if(count==degree-1){
                printf("/");
                for(count=0;count<degree;count++){
                    if(count!=mainCount){   /*kural gere�i paydan�n 0 olmamas� gerekli*/
                        printf("(%.3f-%.3f)",lagrange[mainCount],lagrange[count]);
                        temp2=(lagrange[mainCount]-lagrange[count])*temp2;  /*paydan�n de�eri hesapland�*/
                    }
                }
            }
        }
        printf("\nL[%d,%d]=(%.3f/%.3f)=%.3f",degree-1,mainCount,temp1,temp2,temp1/temp2);
        temp1=1,temp2=1;    /*her seferinde temiz sonu� ��kmas� i�in 1 e e�itlendi*/
    }
    return 0;
}
