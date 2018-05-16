/** \addtogroup types Types
 *  @{
 */
/*****************************************************************************
 * 
 * (C) Copyright Broadcom Corporation 2013-2015
 * 
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * 
 * You may obtain a copy of the License at
 * http://www.apache.org/licenses/LICENSE-2.0
 * 
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 * 
 ***************************************************************************//**
 * \file			types.h
 ******************************************************************************/

#ifndef __OPENNSL_TYPES_H__
#define __OPENNSL_TYPES_H__

#include <sal/types.h>
#include <sal/commdefs.h>
#include <shared/bitop.h>
#include <shared/pbmp.h>
#include <shared/gport.h>
#include <shared/util.h>

/** opennsl_multicast_t */
typedef int opennsl_multicast_t;

#if !defined(OPENNSL_LOCAL_UNITS_MAX)
#endif
#if !defined(OPENNSL_UNITS_MAX)
#endif
#define OPENNSL_PBMP_PORT_MAX   _SHR_PBMP_PORT_MAX 
#define OPENNSL_PBMP_CLEAR(pbm)  _SHR_PBMP_CLEAR(pbm) 
#define OPENNSL_PBMP_MEMBER(bmp, port)  _SHR_PBMP_MEMBER((bmp), (port)) 
#define OPENNSL_PBMP_ITER(bmp, port)  _SHR_PBMP_ITER((bmp), (port)) 
#define OPENNSL_PBMP_COUNT(pbm, count)  _SHR_PBMP_COUNT(pbm, count) 
#define OPENNSL_PBMP_IS_NULL(pbm)  _SHR_PBMP_IS_NULL(pbm) 
#define OPENNSL_PBMP_NOT_NULL(pbm)  _SHR_PBMP_NOT_NULL(pbm) 
#define OPENNSL_PBMP_EQ(pbm_a, pbm_b)  _SHR_PBMP_EQ(pbm_a, pbm_b) 
#define OPENNSL_PBMP_NEQ(pbm_a, pbm_b)  _SHR_PBMP_NEQ(pbm_a, pbm_b) 
#define OPENNSL_PBMP_ASSIGN(dst, src)  _SHR_PBMP_ASSIGN(dst, src) 
#define OPENNSL_PBMP_AND(pbm_a, pbm_b)  _SHR_PBMP_AND(pbm_a, pbm_b) 
#define OPENNSL_PBMP_OR(pbm_a, pbm_b)  _SHR_PBMP_OR(pbm_a, pbm_b) 
#define OPENNSL_PBMP_XOR(pbm_a, pbm_b)  _SHR_PBMP_XOR(pbm_a, pbm_b) 
#define OPENNSL_PBMP_REMOVE(pbm_a, pbm_b)  _SHR_PBMP_REMOVE(pbm_a, pbm_b) 
#define OPENNSL_PBMP_NEGATE(pbm_a, pbm_b)  _SHR_PBMP_NEGATE(pbm_a, pbm_b) 
#define OPENNSL_PBMP_PORT_SET(pbm, port)  _SHR_PBMP_PORT_SET(pbm, port) 
#define OPENNSL_PBMP_PORT_ADD(pbm, port)  _SHR_PBMP_PORT_ADD(pbm, port) 
#define OPENNSL_PBMP_PORT_REMOVE(pbm, port)  _SHR_PBMP_PORT_REMOVE(pbm, port) 
#define OPENNSL_PBMP_PORT_FLIP(pbm, port)  _SHR_PBMP_PORT_FLIP(pbm, port) 
/** Set the default tag protocol ID (TPID) for the specified port. */
typedef int opennsl_port_t;

/** opennsl_pbmp_t */
typedef _shr_pbmp_t opennsl_pbmp_t;

/** opennsl_mac_t */
typedef uint8 opennsl_mac_t[6];

/** opennsl_ip_t */
typedef uint32 opennsl_ip_t;

/** opennsl_ip6_t */
typedef uint8 opennsl_ip6_t[16];

/** opennsl_if_t */
typedef int opennsl_if_t;

/** opennsl_if_group_t */
typedef int opennsl_if_group_t;

/** opennsl_vrf_t */
typedef int opennsl_vrf_t;

/** opennsl_mpls_label_t */
typedef uint32 opennsl_mpls_label_t;

#define OPENNSL_VLAN_DEFAULT    ((opennsl_vlan_t)0x0001) 
/** opennsl_vlan_t */
typedef uint16 opennsl_vlan_t;

/** opennsl_cos_t */
typedef int opennsl_cos_t;

/** opennsl_cos_queue_t */
typedef int opennsl_cos_queue_t;

/** opennsl_module_t */
typedef int opennsl_module_t;

/** opennsl_trunk_t */
typedef int opennsl_trunk_t;

/** 
 * GPORT (generic port) definitions.
 * See shared/gport.h for more details.
 */
typedef int opennsl_gport_t;

#define OPENNSL_GPORT_MODPORT_SET(_gport, _module, _port)  \
    _SHR_GPORT_MODPORT_SET(_gport, _module, _port) 
#define OPENNSL_GPORT_MODPORT_MODID_GET(_gport)  \
    (!_SHR_GPORT_IS_MODPORT(_gport) ? -1 : \
    _SHR_GPORT_MODPORT_MODID_GET(_gport)) 
#define OPENNSL_GPORT_MODPORT_PORT_GET(_gport)  \
    (!_SHR_GPORT_IS_MODPORT(_gport) ? -1 : \
    _SHR_GPORT_MODPORT_PORT_GET(_gport)) 
/** Multicast distribution set */
typedef int opennsl_fabric_distribution_t;

/** Failover Object */
typedef int opennsl_failover_t;

/** opennsl_stg_t */
typedef int opennsl_stg_t;

/** opennsl_color_t */
typedef enum opennsl_color_e {
    opennsltypesReservedEnum1,  
    opennsltypesReservedEnum2,  
    opennsltypesReservedEnum3,  
    opennsltypesReservedEnum4,  
    opennsltypesReservedEnum5,  
    opennsltypesReservedEnum6,  
    opennsltypesReservedEnum7   
} opennsl_color_t;

#if defined(LE_HOST)
#else
#define opennsl_htonl(_l)       (_l)       
#define opennsl_htons(_s)       (_s)       
#define opennsl_ntohl(_l)       (_l)       
#define opennsl_ntohs(_s)       (_s)       
#endif
/***************************************************************************//** 
 *
 *
 *\param    ip6 [OUT]
 *\param    len [IN]
 *
 *\retval   OPENNSL_E_xxx
 ******************************************************************************/
extern int opennsl_ip6_mask_create(
    opennsl_ip6_t ip6, 
    int len) LIB_DLL_EXPORTED ;

/***************************************************************************//** 
 *
 *
 *\param    len [IN]
 *
 *\retval   OPENNSL_E_xxx
 ******************************************************************************/
extern opennsl_ip_t opennsl_ip_mask_create(
    int len) LIB_DLL_EXPORTED ;

/** VLAN Action definitions. */
typedef enum opennsl_vlan_action_e {
    opennsltypesReservedEnum8, 
    opennsltypesReservedEnum9, 
    opennsltypesReservedEnum10, 
    opennsltypesReservedEnum11, 
    opennsltypesReservedEnum12, 
    opennsltypesReservedEnum13, 
    opennsltypesReservedEnum14, 
    opennsltypesReservedEnum15, 
    opennsltypesReservedEnum16, 
    opennsltypesReservedEnum17, 
    opennsltypesReservedEnum18, 
    opennsltypesReservedEnum19 
} opennsl_vlan_action_t;

/** Qualifier Forwarding Type (for opennsl_forwarding_type). */
typedef enum opennsl_forwarding_type_e {
    opennslForwardingTypeL2 = 0,        /**< L2 switching forwarding. */
    opennslForwardingTypeIp4Ucast = 1,  /**< IPv4 Unicast Routing forwarding. */
    opennslForwardingTypeIp4Mcast = 2,  /**< IPv4 Multicast Routing forwarding. */
    opennslForwardingTypeIp6Ucast = 3,  /**< IPv6 Unicast Routing forwarding. */
    opennslForwardingTypeIp6Mcast = 4,  /**< IPv6 Multicast Routing forwarding. */
    opennslForwardingTypeMpls = 5,      /**< MPLS Switching forwarding. */
    opennslForwardingTypeTrill = 6,     /**< Trill forwarding. */
    opennslForwardingTypeRxReason = 7,  /**< Forwarding according to a RxReason. */
    opennslForwardingTypeTrafficManagement = 8, /**< Traffic Management forwarding, when
                                           an external Packet Processor sets the
                                           forwarding decision. */
    opennslForwardingTypeSnoop = 9,     /**< Snooped packet. */
    opennslForwardingTypeFCoE = 10,     /**< Fiber Channel over Ethernet
                                           forwarding. */
    opennslForwardingTypeCount = 11     /**< Always Last. Not a usable value. */
} opennsl_forwarding_type_t;

#define OPENNSL_FORWARDINGTYPE_STRINGS \
{ \
    "L2", \
    "Ip4Ucast", \
    "Ip4Mcast", \
    "Ip6Ucast", \
    "Ip6Mcast", \
    "Mpls", \
    "Trill", \
    "RxReason", \
    "TrafficManagement", \
    "Snoop", \
    "FCoE", \
    "Count"  \
}

#endif /* __OPENNSL_TYPES_H__ */
/*@}*/
