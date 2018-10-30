//
//  detect.h
//  detect
//
//  Created by keisukeYamagishi on 2017/01/29.
//  Copyright © 2017年 keisukeYamagishi. All rights reserved.
//

#ifndef detect_h
#define detect_h

#include <stdio.h>
#include <vector>
#include <string>
#include <list>

using namespace std;

namespace Detect {
    class detect{
    public:
        //Detect file
        detect(string path);
        vector<string> detectDir(string path, string search);
        vector<string> detectDirs(string option);
        string detectPath;
    private:
        vector<string> listDirectory(const char* path);
        string appendCharacter(const char* character, const char* character2);
        bool isDirectory(const char* path);
        string removeLastSlash(string path);
        bool isSlash(string path);
        vector<string> detectFile(string path, string search);
        string extension(const string &path);
        string uuid();
        string lastPath (const std::string &str);
        std::vector<std::string> split(const std::string &str, char sep);
        std::string removeCharacter(std::string str, std::string remove);
        std::string emurateCharactor(std::string str, list<string> lists);
    };
}

#endif
