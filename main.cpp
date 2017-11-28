#include <string> 
#include <list> 
#include <iostream> 
#include <sstream> 
#include <iterator> 
#include "md5.h"

using namespace std;

void filllist(int x0, int x1, list<string>& listelements, int n){

    stringstream convert;

    for(size_t i = x0; i < x1; i++ ){
        convert << i;
        string result = md5(convert.str());
        result.resize(n);
        listelements.push_back(result); 
    }

}

list<string> collision(list<string> m1, list<string> m2, list<string> m3){
    list<string> result;

    for(list<string>::iterator i = m1.begin(); i != m1.end(); i++){
        for(list<string>::iterator j = m2.begin(); j != m2.end(); j++){
            if(*i == *j){
                cout << "enctrou";
                result.push_back(*i);
            }
        } 
    }

    if(result.size() > 0){
        cout << "passou" << endl;
        for(list<string>::iterator i = m3.begin(); i != m3.end(); i++){
            for(list<string>::iterator j = result.begin(); j != result.end(); j++){
                if(*i == *j){
                    result.push_back(*i);
                }
            } 
        }
    }


    return result;
}

int main(){

    list<string> m1;
    list<string> m2;
    list<string> m3;
    list<string> resultcollision;

    filllist(0, 220, m1, 3);
    filllist(200,220, m2, 3);
    filllist(220,225, m3, 3);
   
    resultcollision = collision(m1, m2, m3);
    
    if (resultcollision.size() > 0){
        for(list<string>::iterator s = resultcollision.begin(); s != resultcollision.end(); s++) {
            cout << " " << *s << endl; 
        }
    }
   
    return 0;    
}