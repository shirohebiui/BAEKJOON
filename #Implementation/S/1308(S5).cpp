#include <iostream>

using namespace std;

int isYun(int year) {
    if(year % 400 == 0) return 1; //윤년
    if(year % 100 == 0) return 0; //평년
    if(year % 4 == 0) return 1; //윤년
    return 0; //평년
}
int day_set[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
int main() {
    std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL); std::cout.tie(NULL);

    int year, month, day;
    cin >> year >> month >> day;
    int y, m, d;
    cin >> y >> m >> d;
    if(y - year > 1000) { //gg
        cout << "gg\n";
        return 0;
    } else if(y - year == 1000) {
        if(month < m || (month == m && day <= d)) { //gg
            cout << "gg\n";
            return 0;
        }
    }

    int d_day = 0;
    if(year != y) {
        if(isYun(year)) day_set[2] = 29;
        d_day += day_set[month] - day;
        while(++month<=12) {
            d_day += day_set[month];
        }
        year++;

        while(year != y) {
            if(isYun(year)) d_day += 366;
            else d_day += 365;
            year++;
        }

        if(isYun(y)) day_set[2] = 29;
        else day_set[2] = 28;
        d_day += d;
        while(--m >= 1) {
            d_day += day_set[m];
        }
    } else {
        if(isYun(year)) day_set[2] = 29;
        if(month == m) {
            d_day += d-day;
        } else {
            d_day += day_set[month] - day;
            while(++month<m) {
                d_day += day_set[month];
            }
            d_day += d;
        }
    }
    cout <<"D-"<<d_day<<"\n";
    return 0;
}