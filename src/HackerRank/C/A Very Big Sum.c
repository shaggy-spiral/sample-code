/*
You are given an array of integers of size NN. You need to print the sum of the elements in the array, keeping in mind that some of those integers may be quite large. 
*/

using namespace std;

int main(){
    int n;
    unsigned long long int soma = 0;
    cin >> n;
    vector<unsigned long long int> arr(n);
    for(int arr_i = 0;arr_i < n;arr_i++){
       cin >> arr[arr_i];
    }
    for(int arr_j = 0; arr_j < n; arr_j++) {
        soma += arr[arr_j];
    }
    cout << soma;
    return 0;
}

