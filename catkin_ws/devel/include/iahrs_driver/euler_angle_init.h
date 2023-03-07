// Generated by gencpp from file iahrs_driver/euler_angle_init.msg
// DO NOT EDIT!


#ifndef IAHRS_DRIVER_MESSAGE_EULER_ANGLE_INIT_H
#define IAHRS_DRIVER_MESSAGE_EULER_ANGLE_INIT_H

#include <ros/service_traits.h>


#include <iahrs_driver/euler_angle_initRequest.h>
#include <iahrs_driver/euler_angle_initResponse.h>


namespace iahrs_driver
{

struct euler_angle_init
{

typedef euler_angle_initRequest Request;
typedef euler_angle_initResponse Response;
Request request;
Response response;

typedef Request RequestType;
typedef Response ResponseType;

}; // struct euler_angle_init
} // namespace iahrs_driver


namespace ros
{
namespace service_traits
{


template<>
struct MD5Sum< ::iahrs_driver::euler_angle_init > {
  static const char* value()
  {
    return "6b370111df6d9d8116fbdd43bd394a52";
  }

  static const char* value(const ::iahrs_driver::euler_angle_init&) { return value(); }
};

template<>
struct DataType< ::iahrs_driver::euler_angle_init > {
  static const char* value()
  {
    return "iahrs_driver/euler_angle_init";
  }

  static const char* value(const ::iahrs_driver::euler_angle_init&) { return value(); }
};


// service_traits::MD5Sum< ::iahrs_driver::euler_angle_initRequest> should match
// service_traits::MD5Sum< ::iahrs_driver::euler_angle_init >
template<>
struct MD5Sum< ::iahrs_driver::euler_angle_initRequest>
{
  static const char* value()
  {
    return MD5Sum< ::iahrs_driver::euler_angle_init >::value();
  }
  static const char* value(const ::iahrs_driver::euler_angle_initRequest&)
  {
    return value();
  }
};

// service_traits::DataType< ::iahrs_driver::euler_angle_initRequest> should match
// service_traits::DataType< ::iahrs_driver::euler_angle_init >
template<>
struct DataType< ::iahrs_driver::euler_angle_initRequest>
{
  static const char* value()
  {
    return DataType< ::iahrs_driver::euler_angle_init >::value();
  }
  static const char* value(const ::iahrs_driver::euler_angle_initRequest&)
  {
    return value();
  }
};

// service_traits::MD5Sum< ::iahrs_driver::euler_angle_initResponse> should match
// service_traits::MD5Sum< ::iahrs_driver::euler_angle_init >
template<>
struct MD5Sum< ::iahrs_driver::euler_angle_initResponse>
{
  static const char* value()
  {
    return MD5Sum< ::iahrs_driver::euler_angle_init >::value();
  }
  static const char* value(const ::iahrs_driver::euler_angle_initResponse&)
  {
    return value();
  }
};

// service_traits::DataType< ::iahrs_driver::euler_angle_initResponse> should match
// service_traits::DataType< ::iahrs_driver::euler_angle_init >
template<>
struct DataType< ::iahrs_driver::euler_angle_initResponse>
{
  static const char* value()
  {
    return DataType< ::iahrs_driver::euler_angle_init >::value();
  }
  static const char* value(const ::iahrs_driver::euler_angle_initResponse&)
  {
    return value();
  }
};

} // namespace service_traits
} // namespace ros

#endif // IAHRS_DRIVER_MESSAGE_EULER_ANGLE_INIT_H
