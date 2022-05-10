//p1
#include "std_lib_facilities.h"

struct Date //data type date
{
	Date(int y, int m, int d);

	int y;
	int m;
	int d;
};


Date::Date(int yy, int mm, int dd) //constructor for initialisation
{
	int Minyear(1900), Maxyear(3000);
	if (yy > Maxyear || yy < Minyear)
		cout << " year is not in calender.";
	if (mm > 12 || mm < 1)
		cout << "month not in calender. ";
	if (dd > 31 || dd < 1)
		cout << "day not in  calender." << endl;
	else
	{
		y = yy; m = mm; d = dd;
	}
}


void add_day(Date& dd, int n)
{
	//increase dd by n days
	dd.d += n;
}


ostream& operator<<(ostream& os, const Date& d)
{
	return os << "(" << d.y
		<< "," << d.m
		<< "," << d.d << ")";
}


int main()
{
	Date today( 1976, 8, 28 );
	Date tomorrow( today );

	add_day(tomorrow, 1);

	cout << today << endl;
	cout << tomorrow << endl;

	//invalid date
	Date invalidDate{ 1800, 27, 32 };

	keep_window_open();
	return 0;
}
-------------------------------------------------------------------------------------------------------------------------------------------
//p3
	
	#include "std_lib_facilities.h"

// -----------------------------------------------------------------------------

class Date
{
public:
	Date(int y, int m, int d);

	void add_day(int n);

	int month() const { return m; }
	int day() const { return d; }
	int year() const { return y; }

private:
	int y, m, d; //
};

// -----------------------------------------------------------------------------

Date::Date(int yy, int mm, int dd)
{
	int yearMin(1900), yearMax(3000);
	if (yy > yearMax || yy < yearMin)
		cout << "year is not in calender.";
	if (mm > 12 || mm < 1)
		cout << "month is not in calender.";
	if (dd > 31 || dd < 1)
		cout << " day not in calender." << endl;
	else
	{
		y = yy; m = mm; d = dd;
	}
}

// -----------------------------------------------------------------------------

void Date::add_day(int n)
{
	//if d += n is more than 31, make it 1, else return d
	if (d += n > 31)
	{
		d = 1;
		++m;
	}
}

// -----------------------------------------------------------------------------

ostream& operator<<(ostream& os, const Date& d)
{
	return os << "(" << d.year()
		<< "," << d.month()
		<< "," << d.day() << ")";
}

// -----------------------------------------------------------------------------

int main()
{
	Date today( 1978, 6, 31 );
	Date tomorrow( today );

	tomorrow.add_day(1);

	cout << today << endl;
	cout << tomorrow << endl;

	//invalid date
	Date invalidDate{ 1300, 27, -4 };

	keep_window_open();
	return 0;
}
------------------------------------------------------------------------------------------------------------------------------------
	//p4
	#include "std_lib_facilities.h"

// -----------------------------------------------------------------------------

enum class Month //defined an enumeration class
{
	jan = 1, feb, mar, apr, may, jun, jul, aug, sep, oct, nov, dec//created user defined data type month
};

// -----------------------------------------------------------------------------

class Date
{
public:
	Date(int y, Month m, int d);

	void add_day(int n);

	Month month() const { return m; }
	int day() const { return d; }
	int year() const { return y; }

private:
	int y, d;
	Month m;
};

// -----------------------------------------------------------------------------

Date::Date(int yy, Month mm, int dd)
{
	int yearMin(1900), yearMax(3000);
	if (yy > yearMax || yy < yearMin)
		cout << "year is not in calender.";
	if (int(mm) > 12 || int(mm) < 1) // you get a c cast
		cout << " month  is not in calender.";
	if (dd > 31 || dd < 1)
		cout << " day  is not in calender." << endl;
	else
	{
		y = yy; m = mm; d = dd;
	}
}

// -----------------------------------------------------------------------------

void Date::add_day(int n)
{
	//if d += n is more than 31, make it 1, else return d
	if (d += n > 31)
	{
		d = 1;
		int nextM = int(m) + 1;		// and you get a c cast
		if (nextM > 12)
		{
			m = Month::jan;
			if (++y > 3000)
				cout << "szia! it's not year 3000; " << endl;
		}
		else
			m = Month(nextM);			
	}
}

// -----------------------------------------------------------------------------

ostream& operator<<(ostream& os, const Date& d)
{
	return os << "(" << d.year()
		<< "," << int(d.month())	
		<< "," << d.day() << ")";
}

// -----------------------------------------------------------------------------

int main()
{
	//c casting everywhere!

	Date today( 1978, Month::dec, 31 );
	Date tomorrow( today );

	tomorrow.add_day(1);

	cout << today << endl;
	cout << tomorrow << endl;

	//invalid date
	Date invalidDate{ 1300, Month::dec, -4 };

	keep_window_open();
	return 0;
}
