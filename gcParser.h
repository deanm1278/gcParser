/* 
 * File:   gcParser.h
 * Author: deanmiller
 *
 * Created on November 27, 2015, 9:38 AM
 */

#include <vector>
#include <map>

#ifndef GCPARSER_H
#define	GCPARSER_H

#define NO_LETTER '\0'

typedef struct cmd{
    char letter;
    float number;
    int priority;
    std::map<char, float> params;
    
    bool operator < (const cmd& str) const
    {
        return (priority < str.priority);
    }
} cmd;

class gcParser {
public:
    gcParser();
    int parseBlock(std::string block, std::vector<cmd> &cmds);
    
    static const char paramLetters[23];
    static const char paramCmds[3];
    
    virtual ~gcParser();
private:
    
    std::map <char, std::map<float, int>> order;

};

#endif	/* GCPARSER_H */

