void SORT ()
{
    int i , j , z;
    phonebook temp;
    for(i = 0 ; i < lines - 1 ; i++)
    {
        for(j = 0 ; j < lines - i - 1 ; j++)
        {
            if(strcasecmp(contact[j].Last_Name , contact[j+1].Last_Name) > 0)
            {
                temp = contact [j];
                contact[j] = contact [j+1];
                contact[j+1] = temp;
            }
            else if(strcasecmp(contact[j].Last_Name , contact[j+1].Last_Name) == 0)
            {
                if(strcasecmp(contact[j].First_Name , contact[j+1].First_Name) > 0)
                {
                    temp = contact [j];
                    contact[j] = contact [j+1];
                    contact[j+1] = temp;
                }
                else if(strcasecmp(contact[j].First_Name , contact[j+1].First_Name) == 0)
                {
                    if(strcasecmp(contact[j].Phone_number , contact[j+1].Phone_number) > 0)
                    {
                        temp = contact [j];
                        contact[j] = contact [j+1];
                        contact[j+1] = temp;

                    }
                }
            }
        }
    }
}

void SORTBYDATE ()
{
    int i , j , z;
    phonebook temp;
    for(i = 0 ; i < lines - 1 ; i++)
    {
        for(j = 0 ; j < lines - i - 1 ; j++)
        {
            if(contact[j].dob.year > contact[j+1].dob.year)
            {
                temp = contact [j];
                contact[j] = contact [j+1];
                contact[j+1] = temp;
            }
            else if(contact[j].dob.year == contact[j+1].dob.year)
            {
                if(contact[j].dob.month > contact[j+1].dob.month)
                {
                    temp = contact [j];
                    contact[j] = contact [j+1];
                    contact[j+1] = temp;
                }
                else if(contact[j].dob.month == contact[j+1].dob.month)
                {
                    if(contact[j].dob.day == contact[j+1].dob.day)
                    {
                        temp = contact [j];
                        contact[j] = contact [j+1];
                        contact[j+1] = temp;

                    }
                }
            }
        }
    }
}

void PRINTQUERY ()
{
    int i;
    printf("\n----------------------------------------------------------\n");
    for(i=0;i<sizesearch;i++)
    {
        printf("\n%d)Name: %s %s\nBirth Date dd/MM/yyyy: %d/%d/%d\nAddress: %s %s\nEmail: %s\nPhone Number: %s\n",i+1,search[i]->First_Name,search[i]->Last_Name,search[i]->dob.day,search[i]->dob.month,search[i]->dob.year,search[i]->Address_Number,search[i]->Address,search[i]->Email,search[i]->Phone_number);
        printf("\n----------------------------------------------------------\n");
    }


}

void MENU ()
{
    int i;
    char option[2];
    printf("\n1-Show your contacts\n2-Search for a contact\n3-Add a contact\n4-Modify a contact\n5-Delete a contact\n6-Save\n7-Exit\n");
    do
    {
        printf("Enter a choice from 1-7\n");
        scanf("%s",option);
    }while(!(option[0]>'0' && option[0]<'8' && strlen(option)==1));
        switch(option[0])
        {
            case '1' : PRINT() ;
            break;
            case '2' : MULTISEARCH();
            PRINTQUERY();
            break;
            case '3' : ADD();
            break;
            case '4' : MODIFY();
            break;
            case '5' : DELETE();
            break;
            case '6' : SAVE();
            break;
            case '7' : QUIT();
            break;
        }
}

int VALIDATION (int choice,char valid [100])
{
  int i ;
   if (choice==0)
   {
    for (i=0;i<strlen(valid);i++)
    {
        if(isdigit(valid[i])==0)
        {
            printf("INVALID INPUT\n");
            return 0;
        }
    }
        return 1;
   }
    if (choice==1)
    {
        for(i=0;i<strlen(valid);i++)
        {
            if(isalpha(valid[i])==0)
            {
                printf("INVALID INPUT\n");
                return 0;
            }


        }
return 1;
    }
}

int VALIDATIONOFEMAIL(char Email[Max_length])
{
    int i=0,j=0,index=0,indexdot=0,counter = 0;
    int flag =1 ;
    j = 0;
    for(i=0;i<strlen(Email);i++)
    {
        if(Email[i] == '@')
        {
        j++;
        index=i;
        }
    }
    if(j != 1 && Email[0] != '@')
    {
        printf("INVALID EMAIL\n");
        printf("Re");
        return 0;
        flag = 1;
    }
    else
    {
        for(i = index+1 ; i<=strlen(Email) ; i++)
        {
            if(Email[i] == '.')
            {
                indexdot = i;
            }
        }
        counter = 0;
        for(i=index+1;i<indexdot;i++)
        {
            if(!(isalpha(Email[i])==0))
            {
                counter++;
            }
        }
        if(counter>=2)
        {
            flag = 0;
            return 1;
        }
        else
        {
            printf("INVALID EMAIL\n");
            return 0;
            printf("Re");
        }
    }
    printf("valid\n");
    return 1;
}

int VALIDATIONOFDATE(int option,int value,int month)
 {
     if(option == 0)
     {
        if(!(value >= 1900 && value <= 2019))
        {
            printf("YOU ENTERED INVALID YEAR!\n");
            printf("Re");
            return 0;
        }
        else
            return 1;
     }
    if (option == 1)
     {
        if(!(value >= 1 && value <= 12))
        {
            printf("YOU ENTERED INVALID MONTH!\n");
            printf("Re");
            return 0;
        }
        else
            return 1;
     }
     if(option == 2)
     {
          if(month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12)
        {
            if(!(value >= 1 && value <= 31))
            {
                printf("YOU ENTERED INVALID DAY!\n");
                printf("Re");
                return 0;
            }
            else
                return 1;
        }
        else if(month == 4 || month == 6 || month == 9 || month == 11)
        {
            if(!(value >= 1 && value <= 30))
            {
                printf("YOU ENTERED INVALID DAY!\n");
                printf("Re");
                return 0;
            }
            else
                return 1;
        }
        else if(month == 2)
        {
            if(!(value >= 1 && value <= 28))
            {
                printf("YOU ENTERED INVALID DAY!\n");
                printf("Re");
                return 0;
            }
            else
                return 1;
     }

     }
}

void MULTISEARCH ()
{
    int i,valid=0;
    sizesearch = 0;
    phonebook *x = &contact[0];
    fflush(stdin);
    printf("Enter the first name: ");
    gets(advance.First_Name);
    printf("Enter the last name: ");
    gets(advance.Last_Name);
    printf("Enter the address number: ");
    gets(advance.Address_Number);
    printf("Enter the address: ");
    gets(advance.Address);
    printf("Enter the email: ");
    gets(advance.Email);
    printf("Enter the phone number: ");
    gets(advance.Phone_number);
    for(i=0;i<lines;i++)
    {
        valid = CHECKBLANK(x);
        if(valid==1)
        {
            search[sizesearch] = &contact[i];
            sizesearch++;
        }
        x=x+1;
    }
    if(sizesearch == 0)
        printf("NO CONTACT FOUND!\n");
}

int CHECKBLANK (phonebook *x)
{
    if(strcasecmp(advance.First_Name,"")!=0)
    {
        if(strcasecmp(advance.First_Name,x->First_Name) != 0)
            return 0;
    }
    if(strcasecmp(advance.Last_Name,"")!=0)
    {
        if(strcasecmp(advance.Last_Name,x->Last_Name) != 0)
            return 0;
    }
    if(strcasecmp(advance.Address_Number,"")!=0)
    {
        if(strcasecmp(advance.Address_Number,x->Address_Number) != 0)
            return 0;
    }
    if(strcasecmp(advance.Address,"")!=0)
    {
        if(strcasecmp(advance.Address,x->Address) != 0)
            return 0;
    }
    if(strcasecmp(advance.Email,"")!=0)
    {
        if(strcasecmp(advance.Email,x->Email) != 0)
            return 0;
    }
    if(strcasecmp(advance.Phone_number,"")!=0)
    {
        if(strcasecmp(advance.Phone_number,x->Phone_number) != 0)
            return 0;
    }
    return 1;

}
