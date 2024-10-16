#include <iostream>
using namespace std;

void F(long long n) {
    long long sum = (n * (n + 1)) / 2;  
    if (sum % 2 != 0) {
        cout << "NO" << endl;
        return;
    }
    long long half_sum = sum / 2;
    long long current_sum = 0;
    bool used[1000001] = {0}; // массив, который записывает использовалось ли число в первой группе (то присваивает ему "1"/ иначе число присоединяется ко 2-ой группе)
    cout << "YES" << endl;
    cout << "Первая группа: ";
    long long l = 0;  
    for (long long i = n; i > 0; i--) {
        if (current_sum + i <= half_sum) {
            current_sum += i;
            used[i] = true;  // присваиваем, что число используется в 1-ой группе
            cout << i << " ";
            l++;
        }
        if (current_sum == half_sum) break;
    }
    cout << endl;   
    cout << "Количество элементов в первой группе: " << l << endl;  
    cout << "Вторая группа: ";
    long long k = 0;  
    for (long long i = n; i > 0; i--) {
        // Если значение элемента в bool равен 0, то он складывается ко 2-ой группе
        if (!used[i]) {
            cout << i << " ";
            k++;
        }
    }
    cout << endl;

    
    cout << "Количество элементов во второй группе: " << k << endl;
}


int main() {
    long long n;
    cout << "Введите число n: ";
    cin >> n;
    F(n);

    return 0;
}
