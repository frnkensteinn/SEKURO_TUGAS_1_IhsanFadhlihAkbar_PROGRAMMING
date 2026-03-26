#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;

    vector<int> x(n), c(n);

    for(int i = 0; i < n; i++){
        cin >> x[i];
    }

    for(int i = 0; i < n; i++){
        cin >> c[i];
    }

    vector<pair<int,int>> paket;
    for(int i = 0; i < n; i++){
        paket.push_back({x[i], c[i]});
    }

    sort(paket.begin(), paket.end());
    map<int, bool> diambil;
    int count = 0;

    for(auto &p : paket){
        int kategori = p.second;

        if(!diambil[kategori]){
            diambil[kategori] = true;
            count++;
        }
    }

    cout << count << endl;

    return 0;
}