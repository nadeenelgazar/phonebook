#ifndef STRUCTS_H_INCLUDED
#define STRUCTS_H_INCLUDED
#define Max_length  100

typedef struct {
int day;
int month;
int year;
}DOB;

typedef struct {
char Last_Name [Max_length];
char First_Name [Max_length];
DOB dob;
char Address_Number[Max_length];
char Address [Max_length];
char Email [Max_length];
char Phone_number [Max_length];
} phonebook;

#endif // STRUCTS_H_INCLUDED
