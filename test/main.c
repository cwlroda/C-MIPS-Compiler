int main(){
    int x = 0;
    switch(x+1){
        case 1: x = 0;
        default: x = 777;
        case 2: switch(x+2){
            case 1: x = 7;
            case 2: x = 8;
        }
    }
}