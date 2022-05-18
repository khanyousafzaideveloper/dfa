#include <stdio.h>

int state =1;
char c;
char buffer[]="ababb$"; 
int fwd = 0;

char nextChar()
    {   
        
        char ch= buffer[fwd];
        fwd ++;
        return ch;
    }
char dfa()
{
    
    while(1)
    {
        switch (state)
        {
        case 1:
        c= nextChar();
        if(c=='a')
        {state = 2;
        break;}
        else if (c=='b')
        {state =1;
        break;}
        else if(c=="$")
        {return 'n';}
        
        case 2:
        c= nextChar();
        if (c=='a')
        {state =2;
        break;}
        else if(c=='b')
        {state =3;
        break;}
        else if(c=='$')
        {return 'n';}

        case 3:
        c= nextChar();
        if (c=='a')
        {state =2;
        break;}
        else if(c=='b')
        {state =4;
        break;}
        else if(c=='$')
        {return 'n';} 
        
        case 4:
        c= nextChar();
        if (c=='a')
        {state =2;
        break;}
        else if(c=='b')
        {state =1;
        break;}
        else if(c=='$')
        {return 'y';}
        }
    }
}
 
int main()
{
    
       
    char res = dfa();
    if (res == 'y')
    {
        printf("The string is accepted");
    } 
    else{
        printf("The string is rejected");
    }
}

