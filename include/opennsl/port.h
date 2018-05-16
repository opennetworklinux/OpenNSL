/** \addtogroup port Port Management
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
 * \file			port.h
 ******************************************************************************/

#ifndef __OPENNSL_PORT_H__
#define __OPENNSL_PORT_H__

#include <shared/portmode.h>
#include <shared/port.h>
#include <shared/phyconfig.h>
#include <shared/phyreg.h>
#include <shared/switch.h>
#include <opennsl/types.h>
#include <opennsl/stat.h>
#include <shared/port_ability.h>

#define OPENNSL_PIPES_MAX       _SHR_SWITCH_MAX_PIPES 
/** Port Configuration structure. */
typedef struct opennsl_port_config_s {
    opennsl_pbmp_t fe;                  /**< Mask of FE ports. */
    opennsl_pbmp_t ge;                  /**< Mask of GE ports. */
    opennsl_pbmp_t xe;                  /**< Mask of 10gig ports. */
    opennsl_pbmp_t ce;                  /**< Mask of 100gig ports. */
    opennsl_pbmp_t e;                   /**< Mask of eth ports. */
    opennsl_pbmp_t hg;                  /**< Mask of Higig ports. */
    opennsl_pbmp_t sci;                 /**< Mask of SCI ports. */
    opennsl_pbmp_t sfi;                 /**< Mask of SFI ports. */
    opennsl_pbmp_t spi;                 /**< Mask of SPI ports. */
    opennsl_pbmp_t spi_subport;         /**< Mask of SPI subports. */
    opennsl_pbmp_t port;                /**< Mask of all front panel ports. */
    opennsl_pbmp_t cpu;                 /**< Mask of CPU ports. */
    opennsl_pbmp_t all;                 /**< Mask of all ports. */
    opennsl_pbmp_t stack_int;           /**< Deprecated - unused. */
    opennsl_pbmp_t stack_ext;           /**< Mask of Stack ports. */
    opennsl_pbmp_t tdm;                 /**< Mask of TDM ports. */
    opennsl_pbmp_t pon;                 /**< Mask of PON ports. */
    opennsl_pbmp_t llid;                /**< Mask of LLID ports. */
    opennsl_pbmp_t il;                  /**< Mask of ILKN ports. */
    opennsl_pbmp_t xl;                  /**< Mask of XLAUI ports. */
    opennsl_pbmp_t rcy;                 /**< Mask of RECYCLE ports. */
    opennsl_pbmp_t per_pipe[OPENNSL_PIPES_MAX]; /**< Mask of ports per pipe. The number of
                                           pipes per device can be obtained via
                                           num_pipes field of opennsl_info_t. */
    opennsl_pbmp_t nif;                 /**< Mask of Network Interfaces ports. */
} opennsl_port_config_t;

/** Port ability */
typedef _shr_port_ability_t opennsl_port_ability_t;

#define OPENNSL_PORT_ABILITY_10MB           _SHR_PA_SPEED_10MB 
#define OPENNSL_PORT_ABILITY_100MB          _SHR_PA_SPEED_100MB 
#define OPENNSL_PORT_ABILITY_1000MB         _SHR_PA_SPEED_1000MB 
#define OPENNSL_PORT_ABILITY_2500MB         _SHR_PA_SPEED_2500MB 
#define OPENNSL_PORT_ABILITY_3000MB         _SHR_PA_SPEED_3000MB 
#define OPENNSL_PORT_ABILITY_5000MB         _SHR_PA_SPEED_5000MB 
#define OPENNSL_PORT_ABILITY_6000MB         _SHR_PA_SPEED_6000MB 
#define OPENNSL_PORT_ABILITY_10GB           _SHR_PA_SPEED_10GB 
#define OPENNSL_PORT_ABILITY_11GB           _SHR_PA_SPEED_11GB 
#define OPENNSL_PORT_ABILITY_12GB           _SHR_PA_SPEED_12GB 
#define OPENNSL_PORT_ABILITY_12P5GB         _SHR_PA_SPEED_12P5GB 
#define OPENNSL_PORT_ABILITY_13GB           _SHR_PA_SPEED_13GB 
#define OPENNSL_PORT_ABILITY_15GB           _SHR_PA_SPEED_15GB 
#define OPENNSL_PORT_ABILITY_16GB           _SHR_PA_SPEED_16GB 
#define OPENNSL_PORT_ABILITY_20GB           _SHR_PA_SPEED_20GB 
#define OPENNSL_PORT_ABILITY_21GB           _SHR_PA_SPEED_21GB 
#define OPENNSL_PORT_ABILITY_23GB           _SHR_PA_SPEED_23GB 
#define OPENNSL_PORT_ABILITY_24GB           _SHR_PA_SPEED_24GB 
#define OPENNSL_PORT_ABILITY_25GB           _SHR_PA_SPEED_25GB 
#define OPENNSL_PORT_ABILITY_27GB           _SHR_PA_SPEED_27GB 
#define OPENNSL_PORT_ABILITY_30GB           _SHR_PA_SPEED_30GB 
#define OPENNSL_PORT_ABILITY_32GB           _SHR_PA_SPEED_32GB 
#define OPENNSL_PORT_ABILITY_40GB           _SHR_PA_SPEED_40GB 
#define OPENNSL_PORT_ABILITY_42GB           _SHR_PA_SPEED_42GB 
#define OPENNSL_PORT_ABILITY_48GB           _SHR_PA_SPEED_48GB 
#define OPENNSL_PORT_ABILITY_50GB           _SHR_PA_SPEED_50GB 
#define OPENNSL_PORT_ABILITY_53GB           _SHR_PA_SPEED_53GB 
#define OPENNSL_PORT_ABILITY_100GB          _SHR_PA_SPEED_100GB 
#define OPENNSL_PORT_ABILITY_106GB          _SHR_PA_SPEED_106GB 
#define OPENNSL_PORT_ABILITY_120GB          _SHR_PA_SPEED_120GB 
#define OPENNSL_PORT_ABILITY_127GB          _SHR_PA_SPEED_127GB 
#define OPENNSL_PORT_ABILITY_INTERFACE_TBI  _SHR_PA_INTF_TBI 
#define OPENNSL_PORT_ABILITY_INTERFACE_MII  _SHR_PA_INTF_MII 
#define OPENNSL_PORT_ABILITY_INTERFACE_GMII _SHR_PA_INTF_GMII 
#define OPENNSL_PORT_ABILITY_INTERFACE_SGMII _SHR_PA_INTF_SGMII 
#define OPENNSL_PORT_ABILITY_INTERFACE_XGMII _SHR_PA_INTF_XGMII 
#define OPENNSL_PORT_ABILITY_INTERFACE_QSGMII _SHR_PA_INTF_QSGMII 
#define OPENNSL_PORT_ABILITY_INTERFACE_CGMII _SHR_PA_INTF_CGMII 
#define OPENNSL_PORT_ABILITY_MEDIUM_COPPER  _SHR_PA_MEDIUM_COPPER 
#define OPENNSL_PORT_ABILITY_MEDIUM_FIBER   _SHR_PA_MEDIUM_FIBER 
#define OPENNSL_PORT_ABILITY_LB_NONE        _SHR_PA_LB_NONE 
#define OPENNSL_PORT_ABILITY_LB_MAC         _SHR_PA_LB_MAC 
#define OPENNSL_PORT_ABILITY_LB_PHY         _SHR_PA_LB_PHY 
#define OPENNSL_PORT_ABILITY_LB_LINE        _SHR_PA_LB_LINE 
#define OPENNSL_PORT_ABILITY_AUTONEG        _SHR_PA_AUTONEG 
#define OPENNSL_PORT_ABILITY_COMBO          _SHR_PA_COMBO 
#define OPENNSL_PORT_ABILITY_PAUSE_TX       _SHR_PA_PAUSE_TX 
#define OPENNSL_PORT_ABILITY_PAUSE_RX       _SHR_PA_PAUSE_RX 
#define OPENNSL_PORT_ABILITY_PAUSE          _SHR_PA_PAUSE /**< Both TX and RX. */
#define OPENNSL_PORT_ABILITY_PAUSE_ASYMM    _SHR_PA_PAUSE_ASYMM /**< The following is used
                                                          only by
                                                          opennsl_port_ability_get,
                                                          and indicates that a
                                                          port can support
                                                          having PAUSE_TX be
                                                          different than
                                                          PAUSE_RX. */
#define OPENNSL_PORT_ABILITY_EEE_100MB_BASETX _SHR_PA_EEE_100MB_BASETX /**< EEE ability at
                                                          100M-BaseTX. */
#define OPENNSL_PORT_ABILITY_EEE_1GB_BASET  _SHR_PA_EEE_1GB_BASET /**< EEE ability at
                                                          1G-BaseT. */
#define OPENNSL_PORT_ABILITY_EEE_10GB_BASET _SHR_PA_EEE_10GB_BASET /**< EEE ability at
                                                          10G-BaseT. */
#define OPENNSL_PORT_ABILITY_EEE_10GB_KX    _SHR_PA_EEE_10GB_KX /**< EEE ability at
                                                          10GB-KX. */
#define OPENNSL_PORT_ABILITY_EEE_10GB_KX4   _SHR_PA_EEE_10GB_KX4 /**< EEE ability at
                                                          10GB-KX4. */
#define OPENNSL_PORT_ABILITY_EEE_10GB_KR    _SHR_PA_EEE_10GB_KR /**< EEE ability at
                                                          10GB-KR. */
#define OPENNSL_PORT_ABILITY_FCMAP          _SHR_PA_FCMAP /**< Fiber Channel ability. */
#define OPENNSL_PORT_ABILITY_FCMAP_FCMAC_LOOPBACK _SHR_PA_FCMAP_FCMAC_LOOPBACK /**< Fiber Channel FCMAC
                                                          loopback ability. */
#define OPENNSL_PORT_ABILITY_FCMAP_AUTONEG  _SHR_PA_FCMAP_AUTONEG /**< Fiber Channel FCMAC
                                                          autoneg ability. */
#define OPENNSL_PORT_ABILITY_FCMAP_2GB      _SHR_PA_FCMAP_2GB /**< Fiber Channel ability
                                                          at 2GB. */
#define OPENNSL_PORT_ABILITY_FCMAP_4GB      _SHR_PA_FCMAP_4GB /**< Fiber Channel ability
                                                          at 4GB. */
#define OPENNSL_PORT_ABILITY_FCMAP_8GB      _SHR_PA_FCMAP_8GB /**< Fiber Channel ability
                                                          at 8GB. */
#define OPENNSL_PORT_ABILITY_FCMAP_16GB     _SHR_PA_FCMAP_16GB /**< Fiber Channel ability
                                                          at 16GB. */
/** 
 * Port ability mask.
 * 
 * The following flags are used to indicate which set of capabilities are
 * provided by a PHY or MAC when retrieving the ability of a port,
 * setting or getting the local advertisement, getting the remote
 * advertisement, or setting the MAC encapsulation and/or CRC modes.
 */
typedef _shr_port_mode_t opennsl_port_abil_t;

#define OPENNSL_PORT_ABIL_10MB_HD       _SHR_PM_10MB_HD 
#define OPENNSL_PORT_ABIL_10MB_FD       _SHR_PM_10MB_FD 
#define OPENNSL_PORT_ABIL_100MB_HD      _SHR_PM_100MB_HD 
#define OPENNSL_PORT_ABIL_100MB_FD      _SHR_PM_100MB_FD 
#define OPENNSL_PORT_ABIL_1000MB_HD     _SHR_PM_1000MB_HD 
#define OPENNSL_PORT_ABIL_1000MB_FD     _SHR_PM_1000MB_FD 
#define OPENNSL_PORT_ABIL_2500MB_HD     _SHR_PM_2500MB_HD 
#define OPENNSL_PORT_ABIL_2500MB_FD     _SHR_PM_2500MB_FD 
#define OPENNSL_PORT_ABIL_3000MB_HD     _SHR_PM_3000MB_HD 
#define OPENNSL_PORT_ABIL_3000MB_FD     _SHR_PM_3000MB_FD 
#define OPENNSL_PORT_ABIL_10GB_HD       _SHR_PM_10GB_HD 
#define OPENNSL_PORT_ABIL_10GB_FD       _SHR_PM_10GB_FD 
#define OPENNSL_PORT_ABIL_12GB_HD       _SHR_PM_12GB_HD 
#define OPENNSL_PORT_ABIL_12GB_FD       _SHR_PM_12GB_FD 
#define OPENNSL_PORT_ABIL_13GB_HD       _SHR_PM_13GB_HD 
#define OPENNSL_PORT_ABIL_13GB_FD       _SHR_PM_13GB_FD 
#define OPENNSL_PORT_ABIL_16GB_HD       _SHR_PM_16GB_HD 
#define OPENNSL_PORT_ABIL_16GB_FD       _SHR_PM_16GB_FD 
#define OPENNSL_PORT_ABIL_TBI           _SHR_PM_TBI 
#define OPENNSL_PORT_ABIL_MII           _SHR_PM_MII 
#define OPENNSL_PORT_ABIL_GMII          _SHR_PM_GMII 
#define OPENNSL_PORT_ABIL_SGMII         _SHR_PM_SGMII 
#define OPENNSL_PORT_ABIL_XGMII         _SHR_PM_XGMII 
#define OPENNSL_PORT_ABIL_LB_MAC        _SHR_PM_LB_MAC 
#define OPENNSL_PORT_ABIL_LB_PHY        _SHR_PM_LB_PHY 
#define OPENNSL_PORT_ABIL_LB_NONE       _SHR_PM_LB_NONE 
#define OPENNSL_PORT_ABIL_AN            _SHR_PM_AN 
#define OPENNSL_PORT_ABIL_COMBO         _SHR_PM_COMBO 
#define OPENNSL_PORT_ABIL_PAUSE_TX      _SHR_PM_PAUSE_TX 
#define OPENNSL_PORT_ABIL_PAUSE_RX      _SHR_PM_PAUSE_RX 
#define OPENNSL_PORT_ABIL_PAUSE         _SHR_PM_PAUSE /**< Both TX and RX. */
#define OPENNSL_PORT_ABIL_10B           OPENNSL_PORT_ABIL_TBI /**< Deprecated */
#define OPENNSL_PORT_ABIL_PAUSE_ASYMM   _SHR_PM_PAUSE_ASYMM /**< The following is used only
                                                      by
                                                      opennsl_port_ability_get,
                                                      and indicates that a port
                                                      can support having
                                                      PAUSE_TX be different than
                                                      PAUSE_RX. */
#define OPENNSL_PORT_ABIL_10MB          _SHR_PM_10MB 
#define OPENNSL_PORT_ABIL_100MB         _SHR_PM_100MB 
#define OPENNSL_PORT_ABIL_1000MB        _SHR_PM_1000MB 
#define OPENNSL_PORT_ABIL_2500MB        _SHR_PM_2500MB 
#define OPENNSL_PORT_ABIL_3000MB        _SHR_PM_3000MB 
#define OPENNSL_PORT_ABIL_10GB          _SHR_PM_10GB 
#define OPENNSL_PORT_ABIL_12GB          _SHR_PM_12GB 
#define OPENNSL_PORT_ABIL_13GB          _SHR_PM_13GB 
#define OPENNSL_PORT_ABIL_16GB          _SHR_PM_16GB 
#define OPENNSL_PORT_ABIL_HD            _SHR_PM_HD 
#define OPENNSL_PORT_ABIL_FD            _SHR_PM_FD 
#define OPENNSL_PORT_ABIL_SPD_ANY       _SHR_PM_SPEED_ALL 
#define OPENNSL_PORT_ABIL_SPD_MAX(abil)  \
    _SHR_PM_SPEED_MAX(abil) 
#define OPENNSL_PORT_ABILITY_SPEED_MAX(abil)  _SHR_PA_SPEED_MAX(abil) 
#ifndef OPENNSL_HIDE_DISPATCHABLE

/***************************************************************************//** 
 *\brief Retrieved the port configuration for the specified device.
 *
 *\description opennsl_port_config_get returns all known ports configured on the
 *          specified device.
 *          The logical information indicates port bit maps to represent the
 *          ports on the specified unit (see the Broadcom Network Switching
 *          Stacking Guide for a description of logical port lists).
 *          =OPENNSL_PORT_CONFIG_t describes the meaning of each field.
 *
 *\param    unit [IN]   Unit number.
 *\param    config [OUT]   Pointer to port configuration structure populated on
 *          successful return.
 *
 *\retval    OPENNSL_E_NONE
 *\retval    OPENNSL_E_XXX
 ******************************************************************************/
extern int opennsl_port_config_get(
    int unit, 
    opennsl_port_config_t *config) LIB_DLL_EXPORTED ;

#endif /* OPENNSL_HIDE_DISPATCHABLE */

/***************************************************************************//** 
 *
 *
 *\param    unit [IN]   Unit number.
 *\param    port [IN]
 *
 *\retval   OPENNSL_E_xxx
 ******************************************************************************/
extern char *opennsl_port_name(
    int unit, 
    int port) LIB_DLL_EXPORTED ;

#ifndef OPENNSL_HIDE_DISPATCHABLE

/***************************************************************************//** 
 *\brief Enable or disable a port.
 *
 *\description Controls whether a port is enabled or disabled for transmission
 *          and reception of packets.  The chip should not be configured so as
 *          to switch any packets to a disabled port because the packets may
 *          build up in the MMU.
 *
 *\param    unit [IN]   Unit number.
 *\param    port [IN]   Device or logical port number
 *\param    enable [IN]   Boolean value indicating enable (1) or disable (0).
 *
 *\retval    OPENNSL_E_NONE Operation completed successfully
 *\retval    OPENNSL_E_XXX Operation failed, if retrieving the current enabled
 *          state, the value of the parameter enable is undefined.
 ******************************************************************************/
extern int opennsl_port_enable_set(
    int unit, 
    opennsl_port_t port, 
    int enable) LIB_DLL_EXPORTED ;

/***************************************************************************//** 
 *\brief Enable or disable a port.
 *
 *\description Controls whether a port is enabled or disabled for transmission
 *          and reception of packets.  The chip should not be configured so as
 *          to switch any packets to a disabled port because the packets may
 *          build up in the MMU.
 *
 *\param    unit [IN]   Unit number.
 *\param    port [IN]   Device or logical port number
 *\param    enable [OUT]   Boolean value indicating enable (1) or disable (0).
 *
 *\retval    OPENNSL_E_NONE Operation completed successfully
 *\retval    OPENNSL_E_XXX Operation failed, if retrieving the current enabled
 *          state, the value of the parameter enable is undefined.
 ******************************************************************************/
extern int opennsl_port_enable_get(
    int unit, 
    opennsl_port_t port, 
    int *enable) LIB_DLL_EXPORTED ;

/***************************************************************************//** 
 *\brief Set or retrieve auto-negotiation abilities for a port.
 *
 *\description Set or retrieve the current auto-negotiation abilities for the
 *          specified port. If the port is currently operating with
 *          auto-negotiation disabled, these settings will be programmed into
 *          the underlying devices but not have an affect until
 *          auto-negotiation is enabled. If auto-negotiation is enabled when
 *          the settings are changed, auto-negotiation must be restarted using
 *          =opennsl_port_autoneg_set .
 *          Setting or retrieving the currently set ability structure can be
 *          done at any time, including with auto-negotiation disabled. The
 *          setting will only take affect when auto-negotiation is enabled or
 *          restarted. See.
 *
 *\param    unit [IN]   Unit number.
 *\param    port [IN]   Physical or logical port to query or set information on.
 *\param    ability_mask [IN]   Extended abilities structure,
 *          =EXTENDED_PORT_ABILITY_s .
 *
 *\retval    OPENNSL_E_NONE Requested action performed.
 *\retval    OPENNSL_E_XXX Operation failed
 ******************************************************************************/
extern int opennsl_port_ability_advert_set(
    int unit, 
    opennsl_port_t port, 
    opennsl_port_ability_t *ability_mask) LIB_DLL_EXPORTED ;

/***************************************************************************//** 
 *\brief Set or retrieve auto-negotiation abilities for a port.
 *
 *\description Set or retrieve the current auto-negotiation abilities for the
 *          specified port. If the port is currently operating with
 *          auto-negotiation disabled, these settings will be programmed into
 *          the underlying devices but not have an affect until
 *          auto-negotiation is enabled. If auto-negotiation is enabled when
 *          the settings are changed, auto-negotiation must be restarted using
 *          =opennsl_port_autoneg_set .
 *          Setting or retrieving the currently set ability structure can be
 *          done at any time, including with auto-negotiation disabled. The
 *          setting will only take affect when auto-negotiation is enabled or
 *          restarted. See.
 *
 *\param    unit [IN]   Unit number.
 *\param    port [IN]   Physical or logical port to query or set information on.
 *\param    ability_mask [OUT]   Extended abilities structure,
 *          =EXTENDED_PORT_ABILITY_s .
 *
 *\retval    OPENNSL_E_NONE Requested action performed.
 *\retval    OPENNSL_E_XXX Operation failed
 ******************************************************************************/
extern int opennsl_port_ability_advert_get(
    int unit, 
    opennsl_port_t port, 
    opennsl_port_ability_t *ability_mask) LIB_DLL_EXPORTED ;

/***************************************************************************//** 
 *\brief Retrieve the valid abilities of a local port.
 *
 *\description Retrieve the abilities of the specified local port.
 *
 *\param    unit [IN]   Unit number.
 *\param    port [IN]   Physical or logical port to query or set information on.
 *\param    local_ability_mask [OUT]   Extended ability structure 
 *          =EXTENDED_PORT_ABILITY_s
 *
 *\retval    OPENNSL_E_NONE Operation completed successfully
 *\retval    OPENNSL_E_XXX Operation failed, the return value local_ability_mask is
 *          undefined.
 ******************************************************************************/
extern int opennsl_port_ability_local_get(
    int unit, 
    opennsl_port_t port, 
    opennsl_port_ability_t *local_ability_mask) LIB_DLL_EXPORTED ;

#endif /* OPENNSL_HIDE_DISPATCHABLE */

#ifndef OPENNSL_HIDE_DISPATCHABLE

/***************************************************************************//** 
 *\brief Get or set the default VLAN for packets that ingress untagged.
 *
 *\description All packets that ingress a port untagged are treated as if they
 *          were tagged with the value specified by
 *          opennsl_port_untagged_vlan_set. All ports are initially configured
 *          with the untagged VLAN set to the default VLAN (or VLAN 1). If the
 *          packet egresses on a port that is configured as a tagged port, the
 *          VLAN ID in the egressing packet is set to this value.
 *          If the (port,vid) resolves to a VLAN gport, untagged packets will
 *          be sent to the to the VLAN port, and not the default VLAN. 
 *          Similarly, if (port,vid) resolves to a MPLS gport, untagged
 *          packets will be sent to the MPLS port and not to the default VLAN.
 *           In either case, the value does not affect the egress behavior of
 *          packets.
 *          To affect egress behavior of a VLAN gport, a GPORT ID is passed as
 *          the  port parameter.  The vid is used as the untagged vid on
 *          ingress into a PEP.  Specifically, when an STAG only packet
 *          arrives on a provider port, and egresses a customer port, the
 *          given vid is added to the untagged packet on egress.
 *          These APIs can also be used for WLAN gports. They will set/get the
 *          default  VLAN for untagged packets coming in from a WLAN source
 *          port.
 *
 *\param    unit [IN]   Unit number.
 *\param    port [IN]   Device port number or logical device
 *\param    vid [IN]   VLAN ID used for packets that ingress the port untagged.
 *
 *\retval    OPENNSL_E_NONE Operation completed successfully
 *\retval    OPENNSL_E_UNAVAIL The specified port cannot have an untagged VLAN.
 *\retval    OPENNSL_E_PARAM Invalid port or VLAN ID.
 *\retval    OPENNSL_E_XXX Operation failed
 ******************************************************************************/
extern int opennsl_port_untagged_vlan_set(
    int unit, 
    opennsl_port_t port, 
    opennsl_vlan_t vid) LIB_DLL_EXPORTED ;

/***************************************************************************//** 
 *\brief Get or set the default VLAN for packets that ingress untagged.
 *
 *\description All packets that ingress a port untagged are treated as if they
 *          were tagged with the value specified by
 *          opennsl_port_untagged_vlan_set. All ports are initially configured
 *          with the untagged VLAN set to the default VLAN (or VLAN 1). If the
 *          packet egresses on a port that is configured as a tagged port, the
 *          VLAN ID in the egressing packet is set to this value.
 *          If the (port,vid) resolves to a VLAN gport, untagged packets will
 *          be sent to the to the VLAN port, and not the default VLAN. 
 *          Similarly, if (port,vid) resolves to a MPLS gport, untagged
 *          packets will be sent to the MPLS port and not to the default VLAN.
 *           In either case, the value does not affect the egress behavior of
 *          packets.
 *          To affect egress behavior of a VLAN gport, a GPORT ID is passed as
 *          the  port parameter.  The vid is used as the untagged vid on
 *          ingress into a PEP.  Specifically, when an STAG only packet
 *          arrives on a provider port, and egresses a customer port, the
 *          given vid is added to the untagged packet on egress.
 *          These APIs can also be used for WLAN gports. They will set/get the
 *          default  VLAN for untagged packets coming in from a WLAN source
 *          port.
 *
 *\param    unit [IN]   Unit number.
 *\param    port [IN]   Device port number or logical device
 *\param    vid_ptr [OUT]   Pointer to location to store current default VLAN ID.
 *
 *\retval    OPENNSL_E_NONE Operation completed successfully
 *\retval    OPENNSL_E_UNAVAIL The specified port cannot have an untagged VLAN.
 *\retval    OPENNSL_E_PARAM Invalid port or VLAN ID.
 *\retval    OPENNSL_E_XXX Operation failed
 ******************************************************************************/
extern int opennsl_port_untagged_vlan_get(
    int unit, 
    opennsl_port_t port, 
    opennsl_vlan_t *vid_ptr) LIB_DLL_EXPORTED ;

#endif /* OPENNSL_HIDE_DISPATCHABLE */

#ifndef OPENNSL_HIDE_DISPATCHABLE

/***************************************************************************//** 
 *\brief Get or set the current operating speed of a port.
 *
 *\description Set or get the speed of the specified port. opennsl_port_speed_set
 *          disables auto-negotiation if it is enabled. When setting a speed,
 *          if an error is returned the PHY and the MAC may not be properly
 *          set for operation. A value of 0 indicates, set max speed. For
 *          correct operation  following an error, a valid speed must be set.
 *          When retrieving the current speed of a port, if auto-negotiation
 *          is enabled the current negotiated speed is returned. If
 *          auto-negotiation is in progress or there is no link, speed
 *          returned is undefined. If auto-negotiation is disabled, the forced
 *          speed of the port is returned regardless of the link state.
 *          opennsl_port_speed_max returns the maximum possible operating
 *          speed of the port based on the attributes of the MAC and the PHY.
 *
 *\param    unit [IN]   Unit number.
 *\param    port [IN]   Device or logical port number
 *\param    speed [OUT]   Speed specified in Mbps.
 *
 *\retval    OPENNSL_E_NONE Speed set or retrieved as requested.
 *\retval    OPENNSL_E_INIT Port module not initialized, see .
 *\retval    OPENNSL_E_CONFIG The requested port speed is not supported. In some
 *          configurations the actual speed of the MAC is derived from the PHY
 *          directly and can not be forced to a specific value.
 *\retval    OPENNSL_E_XXX Error occurred, if retrieving port speed, the returned
 *          speed is undefined. If setting speed, the operational state of the
 *          port is undefined.
 ******************************************************************************/
extern int opennsl_port_speed_max(
    int unit, 
    opennsl_port_t port, 
    int *speed) LIB_DLL_EXPORTED ;

/***************************************************************************//** 
 *\brief Get or set the current operating speed of a port.
 *
 *\description Set or get the speed of the specified port. opennsl_port_speed_set
 *          disables auto-negotiation if it is enabled. When setting a speed,
 *          if an error is returned the PHY and the MAC may not be properly
 *          set for operation. A value of 0 indicates, set max speed. For
 *          correct operation  following an error, a valid speed must be set.
 *          When retrieving the current speed of a port, if auto-negotiation
 *          is enabled the current negotiated speed is returned. If
 *          auto-negotiation is in progress or there is no link, speed
 *          returned is undefined. If auto-negotiation is disabled, the forced
 *          speed of the port is returned regardless of the link state.
 *          opennsl_port_speed_max returns the maximum possible operating
 *          speed of the port based on the attributes of the MAC and the PHY.
 *
 *\param    unit [IN]   Unit number.
 *\param    port [IN]   Device or logical port number
 *\param    speed [IN]   Speed specified in Mbps.
 *
 *\retval    OPENNSL_E_NONE Speed set or retrieved as requested.
 *\retval    OPENNSL_E_INIT Port module not initialized, see .
 *\retval    OPENNSL_E_CONFIG The requested port speed is not supported. In some
 *          configurations the actual speed of the MAC is derived from the PHY
 *          directly and can not be forced to a specific value.
 *\retval    OPENNSL_E_XXX Error occurred, if retrieving port speed, the returned
 *          speed is undefined. If setting speed, the operational state of the
 *          port is undefined.
 ******************************************************************************/
extern int opennsl_port_speed_set(
    int unit, 
    opennsl_port_t port, 
    int speed) LIB_DLL_EXPORTED ;

/***************************************************************************//** 
 *\brief Get or set the current operating speed of a port.
 *
 *\description Set or get the speed of the specified port. opennsl_port_speed_set
 *          disables auto-negotiation if it is enabled. When setting a speed,
 *          if an error is returned the PHY and the MAC may not be properly
 *          set for operation. A value of 0 indicates, set max speed. For
 *          correct operation  following an error, a valid speed must be set.
 *          When retrieving the current speed of a port, if auto-negotiation
 *          is enabled the current negotiated speed is returned. If
 *          auto-negotiation is in progress or there is no link, speed
 *          returned is undefined. If auto-negotiation is disabled, the forced
 *          speed of the port is returned regardless of the link state.
 *          opennsl_port_speed_max returns the maximum possible operating
 *          speed of the port based on the attributes of the MAC and the PHY.
 *
 *\param    unit [IN]   Unit number.
 *\param    port [IN]   Device or logical port number
 *\param    speed [OUT]   Speed specified in Mbps.
 *
 *\retval    OPENNSL_E_NONE Speed set or retrieved as requested.
 *\retval    OPENNSL_E_INIT Port module not initialized, see .
 *\retval    OPENNSL_E_CONFIG The requested port speed is not supported. In some
 *          configurations the actual speed of the MAC is derived from the PHY
 *          directly and can not be forced to a specific value.
 *\retval    OPENNSL_E_XXX Error occurred, if retrieving port speed, the returned
 *          speed is undefined. If setting speed, the operational state of the
 *          port is undefined.
 ******************************************************************************/
extern int opennsl_port_speed_get(
    int unit, 
    opennsl_port_t port, 
    int *speed) LIB_DLL_EXPORTED ;

#endif /* OPENNSL_HIDE_DISPATCHABLE */

/** opennsl_port_if_t */
typedef _shr_port_if_t opennsl_port_if_t;

#define OPENNSL_PORT_IF_NOCXN       _SHR_PORT_IF_NOCXN 
#define OPENNSL_PORT_IF_NULL        _SHR_PORT_IF_NULL 
#define OPENNSL_PORT_IF_MII         _SHR_PORT_IF_MII 
#define OPENNSL_PORT_IF_GMII        _SHR_PORT_IF_GMII 
#define OPENNSL_PORT_IF_SGMII       _SHR_PORT_IF_SGMII 
#define OPENNSL_PORT_IF_TBI         _SHR_PORT_IF_TBI 
#define OPENNSL_PORT_IF_XGMII       _SHR_PORT_IF_XGMII 
#define OPENNSL_PORT_IF_RGMII       _SHR_PORT_IF_RGMII 
#define OPENNSL_PORT_IF_SFI         _SHR_PORT_IF_SFI 
#define OPENNSL_PORT_IF_XFI         _SHR_PORT_IF_XFI 
#define OPENNSL_PORT_IF_KR          _SHR_PORT_IF_KR 
#define OPENNSL_PORT_IF_KR2         _SHR_PORT_IF_KR2 
#define OPENNSL_PORT_IF_KR4         _SHR_PORT_IF_KR4 
#define OPENNSL_PORT_IF_CR          _SHR_PORT_IF_CR 
#define OPENNSL_PORT_IF_CR2         _SHR_PORT_IF_CR2 
#define OPENNSL_PORT_IF_CR4         _SHR_PORT_IF_CR4 
#define OPENNSL_PORT_IF_XLAUI       _SHR_PORT_IF_XLAUI 
#define OPENNSL_PORT_IF_XLAUI2      _SHR_PORT_IF_XLAUI2 
#define OPENNSL_PORT_IF_RXAUI       _SHR_PORT_IF_RXAUI 
#define OPENNSL_PORT_IF_XAUI        _SHR_PORT_IF_XAUI 
#define OPENNSL_PORT_IF_SPAUI       _SHR_PORT_IF_SPAUI 
#define OPENNSL_PORT_IF_QSGMII      _SHR_PORT_IF_QSGMII 
#define OPENNSL_PORT_IF_ILKN        _SHR_PORT_IF_ILKN 
#define OPENNSL_PORT_IF_RCY         _SHR_PORT_IF_RCY 
#define OPENNSL_PORT_IF_FAT_PIPE    _SHR_PORT_IF_FAT_PIPE 
#define OPENNSL_PORT_IF_SR          _SHR_PORT_IF_SR 
#define OPENNSL_PORT_IF_SR2         _SHR_PORT_IF_SR2 
#define OPENNSL_PORT_IF_CAUI        _SHR_PORT_IF_CAUI 
#define OPENNSL_PORT_IF_LR          _SHR_PORT_IF_LR 
#define OPENNSL_PORT_IF_LR4         _SHR_PORT_IF_LR4 
#define OPENNSL_PORT_IF_SR4         _SHR_PORT_IF_SR4 
#define OPENNSL_PORT_IF_KX          _SHR_PORT_IF_KX 
#define OPENNSL_PORT_IF_ZR          _SHR_PORT_IF_ZR 
#define OPENNSL_PORT_IF_SR10        _SHR_PORT_IF_SR10 
#define OPENNSL_PORT_IF_OTL         _SHR_PORT_IF_OTL 
#define OPENNSL_PORT_IF_CPU         _SHR_PORT_IF_CPU 
#define OPENNSL_PORT_IF_COUNT       _SHR_PORT_IF_COUNT 
#define OPENNSL_PORT_IF_10B     OPENNSL_PORT_IF_TBI /**< Deprecated */
#ifndef OPENNSL_HIDE_DISPATCHABLE

/***************************************************************************//** 
 *\brief Configure the physical interface between the MAC and the PHY for the
 *       specified port.
 *
 *\description Provides ability to change the physical interface used between the
 *          MAC in the switch device and the PHY. Under normal conditions this
 *          setting will be configured during port initialization and should
 *          not change. This function is provided for diagnostic purposes
 *          only. For information on initial physical interface settings, see.
 *
 *\param    unit [IN]   Unit number.
 *\param    port [IN]   Device or logical port number
 *\param    intf [IN]   Interface to configure or retrieved interface setting.
 *
 *\retval    OPENNSL_E_NONE Operation performed successfully
 *\retval    OPENNSL_E_INIT Port module not initialized, see .
 *\retval    OPENNSL_E_UNAVAIL Requested interface is not available on the
 *          specified port.
 *\retval    OPENNSL_E_XXX Operation failed, if retrieving current operating mode
 *          result value in intf is undefined.
 ******************************************************************************/
extern int opennsl_port_interface_set(
    int unit, 
    opennsl_port_t port, 
    opennsl_port_if_t intf) LIB_DLL_EXPORTED ;

/***************************************************************************//** 
 *\brief Configure the physical interface between the MAC and the PHY for the
 *       specified port.
 *
 *\description Provides ability to change the physical interface used between the
 *          MAC in the switch device and the PHY. Under normal conditions this
 *          setting will be configured during port initialization and should
 *          not change. This function is provided for diagnostic purposes
 *          only. For information on initial physical interface settings, see.
 *
 *\param    unit [IN]   Unit number.
 *\param    port [IN]   Device or logical port number
 *\param    intf [OUT]   Interface to configure or retrieved interface setting.
 *
 *\retval    OPENNSL_E_NONE Operation performed successfully
 *\retval    OPENNSL_E_INIT Port module not initialized, see .
 *\retval    OPENNSL_E_UNAVAIL Requested interface is not available on the
 *          specified port.
 *\retval    OPENNSL_E_XXX Operation failed, if retrieving current operating mode
 *          result value in intf is undefined.
 ******************************************************************************/
extern int opennsl_port_interface_get(
    int unit, 
    opennsl_port_t port, 
    opennsl_port_if_t *intf) LIB_DLL_EXPORTED ;

#endif /* OPENNSL_HIDE_DISPATCHABLE */

/** opennsl_port_duplex_t */
typedef _shr_port_duplex_t opennsl_port_duplex_t;

#define OPENNSL_PORT_DUPLEX_HALF    _SHR_PORT_DUPLEX_HALF 
#define OPENNSL_PORT_DUPLEX_FULL    _SHR_PORT_DUPLEX_FULL 
#define OPENNSL_PORT_DUPLEX_COUNT   _SHR_PORT_DUPLEX_COUNT 
#ifndef OPENNSL_HIDE_DISPATCHABLE

/***************************************************************************//** 
 *\brief Set or retrieve the current maximum packet size permitted on a port.
 *
 *\description Set or retrieve the current maximum frame size for the specified
 *          port. The frame size may be different for ports supporting
 *          multiple speeds. For this reason, whenever the speed of a port
 *          changes the frame size should be set to the desired length.
 *          This API can be used to enable jumbo frames on a port by setting
 *          the frame size to a jumbo value.
 *          When setting the frame size on a port, it is the callers
 *          responsibility to take into account any additional tags or CRC
 *          that may be added by the switch device. For example, when
 *          configuring HiGig ports or stacking ports on some devices, a HiGig
 *          header or stack tag may be added to the packets.
 *          For front-panel ports (that is, non-stacking or HiGig ports),
 *          setting the maximum frame size to X indicates packets of length X
 *          + 4 are permitted.
 *
 *\param    unit [IN]   Unit number.
 *\param    port [IN]   Port to set or retrieve maximum frame size on
 *\param    size [IN]   The frame size to set (or current frame size returned) in
 *          bytes.
 *
 *\retval    OPENNSL_E_NONE Operation completed successfully
 *\retval    OPENNSL_E_INIT Port module not initialized, see .
 *\retval    OPENNSL_E_XXX Operation failed, current frame size for port is
 *          undefined.
 ******************************************************************************/
extern int opennsl_port_frame_max_set(
    int unit, 
    opennsl_port_t port, 
    int size) LIB_DLL_EXPORTED ;

/***************************************************************************//** 
 *\brief Set or retrieve the current maximum packet size permitted on a port.
 *
 *\description Set or retrieve the current maximum frame size for the specified
 *          port. The frame size may be different for ports supporting
 *          multiple speeds. For this reason, whenever the speed of a port
 *          changes the frame size should be set to the desired length.
 *          This API can be used to enable jumbo frames on a port by setting
 *          the frame size to a jumbo value.
 *          When setting the frame size on a port, it is the callers
 *          responsibility to take into account any additional tags or CRC
 *          that may be added by the switch device. For example, when
 *          configuring HiGig ports or stacking ports on some devices, a HiGig
 *          header or stack tag may be added to the packets.
 *          For front-panel ports (that is, non-stacking or HiGig ports),
 *          setting the maximum frame size to X indicates packets of length X
 *          + 4 are permitted.
 *
 *\param    unit [IN]   Unit number.
 *\param    port [IN]   Port to set or retrieve maximum frame size on
 *\param    size [OUT]   The frame size to set (or current frame size returned) in
 *          bytes.
 *
 *\retval    OPENNSL_E_NONE Operation completed successfully
 *\retval    OPENNSL_E_INIT Port module not initialized, see .
 *\retval    OPENNSL_E_XXX Operation failed, current frame size for port is
 *          undefined.
 ******************************************************************************/
extern int opennsl_port_frame_max_get(
    int unit, 
    opennsl_port_t port, 
    int *size) LIB_DLL_EXPORTED ;

#endif /* OPENNSL_HIDE_DISPATCHABLE */

#define OPENNSL_PORT_PHY_CLAUSE45   _SHR_PORT_PHY_CLAUSE45 
#define OPENNSL_PORT_PHY_CLAUSE45_ADDR(_devad, _regad)  \
    _SHR_PORT_PHY_CLAUSE45_ADDR(_devad, _regad) 
#ifndef OPENNSL_HIDE_DISPATCHABLE

/***************************************************************************//** 
 *\brief Read or write PHY registers associated with a port.
 *
 *\description Most PHY-related operations are performed automatically by the API
 *          to satisfy requests. When direct access to the PHY registers are
 *          required for diagnostic purposes or special configuration these
 *          functions can be used. Use of these routines may interfere with
 *          the normal operation of the API, extreme care must be taken when
 *          manipulating PHYs. Normal configuration of speed, duplicity, and
 *          auto-negotiation must be performed using the normal opennsl_port
 *          APIs. .
 *
 *\param    unit [IN]   Unit number.
 *\param    port [IN]   Device or logical port number
 *\param    flags [IN]   Flags indicating how to access the PHY, and which PHY if
 *          the port has an internal serdes. See =OPENNSL_PORT_PHY_flags for
 *          details.
 *\param    phy_reg_addr [IN]   Register address in the PHY
 *\param    phy_data [IN]   Data to be written or data read
 *\param    phy_mask [IN]   Mask write data when modifying register
 *
 *\retval    OPENNSL_E_NONE Operation completed successfully
 *\retval    OPENNSL_E_UNAVAIL Requested operation not supported
 *\retval    OPENNSL_E_XXX Operation failed
 ******************************************************************************/
extern int opennsl_port_phy_modify(
    int unit, 
    opennsl_port_t port, 
    uint32 flags, 
    uint32 phy_reg_addr, 
    uint32 phy_data, 
    uint32 phy_mask) LIB_DLL_EXPORTED ;

#endif /* OPENNSL_HIDE_DISPATCHABLE */

/** MDI crossover control. */
typedef _shr_port_mdix_t opennsl_port_mdix_t;

#define OPENNSL_PORT_MDIX_AUTO          _SHR_PORT_MDIX_AUTO 
#define OPENNSL_PORT_MDIX_FORCE_AUTO    _SHR_PORT_MDIX_FORCE_AUTO 
#define OPENNSL_PORT_MDIX_NORMAL        _SHR_PORT_MDIX_NORMAL 
#define OPENNSL_PORT_MDIX_XOVER         _SHR_PORT_MDIX_XOVER 
#define OPENNSL_PORT_MDIX_COUNT         _SHR_PORT_MDIX_COUNT 
/** MDI crossover status. */
typedef _shr_port_mdix_status_t opennsl_port_mdix_status_t;

#define OPENNSL_PORT_MDIX_STATUS_NORMAL _SHR_PORT_MDIX_STATUS_NORMAL 
#define OPENNSL_PORT_MDIX_STATUS_XOVER  _SHR_PORT_MDIX_STATUS_XOVER 
#define OPENNSL_PORT_MDIX_STATUS_COUNT  _SHR_PORT_MDIX_STATUS_COUNT 
/** Combo port control/status. */
typedef _shr_port_medium_t opennsl_port_medium_t;

#define OPENNSL_PORT_MEDIUM_NONE    _SHR_PORT_MEDIUM_NONE 
#define OPENNSL_PORT_MEDIUM_COPPER  _SHR_PORT_MEDIUM_COPPER 
#define OPENNSL_PORT_MEDIUM_FIBER   _SHR_PORT_MEDIUM_FIBER 
#define OPENNSL_PORT_MEDIUM_COUNT   _SHR_PORT_MEDIUM_COUNT 
#define OPENNSL_PORT_LEARN_ARL      0x01       /**< Learn SLF address. */
#define OPENNSL_PORT_LEARN_CPU      0x02       /**< Copy SLF packet to CPU. */
#define OPENNSL_PORT_LEARN_FWD      0x04       /**< Forward SLF packet */
#define OPENNSL_PORT_LEARN_PENDING  0x08       /**< Mark learned SLF as pending */
#ifndef OPENNSL_HIDE_DISPATCHABLE

/***************************************************************************//** 
 *\brief Control the hardware and software learning support on a port.
 *
 *\description The learning mode configures what set of actions are taken by the
 *          device when an unknown source address is recognized on an
 *          ingressing packet. Each of the learning options can be configured
 *          independently, however the underlying switch device may not
 *          support all combinations. The possible learning modes are
 *          described in =OPENNSL_PORT_LEARN_table .
 *          opennsl_port_learn_set and opennsl_port_learn_get get and set the
 *          current learning mode based on the flags parameter.
 *          opennsl_port_learn_modify allows learning options to be removed
 *          and or added based on the add and remove parameters.
 *
 *\param    unit [IN]   Unit number.
 *\param    port [IN]   Device or logical port
 *\param    flags [IN]   Learning flags as defined in table
 *          =OPENNSL_PORT_LEARN_table
 *
 *\retval    OPENNSL_E_NONE Operation completed successfully.
 *\retval    OPENNSL_E_UNAVAIL Requested learning configuration not supported on
 *          device, the learning mode of the port is unchanged.
 *\retval    OPENNSL_E_INIT Port module not initialized, see .
 *\retval    OPENNSL_E_XXX Operation failed, port state undefined on set or modify,
 *          returned flags value undefined if retrieving status.
 ******************************************************************************/
extern int opennsl_port_learn_set(
    int unit, 
    opennsl_port_t port, 
    uint32 flags) LIB_DLL_EXPORTED ;

/***************************************************************************//** 
 *\brief Control the hardware and software learning support on a port.
 *
 *\description The learning mode configures what set of actions are taken by the
 *          device when an unknown source address is recognized on an
 *          ingressing packet. Each of the learning options can be configured
 *          independently, however the underlying switch device may not
 *          support all combinations. The possible learning modes are
 *          described in =OPENNSL_PORT_LEARN_table .
 *          opennsl_port_learn_set and opennsl_port_learn_get get and set the
 *          current learning mode based on the flags parameter.
 *          opennsl_port_learn_modify allows learning options to be removed
 *          and or added based on the add and remove parameters.
 *
 *\param    unit [IN]   Unit number.
 *\param    port [IN]   Device or logical port
 *\param    flags [OUT]   Learning flags as defined in table
 *          =OPENNSL_PORT_LEARN_table
 *
 *\retval    OPENNSL_E_NONE Operation completed successfully.
 *\retval    OPENNSL_E_UNAVAIL Requested learning configuration not supported on
 *          device, the learning mode of the port is unchanged.
 *\retval    OPENNSL_E_INIT Port module not initialized, see .
 *\retval    OPENNSL_E_XXX Operation failed, port state undefined on set or modify,
 *          returned flags value undefined if retrieving status.
 ******************************************************************************/
extern int opennsl_port_learn_get(
    int unit, 
    opennsl_port_t port, 
    uint32 *flags) LIB_DLL_EXPORTED ;

#endif /* OPENNSL_HIDE_DISPATCHABLE */

#define OPENNSL_PORT_LINK_STATUS_UP 1          
#ifndef OPENNSL_HIDE_DISPATCHABLE

/***************************************************************************//** 
 *\brief Retrieve the current link status of a port.
 *
 *\description This call returns the link status of the port. With linkscan
 *          running (see =linkscan ), the current link status is retrieved
 *          from the linkscan task. This is the normal mode of operation, as
 *          link status in the PHY registers is latched low. If multiple
 *          sources (threads) read the physical link status in the PHY
 *          register, the linkscan task and/or applications can miss a link
 *          down event.
 *          If linkscan is not running, the current link status is retrieved
 *          from the PHY directly.
 *          The possible values of status are:.
 *
 *\param    unit [IN]   Unit number.
 *\param    port [IN]   Device or logical port number.
 *\param    status [OUT]   One of OPENNSL_PORT_LINK_STATUS_*.
 *
 *\retval    OPENNSL_E_NONE Current link state is returned in status
 *\retval    OPENNSL_E_INIT Port module not initialized
 *\retval    OPENNSL_E_XXX Error condition reported from lower layers of software.
 *          In the event of an error code other than OPENNSL_E_NONE, the up
 *          parameter is undefined on return.
 ******************************************************************************/
extern int opennsl_port_link_status_get(
    int unit, 
    opennsl_port_t port, 
    int *status) LIB_DLL_EXPORTED ;

#endif /* OPENNSL_HIDE_DISPATCHABLE */

#define OPENNSL_PORT_VLAN_MEMBER_INGRESS    0x00000001 
#define OPENNSL_PORT_VLAN_MEMBER_EGRESS     0x00000002 
#ifndef OPENNSL_HIDE_DISPATCHABLE

/***************************************************************************//** 
 *\brief Set or retrieve current behavior of tagged packets arriving/leaving on a
 *       port not a member of the specified VLAN.
 *
 *\description Ingress/egress filtering, if enabled, drops all packets
 *          arriving/leaving on a  port with a VLAN tag identifying a VLAN of
 *          which the port is not a member. If disabled, packets will not be
 *          dropped if the port is not a member of the VLAN specified in the
 *          packet. It may however be dropped for other reasons such as
 *          spanning tree state, head of line blocking etc. For switch
 *          family?III, ingress filtering is also applied.
 *          This function supersedes =opennsl_port_ifilter_get . Valid
 *          settings for flags are described in
 *          =OPENNSL_PORT_VLAN_MEMBER_FLAGS_table .
 *
 *\param    unit [IN]   Unit number.
 *\param    port [IN]   Device or logical port number
 *\param    flags [IN]   Flags to indicate port filtering mode
 *
 *\retval    OPENNSL_E_NONE Operation completed successfully
 *\retval    OPENNSL_E_UNAVAIL Operation not supported on underlying device
 *\retval    OPENNSL_E_XXX Operation failed.
 ******************************************************************************/
extern int opennsl_port_vlan_member_set(
    int unit, 
    opennsl_port_t port, 
    uint32 flags) LIB_DLL_EXPORTED ;

/***************************************************************************//** 
 *\brief Set or retrieve current behavior of tagged packets arriving/leaving on a
 *       port not a member of the specified VLAN.
 *
 *\description Ingress/egress filtering, if enabled, drops all packets
 *          arriving/leaving on a  port with a VLAN tag identifying a VLAN of
 *          which the port is not a member. If disabled, packets will not be
 *          dropped if the port is not a member of the VLAN specified in the
 *          packet. It may however be dropped for other reasons such as
 *          spanning tree state, head of line blocking etc. For switch
 *          family?III, ingress filtering is also applied.
 *          This function supersedes =opennsl_port_ifilter_get . Valid
 *          settings for flags are described in
 *          =OPENNSL_PORT_VLAN_MEMBER_FLAGS_table .
 *
 *\param    unit [IN]   Unit number.
 *\param    port [IN]   Device or logical port number
 *\param    flags [OUT]   Flags to indicate port filtering mode
 *
 *\retval    OPENNSL_E_NONE Operation completed successfully
 *\retval    OPENNSL_E_UNAVAIL Operation not supported on underlying device
 *\retval    OPENNSL_E_XXX Operation failed.
 ******************************************************************************/
extern int opennsl_port_vlan_member_get(
    int unit, 
    opennsl_port_t port, 
    uint32 *flags) LIB_DLL_EXPORTED ;

#endif /* OPENNSL_HIDE_DISPATCHABLE */

#ifndef OPENNSL_HIDE_DISPATCHABLE

/***************************************************************************//** 
 *\brief Get the current count of cells or packets queued on a port for
 *       transmission.
 *
 *\description Returns a count that is either the number of internal device cells
 *          (device specific) or the number of packets queued for egress on
 *          the specified port. In general, the count returned should only be
 *          considered as 0 (indicating there are no packets queued on the
 *          port) or >0 (indicating some packets are queued on the port).
 *
 *\param    unit [IN]   Unit number.
 *\param    port [IN]   Device or logical port number.
 *\param    count [OUT]   Returned count of cells or packets queued for egress on
 *          the specified port.
 *
 *\retval    OPENNSL_E_NONE Operation completed successfully
 *\retval    OPENNSL_E_BADID Invalid port number specified
 *\retval    OPENNSL_E_UNAVIL Operation not supported on the specified port.
 ******************************************************************************/
extern int opennsl_port_queued_count_get(
    int unit, 
    opennsl_port_t port, 
    uint32 *count) LIB_DLL_EXPORTED ;

#endif /* OPENNSL_HIDE_DISPATCHABLE */

#define OPENNSL_PORT_DTAG_MODE_NONE     0          /**< No double tagging. */
#define OPENNSL_PORT_DTAG_MODE_INTERNAL 1          /**< Service Provider port. */
#define OPENNSL_PORT_DTAG_MODE_EXTERNAL 2          /**< Customer port. */
#ifndef OPENNSL_HIDE_DISPATCHABLE

/***************************************************************************//** 
 *\brief Set or retrieve the current double tagging mode for a port.
 *
 *\description Configuring double tagging requires the caller configure the TPID
 *          inserted using =opennsl_port_tpid_set .
 *          Depending on the underlying device, double tagging may be enabled
 *          on a per port basis or only on a system wide basis. If a specific
 *          port is requested and double tagging is only supported on a device
 *          basis, then this call will affect all ports.
 *          Valid values for double tagging mode are defined in table.
 *
 *\param    unit [IN]   Unit number.
 *\param    port [IN]   Device or logical port number
 *\param    mode [IN]   Double tag mode as defined in table
 *          =OPENNSL_PORT_DTAG_MODE_table
 *
 *\retval    OPENNSL_E_NONE Operation completed successfully
 *\retval    OPENNSL_E_UNAVAIL Requested double tagging mode is not support on the
 *          device.
 *\retval    OPENNSL_E_XXX Operation failed, if retrieving the current operating
 *          mode, the value of the parameter mode is undefined.
 ******************************************************************************/
extern int opennsl_port_dtag_mode_set(
    int unit, 
    opennsl_port_t port, 
    int mode) LIB_DLL_EXPORTED ;

/***************************************************************************//** 
 *\brief Set or retrieve the current double tagging mode for a port.
 *
 *\description Configuring double tagging requires the caller configure the TPID
 *          inserted using =opennsl_port_tpid_set .
 *          Depending on the underlying device, double tagging may be enabled
 *          on a per port basis or only on a system wide basis. If a specific
 *          port is requested and double tagging is only supported on a device
 *          basis, then this call will affect all ports.
 *          Valid values for double tagging mode are defined in table.
 *
 *\param    unit [IN]   Unit number.
 *\param    port [IN]   Device or logical port number
 *\param    mode [OUT]   Double tag mode as defined in table
 *          =OPENNSL_PORT_DTAG_MODE_table
 *
 *\retval    OPENNSL_E_NONE Operation completed successfully
 *\retval    OPENNSL_E_UNAVAIL Requested double tagging mode is not support on the
 *          device.
 *\retval    OPENNSL_E_XXX Operation failed, if retrieving the current operating
 *          mode, the value of the parameter mode is undefined.
 ******************************************************************************/
extern int opennsl_port_dtag_mode_get(
    int unit, 
    opennsl_port_t port, 
    int *mode) LIB_DLL_EXPORTED ;

#endif /* OPENNSL_HIDE_DISPATCHABLE */

#define OPENNSL_PORT_ATTR_ENABLE_MASK       0x00000001 
#define OPENNSL_PORT_ATTR_AUTONEG_MASK      0x00000004 
#define OPENNSL_PORT_ATTR_SPEED_MASK        0x00000008 
#define OPENNSL_PORT_ATTR_DUPLEX_MASK       0x00000010 
#define OPENNSL_PORT_ATTR_PAUSE_TX_MASK     0x00010000 
#define OPENNSL_PORT_ATTR_PAUSE_RX_MASK     0x00020000 
#define OPENNSL_PORT_ATTR_LOCAL_ADVERT_MASK 0x00080000 
#define OPENNSL_PORT_ATTR_FRAME_MAX_MASK    0x08000000 
#define OPENNSL_PORT_ATTR2_PORT_ABILITY     0x00000001 
#define OPENNSL_PORT_ATTR_ALL_MASK  0xffffffff 
/** opennsl_port_info_s */
typedef struct opennsl_port_info_s {
    uint32 action_mask;                 /**< OPENNSL_PORT_ATTR_xxx. */
    uint32 action_mask2;                /**< OPENNSL_PORT_ATTR2_xxx. */
    int enable;                         
    int linkstatus;                     
    int autoneg;                        
    int speed;                          
    int duplex;                         
    int linkscan;                       
    uint32 learn;                       
    int discard;                        
    uint32 vlanfilter;                  
    int untagged_priority;              
    opennsl_vlan_t untagged_vlan;       
    int stp_state;                      
    int pfm;                            
    int loopback;                       
    int phy_master;                     
    opennsl_port_if_t interface;        
    int pause_tx;                       
    int pause_rx;                       
    int encap_mode;                     
    opennsl_mac_t pause_mac;            
    opennsl_port_abil_t local_advert;   
    opennsl_port_ability_t local_ability; 
    int remote_advert_valid;            
    opennsl_port_abil_t remote_advert;  
    opennsl_port_ability_t remote_ability; 
    int mcast_limit;                    
    int mcast_limit_enable;             
    int bcast_limit;                    
    int bcast_limit_enable;             
    int dlfbc_limit;                    
    int dlfbc_limit_enable;             
    int speed_max;                      
    opennsl_port_abil_t ability;        
    opennsl_port_ability_t port_ability; 
    int frame_max;                      
    opennsl_port_mdix_t mdix;           
    opennsl_port_mdix_status_t mdix_status; 
    opennsl_port_medium_t medium;       
    uint32 fault;                       
} opennsl_port_info_t;

#ifndef OPENNSL_HIDE_DISPATCHABLE

/***************************************************************************//** 
 *\brief Get or set multiple port characteristics.
 *
 *\description opennsl_port_info_get and opennsl_port_info_set get and set all
 *          valid settings for the specific device and port in question. For
 *          these calls the action_mask field of the opennsl_port_info_t
 *          structure is ignored on entry, but defined to contain the valid
 *          action mask bits on return.
 *          For all set operations, if both auto-negotiation is enabled and
 *          the speed or duplex are forced to a specific setting, the result
 *          is undefined.
 *          opennsl_port_selective_get and opennsl_port_selective_set operate
 *          similar to opennsl_port_info_get and opennsl_port_info_set with
 *          the exception that action_mask is used to determine which
 *          attributes to set or retrieve.
 *          opennsl_port_info_save and opennsl_port_info_restore provide a
 *          mechanism to save all valid port state and restore it later. The
 *          info parameter to opennsl_port_info_save must be passed unaltered
 *          to opennsl_port_info_restore to restore the previous port state.
 *          Any changes to the info structure results in undefined behavior.
 *          In the case of setting or restoring port configuration, if the API
 *          call returns an error the port state is undefined. Other than as
 *          is required for proper functionality, the order is which the
 *          configuration options are applied is undefined.
 *          Similarly when retrieving options, if an error is returned the
 *          entire contents of the info structure are undefined.
 *          For example, all three implementations of the function
 *          sample_port_speed_get below perform the same function.
 *
 *\param    unit [IN]   Unit number.
 *\param    port [IN]   Device or logical port number
 *\param    info [IN,OUT]   Pointer to port information structure (see
 *          =PORT_INFORMATION_CONTROL).
 *
 *\retval    OPENNSL_E_NONE Operation completed successfully.
 *\retval    OPENNSL_E_XXX Operation failed, if retrieving information the contents
 *          of info are undefined. If setting configuration, the state of the port
 *          is undefined.
 ******************************************************************************/
extern int opennsl_port_selective_get(
    int unit, 
    opennsl_port_t port, 
    opennsl_port_info_t *info) LIB_DLL_EXPORTED ;

/***************************************************************************//** 
 *\brief Get or set multiple port characteristics.
 *
 *\description opennsl_port_info_get and opennsl_port_info_set get and set all
 *          valid settings for the specific device and port in question. For
 *          these calls the action_mask field of the opennsl_port_info_t
 *          structure is ignored on entry, but defined to contain the valid
 *          action mask bits on return.
 *          For all set operations, if both auto-negotiation is enabled and
 *          the speed or duplex are forced to a specific setting, the result
 *          is undefined.
 *          opennsl_port_selective_get and opennsl_port_selective_set operate
 *          similar to opennsl_port_info_get and opennsl_port_info_set with
 *          the exception that action_mask is used to determine which
 *          attributes to set or retrieve.
 *          opennsl_port_info_save and opennsl_port_info_restore provide a
 *          mechanism to save all valid port state and restore it later. The
 *          info parameter to opennsl_port_info_save must be passed unaltered
 *          to opennsl_port_info_restore to restore the previous port state.
 *          Any changes to the info structure results in undefined behavior.
 *          In the case of setting or restoring port configuration, if the API
 *          call returns an error the port state is undefined. Other than as
 *          is required for proper functionality, the order is which the
 *          configuration options are applied is undefined.
 *          Similarly when retrieving options, if an error is returned the
 *          entire contents of the info structure are undefined.
 *          For example, all three implementations of the function
 *          sample_port_speed_get below perform the same function.
 *
 *\param    unit [IN]   Unit number.
 *\param    port [IN]   Device or logical port number
 *\param    info [IN]   Pointer to port information structure (see
 *          =PORT_INFORMATION_CONTROL).
 *
 *\retval    OPENNSL_E_NONE Operation completed successfully.
 *\retval    OPENNSL_E_XXX Operation failed, if retrieving information the contents
 *          of info are undefined. If setting configuration, the state of the port
 *          is undefined.
 ******************************************************************************/
extern int opennsl_port_selective_set(
    int unit, 
    opennsl_port_t port, 
    opennsl_port_info_t *info) LIB_DLL_EXPORTED ;

#endif /* OPENNSL_HIDE_DISPATCHABLE */

/** Features that can be controlled on a per-port basis. */
typedef enum opennsl_port_control_e {
    opennslportReservedEnum1 = 0, 
    opennslportReservedEnum2 = 1, 
    opennslportReservedEnum3 = 2, 
    opennslportReservedEnum4 = 3, 
    opennslportReservedEnum5 = 4, 
    opennslportReservedEnum6 = 5, 
    opennslportReservedEnum7 = 6, 
    opennslportReservedEnum8 = 7, 
    opennslPortControlIP4 = 8,          /**< Enable IPv4 Routing on port. */
    opennslPortControlIP6 = 9,          /**< Enable IPv6 Routing on port. */
    opennslportReservedEnum9 = 10, 
    opennslportReservedEnum10 = 11, 
    opennslportReservedEnum11 = 12, 
    opennslportReservedEnum12 = 13, 
    opennslportReservedEnum13 = 14, 
    opennslportReservedEnum14 = 15, 
    opennslportReservedEnum15 = 16, 
    opennslportReservedEnum16 = 17, 
    opennslportReservedEnum17 = 18, 
    opennslportReservedEnum18 = 19, 
    opennslportReservedEnum19 = 20, 
    opennslportReservedEnum20 = 21, 
    opennslPortControlTrustIncomingVlan = 22, /**< Trust incoming packet's Vlan tag */
    opennslPortControlDoNotCheckVlan = 23, /**< Enable/disable spanning tree and Vlan
                                           membership checks on ingress ethernet
                                           and higig packets. For cpu port
                                           configuration is applied only for
                                           higig packets. To configure these
                                           settings for ethernet packets
                                           opennslPortControlDoNotCheckVlanFromCpu
                                           port control can be used. */
    opennslportReservedEnum21 = 24, 
    opennslportReservedEnum22 = 25, 
    opennslportReservedEnum23 = 26, 
    opennslportReservedEnum24 = 27, 
    opennslportReservedEnum25 = 28, 
    opennslportReservedEnum26 = 29, 
    opennslportReservedEnum27 = 30, 
    opennslportReservedEnum28 = 31, 
    opennslportReservedEnum29 = 32, 
    opennslportReservedEnum30 = 33, 
    opennslportReservedEnum31 = 34, 
    opennslportReservedEnum32 = 35, 
    opennslportReservedEnum33 = 36, 
    opennslportReservedEnum34 = 37, 
    opennslportReservedEnum35 = 38, 
    opennslportReservedEnum36 = 39, 
    opennslportReservedEnum37 = 40, 
    opennslportReservedEnum38 = 41, 
    opennslportReservedEnum39 = 42, 
    opennslportReservedEnum40 = 43, 
    opennslportReservedEnum41 = 44, 
    opennslportReservedEnum42 = 45, 
    opennslportReservedEnum43 = 46, 
    opennslportReservedEnum44 = 47, 
    opennslportReservedEnum45 = 48, 
    opennslportReservedEnum46 = 49, 
    opennslportReservedEnum47 = 50, 
    opennslportReservedEnum48 = 51, 
    opennslportReservedEnum49 = 52, 
    opennslportReservedEnum50 = 53, 
    opennslportReservedEnum51 = 54, 
    opennslPortControlLanes = 55,       /**< Sets the number of active lanes for a
                                           port that can be dynamically
                                           hot-swapped between one 12G port
                                           (value = 1) or four 1G ports (value =
                                           4). */
    opennslportReservedEnum52 = 56, 
    opennslportReservedEnum53 = 57, 
    opennslportReservedEnum54 = 58, 
    opennslPortControlPFCReceive = 59,  /**< Priority Flow Control packet receive
                                           enable */
    opennslPortControlPFCTransmit = 60, /**< Priority Flow Control packet transmit
                                           enable */
    opennslPortControlPFCClasses = 61,  /**< Priority Flow Control number of
                                           classes */
    opennslPortControlPFCPassFrames = 62, /**< Allow Priority Flow Control packets
                                           into switch device */
    opennslportReservedEnum55 = 63, 
    opennslportReservedEnum56 = 64, 
    opennslportReservedEnum57 = 65, 
    opennslportReservedEnum58 = 66, 
    opennslportReservedEnum59 = 67, 
    opennslportReservedEnum60 = 68, 
    opennslportReservedEnum61 = 69, 
    opennslPortControlL2Move = 70,      /**< Configure L2 station movement
                                           behavior using OPENNSL_PORT_LEARN_xxx
                                           flags */
    opennslportReservedEnum62 = 71, 
    opennslportReservedEnum63 = 72, 
    opennslportReservedEnum64 = 73, 
    opennslportReservedEnum65 = 74, 
    opennslportReservedEnum66 = 75, 
    opennslportReservedEnum67 = 76, 
    opennslportReservedEnum68 = 77, 
    opennslportReservedEnum69 = 78, 
    opennslportReservedEnum70 = 79, 
    opennslportReservedEnum71 = 80, 
    opennslportReservedEnum72 = 81, 
    opennslportReservedEnum73 = 82, 
    opennslportReservedEnum74 = 83, 
    opennslportReservedEnum75 = 84, 
    opennslportReservedEnum76 = 85, 
    opennslportReservedEnum77 = 86, 
    opennslportReservedEnum78 = 87, 
    opennslportReservedEnum79 = 88, 
    opennslportReservedEnum80 = 89, 
    opennslportReservedEnum81 = 90, 
    opennslportReservedEnum82 = 91, 
    opennslPortControlStatOversize = 92, /**< Threshold above which packet will be
                                           counted as oversized */
    opennslportReservedEnum83 = 93, 
    opennslportReservedEnum84 = 94, 
    opennslportReservedEnum85 = 95, 
    opennslportReservedEnum86 = 96, 
    opennslportReservedEnum87 = 97, 
    opennslportReservedEnum88 = 98, 
    opennslportReservedEnum89 = 99, 
    opennslportReservedEnum90 = 100, 
    opennslportReservedEnum91 = 101, 
    opennslportReservedEnum92 = 102, 
    opennslportReservedEnum93 = 103, 
    opennslportReservedEnum94 = 104, 
    opennslportReservedEnum95 = 105, 
    opennslportReservedEnum96 = 106, 
    opennslportReservedEnum97 = 107, 
    opennslportReservedEnum98 = 108, 
    opennslportReservedEnum99 = 109, 
    opennslportReservedEnum100 = 110, 
    opennslportReservedEnum101 = 111, 
    opennslportReservedEnum102 = 112, 
    opennslportReservedEnum103 = 113, 
    opennslportReservedEnum104 = 114, 
    opennslportReservedEnum105 = 115, 
    opennslportReservedEnum106 = 116, 
    opennslportReservedEnum107 = 117, 
    opennslportReservedEnum108 = 118, 
    opennslportReservedEnum109 = 119, 
    opennslportReservedEnum110 = 120, 
    opennslportReservedEnum111 = 121, 
    opennslportReservedEnum112 = 122, 
    opennslportReservedEnum113 = 123, 
    opennslportReservedEnum114 = 124, 
    opennslportReservedEnum115 = 125, 
    opennslportReservedEnum116 = 126, 
    opennslportReservedEnum117 = 127, 
    opennslportReservedEnum118 = 128, 
    opennslportReservedEnum119 = 129, 
    opennslportReservedEnum120 = 130, 
    opennslportReservedEnum121 = 131, 
    opennslportReservedEnum122 = 132, 
    opennslportReservedEnum123 = 133, 
    opennslportReservedEnum124 = 134, 
    opennslportReservedEnum125 = 135, 
    opennslportReservedEnum126 = 136, 
    opennslportReservedEnum127 = 137, 
    opennslportReservedEnum128 = 138, 
    opennslportReservedEnum129 = 139, 
    opennslportReservedEnum130 = 140, 
    opennslportReservedEnum131 = 141, 
    opennslportReservedEnum132 = 142, 
    opennslportReservedEnum133 = 143, 
    opennslportReservedEnum134 = 144, 
    opennslportReservedEnum135 = 145, 
    opennslportReservedEnum136 = 146, 
    opennslportReservedEnum137 = 147, 
    opennslportReservedEnum138 = 148, 
    opennslportReservedEnum139 = 149, 
    opennslportReservedEnum140 = 150, 
    opennslportReservedEnum141 = 151, 
    opennslportReservedEnum142 = 152, 
    opennslportReservedEnum143 = 153, 
    opennslportReservedEnum144 = 154, 
    opennslportReservedEnum145 = 155, 
    opennslportReservedEnum146 = 156, 
    opennslportReservedEnum147 = 157, 
    opennslportReservedEnum148 = 158, 
    opennslportReservedEnum149 = 159, 
    opennslportReservedEnum150 = 160, 
    opennslportReservedEnum151 = 161, 
    opennslportReservedEnum152, 
    opennslportReservedEnum153 = 162, 
    opennslportReservedEnum154 = 163, 
    opennslportReservedEnum155 = 164, 
    opennslportReservedEnum156 = 165, 
    opennslportReservedEnum157 = 166, 
    opennslportReservedEnum158 = 167, 
    opennslportReservedEnum159 = 168, 
    opennslportReservedEnum160 = 169, 
    opennslportReservedEnum161 = 170, 
    opennslportReservedEnum162 = 171, 
    opennslportReservedEnum163 = 172, 
    opennslportReservedEnum164 = 173, 
    opennslportReservedEnum165 = 174, 
    opennslportReservedEnum166 = 175, 
    opennslportReservedEnum167 = 176, 
    opennslportReservedEnum168 = 177, 
    opennslportReservedEnum169 = 178, 
    opennslportReservedEnum170 = 179, 
    opennslportReservedEnum171 = 180, 
    opennslportReservedEnum172 = 181, 
    opennslportReservedEnum173 = 182, 
    opennslportReservedEnum174 = 183, 
    opennslportReservedEnum175 = 184, 
    opennslportReservedEnum176 = 185, 
    opennslportReservedEnum177 = 186, 
    opennslportReservedEnum178 = 187, 
    opennslportReservedEnum179 = 188, 
    opennslportReservedEnum180 = 189, 
    opennslportReservedEnum181 = 190, 
    opennslportReservedEnum182 = 191, 
    opennslportReservedEnum183 = 192, 
    opennslportReservedEnum184 = 193, 
    opennslportReservedEnum185 = 194, 
    opennslportReservedEnum186 = 195, 
    opennslportReservedEnum187 = 196, 
    opennslportReservedEnum188 = 197, 
    opennslportReservedEnum189 = 198, 
    opennslportReservedEnum190 = 199, 
    opennslportReservedEnum191 = 200, 
    opennslportReservedEnum192 = 201, 
    opennslportReservedEnum193 = 202, 
    opennslportReservedEnum194 = 203, 
    opennslportReservedEnum195 = 204, 
    opennslportReservedEnum196 = 205, 
    opennslportReservedEnum197 = 206, 
    opennslportReservedEnum198 = 207, 
    opennslportReservedEnum199 = 208, 
    opennslportReservedEnum200 = 209, 
    opennslportReservedEnum201 = 210, 
    opennslportReservedEnum202 = 211, 
    opennslportReservedEnum203 = 212, 
    opennslportReservedEnum204 = 213, 
    opennslportReservedEnum205 = 214, 
    opennslportReservedEnum206 = 215, 
    opennslportReservedEnum207 = 216, 
    opennslportReservedEnum208 = 217, 
    opennslportReservedEnum209 = 218, 
    opennslportReservedEnum210 = 219, 
    opennslportReservedEnum211 = 220, 
    opennslportReservedEnum212 = 221, 
    opennslportReservedEnum213 = 222, 
    opennslportReservedEnum214 = 223, 
    opennslportReservedEnum215 = 224, 
    opennslportReservedEnum216 = 225, 
    opennslportReservedEnum217 = 226, 
    opennslportReservedEnum218 = 227, 
    opennslportReservedEnum219 = 228, 
    opennslportReservedEnum220 = 229, 
    opennslportReservedEnum221 = 230, 
    opennslportReservedEnum222 = 231, 
    opennslportReservedEnum223 = 232, 
    opennslportReservedEnum224 = 233, 
    opennslportReservedEnum225 = 234, 
    opennslportReservedEnum226 = 235, 
    opennslportReservedEnum227 = 236, 
    opennslportReservedEnum228 = 237, 
    opennslportReservedEnum229 = 238, 
    opennslportReservedEnum230 = 239, 
    opennslportReservedEnum231 = 240, 
    opennslportReservedEnum232 = 241, 
    opennslportReservedEnum233 = 242, 
    opennslportReservedEnum234 = 243, 
    opennslportReservedEnum235 = 244, 
    opennslportReservedEnum236 = 245, 
    opennslportReservedEnum237 = 246, 
    opennslportReservedEnum238 = 247, 
    opennslportReservedEnum239 = 248, 
    opennslportReservedEnum240 = 249, 
    opennslportReservedEnum241 = 250, 
    opennslportReservedEnum242 = 251, 
    opennslportReservedEnum243 = 252, 
    opennslportReservedEnum244 = 253, 
    opennslportReservedEnum245 = 254, 
    opennslportReservedEnum246 = 255, 
    opennslportReservedEnum247 = 256, 
    opennslportReservedEnum248 = 257, 
    opennslportReservedEnum249 = 258, 
    opennslportReservedEnum250 = 259, 
    opennslportReservedEnum251 = 260, 
    opennslportReservedEnum252 = 261, 
    opennslportReservedEnum253 = 262, 
    opennslportReservedEnum254 = 263, 
    opennslportReservedEnum255 = 264, 
    opennslportReservedEnum256 = 265, 
    opennslportReservedEnum257 = 266, 
    opennslportReservedEnum258 = 267, 
    opennslportReservedEnum259 = 268, 
    opennslportReservedEnum260 = 269, 
    opennslportReservedEnum261 = 270, 
    opennslportReservedEnum262 = 271, 
    opennslportReservedEnum263 = 272, 
    opennslportReservedEnum264 = 273, 
    opennslportReservedEnum265 = 274, 
    opennslportReservedEnum266 = 275, 
    opennslportReservedEnum267, 
    opennslportReservedEnum268, 
    opennslportReservedEnum269, 
    opennslportReservedEnum270 = 276, 
    opennslportReservedEnum271 = 277, 
    opennslportReservedEnum272 = 278, 
    opennslportReservedEnum273 = 279, 
    opennslportReservedEnum274 = 280, 
    opennslportReservedEnum275 = 281, 
    opennslportReservedEnum276 = 282, 
    opennslportReservedEnum277 = 283, 
    opennslportReservedEnum278 = 284, 
    opennslportReservedEnum279 = 285, 
    opennslportReservedEnum280 = 286, 
    opennslportReservedEnum281 = 287, 
    opennslportReservedEnum282 = 288, 
    opennslportReservedEnum283 = 289, 
    opennslportReservedEnum284 = 290, 
    opennslportReservedEnum285 = 291, 
    opennslportReservedEnum286 = 292, 
    opennslportReservedEnum287 = 293, 
    opennslportReservedEnum288 = 294, 
    opennslportReservedEnum289 = 295, 
    opennslportReservedEnum290 = 296, 
    opennslportReservedEnum291 = 297, 
    opennslportReservedEnum292 = 298, 
    opennslportReservedEnum293 = 299, 
    opennslportReservedEnum294 = 300, 
    opennslportReservedEnum295 = 301, 
    opennslportReservedEnum296 = 302, 
    opennslportReservedEnum297 = 303, 
    opennslportReservedEnum298 = 304, 
    opennslportReservedEnum299 = 305, 
    opennslportReservedEnum300 = 306, 
    opennslportReservedEnum301 = 307, 
    opennslportReservedEnum302 = 308, 
    opennslportReservedEnum303 = 309, 
    opennslportReservedEnum304 = 310, 
    opennslportReservedEnum305 = 311, 
    opennslportReservedEnum306 = 312, 
    opennslportReservedEnum307 = 313, 
    opennslportReservedEnum308 = 314 
} opennsl_port_control_t;

#ifndef OPENNSL_HIDE_DISPATCHABLE

/***************************************************************************//** 
 *\brief Get or set various features at the port level.
 *
 *\description Control or examine various features at the port level.
 *          opennsl_port_control_set can be used to enable/disable various
 *          features at the port level. The <type> parameter to the API
 *          identifies the feature to be controlled.
 *          opennsl_port_control_get returns the current value of the port
 *          feature identified by <type> parameter.
 *          The feature types are show in =PORT_CONTROL_v :.
 *
 *\param    unit [IN]   Unit number.
 *\param    port [IN]   Device or logical port number
 *\param    type [IN]   Port feature enumerator
 *\param    value [IN]   Value of the bit field in port table
 *
 *\retval    OPENNSL_E_NONE No Error
 *\retval    OPENNSL_E_UNAVAIL Feature unavailable
 *\retval    OPENNSL_E_PORT Invalid Port number specified
 *\retval    OPENNSL_E_XXX Error occurred
 ******************************************************************************/
extern int opennsl_port_control_set(
    int unit, 
    opennsl_port_t port, 
    opennsl_port_control_t type, 
    int value) LIB_DLL_EXPORTED ;

/***************************************************************************//** 
 *\brief Get or set various features at the port level.
 *
 *\description Control or examine various features at the port level.
 *          opennsl_port_control_set can be used to enable/disable various
 *          features at the port level. The <type> parameter to the API
 *          identifies the feature to be controlled.
 *          opennsl_port_control_get returns the current value of the port
 *          feature identified by <type> parameter.
 *          The feature types are show in =PORT_CONTROL_v :.
 *
 *\param    unit [IN]   Unit number.
 *\param    port [IN]   Device or logical port number
 *\param    type [IN]   Port feature enumerator
 *\param    value [OUT]   Value of the bit field in port table
 *
 *\retval    OPENNSL_E_NONE No Error
 *\retval    OPENNSL_E_UNAVAIL Feature unavailable
 *\retval    OPENNSL_E_PORT Invalid Port number specified
 *\retval    OPENNSL_E_XXX Error occurred
 ******************************************************************************/
extern int opennsl_port_control_get(
    int unit, 
    opennsl_port_t port, 
    opennsl_port_control_t type, 
    int *value) LIB_DLL_EXPORTED ;

#endif /* OPENNSL_HIDE_DISPATCHABLE */

/***************************************************************************//** 
 *\brief Initializes the opennsl_port_info_t structure.
 *
 *\description Initializes the opennsl_port_info_t structure.
 *
 *\param    info [IN,OUT]   Pointer to port information structure (see
 *          =PORT_INFORMATION_CONTROL).
 *
 *\returns  Nothing
 ******************************************************************************/
extern void opennsl_port_info_t_init(
    opennsl_port_info_t *info) LIB_DLL_EXPORTED ;

/***************************************************************************//** 
 *\brief Initialize a Port Ability structure.
 *
 *\description Initializes a port abilities structure to default values. This
 *          function should be used to initialize any Port Ability structure
 *          prior to filling it out and passing it to an API function. This
 *          ensures that subsequent API releases may add new structure members
 *          to the opennsl_port_ability_t structure, and
 *          opennsl_port_ability_t_init will initialize the new members to
 *          correct default values.
 *
 *\param    ability [IN,OUT]
 *
 *\retval    None.
 ******************************************************************************/
extern void opennsl_port_ability_t_init(
    opennsl_port_ability_t *ability) LIB_DLL_EXPORTED ;

#ifndef OPENNSL_HIDE_DISPATCHABLE

/***************************************************************************//** 
 *\brief Get the GPORT ID for the specified local port number.
 *
 *\description This API can be used to get the GPORT ID corresponding to a local
 *          port number.  The supplied port number should return FALSE on a
 *          OPENNSL_GPORT_IS_SET(port) test.
 *          The GPORT ID returned in this API is a MODPORT type. Therefore
 *          this call will fail on devices without a module ID.
 *
 *\param    unit [IN]   Unit number.
 *\param    port [IN]   Port number
 *\param    gport [OUT]   GPORT ID
 *
 *\retval    OPENNSL_E_NONE No Error
 *\retval    OPENNSL_E_UNAVAIL Feature unavailable
 *\retval    OPENNSL_E_PORT Invalid Port number
 *\retval    OPENNSL_E_PARAM Invalid Parameter
 *\retval    OPENNSL_E_XXX Error occurred
 ******************************************************************************/
extern int opennsl_port_gport_get(
    int unit, 
    opennsl_port_t port, 
    opennsl_gport_t *gport) LIB_DLL_EXPORTED ;

/***************************************************************************//** 
 *\brief Get local port number encoded within a GPORT ID.
 *
 *\description This API can be used to get a local port number encoded into a
 *          GPORT ID. This resulting port number will return FALSE on a
 *          OPENNSL_GPORT_IS_SET(port) test.  To encode the result as a local
 *          port gport ID, use OPENNSL_GPORT_LOCAL_SET(gport_local,
 *          local_port);
 *          If the encoding of GPORT ID does not contain a local port on a
 *          device, this API will return an error. GPORT ID may be encoded as
 *          both MODPORT and DEVPORT.
 *
 *\param    unit [IN]   Unit number.
 *\param    gport [IN]   GPORT ID
 *\param    local_port [OUT]   Local port number
 *
 *\retval    OPENNSL_E_NONE Success
 *\retval    OPENNSL_E_UNAVAIL Feature unavailable
 *\retval    OPENNSL_E_XXX Error occurred
 ******************************************************************************/
extern int opennsl_port_local_get(
    int unit, 
    opennsl_gport_t gport, 
    opennsl_port_t *local_port) LIB_DLL_EXPORTED ;

#endif /* OPENNSL_HIDE_DISPATCHABLE */

#ifndef OPENNSL_HIDE_DISPATCHABLE

/***************************************************************************//** 
 *\brief Enable/disable packet and byte counters for the selected gport.
 *
 *\description This API will initialize statistic collection for the given GPORT
 *          (enable=TRUE) or release the HW resources used for the tracking
 *          the statistics (enable=FALSE).
 *
 *\param    unit [IN]   Unit number.
 *\param    port [IN]   GPORT ID
 *\param    enable [IN]   Non-zero to enable counter collection, zero to disable.
 *
 *\retval    OPENNSL_E_XXX
 ******************************************************************************/
extern int opennsl_port_stat_enable_set(
    int unit, 
    opennsl_gport_t port, 
    int enable) LIB_DLL_EXPORTED ;

#endif /* OPENNSL_HIDE_DISPATCHABLE */

#if defined(INCLUDE_CES)
#endif
#endif /* __OPENNSL_PORT_H__ */
/*@}*/
