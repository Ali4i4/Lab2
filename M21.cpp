#include <iostream>

using namespace std;

//string* funkcia6(int m, int n, string *cafe){
  //  cout << endl << "Под каким номером посмотреть? ";
//    int nom;
 //   cin >> nom;
 //   for (int j = 0; j < 4; j++){
 //       cout << cafe[nom-1][j];
 //   }
 //   return 0;
//}

int main()
{
    cout << "Добро пожаловать в приложение!" << endl << "Пора за работу! Начнём создавать таблицу заказов " << endl << endl << "Введите количество заказов: "; // ПОТОМ = ПОКА СИН НЕ \n
    int n;
    cin >> n;
    cout << endl;
    int count;
    int z;
    //int filter;
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
            else
            {
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
        }
        cout << endl;
    }
    int choice;
    cout <<  endl << "Нажмите " << endl << "1 - перезапись таблицы заказов" << endl << "2 - просмотр таблицы заказов" << endl << "3 - изменение заказа под номером N" << endl << "4 - фильтрация по номеру стола" << endl << "5 - подсчет номера столика с максимальным ожиданием" << endl << "6 - показать под номером" << endl << "7 - сортировка по времени ожидания" << endl << "0 - выход из приложения" << endl;
    cin >> choice;
    while (choice != 0)
    {
        if (choice == 1)
            {
                int save = n;
                cout << "Введите новое количество заказов: ";
                int n;
                cin >> n;
                cin.ignore();
                cout << endl;
                for (int i = 0; i < n; i++)
                {
                    for (int j = 0; j < m; j++)
                    {
                        if (j == 0)
                        {
                            count = i + 1;
                            cafe[i][j] = to_string(count);
                        }
                        else
                        {
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
                    }
                    cout << endl;
                }
                if (n < save)
                {
                    n = n + 1;
                    for (n; n <= save; n++)
                    {
                        for (int j = 0; j < m; j++)
                        {
                            cafe[n][j].clear();
                        }
                    }
                }
            }
            if (choice == 2)
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
            if (choice == 3)
            {
                cout <<endl << "В заказе под каким номером требуются изменения? ";
                cin >> choice;
                cin.ignore();
                for (int i = 0; i < n; i++)
                {
                    for (int j = 0; j < m; j++)
                    {
                        if (cafe[i][0] == to_string(choice))
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
                                cout << "Введите время приготовления (в минутах): "; //!!
                                getline(cin, cafe[i][j]); 
                            }
                        }
                    }
                }
            }
            if (choice == 4)
            {
                cout << endl << "Введите номер стола для фильтрации: ";
                cin >> choice;
                for (int i = 0; i < n; i++)
                {
                    if (stoi(cafe[i][1]) == choice)
                    {
                        z = i;
                    }
                }
                cout << "Детали заказа для " << choice << " стола: "; 
                for (int j = 0; j < m; j++)
                {
                    if (j == 0)
                    {
                        cout << "Номер заказа " << cafe[z][j] << ", ";
                    }
                    if (j == 1)
                    {
                        cout << "стол " << cafe[z][j] << ", ";
                    }
                    if (j == 2)
                    {
                        cout << cafe[z][j] << ", ";
                    }
                    if (j == 3)
                    {
                        cout << cafe[z][j] << " минут.";
                    }
                }
                cout << endl;
            }
            if (choice == 5)
            {  
                cout << "Номер столика с максимальным ожиданием - " ;  
                int max = 0;  
                int preobraz; 
                int s; 
                for (int i = 0; i < n; i++)
                {  
                    for (int j = 0; j < m; j++)
                    {  
                        if  (j == 3)
                        { 
                            preobraz = stoi(cafe[i][j]); 
                            if (preobraz > max)
                            {  
                                max = preobraz; 
                                s = i;
                            } 
                        } 
                    }  
                }  
                cout << cafe[s][1]; 
            } 
            cout << endl;
            if (choice == 6){
            //funkcia6(n, m, *cafe);
                cout << endl << "Под каким номером посмотреть? ";
                int nom;
                cin >> nom;
                for (int j = 0; j < 4; j++){
                    cout << cafe[nom-1][j] << " ";
                }
                cout << endl;
            }
            if (choice == 7){
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
                        cafe[I][j].clear();
                        cafe[I][j] = cafe[MaxI][j];
                        cafe[MaxI][j].clear();
                        cafe[MaxI][j] = word;
                        word.clear();
                    }
                    for (int j=0; j<4; j++){
                        cout << cafe[I][j] << " ";
                    }
                    cout << endl;
                }
            }
    cout << "Что дальше? ";
    cout <<  endl << "Нажмите " << endl << "1 - перезапись таблицы заказов" << endl << "2 - просмотр таблицы заказов" << endl << "3 - изменение заказа под номером N" << endl << "4 - фильтрация по номеру стола" << endl << "5 - подсчет номера столика с максимальным ожиданием" << endl << "6 - показать под номером" << endl << "7 - сортировка по времени ожидания" << endl << "0 - выход из приложения" << endl;
    cin >> choice;
    }
    cout << "Хорошая работа! Ждём ващего возвращения! ";
    //return 0;
}
