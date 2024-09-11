#include <iostream>
#include <fstream>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

void saveDataset(const vector<int>& dataset, const string& filename) {
    ofstream file(filename);
    if (file.is_open()) {
        for (int num : dataset) {
            file << num << " ";
        }
        file.close();
    } else {
        cerr << "No se pudo abrir el archivo para guardar el dataset." << endl;
    }
}

vector<int> loadDataset(const string& filename) {
    ifstream file(filename);
    vector<int> dataset;
    int value;
    while (file >> value) {
        dataset.push_back(value);
    }
    return dataset;
}

vector<int> generateDataset(int size) {
    vector<int> dataset(size);
    for (int i = 0; i < size; i++) {
        dataset[i] = rand() % 1000; // Valores aleatorios entre 0 y 999
    }
    return dataset;
}

void generateOrderedDataset(int size) {
    vector<int> dataset(size);
    for (int i = 0; i < size; i++) {
        dataset[i] = i; // Dataset ordenado ascendentemente
    }
    saveDataset(dataset, "ordered_" + to_string(size) + ".txt");
}

void generateReverseOrderedDataset(int size) {
    vector<int> dataset(size);
    for (int i = 0; i < size; i++) {
        dataset[i] = size - i - 1; // Dataset ordenado descendentemente
    }
    saveDataset(dataset, "reverse_ordered_" + to_string(size) + ".txt");
}

void generatePartiallyOrderedDataset(int size) {
    vector<int> dataset(size);
    for (int i = 0; i < size; i++) {
        dataset[i] = rand() % (size / 10) * 10; // Dataset con pocos valores únicos
    }
    saveDataset(dataset, "partially_ordered_" + to_string(size) + ".txt");
}

int main() {
    srand(time(0)); // Inicializar la semilla aleatoria

    // Tamaños de datasets para probar
    vector<int> sizes = {100000}; 

    for (int size : sizes) {
        generateDataset(size);
        generateOrderedDataset(size);
        generateReverseOrderedDataset(size);
        generatePartiallyOrderedDataset(size);
    }

    return 0;
}
