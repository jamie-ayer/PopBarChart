#include <iostream>
#include <fstream>

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

    cout << "\nFile opened successfully..." << endl;
    cout << "Adding file data to vector..." << endl;

    inFS >> population;
    while(!inFS.fail()){
        data.push_back(population);
        inFS >> population;
    }

    cout << "Printing chart data...\n" << endl;
    chart_output(data);

    inFS.close();
    if(!inFS.is_open())
        cout << "\nFile closed successfully...\n" << endl;

    return 0;
}

string get_chart_data(int pop){

    string stars;

    for(int i = 0; i < (pop/1000); i++)
        stars.append("*");
    
    return stars;
}

void chart_output(vector<int> &data){

    cout << "PRAIRIEVILLE POPULATION GROWTH\n" << endl;
    cout << setw(5) << left << "YEAR" << "|" << " POPULATION" << endl;
    cout << setw(6) << right << setfill('-') << "+" << setw(21) << left << "" << setfill(' ') << endl;

    for(int i = 0; i < 6; i++)
        cout << setw(5) << 1900+(i*20) << "|" << " " << get_chart_data(data[i]) << endl;

    cout << setw(6) << right << setfill('-') << "+" << setw(21) << left << "" << setfill(' ') << endl;

}