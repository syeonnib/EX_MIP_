// Generated by gencpp from file autoware_msgs/VscanTrackedArray.msg
// DO NOT EDIT!


#ifndef AUTOWARE_MSGS_MESSAGE_VSCANTRACKEDARRAY_H
#define AUTOWARE_MSGS_MESSAGE_VSCANTRACKEDARRAY_H


#include <string>
#include <vector>
#include <memory>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>

#include <std_msgs/Header.h>
#include <autoware_msgs/VscanTracked.h>

namespace autoware_msgs
{
template <class ContainerAllocator>
struct VscanTrackedArray_
{
  typedef VscanTrackedArray_<ContainerAllocator> Type;

  VscanTrackedArray_()
    : header()
    , obj_tracked()  {
    }
  VscanTrackedArray_(const ContainerAllocator& _alloc)
    : header(_alloc)
    , obj_tracked(_alloc)  {
  (void)_alloc;
    }



   typedef  ::std_msgs::Header_<ContainerAllocator>  _header_type;
  _header_type header;

   typedef std::vector< ::autoware_msgs::VscanTracked_<ContainerAllocator> , typename std::allocator_traits<ContainerAllocator>::template rebind_alloc< ::autoware_msgs::VscanTracked_<ContainerAllocator> >> _obj_tracked_type;
  _obj_tracked_type obj_tracked;





  typedef boost::shared_ptr< ::autoware_msgs::VscanTrackedArray_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::autoware_msgs::VscanTrackedArray_<ContainerAllocator> const> ConstPtr;

}; // struct VscanTrackedArray_

typedef ::autoware_msgs::VscanTrackedArray_<std::allocator<void> > VscanTrackedArray;

typedef boost::shared_ptr< ::autoware_msgs::VscanTrackedArray > VscanTrackedArrayPtr;
typedef boost::shared_ptr< ::autoware_msgs::VscanTrackedArray const> VscanTrackedArrayConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::autoware_msgs::VscanTrackedArray_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::autoware_msgs::VscanTrackedArray_<ContainerAllocator> >::stream(s, "", v);
return s;
}


template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator==(const ::autoware_msgs::VscanTrackedArray_<ContainerAllocator1> & lhs, const ::autoware_msgs::VscanTrackedArray_<ContainerAllocator2> & rhs)
{
  return lhs.header == rhs.header &&
    lhs.obj_tracked == rhs.obj_tracked;
}

template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator!=(const ::autoware_msgs::VscanTrackedArray_<ContainerAllocator1> & lhs, const ::autoware_msgs::VscanTrackedArray_<ContainerAllocator2> & rhs)
{
  return !(lhs == rhs);
}


} // namespace autoware_msgs

namespace ros
{
namespace message_traits
{





template <class ContainerAllocator>
struct IsFixedSize< ::autoware_msgs::VscanTrackedArray_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::autoware_msgs::VscanTrackedArray_<ContainerAllocator> const>
  : FalseType
  { };

template <class ContainerAllocator>
struct IsMessage< ::autoware_msgs::VscanTrackedArray_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::autoware_msgs::VscanTrackedArray_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::autoware_msgs::VscanTrackedArray_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::autoware_msgs::VscanTrackedArray_<ContainerAllocator> const>
  : TrueType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::autoware_msgs::VscanTrackedArray_<ContainerAllocator> >
{
  static const char* value()
  {
    return "6452543c0811934ca1329c54d19f5c59";
  }

  static const char* value(const ::autoware_msgs::VscanTrackedArray_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0x6452543c0811934cULL;
  static const uint64_t static_value2 = 0xa1329c54d19f5c59ULL;
};

template<class ContainerAllocator>
struct DataType< ::autoware_msgs::VscanTrackedArray_<ContainerAllocator> >
{
  static const char* value()
  {
    return "autoware_msgs/VscanTrackedArray";
  }

  static const char* value(const ::autoware_msgs::VscanTrackedArray_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::autoware_msgs::VscanTrackedArray_<ContainerAllocator> >
{
  static const char* value()
  {
    return "std_msgs/Header header\n"
"VscanTracked[] obj_tracked\n"
"================================================================================\n"
"MSG: std_msgs/Header\n"
"# Standard metadata for higher-level stamped data types.\n"
"# This is generally used to communicate timestamped data \n"
"# in a particular coordinate frame.\n"
"# \n"
"# sequence ID: consecutively increasing ID \n"
"uint32 seq\n"
"#Two-integer timestamp that is expressed as:\n"
"# * stamp.sec: seconds (stamp_secs) since epoch (in Python the variable is called 'secs')\n"
"# * stamp.nsec: nanoseconds since stamp_secs (in Python the variable is called 'nsecs')\n"
"# time-handling sugar is provided by the client library\n"
"time stamp\n"
"#Frame this data is associated with\n"
"string frame_id\n"
"\n"
"================================================================================\n"
"MSG: autoware_msgs/VscanTracked\n"
"geometry_msgs/Point position\n"
"float32 orientation\n"
"float32 velocity\n"
"GeometricRectangle geo_rect\n"
"================================================================================\n"
"MSG: geometry_msgs/Point\n"
"# This contains the position of a point in free space\n"
"float64 x\n"
"float64 y\n"
"float64 z\n"
"\n"
"================================================================================\n"
"MSG: autoware_msgs/GeometricRectangle\n"
"float32 wl\n"
"float32 wr\n"
"float32 lf\n"
"float32 lb\n"
;
  }

  static const char* value(const ::autoware_msgs::VscanTrackedArray_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::autoware_msgs::VscanTrackedArray_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.header);
      stream.next(m.obj_tracked);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct VscanTrackedArray_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::autoware_msgs::VscanTrackedArray_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::autoware_msgs::VscanTrackedArray_<ContainerAllocator>& v)
  {
    s << indent << "header: ";
    s << std::endl;
    Printer< ::std_msgs::Header_<ContainerAllocator> >::stream(s, indent + "  ", v.header);
    s << indent << "obj_tracked[]" << std::endl;
    for (size_t i = 0; i < v.obj_tracked.size(); ++i)
    {
      s << indent << "  obj_tracked[" << i << "]: ";
      s << std::endl;
      s << indent;
      Printer< ::autoware_msgs::VscanTracked_<ContainerAllocator> >::stream(s, indent + "    ", v.obj_tracked[i]);
    }
  }
};

} // namespace message_operations
} // namespace ros

#endif // AUTOWARE_MSGS_MESSAGE_VSCANTRACKEDARRAY_H
