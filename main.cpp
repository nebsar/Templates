/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Eagleye
 *
 * Created on September 8, 2018, 11:57 PM
 */

#include <cstdlib>
#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>

#include "TemplateClass.h"
#include "Curiously_Recurring_Template_Pattern.h"

using namespace std;

/*
 * 
 */

//template <class T>
//class TemplateClass1 {
//public:
//
//    TemplateClass1(T a, T b) : first(a), second(b) {
//
//    }
//    T first, second;
//    T bigger();
//};
//
//template <class T>
//T TemplateClass1<T>::bigger() {
//    return first > second ? first : second;
//}

template<typename It, typename Pred>
bool Contains(It first, It last, Pred pred) {

    for (; first < last; first++) {
        if (pred(*first)) {
            return true;
        }
    }

    return false;
}

bool hasTwo(int const& i) {
    return i == 2;
}

struct S {

    bool operator()(int const& i) const {
        return i == 2;
    }
};

int main(int argc, char** argv) {

    TemplateClass<int> t(100, 50);
    cout << t.bigger();

    vector<int> v = {5, 4, 3, 2, 8, 9};

    Contains(v.begin(), v.end(), hasTwo);

    cout << boolalpha << Contains(v.begin(), v.end(), [](int const& i) {
        return i == 2;
    }) << endl;

    cout << boolalpha << Contains(v.begin(), v.end(), S()) << endl;
    
    Curiously_Recurring_Template_Pattern crtp;
    
    crtp.execute();

    return 0;
}

