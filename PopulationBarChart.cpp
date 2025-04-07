#include <iostream>
#include <fstream>
#include <string>

using namespace std;

string get_chart_data(int);
void chart_output(vector<int>&);

int main(){

    ifstream inFS;
    vector<int> data;
    int population;

    inFS.open("People.txt");

    if(!inFS.is_open()){
        cout << "ERROR OPENING FILE" << endl;
        return 1;
    }

    cout << "\nFILE OPENED SUCCESSFULLY\n" << endl;
    cout << "\nADDING FILE DATA TO VECTOR\n" << endl;

    inFS >> population;
    while(!inFS.fail()){
        data.push_back(population);
        inFS >> population;
    }

    cout << "\nPRINTING FILE POPULATION DATA\n" << endl;
    chart_output(data);

    inFS.close();
    if(!inFS.is_open())
        cout << "\nFILE CLOSED SUCCESSFULLY\n" << endl;

    return 0;
}

string get_chart_data(int pop){

    string stars;

    for(int i = 0; i < (pop/1000); i++)
        stars.append("*");
    
    return stars;
}

void chart_output(vector<int> &data){

    cout << setw(5) << left << "YEAR" << "|" << " POPULATION" << endl;
    cout << setw(6) << right << setfill('-') << "+" << setw(21) << left << "" << setfill(' ') << endl;

    for(int i = 0; i < 6; i++)
        cout << setw(5) << 1900+(i*20) << "|" << " " << get_chart_data(data[i]) << endl;

    cout << setw(6) << right << setfill('-') << "+" << setw(21) << left << "" << setfill(' ') << endl;

}