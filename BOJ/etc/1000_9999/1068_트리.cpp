#include <iostream>
#include <vector>
using namespace std;

vector<int> tree[50];
int parent[50];
int deleted = 0;

void deleteTarget(int target){
    if(tree[target].empty()){
        deleted++;
        return;
    }

    for(int i = 0; i < tree[target].size(); i++){
        deleteTarget(tree[target][i]);
    }
}

int main(){
    int N, target;
    cin >> N;

    for(int i = 0; i < N; i++){
        int tmp;
        cin >> tmp;
        parent[i]=tmp;
        if(tmp != -1)
            tree[tmp].push_back(i);
    }
    cin >> target;
    deleteTarget(target);

    int leaf = 0;
    for(int i = 0; i < N; i++){
        if(tree[i].empty()) leaf++;
    }
    if(tree[parent[target]].size() - 1 == 0)
        deleted--;
    cout << leaf - deleted;
}