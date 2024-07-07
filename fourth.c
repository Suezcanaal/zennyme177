//prisms algo
#include <stdio.h>
#include <stdlib.h>

void prism(int n,int a[10][10])
{
    int i,j,min,mina = 0,visited[10],ne =1;
    for(i=1;i<=n;i++)
    visited[i]=0;
    
    printf("The edges considered for MST are\n");
    visited[1] = 1;
    
    while(ne < n){
        for(i=1;min = 999;i<=n; i++){
            for(j=1;j<=n;j++){
                if(a[i][j] < min){
                    if(visited[i]==0){
                        continue;
                        }
                    else{
                        min = a[i],[j];
                        u=i;
                        v=j;
                    }
                        
                }
                if(visited[u] == 0 || visited[v] == 0){
                    printf("%d Edge (%d,%d) = %d",ne++,u,v,min);
                    mina = mina + min;
                    visited[v]=1;
                }
                a[u][v] = a[v][u] = 999;
            }
            
        }
    }
    printf("\n the cost of construsting MST is %a",mina);
}

int main()
{
    int i,j,n,a[10][10];
    printf("Enter the number of nodes\n");
    scanf("%d",&n);
    
    printf("Eter the cost matrix\n");
    for(i=1;i<n;i++){
        for(j=1;j<n;j++){
            scanf("%d",&a[i][j]);
            if(a[i][j]==0)
            a[i][j] = 999;
        }
    }
    
    prism(n , a);
    
    return 0;
}


output: 
0 2 0 6
2 0 3 8
0 3 0 0
6 8 0 0

//dijkstr algo
  #include <stdio.h>
#include <stdlib.h>

void dijkstra(int n, int a[10][10], int s, int dist[10]) {
    int i, v, count, min, visited[10];

    for (i = 0; i < n; i++) {
        visited[i] = 0;
        dist[i] = a[s][i];
    }
    visited[s] = 1;
    dist[s] = 0;

    for (count = 1; count < n; count++) {
        min = 999;
        for (i = 0; i < n; i++) {
            if (dist[i] < min && visited[i] == 0) {
                min = dist[i];
                v = i;
            }
        }
        visited[v] = 1;
        for (i = 0; i < n; i++) {
            if (!visited[i] && dist[v] + a[v][i] < dist[i]) {
                dist[i] = dist[v] + a[v][i];
            }
        }
    }
}

int main() {
    int i, j, n, s, a[10][10], dist[10];

    printf("Enter the number of nodes\n");
    scanf("%d", &n);

    printf("Enter the adjacency matrix\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &a[i][j]);
            if (a[i][j] == 0 && i != j) {
                a[i][j] = 999; // Consider 999 as infinity
            }
        }
    }

    printf("\n/*******************************/\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }
    printf("\n/*******************************/\n");

    printf("Enter the source vertex\n");
    scanf("%d", &s);

    dijkstra(n, a, s, dist);

    printf("The shortest path from vertex %d is \n", s);

    for (i = 0; i < n; i++) {
        if (s != i) {
            printf("%d -> %d = %d\n", s, i, dist[i]);
        }
    }

    return 0;
}

output:
0 10 6 0
10 0 0 1
6 0 0 2
0 1 2 0


  #include <stdio.h>
#include <stdlib.h>

int n, W, w[10], v[10], V[10][10], x[10];

// Max function
int max(int a, int b) {
    return (a > b) ? a : b;
}

// Function to solve the Knapsack problem
void Knapsack() {
    int i, j;

    // Building the table V[][] in bottom-up manner
    for (i = 0; i <= n; i++) {
        for (j = 0; j <= W; j++) {
            if (i == 0 || j == 0) {
                V[i][j] = 0;
            } else if (w[i] <= j) {
                V[i][j] = max(V[i - 1][j], V[i - 1][j - w[i]] + v[i]);
            } else {
                V[i][j] = V[i - 1][j];
            }
        }
    }
}

// Function to print the solution
void printSolution() {
    int i = n, j = W;

    while (i > 0 && j > 0) {
        if (V[i][j] != V[i - 1][j]) {
            x[i] = 1;
            j = j - w[i];
        } else {
            x[i] = 0;
        }
        i--;
    }
}

int main() {
    int i;

    printf("Enter number of objects: ");
    scanf("%d", &n);

    printf("Enter Knapsack Capacity: ");
    scanf("%d", &W);

    printf("Enter the weights of the objects:\n");
    for (i = 1; i <= n; i++) {
        scanf("%d", &w[i]);
    }

    printf("Enter the profits of the objects:\n");
    for (i = 1; i <= n; i++) {
        scanf("%d", &v[i]);
    }

    Knapsack();
    printSolution();

    printf("Objects included in the knapsack:\n");
    printf("Object \t Weight \t Profit\n");
    for (i = 1; i <= n; i++) {
        if (x[i] == 1) {
            printf("%d \t %d \t %d\n", i, w[i], v[i]);
        }
    }

    printf("The maximum profit is %d\n", V[n][W]);

    return 0;
}

output:
Running Example:
Enter the number of items: 4
Enter the weights of the items: 2 3 4 5
Enter the values (profits) of the items: 3 4 5 6
Enter the capacity of the knapsack: 5
