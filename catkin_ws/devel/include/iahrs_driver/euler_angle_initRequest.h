// Generated by gencpp from file iahrs_driver/euler_angle_initRequest.msg
// DO NOT EDIT!


#ifndef IAHRS_DRIVER_MESSAGE_EULER_ANGLE_INITREQUEST_H
#define IAHRS_DRIVER_MESSAGE_EULER_ANGLE_INITREQUEST_H


#include <string>
#include <vector>
#include <memory>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>


namespace iahrs_driver
{
template <class ContainerAllocator>
struct euler_angle_initRequest_
{
  typedef euler_angle_initRequest_<ContainerAllocator> Type;

  euler_angle_initRequest_()
    {
    }
  euler_angle_initRequest_(const ContainerAllocator& _alloc)
    {
  (void)_alloc;
    }







  typedef boost::shared_ptr< ::iahrs_driver::euler_angle_initRequest_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::iahrs_driver::euler_angle_initRequest_<ContainerAllocator> const> ConstPtr;

}; // struct euler_angle_initRequest_

typedef ::iahrs_driver::euler_angle_initRequest_<std::allocator<void> > euler_angle_initRequest;

typedef boost::shared_ptr< ::iahrs_driver::euler_angle_initRequest > euler_angle_initRequestPtr;
typedef boost::shared_ptr< ::iahrs_driver::euler_angle_initRequest const> euler_angle_initRequestConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::iahrs_driver::euler_angle_initRequest_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::iahrs_driver::euler_angle_initRequest_<ContainerAllocator> >::stream(s, "", v);
return s;
}


} // namespace iahrs_driver

namespace ros
{
namespace message_traits
{





template <class ContainerAllocator>
struct IsFixedSize< ::iahrs_driver::euler_angle_initRequest_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::iahrs_driver::euler_angle_initRequest_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::iahrs_driver::euler_angle_initRequest_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::iahrs_driver::euler_angle_initRequest_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::iahrs_driver::euler_angle_initRequest_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::iahrs_driver::euler_angle_initRequest_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::iahrs_driver::euler_angle_initRequest_<ContainerAllocator> >
{
  static const char* value()
  {
    return "d41d8cd98f00b204e9800998ecf8427e";
  }

  static const char* value(const ::iahrs_driver::euler_angle_initRequest_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0xd41d8cd98f00b204ULL;
  static const uint64_t static_value2 = 0xe9800998ecf8427eULL;
};

template<class ContainerAllocator>
struct DataType< ::iahrs_driver::euler_angle_initRequest_<ContainerAllocator> >
{
  static const char* value()
  {
    return "iahrs_driver/euler_angle_initRequest";
  }

  static const char* value(const ::iahrs_driver::euler_angle_initRequest_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::iahrs_driver::euler_angle_initRequest_<ContainerAllocator> >
{
  static const char* value()
  {
    return "#This message is used to send command to IAHRS(IMU)\n"
"#Euler_angle_init command\n"
"\n"
;
  }

  static const char* value(const ::iahrs_driver::euler_angle_initRequest_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::iahrs_driver::euler_angle_initRequest_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream&, T)
    {}

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct euler_angle_initRequest_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::iahrs_driver::euler_angle_initRequest_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream&, const std::string&, const ::iahrs_driver::euler_angle_initRequest_<ContainerAllocator>&)
  {}
};

} // namespace message_operations
} // namespace ros

#endif // IAHRS_DRIVER_MESSAGE_EULER_ANGLE_INITREQUEST_H
