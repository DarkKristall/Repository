#include <iostream>
#include <vector>
#include <map>

using namespace std;

int Factorial(int n){
    if (n > 1) return n * Factorial(n-1);
    return 1;
}

int main(int argc, char const *argv[])
{
    int number;
    cout << "Выберите нужный алгоритм:\n1. Факториал\n2. Число сочетаний\n3. Число сочетаний c повторениями\n";
    cin >> number;
    if (number ==1){
        int n;
        cout << "n = ";
        cin >> n;
        cout << "Factorial("s << n << ") = "s << Factorial(n) << endl;
    } else if (number == 2){
        int n, k;
        cout << "n = ";
        cin >> n;
        cout << "k = ";
        cin >> k;
        cout << "P(n,k) = " << Factorial(n) / (Factorial(n - k)* Factorial(k)) << endl;
    } else if (number == 3){
        int n, k;
        cout << "n = ";
        cin >> n;
        cout << "k = ";
        cin >> k;
        cout <<  "С(n,k) = "s << Factorial(k + n - 1) / (Factorial(n -1) * Factorial(k)) << endl;
    }
    return 0;
}
