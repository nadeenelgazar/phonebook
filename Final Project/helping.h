#ifndef HELPING_H_INCLUDED
#define HELPING_H_INCLUDED

void SORT();
void SORTBYDATE();
void PRINTQUERY();
void MENU();
int VALIDATION (int choice,char valid [100]);
int VALIDATIONOFEMAIL(char Email[Max_length]);
int VALIDATIONOFDATE(int option,int value,int month);
void MULTISEARCH ();
int CHECKBLANK (phonebook *x);

#endif // HELPING_H_INCLUDED
