#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <sys/time.h>

#define M 500  // Number of rows in matrix A (and matrix C)
#define N 500  // Number of columns in matrix A and number of rows in matrix B
#define P 500  // Number of columns in matrix B (and matrix C)

int A[M][N], B[N][P], C[M][P];

struct ThreadData {
    int row;
};

// Function to perform matrix multiplication for a single row in matrix C
void *multiply_row(void *arg) {
    struct ThreadData *data = (struct ThreadData *)arg;
    int i = data->row;
    struct timeval start, end;
    gettimeofday(&start, NULL);

    for (int j = 0; j < P; j++) {
        C[i][j] = 0;
        for (int k = 0; k < N; k++) {
            C[i][j] += A[i][k] * B[k][j];
        }
    }

    gettimeofday(&end, NULL);
    long seconds = end.tv_sec - start.tv_sec;
    long microseconds = end.tv_usec - start.tv_usec;
    double time_taken = seconds + microseconds / 1000000.0;
    printf("Thread for row %d took %f seconds\n", i, time_taken);

    pthread_exit(NULL);
}

// Sequential matrix multiplication
void multiply_sequential() {
    struct timeval start, end;
    gettimeofday(&start, NULL);

    for (int i = 0; i < M; i++) {
        for (int j = 0; j < P; j++) {
            C[i][j] = 0;
            for (int k = 0; k < N; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }

    gettimeofday(&end, NULL);
    long seconds = end.tv_sec - start.tv_sec;
    long microseconds = end.tv_usec - start.tv_usec;
    double time_taken = seconds + microseconds / 1000000.0;
    printf("Sequential program took %f seconds\n", time_taken);
}

int main() {
    // Initialize matrices A and B with random values
    srand(0);
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            A[i][j] = rand() % 10;
        }
    }
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < P; j++) {
            B[i][j] = rand() % 10;
        }
    }

    // Sequential matrix multiplication
    printf("Starting sequential matrix multiplication...\n");
    multiply_sequential();

    // Parallel matrix multiplication using threads
    pthread_t threads[M];
    struct ThreadData thread_data[M];
    printf("Starting parallel matrix multiplication...\n");

    struct timeval start, end;
    gettimeofday(&start, NULL);

    for (int i = 0; i < M; i++) {
        thread_data[i].row = i;
        pthread_create(&threads[i], NULL, multiply_row, (void *)&thread_data[i]);
    }

    // Wait for all threads to finish
    for (int i = 0; i < M; i++) {
        pthread_join(threads[i], NULL);
    }

    gettimeofday(&end, NULL);
    long seconds = end.tv_sec - start.tv_sec;
    long microseconds = end.tv_usec - start.tv_usec;
    double time_taken = seconds + microseconds / 1000000.0;
    printf("Parallel program took %f seconds\n", time_taken);

    return 0;
}
