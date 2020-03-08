#include <iostream>
#include <map>
#include <string>

using namespace std;

int main() {

    int N = 3;
    string coffeeName[] = {"Americano", "Latte", "Cappuccino"};
    int coffeePrice[] = {2, 4, 4};
    map<string, int> coffeeManu;

    // build the map
    for(int i = 0; i < N; i++){
        coffeeManu.insert(make_pair(coffeeName[i], coffeePrice[i]));
    }

    // visit by key
    cout << "coffeeManu[Americano] = "  << coffeeManu["Americano"] << endl;

    // traverse through the map
    for(auto itr = coffeeManu.begin(); itr != coffeeManu.end(); itr++) {
        cout << "Coffee = " << itr->first << " and price = " << itr->second << endl;
    }


    // visit by key
    coffeeManu["Americano"] = 80; 
    cout << "coffeeManu[Americano] = "  << coffeeManu["Americano"] << endl;


    return 0;

}
