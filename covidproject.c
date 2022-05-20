#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include <stdlib.h>
#define MAX 30
struct Patient_Details
{
    int Patient_ID;
    char Name[MAX];
    char Dept[MAX];
    int Date_Of_Admission[MAX];
    int Date_Of_Release[MAX];
    char Investigating_Doctor_name[MAX];
    char Disease[MAX];
    char Gaurdian_name[MAX];
    char Emergency_contact_no[MAX];
    int Fee_due;
    int Age;
    char blood[MAX];
    char PhNo[MAX];
    char available;
    struct Patient_Details *prev;
    struct Patient_Details *next;
};
typedef struct Patient_Details *NODE;
#define MALLOC(p, s, t)                  \
    p = (t)malloc(s);                    \
    if (p == NULL)                       \
    {                                    \
        printf("Insufficient Memory\n"); \
        exit;                            \
    }

int patient_ID = 0;
int age;
char blood[MAX];
char name[MAX];
char Dept[MAX];
int DOA[MAX];
int DOR[MAX];
char investigating_Doctor_name[MAX];
char disease[MAX];
char gaurdian_name[MAX];
char emergency_contact_no[MAX];
int fee_due;
char phNo[MAX];

void display_individual(NODE t)
{
    int i;
    printf("Patient_ID = %d\n", t->Patient_ID);
    printf("Name = %s\n", t->Name);
    printf("Age = %d\n", t->Age);
    printf("Department = %s\n", t->Dept);
    for (i = 0; i < 3; i++)
        printf("Date Of Admission = %d\n", t->Date_Of_Admission[i]);
    for (i = 0; i < 3; i++)
        printf("Date Of Release = %d\n", t->Date_Of_Release[i]);
    printf("Investigating Doctor Name = %s\n", t->Investigating_Doctor_name);
    printf("Disease Name = %s\n", t->Disease);
    printf("Blood Group = %s\n", t->blood);
    printf("Gaurdian Name = %s\n", t->Gaurdian_name);
    printf("Emergency Contact Number = %s\n", t->Emergency_contact_no);
    printf("Phone Number = %s\n", t->PhNo);
    printf("Patient Available in Hospital or Not = %c\n", t->available);
    printf("Amount to be Paid = %d\n", t->Fee_due);
}

void search(NODE first)
{
    int choice;
    NODE temp;
    int c = 0;
    printf("Enter your preference to Search a  Patient in the Hospital\n");
    printf("1.Name\t2.Department\t3.Date of Admission\t4.Date of Release\n");
    printf("Enter your choice\n");
    scanf("%d", &choice);
    switch (choice)
    {
    case 1:
        if (first == NULL)
            printf("No patients admitted!\n");
        else
        {
            temp = first->next;
            printf("Enter Name\n");
            scanf("%s", name);
            while (temp != first)
            {
                if (strcmp(name, temp->Name) == 0)
                {
                    c = c + 1;
                    display_individual(temp);
                }
                temp = temp->next;
            }
            if (strcmp(name, temp->Name) == 0)
            {
                c = c + 1;
                display_individual(temp);
            }
        }
        if (c == 0)
            printf("No patients admitted with that name!\n");
        break;
    case 2:
        if (first == NULL)
            printf("No patients admitted!\n");
        else
        {
            temp = first->next;
            printf("Enter Department\n");
            scanf("%s", Dept);
            while (temp != first)
            {
                if (strcmp(Dept, temp->Dept) == 0)
                {
                    c = c + 1;
                    display_individual(temp);
                }
                temp = temp->next;
            }
            if (strcmp(Dept, temp->Dept) == 0)
            {
                c = c + 1;
                display_individual(temp);
            }
        }
        if (c == 0)
            printf("No patients admitted in that Department!\n");
        break;
    case 3:
        if (first == NULL)
            printf("No patients admitted!\n");
        else
        {
            temp = first->next;
            printf("enter patient date of admission\n");
            scanf("%d", &DOA[0]);
            printf("enter patient month of admission\n");
            scanf("%d", &DOA[1]);
            printf("enter patient year of admission\n");
            scanf("%d", &DOA[2]);
            while (temp != first)
            {
                if (DOA[0] == temp->Date_Of_Admission[0] && DOA[1] == temp->Date_Of_Admission[1] && DOA[2] == temp->Date_Of_Admission[2])
                {
                    c = c + 1;
                    display_individual(temp);
                }
                temp = temp->next;
            }
            if (DOA[0] == temp->Date_Of_Admission[0] && DOA[1] == temp->Date_Of_Admission[1] && DOA[2] == temp->Date_Of_Admission[2])
            {
                c = c + 1;
                display_individual(temp);
            }
        }
        if (c == 0)
            printf("No patients admitted on that date!\n");
        break;
    case 4:
        if (first == NULL)
            printf("No patients admitted!\n");
        else
        {
            temp = first->next;
            printf("enter patient date of release\n");
            scanf("%d", &DOR[0]);
            printf("enter patient month of release\n");
            scanf("%d", &DOR[1]);
            printf("enter patient year of release\n");
            scanf("%d", &DOR[2]);
            while (temp != first)
            {
                if (DOR[0] == temp->Date_Of_Release[0] && DOR[1] == temp->Date_Of_Release[1] && DOR[2] == temp->Date_Of_Release[2])
                {
                    c = c + 1;
                    display_individual(temp);
                }
                temp = temp->next;
            }
            if (DOR[0] == temp->Date_Of_Release[0] && DOR[1] == temp->Date_Of_Release[1] && DOR[2] == temp->Date_Of_Release[2])
            {
                c = c + 1;
                display_individual(temp);
            }
        }
        if (c == 0)
            printf("No patients released on that date!\n");
        break;
    default:
        printf("Invalid Choice\n");
        break;
    }
}

void Display(NODE first)
{
    NODE temp;
    if (first == NULL)
    {
        printf("No Patients Admitted!");
    }
    else
    {
        temp = first;
        while (temp->next != first)
        {
            if (temp->available == 'Y')
                display_individual(temp);
            temp = temp->next;
        }
        if (temp->available == 'Y')
            display_individual(temp);
    }
}

int days_admitted()
{
    int i, diff = 0, flag = 0;
    if (DOA[2] % 100)
    {
        if (DOA[2] % 4 == 0)
            flag = 1;
    }
    else
    {
        if (DOA[2] % 400 == 0)
            flag = 1;
    }
    if (DOA[1] == DOR[1])
    {
        return (DOR[0] - DOA[0]);
    }
    else
    {
        if (DOA[1] == 1 || DOA[1] == 3 || DOA[1] == 5 || DOA[1] == 7 || DOA[1] == 8 || DOA[1] == 10 || DOA[1] == 12)
            diff += 31 - DOA[0];
        else if (DOA[1] == 2 && flag == 1)
            diff += 29 - DOA[0];
        else if (DOA[1] == 2 && flag == 0)
            diff += 28 - DOA[0];
        else
            diff += 30 - DOA[0];
        for (i = DOA[1] + 1; i < DOR[1]; i++)
        {
            if (i == 3 || i == 5 || i == 7 || i == 8 || i == 10 || i == 12)
                diff += 31;
            else if (i == 2 && flag == 1)
                diff += 29;
            else if (i == 2 && flag == 0)
                diff += 28;
            else
                diff += 30;
        }
        diff += DOR[0];
    }
    return (diff + 1);
}

void bill(NODE first, int days)
{
    int medicine_charge, bed_charge, total_charge, tax, pid, flag;
    float age_discount;
    float charge, fcharge;
    int consul_charge = 100;

    NODE x = first;
    printf("Search by Patient ID :\n");
    scanf("%d", pid);
    if (x == NULL)
    {
        printf("No patient entry\n");
    }
    else if (x->next == NULL)
    {
        if (x->Patient_ID == pid)
            display_individual(x);
        else
            printf("Patient with given patient ID does not exist ! \n");
    }

    do
    {
        if (x->Patient_ID == pid)
            flag = 1;
        x = x->next;
    } while ((x != first) && (flag == 0));

    if ((flag == 0) && (x == first))
    {
        printf("Patient with given patient ID does not exist ! \n");
    }
    else if (strcmp(x->Dept, "AND") == 0)
    {
        charge = 2000;
        medicine_charge = 1000;
    }
    else if (strcmp(x->Dept, "AYU") == 0)
    {
        charge = 500;
        medicine_charge = 300;
    }
    else if (strcmp(x->Dept, "CAR") == 0)
    {
        charge = 40000;
        medicine_charge = 5000;
    }
    else if (strcmp(x->Dept, "DEN") == 0)
    {
        charge = 1200;
        medicine_charge = 300;
    }
    else if (strcmp(x->Dept, "DIA") == 0)
    {
        charge = 1300;
        medicine_charge = 500;
    }
    else if (strcmp(x->Dept, "NEP") == 0)
    {
        charge = 15000;
        medicine_charge = 4000;
    }
    else if (strcmp(x->Dept, "NEU") == 0)
    {
        charge = 60000;
        medicine_charge = 9000;
    }
    else if (strcmp(x->Dept, "ONC") == 0)
    {
        charge = 0;
        medicine_charge = 200;
    }

    bed_charge = 150 * days;
    total_charge = charge + medicine_charge + bed_charge;

    if (x->Age > 60 || x->Age < 18)
    {
        age_discount = ((total_charge * 10) / 100);
        total_charge = total_charge - age_discount;
    }
    tax = total_charge + ((total_charge * 3) / 100);
    fcharge = total_charge + tax;
    printf("Name = %s\ncharge = %.2f\nmedicine charge=%d\nbed charge=%d\t\t\tage discount=%.2f\ntax=%.2f\nfcharge=%.2f\n",
           x->Name, charge, medicine_charge, bed_charge, age_discount, tax, fcharge);
    x->available = 'N';
    x->Fee_due = fcharge;
}
void update(int key, NODE first)
{
    NODE cur;
    int choice, i;
    if (first == NULL)
    {
        printf("List is empty\n");
    }
    else
    {
        cur = first;
        while (cur->next != first)
        {
            if (key == cur->Patient_ID)
            {
                printf("1.Name\t2.Age\t3.department\t4.date of admission\t5.date of release\t6.investigating doctor\t7.disease\t8.guardian name\t9.emergency contact no\t10.phone no\n");
                printf("enter the entry which you want to update\n");
                scanf("%d", &choice);
                switch (choice)
                {
                case 1:
                    printf("Enter the new Name\n");
                    scanf("%s", name);
                    strcpy(cur->Name, name);
                    break;
                case 2:
                    printf("enter the new Age\n");
                    scanf("%d", age);
                    cur->Age = age;
                    break;
                case 3:
                    printf("enter the new department\n");
                    printf("enter Deparment code :\n1.AND - ANDROLOGY \n2.AYU - AYURVEDIC  \n3.CAR - CARDIOLOGY \n4.DEN  - DENTAL \n5.DIA - DIABETES \n6.NEP - NEPHROLOGY\n7.NEU - NEUROLOGY \n8.ONC - ONCOLOGY\n");
                    scanf("%s", Dept);
                    strcpy(first->Dept, Dept);
                    break;
                case 4:
                    printf("enter patient date of admission\n");
                    scanf("%d", &DOA[0]);
                    printf("enter patient month of admission\n");
                    scanf("%d", &DOA[1]);
                    printf("enter patient year of admission\n");
                    scanf("%d", &DOA[2]);
                    for (i = 0; i < 3; i++)
                        cur->Date_Of_Admission[i] = DOA[i];
                    break;

                case 5:
                    printf("enter patient date of release\n");
                    scanf("%d", &DOR[0]);
                    printf("enter patient month of release\n");
                    scanf("%d", &DOR[1]);
                    printf("enter patient year of release\n");
                    scanf("%d", &DOR[2]);
                    for (i = 0; i < 3; i++)
                        cur->Date_Of_Release[i] = DOR[i];
                    break;

                case 6:
                    printf("enter the new Investigating doctor\n");
                    scanf("%s", investigating_Doctor_name);
                    strcpy(cur->Investigating_Doctor_name, investigating_Doctor_name);
                    break;
                case 7:
                    printf("enter the new disease name\n");
                    scanf("%s", disease);
                    strcpy(cur->Disease, disease);
                    break;
                case 8:
                    printf("enter the new guardian name\n");
                    scanf("%s", gaurdian_name);
                    strcpy(cur->Gaurdian_name, gaurdian_name);
                    break;
                case 9:
                    printf("enter the new emergency contact no\n");
                    scanf("%s", emergency_contact_no);
                    strcpy(cur->Emergency_contact_no, emergency_contact_no);
                    break;
                case 10:
                    printf("enter the new Phone no\n");
                    scanf("%s", phNo);
                    strcpy(cur->PhNo, phNo);
                    break;
                default:
                    printf("INVALID CHOICE\n");
                }
                break;
            }
            cur = cur->next;
        }
        if (key == cur->Patient_ID)
        {
            printf("1.Name\t2.Age\t3.department\t4.date of admission\t5.date of release\t6.investigating doctor\t7.disease\t8.guardian name\t9.emergency contact no\t10.phone no\n");
            printf("enter the entry which you want to update\n");
            scanf("%d", &choice);
            switch (choice)
            {
            case 1:
                printf("Enter the new Name\n");
                scanf("%s", name);
                strcpy(cur->Name, name);
                break;
            case 2:
                printf("enter the new Age\n");
                scanf("%d", age);
                cur->Age = age;
                break;
            case 3:
                printf("enter the new department\n");
                printf("enter Deparment code :\n1.AND - ANDROLOGY \n2. AYU - AYURVEDIC  \n3.CAR - CARDIOLOGY \n4.DEN  - DENTAL \n5.DIA - DIABETES \n6.NEP - NEPHROLOGY\n7.NEU - NEUROLOGY \n8.ONC - ONCOLOGY\n");
                scanf("%s", Dept);
                strcpy(cur->Dept, Dept);
                break;
            case 4:
                printf("enter patient date of admission\n");
                scanf("%d", &DOA[0]);
                printf("enter patient month of admission\n");
                scanf("%d", &DOA[1]);
                printf("enter patient year of admission\n");
                scanf("%d", &DOA[2]);
                for (i = 0; i < 3; i++)
                    cur->Date_Of_Admission[i] = DOA[i];
                break;

            case 5:
                printf("enter patient date of release\n");
                scanf("%d", &DOR[0]);
                printf("enter patient month of release\n");
                scanf("%d", &DOR[1]);
                printf("enter patient year of release\n");
                scanf("%d", &DOR[2]);
                for (i = 0; i < 3; i++)
                    cur->Date_Of_Release[i] = DOR[i];
                break;

            case 6:
                printf("enter the new Investigating doctor\n");
                scanf("%s", investigating_Doctor_name);
                strcpy(cur->Investigating_Doctor_name, investigating_Doctor_name);
                break;
            case 7:
                printf("enter the new disease name\n");
                scanf("%s", disease);
                strcpy(cur->Disease, disease);
                break;
            case 8:
                printf("enter the new guardian name\n");
                scanf("%s", gaurdian_name);
                strcpy(cur->Gaurdian_name, gaurdian_name);
                break;
            case 9:
                printf("enter the new emergency contact no\n");
                scanf("%s", emergency_contact_no);
                strcpy(cur->Emergency_contact_no, emergency_contact_no);
                break;
            case 10:
                printf("enter the new Phone no\n");
                scanf("%s", phNo);
                strcpy(cur->PhNo, phNo);
                break;
            default:
                printf("INVALID CHOICE\n");
            }
        }
    }
}

void ReadData()
{
    printf("enter patient name\n");
    scanf("%s", name);
    printf("enter patient age\n");
    scanf("%d", &age);
    printf("enter patient blood group\n");
    scanf("%s", blood);
    printf("enter patient date of admission\n");
    scanf("%d", &DOA[0]);
    printf("enter patient month of admission\n");
    scanf("%d", &DOA[1]);
    printf("enter patient year of admission\n");
    scanf("%d", &DOA[2]);
    printf("enter patient date of Release\n");
    scanf("%d", &DOR[0]);
    printf("enter patient month of Release\n");
    scanf("%d", &DOR[1]);
    printf("enter patient year of Release\n");
    scanf("%d", &DOR[2]);
    printf("enter Deparment code :\n1.AND - ANDROLOGY \n2. AYU - AYURVEDIC  \n3.CAR - CARDIOLOGY \n4.DEN  - DENTAL \n5.DIA - DIABETES \n6.NEP - NEPHROLOGY\n7.NEU - NEUROLOGY \n8.ONC - ONCOLOGY\n");
    scanf("%s", Dept);
    printf("enter disease name\n");
    scanf("%s", disease);
    printf("Guardian Name\n");
    scanf("%s", gaurdian_name);
    printf("enter patient phone number\n");
    scanf("%s", phNo);
    printf("enter patient emergency contact number\n");
    scanf("%s", emergency_contact_no);
    printf("enter investigating  doctor name\n");
    scanf("%s", investigating_Doctor_name);
}

NODE insert(NODE first)
{
    NODE q, last;
    int i;
    MALLOC(q, sizeof(struct Patient_Details), NODE);
    patient_ID = patient_ID + 1;
    q->Patient_ID = patient_ID;
    q->Age = age;
    strcpy(q->Dept, Dept);
    strcpy(q->Name, name);
    for (i = 0; i < 3; i++)
        q->Date_Of_Admission[i] = DOA[i];
    for (i = 0; i < 3; i++)
        q->Date_Of_Release[i] = DOR[i];
    strcpy(q->blood, blood);
    strcpy(q->Disease, disease);
    strcpy(q->PhNo, phNo);
    strcpy(q->Gaurdian_name, gaurdian_name);
    strcpy(q->Emergency_contact_no, emergency_contact_no);
    strcpy(q->Investigating_Doctor_name, investigating_Doctor_name);
    q->available = 'Y';
    if (first == NULL)
    {
        q->next = q;
        q->prev = q;
        return q;
    }
    else
    {
        last = first->prev;
        last->next = q;
        q->prev = last;
        first->prev = q;
        q->next = first;
        return first;
    }
}

void main()
{
    NODE first = NULL;
    int done = 0, done1 = 0, p_id, days, choice;
    while (!done)
    {

        printf("\n __HOSPITAL_NAME__ \nSelect an option :\n1.EMERGENCY \t2.COVID WARD \t3.Exit\n");
        scanf("%d", &choice);
        switch (choice)
        {

        case 1:
            printf("EMERGENCY WARD - BASE charge = 10,000/- \n Other formalties and procedures will be carried out later\n");
            break;
        case 2:
            while (!done1)
            {
                printf("\nIn COVID WARD : \nEnter your choice:\n1.New entry\t2.Edit/Update\t3.Search\t4.Display\t5.Generate Bill\t6.Exit\n");
                scanf("%d", &choice);
                switch (choice)
                {
                case 1:
                    printf("__NEW_PATIENT_\n");
                    ReadData();
                    first = insert(first);
                    break;
                case 2:
                    printf("UPDATING PATIENT INFO: \n");
                    printf("Kindly enter patient ID : \n");
                    scanf("%d", &p_id);
                    update(p_id, first);
                    break;
                case 3:
                    printf("SEARCHING PATIENT : \n");
                    search(first);
                    break;
                case 4:
                    printf("DISPLAY : \n");
                    Display(first);
                    break;
                case 5:
                    printf("GENERAING BILL and deleting patient entry : \n");
                    printf("Enter Patient Unique ID\n");
                    scanf("%d", &patient_ID);
                    days = days_admitted();
                    bill(first, days);
                    break;
                case 6:
                    done1 = 1;
                    break;
                default:
                    printf("Invalid choice\n");
                }
            }
            break;
        case 3:
            done = 1;
            break;
        default:
            printf("Invalid Choice\n");
        }
    }
}