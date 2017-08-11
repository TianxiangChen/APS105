/* 
 * APS105 Lab8--Linked Lists
 * A book system implemented using linked list.
 * It has functions:
 * Insert a book
 * Delete a book
 * Search a book
 * Display all book
 * Search all books whose rating is higher or equal than an input value
 * 
 * Author: TianxiangChen
 *
 * Created on August 7, 2017, 8:14 PM
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <malloc.h>
#include <string.h>
#include <ctype.h>

//Program-wide constant
#define MAX_LENGTH 1024

typedef struct book{
    char name[MAX_LENGTH], author[MAX_LENGTH];
    int rating;
    char category;
    struct book* next;
}BOOK;


void MenuDisplay();
void safegets (char s[], int arraySize);//A helper function to read string input
BOOK* Insert(BOOK* head);//Insert a data into the inventory
BOOK* NewNode();//Create a new node as the head
BOOK* InsetHelper(BOOK* head, BOOK *data);//actual function for inserting
bool CheckDuplicate(BOOK *head, BOOK *data);
BOOK* DeleteBook(BOOK *head);
void SearchBook(BOOK *head);
void SearchRating(BOOK *head);
void PrintInventory(BOOK *head);//Display all book info in the inventory
void quit_function(BOOK *head);//Delete all data(free memory space) and end the program





int main(int argc, char** argv) {
    bool run=true;
    char command;
    struct BOOK* head=NULL;
    MenuDisplay();
    
    while(run){
        printf("Command?: \n");
        scanf(" %c",&command);
        getchar();//take the new line char
        command = toupper(command);
        
        switch(command){
            case('I'):
                head=Insert(head);
                break;
            case('D'):
                head=DeleteBook(head);
                break;
            case('S'):
                SearchBook(head);
                break;
            case('V'):
                SearchRating(head);
                break;
            case('P'):
                PrintInventory(head);
                break;
            case('Q'):
                quit_function(head);
                run=false;
                break;
            default:
                printf("Invalid input.\n");
                MenuDisplay();
                break;
        }
    }

    return (EXIT_SUCCESS);
}


//**********************************************************************
// Support Function Definitions

// Function to get a line of input without overflowing target char array.
void safegets (char s[], int arraySize)
{
    int i = 0, maxIndex = arraySize - 1;
    char c;
    while (i < maxIndex && (c = getchar()) != '\n')
    {
        s[i] = c;
        i = i + 1;
    }
    s[i] = '\0';
}

void MenuDisplay(){
    printf("Online Bookstore Inventory Management Program.\n");
    printf("Commands are I (insert), D (delete), S (search by name), V "
                "(search by rating),P (print), Q (quit)\n");
}

BOOK* Insert(BOOK* head){
        if(head==NULL)
            return NewNode();
        else{
            BOOK *book=NewNode();
            if(book==NULL)
                return book;
            BOOK *current=head;
            bool IsRepeated=false;
            IsRepeated=CheckDuplicate(head, book);
            if(IsRepeated){
                printf("The book %s is already in the inventory.\n",head->name);
                free(book);
            }
            else{//insert the book
                head=InsetHelper(head,book);
            }
        }
        
}

BOOK* NewNode(){
    BOOK* head=(BOOK*)malloc(sizeof(BOOK));
    if(head==NULL)
        printf("Error. Memory Full.\n");
    else{
        printf("Book: ");
        //getchar();
        safegets(head->name,MAX_LENGTH);
        printf("Author: ");
        //getchar();
        safegets(head->author,MAX_LENGTH);
        printf("Rating: ");
        //getchar();
        scanf(" %d",&head->rating);
        printf("Category: ");
        getchar(); 
        scanf("%c",&head->category);
        if((head->category!='F')&&(head->category!='H')&&(head->category!='P')&&
                (head->category!='A')){
            printf("Wrong Category. Cannot insert the book.\n");
            free(head);
            head=NULL;
        }
        head->next=NULL;
        }
    return head;
}

BOOK* InsetHelper(BOOK* head, BOOK *data){
    // Insert a book entry into the linked list.
    // Maintain the list in correct order (F, H, P, A).
    BOOK *current=head;
    bool FoundPosition=false;
    if(data->category=='F'){//case 1
        if(head->category!='F'){//if head is book other than F, then F should be
            //put at the head
            data->next=head;
           return data;
        }
        else{
            while((current->next!=NULL)&&(!FoundPosition)){
                if(current->next->category=='F')   
                    current=current->next;  
                else
                    FoundPosition=true;
            }
            data->next=current->next;
            current->next=data;
            return head;
        }
    }
    else if(data->category=='H'){//case 2
        if((head->category=='P')||(head->category=='A')){
            data->next=head;
            return data;
        }
        else{
            while((current->next!=NULL)&&(!FoundPosition)){
                if(current->next!=NULL){
                    if((current->next->category!='P')&&(current->next->category!='A'))
                            current=current->next;
                    else
                        FoundPosition=true;
                }
                else
                    FoundPosition=true;

            }
            data->next=current->next;
            current->next=data;
            return head;
        }
    }
    else if(data->category=='P'){//case 3
        if(head->category=='A'){
            data->next=head;
            return data;
        }
        else{
            if(head->next==NULL){
                head->next=data;
                return head;
            }
            while((current->next!=NULL)&&(!FoundPosition)){
                if(current->next!=NULL){
                    if(current->next->category!='A')
                        current=current->next;
                    else
                        FoundPosition=true;
                }
                else
                    FoundPosition=true;   
            }
            data->next=current->next;
            current->next=data;
            return head;
        }
    }
    else{//case 4 data->category=='A'
        while(current->next!=NULL)
                current=current->next;
            current->next=data;
            return head;
        }
            
}

bool CheckDuplicate(BOOK* head, BOOK *data){
    BOOK *current=head;
    bool IsFind=false;
    
    while((current!=NULL)&&(!IsFind)){
        if(strcmp(current->name,data->name)==0)
            IsFind=true;
        current=current->next;
    }
    return IsFind;
}

BOOK* DeleteBook(BOOK *head){
    char book[MAX_LENGTH];
    printf("Please enter the book name you want to delete: ");
    safegets(book,MAX_LENGTH);
    BOOK* current=head;
    bool IsFind=false;
    if(head==NULL){
        printf("Empty list.\n");
        return head;
    }
    else{
        if(strcmp(head->name,book)==0){//if the one is at the head
            BOOK *temp=head->next;
            free(head);
            return temp;
        }
        
        while((current->next!=NULL)&&(!IsFind)){
            if(strcmp(current->next->name,book)==0){
                IsFind=true;
                BOOK *temp=current->next;
                if(current->next->next!=NULL)
                    current->next=current->next->next;
                else
                    current->next=NULL;
                free(temp);
            }
            if(!IsFind)
                current=current->next;
        }
        if(IsFind)
            printf("%s is deleted.\n",book);
        else
            printf("%s is not found.\n",book);
        return head;
    }
//    if(IsFind)
//        printf("The book %s has been deleted.\n", book);
//    else
//        printf("The book %s is not in the inventory.\n", book);
}
void SearchBook(BOOK *head){
    char input_book[MAX_LENGTH];
    printf("Please enter the book name you want to search: ");
    //getchar();
    safegets(input_book,MAX_LENGTH);
    
    BOOK *current=head;
    bool IsFind=false;
    while((current!=NULL)&&(!IsFind)){
        if(strcmp(current->name,input_book)==0)
            IsFind=true;
        current=current->next;
    }
    if(IsFind)
        printf("The book %s is in the inventory.\n", input_book);
    else
        printf("The book %s is not in the inventory.\n", input_book);
}

void SearchRating(BOOK *head){
    int rating;
    printf("Please enter an integer between 1 and 10. \n");
    printf("The system will show the books have a rating higher or equal to"
            " that number: ");
    scanf("%d", &rating);
    
    BOOK *current=head;
    bool IsFind=false;
    while(current!=NULL){
        if(current->rating >= rating){
            printf("Name: %s Author: %s Category: %c Rating: %d\n",
                    current->name,current->author,current->category,current->rating);
            IsFind=true;
        }
        current=current->next;
    }
    if(!IsFind)
        printf("There is no book rates higher or equal than %d in the system.\n"
                , rating);
}

void PrintInventory(BOOK *head){
    if(head==NULL)
        printf("No book in the inventory.\n");
    else{
        BOOK *current=head;
        while(current!=NULL){
            printf("Name: %s Author: %s Category: %c Rating: %d\n",
                    current->name,current->author,current->category,current->rating);
            current=current->next;
        } 
    }
        
}

void quit_function(BOOK *head){
    while(head!=NULL){
        BOOK *temp=head;
        head=head->next;
        free(temp);
    }
    printf("The inventory is empty now.\n");
    printf("Program ends.\n");
}