/* 
 * File:   example.cpp
 * Author: deanmiller
 *
 * Created on November 28, 2015, 7:23 PM
 * This is untested but usage should be something like this
 */

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>

#include "gcParser.h"

using namespace std;

int main(int argc, char** argv) {
    
   gcParser parse();
   
    //open the source file and begin reading lines
    ifstream infile("myfile.gcode");

    string line;
    while (getline(infile, line))
    {
        vector<cmd> cmds; //vector to hold the commands
        parse.parseBlock(line, cmds); //parse the block into an order vector of cmd structs

        vector<cmd>::iterator v = cmds.begin();
           while( v != cmds.end()) {
               cmd c = *v;

               //echo the command and any parameters
               cout << "Command: " << c.letter << c.number << endl;
               for(auto elem : c.params)
               {
                  std::cout << elem.first << " " << elem.second << "\n";
               }

              v++;
           }
    }
    
    return 0;
}

