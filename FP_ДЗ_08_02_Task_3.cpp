// Пользователь вводит прибыль фирмы за год (12 месяцев).
// Затем пользователь вводит диапазон(например, 3 и 6 — поиск
// между 3 - м и 6 - м месяцем).Необходимо определить месяц,
// в котором прибыль была максимальна и месяц, в котором
// прибыль была минимальна с учетом выбранного диапазона.

#include <iostream>
#include <windows.h>
using namespace std;

const int CalendarSize = 12;
int Calendar[CalendarSize];
double ProfitsPerMonth[CalendarSize];


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
        // Формула расчёта дней в году
        int daysInMonth = 28 + (i + i / 8) % 2 + 2 % i + 2 * (1 / i);

        if (i == 2 && IsLeapYear(year))
            daysInMonth++;

        Calendar[i - 1] = daysInMonth;
    }
}


/// <summary>
/// Метод расчёта прибыли по месяцам
/// </summary>
/// <param name="totalProfit">Заполняет массив</param>
void CalcProfitPerMonth(double totalProfit)
{
    int totalDaysInYear = 0;

    // Получаю общее количество дней в году
    for (int i = 0; i < CalendarSize; i++)
        totalDaysInYear += Calendar[i];

    // Распределяю прибыль по месяцам
    for (int i = 0; i < CalendarSize; i++)
        ProfitsPerMonth[i] = totalProfit * (static_cast<double>(Calendar[i]) / totalDaysInYear);
}

/// <summary>
/// Общий метод для подсчёта и вывода максимального и минимального дохода
/// </summary>
void FindProfit(bool findMax, int monthStart, int monthEnd)
{
    int extProfitMonth = monthStart;
    double extProfit = ProfitsPerMonth[monthStart];

    for (int i = monthStart + 1; i <= monthEnd; i++)
    {
        if ((findMax && ProfitsPerMonth[i] > extProfit) || (!findMax && ProfitsPerMonth[i] < extProfit))
        {
            extProfit = ProfitsPerMonth[i];
            extProfitMonth = i;
        }
    }

    std::cout << (findMax ? "Максимальная" : "Минимальная") << " прибыль была в " << extProfitMonth
        << " месяце" << " составила: " << extProfit << " денег " << std::endl;
}

/// <summary>
/// Показывает максимальную выручку в указанном диапазоне и месяц
/// </summary>
/// <param name="monthStart">Начало диапазона</param>
/// <param name="monthEnd">Конец диапазона</param>
void MaxProfit(int monthStart, int monthEnd)
{
    FindProfit(true, monthStart, monthEnd);
}


/// <summary>
/// Показывает минимальную выручку в указанном диапазоне и месяц
/// </summary>
/// <param name="monthStart">Начало диапазона</param>
/// <param name="monthEnd">Конец диапазона</param>
void MinProfit(int monthStart, int monthEnd)
{
    FindProfit(false, monthStart, monthEnd);
}

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    double profitForYear = 0, maxProfit = 0, minProfit = 0;
    int year = 0, monthStart = 0, monthEnd =0;

    FillDaysInMonth(2023);
    CalcProfitPerMonth(300000);

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


    MinProfit(monthStart, monthEnd);
    MaxProfit(monthStart, monthEnd);    
}

