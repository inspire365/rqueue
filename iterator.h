#ifndef CAN_ITERATOR_H__
#define CAN_ITERATOR_H__

namespace can { namespace common {

template<typename T>
class iterator
{
public:

  virtual ~ iterator() { }
  virtual void first() = 0;
  virtual void next() = 0;
  virtual bool done() const = 0;
  virtual const T& current() const = 0;


protected:

  iterator() { }

}; // iterator

}} // ::can::common

#endif // CAN_ITERATOR_H__

