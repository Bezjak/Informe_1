#include <bits/stdc++.h>

using namespace std;

void merge(vector<int>& arr, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    vector<int> L(n1), R(n2);

    for(int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for(int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    int i = 0, j = 0;
    int k = left;

    while(i < n1 && j < n2) {
        if(L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while(i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}


void mergeSort(vector<int>& arr, int left, int right) {
	if(left >= right)
		return;

	int mid = left + (right - left) / 2;
	mergeSort(arr, left, mid);
	mergeSort(arr, mid + 1, right);
	merge(arr, left, mid, right);
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
    mergeSort(arr, 0, arr.size() - 1);
    auto end = chrono::high_resolution_clock::now();

    chrono::duration<double> elapsed = end - start;
    cout << "Tiempo de ejecución para " << filename << ": " << elapsed.count() << " segundos" << endl;
}

int main() {
    vector<string> filenames = {
        "ordered_1000.txt",
        "reverse_ordered_1000.txt",
        "partially_ordered_1000.txt"
    };

    for (const string& filename : filenames) {
        cout << "Prueba con dataset: " << filename << endl;
        measureExecutionTime(filename);
    }

    return 0;
}

// https://www.geeksforgeeks.org/merge-sort/