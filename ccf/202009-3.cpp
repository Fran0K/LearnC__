//
// Created by Frank Lin on 14/9/21.
//

int notFunc(int i){
    if (i ==1){
        return 0;
    } else{
        return 1;
    }
}

int andFUnc(int k){
    int temp = 0;
    int ans = 0;
    for(int j = 0; j<k; ++j){
        if (j ==0){
           cin >> ans;
        } else{
            cin >> temp;
            ans = (ans && emp);
        }
    }
    return ans;
}

int orFUnc(int k){
    int temp = 0;
    int ans = 0;
    for(int j = 0; j<k; ++j){
        if (j ==0){
            cin >> ans;
        } else{
            cin >> temp;
            ans = (ans || emp);
        }
    }
    return ans;
}
