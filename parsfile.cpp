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
					cout<<"\n Class name: "<<word<<"\n";  
				}

            }// end while
        }       
        else
        {
        	cout<<"\nFile is NOT opened........";
        }
    }//end findClassNames

};




////// class for Java Files as input
class JavaFile : public Files
{
public: 
	JavaFile()
	{
//  cout<<"\nIn Java File Class....constructor..."; 
	}
public:
	void findMethodsInClass(char fileName[20])
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
	cout<<"\n Function in Java Class: "<<word<<"\n";  
}


}
}

}// end while
}
else
{
	cout<<"\nFile is NOT opened........";
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
	cout<<"\n Property in Java Class: "<<word<<"\n";  
}

}
}

}// end while
}
else
{
	cout<<"\nFile is NOT opened........";
}
}





};//end Java File Class

////// class for Php Files
class PhpFile :public Files
{
public:
	PhpFile()
	{
//cout<<"\nIn the constructor of PhpFile...";
	}
public:
	
	void findMethodsInClass(char fileName[20])
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
//cout<<"\nIn findMethodsInClass............";
inputFile.open(fileName);
if(inputFile.is_open())
{

	while(!inputFile.eof())
	{   
		inputFile>>buffer;
//cout <<"\nbuffer at 1: "<<buffer;

		if((buffer.compare("public")==0))
		{ 
			flag=1;
//cout <<"\nflag is:1 ";
		}
		else
		{
			if((buffer.compare("protected")==0))
			{
				flag=2;  
//cout <<"\nflag is:2 ";
			}
			else
			{ 
				if((buffer.compare("private")==0))
				{                          
					flag=3;  
//cout <<"\nflag is:3  ";  
				}
}//else2
}// else1
inputFile>>buffer;
//cout <<"\nbuffer at 2: "<<buffer;
if((buffer.compare("function")==0))
{
	inputFile>>buffer;
//cout <<"\nbuffer at 3: "<<buffer;
	cout<<"\nFunction Name is "<<buffer<<" with Access Specifier as: "; 


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
		default:
;//do nothing flag is 0

}//end switch  
}//end if

}//endwhile....                                    
// }//end for
}//end if 
else 
{
	cout<<"\nFile is NOT opened........";
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
//cout<<word; 
			if((word.compare("public")==0)||(word.compare("private")==0)||(word.compare("protected")==0))                     
			{
				inputFile3>>word;
				if(word[0]=='$')
				{
					cout<<"\nProperty of class is: "<<word<<"\n";
				}              
			}
			if((word.compare("var")==0))
			{ 
				inputFile3>>word;  
				if(word[0]=='$')
				{
					cout<<"\nProperty of class is: "<<word<<"\n";
				}              
			}                              
}// end while
}
else
{
	cout<<"\nFile is NOT opened........";
}
}// end function


};//end of phpFileClass


class RubyFiles : public Files
{
public:
	
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
						cout<<"\n Property in Ruby Class: "<<word<<"\n";
					}            
				}
            }// end while
        }
        else
        {
        	cout<<"\nFile is NOT opened........";
        }
    }// end function
    void findMethodsInClass(char fileName[20])
    {
    	std::ifstream inputFile3;
    	std::string word; 
    	inputFile3.open(fileName);
    	if(inputFile3.is_open())
    	{
    		while(!inputFile3.eof())
    		{
    			inputFile3>>word;              
                //cout<<word; 
    			if(word.compare("def")==0)
    			{
    				inputFile3>>word;
    				cout<<"\n Method in Ruby Class: "<<word<<"\n";
    			}            
            }// end while
        }
        else
        {
        	cout<<"\nFile is NOT opened........";
        }
    }// end function  


};//end of rubyFileClass


//NonMember Function of all classes
int main()
{
	char storage[200];
	char fileName[20];
	char storeData[20]; 
	int index;

	std::ifstream inputFile; 
	cout<<"\nEnter your filename.extension: ";
	cin>>fileName;

	inputFile.open(fileName);
	while(true)
	{
		inputFile>>storeData;
		std::string str(storeData);
		if(str.compare("<?php")==0)
		{
			cout<<"\nThis is a php file...\n";
			PhpFile php1;
			php1.findClassNames(fileName);     
			php1.findPropertiesOfClass(fileName);
			php1.findMethodsInClass(fileName);
			break;

		}
		else if((str.compare("import")==0) || (str.compare("public"))==0)
		{
			cout<<"\nThis is Java File\n";
			JavaFile java1;
			java1.findClassNames(fileName);      
			java1.findPropertiesOfClass(fileName);
			java1.findMethodsInClass(fileName);
			break;      
		}
		else if(str.compare("class")==0)
		{
			cout<<"\nThis is a Ruby File....\n";
			RubyFiles ruby1;
			ruby1.findClassNames(fileName);
			ruby1.findPropertiesOfClass(fileName);
			ruby1.findMethodsInClass(fileName);     
			break;
		}

	}

	return 0;
}
