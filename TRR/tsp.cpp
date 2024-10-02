#include <iostream>
#include <algorithm>

using namespace std;

const int MAX = 100;
const int INF = 100000;

int n; // số thành phố
int distanceMatrix[MAX][MAX];

int calculateCost(int distanceMatrix[MAX][MAX], int citi[], int n) {
    int cost = 0;
    for (int i = 1; i < n; i++) {
        cost = cost + distanceMatrix[citi[i]][citi[i + 1]];
    }
    cost = cost + distanceMatrix[citi[n]][citi[1]];
    return cost;
}

void TSP(int distanceMatrix[MAX][MAX], int n) {
    int city[n + 1];
    for (int i = 1; i <= n; i++) {
        city[i] = i;
    }
    int min_cost = INF;
    int min_path[n + 1];
    do {
        int current_cost = calculateCost(distanceMatrix, city, n);
        if (current_cost < min_cost) {
            min_cost = current_cost;
            for (int i = 1; i <= n; i++) {
                min_path[i] = city[i];
            }
        }
    } while (next_permutation(city + 2, city + n + 1));
    cout << "Đường đi ngắn nhất" << endl;
    for (int i = 1; i <= n; i++) {
        cout << min_path[i] << " ";
    }
    cout << 1;
    cout << endl << "Chi phí: ";
    cout << min_cost;
}

void TSP2(int distanceMatrix[MAX][MAX], int n, int s) {
    int city[n + 1];
    for (int i = 1; i <= n; i++) {
        city[i] = i;
    }
    swap(city[1], city[s]);

    int min_cost = INF;
    int min_path[n + 1];

    do {
        int current_cost = calculateCost(distanceMatrix, city, n);
        if (current_cost < min_cost) {
            min_cost = current_cost;
            for (int i = 1; i <= n; i++) {
                min_path[i] = city[i];
            }
        }
    } while (next_permutation(city + 2, city + n + 1));

    cout << "Đường đi ngắn nhất từ thành phố " << s << endl;
    for (int i = 1; i <= n; i++) {
        cout << min_path[i] << " ";
    }
    cout << s;
    cout << endl << "Chi phí: " << min_cost;
}

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> distanceMatrix[i][j];
        }
    }
    cout << endl;
    TSP(distanceMatrix, n);
    cout << endl;
    TSP2(distanceMatrix, n, 3);
    return 0;
}
