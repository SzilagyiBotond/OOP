//
// Created by admin on 2023. 03. 02..
//
#include <stdio.h>
typedef struct {
    int array[100];
    int len;
}vector;
int is_prime(int n)
/**This function check whether a number is a prime or not.
 *
 * @param n : an integer
 * @return : True if prime, false if not prime
 */
{
    for (int i = 2; i <n ; i++) {
        if(n%i==0 && i!=n)
            return 0;
    }
    return 1;
}
void decompose(int exponents[],int n)
/**This function decomposes a number, and stores its factors in an array.
 *
 * @param exponents : an array
 * @param n : an integer
 */
{
    int i=2;
    if(is_prime(n)==1)
        exponents[n]=1;
    else
        while(n>1)
        {
            if(is_prime(i)==1 && n%i==0)
            {
                exponents[i]+=1;
                n=n/i;
            }
            else
                i++;
        }
}

vector read_array()
/**This function reads an array from the console.
 *
 * @return : the array
 */
{
    vector vector1;
    printf("How many elements: ");
    scanf("%d",&vector1.len);
    for (int i = 0; i < vector1.len; i++) {
        scanf("%d",&vector1.array[i]);
    }
    return vector1;
}
int relative_primes(int a,int b)
/**This function checks whether two integers are relative primes or not.
 *
 * @param a :an integer
 * @param b : an integer
 * @return :True if relative primes, false otherwise
 */
{
    int exp1[100]={0},exp2[100]={0};
    decompose(exp1,a);
    decompose(exp2,b);
    for (int i = 2; i < 100; i++) {
        if(exp1[i]!=0 && exp2[i]!=0)
            return 0;
    }
    return 1;
}
void longest_subsequence(vector a,int* ending_final,int* longest_final)
/**This function prints the longest subsequence in an array, in which the consecutive elements are relative primes
 *
 * @param a : an array
 */
{
    int ending=0;
    int longest=0;
    int current=1;
    for (int i = 0; i < a.len-1; i++) {
        if(relative_primes(a.array[i],a.array[i+1])==1)
        {
            current+=1;
            if(current>longest)
            {
                longest=current;
                ending=i+1;
            }
        }
        else
        {
            current=1;
        }
    }
//    printf("The longest subsequence is: ");
//    for (int i = ending-longest+1; i <= ending; i++) {
//        printf("%d ",a.array[i] );
//    }
//    printf("\n");
    *ending_final=ending;
    *longest_final=longest;

}
void menu()
/**This function is a menu for this program.
 *
 */
{
    while(1)
    {
        printf("What to do (1 - Decomposition , 2 - Longest subarray): ");
        int option;
        scanf("%d",&option);
        if(option==3)
            break;
        switch (option) {
            case 1:
            {
                int n,p;
                printf("What is the number: ");
                scanf("%d",&n);
                int exponents[100]={0};
                decompose(exponents,n);
                printf("What is the prime number: ");
                scanf("%d",&p);
                if(is_prime(p)==1)
                    printf("Its factor in the decomposition: %d\n",exponents[p]);
                else
                    printf("The number given is not prime\n");
                break;
            }
            case 2:
            {
                vector vector1;
                vector1=read_array();
                /*for (int i = 0; i < vector1.len; i++) {
                    printf("%d ",vector1.array[i]);
                }*/
                printf("\n");
                int ending_final,longest_final;
                longest_subsequence(vector1,&ending_final,&longest_final);
                printf("The longest subsequence is: ");
                for (int i = ending_final-longest_final+1; i <= ending_final; i++) {
                    printf("%d ",vector1.array[i] );
                }
                printf("\n");
                break;
            }
        }
    }

}
int main(){
    menu();
    return 0;
}