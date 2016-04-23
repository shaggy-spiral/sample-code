/*
Given an array of NN integers, can you find the sum of its elements?
*/

using namespace std;

int main(){
    int n, arr_j = 0;
    int soma = 0;
    cin >> n;
    vector<int> arr(n);
    for(int arr_i = 0;arr_i < n;arr_i++){
       cin >> arr[arr_i];
    }
    for(arr_j = 0;arr_j < n;arr_j++){
        soma += arr[arr_j];
    }
    cout << soma;
    return 0;
}
