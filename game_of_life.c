#include <stdio.h>

int neighbour_sum(int a[18][18], int i, int j){
    int sum = 0;
    for (int mi = -1; mi < 2; mi ++){
        for (int mj = -1; mj < 2; mj ++){
            sum += a[i + mi][j + mj];
        }
    }
    sum -= a[i][j];
    return sum;
}

void one_step(int a[18][18]){
    int b[18][18] = {0};
    for (int i = 1; i < 17; i++){
        for (int j = 1; j < 17; j++){
            int sum = neighbour_sum(a, i, j);
            if (((a[i][j] == 0) && (sum == 3)) || ((a[i][j] == 1) && ((sum == 2) || (sum == 3)))){
                b[i][j] = 1;
            }
        }
    }

    for (int i = 1; i < 17; i++){
        for (int j = 1; j < 17; j++){
            a[i][j] = b[i][j];
        }
    }
}

int main(){
    int a [18][18] = {0};

    printf("Введите поле для доски 16 на 16, где 0 - пустое поле, а 1 - непустое:\n");
    for (int i = 1; i < 17; i++){
        for (int j = 1; j < 17; j++){
            int n;
            scanf("%d", &n);
            a[i][j] = n;
        }
    }

    printf("-------------------------------\n");
    for (int k = 0; k < 10; k++){
        one_step(a);
        for (int i = 1; i < 17; i ++){
            for (int j = 1; j < 17; j++){
                printf("%d ", a[i][j]);
            }
            printf("\n");
        }
        printf("-----------------------------\n");
    }

    return 0;
}