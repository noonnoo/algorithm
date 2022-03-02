#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

void location_sort(int N) {
	vector<pair<int, int>> people;		//age, index
	vector<string> names;

	for (int i = 0; i < N; i++) {
		int age;
		string name;
		cin >> age >> name;

		people.push_back(make_pair(age, i));	//index를 담아 들어온 순서 저장
		names.push_back(name);
	}

	sort(people.begin(), people.end());		//STL의 sort함수 이용

	for (int i = 0; i < N; i++) {
		cout << people[i].first << " " << names[people[i].second] << "\n";
	}
}

int main() {
	long long N;
	cin >> N;

	location_sort(N);
}
