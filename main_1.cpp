#include <iostream>

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
    
    int size_array;
    int number;
    int maximum=0;
    int sum=0;
    
    cout<<"Введите размерность массива: ";
    size_array=isNumber();
    cout<<"Введите элементы массива: ";
    int* array=new int[size_array];
    for (int i=0; i<size_array;i++){
        number=isNumber();
        array[i]=number*number;
    }
    cout<<"Элементы массива: ";
    for (int i=0; i<size_array;i++){
        cout<<array[i]<<' ';
        sum+=array[i];
        maximum=i==0? array[0]: max(array[i], maximum);
    }
    int average_value=sum/size_array;
    cout<<endl<<"Сумма элементов массива: "<<sum<<endl;
    cout<<"Среднее значение: "<<average_value<<endl;
    cout<<"Максимальный элемент массива: "<<maximum<<endl;
    delete[] array;
    
    return 0;
}

    

