#include <bits/stdc++.h>

using namespace std;

void transponerMatriz(const vector<vector<int>>& B, vector<vector<int>>& B_T, int p, int n) {
    for (int i = 0; i < p; i++) {
        for (int j = 0; j < n; j++) {
            B_T[j][i] = B[i][j];  // Transponer B: columnas pasan a filas
        }
    }
}

// Función para multiplicar matrices optimizada (usando la transposición de B)
void tradicionalOptimizada(const vector<vector<int>>& A, const vector<vector<int>>& B_T, vector<vector<int>>& C, int m, int p, int n) {
    // Inicializar la matriz C a ceros
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            C[i][j] = 0;
        }
    }

    // Multiplicación de matrices usando B transpuesta
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < p; k++) {
                C[i][j] += A[i][k] * B_T[j][k];  // Usamos B_T (B transpuesta)
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
    vector<vector<int>> B_T(n, vector<int>(p)); // Matriz transpuesta de B de tamaño n x p
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

    // Transponer la matriz B
    transponerMatriz(B, B_T, p, n);

    // Llamar a la función de multiplicación optimizada
    tradicionalOptimizada(A, B_T, C, m, p, n);

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