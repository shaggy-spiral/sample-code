/*
Given a square matrix of size N×NN×N, calculate the absolute difference between the sums of its diagonals.
*/
using namespace std;

int main(){
    int n;
    int soma_1 = 0;
    int soma_2 = 0;
    int soma_t = 0;
    cin >> n;
    vector< vector<int> > a(n,vector<int>(n));
    for(int a_i = 0;a_i < n;a_i++){
       for(int a_j = 0;a_j < n;a_j++){
          cin >> a[a_i][a_j];
       }
    }
      for(int b_i = 0;b_i < n;b_i++){
       for(int b_j = 0;b_j < n;b_j++){
          if(b_i == b_j) {
              soma_1 += a[b_i][b_j];  
          }
        }
      }
     for(int b_i = 0; b_i < n; b_i++) {
       for(int b_j = n - b_i - 1 ; b_j >= 0; b_j--) { 
             soma_2 += a[b_i][b_j];
             break;
       }
     }
   soma_t = abs(soma_1 - soma_2);
   cout << soma_t;
   return 0;
}
