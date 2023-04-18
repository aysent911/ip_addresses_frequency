#include <iostream>
#include <string>
#include <fstream>
using namespace std;
struct addresses{
  string ipAddress;
  int ipCount;
}address[1000];
void findAddress(){			//find IP address and the counts
  string fileName ="log_file.log";
  string readLine;
  string foundIP;
  bool existing = false;
  ifstream inputFile(fileName,ios::in);	//open log_file into fstream inputFile
  if(inputFile.is_open()){
    cout<<"File \""<<fileName<<"\" opened successfully!"<<endl;
    do{
      getline(inputFile,readLine);	//read log_file line by line
      if(readLine.length()==0){
      }else{				//extract IP only
        foundIP=readLine.substr(readLine.find("html")+6,readLine.length());
        int p;
        for(p = 0;address[p].ipAddress!="";p++){
          if(address[p].ipAddress == foundIP){//check if IP and count is logged
            existing = true;		
            break;
          }
        }
        if(existing){	//if already logged increment count
          address[p].ipCount++;
        }else{		//enter new IP:count pair into the structure
         address[p].ipAddress = foundIP;
         address[p].ipCount=1;
        }
      }
    }while(! inputFile.eof());
    inputFile.close();
  }else{
    cout<<"Cannot find file \""<<fileName<<"\"!"<<endl;
  }
}
void printMostOften(){		//print to "IPv4_frequency.log" file
  string fileName =  "IPv4_frequency.log";
  ofstream outputFile(fileName,ios::out);
  if(outputFile.is_open()){
    cout<<"File \""<<fileName<<"\" created successfully!"<<endl;
    outputFile<<"IP Address"<<"\t"<<"Frequency"<<endl;
    for(int n = 0;address[n].ipAddress!="";n++){
      outputFile<<address[n].ipAddress<<"\t"<<address[n].ipCount<<endl;
    }
    outputFile.close();
  }else{
    cout<<"Cannot find file \""<<fileName<<"\"!"<<endl;
  }
}
int main(){
  findAddress();
  printMostOften();
  return 0;
}
