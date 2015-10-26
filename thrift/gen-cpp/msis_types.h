/**
 * Autogenerated by Thrift Compiler (0.9.1)
 *
 * DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
 *  @generated
 */
#ifndef msis_TYPES_H
#define msis_TYPES_H

#include <thrift/Thrift.h>
#include <thrift/TApplicationException.h>
#include <thrift/protocol/TProtocol.h>
#include <thrift/transport/TTransport.h>

#include <thrift/cxxfunctional.h>


namespace msis {

typedef struct _Entity__isset {
  _Entity__isset() : names(false), values(false) {}
  bool names;
  bool values;
} _Entity__isset;

class Entity {
 public:

  static const char* ascii_fingerprint; // = "AA819045335EAFAB5C2FE456B4B9CC1C";
  static const uint8_t binary_fingerprint[16]; // = {0xAA,0x81,0x90,0x45,0x33,0x5E,0xAF,0xAB,0x5C,0x2F,0xE4,0x56,0xB4,0xB9,0xCC,0x1C};

  Entity() {
  }

  virtual ~Entity() throw() {}

  std::vector<std::string>  names;
  std::vector<std::string>  values;

  _Entity__isset __isset;

  void __set_names(const std::vector<std::string> & val) {
    names = val;
  }

  void __set_values(const std::vector<std::string> & val) {
    values = val;
  }

  bool operator == (const Entity & rhs) const
  {
    if (!(names == rhs.names))
      return false;
    if (!(values == rhs.values))
      return false;
    return true;
  }
  bool operator != (const Entity &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const Entity & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

void swap(Entity &a, Entity &b);

} // namespace

#endif