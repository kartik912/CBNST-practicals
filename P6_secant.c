#include<stdio.h>
#include<math.h>
float f(float x)
{
    return(x*x*x-4); // f(x)= x^3-4
}
int main()
{
    float a,b,c,e;
    int count=1,n;
    while(1) {
        printf("\n\nEnter the values of a and b:\n"); //(a,b) must contain the solution.
        scanf("%f%f",&a,&b);
        if (f(a) * f(b) >= 0) {
		    printf("You have not assumed right a and b\n");
            continue;
		}
        break;
    }
    printf("Enter the values of allowed error and maximun number of iterations:\n");
    scanf("%f %d",&e,&n);
    do
    {
        if(f(a)==f(b))
        {
            printf("\nSolution cannot be found as the values of a and b are same.\n");
        return 0;
        }
        c=(a*f(b)-b*f(a))/(f(b)-f(a));
        a=b;
        b=c;
        printf("Iteration No-%d    x=%f\n",count,c);
        count++;
        if(fabs(f(c)) < e) {
            printf("\n The required solution is %f\n",c);
            return 0;
        }
    } while(count < n);
    printf("Solution does not converge or iterations not sufficient:\n");
    return 1;

}