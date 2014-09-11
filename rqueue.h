#ifndef R_QUEUE_H_
#define R_QUEUE_H_

#include <exception>
#include <string>

class rexception : public ::std::exception
{
public:

  rexception(const ::std::string& msg)
    : msg_(msg)
  {
    // empty
  }

  virtual ~rexception() throw()
  {
    // empty
  }

  virtual const char* what() const throw()
  {
    return msg_.c_str();
  }

private:

  ::std::string msg_;

}; // rexception

template<typename T>
class rqueue
{
public:

  rqueue(size_t size)
    : total_(size)
    , size_(0)
    , queue_(NULL)
    , index_(0)
  {
    // should make sure size greater than 2
    queue_ = new T[size];
  }

  ~rqueue()
  {
    if (queue_)
    {
      delete [] queue_;
      queue_ = NULL;
    }
  }

  bool empty() const
  {
    return (size_ == 0);
  }

  size_t size() const
  {
    return size_;
  }

  void push(const T& rhs)
  {
    if (size_ >= total_)
    {
      throw rexception("rqueue up of bound");
    }
    queue_[index_] = rhs;
    ++size_;
    ++index_;
    if (index_ >= total_) index_ = 0;
  }

  void pop()
  {
    if (size_ < 1)
    {
      throw rexception("rqueue below of bound");
    }
    --size_;
  }

  T& front()
  {
    if(size_ < 1)
    {
      throw rexception("rqueue empty");
    }
    size_t idx = size_ > index_ ? (total_ - size_ + index_) : (index_ - size_);
    return queue_[idx];
  }

  const T& front() const
  {
    return this->front();
  }

  T& back()
  {
    if(size_ < 1)
    {
      throw rexception("rqueue empty");
    }
    size_t idx = index_ > 0 ? (index_ - 1) : (total_ -1);
    return queue_[idx];
  }

  const T& back() const
  {
    return this->back();
  }

private:

  size_t total_;  // total elements the queue can hold
  size_t size_;   // current size of the queue

  T*     queue_;  // queue storage
  size_t index_;  // the index of the position for the next push

};  // rqueue

#endif // R_QUEUE_H_

