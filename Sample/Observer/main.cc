#include <limits>
#include <iostream>
#include "base/observer_list.h"

#pragma comment(lib,"base.lib")
class MyWidget {
 public:
  class Observer {
   public:
    virtual void OnFoo(MyWidget* w) = 0;
    virtual void OnBar(MyWidget* w, int x, int y) = 0;
  };

  void AddObserver(Observer* obs) {
    observer_list_.AddObserver(obs);
  }

  void RemoveObserver(Observer* obs) {
    observer_list_.RemoveObserver(obs);
  }

  void NotifyFoo() {
    FOR_EACH_OBSERVER(Observer, observer_list_, OnFoo(this));
  }

  void NotifyBar(int x, int y) {
    FOR_EACH_OBSERVER(Observer, observer_list_, OnBar(this, x, y));
  }
  std::string GetName()
  {
    return "MyWidget";
  }

 private:
  ObserverList<Observer> observer_list_;
};

class MyObs : public MyWidget::Observer
{
  virtual void OnFoo(MyWidget* w)
  {
    std::cout << w->GetName() << " MyObs OnFoo" << std::endl;
  }
  virtual void OnBar(MyWidget* w, int x, int y)
  {
    std::cout << w->GetName() << " MyObs OnBar" << std::endl;
  }
};
class MyObs2 : public MyWidget::Observer
{
  virtual void OnFoo(MyWidget* w)
  {
    std::cout << w->GetName() << " MyObs2 OnFoo" << std::endl;
  }
  virtual void OnBar(MyWidget* w, int x, int y)
  {
    std::cout << w->GetName() << " MyObs2 OnBar" << x << y <<std::endl;
  }
};

int main()
{
  MyWidget mw;
  MyObs  myobs;
  MyObs2 myobs2;
  mw.AddObserver(&myobs);
  mw.AddObserver(&myobs2);
  mw.NotifyBar(3,3);
  mw.NotifyFoo();
  return 0;
}