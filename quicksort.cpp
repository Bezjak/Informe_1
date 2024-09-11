#include <bits/stdc++.h>

using namespace std;

int partition(vector<int>& arr, int low, int high) {
	int pivot = arr[high];
	int i = low - 1;

	for(int j = low; j <= high - 1; j++) {
		if(arr[j] < pivot) {
			i++;
			swap(arr[i], arr[j]);
		}
	}

	swap(arr[i + 1], arr[high]);
	return i + 1;
}

void quickSort(vector<int>& arr, int low, int high) {
	if(low < high) {
		int pi = partition(arr, low, high);
		quickSort(arr, low, pi - 1);
		quickSort(arr, pi + 1, high);
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

// Función para medir el tiempo de ejecución
void measureExecutionTime(const string& filename) {
    vector<int> arr = loadDataset(filename);

    auto start = chrono::high_resolution_clock::now();
    quickSort(arr, 0, arr.size() - 1);
    auto end = chrono::high_resolution_clock::now();

    chrono::duration<double> elapsed = end - start;
    cout << "Tiempo de ejecución para " << filename << ": " << elapsed.count() << " segundos" << endl;
}

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

// https://www.geeksforgeeks.org/quick-sort-algorithm/