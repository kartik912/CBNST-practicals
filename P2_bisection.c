#include <stdio.h>
#include<math.h>

void bisect(float *mid, float a, float b, int *cnt);
double get_fun(double res);

int main()
{
    int cnt=0, mx;
    float mid, a, b, err, root;
    while(1){
        printf("\nEnter the first starting point: ");
        scanf("%f", &a);
        printf("\nEnter the second ending point: ");
        scanf("%f", &b);
        if (get_fun(a) * get_fun(b) >= 0) {
		    printf("You have not assumed right a and b\n");
            continue;
		}
        break;
    }
    

    printf("\nEnter the maximum iteration to be allowed: ");
    scanf("%d", &mx);

    printf("\nInput the number of allowed error point: ");
    scanf("%f", &err);

    bisect(&mid, a, b, &cnt);

    for (cnt = 1; cnt < mx; mid = root)
    {
        if (get_fun(a) * get_fun(mid) < 0)
        {
            b = mid;
        }
        else
        {
            a = mid;
        }

        bisect(&root, a, b, &cnt);

        if (fabs(root - mid) < err)
        {
            printf("\nThe approximation root is: %f\n", root);
            return 0;
        }
    }

    printf("The iterations are insufficient.\n");
    return 0;
}

void bisect(float *mid, float a, float b, int *cnt)
{
    *mid = (a + b) / 2;
    printf("Iteration\t%d:\t%f\n", *cnt, *mid);
    (*cnt)++;
}

double get_fun(double res)
{
    return (res * res * res - 4 * res - 9);
}