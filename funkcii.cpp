#include <iostream>
using namespace std;

string* Rewrite(int n, int m, int count, string** cafe){
    cout << endl << "Введите новое число заказов, не превышающее " << n << ": ";
    int order;
    cin >> order;
    cin.ignore();
    cout << endl;
    if (order > n)
        cout << "Введено количество заказов, не соответствующее требованию. Повторите попытку позже. " << endl;
    else
    {
        for (int i = 0; i < order; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (j == 0)
                {
                    count = i + 1;
                    cafe[i][j] = to_string(count);
            }
                if (j == 1)
                {
                    cout << "Введите номер стола для " << count << " заказа: ";
                    getline(cin, cafe[i][j]);
                }
                if (j == 2)
                {
                    cout << "Введите блюдо: ";
                    getline(cin, cafe[i][j]);
                }
                if (j == 3)
                {
                    cout << "Введите время приготовления (в минутах): ";
                    getline(cin, cafe[i][j]); 
                }
                if (j == 4)
                {
                    cout << "Введите время обслуживания клиента официантом: ";
                    getline(cin, cafe[i][j]);
                }
            }
            n = order;
            cout << endl;
        }
    }
    return 0;
}

string* Look(int n, int m, int z, int replace, string** cafe, string** add){
    cout << endl << "Текущая таблица заказов: " << endl;
    cout << "№ | Номер стола |   Блюдо   | Время приготовления | Время обслуживания " << endl; 
    for (int i = 0; i < n; i++)
    {
        if (replace == 0)
            cout << cafe[i][0] << "        " << cafe[i][1] << "          " << cafe[i][2] << "             " << cafe[i][3] << "                   " << cafe[i][4] << endl;
        else
            cout << add[i][0] << "        " << add[i][1] << "          " << add[i][2] << "             " << add[i][3] << "                   " << add[i][4] << endl;
    } 
    return 0;
}

string* Change(int n, int m, string** cafe){
    int choice3;
    cout << endl << "В заказе под каким номером требуются изменения? ";
    cin >> choice3;
    cin.ignore();
    if (choice3 > n || choice3 <= 0)
        cout << endl << "Номер заказа не существует. Повторите попытку позже. " << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (cafe[i][0] == to_string(choice3))
            {
                if (j == 1)
                {
                    cout << "Введите новый номер стола: ";
                    getline(cin, cafe[i][j]);
                }
                if (j == 2)
                {
                    cout << "Введите блюдо: ";
                    getline(cin, cafe[i][j]);
                    }
                if (j == 3)
                {
                    cout << "Введите время приготовления (в минутах): ";
                    getline(cin, cafe[i][j]); 
                }
                if (j == 4)
                {
                    cout << "Введите время обслуживания клиента официантом: ";
                    getline(cin, cafe[i][j]);
                }
            }
        }
    }
    return 0;
}

string* Filtr(int n, int m, string** cafe){
    int prove = 0;
    cout << endl << "Введите номер стола для фильтрации: ";
    int choice4;
    cin >> choice4;
    cout << endl;
    int z;
    int k = 1;
    for (int i = 0; i < n; i++)
    {
        if (stoi(cafe[i][1]) == choice4)
        {
            z = i;
            if (k == 1)
            {
                cout << "Детали заказа для " << choice4 << " стола: " << endl << "Номер заказа " << cafe[z][0] << ", " << cafe[z][2] << ", время приготовления (в минутах) - " << cafe[z][3] << ", время обслуживания - " << cafe[z][4] << endl;
                    }
            else
            {
                cout << "Номер заказа " << cafe[z][0] << ", " << cafe[z][2] << ", время приготовления (в минутах) - " << cafe[z][3] << ", время обслуживания - " << cafe[z][4] << endl;
                    }
            k++;
            prove = 1;
        }
    }
    if (prove == 0)
        cout << "Введённый номер стола не действителен для данной таблицы. Повторите попытку позже." << endl;
    return 0;
}

string* Max(int n, int m, string** cafe){
    cout << endl << "Столик с максимальным ожиданием: " << endl;
    int k = 0;
    int sum = 0;
    int max = 0;
    int l = 2;
    int b[n][l];
    while (k < n)
    {
        sum = 0;
        for (int i = 0; i < n; i++)
        {
            if (stoi(cafe[k][1]) == stoi(cafe[i][1]))
                sum += stoi(cafe[i][3]);
        }
        if (max < sum)
            max = sum;
        b[k][0] = stoi(cafe[k][1]);
        b[k][1] = sum;
        k++;
    } //нашли максимум
    k = 0;
    while (k < n)
    {
        for (int i = 0; i < n; i++)
        {
            if (b[k][0] == b[i][0] && i != k)
            {
                b[i][1] = 0;
                b[i][0] = 0;
            }
        }
        k++;
    }
    for (int i = 0; i < n; i++)
    {
        if (b[i][1] == max)
            cout << "стол " << b[i][0] << " (время ожидания = " << max << ")" << endl;
    }
    return 0;
}

string* Nomer(int n, int m, string** cafe){
    cout << endl << "Под каким номером заказа посмотреть? ";
    int nom;
    cin >> nom;
    if (nom > n)
    cout << endl << "Введённый номер заказа не существует. Повторите попытку позже. ";
    else
    {
        int str;
        cout << endl << "Детали заказа под номером " << nom << ": " ;
        for (int i = 0; i < n; i++)
        {
            if (stoi(cafe[i][0]) == nom)
            {
                str = i;
            }
        }
        cout << "стол " << cafe[str][1] << ", " << cafe[str][2] << ", время приготовления - " << cafe[str][3] << ", время обслуживания - " << cafe[str][4] << endl;
    }
    return 0;
}

string* Sortirovka1(int n, int m, string** cafe){
    cout << endl << "Таблица заказов в порядке убывания длительности приготовления блюда: " << endl << endl << "№ | Номер стола |   Блюдо   | Время приготовления " << endl;
    for (int I=0; I<n; I++){
        int Max = 0, MaxI;
        for (int i=I; i<n; i++){
            if (stoi(cafe[i][3]) >= Max){
                Max = stoi(cafe[i][3]);
                MaxI = i;
            }
        }
        for (int j=0; j<4; j++){
            string word;
            word = cafe[I][j];
            (cafe[I][j]).clear();
            cafe[I][j] = cafe[MaxI][j];
            (cafe[MaxI][j]).clear();
            cafe[MaxI][j] = word;
            word.clear();
        }
        for (int j=0; j<4; j++){
            cout << cafe[I][j] << " ";
        }
        cout << endl;
    }
    return 0;
}

string* Sortirovka2(int n, int m, string** cafe){
    cout << endl << "Таблица заказов в порядке возрастания длительности приготовления блюда: " << endl << endl << "№ | Номер стола |   Блюдо   | Время приготовления " << endl; 
    int znach;
    for (int k = 0; k < n; k++)
    {
        for (int i = 0; i < n - 1; i++)
        {
            znach = stoi(cafe[i + 1][3]);
            if (stoi(cafe[i][3]) > znach)
            {
                for (int j = 0; j < m; j++)
                {
                    string save;
                    save = cafe[i + 1][j];
                    cafe[i + 1][j].clear();
                    cafe[i + 1][j] = cafe[i][j];
                    cafe[i][j].clear();
                    cafe [i][j] = save;
                }
            }
        }
    }
    for (int i = 0; i < n; i++){
        cout << cafe[i][0] << "        " << cafe[i][1] << "          " << cafe[i][2] << "             " << cafe[i][3] << "          " << cafe[i][4] << endl;
    }
    return 0;
}    

string* Adding(int n, int m, int replace, int z, string** cafe, string** add){
    cout << "Введите детали  нового заказа: " << endl;
    cin.ignore();
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            add[i][j] = cafe[i][j];
        }
    }
    for (int j = 0; j < m; j++)
    {
        if (j == 0)
            add[z - 1][j] = to_string(z);
        if (j == 1)
        {
            cout << "Введите новый номер стола: ";
            getline(cin, add[z - 1][j]);
        }
        if (j == 2)
        {
            cout << "Введите блюдо: ";
            getline(cin, add[z - 1][j]);
        }
        if (j == 3)
        {
            cout << "Введите время приготовления (в минутах): ";
            getline(cin, add[z - 1][j]); 
        }
        if (j == 4)
        {
            cout << "Введите время обслуживания клиента официантом: ";
            getline(cin, add[z - 1][j]);
        }
    }
    cout << endl;
    n += 1;
    replace = 1;
    return 0;
}

string* Delete(int n, int m, string** cafe){
    cout << endl << "Под каким номером удалить заказ? " << endl;
    int choice9;
    cin >> choice9;
    choice9 -= 1;
    if (choice9 + 1 > n || choice9 <= 0) 
        cout << "Данный номер заказа не существует. Повторите попытку позже." << endl;
    if (choice9 + 1 == n)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cafe[choice9][j].clear();
            }
        }
    }
    else
    {
        for (choice9; choice9 < n - 1; choice9++)
        {
            for (int j = 0; j < m; j++)
            {
                if (j != 0)
                    cafe[choice9][j] = cafe[choice9 + 1][j];
            }
        }
    }
    cout << "Успешно удалено. " ;
    n = n - 1;
    return 0;
}

string* Middle(int n, int m, string** cafe){
    int summa = 0;
    cout << "Среднее время обслуживание клиента официантом: ";
    for (int i = 0; i < n; i++)
    {
        summa = summa + stoi(cafe[i][4]);
    }
    cout << summa/n << endl;
    summa = 0;
    cout << "Среднее время обслуживание клиента официантом, включая приготовление блюдо: ";
    for (int i = 0; i < n; i++)
    {
        summa = summa + stoi(cafe[i][4]) + stoi(cafe[i][3]);
    }
    cout << summa/n << endl;
    return 0;
}
 
int Vibor(int choice){
    cout <<  endl << "Нажмите " << endl << "1 - перезапись таблицы заказов" << endl << "2 - просмотр таблицы заказов" << endl << "3 - изменение заказа под номером N" << endl << "4 - фильтрация по номеру стола" << endl << "5 - подсчет номера столика с максимальным ожиданием" << endl << "6 - показать под номером N" << endl << "7 - сортировка по времени ожидания" << endl << "8 - добавить под номером N" << endl << "9 - удалить под номером N" << endl << "10 - вывести среднее время обслуживание клиента" << endl << "0 - выход из приложения" << endl;
    cin >> choice;
    return 0;
}   

int main()
{
    cout << "Добро пожаловать в приложение!" << endl << "Пора за работу! Начнём создавать таблицу заказов " << endl << endl << "Введите количество заказов: "; // ПОТОМ = ПОКА СИН НЕ \n
    int n;
    cin >> n;
    int m = 5; 
    cout << endl;
    int count;
    int choice;
    int replace = 0;
    string** cafe = new string*[n];
    cin.ignore();
    for (int i=0; i < n; i++){
        cafe[i] = new string[m];
    }
    int z = n + 1;
    string** add = new string*[z];
    for (int i=0; i < n; i++){
        add[z] = new string[m];
    }
    cin.ignore();
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (j == 0)
            {
                count = i + 1;
                cafe[i][j] = to_string(count);
            }
            if (j == 1)
            {
                cout << "Введите номер стола для " << count << " заказа: ";
                getline(cin, cafe[i][j]);
            }
            if (j == 2)
            {
                cout << "Введите блюдо: ";
                getline(cin, cafe[i][j]);
            }
            if (j == 3)
            {
                cout << "Введите время приготовления (в минутах): ";
                getline(cin, cafe[i][j]); 
            }
            if (j == 4)
            {
                cout << "Введите время обслуживания клиента официантом: ";
                getline(cin, cafe[i][j]);
            }
        }
        cout << endl;
    }
    Vibor(choice);
    while (choice != 0)
    {
        if (choice == 1)
        {
            Rewrite(n, m, count, cafe);
        }
        if (choice == 2)
        {
            Look(n, m, z, replace, cafe, add);
        }
        if (choice == 3)
        {
            Change(n, m, cafe);
        }
        if (choice == 4)
        {
            Filtr(n, m, cafe);
        }
        if (choice == 5)
        { 
            Max(n, m, cafe);
        } 
        if (choice == 6)
        {
            Nomer(n, m, cafe);
        }
        if (choice == 7)
        {
            cout << "Выберите сортировку: " << endl <<"1 - по убыванию " << endl << "2 - по возрастанию " << endl;
            int choice7;
            cin >> choice7;
            if (choice7 == 1)
            {
                Sortirovka1(n, m, cafe);
            }
            if (choice7 == 2)
            {
                Sortirovka2(n, m, cafe);
            }
        }
        if (choice == 8)
        {
            Adding(n, m, replace, z, cafe, add);
        }
        if (choice == 9)
        {
            Delete(n, m, cafe);
        }
        if (choice == 10)
        {
            Middle(n, m, cafe);
        }
        Vibor(choice);
    }
    cout << "Хорошая работа! Ждём ващего возвращения! ";
    return 0;
}
