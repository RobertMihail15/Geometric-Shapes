#include <iostream>
#include <cmath>
#include <vector>
#include <iomanip>
using namespace std;
class Point{
private:
    double x,y;
public:
    Point(){ 
        x=0;
    y=0;
    }
    Point(double X,double Y){
x=X;
y=Y;
    }
    double getX() const {
        return x;
    }
    double getY() const {
        return y;
    }
    void setX(double X){
        x=X;
    }
    void setY(double Y){
        y=Y;
    }
    Point operator -(const Point& a)const
    {
        Point b(abs(x-a.x),abs(y-a.y));
        return b;
    }
};
class Shape{
protected:
    Point mFirst,mSecond;
    string mName;
public:
    Shape(){
        Point mFirst(0,0);
        Point mSecond(0,0);
    }
    Shape(Point a, Point b){
        mFirst=a;
        mSecond=b;
    }
    Point getFirst() const{
        return mFirst;
    }
    Point getSecond() const{
        return mSecond;
    }
    void setFirst(Point a){
        mFirst=a;
    }
    void setSecond(Point b){
        mSecond=b;
    }
    string getName() const{
        return mName;
    }
    void setName(string name){
        mName=name;
    }
    virtual double getPerimeter()const=0;
    virtual double getArea()const=0;
};
class Quadrilateral: public Shape{
public:
    Quadrilateral(){
        Point a(0,0);
        setFirst(a);
        setSecond(a);
        mName="Unknown";
    }
    Quadrilateral(Point a, Point b,string name){
        setFirst(a);
        setSecond(b);
        mName=name;
    }
    double getLength() const{
        Point b(getFirst()-getSecond());
        return b.getX();
    }
    double getWidth() const{
        Point b(getFirst()-getSecond());
        return b.getY();
    }
     double getPerimeter() const override{
        return (getLength()*2+getWidth()*2);
    }
     double getArea() const override{
        return getWidth()*getLength();
    }
};
class Circle: public Shape{
private:
    double mRadius;
public:
    Circle(){
        Point a(0,0);
        setFirst(a);
        setSecond(a);
        mRadius=0;
        mName="Unknown";
    }
    Circle(Point a, double b){   
        Point c(0,0);
        mFirst=a;
        mSecond=c;
        mRadius=b;
        mName="cerc";
    }
     double getPerimeter()const override{
        return (2*M_PI*mRadius);
    }
     double getArea()const  override{
        return (M_PI*mRadius*mRadius);
    }
    void setRadius(double a){
        mRadius=a;
    }
    double getRadius() const{
        return mRadius;
    }
};
int main() {
int n,i,j,sw=0;
double min,max,a,b,r,d;
vector<Quadrilateral>v;
vector<Circle>y;
vector<double>per;
vector<double>arie;
cin>>n>>min>>max;
    if (min>max||n<1||n>500){
        cout<<"Valoare de intrare invalida";
    }
    else{
        for(i=0;i<n;i++)
        {
            string c;
            cin>>c;
            if(c=="dreptunghi")
            { cin>>a>>b>>r>>d;
            if(a<-1000||a>1000||b<-1000||b>1000||r<-1000||r>1000||d<-1000||d>1000)
                sw=1;
              Point q(a,b);
                Point w(r,d);
                Quadrilateral e(q,w,c);
                v.push_back(e);
                per.push_back(e.getPerimeter());
                arie.push_back(e.getArea());
            }
            if (c=="patrat")
            {
                cin>>a>>b>>r>>d;
                if(a<-1000||a>1000||b<-1000||b>1000||r<-1000||r>1000||d<-1000||d>1000)
                    sw=1;
                Point q(a,b);
                Point w(r,d);
                Quadrilateral e(q,w,c);
                v.push_back(e);
                per.push_back(e.getPerimeter());
                arie.push_back(e.getArea());
            }
            if(c=="cerc")
            {
                cin>>a>>b>>d;
                if(a<-1000||a>1000||b<-1000||b>1000||d<-1000||d>1000)
                    sw=1;
                Point q(a,b);
                Circle e(q,d);
                y.push_back(e);
                per.push_back(e.getPerimeter());
                arie.push_back(e.getArea());
            }
        }
        for(i=0;i<arie.size()-1;i++)
          for(j=i+1;j<arie.size();j++)
          {
              if (arie[i]>arie[j])
              {
                  a=arie[i];
                  arie[i]=arie[j];
                  arie[j]=a;
                  a=per[i];
                  per[i]=per[j];
                  per[j]=a;
              }
              if(arie[i]==arie[j])
              {
                  if(per[i]>per[j])
                  {
                      a=arie[i];
                      arie[i]=arie[j];
                      arie[j]=a;
                      a=per[i];
                      per[i]=per[j];
                      per[j]=a;
                  }
              }
          }
        cout<<fixed<<setprecision(6);
          if(sw==1)
              cout<<"Valoare de intrare invalida";
          else {
              for (i = 0; i < arie.size() - 1; i++) {
                  if (arie[i] != arie[i + 1]) {
                      for (j = 0; j < v.size(); j++)
                          if (v[j].getArea() == arie[i]) {
                              cout << v[j].getName() << " " << v[j].getArea() << " " << v[j].getPerimeter() << endl;
                              Point q(0, 0);
                              Quadrilateral e(q, q, "patrat");
                              v[j] = e;
                          }
                      for (j = 0; j < y.size(); j++)
                          if (y[j].getArea() == arie[i]) {
                              cout << y[j].getName() << " " << y[j].getArea() << " " << y[j].getPerimeter() << endl;
                              Point q(0, 0);
                              Circle e(q, 0);
                              y[j] = e;
                          }
                  }
                  if (arie[i] == arie[i + 1]) {
                      for (j = 0; j < v.size(); j++)
                          if (v[j].getPerimeter() == per[i]) {
                              cout << v[j].getName() << " " << v[j].getArea() << " " << v[j].getPerimeter() << endl;
                              Point q(0, 0);
                              Quadrilateral e(q, q, "patrat");
                              v[j] = e;
                          }
                      for (j = 0; j < y.size(); j++)
                          if (y[j].getPerimeter() == per[i]) {
                              cout << y[j].getName() << " " << y[j].getArea() << " " << y[j].getPerimeter() << endl;
                              Point q(0, 0);
                              Circle e(q, 0);
                              y[j] = e;
                          }

                  }
              }
              for (j = 0; j < v.size(); j++)
                  if (v[j].getArea() == arie[arie.size() - 1])
                      cout << v[j].getName() << " " << v[j].getArea() << " " << v[j].getPerimeter() << endl;

              for (j = 0; j < y.size(); j++)
                  if (y[j].getArea() == arie[arie.size() - 1])
                      cout << y[j].getName() << " " << y[j].getArea() << " " << y[j].getPerimeter() << endl;
          }

    }
    return 0;
}
