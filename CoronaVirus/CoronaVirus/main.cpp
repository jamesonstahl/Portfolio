#include <iostream>
#include <string>
#include <vector>
#include "curl/curl.h"

using namespace std;

class Person{
public:
    Person();
    Person(string name, int age, string state, vector<string> conditions, int counter);
    void CalculateRisk();
    void ShowInfo();
private:
    string name;
    int age;
    string state;
    vector<string> conditions;
    int counter;
};

Person::Person(){
    
}

//Constructor assigns user inputted parameters to variables
Person::Person(string a, int b, string c, vector<string> d, int e){
    name = a;
    age = b;
    state = c;
    conditions = d;
    counter = e;
    
}

//Calculated risk for COVID-19 by adding to a risk counter depending on state, age, and conditions
void Person::CalculateRisk(){
    vector<string> highRisk{"NY", "NJ", "MA", "IL", "CA", "PA", "MI", "FL", "TX", "CT"};
    for(int i = 0; i < highRisk.size(); i++){
        if(state == highRisk[i]){
            counter++;
        }
    }
    if(age < 17){
        counter++;
    }
    else if(age < 65){
        counter += 2;
    }
    else{
        counter += 3;
    }
    if(counter < 5){
        cout << "YOU ARE AT LOW RISK FOR COVID-19" << endl;
        cout << "Stay at home, social distance, wash hands, wear a mask" << endl;
        cout << endl;
    }
    else if(counter < 10){
        cout << "YOU ARE AT MODERATE RISK FOR COVID-19" << endl;
        cout << "Stay at home, social distance, wash hands, wear a mask, consider getting tested" << endl;
        cout << endl;
    }
    else{
        cout << "YOU ARE AT HIGH RISK FOR COVID-19" << endl;
        cout << "Stay at home, social distance, wash hands, wear a mask, get tested as soon as possible, self-quarantine" << endl;
        cout << endl;
    }
}

//Prints out user info
void Person::ShowInfo(){
    cout << name << endl;
    cout << age << endl;
    cout << state << endl;
    if(conditions.size() != 0){
        cout << "Conditions:" << endl;
        for(int i = 0; i < conditions.size(); i++){
            cout << conditions[i] << endl;
        }
    }
}

//User inputs personal information and takes a series of health assessment questions
//Increases risk counter if the user has COVID symptoms or pre existing conditions
//Calls the ShowInfo and CalculateRisk function
void Questions(){
    string name;
    int age;
    string state;
    vector<string> conditions;
    string input;
    int c = 0;
    Person activePerson;
    
    cout << "Enter your name: ";
    cin >> name;
    cout << "Enter your age: ";
    cin >> age;
    cout << "Enter the two letter abbreviation for your state: ";
    cin >> state;
    cout << "FOR THE FOLLOWING QUESTIONS PRESS 'Y' FOR YES AND 'N' FOR NO" << endl;
    cout << "1) Do you have a fever, chills, or sweating? ";
    cin >> input;
    if(input == "Y"){
        conditions.push_back("fever, chills, or sweating");
        c++;
    }
    cout << "2) Do you have difficulty breathing? ";
    cin >> input;
    if(input == "Y"){
        conditions.push_back("difficulty breathing");
        c++;
    }
    cout << "3) Do you have a new or worsening cough? ";
    cin >> input;
    if(input == "Y"){
        conditions.push_back("new or worsening cough");
        c++;
    }
    cout << "4) Do you have a sore throat? ";
    cin >> input;
    if(input == "Y"){
        conditions.push_back("sore throat");
        c++;
    }
    cout << "5) Do you have body aches? ";
    cin >> input;
    if(input == "Y"){
        conditions.push_back("body aches");
        c++;
    }
    cout << "6) Have you vomited or had diarrhea? ";
    cin >> input;
    if(input == "Y"){
        conditions.push_back("vomit or diarrhea");
        c++;
    }
    cout << "7) Have you been working or volunteering? ";
    cin >> input;
    if(input == "Y"){
        conditions.push_back("working or volunteering");
        c++;
    }
    cout << "8) Have you been in contact with someone who has tested positive for COVID-19? ";
    cin >> input;
    if(input == "Y"){
        conditions.push_back("contact with someone who has tested positive for COVID-19");
        c++;
    }
    cout << "9) Have you traveled within the past two weeks? ";
    cin >> input;
    if(input == "Y"){
        conditions.push_back("traveled");
        c++;
    }
    cout << "10) Do you have chronic lung disease? ";
    cin >> input;
    if(input == "Y"){
        conditions.push_back("chronic lung disease");
        c++;
    }
    cout << "11) Do you have asthma? ";
    cin >> input;
    if(input == "Y"){
        conditions.push_back("asthma");
        c++;
    }
    cout << "12) Do you have a serious heart condition? ";
    cin >> input;
    if(input == "Y"){
        conditions.push_back("serious heart condition");
        c++;
    }
    cout << "13) Do you have diabetes? ";
    cin >> input;
    if(input == "Y"){
        conditions.push_back("diabetes");
        c++;
    }
    cout << "14) Do you a weakened immune system? ";
    cin >> input;
    if(input == "Y"){
        conditions.push_back("weakened immune system");
        c++;
    }
    cout << "15) Have you had dialysis? ";
    cin >> input;
    if(input == "Y"){
        conditions.push_back("dialysis");
        c++;
    }
    cout << "16) Do you have liver disease? ";
    cin >> input;
    if(input == "Y"){
        conditions.push_back("liver disease");
        c++;
    }
    cout << "17) Are you pregnant? ";
    cin >> input;
    if(input == "Y"){
        conditions.push_back("pregnant");
        c++;
    }
    cout << "18) Are you severely obese? ";
    cin >> input;
    if(input == "Y"){
        conditions.push_back("severely obese");
        c++;
    }
    cout << endl;
    activePerson = Person(name, age, state, conditions, c);
    activePerson.ShowInfo();
    activePerson.CalculateRisk();
}

//Uses the libcurl library to extract and print current COVID statistics
void Api(){
    string choice;
    cout << "COVID-19 DATABASE" << endl;
    while(choice != "3"){
        cout << "Select 1 to see global data" << endl;
        cout << "Select 2 to see US data" << endl;
        cout << "Select 3 to quit" << endl;
        cin >> choice;
        //Retrieves global data
        if(choice == "1"){
            CURL *curl;
            CURLcode res;
            curl = curl_easy_init();
            if(curl) {
              curl_easy_setopt(curl, CURLOPT_CUSTOMREQUEST, "GET");
              curl_easy_setopt(curl, CURLOPT_URL, "https://api.thevirustracker.com/free-api?global=stats");
              curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L);
              curl_easy_setopt(curl, CURLOPT_DEFAULT_PROTOCOL, "https");
              struct curl_slist *headers = NULL;
              curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headers);
              res = curl_easy_perform(curl);
            }
            curl_easy_cleanup(curl);
        }
        //Retrieves US data
        else if(choice == "2"){
            CURL *curl;
            CURLcode res;
            curl = curl_easy_init();
            if(curl) {
              curl_easy_setopt(curl, CURLOPT_CUSTOMREQUEST, "GET");
              curl_easy_setopt(curl, CURLOPT_URL, "https://api.thevirustracker.com/free-api?countryTotal=US");
              curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L);
              curl_easy_setopt(curl, CURLOPT_DEFAULT_PROTOCOL, "https");
              struct curl_slist *headers = NULL;
              curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headers);
              res = curl_easy_perform(curl);
            }
            curl_easy_cleanup(curl);
        }
    }
}

int main(int argc, const char * argv[]) {
    string choice1;
    //Prints out user menu
    cout << "Welcome to the COVID-19 Program" << endl;
    while(choice1 != "3"){
        cout << "Select 1 to check your risk for COVID-19" << endl;
        cout << "Select 2 to see COVID-19 data" << endl;
        cout << "Select 3 to quit" << endl;
        cin >> choice1;
        if(choice1 == "1"){
            Questions();
        }
        else if(choice1 == "2"){
            Api();
        }
    }
    return 0;
}
