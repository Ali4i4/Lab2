#include <iostream>

using namespace std;

int main()
{
    cout << "Добро пожаловать в приложение!" << endl << "Пора за работу! Начнём создавать таблицу заказов " << endl << endl << "Введите количество заказов: "; // ПОТОМ = ПОКА СИН НЕ \n
    int n;
    cin >> n;
    cout << endl;
    int count;
    int z;
    int m = 4; 
    string cafe[n][m];
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
        }
        cout << endl;
    }
    int choice;
    cout <<  endl << "Нажмите " << endl << "1 - перезапись таблицы заказов" << endl << "2 - просмотр таблицы заказов" << endl << "3 - изменение заказа под номером N" << endl << "4 - фильтрация по номеру стола" << endl << "5 - подсчет номера столика с максимальным ожиданием" << endl << "6 - показать под номером N" << endl << "7 - сортировка по времени ожидания" << endl << "0 - выход из приложения" << endl;
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
                    }
                    n = order;
                    cout << endl;
                }
            }
        }
        if (choice == 2)
        {
            cout << endl << "Текущая таблица заказов: " << endl;
            cout << "№ | Номер стола |   Блюдо   | Время приготовления " << endl; 
            for (int i = 0; i < n; i++)
                cout << cafe[i][0] << "      " << "стол " << cafe[i][1] << "          " << cafe[i][2] << "        " << cafe[i][3] << "   " << endl;
        }
        if (choice == 3)
        {
            int c = 0;
            int choice3;
            cout << endl << "В заказе под каким номером требуются изменения? ";
            cin >> choice3;
            cin.ignore();
            cout << endl;
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
                        c = 1;
                    }
                }
            }
            if (c == 0)
                cout << "Введённый номер заказа не существует. Повторите попытку позже. " << endl;
                
        }
        if (choice == 4)
        {
            int prove = 0;
            cout << endl << "Введите номер стола для фильтрации: ";
            cin >> choice;
            cout << endl;
            int z;
            int k = 1;
            for (int i = 0; i < n; i++)
            {
                if (stoi(cafe[i][1]) == choice)
                {
                    if (k == 1)
                    {
                        z = i;
                        cout << "Детали заказа для " << choice << " стола: " << endl << "Номер заказа " << cafe[z][0] << ", " << cafe[z][2] << ", время приготовления (в минутах) - " << cafe[z][3] << endl;
                    }
                    else
                    {
                        z = i;
                        cout << "Номер заказа " << cafe[z][0] << ", " << cafe[z][2] << ", время приготовления (в минутах) - " << cafe[z][3] << endl;
                    }
                    k++;
                    prove = 1;
                }
            }
            if (prove == 0)
                cout << "Введённый номер стола не действителен для данной таблицы. Повторите попытку позже." << endl;
        }
        if (choice == 5)
        {  
            cout << endl << "Столик с максимальным ожиданием - ";
            int k = 0;
            int sum;
            int max;
            int tab;
            while (k < n)
            {
                sum = 0;
                for (int i = 0; i < n; i++)
                {
                    if (stoi(cafe[i][1]) == stoi(cafe[k][1]))
                        sum += stoi(cafe[i][3]);
                    //cout << endl << "k = " << k << ", i = " << i << ", sum = " << sum;
                }
                if (max < sum)
                {
                    max = sum;
                    tab = k;
                }
                //cout << "max = " << max << ", tab = " << tab << endl;
                k++;
            }
            cout << cafe[tab][1] << " (время ожидания = " << max << ")";
        } 
        if (choice == 6)
        {
            cout << endl << "Под каким номером заказа посмотреть? ";
            int nom;
            cin >> nom;
            cout << endl << "Детали заказа под номером " << nom << ": " << "стол " << cafe[nom  - 1][1] << ", " << cafe[nom - 1][2] << ", " << "время приготовления - " << cafe[nom - 1][3] << endl;
        }
        if (choice == 7)
        {
            cout << endl << "Таблица заказов в порядке убывания длительности приготовления блюда: " << endl;
            for (int I = 0; I < n; I++)
            {
                int Max = 0, MaxI;
                for (int i = I; i < n; i++)
                {
                    if (stoi(cafe[i][3]) >= Max)
                    {
                        Max = stoi(cafe[i][3]);
                        MaxI = i;
                    }
                }
                for (int j = 0; j < 4; j++)
                {
                    string word;
                    word = cafe[I][j];
                    cafe[I][j].clear();
                    cafe[I][j] = cafe[MaxI][j];
                    cafe[MaxI][j].clear();
                    cafe[MaxI][j] = word;
                    word.clear();
                }
                cout << cafe[I][0] << "      " << "стол " << cafe[I][1] << "      " << cafe[I][2] << "        " << cafe[I][3] << "   " << endl;
            }
        }
        cout << endl << endl << "Что дальше? " << endl << "Нажмите " << endl << "1 - перезапись таблицы заказов" << endl << "2 - просмотр таблицы заказов" << endl << "3 - изменение заказа под номером N" << endl << "4 - фильтрация по номеру стола" << endl << "5 - подсчет номера столика с максимальным ожиданием" << endl << "6 - показать под номером N" << endl << "7 - сортировка по времени ожидания" << endl << "0 - выход из приложения" << endl;
        cin >> choice;
    }
    cout << "Хорошая работа! Ждём ващего возвращения! ";
    return 0;
}
