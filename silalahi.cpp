//Steven Silalahi

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <stack>

using namespace std;

int main()
{
  //necessary variables
  ifstream readFile;
  string theString;
  char elem;

  //creates the stack
  stack<char> theStack;
  
  readFile.open("input.txt"); //reads the input file
  
  while(readFile >> theString) //the while loop keeps reading the entire file
    {
      //have z at the bottom of the stack
            theStack.push('z');
     
      for(int j=0; j< theString.length(); j++) //the for loop iterates through the string
	{
       	  //each element in the string 
	   elem = theString[j];
	  
	  //only grabs parenthesis and brackets from the string
	  if(elem == ')' || elem == '(' || elem == ']' || elem == '[')
	    {
	      //push of there's nothing on the stack
	      if(theStack.top()=='z')
		{
		  if(elem== '[' || elem =='(' || elem ==')' || elem== ']')
		    {
		      theStack.push(elem);
		    }
		}
	       
	      //on an unempty stack
	      else  if(theStack.top()!= 'z')
		{  
		  //keep pushing when it reads '(' or '['
		  if(elem == '(')
                    {
                      theStack.push(elem);
                    }
                  if(elem == '[')
                    {
                      theStack.push(elem);
		    }
		    
		  //pop when it reads ')' or ']'
		  if(theStack.top()== '(')
		    {
		      if(elem == ')')
			{
			  theStack.pop();
			 
			}
		    }
		  if(theStack.top()== '[')
		    {
		      if(elem == ']')
			{
 
			  theStack.pop();
		       
     			}
		    }    
	       	}	  
	     }
	      
	}//for loop

      //use z as indicator whether or not the string is balanced
      // because z will always be at the bottom of the stack
      if(theStack.top()== 'z')
	{
	  cout<< "Parentheses are balanced for String " << theString  <<endl;
	  cout<< ""<<endl;
	}
	 else
	   {
	     cout<<"Parentheses are not balanced for String "<< theString<< endl;
	     cout<<""<<endl;
	   }
    }//while loop
}

//end of program
