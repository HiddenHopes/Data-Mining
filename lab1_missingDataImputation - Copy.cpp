#include<bits/stdc++.h>
using namespace std;

int t=10, n=0, m=0, choice, avg_age, avg_salary;
string name[11];
string country[11];
string sAge[11]; int age[11];
string sSalary[11]; int salary[11];

void input(){
    ifstream inFile ( "data1.csv" ); // taking whole file in memory
    for(int i=1; i<=t; i++){
        //input each row
        getline(inFile, name[i], ',');
        getline(inFile, country[i], ',');
        getline(inFile,sAge[i],',');       if(sAge[i]!="NaN"){age[i]=atoi(sAge[i].c_str()); n++;}
        getline(inFile,sSalary[i],'\n');   if(sAge[i]!="NaN"){salary[i]=atoi(sSalary[i].c_str()); m++;}
    }
}

void showData(){
    for(int i=1; i<=t; i++)
        cout<<name[i]<<","<<country[i]<<","<<sAge[i]<<","<<sSalary[i]<<endl;
}

int average(int a[], int n){
    int sum=0;
    for(int i=1; i<=n; i++)
        sum = sum + a[i];
    int avg = sum/n;
    return avg;
}

int mostFreqValue(int a[], int n){
    map<int,int> cnt;
    int mx = 0;
    int MostFreq;
    for(int i=1; i<=n; i++){
        cnt[a[i]] = cnt[a[i]]+1;
        if(mx<cnt[a[i]]) {MostFreq = a[i]; mx = cnt[a[i]];}
    }
    return MostFreq;
}

void mean(){
    cout<<"with mean value\n\n";
    avg_age = average(age, n);
    avg_salary = average(salary, m);

    for(int i=1; i<=t; i++){
        if(sAge[i]=="NaN") {
            age[i] = avg_age;        ostringstream s; s<<avg_age;
            sAge[i]= s.str();
        }
        if(sSalary[i]=="NaN") {
            salary[i] = avg_salary;  ostringstream s; s<<avg_salary;
            sSalary[i]= s.str();
        }
    }
}

void median(){
    cout<<"with median value\n\n";
    for(int i=1; i<=t; i++){
        if(sAge[i]=="NaN") {
            age[i] = (age[i-1]+age[i+1])/2;        ostringstream s; s<<age[i];
            sAge[i]= s.str();
        }
        if(sSalary[i]=="NaN") {
            salary[i] = (salary[i-1]+salary[i+1])/2;  ostringstream s; s<<salary[i];
            sSalary[i]= s.str();
        }
    }
}

void mostFreq(){
     cout<<"with most frequent value\n\n";
    int MostFreqAge=mostFreqValue(age,n);
    int MostFreqSalary = mostFreqValue(salary,m);

    for(int i=1; i<=t; i++){
        if(sAge[i]=="NaN") {
            ostringstream s; s<<MostFreqAge;
            sAge[i]= s.str();
        }
        if(sSalary[i]=="NaN") {
            ostringstream s; s<<MostFreqSalary;
            sSalary[i]= s.str();
        }
    }
}

int main(){


    //freopen("out.csv","w",stdout); // output is stored in out.csv file

    input();

    cout<<"\nBefore imputing:\n\n";
    showData(); cout<<endl;

        cout<<"Press 1: To impute missing data with MEAN value\n";
        cout<<"Press 2: To impute missing data with MEDIAN value\n";
        cout<<"Press 3: To impute missing data with Most Frequent value\n";

        cin>>choice;

    cout<<"\nAfter imputing missing value: ";
    switch(choice){
        case 1: mean();     break;
        case 2: median();   break;
        case 3: mostFreq(); break;
    }
    showData();

    return 0;
}
