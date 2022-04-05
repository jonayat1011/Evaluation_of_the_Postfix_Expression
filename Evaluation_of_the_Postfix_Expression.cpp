
#include<iostream>
#include<string>
#include<math.h>
using namespace std;

class Evaluation
{
public:
bool isOperand(char c)
{
	if((c>='0' && c<='9'))
    {
		return true;
	}
	else
	{
		return false;
	}
}
int i=0,top=-1;
int stack[100];
int a,b;
void pushS(int c)
	{
      top++;
      stack[top]=c;

    }
int getTop()
	{
        return stack[top];
    }
void popS()
	{		
		top--;				
	}
bool isOperator(char c)
    {
	if(c=='+' || c=='-' ||  c=='*' ||c =='/'|| c=='^' ||c=='%')
	{
		return true;
	}
	else
	{
		return false;
	}
    }


void  evaluating(string postfix){
    while(postfix[i]!= '\0')
    {
     if(isOperand(postfix[i]))
     {
       
        switch (postfix[i])
            {
                case '0': 
                          pushS(0);
                          break;

                case '1': 
                          pushS(1);
                          break;
                case '2': 
                          pushS(2);
                          break;
                case '3': 
                          pushS(3);
                          break;
                case '4': 
                          pushS(4);
                          break;
                case '5': 
                          pushS(5);
                          break;
                case '6': 
                          pushS(6);
                          break;
                case '7': 
                          pushS(7);
                          break;
                case '8': 
                          pushS(8);
                          break;
                case '9': 
                          pushS(9);
                          break;
        
                 default:
                          break;
            }
            i++;
     }
     else if(isOperator(postfix[i]))
     {
        a = getTop();
        popS();
        b = getTop();
        popS();
        switch (postfix[i])
            {
                case '+': 
                          pushS(b + a);
                          break;
                case '-': 
                          pushS(b - a);
                          break;
                case '*': 
                          pushS(b * a);
                          break;
                case '/': 
                          pushS(b / a);
                          break;
                case '^': 
                          pushS(pow(b,a));
                          break;
                case '%': 
                          pushS(b % a );
                          break;
        
                 default:
                          break;
            }
            i++;
     }
     else{
         cout<<endl;
         cout<<"***********The expression invalid ********"<<endl;
          break;
         }
   
     }
    
    }
void print()
	{ 
   
	cout<<getTop();
   
    cout<<endl;
    }
};
int main(){
    Evaluation s1;
    string postfixExpr;
    //="12312*-/+18*2/-62+/";
    cout<<endl;
    cout<<"Enter   a  Postfix   Expression      : ";
    cin>>postfixExpr;
    s1.evaluating(postfixExpr);
    cout<<endl;
    cout<<"Evaluation of the Postfix Expression : ";
    s1.print();
    cout<<endl;
return 0;
}