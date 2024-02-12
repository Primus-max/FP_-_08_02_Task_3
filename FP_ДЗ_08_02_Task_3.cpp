﻿// Пользователь вводит прибыль фирмы за год (12 месяцев).
// Затем пользователь вводит диапазон(например, 3 и 6 — поиск
// между 3 - м и 6 - м месяцем).Необходимо определить месяц,
// в котором прибыль была максимальна и месяц, в котором
// прибыль была минимальна с учетом выбранного диапазона.

#include <iostream>
#include <windows.h>
using namespace std;

const int CalendarSize = 12;
int Calendar[CalendarSize];

/// <summary>
/// Метод проверки високосного года
/// </summary>
/// <param name="year">Текущий год</param>
/// <returns>bool является год високосным или нет</returns>
bool IsLeapYear(int year)
{
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}


/// <summary>
/// Метод заполнения массива днями 
/// </summary>
/// <param name="year">Текущий год</param>
/// <returns>Заполняет массив</returns>
void FillDaysInMonth(int year)
{
    for (int i = 1; i <= CalendarSize; i++)
    {
        int daysInMonth = 28 + (i + i / 8) % 2 + 2 % i + 2 * (1 / i);

        if (i == 2 && IsLeapYear(year))
            daysInMonth++;

        Calendar[i] = daysInMonth;
    }
}

double CalcMinProfit() {

}

double CalcMaxProfit(int monthStart, int monthEnd)
{
    double result = 0;
    int minDays = Calendar[monthStart];
    for (int i = monthStart; i <= monthEnd; i++)
    {
        if (Calendar[i] < minDays)
            minDays = Calendar[i];

    }
}

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    double profitForYear = 0, maxProfit = 0, minProfit = 0;
    int year = 0, monthStart = 0, monthEnd =0;

    FillDaysInMonth(2023);

    cout << "Калькулятор расчёта прибыли за указанный период в году. " << endl
         << + "Будет рассчитана максимальная и минимальная прибыль за указанный период\n";
    cout << "--------------------------------------------------------" << endl;
    cout << "Введите год для расчёта : ";
    cin >> year;
    cout << "Введите прибыль за весь год : ";
    cin >> profitForYear;
    cout << "Введите первый месяц (начало) : ";
    cin >> monthStart;
    cout << "Введите последний месяц (конец) : ";
    cin >> monthEnd;


}

