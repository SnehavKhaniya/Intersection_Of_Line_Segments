#include<bits/stdc++.h>

using namespace std;

class Point{
    public:
    int x;
    int y;
    Point(int x = 0, int y = 0){
        this->x = x;
        this->y = y;
    }
};

int direction(Point Pi,Point Pj,Point Pk){

    Point PiPk;
    PiPk.x = (Pk.x - Pi.x);
    PiPk.y = (Pk.y - Pi.y);

    Point PiPj;
    PiPj.x = (Pj.x - Pi.x);
    PiPj.y = (Pj.y - Pi.y);

    int d = (PiPk.x * PiPj.y) - (PiPk.y * PiPj.x);
    
    return d;
}

bool OnLineSegement(Point Pi,Point Pj,Point Pk){
    if((min(Pi.x,Pj.x) <= Pk.x <= max(Pi.x, Pj.x)) && (min(Pi.y,Pj.y) <= Pk.y <= max(Pi.y, Pj.y))){
        return true;
    }
    return false;
}

bool intersection(Point Pi, Point Pj, Point Pk, Point Pl){
    int dk = direction(Pi,Pj,Pk);
    int dl = direction(Pi,Pj,Pl);
    int di = direction(Pk,Pl,Pi);
    int dj = direction(Pk,Pl,Pj);

    if((dk * dl) < 0 &&  (di * dj) < 0){
        return true;
    }
    else if(di < 0 && OnLineSegement(Pk,Pl,Pi)){
        return true;
    }
    else if(dj < 0 && OnLineSegement(Pk,Pl,Pj)){
        return true;
    }
    else if(dk < 0 && OnLineSegement(Pi,Pj,Pk)){
        return true;
    }
    else if(dl < 0 && OnLineSegement(Pi,Pj,Pl)){
        return true;
    }

    return false;
}
int main(){
    Point Pi(1,1);
    Point Pj(4,8);
    Point Pk(2,6);
    Point Pl(6,3);
    
    // Pi.x = 1;
    // Pi.y = 1;
    // Pj.x = 4;
    // Pj.y = 8;
    // Pk.x = 2;
    // Pk.y = 6;
    // Pl.x = 6;
    // Pl.y = 3;
    if(intersection(Pi,Pj,Pk,Pl)){
        cout << "Line segment intersect "<< endl;
    }
    else{
        cout << "Line segment do not intersect" << endl;
    }

    return 0;
}


