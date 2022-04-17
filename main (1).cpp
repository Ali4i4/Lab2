#include <iostream>

using namespace std;

int main()
{
    cout << "Добро пожаловать в приложение!" << endl << "Пора за работу! Начнём создавать таблицу заказов " << endl;
    cout << "Введите количество строк: "; // ПОТОМ = ПОКА СИН НЕ \n
    int n;
    cin >> n;
    int b;
    int m = 4; //столбцы = номер пп номер стола блюдо длительность
    string cafe[n][m];
    cin.ignore();
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (j == 0)
            {
                b = i + 1;
                cafe[i][j] = to_string(b);
            }
            else
            {
                if (j == 1)
                {
                    cout << "Введите номер стола: ";
                    getline(cin, cafe[i][j]);
                }
                if (j == 2)
                {
                    cout << "Введите блюдо: ";
                    getline(cin, cafe[i][j]);
                }
                if (j == 3)
                {
                    cout << "Введите время приготовления (в минутах): "; //!!
                    getline(cin, cafe[i][j]); 
                }
            }
        }
    }
    int c;
    int change;
    cout <<  endl << "Нажмите " << endl << "1 - для перезаписи таблицы заказов" << endl << "2 - для просмотра таблицы заказов" << endl << "3 - для изменения заказа под номером N" << endl << "4 - для фильтрации по номеру стола" << endl << "5 - выход из приложения" << endl;
    cin >> c;
    while (c != 5)
    {
        if (c == 2)
        {
            cout << "№ | Номер стола | Блюдо | Время приготовления " << endl; //фиксированные пробелы
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < m; j++)
                {
                    if (j == 0)
                    {
                        cout << cafe[i][j] << "      ";
                    }
                    if (j == 1)
                    {
                        cout << "стол " << cafe[i][j] << "      ";
                    }
                    if (j == 2)
                    {
                        cout << cafe[i][j] << "        ";
                    }
                    if (j == 3)
                    {
                        cout << cafe[i][j] << "   ";
                    }
                }
                cout << endl;
            }
        }
        if (c == 3)
        {
            cout <<endl << "Под каким номером требуются изменения? ";
            cin >> change;
            cin.ignore();
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < m; j++)
                {
                    if (cafe[i][0] == to_string(change))
                    {
                        if (j == 1)
                        {
                            cout << "Введите номер стола: ";
                            getline(cin, cafe[i][j]);
                        }
                        if (j == 2)
                        {
                            cout << "Введите блюдо: ";
                            getline(cin, cafe[i][j]);
                        }
                        if (j == 3)
                        {
                            cout << "Введите время приготовления (в минутах): "; //!!
                            getline(cin, cafe[i][j]); 
                        }
                    }
                }
            }
        }
        cout << "Что дальше? ";
        cin >> c;
    }
    return 0;
}
