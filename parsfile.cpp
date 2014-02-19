#include<iostream>
#include<string>
#include<fstream>
#include<cstring>

using std::ifstream;
using namespace std;

class Files
{
  public:
  virtual void findMethodsInClass(char fileName[20]){};
  virtual void findPropertiesOfClass(char fileName[20]){};
  void findClassNames(char fileName[20])
  {
    int index=0, flag=0;
    ifstream inputFile;
    string word; 
    inputFile.open(fileName);
    if(!inputFile.is_open())
      cout<<"\n Unable to open file ..... ";
    else
      while(!inputFile.eof())
      {
        inputFile>>word;
        if(!word.compare("class"))
        {
          inputFile>>word;
          cout<<"\n Class name: "<<word<<"\n";  
        }

      }// end while
    
  }//end function findClassNames
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
    if(!inputFile.is_open())
      cout<<"\nUnable to open file ... ";
    else
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
    
  }// end function findMethodsInClass

  void findPropertiesOfClass(char fileName[20])
  {
    int index=0, flag=0;
    ifstream inputFile;
    string word; 

    inputFile.open(fileName);
    if(!inputFile.is_open())
      cout<<"\nUnable to open file ... ";
    else
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
    if(!inputFile.is_open())
      cout<<"\nUnable to open file ... ";
    else
      while(!inputFile.eof())
      {   
        inputFile>>buffer;        
        if(!buffer.compare("public"))
          flag=1;          
        else if(!buffer.compare("protected"))
          flag=2;              
        else if(!buffer.compare("private"))                    
          flag=3;               
                
        inputFile>>buffer;
        if(!buffer.compare("function"))
          {
            inputFile>>buffer;            
            cout<<"\nFunction Name is: "<<buffer<<" with Access Specifier: "; 
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
                      cout<<"No access specifier.\n"; 
              default: ;//do nothing

            }//end switch  
          }//end if
      }//endwhile....                                        
    
  }// end function


  void findPropertiesOfClass(char fileName[20])
  {
    ifstream inputFile3;
    string word; 
    inputFile3.open(fileName);
    if(!inputFile3.is_open())
      cout<<"\nUnable to open file ... ";
    else
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
    
  }// end function fPOC

};//end of phpFileClass


class RubyFile : public Files
{
  public:
  void findPropertiesOfClass(char fileName[20])
  {
    ifstream inputFile3;
    string word; 
    inputFile3.open(fileName);
    if(!inputFile3.is_open())
      cout<<"\nUnable to open file ... ";
    else
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
    
  }// end function

  void findMethodsInClass(char fileName[20])
  {
    ifstream inputFile3;
    string word; 
    inputFile3.open(fileName);
    if(!inputFile3.is_open())
      cout<<"\nUnable to open file ... ";
    else
      while(!inputFile3.eof())
      {
        inputFile3>>word;
        if(!word.compare("def"))
        {
          inputFile3>>word;
          cout<<"\n Method in Ruby Class: "<<word<<"\n";
        }            
      }// end while
    
  }// end function  
};//end of rubyFileClass

void processFile(Files& aFile,char fileName[20])
{
  aFile.findClassNames(fileName);
  aFile.findPropertiesOfClass(fileName);
  aFile.findMethodsInClass(fileName);     
}
//NonMember Function of all classes
int main()
{
  char storage[200];  
  char storeData[20]; 
  int index;
  char inputFiles[][20] = {"student.java","college.java","binding.rb","myclass.php","class.smtp.php"};  
  ifstream inputFile; 
  
  for(index=0 ; index<5 ; index++)
  {
    cout<<"----------------------------------------------------------------------------\n"<<endl;
    inputFile.open(inputFiles[index]);
    while(!inputFile.eof())
    {
      inputFile>>storeData;
      string str(storeData);
      if(!str.compare("<?php"))
      {
        cout<<inputFiles[index]<<"\nThis is a php file...\n";
        PhpFile phpFile;
        processFile(phpFile,inputFiles[index]);      
        break;
      }
      else if( (!str.compare("import")) || (!str.compare("public")) )
      {
        cout<<inputFiles[index]<<"\nThis is Java File...\n";
        JavaFile javaFile;
        processFile(javaFile,inputFiles[index]);      
        break;      
      }
      else if(!str.compare("class"))
      {
        cout<<inputFiles[index]<<"\nThis is a Ruby File....\n";
        RubyFile rubyFile;
        processFile(rubyFile,inputFiles[index]);      
        break;
      }
     
    }//end inner while
    inputFile.close();
    
  }//end outer for

  return 0;
}
