//
//  main.cpp
//  detect
//
//  Created by keisukeYamagishi on 2017/03/05.
//  Copyright © 2017年 keisukeYamagishi. All rights reserved.
//

#include <iostream>
#include "Detect/detect.h"
#include "Detect/option.h"

using namespace std;

#define DETECT_VERSION "1.1.0"

int main(int argc, const char * argv[]) {

    Detect::option o = *new Detect::option;
    o.setOption(argc, argv);

    if(argv[1]==NULL){
        cout << "usage: detect [--version] [<path>] [-s search=value]" << endl;
        cout << "\n";
        cout << "These are common detect commands used in various situations:" << endl;
        cout << "\n";
        cout << "detect version: " << DETECT_VERSION << endl;
        cout << "\n";
        cout << "option: " << endl;
        cout << "\n";
        cout << "-s set search value " << endl;
        cout << "--v output detedt version number" << endl;
        cout << "\n";
        cout << "Regars !" << endl;
        cout << "\n";
    }else if(o.options.option_c == "--v"
        || o.options.option_c == "--version"){
        cout << "detect version: " << DETECT_VERSION << endl;
    }else{
        std::string path = string(argv[1]);
        Detect::detect det = Detect::detect(path);
        vector<string> result = det.detectDirs(o.options.search);
    }
    return 0;
}
