#include <iostream>
using namespace std;

int main(){
    int T;
    cin >> T;

    while(T--){
        int N;
        int a, b;
        int parent[10001] = { 0, };
        bool path[10001] = { false, };

        cin >> N;
        while(N--){
            cin >> a >> b;
            if(N != 0)
                parent[b] = a;
        }

        int desc = a, ansc = parent[a];
        path[a] = true;
        while(true){
            if(ansc == 0) break;
            path[ansc] = true;
            desc = ansc;
            ansc = parent[ansc];
        }

        desc = b;
        ansc = parent[b];
        while(true){
            if(path[desc] == true) break;
            desc = ansc;
            ansc = parent[ansc];
        }   
        cout << desc << "\n";
    }
}