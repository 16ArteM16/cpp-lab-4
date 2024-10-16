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

    bool used[1000001] = {0}; // массив для хранения информации о том, включен ли элемент в первую группу

    cout << "YES" << endl;

    cout << "Первая группа: ";
    long long l = 0;  
    for (long long i = n; i > 0; i--) {
        if (current_sum + i <= half_sum) {
            current_sum += i;
            used[i] = true;  // отмечаем, что элемент включен в первую группу
            cout << i << " ";
            l++;
        }
        if (current_sum == half_sum) break;
    }
    cout << endl;

    
    cout << "Количество элементов в первой группе: " << l << endl;
    
    cout << "Вторая группа: ";
    long long k = 0;  // счётчик для второй группы
    for (long long i = n; i > 0; i--) {
        // Если элемент не был включён в первую группу, он идёт во вторую
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
