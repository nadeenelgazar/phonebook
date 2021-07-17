void LOAD()
{
    int i=0,j;
    printf("Enter the path of the file: ");
    gets(path);
    fp = fopen(path,"r");
    while(fp == NULL)
    {
        printf("File NOT FOUND!\n");
        printf("Enter the file path of the file: ");
        gets(path);
        fp = fopen(path,"r");
    }
    while (!feof(fp))
    {
        fscanf(fp,"%[^,],%[^,],%d-%d-%d,%s %[^,],%[^,],%s\n",&contact[lines].Last_Name,&contact[lines].First_Name,&contact[lines].dob.day,&contact[lines].dob.month,&contact[lines].dob.year,&contact[lines].Address_Number,&contact[lines].Address,&contact[lines].Email,&contact[lines].Phone_number);
        lines ++;
    }
    fclose(fp);
}

void PRINT()
{
    int z;
    char choose[2];
    printf("Choose the sorting method:\n1)Sort by last name then first name then phone number\n2)Sort by date of birth\n");
    do
    {
        printf("Enter a choice from 1-2\n");
        scanf("%s",choose);
    }while(!(choose[0]>'0' && choose[0]<'3' && strlen(choose)==1));
    switch(choose[0])
    {
    case '1' :
        SORT();
        break;
    case '2':
        SORTBYDATE();
        break;
    }
    printf("\n----------------------------------------------------------\n");
    for (z = 0 ; z < lines ; z++ )
        {
            printf("\nName: %s %s\nBirth Date dd/MM/yyyy: %d/%d/%d\nAddress: %s %s\nEmail: %s\nPhone Number: %s\n",contact[z].First_Name,contact[z].Last_Name,contact[z].dob.day,contact[z].dob.month,contact[z].dob.year,contact[z].Address_Number,contact[z].Address,contact[z].Email,contact[z].Phone_number);
            printf("\n----------------------------------------------------------\n");
        }

}

void QUERY ()
{
    printf("Search for the name\n");
    int i , j = 0;
    char search_last_name[Max_length];
    if (search_selection == 0)
    {

    printf("Enter the last name: ");
    scanf("%s",search_last_name);
    for(i=0;i<lines;i++)
        {
            if (strcasecmp(contact[i].Last_Name,search_last_name)==0)
            {
            search[sizesearch] = &contact[i];
            sizesearch++;
            }
        }
        if (sizesearch == 0)
            printf("NO CONTACT FOUND!\n");
    }
    else if (search_selection == 1)
    {
        char search_first_name[Max_length];
        printf("Enter the last name: ");
        scanf("%s",search_last_name);
        printf("Enter the first name: ");
        scanf("%s",search_first_name);
        for(i=0;i<lines;i++)
        {
            if (strcasecmp(contact[i].Last_Name , search_last_name) == 0 && strcasecmp(contact[i].First_Name , search_first_name) == 0)
            {
            search[sizesearch] = &contact[i];
            sizesearch++;
            }
        }
        if (sizesearch == 0)
            printf("NO CONTACT FOUND!\n");
        search_selection = 0;
    }
}

void ADD ()
{
    int j = 0,i=0 ,y ,flag;
    lines ++;
    printf("Adding new contact\n");
    do
    {
        printf("Enter the first name: ");
        scanf("%s",contact[lines - 1].First_Name);
        y=VALIDATION(1,contact[lines - 1].First_Name);

    }while(y==0);
    do
    {
        printf("Enter the last name: ");
        scanf("%s",contact[lines - 1].Last_Name);
        y=VALIDATION(1,contact[lines - 1].Last_Name);
    }while(y==0);
    do
    {
        printf("Enter the year of birth: ");
        scanf("%d",&contact[lines - 1].dob.year);
        y=VALIDATIONOFDATE(0,contact[lines - 1].dob.year);
    }while(y==0);
    do
    {
        printf("Enter the month of birth: ");
        scanf("%d",&contact[lines - 1].dob.month);
        y=VALIDATIONOFDATE(1,contact[lines - 1].dob.month);
    }while(y==0);
    do
    {
        printf("Enter the day of birth: ");
        scanf("%d",&contact[lines - 1].dob.day);
        y=VALIDATIONOFDATE(2,contact[lines - 1].dob.day,contact[lines - 1].dob.month);
    }while(y == 0);
    do
    {
        printf("Enter the address number: ");
        scanf("%s",contact[lines - 1].Address_Number);
        y=VALIDATION(0,contact[lines - 1].Address_Number);
    }while(y==0);
    printf("Enter the address: ");
    scanf("\n%[^\n]",contact[lines - 1].Address);
    do{
        printf("Enter the Email: ");
        scanf("%s",contact[lines - 1].Email);
        y=VALIDATIONOFEMAIL(contact[lines - 1].Email);
    }while(y==0);

    do
    {
        printf("Enter the phone number: ");
        scanf("%s",contact[lines - 1].Phone_number);
        y=VALIDATION(0,contact[lines - 1].Phone_number);
    }while(y==0);
    printf("The contact has been added\n");
}

void MODIFY()
{
    int j,i,index = 0,x,y;
    char option[2]  ;
    sizesearch = 0;
    printf("Modifying a contact\n");
    QUERY();
    if(sizesearch != 0)
    {
        PRINTQUERY();
        do
        {
        printf("enter the number of the contact you want to modify: ");
        scanf("%d",&x);
        }while(!(x > 0 && x<=sizesearch));
        index=x-1;
        printf("Choose what you want to modify:\n1)firstname\n2)lastname\n3)day of birth\n4)month of birth\n5)year of birth\n6)address no\n7)address\n8)Email\n9)phone number\n");
    do
    {
        printf("Enter a choice from 1-9\n");
        scanf("%s",option);
    }while(!(option[0]>'0' && option[0]<='9' && strlen(option)==1));
        switch(option[0])
        {
            case '1':
                do{
                printf("Modifying the first name\n");
                scanf("%s",search[index]->First_Name);
                y=VALIDATION(1,search[index]->First_Name);
                }while(y==0);
                break;

            case '2':
                do{
                printf("Modifying the last name\n");
                scanf("%s",search[index]->Last_Name);
                y=VALIDATION(1,search[index]->Last_Name);
                }while(y==0);
                break;

            case '3':
                do{
                printf("Modifying the day of birth\n");
                scanf("%d",&search[index]->dob.day);
                y=VALIDATIONOFDATE(2,search[index]->dob.day);
                }while(y==0);
                break;

            case '4':
                do{
                printf("Modifying the month of birth\n");
                scanf("%d",&search[index]->dob.month);
                y=VALIDATIONOFDATE(1,search[index]->dob.month);
                }while(y==0);
                break;

            case '5':
                do{
                printf("Modifying the year of birth\n");
                scanf("%d",&search[index]->dob.year);
                y=VALIDATIONOFDATE(0,search[index]->dob.year);
                }while(y==0);
                break;

            case '6':
                do{
                printf("Modifying the address number\n");
                scanf("%s",search[index]->Address_Number);
                y=VALIDATION(0,search[index]->Address_Number);
                }while(y==0);
                break;

            case '7':
                printf("Modifying the address\n");
                scanf("%s",search[index]->Address) ;
                break;

            case '8':
                do{
                printf("Modifying the email\n");
                scanf("%s",search[index]->Email);
                y=VALIDATIONOFEMAIL(search[index]->Email);
                }while(y==0);
                break;

            case '9':
                do{
                printf("Modifying the phone number\n");
                scanf("%s",&search[index]->Phone_number);
                y=VALIDATION(0,search[index]->Phone_number);
                }while(y==0);
                break;

        }
        printf("The contact has been modified\n");
    }
    else
       {
            printf("SEARCH FOR AN EXISTING CONTACT!\n");
            MODIFY();
       }

}

void DELETE ()
{
    search_selection = 1;
    sizesearch = 0;
    QUERY();
    if(sizesearch != 0)
    {
        PRINTQUERY();
        int  n , index = 0 , j;
        do
        {
        printf("enter the number of the contact you want to delete: ");
        scanf("%d",&n);
        }while(!(n > 0 && n<=sizesearch));
        index = search[n-1] - contact;
        for(j = index ; j<lines ; j++)
        {
            contact[j] = contact[j+1];

        }
        lines --;
    }
    else
    {
        printf("SEARCH FOR AN EXISTING CONTACT!\n");
        DELETE();
    }
    printf("Your contact has been deleted\n");
}

void SAVE ()
{
    int i;
     fp = fopen(path,"w");
    for (i = 0 ; i < lines ; i++)
    {
        fprintf(fp,"%s,%s,%d-%d-%d,%s %s,%s,%s\n",contact[i].Last_Name,contact[i].First_Name,contact[i].dob.day,contact[i].dob.month,contact[i].dob.year,contact[i].Address_Number,contact[i].Address,contact[i].Email,contact[i].Phone_number);
    }
    fclose(fp);
    printf("Your changes have been saved\n");
}

void QUIT ()
{
    exit(1);
}
