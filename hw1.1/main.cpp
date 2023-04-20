#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int find_i(vector<bool> finish, vector<vector<int>> need, vector<int> work) {
	for (int i = 0; i < finish.size(); i++) {
		if (finish[i] == false && work >= need[i]) {
			return i;
		}
	}
	return -1;
}

int main() {
	int num_pr, num_r;
	cout << "Number of processes is ";
	cin >> num_pr;
	cout << "Number of resources is ";
	cin >> num_r;
	vector<int> available(num_r);
	cout << "Filling \'Available\' vector" << endl;
	for (int i = 0; i < num_r; i++) {
		cin >> available[i];
	}
	vector<vector<int>> max(num_pr, vector<int>(num_r, 0)), allocation(num_pr, vector<int>(num_r, 0)),
		need(num_pr, vector<int>(num_r, 0));

	cout << "Filling \'Need\' vector" << endl;
	for (int i = 0; i < num_pr; i++) {
		cout << "Process number " << i << endl;
		for (int j = 0; j < num_r; j++) {
			//cin >> allocation[i][j];
			//cin >> max[i][j];
			cin >> need[i][j];
		}
	}
	vector<int> work = available;
	vector<bool> finish(num_pr, false);

	while (find_i(finish, need, work) != -1) {

		//Ищем finish[i]=false и Need [i] <= Work
		int ind = find_i(finish, need, work);
		std::cout << ind;

		//Выделяем ресурсы
		allocation[ind] = need[ind];
		std::transform(work.begin(), work.end(), allocation[ind].begin(), work.begin(), std::minus<int>());


		//Освобождаем ресурсы
		std::transform(work.begin(), work.end(), allocation[ind].begin(), work.begin(), std::plus<int>());
		//Присваиваем процессу признак завершенности
		finish[ind] = true;

	}

	int k = 0;
	for (int i = 0; i < finish.size(); i++) {
		if (finish[i]) {
			k += 1;
		}
	}
	if (k == num_pr) {
		std::cout << "System is in a safe state" << std::endl;
	}
	else {
		std::cout << "System is not in a safe state";
	}

}