//
// Created by konstantin on 01.10.2023.
//

#include <iostream>
#include <algorithm>

using namespace std;
bool perestanovka(int* urna, int n){
    for (int i=0; i<=n; i++){
        if (urna[i]==i){
            return 1;
        }
    }
    return 0;
}

int main(){
    int n=10; int p=3628800;
    int ans=0;
    int arr[10] = { 0,1,2,3,4,5,6,7,8,9 };

    for (int i = 0; i < p; ++i)
    {
        next_permutation(arr, arr + n);
        if (perestanovka(arr,n))
            ans++;
    }
    cout << ans << endl;

    return 0;





}