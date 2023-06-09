#include<iostream>
#include<fstream>
using namespace std;

int main()
{
    ofstream fout;  //fout is object name it can be any thing
    /*
    1.file create
    2.file open
    3.write operation (by ofstream)-->[fout+cin]
    4.close

    and for reading-
    1.open
    2.read file(ifstream)-->[fin+cout]
    3.close
    */

   string line;
   fout.open("abc.txt",ios::app|ios::in|ios::out); //ios::app-->>is mode of operation.
   //here .open creates as well as opens the file.and if file is already created then it opens the file.
   //##if path is wrong and file is not created than there will be NULL in fout.

   if(!fout)
   {
    cout<<"file not created or not able to open."<<endl;
   }
   else{
    while(fout)
    {
        getline(cin,line); //takes one line input (terminate at 'enter').
        
        if(line == "-1")//this is just a random condition to terminate the loop nothing else.
        break;

        fout<<line;
    }

    cout<<"file created successfully."<<endl;
   }
   cout<<endl;

   fout.close();

   ifstream fin;
   fin.open("/home/omkar/Desktop/programs/#a_oops/abc.txt");
    //-->>seekg.....
    fin.seekg(4,ios_base::beg);//##
    /*
    basically it moves the pointer to from  where we want to read or write.
    ##->seekg(offset,base_address)
    ->>base_address==> 'beg' makes it to point at begining of file
                        'end' makes it to move at end of file

    ->>offset==> now let offset is "x"
    then it skips x position from where the base_address pointer is pointing.
    
    <>line 49(fin.seekg(4,ios_base::beg)) says that read file from beg and skip the 4 positions.
    */

   while(!fin.eof())  //eof->>end of file.
   {
    getline(fin,line);
    cout<<line<<endl;
   }
   fin.close(); 


    return 0;
}