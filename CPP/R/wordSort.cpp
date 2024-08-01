
#include <iostream>
#include <fstream>
#include <string>
#include <conio.h>
std::ifstream::pos_type get_size (const std::string &fn);

int main()
{
SetConsoleCP(1251);
SetConsoleOutputCP(1251);

std::string filename = "f12.txt";
std::fstream fs( filename, std::fstream::txt);
int file_size = get_size(filename);
if(file_size < 0)std::cerr
 << "Error in [" << __PRETTY_FUNCTION__ << "]" << strerror(errno);

char T[250];
while( !feof(fs))
{
    fgets(T, 250, fs);
}
}

std::ifstream::pos_type get_size (const std::string &fn) // Read file and return size
{
	std::ifstream ifs (fn, std::ifstream::ate);
	return ifs.tellg();
}

std::string sorting( std::string str)
{
int k=0;
//считаем пробелы
 for(int i=0;i<str.length();i++) if(str[i]==' ') k++;
std::string words[k+1]; 
k=0;
int word_begin=0,word_end=0;
//заполняем массив строк
for (int i=0; i<str.length();i++)  
  {
    if(str[i]==' ' || i==str.length()-1) 
    {
      word_end=i;
      for(int j=word_begin;j<word_end;j++) words[k]+=str[j];
      k++;
      word_begin=word_end+1;
    }
  }
// сортируем массив строк
std::string tmp="";
for(int i=0;i<k;i++)
  for(int j=i;j<k;j++)
    if(words[i]>words[j]) 
      {
         tmp=words[i]; 
         words[i]=words[j];
         words[j]=tmp;
       }
str="";
//вставляем отсортированный вариант в исходную строку
//(теперь можно из main просто считать строку, вызвать функцию и вывести строку, уже отсортированную)
for(int i=0;i<k;i++) str+=words[i]+ " ";
return str;
}