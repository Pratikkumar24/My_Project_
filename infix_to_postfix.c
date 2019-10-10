#include<stdio.h>
#include<stdlib.h>
struct node
{
    char data;
    struct node* next;
}*top=NULL;
//************************************************************
void push(char c)
{
    struct node* temp;
    temp=(struct node*)malloc(sizeof(struct node));
    temp->data=c;

        temp->next=top;
        top=temp;
}
int pop()
{
    if(top == NULL)
        return 0;
    else
    {
        struct node* temp;
        temp=top;
        if(temp->data!=')'&& temp->data!='(')
            printf("%c",temp->data);
        top=top->next;
        free(temp);
    }
    
}
//****************END OF STACK OPERATION**********************



//**********************Precedency checking*************************
int precedence(char c)
{

    switch(c)
    {
        case '!': return 5;
        case '^': return 4;
        case '#': return -10;
        case '/':
        case '*':return 3;
        case '%':return 2;
        case '+':
        case '-':return 1;
        case '<':
        case '>':return 0;
        case '&':
        case '|':return -1; 
        case '(':return -9;
    }
    return -1;
}
//***************************************isalpha function***********
int isal(char c)
{

    if(c>=65&&c<=90 || c>=97&&c<=122)
        return 1;
    else return 0;
}
//****************************TO display values*********************
void display()
{
    struct node* t;
    t=top;
    while(t!=NULL)
    {
        if(t->data!='#')
        printf(" %c",t->data);
        t=t->next;
    }
}



//*************************************MAIN FUNCTION******************
int main()
{
    char ch[30];
    scanf("%s",ch);
    int i;
    push('#');


    for( i=0; ch[i]!='\0'; i++)
    {

        if(isal(ch[i])!=0)                     //if its a character then print
          {
            printf("%c",ch[i]);
          }


        else if(ch[i]=='(')                    //if its '(' then push inside
            {((H*((((A+((B+C)*D))*F)*G)*E))+J)

                push(ch[i]);
            }



        else if(ch[i]==')')                 //if its ')' then pop until we reach '(' and keep on printing the value
        {

            while(top->data!='(' && top->data!='#')
                {
                    pop();
                }
                pop(); //extra pop is for poping the last bracket
        }


       else                                                           //if its operator
        {


            if(precedence(top->data) < precedence(ch[i]))     //checks the precedency if high then pushes inside
                {

                    push( ch[i] );

                }
            else
            {
                if(precedence(ch[i]) == precedence(top->data)) //if the precedency is equal then pop once
                    pop();
                else
                {
                    while(top->data!='(' && top->data!='#')
                     pop();
                    
                }
                 push(ch[i]); //after poping just push the element into the stack
            }
            
        }

        
        
    }
    //poo the rest of the element from the stack

    while(top->data!='#')
    {
        pop();
    }


    return 0;
}