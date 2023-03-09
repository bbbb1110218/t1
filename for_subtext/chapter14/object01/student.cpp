#include "student.h"

double Student::Average()const{
    if(scores.size()>0)
        return scores.sum()/scores.size();
    else
        return 0.0;

}

const string& Student::Name()const{
    return name;
}


double & Student::operator[](int n)  
{
    return scores[n];
}

double Student::operator[](int n)const      
{
    return scores[n];
}

istream& operator>>(istream&is,Student &stu){
    is >> stu.name;
    return is;
}

istream& getline(istream&is,Student&stu){
    getline(is,stu.name);
    return is;
}


ostream & operator<<(ostream&os,const Student &stu){
    os <<"Score for "<< stu.name << ":\n";
    int lim=stu.scores.size();
    if(lim >0){
        int i;
        for(i=0;i<lim;i++){
            os << stu.scores[i] << " ";
            if(i % 5==4) os <<"\n";
        }
        if(i % 5 !=0) os << endl;
    }else{
        os << "empty score" << endl; 
    }
    return os;
    
} 
