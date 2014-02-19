#include<iostream>
#include<string>
#include<fstream>
#include<cstring>
using namespace std;
using std::ifstream;
class Files
{
  public:
  void findClassNames(char fileName[20])
  {
    int index=0;
    int flag=0;
    ifstream inputFile;
    string word; 
    inputFile.open(fileName);
    if(inputFile.is_open())
    {
      while(!inputFile.eof())
      {
        inputFile>>word;
        if(!word.compare("class"))
        {
          inputFile>>word;
          cout<<"\n Class name: "<<word<<"\n";  
        }

      }// end while
    }       
    else
    {
      cout<<"\nFile is NOT opened........";
    }
  }//end findClassNames
};//end super class


// class for Java Files as input
class JavaFile : public Files
{
  
  public:
  void findMethodsInClass(char fileName[20])
  {
    int index=0, flag=0;
    ifstream inputFile;
    string word; 

    inputFile.open(fileName);
    if(inputFile.is_open())
    {
      while(!inputFile.eof())
      {
        inputFile>>word;
        if( (!word.compare("public")) || (!word.compare("private")) || (!word.compare("protected")) )
        {
          inputFile>>word;
          if( (!word.compare("void")) || (!word.compare("String")) || (!word.compare("Long")) || (!word.compare("int")) || (!word.compare("Double")) )
          {
            inputFile>>word;
            for(index=0;word[index]!='(';index++)// finds weather word is a function name or variable name    
            {
              if(word[index]=='\0')
              {
                flag=1;//word contains variable.
                break;
              }
            }
            if(word[index]=='(')            
              cout<<"\n Function in Java Class: "<<word<<"\n";              
          }
        }
      }// end while
    }
    else    
      cout<<"\nFile is NOT opened........";
  }// end function findMethodsInClass

  void findPropertiesOfClass(char fileName[20])
  {
    int index=0, flag=0;
    ifstream inputFile;
    string word; 

    inputFile.open(fileName);
    if(inputFile.is_open())
    {
      while(!inputFile.eof())
      {
        inputFile>>word;
        if( (!word.compare("public")) || (!word.compare("private")) || (!word.compare("protected")) )
        {
          inputFile>>word;
          if( (!word.compare("void")) || (!word.compare("String")) || (!word.compare("Long")) || (!word.compare("int")) || (!word.compare("Double")) )
          {
            inputFile>>word;
            flag=0;//word does not contain variable
            for(index=0;word[index]!='(';index++)// finds weather word is a function name or variable name    
            {
              if(word[index]=='\0')
              {
                flag=1;//word contains variable.
                break;
              }
            }
            if(flag)
              cout<<"\n Property in Java Class: "<<word<<"\n";  

          }
        }

      }// end while
    }
    else    
      cout<<"\nFile is NOT opened........";

  }// end function findPropertiesOfClass

};//end Java File Class


// class for Php Files
class PhpFile :public Files
{  
  public:
  void findMethodsInClass(char fileName[20])
  {
    char ch;
    char previousWord[100];
    char accessSpecifier[20]; 

    int flag=0;
    int index=0, index2=0, index3=0;

    ifstream inputFile; 
    string buffer, functionName; 
    
    inputFile.open(fileName);
    if(inputFile.is_open())
    {
      while(!inputFile.eof())
      {   
        inputFile>>buffer;        
        if(!buffer.compare("public"))
          flag=1;          
        else
          if(!buffer.compare("protected"))
            flag=2;              
          else          
            if(!buffer.compare("private"))                    
              flag=3;               
                
        inputFile>>buffer;
        if(!buffer.compare("function"))
          {
            inputFile>>buffer;            
            cout<<"\nFunction Name is: "<<buffer<<" with Access Specifier as: "; 
            switch(flag)
            {
              case 1:
                      cout<<"public\n";
                      break;  
              case 2:
                      cout<<"protected\n";
                      break;  
              case 3:
                      cout<<"private\n"; 
                      break;  
              case 0:
                      cout<<"No access specifier.(Default function)\n"; 
              default: ;//do nothing

            }//end switch  
          }//end if
        }//endwhile....                                        
    }//end if 
    else     
      cout<<"\nFile is NOT opened........";

  }// end function


  void findPropertiesOfClass(char fileName[20])
  {
    ifstream inputFile3;
    string word; 
    inputFile3.open(fileName);
    if(inputFile3.is_open())
    {
      while(!inputFile3.eof())
      {
        inputFile3>>word;                      
        if( (!word.compare("public")) || (!word.compare("private")) || (!word.compare("protected")) )                     
        {
          inputFile3>>word;
          if(word[0]=='$')          
            cout<<"\nProperty of class is: "<<word<<"\n";
        }
        if(!word.compare("var"))
        { 
          inputFile3>>word;  
          if(word[0]=='$')         
            cout<<"\nProperty of class is: "<<word<<"\n";          
        }                              
      }// end while
    }
    else    
      cout<<"\nFile is NOT opened........";

  }// end function fPOC
};//end of phpFileClass


class RubyFiles : public Files
{
  public:
  void findPropertiesOfClass(char fileName[20])
  {
    ifstream inputFile3;
    string word; 
    inputFile3.open(fileName);
    if(inputFile3.is_open())
    {
      while(!inputFile3.eof())
      {
        inputFile3>>word;
        if(!word.compare("class"))             
        {
          inputFile3>>word;
          inputFile3>>word;
          if((word[0]=='@')&&(word[1]!='@'))          
            cout<<"\n Property in Ruby Class: "<<word<<"\n";
        }
      }// end while
    }
    else
      cout<<"\nFile is NOT opened........";

  }// end function

  void findMethodsInClass(char fileName[20])
  {
    ifstream inputFile3;
    string word; 
    inputFile3.open(fileName);
    if(inputFile3.is_open())
    {
      while(!inputFile3.eof())
      {
        inputFile3>>word;
        if(!word.compare("def"))
        {
          inputFile3>>word;
          cout<<"\n Method in Ruby Class: "<<word<<"\n";
        }            
      }// end while
    }
    else
      cout<<"\nFile is NOT opened........";
  }// end function  
};//end of rubyFileClass

//NonMember Function of all classes
int main()
{
  char storage[200];
  char fileName[20];
  char storeData[20]; 
  int index;

  ifstream inputFile; 
  cout<<"\nEnter your filename.extension: ";
  cin>>fileName;

  inputFile.open(fileName);
  while(!inputFile.eof())
  {
    inputFile>>storeData;
    string str(storeData);
    if(!str.compare("<?php"))
    {
      cout<<"\nThis is a php file...\n";
      PhpFile php;
      php.findClassNames(fileName);     
      php.findPropertiesOfClass(fileName);
      php.findMethodsInClass(fileName);
      break;
    }
    else if((!str.compare("import")) || (!str.compare("public")))
    {
      cout<<"\nThis is Java File\n";
      JavaFile java;
      java.findClassNames(fileName);      
      java.findPropertiesOfClass(fileName);
      java.findMethodsInClass(fileName);
      break;      
    }
    else if(!str.compare("class"))
    {
      cout<<"\nThis is a Ruby File....\n";
      RubyFiles ruby;
      ruby.findClassNames(fileName);
      ruby.findPropertiesOfClass(fileName);
      ruby.findMethodsInClass(fileName);     
      break;
    }

  }//end while
  return 0;
}
