#include <iostream>
#include <deque>
using namespace std;

typedef struct tree {
	int r, c, age;
};

int N, M, K, num = 0;
int land[11][11];
int A[11][11];
int around[8][2] = { {-1,-1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 1}, {1, -1}, {1, 0}, {1, 1} };

deque<tree> trees;

void ss() {
	int size = trees.size();
	for (int i = 0; i < size; i++) {								//spring
		if (trees[i].age > 0 && land[trees[i].r][trees[i].c] >= trees[i].age) {
			land[trees[i].r][trees[i].c] -= trees[i].age;
			trees[i].age++;
		}
		else if(trees[i].age != 0) {
			trees[i].age *= (-1);									//죽음 표시
		}
	}

	for (int i = 0; i < size; i++) {								//summer
		if (trees[i].age < 0) {										//이번년도에 죽은 나무라면
			land[trees[i].r][trees[i].c] -= (trees[i].age / 2);		//양분흡수
			trees[i].age = 0;
			num--;													//나무 죽음
		}
	}
}

void fw() {
	tree t;
	t.age = 1;

	for (int i = 0; i < trees.size(); i++) {						//fall
		if (trees[i].age > 0 && trees[i].age % 5 == 0) {
			for (int j = 0; j < 8; j++) {
				int r = trees[i].r + around[j][0];
				int c = trees[i].c + around[j][1];

				if (r < 1 || r > N || c < 1 || c > N)
					continue;

				t.r = r;
				t.c = c;
				trees.push_front(t);								//새 나무 심을 수 있으면 front에 push
				num++;
				i++;
			}
		}
	}

	for (int i = 1; i <= N; i++) {									//winter
		for (int j = 1; j <= N; j++) {
			land[i][j] += A[i][j];
		}
	}
}


int main() {
	cin >> N >> M >> K;

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			land[i][j] = 5;
			cin >> A[i][j];
		}
	}

	for (int i = 0; i < M; i++) {
		tree t;
		cin >> t.r >> t.c >> t.age;
		trees.push_back(t);
		num++;
	}

	while(K--) {
		ss();
		fw();
	}
	cout << num;
}
