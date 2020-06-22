#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <ctime>
using namespace std;
 

int firstDayofNewYearAndMonth (int);
int numOfDaysInAMonth (int, bool); 
void printHeader (int); 
void printMonth (int, int&); 
void skipToDay (int);
bool checkYear(int);
 
int main () 
{
   
    int year, firstDayInCurrentMonth;
    int currentMonth = 1;
    int numDays;
   
    cout << "Ban muon xem lich cua nam nao ? ";
    cin >> year;
    
    cout << endl;
    
    firstDayInCurrentMonth = firstDayofNewYearAndMonth(year);
    bool IsCheck = checkYear(year);
   
    cout << year << endl;
    
    while (currentMonth <= 12) {
        numDays = numOfDaysInAMonth(currentMonth, IsCheck);
        printHeader(currentMonth);
        printMonth(numDays, firstDayInCurrentMonth);
        cout << endl << endl << endl;
        currentMonth = currentMonth + 1;
    }
    
    cout << endl;
    // current date/time based on current system
    time_t now = time(0);

    tm *ltm = localtime(&now);

    // print various components of tm structure.
    cout << "Bay gio la  :\n ";
    cout << "Gio: "<< 1 + ltm->tm_hour << ":";
    cout << 1 + ltm->tm_min << ":";
    cout << 1 + ltm->tm_sec << endl;
    cout << "Ngay: "<<  ltm->tm_mday << endl;
    cout << "Thang: "<< 1 + ltm->tm_mon<< endl;
    cout << "Nam : "<< 1900 + ltm->tm_year << endl;
   
    system("PAUSE");
    return EXIT_SUCCESS;
}

/**************************************************************************/
/* This function calculates the first day of the new year                 */
/**************************************************************************/

int  firstDayofNewYearAndMonth(int year) { 
    int day_start; 
    int x1, x2, x3; 
    x1 = (year - 1)/ 4;
    x2 = (year - 1)/ 100; 
    x3 = (year - 1)/ 400; 
    day_start = (year + x1 - x2 + x3) %7; 
    return day_start; 
} 

bool checkYear(int year) { 
  // Trả về true nếu
  // chia hết cho 4 nhưng không chia hết cho 100 
  // hoặc chia hết cho 400
  return (((year % 4 == 0) && (year % 100 != 0)) || 
          (year % 400 == 0)); 
}

/**************************************************************************/    
/* This function returns the number of days in a month                    */
/**************************************************************************/

int numOfDaysInAMonth (int m, bool IsCheck){
    if (m == 1 || m == 3 || m == 5 || m == 7 || m == 8 || m == 10 || m == 12) 
        return(31);
    else if (m == 2) 
        return IsCheck == true ? (29) : (28);
    else if (m == 4 || m == 6 || m == 9 || m == 11) 
        return(30);
}

/**************************************************************************/
/*    It takes the number of the month and prints outs the name of the    */
/*  month and the frame of the calander                                   */
/**************************************************************************/

void printHeader (int m) {
    if (m == 1){ 
        cout << "January" << endl; }
    else if (m == 2) { 
        cout << "February" << endl; } 
    else if (m == 3) {     
         cout << "March" << endl; }
    else if (m == 4) {  
         cout << "April" << endl; }
    else if (m == 5) {  
         cout << "May" << endl; }
    else if (m == 6) {  
         cout << "June" << endl; }
    else if (m == 7) {  
         cout << "July" << endl; }
    else if (m == 8) { 
         cout << "August" << endl; }
    else if (m == 9) {  
        cout << "September" << endl; }
    else if (m == 10) {  
        cout << "October" << endl; }
    else if (m == 11) {  
        cout << "November" << endl; }
    else if (m == 12) {  
        cout << "December" << endl; }

    cout << " S  M  T  W  T  F  S" <<endl;
    cout << "_____________________" << endl;
}

/**************************************************************************/
/* Helps with the skipToDay function blah blah blah                       */
/**************************************************************************/

void skip (int i) {
    while (i > 0) {
        cout << " ";
        i = i - 1;
    }
}

/**************************************************************************/ 
/* This function prints out the days in the month after the header for    */
/* each month                                                             */
/**************************************************************************/

void printMonth (int numDays, int &weekDay) {
    int day = 1;
    skipToDay(weekDay);
    while (day <= numDays) {
        cout << setw(2) << day << " ";
        if (weekDay == 6){
            cout << endl;
            weekDay = 0;
        }
    else weekDay = weekDay + 1;
    day = day + 1; 
    }
}

/**************************************************************************/
/* Prints spaces in monthly calander                                      */
/**************************************************************************/

void skipToDay (int d){
    return skip(3*d);
}
