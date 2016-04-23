/*
Given an array of integers, calculate which fraction of its elements are positive, which fraction of its elements are negative, and which fraction of its elements are zeroes, respectively. Print the decimal value of each fraction on a new line.
*/
using namespace std;

int main(){
    int n;
    int pos = 0;
    int neg = 0;
    int zeros = 0;
    float frac_pos = 0.0f;
    float frac_neg = 0.0f;
    float frac_zeros = 0.0f;
    cin >> n;
    vector<int> arr(n);
    for(int arr_i = 0;arr_i < n;arr_i++){
       cin >> arr[arr_i];
    }
    for(int arr_j = 0;arr_j < n;arr_j++){
       if( arr[arr_j] > 0 ) {
           pos++;
       }
       if( arr[arr_j] < 0) {
           neg++;
       }
       if( arr[arr_j] == 0) {
           zeros++;
       } 
    }
    frac_pos = pos / (float)n;
    frac_neg = neg / (float)n;
    frac_zeros = zeros / (float)n;
    cout << frac_pos << endl << frac_neg << endl << frac_zeros;
    return 0;
}
