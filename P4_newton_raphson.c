#include<stdio.h>
#include<math.h>
float f(float x)
{
    return x*log10(x) - 1.2;
}
float df (float x)
{
    return log10(x) + 0.43429;
}
void main()
{
    int itr, maxmitr;
    float h, x0, x1, allerr;

    while(1) {
        printf("Enter x0 : ");
        if(df(x0) == 0) {
            printf("Not valid value of x0\n");
            continue;
        }
        break;
    }
    printf("\nEnter allowed error and maximum iterations\n");
    scanf("%f %d", &allerr, &maxmitr);
    for (itr=1; itr<=maxmitr; itr++)
    {
        h=f(x0)/df(x0);
        x1=x0-h;
        printf(" At Iteration no. %3d, x = %9.6f\n", itr, x1);
        if (fabs(h) < allerr)
        {
            printf("After %3d iterations, root = %8.6f\n", itr, x1);
            return 0;
        }
        x0=x1;
    }
    printf(" The required solution does not converge or iterations are insufficient\n");
    return 1;
}