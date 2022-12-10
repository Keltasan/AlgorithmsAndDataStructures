/*
Реализовать сортировку Timsort. В реализации должны быть выполнены все основные элементы алгоритма: 
сортировка вставками, поиск последовательностей run, подсчёт minrun, слияние последовательностей run,
режим галопа при слиянии.
*/
#include <iostream>
#include <ctime>
#include "Stack.h"
#include "Array.h"
#include "Sort.h"

int main() {
	int  N = 0;	//number of elements in custom array
	std::cout << "Enter the number of array elements:" << std::endl;
	std::cin >> N;
	std::cout << std::endl << std::endl;

	if (N > 1) {
		Array<int> userArr;	//custom array
		userArr.random(N);

		std::cout << "Your array has " << N << " elements:" << std::endl;	//custom array output
		//userArr.print();
		std::cout << std::endl;

		unsigned int start_time = clock();
		TimSort(userArr, N);	//sorting TimSort
		unsigned int end_time = clock() - start_time;

		std::cout << "Your sorted array:" << std::endl;	//output sorted custom array
		//userArr.print();
		std::cout << std::endl << "Algorithm worktime is " << end_time << "ms" << std::endl;
	}
	else {
		std::cout << "Invalid input" << std::endl;
	}

	system("pause");
	return 0;
}