#include <iostream>
#include <fstream>
#include <cstring>

typedef unsigned long long bignum;

void swap(std::string *xp, std::string *yp);
void bubbleSort(std::string arr[], int n);

int main()
{
    char abc[26];
    for(int i = 0; i < 26; i++)
        abc[i] = 65 + i;
    std::fstream file("names.txt", std::ios_base::in|std::ios_base::out);
    
    std::string getfile;
    int num(0);
    while(!file.eof())
    {
        std::getline(file, getfile, ',');
        num += 1;
    }
    std::cout << "To file \"names\" consists of: " << num << " names." << std::endl;
    
    
    file.seekg(0);//starting again from 0 to read again the names to store in an array
    const int len = num;
    std::string FileNames[len];
    int i = 0;
    while(!file.eof())
    {
        std::getline(file, getfile, ',');
        FileNames[i] = getfile;
        i++;
    }
    
    bubbleSort(FileNames, len); //to slow for an actual program but...

    bignum allsum(0);
    for(int i = 0; i < len; i++)
    {   
        long sum(0);    
        const int wordlen = strlen(FileNames[i].c_str()); //legnth of current name
        char word[wordlen]; //declared array of characters for name 
        strcpy(word, FileNames[i].c_str()); //copies name to array
        //mexri edo einai sostotato
        for(int ii = 0; ii < wordlen; ii++)
        {
            for(int jj = 0; jj < 26; jj++)
            {
                if(word[ii] == '\0')
                    break;
                if(word[ii] == abc[jj])
                    sum += jj + 1;   
            }
        }
        sum *= i + 1;
        allsum += sum;
    }
    std::cout << "The answer is: " << allsum << std::endl;
    //Edo brisketai to lathos!!!!!!!!!!!
}


void swap(std::string *xp, std::string *yp) 
{ 
    std::string temp = *xp; 
    *xp = *yp; 
    *yp = temp; 
} 

void bubbleSort(std::string arr[],const int n) 
{
   for (int i = 0; i < n-1; i++)       
  
       // Last i elements are already in place    
       for (int j = 0; j < n-i-1; j++)  
           if (arr[j+1] < arr[j]) 
              swap(&arr[j], &arr[j+1]);    
} 