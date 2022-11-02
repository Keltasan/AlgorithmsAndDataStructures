/*
Реализовать сортировку Timsort. В реализации должны быть выполнены все основные элементы алгоритма: 
сортировка вставками, поиск последовательностей run, подсчёт minrun, слияние последовательностей run,
режим галопа при слиянии.
*/
#include <iostream>
#include <ctime>

void fillArr(int* arr, int N) {
	for (int i = 0; i < N; i++) {
		arr[i] = rand();
	}
}

void deleteArr(int* arr) {
	delete[]arr;
}

void printArr(int* arr, int N) {
	for (int i = 0; i < N; i++) {
		std::cout << arr[i] << " ";
	}
	std::cout << std::endl;
}


void InsertionSort(int* arr, int left, int right) {
	for (int i = left + 1; i <= right; i++) {
		int temp = arr[i];
		int j = i - 1;
		while (j >= left && arr[j] > temp) {
			arr[j + 1] = arr[j];
			j--;
		}
		arr[j + 1] = temp;
	}
}


void Merge(int* arr, int first, int mid, int last) {


	int lenght1 = mid - first + 1, lenght2 = last - mid;

	int* firstArr = new int[lenght1];
	int* secondArr = new int[lenght2];

	for (int i = 0; i < lenght1; i++)
		firstArr[i] = arr[first + i];
	for (int j = 0; j < lenght2; j++)
		secondArr[j] = arr[mid + 1 + j];

	int i = 0, j = 0, k = first;

	while (i < lenght1 && j < lenght2) {
		if (firstArr[i] <= secondArr[j]) {
			arr[k] = firstArr[i];
			i++;
		}
		else {
			arr[k] = secondArr[j];
			j++;
		}
		k++;
	}

	while (i < lenght1) {
		arr[k] = firstArr[i];
		i++;
		k++;
	}

	while (j < lenght2) {
		arr[k] = secondArr[j];
		j++;
		k++;
	}

	delete[]firstArr;
	delete[]secondArr;
}

void MergeSort(int* arr, int left, int right) {
	if (left < right) {
		int mid = left + (right - left) / 2;
		MergeSort(arr, left, mid);
		MergeSort(arr, mid + 1, right);
		Merge(arr, left, mid, right);
	}
	else { return; }
}


int GetMinrun(int N) {
	int r = 0;
	while (N >= 64) {
		r |= N & 1;
		N >>= 1;
	}
	std::cout << "minrun = " << (N + r) << std::endl;
	return N + r;
}

void TimSort(int* arr, int N) {

	int minrun = GetMinrun(N);

	for (int i = 0; i < N; i += minrun) {
		int min = 0;
		if ((i + (minrun - 1)) >= (N - 1)) {
			min = N - 1;
		}
		else {
			min = i + (minrun - 1);
		}
		InsertionSort(arr, i, min);
	}

	for (int size = minrun; size < N; size = 2 * size) {
		for (int left = 0; left < N; left += 2 * size) {
			int min = 0;
			if ((left + 2 * size - 1) >= (N - 1)) {
				min = N - 1;
			}
			else {
				min = left + 2 * size - 1;
			}
			int mid = left + size - 1;
			int right = min;

			if (mid < right) {
				Merge(arr, left, mid, right);
			}
		}
	}
}


int main() {
	int N = 0;
	std::cout << "Enter the number of elements in your array:" << std::endl;
	std::cin >> N;

	int* userArr = new int[N];

	fillArr(userArr, N);

	//printArr(userArr, N);

	unsigned int start_time = clock();

	TimSort(userArr, N);

	unsigned int end_time = clock();

	//printArr(userArr, N);

	std::cout << "Algorithm work time is " << end_time - start_time << "ms" << std::endl;

	deleteArr(userArr);

	system("pause");
	return 0;
}