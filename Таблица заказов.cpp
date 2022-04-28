#include <iostream>

using namespace std;

string* vvod (int n, int m, int count, string** a, int i, int j)
{
    if (j == 0)
    {
        count = i + 1;
        a[i][j] = to_string(count);
    }
    if (j == 1)
    {
        cout << "Введите номер стола для " << i + 1 << " заказа: ";
        getline(cin, a[i][j]);
    }
    if (j == 2)
    {
        cout << "Введите блюдо: ";
        getline(cin, a[i][j]);
    }
    if (j == 3)
    {
        cout << "Введите время приготовления (в минутах): ";
        getline(cin, a[i][j]); 
    }
    if (j == 4)
    {
        cout << "Введите время обслуживания клиента официантом: ";
        getline(cin, a[i][j]);
    }
    return 0;
}

string* change(int n, int m, string** a, int choice3, int count)
{
    int i, j;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (a[i][0] == to_string(choice3))
            {
                if (j == 1)
                {
                    cout << "Введите новый номер стола: ";
                    getline(cin, a[i][j]);
                }
                if (j == 2)
                {
                    cout << "Введите блюдо: ";
                    getline(cin, a[i][j]);
                    }
                if (j == 3)
                {
                    cout << "Введите время приготовления (в минутах): ";
                    getline(cin, a[i][j]); 
                }
                if (j == 4)
                {
                    cout << "Введите время обслуживания клиента официантом: " << endl;
                    getline(cin, a[i][j]);
                }
            }
        }
    }
    return 0;
}

string* filtr(int n, int m, string** a, int choice4)
{
    int prove = 0;
    int k = 1;
    for (int i = 0; i < n; i++)
    {
        if (stoi(a[i][1]) == choice4)
        {
            if (k == 1)
                cout << "Детали заказа для " << choice4 << " стола: " << endl << "Номер заказа " << a[i][0] << ", " << a[i][2] << ", время приготовления (в минутах) - " << a[i][3] << ", время обслуживания - " << a[i][4] << endl;
            else
                cout << "Номер заказа " << a[i][0] << ", " << a[i][2] << ", время приготовления (в минутах) - " << a[i][3] << ", время обслуживания - " << a[i][4] << endl;
            k++;
            prove = 1;
        }
    }
    if (prove == 0)
        cout << "Введённый номер стола не действителен для данной таблицы. Повторите попытку позже." << endl;
    return 0;
}

string* waiting(int n, int m, string** a)
{
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
            if (stoi(a[k][1]) == stoi(a[i][1]))
                sum += stoi(a[i][3]);
        }
        if (max < sum)
            max = sum;
        b[k][0] = stoi(a[k][1]);
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

string* nomer(int n, int m, string** a, int nom)
{
    int str;
    cout << endl << "Детали заказа под номером " << nom << ": " ;
    for (int i = 0; i < n; i++)
    {
        if (stoi(a[i][0]) == nom)
            str = i;
    }
    cout << "стол " << a[str][1] << ", " << a[str][2] << ", время приготовления - " << a[str][3] << ", время обслуживания - " << a[str][4] << endl;
    return 0;
}

string* sortirovka1(int n, int m, string** a)
{
    for (int I = 0; I < n; I++)
    {
        int Max = 0, MaxI;
        for (int i = I; i < n; i++)
        {
            if (stoi(a[i][3]) >= Max)
            {
                Max = stoi(a[i][3]);
                MaxI = i;
            }
        }
        for (int j = 0; j < 4; j++)
        {
            string word;
            word = a[I][j];
            (a[I][j]).clear();
            a[I][j] = a[MaxI][j];
            (a[MaxI][j]).clear();
            a[MaxI][j] = word;
            word.clear();
        }
    }
    return 0;
}

string* sortirovka2(int n, int m, string** cafe)
{
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
    return 0;
}

string* deleting(int n, int m, string** a, int choice9)
{
    choice9 -= 1;
    if (choice9 + 1 > n || choice9 <= 0) 
        cout << "Данный номер заказа не существует. Повторите попытку позже." << endl;
    if (choice9 + 1 == n)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
                a[choice9][j].clear();
        }
    }
    else
    {
        for (choice9; choice9 < n - 1; choice9++)
        {
            for (int j = 0; j < m; j++)
            {
                if (j != 0)
                    a[choice9][j] = a[choice9 + 1][j];
            }
        }
    }
    return 0;
}

string* middle(int n, int m, string** cafe)
{
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

int main()
{
    cout << "Добро пожаловать в приложение!" << endl << "Пора за работу! Начнём создавать таблицу заказов " << endl << endl << "Введите количество заказов: "; // ПОТОМ = ПОКА СИН НЕ \n
    int n;
    cin >> n;
    cin.ignore();
    int m = 5; 
    cout << endl;
    int count;
    int choice;
    int replace = 0;
    string** cafe = new string*[n];
    for (int i = 0; i < n; i++)
        cafe[i] = new string[m];
    int z = n + 1;
    string add[z][m];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            vvod(n, m, count, cafe, i, j);
        cout << endl;
    }
    cout <<  endl << "Нажмите " << endl << "1 - перезапись таблицы заказов" << endl << "2 - просмотр таблицы заказов" << endl << "3 - изменение заказа под номером N" << endl << "4 - фильтрация по номеру стола" << endl << "5 - подсчет номера столика с максимальным ожиданием" << endl << "6 - показать под номером N" << endl << "7 - сортировка по времени ожидания" << endl << "8 - добавить под номером N" << endl << "9 - удалить под номером N" << endl << "10 - вывести среднее время обслуживание клиента" << endl << "0 - выход из приложения" << endl;
    cin >> choice;
    while (choice != 0)
    {
        if (choice == 1)
        {
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
                        vvod (n, m, count, cafe, i, j);
                    cout << endl;
                }
                n = order;
            }
        }
        if (choice == 2)
        {
            cout << endl << "Текущая таблица заказов: " << endl;
            cout << "№ | Номер стола |   Блюдо   | Время приготовления | Время обслуживания " << endl; 
            for (int i = 0; i < n; i++)
            {
                if (replace == 0)
                    cout << cafe[i][0] << "        " << cafe[i][1] << "          " << cafe[i][2] << "             " << cafe[i][3] << "                   " << cafe[i][4] << endl;
                else
                    cout << add[i][0] << "        " << add[i][1] << "          " << add[i][2] << "             " << add[i][3] << "                   " << add[i][4] << endl;
            } 
        }
        if (choice == 3)
        {
            int choice3;
            cout << endl << "В заказе под каким номером требуются изменения? ";
            cin >> choice3;
            cin.ignore();
            if (choice3 > n || choice3 <= 0)
                cout << endl << "Номер заказа не существует. Повторите попытку позже. " << endl;
            else
                change(n, m, cafe, choice3, count);
        }
        if (choice == 4)
        {
            cout << endl << "Введите номер стола для фильтрации: ";
            int choice4;
            cin >> choice4;
            cout << endl;
            filtr(n, m, cafe, choice4);
        }
        if (choice == 5)
        { 
            cout << endl << "Столик с максимальным ожиданием: " << endl;
            waiting(n, m, cafe);
        } 
        if (choice == 6)
        {
            cout << endl << "Под каким номером заказа посмотреть? ";
            int nom;
            cin >> nom;
            if (nom > n)
                cout << endl << "Введённый номер заказа не существует. Повторите попытку позже. " << endl;
            else
                nomer(n, m, cafe, nom);
        }
        if (choice == 7)
        {
            cout << "Выберите сортировку: " << endl << "1 - по убыванию " << endl << "2 - по возрастанию " << endl;
            int choice7;
            cin >> choice7;
            if (choice7 == 1)
            {
                cout << endl << "Таблица заказов в порядке убывания длительности приготовления блюда: " << endl << endl << "№ | Номер стола |   Блюдо   | Время приготовления | Время обслуживания " << endl; 
                sortirovka1(n, m, cafe);
            }
            if (choice7 == 2)
            {
                cout << endl << "Таблица заказов в порядке возрастания длительности приготовления блюда: " << endl << endl << "№ | Номер стола |   Блюдо   | Время приготовления | Время обслуживания " << endl; 
                sortirovka2(n, m, cafe);
            }
            for (int i = 0; i < n; i++)
                cout << cafe[i][0] << "        " << cafe[i][1] << "          " << cafe[i][2] << "               " << cafe[i][3] << "                " << cafe[i][4] << endl;
        }
        if (choice == 8)
        {
            z = n + 1;
            cout << "Введите детали  нового заказа: " << endl << endl;
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
        }
        if (choice == 9)
        {
            cout << endl << "Под каким номером удалить заказ? " << endl;
            int choice9;
            cin >> choice9;
            deleting(n, m, cafe, choice9);
            cout << "Успешно удалено. " << endl;
            n = n - 1;
        }
        if (choice == 10)
        {
            middle(n, m, cafe);
        }
        cout <<  endl << "Нажмите " << endl << "1 - перезапись таблицы заказов" << endl << "2 - просмотр таблицы заказов" << endl << "3 - изменение заказа под номером N" << endl << "4 - фильтрация по номеру стола" << endl << "5 - подсчет номера столика с максимальным ожиданием" << endl << "6 - показать под номером N" << endl << "7 - сортировка по времени ожидания" << endl << "8 - добавить под номером N" << endl << "9 - удалить под номером N" << endl << "10 - вывести среднее время обслуживание клиента" << endl << "0 - выход из приложения" << endl;
        cin >> choice;
    }
    cout << "Хорошая работа! Ждём ващего возвращения! ";
    return 0;
}
