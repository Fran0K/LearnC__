#include <vector>
#include <unordered_map>
#include <iostream>
using namespace std;

vector<string> preprocessDate(vector<string> dates) {
    unordered_map<string, string>month={
            {"Jan","01"},{"Feb","02"},{"Mar","03"},{"Apr","04"},
            {"May","05"},{"Jun","06"},{"Jul","07"},{"Aug","08"},
            {"Sep","09"},{"Oct","10"},{"Nov","11"},{"Dec","12"}
    };
    vector<string>ans;
    for(auto d : dates){
        int n = d.size();
        int fb = d.find(" ");
        string days = d.substr(0,fb);
        string temp = d.substr(fb+1,n);
        int sd = temp.find(" ");
        string mon = temp.substr(0,sd);
        string year = temp.substr(sd+1, n);

        string t;
        for(int i =0 ;i<days.size();i++){
            if(isdigit(days[i])){
                t+=days[i];
            }
        }
        t+='-';
        auto it = month.find(mon);
        t+=it->second;
        t+='-';

        t+=year;
        ans.push_back(t);
    }


    return ans;

}

int main()
{
    vector<string>kk={"20th Sep 1958",
                        "16th Mar 2068",
                        "25th May 1912",
                        "16th Dec 2018",
                        "26th Dec 2061",
                        "4th Nov 2030"};
    preprocessDate(kk);


}
