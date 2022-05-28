//
// Created by Frank Lin on 29/4/2022.
//

int xx(int a, int b){
    int x = a;
    int y= b;
    while(x==y){
        if(x>y){
            x = x-y;
        }
        if(x<y){
            y = y-x;
        }
    }
    return  x;
}

int main(){
    int a = xx(2437, 875);
}

