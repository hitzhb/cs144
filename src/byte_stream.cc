#include <cstddef>
#include <cstdint>
#include <stdexcept>
#include <iostream>
#include <string_view>

#include "byte_stream.hh"

using namespace std;

ByteStream::ByteStream( uint64_t capacity ) : capacity_( capacity ) {}

void Writer::push( string data )
{
  // Your code here.
  // (void)data;
  // cout << "push() begin..." << endl;
  uint64_t sz = data.size();
  uint64_t input_num = min(sz, avl_sz);
  // cout << "avl_sz: " << avl_sz << endl;
  // if(sz <= avl_sz) {
      // for(uint64_t i = 0; i < input_num; ++i) {
      //     buffer_.push_front(data[i]);
      // }
  buffer_.append(data.begin(), data.begin() + static_cast<int>(input_num));
      total_write_bytes += input_num;
      avl_sz -= input_num;
  // } else {
  //     for(uint64_t i = 0; i < avl_sz; ++i) {
  //         buffer_.push_front(data[i]);
  //     }
  //     total_write_bytes += avl_sz;
  //     avl_sz = 0;
  // }
  // cout << "push() end" <<endl;
}

void Writer::close()
{
  // Your code here.
  // cout << "close()" << endl;
  reach_end_ = true;
}

void Writer::set_error()
{
  // Your code here.
  // cout << "set_error()" << endl;
  set_error_ = true;
}

bool Writer::is_closed() const
{
  // Your code here.
  // cout << "is_closed()" << endl;
  return reach_end_;
}

uint64_t Writer::available_capacity() const
{
  // Your code here.
  // avl_cap = capacity_ - total_write_bytes;
  // cout << "available_capacity()" << endl;
  return avl_sz;
}

uint64_t Writer::bytes_pushed() const
{
  // Your code here.
  // cout << "bytes_pushed()" << endl;
  return total_write_bytes;
}
// string str;
string_view Reader::peek() const
{
  // Your code here.
  // string str(buffer_.rbegin(), buffer_.rbegin() + static_cast<std::ptrdiff_t>(bytes_buffered()) - 1);
  // string str(buffer_.end() - static_cast<std::ptrdiff_t>(bytes_buffered()), buffer_.end());
  // string_view msg(buffer_.rbegin(), static_cast<std::ptrdiff_t>(bytes_buffered()) - 1);
  // cout << str << endl;
  // string msg(str);
  // return str;
  // cout << "peek() begin..." << endl;
  // shared_ptr<string> str = "";
  // str = string().assign(buffer_.rbegin(), buffer_.rbegin() + static_cast<std::ptrdiff_t>(bytes_buffered()));
  // string_view msg(str);
  // cout << msg << endl;
  // string_view msg(buffer_.rbegin(), buffer_.rbegin() + static_cast<ptrdiff_t>(bytes_buffered()));
  // cout << "peek() will return msg" << endl;
  // static string str;
  // str = {};
  // str.assign(buffer_.rbegin(), buffer_.rbegin() + static_cast<ptrdiff_t>(bytes_buffered()));
  // string_view msg(str);
  return {buffer_.begin(), buffer_.end()};
  // return msg;
}

bool Reader::is_finished() const
{
  // Your code here.
  // return Writer::is_closed() && (total_write_bytes == total_read_bytes);
  // cout << "is_finished()" << endl;
  return reach_end_ && (total_write_bytes == total_read_bytes);
}

bool Reader::has_error() const
{
  // Your code here.
  // cout << "has_error()" << endl;
  return set_error_;
}

void Reader::pop( uint64_t len )
{
  // Your code here.
  // (void)len;
  // cout << "pop()" << endl;
  uint64_t output_num = min(len, bytes_buffered());
  // for(uint64_t i = 0; i < output_num; ++i) {
  //   buffer_.erase(); 
  // }
  buffer_.erase(buffer_.begin(), buffer_.begin() + static_cast<int>(output_num));
    avl_sz += output_num;
    total_read_bytes += output_num;
}

uint64_t Reader::bytes_buffered() const
{
  // Your code here.
  // cout << "bytes_buffered()" << endl;
  return capacity_ - avl_sz;
}
uint64_t Reader::bytes_popped() const
{
  // Your code here.
  // cout << "bytes_popped()" << endl;
  return total_read_bytes;
}
