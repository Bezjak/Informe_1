#include <bits/stdc++.h>

using namespace std;

void insertionSort(int arr[], int *begin, int *end) { 
	int left = begin - arr; 
	int right = end - arr; 

	for (int i = left+1; i <= right; i++) { 
		int key = arr[i]; 
		int j = i - 1; 

		while (j >= left && arr[j] > key) { 
			arr[j+1] = arr[j]; 
			j = j-1; 
		} 
		arr[j+1] = key; 
	} 
	return; 
} 

int* partition(int arr[], int low, int high) { 
	int pivot = arr[high];
	int i = (low - 1);

	for (int j = low; j <= high- 1; j++) { 
		if (arr[j] <= pivot) { 
			i++; 
			swap(arr[i], arr[j]); 
		} 
	} 
	swap(arr[i + 1], arr[high]); 
	return (arr + i + 1); 
} 

int *medianOfThree(int * a, int * b, int * c) { 
	if (*a < *b && *b < *c) 
		return (b); 

	if (*a < *c && *c <= *b) 
		return (c); 

	if (*b <= *a && *a < *c) 
		return (a); 

	if (*b < *c && *c <= *a) 
		return (c); 

	if (*c <= *a && *a < *b) 
		return (a); 

	if (*c <= *b && *b <= *a) 
		return (b);

	return a; // Esto es solo para evitar Warnings del copilador
}

void introSortUtil(int arr[], int * begin, int * end, int depthLimit) { 
	int size = end - begin; 

	if (size < 16) { 
		insertionSort(arr, begin, end); 
		return; 
	} 

	if (depthLimit == 0) { 
		make_heap(begin, end + 1); 
		sort_heap(begin, end + 1); 
		return; 
	} 

	int * pivot = medianOfThree(begin, begin + size / 2, end); 

	swap(*pivot, *end); 

	int * partitionPoint = partition(arr, begin-arr, end-arr); 
	introSortUtil(arr, begin, partitionPoint - 1, depthLimit - 1); 
	introSortUtil(arr, partitionPoint + 1, end, depthLimit - 1); 

	return; 
} 

void introSort(int arr[], int *begin, int *end) { 
	int depthLimit = 2 * log(end-begin);
	introSortUtil(arr, begin, end, depthLimit);
	return;
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
    vector<int> data = loadDataset(filename);

    auto start = chrono::high_resolution_clock::now();
    introSort(data.data(), data.data(), data.data() + data.size() - 1);
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

// https://www.geeksforgeeks.org/introSort-cs-sorting-weapon/