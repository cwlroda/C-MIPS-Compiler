enum Color{red, blue, green = 10, yellow};
enum Sky{clouds, birds, sun, moon};
int main(){
    int x = green;
    switch(x){
        case red: x = 0;
        default: x = 777;
        case blue: x = x + 1;
        case yellow: switch(x+2){
            case sun: x = 5;
            case moon: x = 7;
        }
    }
}



