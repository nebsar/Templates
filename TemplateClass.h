/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   TemplateClass.h
 * Author: Eagleye
 *
 * Created on September 8, 2018, 11:57 PM
 */

#ifndef TEMPLATECLASS_H
#define TEMPLATECLASS_H

#include <cstdlib>
#include <iostream>

using namespace std;

template <class T>
class TemplateClass {
public:

    TemplateClass(T a, T b) : first(a), second(b) {
    }
    T first, second;
    T bigger();
};

template <class T>
T TemplateClass<T>::bigger() {
    return first > second ? first : second;
}

#endif /* TEMPLATECLASS_H */

