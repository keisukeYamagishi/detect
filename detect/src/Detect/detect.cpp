//
//  detect.cpp
//  detect
//
//  Created by keisukeYamagishi on 2017/01/29.
//  Copyright © 2017年 keisukeYamagishi. All rights reserved.
//

#include "detect.h"
#include <iostream>
#include <sstream>
#include <sys/types.h>
#include <dirent.h>
#include <sys/stat.h>
#include <unistd.h>
#include <cstring>

namespace Detect {

    detect::detect(string path){
        this->detectPath = path;
    }

    vector<string> detect::detectDirs(string option){
      cout << "Search: " << option << "\n";
        return this->detectDir(this->detectPath, option);
    }

    vector<string> detect::detectDir(string path, string search){
        return this->detectFile(path, search);
    }

    vector<string> detect::detectFile(string path, string search){

        vector<string> results;
        vector<string> dirs;
        vector<string> lists = listDirectory(path.c_str());

        for(auto itr=lists.begin(); itr != lists.end(); ++itr){

            string full_path = *itr;

            if(isDirectory(full_path.c_str())){

                dirs.push_back(full_path);
                if(full_path.find(search) != string::npos){
                    cout << "detect:  " <<  full_path << endl;
                    results.push_back(full_path);
                }
            }else{
                if(full_path.find(search)!=string::npos){
                    cout << "detect:  " << full_path << endl;
                    results.push_back(full_path);
                }
            }
        }
        for(auto itr = dirs.begin(); itr != dirs.end(); ++itr){
            string dir_path = *itr;
            vector<string> sub_dir = detectFile(dir_path, search);
            results.insert(results.end(), sub_dir.begin(), sub_dir.end());
        }
        return results;
    }

    vector<string> detect::listDirectory(const char *path){
        vector<string> dir;
        DIR* dp=opendir(path);
        if (dp!=NULL)
        {
            struct dirent* dent;
            do{
                dent = readdir(dp);
                if (dent!=NULL){
                    string fullPath = "";
                    string path_str = string(path);
                    if (strcmp(path, "/")!=0) {
                        fullPath  = string(path) + "/";
                    }else{
                        fullPath = string(path);
                    }
                    fullPath += string(dent->d_name);

                    if( strcmp(dent->d_name,".")!=0
                       && strcmp(dent->d_name,"..")!=0){
                        dir.push_back(fullPath);
                    }
                }
            }while(dent!=NULL);
            closedir(dp);
        }
        return dir;
    }

    string detect::appendCharacter(const char* character, const char* character2){
        size_t len = strlen(character) + strlen(character);
        char *buf = (char *)malloc(len + 1);
        buf[len] = 0;
        strcpy(buf, character);
        strcat(buf, character2);
        free(buf);
        return string(buf);
    }

    bool detect::isDirectory(const char *path){
        struct stat stat_buf;

        stat(path, &stat_buf);
        if ((stat_buf.st_mode & S_IFMT) == S_IFDIR
            && strcmp(lastPath(string(path)).c_str(), ".")
            && strcmp(lastPath(string(path)).c_str(), "..")) {
            return true;
        }
        return false;
    }

    string detect::extension(const string &path) {
        string ext;
        size_t pos1 = path.rfind('.');
        if(pos1 != string::npos){
            ext = path.substr(pos1+1, path.size()-pos1);
            string::iterator itr = ext.begin();
            while(itr != ext.end()){
                *itr = tolower(*itr);
                itr++;
            }
            itr = ext.end()-1;
            while(itr != ext.begin()){
                if(*itr == 0 || *itr == 32){
                    ext.erase(itr--);
                }
                else{
                    itr--;
                }
            }
        }
        return ext;
    }

    string detect::lastPath(const std::string &str){

        vector<string> strs = split(str, '/');

        return strs[strs.size()-1];

    }

    std::vector<std::string> detect::split(const std::string &str, char sep)
    {
        std::vector<std::string> splits;
        std::stringstream string_str(str);
        std::string buffer;
        while( std::getline(string_str, buffer, sep) ) {
            if(buffer!=""){
                splits.push_back(buffer);
            }
        }
        return splits;
    }

    bool detect::isSlash(string path){
        string last = path.substr(path.size()-1);
        if(last.find("/") != string::npos){
            return true;
        }
        return false;
    }

    string detect::removeLastSlash(string path){
        path.erase(path.size()-1,1);
        return path;
    }

}
