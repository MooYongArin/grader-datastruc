#ifndef __STUDENT_H_
#define __STUDENT_H_

template <typename T>
bool CP::queue<T>::operator==(const CP::queue<T> &other) const
{
  // write your code here
  //
  if (this->size() == other.size())
  {
    for (size_t i = 0; i < this->size(); i++)
    {
      if (mData[(mFront + i) % mCap] != other.mData[(other.mFront + i) % other.mCap])
      {
        return false;
      }
      
    }
    return true;
  }
  return false;
  //  YOU CANNOT CALL push or pop
}

#endif