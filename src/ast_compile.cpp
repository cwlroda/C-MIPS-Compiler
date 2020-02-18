#include "ast.hpp"

#include <string>
#include <regex>

static int makeNameUnq=0;

static std::string makeName(std::string base)
{
    return "_"+base+"_"+std::to_string(makeNameUnq++);
}

void CompileRec(
    std::string destReg,    // The name of the register to put the result in
    TreePtr program
){
    std::regex reNum("^-?[0-9]+$");
    std::regex reId("^[a-z][a-z0-9]*$");
    
    if( regex_match( program->type, reNum ) ){
        std::cout<<"const "<<destReg<<" "<<program->type<<std::endl;
        
    }
    else if( regex_match( program->type, reId ) ){
        std::string zero = makeName("zero");
        std::cout<<"const "<<zero<<" 0"<<std::endl;
        std::cout<<"add "<<destReg<<" "<<program->type<<" "<<zero<<std::endl;
    }
    else if(program->type=="Param"){
        std::cout<<"param "<<destReg<<" "<<program->value<<std::endl;
    }
    else if(program->type=="Seq"){
        for(unsigned i=0; i<program->branches.size(); i++){
            CompileRec(destReg, program->branches[i]);
        }   
    }
    else if(program->type=="Output"){
        CompileRec(destReg, program->branches[0]);
        std::cout<<"output "<<destReg<<std::endl;
    }
    else if(program->type=="LessThan"){
        std::string A = makeName("Comparer");
        std::string B = makeName("Compared");
        CompileRec(A, program->branches[0]);
        CompileRec(B, program->branches[1]);
        std::cout<<"lt "<<destReg<<" "<<A<<" "<<B<<std::endl;
    }
    else if(program->type=="Add"){
        std::string A = makeName("Adder");
        std::string B = makeName("Added");
        CompileRec(A, program->branches[0]);
        CompileRec(B, program->branches[1]);
        std::cout<<"add "<<destReg<<" "<<A<<" "<<B<<std::endl;
    }
    else if(program->type=="Sub"){
        std::string A = makeName("Subber");
        std::string B = makeName("Subbed");
        CompileRec(A, program->branches[0]);
        CompileRec(B, program->branches[1]);
        std::cout<<"sub "<<destReg<<" "<<A<<" "<<B<<std::endl;
    }
    else if(program->type=="Assign"){
        std::string zero = makeName("zero");
        std::cout<<"const "<<zero<<" 0"<<std::endl;
        CompileRec(destReg, program->branches[0]);
        std::cout<<"add "<<program->value<<" "<<destReg<<" "<<zero<<std::endl;
    }
    else if(program->type=="Input"){
        std::cout<<"input "<<destReg<<std::endl;
    }
    else if(program->type=="If"){
        std::string zero = makeName("zero");
        std::cout<<"const "<<zero<<" 0"<<std::endl;
        std::string falsee = makeName("false");
        std::string endd = makeName("end");
        std::string branchCondition = makeName("branchCondition");
        CompileRec(branchCondition, program->branches[0]);
        std::cout<<"beq "<<branchCondition<<" "<<zero<<" "<<falsee<<std::endl;
        //True_Statement
        CompileRec(destReg, program->branches[1]);
        std::cout<<"beq "<<zero<<" "<<zero<<" "<<endd<<std::endl;
        //False_Statement
        std::cout<<":"<<falsee<<std::endl;
        CompileRec(destReg, program->branches[2]);
        std::cout<<":"<<endd<<std::endl;
    }
    else if(program->type=="While"){
        std::string zero = makeName("zero");
        std::cout<<"const "<<zero<<" 0"<<std::endl;
        std::string start = makeName("start");
        std::string endd = makeName("end");
        std::cout<<":"<<start<<std::endl;
        CompileRec(destReg, program->branches[0]);
        std::cout<<"beq "<<destReg<<" "<<zero<<" "<<endd<<std::endl;
        CompileRec(destReg, program->branches[1]);
        std::cout<<"beq "<<zero<<" "<<zero<<" "<<start<<std::endl;
        std::cout<<":"<<endd<<std::endl;
    }


    
    // TODO : handle the others
    else{
        throw std::runtime_error("Unknown construct '"+program->type+"'");
    }
}

void Compile(
    TreePtr program
){
    // Create a register to hold the final result
    std::string res=makeName("res");
    
    // Compile the whole thing
    CompileRec(res, program);
    
    // Put the result out
    std::cout<<"halt "<<res<<"\n";
}
