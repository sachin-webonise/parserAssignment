#include<iostream>
#include<string>
#include<fstream>
#include<cstring>
//using namepace std;
using std::ifstream;
/*abstract class Files
{
 public:
        Files()
         {
          std::cout<<"In a Super constructor...constructor of Files...";
         }

};*/
////// class for Php Files



////// class for Java Files as input
class JavaFile//: public Files
{
 public: 
        JavaFile()
         {
           //std::cout<<"\nIn Java File Class....constructor..."; 
         }
 public:
        void findMethosInClass(char fileName[20])
         {
            int index=0;
            int flag=0;
            std::ifstream inputFile;
            std::string word; 
            inputFile.open(fileName);
            if(inputFile.is_open())
             {
              while(!inputFile.eof())
               {
                 inputFile>>word;
                 if((word.compare("public")==0)||(word.compare("private")==0)||(word.compare("protected")==0))
                    {
                       inputFile>>word;
                       if((word.compare("void")==0)||(word.compare("String")==0)||(word.compare("Long")==0)||(word.compare("int")==0)||(word.compare("Double")==0))
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
                              {
                                std::cout<<"\n Function in Java Class: "<<word<<"\n";  
                              }
                            
                            
                          }
                    }
                 
               }// end while
             }
            else
             {
              std::cout<<"\nFile is NOT opened........";
             }
         }
        void findPropertiesOfClass(char fileName[20])
         {
            int index=0;
            int flag=0;
            std::ifstream inputFile;
            std::string word; 
            inputFile.open(fileName);
            if(inputFile.is_open())
             {
              while(!inputFile.eof())
               {
                 inputFile>>word;
                 if((word.compare("public")==0)||(word.compare("private")==0)||(word.compare("protected")==0))
                    {
                       inputFile>>word;
                       if((word.compare("void")==0)||(word.compare("String")==0)||(word.compare("Long")==0)||(word.compare("int")==0)||(word.compare("Double")==0))
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
                            if(flag==1)
                              {
                                std::cout<<"\n Property in Java Class: "<<word<<"\n";  
                              }
                                                        
                          }
                    }
                 
               }// end while
             }
            else
             {
              std::cout<<"\nFile is NOT opened........";
             }
         }

      
       void findClassNames(char fileName[20])
         {
            int index=0;
            int flag=0;
            std::ifstream inputFile;
            std::string word; 
            inputFile.open(fileName);
            if(inputFile.is_open())
             {
              while(!inputFile.eof())
               {
                 inputFile>>word;
                 if(word.compare("class")==0)
                   {
                    inputFile>>word;
                    std::cout<<"\n Class name: "<<word<<"\n";  
                   }
                 
               }// end while
             }
            else
             {
              std::cout<<"\nFile is NOT opened........";
             }
         }

     
};//end Java File Class

////// class for Php Files
class PhpFile //:public Files
{
  public:
           PhpFile()
            {
              //std::cout<<"\nIn the constructor of PhpFile...";
            }
  public:
          void findClassNames(char fileName[20])
            {
              JavaFile obj;
              obj.findClassNames(fileName);
            }
          
          void findMethosInClass(char fileName[20])
            {
              char ch;
              int flag=0;//
              int index=0;
              int index2=0;
              int index3=0;
              std::ifstream inputFile; 
              std::string buffer; 
              char previousWord[100];
              std::string functionName;
              char accessSpecifier[20]; 
              //std::cout<<"\nIn findMethosInClass............";
              inputFile.open(fileName);
              if(inputFile.is_open())
               {
                
                 while(!inputFile.eof())
                  {   
                    inputFile>>buffer;
                    //std::cout <<"\nbuffer at 1: "<<buffer;
                    
                    if((buffer.compare("public")==0))
                         { 
                          flag=1;
                          //std::cout <<"\nflag is:1 ";
                         }
                      else
                       {
                        if((buffer.compare("protected")==0))
                         {
                          flag=2;  
                          //std::cout <<"\nflag is:2 ";
                         }
                        else
                        { 
                         if((buffer.compare("private")==0))
                          {                          
                           flag=3;  
                           //std::cout <<"\nflag is:3  ";  
                          }
                        }//else2
                       }// else1
                         inputFile>>buffer;
                         //std::cout <<"\nbuffer at 2: "<<buffer;
                            if((buffer.compare("function")==0))
                               {
                                 inputFile>>buffer;
                                 //std::cout <<"\nbuffer at 3: "<<buffer;
                                 std::cout<<"\nFunction Name is "<<buffer<<" with Access Specifier as: "; 
                                 
                                 
                                 switch(flag)
                                  {
                                   case 1:
                                          std::cout<<"public\n";
                                          break;  
                                   case 2:
                                          std::cout<<"protected\n";
                                          break;  
                                   case 3:
                                          std::cout<<"private\n"; 
                                          break;  
                                   case 0:
                                          std::cout<<"No access specifier.(Default function)\n"; 
                                   default:
                                            ;//do nothing flag is 0

                                  }//end switch  
                               }//end if
                             
                   }//endwhile....                                    
                 // }//end for
               }//end if 
               else 
                {
                 std::cout<<"\nFile is NOT opened........";
                }            
     
            }// end function
       void findPropertiesOfClass(char fileName[20])
          {
            std::ifstream inputFile3;
            std::string word; 
            inputFile3.open(fileName);
            if(inputFile3.is_open())
             {
              while(!inputFile3.eof())
               {
                inputFile3>>word;              
                //std::cout<<word; 
                if((word.compare("public")==0)||(word.compare("private")==0)||(word.compare("protected")==0))                     
                  {
                    inputFile3>>word;
                    if(word[0]=='$')
                      {
                        std::cout<<"\nProperty of class is: "<<word<<"\n";
                      }              
                  }
                if((word.compare("var")==0))
                  { 
                   inputFile3>>word;  
                   if(word[0]=='$')
                      {
                        std::cout<<"\nProperty of class is: "<<word<<"\n";
                      }              
                  }                              
               }// end while
             }
            else
             {
              std::cout<<"\nFile is NOT opened........";
             }
          }// end function
         
   
};//end of phpFileClass


class RubyFiles
{
 public:
         void findClassNames(char fileName[20])
            {
              JavaFile obj;
              obj.findClassNames(fileName);
            }
         void findPropertiesOfClass(char fileName[20])
          {
            std::ifstream inputFile3;
            std::string word; 
            inputFile3.open(fileName);
            if(inputFile3.is_open())
             {
              while(!inputFile3.eof())
               {
                inputFile3>>word;
                if(word.compare("class")==0)             
                 {
                  inputFile3>>word;
                  inputFile3>>word;
                  if((word[0]=='@')&&(word[1]!='@'))
                    {
                     std::cout<<"\n Property in Ruby Class: "<<word<<"\n";
                    }            
                 }
               }// end while
             }
            else
             {
              std::cout<<"\nFile is NOT opened........";
             }
          }// end function
         void findMethosInClass(char fileName[20])
          {
            std::ifstream inputFile3;
            std::string word; 
            inputFile3.open(fileName);
            if(inputFile3.is_open())
             {
              while(!inputFile3.eof())
               {
                inputFile3>>word;              
                //std::cout<<word; 
                if(word.compare("def")==0)
                  {
                    inputFile3>>word;
                    std::cout<<"\n Method in Ruby Class: "<<word<<"\n";
                  }            
               }// end while
             }
            else
             {
              std::cout<<"\nFile is NOT opened........";
             }
          }// end function  

 
};//end of rubyFileClass


//NonMember Function of all classes
int main()
{
 char storage[200];
 char fileName[20];
 char storeData[20];
 int flag=true;
 int index;

 std::ifstream inputFile; 
 std::cout<<"\nEnter your filename.extension: ";
 std::cin>>fileName;
 
 inputFile.open(fileName);
 while(flag)
  {
   inputFile>>storeData;
   std::string str(storeData);
   if(str.compare("<?php")==0)
    {
     std::cout<<"\nThis is a php file...\n";
     PhpFile php1;
     php1.findClassNames(fileName);     
     php1.findPropertiesOfClass(fileName);
     php1.findMethosInClass(fileName);
     flag=false;
     
    }
   if((str.compare("import")==0) || (str.compare("public"))==0)
    {
      std::cout<<"\nThis is Java File\n";
      JavaFile java1;
      java1.findClassNames(fileName);      
      java1.findPropertiesOfClass(fileName);
      java1.findMethosInClass(fileName);
       
      flag=false; 
    }
   if(str.compare("class")==0)
     {
      std::cout<<"\nThis is a Ruby File....\n";
      RubyFiles ruby1;
      ruby1.findClassNames(fileName);
      ruby1.findPropertiesOfClass(fileName);
      ruby1.findMethosInClass(fileName);     
      flag=false;  
     }
   
  }

 return 0;
}
