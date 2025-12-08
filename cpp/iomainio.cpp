#include <iostream>
#include <iomanip>
using namespace std;

int main(){
    cout << "=== num structure verbose show ===" <<endl;
    cout << setfill('-')<<setw(50)<<"" << endl;
    cout<<setfill(' ');

    cout<<"|"<<setw(10)<<left<<"name";
    cout<<"|"<<setw(8)<<right<<"grade";
    cout<<"|"<<setw(10)<<right<<"percent";
    cout<<"|"<<setw(8)<<right<<"hex"<<"|"<<endl;


    cout<<setfill('-')<<setw(50)<<""<<endl;
    cout<<setfill(' ');
    string names[] = {"A","B","C"};
    double scores[] = {95.23,83.32,34.65};
    for(int i=0; i< 3;i++){
    cout<<"|"<<setw(10)<<left<<names[i]
        <<"|"<<setw(8)<<right<<fixed<<setprecision(2)<<scores[i]
        <<"|"<<setw(10)<<right<<fixed<<setprecision(1)<<(scores[i]/100*100)<<"%"
        <<"|"<<setw(8)<<right<<hex<<uppercase<<(int)scores[i]<<"|"<<endl;
         
    }
    cout<<setfill('-')<<setw(50)<<""<<endl;
    return 0;
}
