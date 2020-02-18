#include "ast.hpp"

#include <regex>

int32_t Interpret(
    InterpretContext &context, // Contains the parameters and variable bindings
    TreePtr program
){
    std::regex reNum("^-?[0-9]+$");
    std::regex reId("^[a-z][a-z0-9]*$");
    
    if( regex_match(program->type, reNum) ){
        return std::atol(program->type.c_str());

    }
    // TODO : Check for things matching reId - DONE
    else if( regex_match(program->type, reId) ){
        return context.bindings[program->type];
    }
    else if(program->type=="Param"){
        unsigned index=atol(program->value.c_str());
        auto value=context.params.at(index);
        return value; 
    }
    else if(program->type=="Output"){
        int32_t val=Interpret(context, program->branches.at(0));
        std::cout<<val<<std::endl;
        return val;
    }
    else if(program->type == "Input"){
        int32_t val;
        std::cin>>val;
        return val;
    }
    else if(program->type == "LessThan"){
        int32_t A=Interpret(context, program->branches.at(0));
        int32_t B=Interpret(context, program->branches.at(1));
        return A<B;
    }
    else if(program->type == "Add"){
        int32_t A=Interpret(context, program->branches.at(0));
        int32_t B=Interpret(context, program->branches.at(1));
        return A+B;
    }
    else if(program->type == "Sub"){
        int32_t A=Interpret(context, program->branches.at(0));
        int32_t B=Interpret(context, program->branches.at(1));
        return A-B;
    }
    else if(program->type == "Assign"){
        int32_t V=Interpret(context, program->branches.at(0));
        context.bindings[program->value] = V;
        return V;
    }
    else if(program->type == "Seq"){
        if(program->branches.size() == 0){
            throw std::runtime_error("Seq needs at least one operand");
        }
        int32_t val = 0;
        //std::cout << "PROGBRANCHSIZE"<< " " << program->branches.size() << std::endl;
        for(int i=0; i<program->branches.size(); i++){
            val = Interpret(context, program->branches.at(i));
        }
        //std::cout << "VAL" << val << std::endl;
        return val;
    }
    else if(program->type == "If"){
        if(Interpret(context, program->branches.at(0))!=0){
            return Interpret(context, program->branches.at(1));
        }
        else{
            return Interpret(context, program->branches.at(2));
        }
    }
    else if(program->type == "While"){
        while(Interpret(context, program->branches.at(0))!=0){
            Interpret(context, program->branches.at(1));
        }
        return 0;
    }
    // TODO: Handle other constructs  
    else{
        throw std::runtime_error("Unknown construct '"+program->type+"'");
    }
}
