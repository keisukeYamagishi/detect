//
//  option.cpp
//  detect
//
//  Created by keisukeYamagishi on 2017/01/30.
//  Copyright © 2017年 keisukeYamagishi. All rights reserved.
//

#include "option.h"
#include <iostream>
#include <cstring>

namespace Detect {
    
    void option::setOption(int argc, const char **argv){
        
        int i=0;
        for(; i<argc; ++i){
            if(strcmp( argv[i] , "-s")==0){
                
                options.search = string(argv[i+1]);
                    
            }else if(strcmp(argv[i] , "-t")==0){

                options.option_c = string(argv[i+1]);

            }else if(strcmp(argv[i], "--v")==0){
                options.option_c = "--v";
            }else if(strcmp(argv[i], "--version") == 0){
                options.option_c = "--version";
            }
        }
    }
}
