#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(void){
    int n,m;
    cin >> n >> m;
    vector<int> v(n);
    bool check[21];
    for(int i=0; i<n; i++){
        cin >> v[i];
    }
    
    int cnt = 0;
    for(int i=0; i<20; i++){
        check[i] = true;
    }
    
    for(int i=0; i<n; i++){
        check[i] = false;
        do{
            int sum = 0;
            for(int j=0; j<n; j++){
                if(check[j] != true){
                    sum += v[j];
                }
            }
            if(sum == m){
                cnt +=1;
            }
            
        }while(next_permutation(check,check+n));
    }
    cout << cnt;
    
    return 0;
}
