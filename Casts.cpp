#include<iostream>

class Parent
{
public:
  virtual void name()
  {
      std::cout<<"Hello from parent!"<<std::endl;
  }
  void called()
  {
      ++times_called;
      std::cout<<"I've been called "<< times_called<< " times"<<std::endl;
  }

private:
    inline static unsigned times_called = 0;
};

class Child :public Parent
{
public:
    void name() override
    {
        std::cout<<"Hello from child!"<<std::endl;
    }

};

class Sibling: public Parent
{
public:
    void name() override
    {
        std::cout<<"Hello from Sibling!"<<std::endl;
    }

};
int main()
{
//Parent* joe = new Child; //polymorphism
//joe->name()

//Child* jane = new Child;
//Parent* bob = dynamic_cast<Parent*> (jane);
//bob->name();
//bob->called(); //cast from child to parent works (upcast)


//Parent* bob = new Parent;
//Child* jane = dynamic_cast<Child*> (bob);
//jane->name();
//jane->called(); //cast from parent to child doesn't work (downcast)

//Child* ann = new Child;
//Sibling* alice = dynamic_cast<Sibling*> (ann);
//
//if (alice)
//    std::cout<<"Conversion is valid"<<std::endl;
//alice->name(); //cast from sibling to child doesn't work

//but

Parent* bob = new Child;
bob->name();
Child* andy = dynamic_cast<Child*>(bob);
andy->name(); //cast from parent to child works (downcast) if parent points to a child


}