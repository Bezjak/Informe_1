#include <bits/stdc++.h>

using namespace std;

void tradicional(const vector<vector<int>>& A, const vector<vector<int>>& B, vector<vector<int>>& C, int m, int p, int n) {
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            C[i][j] = 0;
        }
    }

    for (int i = 0; i < m; i++) {        // Recorrer las filas de A
        for (int j = 0; j < n; j++) {    // Recorrer las columnas de B
            for (int k = 0; k < p; k++) {// Recorrer las columnas de A y filas de B
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}

int main() {
    int m, p, n;

    // Pedir las dimensiones de las matrices
    cout << "Ingrese el número de filas de A (m): ";
    cin >> m;
    cout << "Ingrese el número de columnas de A (p) y filas de B: ";
    cin >> p;
    cout << "Ingrese el número de columnas de B (n): ";
    cin >> n;

    // Declarar las matrices A, B y C
    vector<vector<int>> A(m, vector<int>(p));  // Matriz A de tamaño m x p
    vector<vector<int>> B(p, vector<int>(n));  // Matriz B de tamaño p x n
    vector<vector<int>> C(m, vector<int>(n));  // Matriz C de tamaño m x n (Resultado)

    // Leer los valores de la matriz A
    cout << "Ingrese los elementos de la matriz A:" << endl;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < p; j++) {
            cin >> A[i][j];
        }
    }

    // Leer los valores de la matriz B
    cout << "Ingrese los elementos de la matriz B:" << endl;
    for (int i = 0; i < p; i++) {
        for (int j = 0; j < n; j++) {
            cin >> B[i][j];
        }
    }

    // Llamar a la función de multiplicación de matrices
    tradicional(A, B, C, m, p, n);

    // Imprimir la matriz resultante C
    cout << "Matriz C (Resultado de A * B):" << endl;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cout << C[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
