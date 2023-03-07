// Generated by gencpp from file ublox_msgs/NavVELNED.msg
// DO NOT EDIT!


#ifndef UBLOX_MSGS_MESSAGE_NAVVELNED_H
#define UBLOX_MSGS_MESSAGE_NAVVELNED_H


#include <string>
#include <vector>
#include <memory>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>


namespace ublox_msgs
{
template <class ContainerAllocator>
struct NavVELNED_
{
  typedef NavVELNED_<ContainerAllocator> Type;

  NavVELNED_()
    : iTOW(0)
    , velN(0)
    , velE(0)
    , velD(0)
    , speed(0)
    , gSpeed(0)
    , heading(0)
    , sAcc(0)
    , cAcc(0)  {
    }
  NavVELNED_(const ContainerAllocator& _alloc)
    : iTOW(0)
    , velN(0)
    , velE(0)
    , velD(0)
    , speed(0)
    , gSpeed(0)
    , heading(0)
    , sAcc(0)
    , cAcc(0)  {
  (void)_alloc;
    }



   typedef uint32_t _iTOW_type;
  _iTOW_type iTOW;

   typedef int32_t _velN_type;
  _velN_type velN;

   typedef int32_t _velE_type;
  _velE_type velE;

   typedef int32_t _velD_type;
  _velD_type velD;

   typedef uint32_t _speed_type;
  _speed_type speed;

   typedef uint32_t _gSpeed_type;
  _gSpeed_type gSpeed;

   typedef int32_t _heading_type;
  _heading_type heading;

   typedef uint32_t _sAcc_type;
  _sAcc_type sAcc;

   typedef uint32_t _cAcc_type;
  _cAcc_type cAcc;



// reducing the odds to have name collisions with Windows.h 
#if defined(_WIN32) && defined(CLASS_ID)
  #undef CLASS_ID
#endif
#if defined(_WIN32) && defined(MESSAGE_ID)
  #undef MESSAGE_ID
#endif

  enum {
    CLASS_ID = 1u,
    MESSAGE_ID = 18u,
  };


  typedef boost::shared_ptr< ::ublox_msgs::NavVELNED_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::ublox_msgs::NavVELNED_<ContainerAllocator> const> ConstPtr;

}; // struct NavVELNED_

typedef ::ublox_msgs::NavVELNED_<std::allocator<void> > NavVELNED;

typedef boost::shared_ptr< ::ublox_msgs::NavVELNED > NavVELNEDPtr;
typedef boost::shared_ptr< ::ublox_msgs::NavVELNED const> NavVELNEDConstPtr;

// constants requiring out of line definition

   

   



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::ublox_msgs::NavVELNED_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::ublox_msgs::NavVELNED_<ContainerAllocator> >::stream(s, "", v);
return s;
}


template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator==(const ::ublox_msgs::NavVELNED_<ContainerAllocator1> & lhs, const ::ublox_msgs::NavVELNED_<ContainerAllocator2> & rhs)
{
  return lhs.iTOW == rhs.iTOW &&
    lhs.velN == rhs.velN &&
    lhs.velE == rhs.velE &&
    lhs.velD == rhs.velD &&
    lhs.speed == rhs.speed &&
    lhs.gSpeed == rhs.gSpeed &&
    lhs.heading == rhs.heading &&
    lhs.sAcc == rhs.sAcc &&
    lhs.cAcc == rhs.cAcc;
}

template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator!=(const ::ublox_msgs::NavVELNED_<ContainerAllocator1> & lhs, const ::ublox_msgs::NavVELNED_<ContainerAllocator2> & rhs)
{
  return !(lhs == rhs);
}


} // namespace ublox_msgs

namespace ros
{
namespace message_traits
{





template <class ContainerAllocator>
struct IsFixedSize< ::ublox_msgs::NavVELNED_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::ublox_msgs::NavVELNED_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::ublox_msgs::NavVELNED_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::ublox_msgs::NavVELNED_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::ublox_msgs::NavVELNED_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::ublox_msgs::NavVELNED_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::ublox_msgs::NavVELNED_<ContainerAllocator> >
{
  static const char* value()
  {
    return "b03402bb86164e74f01e04bff1850150";
  }

  static const char* value(const ::ublox_msgs::NavVELNED_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0xb03402bb86164e74ULL;
  static const uint64_t static_value2 = 0xf01e04bff1850150ULL;
};

template<class ContainerAllocator>
struct DataType< ::ublox_msgs::NavVELNED_<ContainerAllocator> >
{
  static const char* value()
  {
    return "ublox_msgs/NavVELNED";
  }

  static const char* value(const ::ublox_msgs::NavVELNED_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::ublox_msgs::NavVELNED_<ContainerAllocator> >
{
  static const char* value()
  {
    return "# NAV-VELNED (0x01 0x12)\n"
"# Velocity Solution in NED\n"
"#\n"
"# See important comments concerning validity of velocity given in section\n"
"# Navigation Output Filters.\n"
"#\n"
"\n"
"uint8 CLASS_ID = 1\n"
"uint8 MESSAGE_ID = 18\n"
"\n"
"uint32 iTOW             # GPS Millisecond time of week [ms]\n"
"\n"
"int32 velN              # NED north velocity [cm/s]\n"
"int32 velE              # NED east velocity [cm/s]\n"
"int32 velD              # NED down velocity [cm/s]\n"
"uint32 speed            # Speed (3-D) [cm/s]\n"
"uint32 gSpeed           # Ground Speed (2-D) [cm/s]\n"
"int32 heading           # Heading of motion 2-D [deg / 1e-5]\n"
"uint32 sAcc             # Speed Accuracy Estimate [cm/s]\n"
"uint32 cAcc             # Course / Heading Accuracy Estimate [deg / 1e-5]\n"
;
  }

  static const char* value(const ::ublox_msgs::NavVELNED_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::ublox_msgs::NavVELNED_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.iTOW);
      stream.next(m.velN);
      stream.next(m.velE);
      stream.next(m.velD);
      stream.next(m.speed);
      stream.next(m.gSpeed);
      stream.next(m.heading);
      stream.next(m.sAcc);
      stream.next(m.cAcc);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct NavVELNED_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::ublox_msgs::NavVELNED_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::ublox_msgs::NavVELNED_<ContainerAllocator>& v)
  {
    s << indent << "iTOW: ";
    Printer<uint32_t>::stream(s, indent + "  ", v.iTOW);
    s << indent << "velN: ";
    Printer<int32_t>::stream(s, indent + "  ", v.velN);
    s << indent << "velE: ";
    Printer<int32_t>::stream(s, indent + "  ", v.velE);
    s << indent << "velD: ";
    Printer<int32_t>::stream(s, indent + "  ", v.velD);
    s << indent << "speed: ";
    Printer<uint32_t>::stream(s, indent + "  ", v.speed);
    s << indent << "gSpeed: ";
    Printer<uint32_t>::stream(s, indent + "  ", v.gSpeed);
    s << indent << "heading: ";
    Printer<int32_t>::stream(s, indent + "  ", v.heading);
    s << indent << "sAcc: ";
    Printer<uint32_t>::stream(s, indent + "  ", v.sAcc);
    s << indent << "cAcc: ";
    Printer<uint32_t>::stream(s, indent + "  ", v.cAcc);
  }
};

} // namespace message_operations
} // namespace ros

#endif // UBLOX_MSGS_MESSAGE_NAVVELNED_H
