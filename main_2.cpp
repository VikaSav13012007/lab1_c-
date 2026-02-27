#include <iostream>
#include <iomanip>

using namespace std;

int isNumber() {
    int number;
    while (!(cin >> number)) {
        cout << "Неправильный ввод. Повторный ввод: ";
        cin.clear();
        cin.ignore(10000, '\n');
    }
    return number;
}

int main(){
    int m, n;
    cout<<"Введите количество строк m и столбцов n: ";
    m=isNumber();
    n=isNumber();
    cout<<"Элементы массива: "<<endl;
    int** array=new int*[m];
    for (int i=0; i<m;i++){
        array[i]=new int[n];
    }
    int number=1;
    int sum_row=0;
    for (int i=0;i<m;i++){
        
        for (int j=0; j<n;j++){
            array[i][j]=number;
            number++;
            cout << setw(4) << array[i][j];
        }
        cout<<endl;
    }
    for (int i=0;i<m;i++){
        sum_row=0;
        for (int j=0; j<n;j++){
            sum_row+=array[i][j];
        }
        cout<<"Сумма элементов строки "<<i+1<<" "<<sum_row<<endl;
    }
    int maximum=array[m-1][n-1];
    int sum_column=0;
    for (int i=0;i<n;i++){
        sum_column=0;
        for (int j=0; j<m;j++){
            sum_column+=array[j][i];
        }
        cout<<"Сумма элементов столбца "<<i+1<<" "<<sum_column<<endl;
    }
    cout<<"Максимальное значение: "<<maximum<<endl;
    
    int** array_tr=new int*[n];
    for (int i=0; i<n;i++){
        array_tr[i]=new int[m];}
    for(int i=0; i<m;i++){
        for (int j=0;j<n;j++){
            array_tr[j][i]=array[i][j];
            
            }
        }
    cout<<"Транспонированая матрица:"<<endl;
    for (int i=0;i<n;i++) {
        for(int j=0;j<m;j++){
            cout << setw(4) << array_tr[i][j];
        }
        cout<<endl;
    }
    for (int i=0;i<m;i++){
        delete[] array[i];
    }
    for (int i=0;i<n;i++){
        delete[] array_tr[i];
    }
    delete[] array;
    delete[] array_tr;

    return 0;
}

