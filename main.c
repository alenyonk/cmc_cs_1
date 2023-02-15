#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int count1 = 0; // compare
int count2 = 0; // change

long long llabs(long long a){
    if (a > 0)
        return a;
    return -a;
}

void born (long long *a, long long n, int p){
    if (p == 1){
        for (int i = 0; i < n; i++){
            a[i] = n - i;
        }
    }
    else if (p == 2){
        for (int i = 0; i < n; i++){
              a[i] = i;
        }
    }
    else{
        srand((unsigned)time(NULL));
            for(int i = 0; i < n; i++){
                a[i] = rand();
            }
    }
}

static void sift (long long  *a, long long l, long long r) {
    long long i, j, x;
     i = l;
    j = 2*l;
    x = llabs(a[l]);
/* j указывает на наибольшего сына */
    count1 ++;
    if (j < r && llabs(a[j]) < llabs(a[j + 1])){
        j++;
    }
 /* i указывает на отца */
     while (j <= r && x < llabs(a[j]) && ++count1 ) {
 /* обмен с наибольшим сыном: a[i] == x */
         a[i] = a[j];
         a[j] = x;
         count2 ++;
 /* продвижение индексов к следующему сыну */
         i = j;
         j = 2*j;
 /* выбор наибольшего сына */
         count1 ++;
         if (j < r && llabs(a[j]) < llabs(a[j + 1]))
             j++;
        }
}

void heap(long long *a, long long n){
    long long x;
    for (long long i = n/2 - 1; i >= 0; i--)
        sift(a, i, i - 1);
    for (long long i = n - 1; i > 0; i--){
        x = a[0];
        a[0] = a[i];
        a[i] = x;
        count2 ++;
        sift(a, 0, i - 1);
    }
}
/* Построим пирамиду по сортируемому массиву */
/* Элементы нумеруются с 0 -> идем от n/2-1 */
/* Текущий максимальный элемент в конец */
/* Восстановим пирамиду в оставшемся массиве */
void selection(long long *a, long long n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int min_index = i;
        for (int j = i + 1; j < n; j++)
        {
            count1 ++;
            if (llabs(a[j]) < llabs(a[min_index]))
            {
                min_index = j;
            }
        }
        if (min_index != i)
        {
            long long x = a[i];
            a[i] = a[min_index];
            a[min_index] = x;
            count2 ++;
        }
    }
}

int main (void){
    long long n = 10;
    int choice = 1;
    long long *arr = malloc(n * sizeof(long long));
    long long *arr1 = malloc(n * sizeof(long long));
    born(arr, n, choice);
    for (int i = 0; i < n; i++){
        arr1[i] = arr[i];
    }
    heap(arr, n);
    for (int i = 0; i < n; i ++)
        printf("%lld ", arr[n - i]);
    printf("\n%d", count1);
    printf("\n%d\n", count2);
    count1 = 0;
    count2 = 0;
    selection(arr1, n);
    for (int i = 0; i < n; i ++)
        printf("%lld ", arr1[n - i]);
    printf("\n%d", count1);
    printf("\n%d\n", count2);
    
    
    
}

