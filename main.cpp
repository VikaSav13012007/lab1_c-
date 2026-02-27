#include <iostream>
#include <iomanip>

using namespace std;

int isNumber() {
    int number;
    while (!(cin >> number)) {
        cout << "Неправильный ввод ха-ха. Повторный ввод: ";
        cin.clear();
        cin.ignore(10000, '\n');
    }
    return number;
}

void Location_of_ships(char** arr, int x0, int y0, int x, int y) {
    if (x0 == x) {
        for (int i = y0 - 1; i <= y - 1; i++) {
            arr[x0 - 1][i] = 'K';
        }
    }
    else {
        for (int i = x0 - 1; i <= x - 1; i++) {
            arr[i][y0 - 1] = 'K';
        }
    }

    cout << "Корабль поставлен:" << endl;
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            cout << setw(4) << arr[i][j];
        }
        cout << endl;
    }
}

void Placement_ship(char** arr, int a) {
    cout << "Выберите расположение кораблей на поле" << endl;
    cout << "Всего кораблей 3: 2-х, 3-х, 4-х палубные" << endl;
    cout << "Первая из координат это строки, вторая - столбцы" << endl;
    cout << "Игрок " << a << endl;

   
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            arr[i][j] = 'o';
            cout << setw(4) << arr[i][j];
        }
        cout << endl;
    }

    int x0, y0, x, y;
    int shipSize = 2;  
    bool canPlace = true;

    while (shipSize <= 4) {
        canPlace = true;
        cout << "\nРазмещаем " << shipSize << "-х палубный корабль" << endl;
        cout << "Конечные координаты должны быть больше начальных" << endl;

        cout << "Напишите начальную строку и столбец через пробел: ";
        x0 = isNumber();
        y0 = isNumber();
        
        cout << "Напишите конечную строку и столбец через пробел: ";
        x = isNumber();
        y = isNumber();

        // проверка границ и длины
        if (((((x - x0) == shipSize - 1) && (y == y0)) ||
            (((y - y0) == shipSize - 1) && (x == x0)))
            && x > 0 && x0 > 0 && y > 0 && y0 > 0
            && x0 <= 10 && y0 <= 10 && y <= 10 && x <= 10) {

            if (x0 == x) {  
                for (int k = y0 - 1; k <= y - 1; k++) {
                    if (arr[x0 - 1][k] == 'K') {
                        canPlace = false;
                        break;  
                    }
                }
            }
            else {  
                for (int k = x0 - 1; k <= x - 1; k++) {
                    if (arr[k][y0 - 1] == 'K') {
                        canPlace = false;
                        break; 
                    }
                }
            }

            if (canPlace) {
                Location_of_ships(arr, x0, y0, x, y);
                shipSize++;  
            }
            else {
                cout << "Здесь уже есть корабль! Выберите другое место." << endl;
            }
        }
        else {
            cout << "Неправильно введены координаты" << endl;
        }
    }
}

int main() {
   
    setlocale(LC_ALL, "Russian");
    char** array1 = new char* [10];
    char** array2 = new char* [10];
    for (int i = 0; i < 10; i++) {
        array1[i] = new char[10];
        array2[i] = new char[10];
    }

    int a = 1;
    Placement_ship(array1, a);

    for (int j = 0; j < 50; j++) {
        cout << "." << endl;
    }

    a++;
    Placement_ship(array2, a);

    for (int j = 0; j < 50; j++) {
        cout << "." << endl;
    }

    char field_of_shots1[10][10];
    char field_of_shots2[10][10];

    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            field_of_shots1[i][j] = 'o';
            field_of_shots2[i][j] = 'o';
        }
    }

    bool win = false;
    int cnt = 1;
    int all_shots_in_ships1 = 9;
    int all_shots_in_ships2 = 9;
    int x = 0, y = 0;
    bool shot = false;

    while (!win) {
        shot = false;
        if (cnt % 2 == 1) {
            while (!shot && !win) {
                cout << "Ход первого игрока" << endl;
                for (int i = 0; i < 10; i++) {
                    for (int j = 0; j < 10; j++) {
                        cout << setw(4) << field_of_shots1[i][j];
                    }
                    cout << endl;
                }
                cout << "Введите строку и столбец для выстрела через пробел: ";
                x = isNumber();
        
                y = isNumber();

                if (x > 0 && x <= 10 && y > 0 && y <= 10) {
                    if (array2[x - 1][y - 1] == 'K' && field_of_shots1[x - 1][y - 1]!='X') {
                        field_of_shots1[x - 1][y - 1] = 'X';
                        cout << "Ура вы попали! Ходите ещё раз!" << endl;
                        all_shots_in_ships1--;
                    }
                    else {
                        cout << "Промах!" << endl;
                        shot = true;
                        field_of_shots1[x - 1][y - 1] = 'P';
                        cnt++;
                    }
                }
                else {
                    cout << "Координаты вне поля!" << endl;
                }

                if (all_shots_in_ships1 == 0) {
                    win = true;
                }
                for (int j = 0; j < 3; j++) {
                    cout << endl;
                }
            }
        }
        else {
            while (!shot && !win) {
                cout << "Ход второго игрока" << endl;
                for (int i = 0; i < 10; i++) {
                    for (int j = 0; j < 10; j++) {
                        cout << setw(4) << field_of_shots2[i][j];
                    }
                    cout << endl;
                }
                cout << "Введите строку и столбец для выстрела через пробел: ";
                x = isNumber();

                y = isNumber();

                if (x > 0 && x <= 10 && y > 0 && y <= 10) {
                    if (array1[x - 1][y - 1] == 'K' && field_of_shots2[x - 1][y - 1]!='X') {
                        field_of_shots2[x - 1][y - 1] = 'X';
                        cout << "Ура вы попали! Ходите ещё раз!" << endl;
                        all_shots_in_ships2--;
                    }
                    else {
                        cout << "Промах!" << endl;
                        shot = true;
                        field_of_shots2[x - 1][y - 1] = 'P';
                        cnt++;
                    }
                }
                else {
                    cout << "Координаты вне поля!" << endl;
                }

                if (all_shots_in_ships2 == 0) {
                    win = true;
                }
                for (int j = 0; j < 3; j++) {
                    cout << endl;
                }
            }
        }
    }

    if (cnt % 2 == 0) {
        cout << "Выиграл второй игрок!" << endl;
    }
    else {
        cout << "Выиграл первый игрок!" << endl;
    }

    for (int i = 0; i < 10; i++) {
        delete[] array1[i];
        delete[] array2[i];
    }
    delete[] array1;
    delete[] array2;

    return 0;
}