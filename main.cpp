#include <iostream>
#include "rqueue.h"

using namespace std;

using ::can::common::rqueue;
using ::can::common::rqueue_iterator;

int main()
{

  rqueue<int> rq(5);

  cout << "now insert to rqueue" << endl;
  size_t i = 0;
  try
  {
    for(i = 1; i < 7; ++i)
    {
      rq.push(i);
    }
  }
  catch(const exception& e)
  {
    cout << "push exception i = " << i << " " <<  e.what() << endl;
  }

  rq.pop();
  rq.pop();
  rq.pop();
  rq.pop();
  rq.push(100);
  rq.push(101);
  rq.push(102);


  cout << "iterator output: " << endl;
  rqueue_iterator<int> it(rq);
  for(it.first(); !it.done(); it.next())
  {
    cout << "item: " << it.current() << endl;
  }


  cout << "now pop out from rqueue" << endl;
  try
  {
    for(i = 1; i < 7; ++i)
    {
      cout << rq.front() << endl;
      rq.pop();
    }
  }
  catch(const exception& e)
  {
    cout << "pop exception i = " << i << " " <<  e.what() << endl;
  }

  return 0;
}


