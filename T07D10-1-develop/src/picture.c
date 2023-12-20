#include <stdio.h>
#include <stdlib.h>

#define N 15
#define M 13

void transform(int *buf, int **matr, int n, int m);
void make_picture(int **picture, int n, int m);
void reset_picture(int **picture, int n, int m);
void Output1(int **a, int n, int m);

int main() {
    int **picture_data = malloc(M * sizeof(int *));
    for (int i = 0; i < M; i++) picture_data[i] = malloc(N * sizeof(int));

    int *picture = (int *)malloc(N * sizeof(int));

    transform(picture, picture_data, N, M);

    make_picture(picture_data, N, M);
    Output1(picture_data, N, M);
    free(picture_data);
    free(picture);
    return 0;
}

void make_picture(int **picture, int n, int m) {
    int frame_w[] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
    int frame_h[] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
    int tree_trunk[] = {7, 7, 7, 7};
    int tree_foliage[] = {3, 3, 3, 3};
    int sun_data[6][5] = {{0, 6, 6, 6, 6}, {0, 0, 6, 6, 6}, {0, 0, 6, 6, 6},
                          {0, 6, 0, 0, 6}, {0, 0, 0, 0, 0}, {0, 0, 0, 0, 0}};

    reset_picture(picture, n, m);

    int length_frame_w = sizeof(frame_w) / sizeof(frame_w[0]);
    int length_frame_h = sizeof(frame_h) / sizeof(frame_h[0]);

    for (int i = 1; i < 6; i++)
        for (int j = 7; j < 11; j++) {
            picture[i][j] = sun_data[i - 1][j - 7];
        }

    for (int i = 2; i < 6; i++)
        for (int j = 3; j < 5; j++) {
            picture[i][j] = tree_foliage[i - 2];
        }

    for (int i = 2; i < 6; i++)
        for (int j = 3; j < 5; j++) {
            picture[j][i] = tree_foliage[i - 2];
        }

    for (int j = 2; j < 6; j++) picture[10][j] = tree_trunk[j - 2];

    for (int i = 6; i < 10; i++)
        for (int j = 3; j < 5; j++) {
            picture[i][j] = tree_trunk[i - 6];
        }
    for (int i = 0; i < length_frame_w; i++) {
        picture[0][i] = frame_w[i];
        picture[N - 1][i] = frame_w[i];
        picture[(N - 1) / 2][i] = frame_w[i];
    }

    for (int i = 0; i < length_frame_h; i++) {
        picture[i][0] = frame_h[i];
        picture[i][(M - 1) / 2] = frame_h[i];
        picture[i][M - 1] = frame_h[i];
    }
}

void reset_picture(int **picture, int n, int m) {
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            picture[i][j] = 0;
        }
    }
}

void transform(int *buf, int **matr, int n, int m) {
    for (int i = 0; i < n; i++) {
        matr[i] = buf + i * m;
    }
}

void Output1(int **a, int n, int m) {
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) {
            if ((j == m - 1) && (i != n - 1))
                printf("%d\n", a[i][j]);
            else if ((j == m - 1) && (i == n - 1))
                printf("%d", a[i][j]);
            else
                printf("%d ", a[i][j]);
        }
}
