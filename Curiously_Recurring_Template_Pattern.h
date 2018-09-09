/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Curiously_Recurring_Template_Pattern.h
 * Author: Eagleye
 *
 * Created on September 9, 2018, 2:29 AM
 */

#ifndef CURIOUSLY_RECURRING_TEMPLATE_PATTERN_H
#define CURIOUSLY_RECURRING_TEMPLATE_PATTERN_H

#include <vector>
#include <iostream>

class Curiously_Recurring_Template_Pattern {
public:

    struct Shape {
        virtual Shape* Clone() = 0;
        virtual ~Shape() = default;
    };

    template <typename T>
    struct ShapeCRTP : public Shape {

        virtual Shape* Clone() override {
            return new T(*static_cast<T*> (this));
        }
    };

    struct Square : public ShapeCRTP<Square> {
        int x = 1;
    };

    struct Rectangle : public ShapeCRTP<Rectangle> {
        int x = 1;
        int y = 2;
    };

    struct Triangle : public ShapeCRTP<Triangle> {
        int x = 1;
        int y = 2;
        int z = 3;
    };

    void execute();

};

void Curiously_Recurring_Template_Pattern::execute() {
    vector<Shape*> v;
    v.push_back(new Square);
    v.push_back(new Rectangle);
    v.push_back(new Triangle);

    int i = 0;
    for (auto s : v) {
        Shape* c = s->Clone();
        cout << "trial - " << i << endl;
        cout << dynamic_cast<Rectangle*> (c) << endl;
        cout << dynamic_cast<Square*> (c) << endl;
        cout << dynamic_cast<Triangle*> (c) << endl;
        i++;

    }

}



#endif /* CURIOUSLY_RECURRING_TEMPLATE_PATTERN_H */

