# gcParser

CURRENTLY IN PROGRESS

a C++ class that parses a block of gcode and returns a vector of cmd structs (as defined in gcParser.h):
struct cmd{
    char letter;
    float number;
    int priority;
    std::map<char, float> params;
    }

This struct will contain the command letter (G, M, or Null for parameters with no associated master command), as well as the command number (e.g. 1 for G1) and the command priority (lower number for higher priority commands), and a std::map of parameters passed to the command.

The returned comand vector will be sorted in order of command priority (defined here http://linuxcnc.org/docs/html/gcode/overview.html)

Make sure you have C++11, g++-4.7 or greater, and the boost regex library installed. To compile, make sure to inclde -lboost_regex in your compilation line.

The only thing this has been tested with is ARM embedded debian linux running on Beaglebone Black.
