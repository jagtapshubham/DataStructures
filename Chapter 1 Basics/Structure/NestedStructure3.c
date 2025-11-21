#include<stdio.h>
#include<string.h>

struct time {
	int hr;
	int min;
	int sec;
};

struct date {
	char day[20];
	struct time t1;
};

struct student {
	int rollNo;
	struct date d1;
};

int main(void) {

	struct student s1;

	s1.d1.t1.hr = 10;
	strcpy(s1.d1.day, "Thursday");
	s1.rollNo = 21;

	printf("Time = %d\n", s1.d1.t1.hr);
	printf("Date = %s\n", s1.d1.day);
	printf("Roll No = %d\n", s1.rollNo);

	return 0;
}