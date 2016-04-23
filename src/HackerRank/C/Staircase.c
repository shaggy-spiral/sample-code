/*
Your teacher has given you the task of drawing a staircase structure. Being an expert programmer, you decided to make a program to draw it for you instead. Given the required height, can you print a staircase as shown in the example? 
*/

using namespace std;

int main(){
    int n;
    cin >> n;
    int spaces = 0;
    int coiso = 0;
    for (int i = 1; i <= n; i++) {
        coiso = i;
        spaces = n - i;
        for(int j = 1; j <= n; j++) {
            if( spaces >= 1) {
                cout << ' ';
                spaces--;
                
            } else {
                if ( coiso >= 1) {
                    cout << '#';
                    coiso--;
                }
            }
        
        }
    cout << endl;      
        }
    
    return 0;
}

