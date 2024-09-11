#include <bits/stdc++.h>

using namespace std;

/*
 * Este algoritmo selecciona el elemento más pequeño en cada iteración y lo coloca 
 * en la posición correspondiente. Recorre el vector y realiza intercambios si encuentra 
 * un valor menor al actual.
 */

void selectionSort(vector<int>& arr) {
	int n = arr.size();

	for(int i = 0; i < n-1; i++) {
		int min_idx = i;

		for(int j = i + 1; j <n; j++) {
			if(arr[j] < arr[min_idx])
				min_idx = j;
		}
		if(min_idx != i)
			swap(arr[min_idx], arr[i]);
	}
}

// Función para leer un dataset desde un archivo
vector<int> loadDataset(const string& filename) {
    ifstream file(filename);
    vector<int> dataset;
    if (!file.is_open()) {
        cerr << "No se pudo abrir el archivo " << filename << endl;
        return dataset; // Retorna un vector vacío en caso de error
    }

    int value;
    while (file >> value) {
        dataset.push_back(value);
    }
    
    if (file.bad()) {
        cerr << "Error al leer el archivo " << filename << endl;
    }

    return dataset;
}

// Función para imprimir el tiempo de ejecución
void measureExecutionTime(const string& filename) {
    vector<int> arr = loadDataset(filename);

    auto start = chrono::high_resolution_clock::now();
    selectionSort(arr);
    auto end = chrono::high_resolution_clock::now();

    chrono::duration<double> elapsed = end - start;
    cout << "Tiempo de ejecución para " << filename << ": " << elapsed.count() << " segundos" << endl;
}

// Función main para ver los tiempos de ejecución de los distintos Datasets
int main() {
    vector<string> filenames = {
        "ordered_1000.txt",
        "ordered_10000.txt",
        "ordered_100000.txt",
        "reverse_ordered_1000.txt",
        "reverse_ordered_10000.txt",
        "reverse_ordered_100000.txt",
        "partially_ordered_1000.txt",
        "partially_ordered_10000.txt",
        "partially_ordered_100000.txt"
    };

    for (const string& filename : filenames) {
        cout << "Prueba con dataset: " << filename << endl;
        measureExecutionTime(filename);
    }

    return 0;
}

// https://www.geeksforgeeks.org/selection-sort-algorithm-2/