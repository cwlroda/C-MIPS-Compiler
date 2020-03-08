#ifndef AST_CONTEXT_HPP
#define AST_CONTEXT_HPP

#include <string>
#include <vector>
#include <map>
#include <memory>

class Context{
    public:
        Context();

    private:
        std::vector<std::map<std::string, std::string> > scope;
        std::vector<int> params;
        std::map<std::string, int> bindings;
        int stack[];

};

#endif