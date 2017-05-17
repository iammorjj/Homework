#ifndef WGRLIB_H_INCLUDED
#define WGRLIB_H_INCLUDED

#include <bits/stdc++.h>

using namespace std;

// module
void go(); // run module
void stop(); // stop module
void handler(const string& input,
    string& option, int& depth, string& site); // handle user commands

// db
void save(const char* path = "./DataBase.xml"); // save changes
void load(const char* path = "./DataBase.xml"); // load db
void clr(const char* path = "./DataBase.xml"); // clear db

// graph
void add(const string& site); // add vertex
void area(const string& site, int depth); // advice by site
void dfs(const string& site, int depth); // make group by site
void top(int i = 3); // top list
void updTop(); // update top

#endif // WGRLIB_H_INCLUDED
