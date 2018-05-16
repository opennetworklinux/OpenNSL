/** \addtogroup stat Statistics
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
 * \file			stat.h
 ******************************************************************************/

#ifndef __OPENNSL_STAT_H__
#define __OPENNSL_STAT_H__

#include <opennsl/types.h>

/** 
 * Statistics counters.
 * 
 * Note: the following RFC 2465 MIBs are not supported:
 * 
 *   snmpIpv6IfStatsInTooBigErrors,
 *   snmpIpv6IfStatsInNoRoutes,
 *   snmpIpv6IfStatsInUnknownProtos,
 *   snmpIpv6IfStatsInTruncatedPkts,
 *   snmpIpv6IfStatsInDelivers,
 *   snmpIpv6IfStatsOutRequests,
 *   snmpIpv6IfStatsOutFragOKs,
 *   snmpIpv6IfStatsOutFragFails,
 *   snmpIpv6IfStatsOutFragCreates,
 *   snmpIpv6IfStatsReasmReqds,
 *   snmpIpv6IfStatsReasmOKs,
 *   snmpIpv6IfStatsReasmFails,
 */
typedef enum opennsl_stat_val_e {
    opennsl_spl_snmpIfInOctets = 0,     /**< RFC 1213 */
    opennsl_spl_snmpIfInUcastPkts = 1,  /**< RFC 1213 */
    opennsl_spl_snmpIfInNUcastPkts = 2, /**< RFC 1213 */
    opennsl_spl_snmpIfInDiscards = 3,   /**< RFC 1213 */
    opennsl_spl_snmpIfInErrors = 4,     /**< RFC 1213 */
    opennsl_spl_snmpIfInUnknownProtos = 5, /**< RFC 1213 */
    opennsl_spl_snmpIfOutOctets = 6,    /**< RFC 1213 */
    opennsl_spl_snmpIfOutUcastPkts = 7, /**< RFC 1213 */
    opennsl_spl_snmpIfOutNUcastPkts = 8, /**< RFC 1213 */
    opennsl_spl_snmpIfOutDiscards = 9,  /**< RFC 1213 */
    opennsl_spl_snmpIfOutErrors = 10,   /**< RFC 1213 */
    opennsl_spl_snmpIfOutQLen = 11,     /**< RFC 1213 */
    opennsl_spl_snmpIpInReceives = 12,  /**< RFC 1213 */
    opennsl_spl_snmpIpInHdrErrors = 13, /**< RFC 1213 */
    opennsl_spl_snmpIpForwDatagrams = 14, /**< RFC 1213 */
    opennsl_spl_snmpIpInDiscards = 15,  /**< RFC 1213 */
    opennsl_spl_snmpDot1dBasePortDelayExceededDiscards = 16, /**< RFC 1493 */
    opennsl_spl_snmpDot1dBasePortMtuExceededDiscards = 17, /**< RFC 1493 */
    opennsl_spl_snmpDot1dTpPortInFrames = 18, /**< RFC 1493 */
    opennsl_spl_snmpDot1dTpPortOutFrames = 19, /**< RFC 1493 */
    opennsl_spl_snmpDot1dPortInDiscards = 20, /**< RFC 1493 */
    opennsl_spl_snmpEtherStatsDropEvents = 21, /**< RFC 1757 (EtherStat) */
    opennsl_spl_snmpEtherStatsMulticastPkts = 22, /**< RFC 1757 (EtherStat) */
    opennsl_spl_snmpEtherStatsBroadcastPkts = 23, /**< RFC 1757 (EtherStat) */
    opennsl_spl_snmpEtherStatsUndersizePkts = 24, /**< RFC 1757 (EtherStat) */
    opennsl_spl_snmpEtherStatsFragments = 25, /**< RFC 1757 (EtherStat) */
    opennsl_spl_snmpEtherStatsPkts64Octets = 26, /**< RFC 1757 (EtherStat) */
    opennsl_spl_snmpEtherStatsPkts65to127Octets = 27, /**< RFC 1757 (EtherStat) */
    opennsl_spl_snmpEtherStatsPkts128to255Octets = 28, /**< RFC 1757 (EtherStat) */
    opennsl_spl_snmpEtherStatsPkts256to511Octets = 29, /**< RFC 1757 (EtherStat) */
    opennsl_spl_snmpEtherStatsPkts512to1023Octets = 30, /**< RFC 1757 (EtherStat) */
    opennsl_spl_snmpEtherStatsPkts1024to1518Octets = 31, /**< RFC 1757 (EtherStat) */
    opennsl_spl_snmpEtherStatsOversizePkts = 32, /**< RFC 1757 (EtherStat) */
    opennsl_spl_snmpEtherRxOversizePkts = 33, /**< Rx component of
                                           snmpEtherStatsOversizePkts */
    opennsl_spl_snmpEtherTxOversizePkts = 34, /**< Tx component of
                                           snmpEtherStatsOversizePkts */
    opennsl_spl_snmpEtherStatsJabbers = 35, /**< RFC 1757 (EtherStat) */
    opennsl_spl_snmpEtherStatsOctets = 36, /**< RFC 1757 (EtherStat) */
    opennsl_spl_snmpEtherStatsPkts = 37, /**< RFC 1757 (EtherStat) */
    opennsl_spl_snmpEtherStatsCollisions = 38, /**< RFC 1757 (EtherStat) */
    opennsl_spl_snmpEtherStatsCRCAlignErrors = 39, /**< RFC 1757 (EtherStat) */
    opennsl_spl_snmpEtherStatsTXNoErrors = 40, /**< RFC 1757 (EtherStat) */
    opennsl_spl_snmpEtherStatsRXNoErrors = 41, /**< RFC 1757 (EtherStat) */
    opennsl_spl_snmpDot3StatsAlignmentErrors = 42, /**< RFC 2665 */
    opennsl_spl_snmpDot3StatsFCSErrors = 43, /**< RFC 2665 */
    opennsl_spl_snmpDot3StatsSingleCollisionFrames = 44, /**< RFC 2665 */
    opennsl_spl_snmpDot3StatsMultipleCollisionFrames = 45, /**< RFC 2665 */
    opennsl_spl_snmpDot3StatsSQETTestErrors = 46, /**< RFC 2665 */
    opennsl_spl_snmpDot3StatsDeferredTransmissions = 47, /**< RFC 2665 */
    opennsl_spl_snmpDot3StatsLateCollisions = 48, /**< RFC 2665 */
    opennsl_spl_snmpDot3StatsExcessiveCollisions = 49, /**< RFC 2665 */
    opennsl_spl_snmpDot3StatsInternalMacTransmitErrors = 50, /**< RFC 2665 */
    opennsl_spl_snmpDot3StatsCarrierSenseErrors = 51, /**< RFC 2665 */
    opennsl_spl_snmpDot3StatsFrameTooLongs = 52, /**< RFC 2665 */
    opennsl_spl_snmpDot3StatsInternalMacReceiveErrors = 53, /**< RFC 2665 */
    opennsl_spl_snmpDot3StatsSymbolErrors = 54, /**< RFC 2665 */
    opennsl_spl_snmpDot3ControlInUnknownOpcodes = 55, /**< RFC 2665 */
    opennsl_spl_snmpDot3InPauseFrames = 56, /**< RFC 2665 */
    opennsl_spl_snmpDot3OutPauseFrames = 57, /**< RFC 2665 */
    opennsl_spl_snmpIfHCInOctets = 58,  /**< RFC 2233 */
    opennsl_spl_snmpIfHCInUcastPkts = 59, /**< RFC 2233 */
    opennsl_spl_snmpIfHCInMulticastPkts = 60, /**< RFC 2233 */
    opennsl_spl_snmpIfHCInBroadcastPkts = 61, /**< RFC 2233 */
    opennsl_spl_snmpIfHCOutOctets = 62, /**< RFC 2233 */
    opennsl_spl_snmpIfHCOutUcastPkts = 63, /**< RFC 2233 */
    opennsl_spl_snmpIfHCOutMulticastPkts = 64, /**< RFC 2233 */
    opennsl_spl_snmpIfHCOutBroadcastPckts = 65, /**< RFC 2233 */
    opennsl_spl_snmpIpv6IfStatsInReceives = 66, /**< RFC 2465 */
    opennsl_spl_snmpIpv6IfStatsInHdrErrors = 67, /**< RFC 2465 */
    opennsl_spl_snmpIpv6IfStatsInAddrErrors = 68, /**< RFC 2465 */
    opennsl_spl_snmpIpv6IfStatsInDiscards = 69, /**< RFC 2465 */
    opennsl_spl_snmpIpv6IfStatsOutForwDatagrams = 70, /**< RFC 2465 */
    opennsl_spl_snmpIpv6IfStatsOutDiscards = 71, /**< RFC 2465 */
    opennsl_spl_snmpIpv6IfStatsInMcastPkts = 72, /**< RFC 2465 */
    opennsl_spl_snmpIpv6IfStatsOutMcastPkts = 73, /**< RFC 2465 */
    opennsl_spl_snmpIfInBroadcastPkts = 74, /**< RFC 1573 */
    opennsl_spl_snmpIfInMulticastPkts = 75, /**< RFC 1573 */
    opennsl_spl_snmpIfOutBroadcastPkts = 76, /**< RFC 1573 */
    opennsl_spl_snmpIfOutMulticastPkts = 77, /**< RFC 1573 */
    opennsl_spl_snmpIeee8021PfcRequests = 78, /**< IEEE 802.1bb */
    opennsl_spl_snmpIeee8021PfcIndications = 79, /**< IEEE 802.1bb */
    snmpOpenNSLReceivedUndersizePkts = 80, /**< Broadcom-specific */
    snmpOpenNSLTransmittedUndersizePkts = 81, /**< Broadcom-specific */
    snmpOpenNSLIPMCBridgedPckts = 82,   /**< Broadcom-specific */
    snmpOpenNSLIPMCRoutedPckts = 83,    /**< Broadcom-specific */
    snmpOpenNSLIPMCInDroppedPckts = 84, /**< Broadcom-specific */
    snmpOpenNSLIPMCOutDroppedPckts = 85, /**< Broadcom-specific */
    snmpOpenNSLEtherStatsPkts1519to1522Octets = 86, /**< Broadcom-specific */
    snmpOpenNSLEtherStatsPkts1522to2047Octets = 87, /**< Broadcom-specific */
    snmpOpenNSLEtherStatsPkts2048to4095Octets = 88, /**< Broadcom-specific */
    snmpOpenNSLEtherStatsPkts4095to9216Octets = 89, /**< Broadcom-specific */
    snmpOpenNSLReceivedPkts64Octets = 90, /**< Broadcom-specific */
    snmpOpenNSLReceivedPkts65to127Octets = 91, /**< Broadcom-specific */
    snmpOpenNSLReceivedPkts128to255Octets = 92, /**< Broadcom-specific */
    snmpOpenNSLReceivedPkts256to511Octets = 93, /**< Broadcom-specific */
    snmpOpenNSLReceivedPkts512to1023Octets = 94, /**< Broadcom-specific */
    snmpOpenNSLReceivedPkts1024to1518Octets = 95, /**< Broadcom-specific */
    snmpOpenNSLReceivedPkts1519to2047Octets = 96, /**< Broadcom-specific */
    snmpOpenNSLReceivedPkts2048to4095Octets = 97, /**< Broadcom-specific */
    snmpOpenNSLReceivedPkts4095to9216Octets = 98, /**< Broadcom-specific */
    snmpOpenNSLTransmittedPkts64Octets = 99, /**< Broadcom-specific */
    snmpOpenNSLTransmittedPkts65to127Octets = 100, /**< Broadcom-specific */
    snmpOpenNSLTransmittedPkts128to255Octets = 101, /**< Broadcom-specific */
    snmpOpenNSLTransmittedPkts256to511Octets = 102, /**< Broadcom-specific */
    snmpOpenNSLTransmittedPkts512to1023Octets = 103, /**< Broadcom-specific */
    snmpOpenNSLTransmittedPkts1024to1518Octets = 104, /**< Broadcom-specific */
    snmpOpenNSLTransmittedPkts1519to2047Octets = 105, /**< Broadcom-specific */
    snmpOpenNSLTransmittedPkts2048to4095Octets = 106, /**< Broadcom-specific */
    snmpOpenNSLTransmittedPkts4095to9216Octets = 107, /**< Broadcom-specific */
    snmpOpenNSLTxControlCells = 108,    /**< Fabric TX Control cells counter.
                                           (Broadcom-specific) */
    snmpOpenNSLTxDataCells = 109,       /**< Fabric TX Data cell counter.
                                           (Broadcom-specific) */
    snmpOpenNSLTxDataBytes = 110,       /**< Fabric TX Data byte counter.
                                           (Broadcom-specific) */
    snmpOpenNSLRxCrcErrors = 111,       /**< Fabric RX CRC errors counter.
                                           (Broadcom-specific) */
    snmpOpenNSLRxFecCorrectable = 112,  /**< Fabric RX LFEC/FEC correctable error.
                                           (Broadcom-specific) */
    snmpOpenNSLRxBecCrcErrors = 113,    /**< Fabric RX BEC crc error.
                                           (Broadcom-specific) */
    snmpOpenNSLRxDisparityErrors = 114, /**< Fabric RX 8b/10b disparity errors.
                                           (Broadcom-specific) */
    snmpOpenNSLRxControlCells = 115,    /**< Fabric RX Control cells counter.
                                           (Broadcom-specific) */
    snmpOpenNSLRxDataCells = 116,       /**< Fabric RX Data cell counter.
                                           (Broadcom-specific) */
    snmpOpenNSLRxDataBytes = 117,       /**< Fabric RX Data byte counter.
                                           (Broadcom-specific) */
    snmpOpenNSLRxDroppedRetransmittedControl = 118, /**< Fabric RX dropped retransmitted
                                           control. (Broadcom-specific) */
    snmpOpenNSLTxBecRetransmit = 119,   /**< Fabric TX BEC retransmit.
                                           (Broadcom-specific) */
    snmpOpenNSLRxBecRetransmit = 120,   /**< Fabric RX BEC retransmit.
                                           (Broadcom-specific) */
    snmpOpenNSLTxAsynFifoRate = 121,    /**< Fabric TX Asyn fifo rate at units of
                                           40 bits. (Broadcom-specific) */
    snmpOpenNSLRxAsynFifoRate = 122,    /**< Fabric RX Asyn fifo rate at units of
                                           40 bits. (Broadcom-specific) */
    snmpOpenNSLRxFecUncorrectable = 123, /**< Fabric RX LFEC/FEC uncorrectable
                                           erros. (Broadcom-specific) */
    snmpOpenNSLRxBecRxFault = 124,      /**< Fabric RX BEC RX fault.
                                           (Broadcom-specific) */
    snmpOpenNSLRxCodeErrors = 125,      /**< Fabric RX 8b/10b code errors.
                                           (Broadcom-specific) */
    snmpOpenNSLRxLlfcPrimary = 126,     /**< Fabric RX LLFC Primary.
                                           (Broadcom-specific) */
    snmpOpenNSLRxLlfcSecondary = 127,   /**< Fabric RX LLFC Secondary.
                                           (Broadcom-specific) */
    snmpOpenNSLCustomReceive0 = 128,    /**< Broadcom-specific */
    snmpOpenNSLCustomReceive1 = 129,    /**< Broadcom-specific */
    snmpOpenNSLCustomReceive2 = 130,    /**< Broadcom-specific */
    snmpOpenNSLCustomReceive3 = 131,    /**< Broadcom-specific */
    snmpOpenNSLCustomReceive4 = 132,    /**< Broadcom-specific */
    snmpOpenNSLCustomReceive5 = 133,    /**< Broadcom-specific */
    snmpOpenNSLCustomReceive6 = 134,    /**< Broadcom-specific */
    snmpOpenNSLCustomReceive7 = 135,    /**< Broadcom-specific */
    snmpOpenNSLCustomReceive8 = 136,    /**< Broadcom-specific */
    snmpOpenNSLCustomTransmit0 = 137,   /**< Broadcom-specific */
    snmpOpenNSLCustomTransmit1 = 138,   /**< Broadcom-specific */
    snmpOpenNSLCustomTransmit2 = 139,   /**< Broadcom-specific */
    snmpOpenNSLCustomTransmit3 = 140,   /**< Broadcom-specific */
    snmpOpenNSLCustomTransmit4 = 141,   /**< Broadcom-specific */
    snmpOpenNSLCustomTransmit5 = 142,   /**< Broadcom-specific */
    snmpOpenNSLCustomTransmit6 = 143,   /**< Broadcom-specific */
    snmpOpenNSLCustomTransmit7 = 144,   /**< Broadcom-specific */
    snmpOpenNSLCustomTransmit8 = 145,   /**< Broadcom-specific */
    snmpOpenNSLCustomTransmit9 = 146,   /**< Broadcom-specific */
    snmpOpenNSLCustomTransmit10 = 147,  /**< Broadcom-specific */
    snmpOpenNSLCustomTransmit11 = 148,  /**< Broadcom-specific */
    snmpOpenNSLCustomTransmit12 = 149,  /**< Broadcom-specific */
    snmpOpenNSLCustomTransmit13 = 150,  /**< Broadcom-specific */
    snmpOpenNSLCustomTransmit14 = 151,  /**< Broadcom-specific */
    opennsl_spl_snmpDot3StatsInRangeLengthError = 152, /**< RFC 1284 */
    opennsl_spl_snmpDot3OmpEmulationCRC8Errors = 153, /**< RFC 4837 */
    opennsl_spl_snmpDot3MpcpRxGate = 154, /**< RFC 4837 */
    opennsl_spl_snmpDot3MpcpRxRegister = 155, /**< RFC 4837 */
    opennsl_spl_snmpDot3MpcpTxRegRequest = 156, /**< RFC 4837 */
    opennsl_spl_snmpDot3MpcpTxRegAck = 157, /**< RFC 4837 */
    opennsl_spl_snmpDot3MpcpTxReport = 158, /**< RFC 4837 */
    opennsl_spl_snmpDot3EponFecCorrectedBlocks = 159, /**< RFC 4837 */
    opennsl_spl_snmpDot3EponFecUncorrectableBlocks = 160, /**< RFC 4837 */
    snmpOpenNSLPonInDroppedOctets = 161, /**< Broadcom-specific */
    snmpOpenNSLPonOutDroppedOctets = 162, /**< Broadcom-specific */
    snmpOpenNSLPonInDelayedOctets = 163, /**< Broadcom-specific */
    snmpOpenNSLPonOutDelayedOctets = 164, /**< Broadcom-specific */
    snmpOpenNSLPonInDelayedHundredUs = 165, /**< Broadcom-specific */
    snmpOpenNSLPonOutDelayedHundredUs = 166, /**< Broadcom-specific */
    snmpOpenNSLPonInFrameErrors = 167,  /**< Broadcom-specific */
    snmpOpenNSLPonInOamFrames = 168,    /**< Broadcom-specific */
    snmpOpenNSLPonOutOamFrames = 169,   /**< Broadcom-specific */
    snmpOpenNSLPonOutUnusedOctets = 170, /**< Broadcom-specific */
    snmpOpenNSLEtherStatsPkts9217to16383Octets = 171, /**< Broadcom-specific */
    snmpOpenNSLReceivedPkts9217to16383Octets = 172, /**< Broadcom-specific */
    snmpOpenNSLTransmittedPkts9217to16383Octets = 173, /**< Broadcom-specific */
    snmpOpenNSLRxVlanTagFrame = 174,    /**< Broadcom-specific */
    snmpOpenNSLRxDoubleVlanTagFrame = 175, /**< Broadcom-specific */
    snmpOpenNSLTxVlanTagFrame = 176,    /**< Broadcom-specific */
    snmpOpenNSLTxDoubleVlanTagFrame = 177, /**< Broadcom-specific */
    snmpOpenNSLRxPFCControlFrame = 178, /**< PFC Receive Control Frame */
    snmpOpenNSLTxPFCControlFrame = 179, /**< PFC Transmit Control Frame */
    snmpOpenNSLRxPFCFrameXonPriority0 = 180, /**< Receive PFC Frame Priority 0 XON to
                                           XOFF */
    snmpOpenNSLRxPFCFrameXonPriority1 = 181, /**< Receive PFC Frame Priority 1 XON to
                                           XOFF */
    snmpOpenNSLRxPFCFrameXonPriority2 = 182, /**< Receive PFC Frame Priority 2 XON to
                                           XOFF */
    snmpOpenNSLRxPFCFrameXonPriority3 = 183, /**< Receive PFC Frame Priority 3 XON to
                                           XOFF */
    snmpOpenNSLRxPFCFrameXonPriority4 = 184, /**< Receive PFC Frame Priority 4 XON to
                                           XOFF */
    snmpOpenNSLRxPFCFrameXonPriority5 = 185, /**< Receive PFC Frame Priority 5 XON to
                                           XOFF */
    snmpOpenNSLRxPFCFrameXonPriority6 = 186, /**< Receive PFC Frame Priority 6 XON to
                                           XOFF */
    snmpOpenNSLRxPFCFrameXonPriority7 = 187, /**< Receive PFC Frame Priority 7 XON to
                                           XOFF */
    snmpOpenNSLRxPFCFramePriority0 = 188, /**< Receive PFC Frame Priority 0 */
    snmpOpenNSLRxPFCFramePriority1 = 189, /**< Receive PFC Frame Priority 1 */
    snmpOpenNSLRxPFCFramePriority2 = 190, /**< Receive PFC Frame Priority 2 */
    snmpOpenNSLRxPFCFramePriority3 = 191, /**< Receive PFC Frame Priority 3 */
    snmpOpenNSLRxPFCFramePriority4 = 192, /**< Receive PFC Frame Priority 4 */
    snmpOpenNSLRxPFCFramePriority5 = 193, /**< Receive PFC Frame Priority 5 */
    snmpOpenNSLRxPFCFramePriority6 = 194, /**< Receive PFC Frame Priority 6 */
    snmpOpenNSLRxPFCFramePriority7 = 195, /**< Receive PFC Frame Priority 7 */
    snmpOpenNSLTxPFCFramePriority0 = 196, /**< Transmit PFC Frame Priority 0 */
    snmpOpenNSLTxPFCFramePriority1 = 197, /**< Transmit PFC Frame Priority 1 */
    snmpOpenNSLTxPFCFramePriority2 = 198, /**< Transmit PFC Frame Priority 2 */
    snmpOpenNSLTxPFCFramePriority3 = 199, /**< Transmit PFC Frame Priority 3 */
    snmpOpenNSLTxPFCFramePriority4 = 200, /**< Transmit PFC Frame Priority 4 */
    snmpOpenNSLTxPFCFramePriority5 = 201, /**< Transmit PFC Frame Priority 5 */
    snmpOpenNSLTxPFCFramePriority6 = 202, /**< Transmit PFC Frame Priority 6 */
    snmpOpenNSLTxPFCFramePriority7 = 203, /**< Transmit PFC Frame Priority 7 */
    opennsl_spl_snmpFcmPortClass3RxFrames = 204, /**< RFC 4044 */
    opennsl_spl_snmpFcmPortClass3TxFrames = 205, /**< RFC 4044 */
    opennsl_spl_snmpFcmPortClass3Discards = 206, /**< RFC 4044 */
    opennsl_spl_snmpFcmPortClass2RxFrames = 207, /**< RFC 4044 */
    opennsl_spl_snmpFcmPortClass2TxFrames = 208, /**< RFC 4044 */
    opennsl_spl_snmpFcmPortClass2Discards = 209, /**< RFC 4044 */
    opennsl_spl_snmpFcmPortInvalidCRCs = 210, /**< RFC 4044 */
    opennsl_spl_snmpFcmPortDelimiterErrors = 211, /**< RFC 4044 */
    snmpOpenNSLSampleIngressPkts = 212, /**< Total number of packets eligible to
                                           be sampled by Ingress Sampler.
                                           (Broadcom-specific) */
    snmpOpenNSLSampleIngressSnapshotPkts = 213, /**< Total number of eligible packets when
                                           the last packet was sampled by
                                           Ingress sampler. (Broadcom-specific) */
    snmpOpenNSLSampleIngressSampledPkts = 214, /**< Total number of packets sampled by
                                           Ingress sampler. (Broadcom-specific) */
    snmpOpenNSLSampleFlexPkts = 215,    /**< Total number of packets eligible to
                                           be sampled by Flex sampler enabled by
                                           IFP ingress sampling policy action.
                                           (Broadcom-specific) */
    snmpOpenNSLSampleFlexSnapshotPkts = 216, /**< Total number of eligible packets when
                                           the last packet was sampled by Flex
                                           sampler enabled by IFP ingress
                                           sampling policy action.
                                           (Broadcom-specific) */
    snmpOpenNSLSampleFlexSampledPkts = 217, /**< Total number of packets sampled by
                                           Flex sampler enabled by IFP ingress
                                           sampling policy action.
                                           (Broadcom-specific) */
    snmpOpenNSLEgressProtectionDataDrop = 218, /**< Egress Protection data drop in EPIPE.
                                           (Broadcom-specific) */
    opennsl_spl_snmpValCount = 219      
} opennsl_stat_val_t;

#define OPENNSL_STAT_NAME_INITIALIZER \
{ \
    "opennsl_spl_snmpIfInOctets", \
    "opennsl_spl_snmpIfInUcastPkts", \
    "opennsl_spl_snmpIfInNUcastPkts", \
    "opennsl_spl_snmpIfInDiscards", \
    "opennsl_spl_snmpIfInErrors", \
    "opennsl_spl_snmpIfInUnknownProtos", \
    "opennsl_spl_snmpIfOutOctets", \
    "opennsl_spl_snmpIfOutUcastPkts", \
    "opennsl_spl_snmpIfOutNUcastPkts", \
    "opennsl_spl_snmpIfOutDiscards", \
    "opennsl_spl_snmpIfOutErrors", \
    "opennsl_spl_snmpIfOutQLen", \
    "opennsl_spl_snmpIpInReceives", \
    "opennsl_spl_snmpIpInHdrErrors", \
    "opennsl_spl_snmpIpForwDatagrams", \
    "opennsl_spl_snmpIpInDiscards", \
    "opennsl_spl_snmpDot1dBasePortDelayExceededDiscards", \
    "opennsl_spl_snmpDot1dBasePortMtuExceededDiscards", \
    "opennsl_spl_snmpDot1dTpPortInFrames", \
    "opennsl_spl_snmpDot1dTpPortOutFrames", \
    "opennsl_spl_snmpDot1dPortInDiscards", \
    "opennsl_spl_snmpEtherStatsDropEvents", \
    "opennsl_spl_snmpEtherStatsMulticastPkts", \
    "opennsl_spl_snmpEtherStatsBroadcastPkts", \
    "opennsl_spl_snmpEtherStatsUndersizePkts", \
    "opennsl_spl_snmpEtherStatsFragments", \
    "opennsl_spl_snmpEtherStatsPkts64Octets", \
    "opennsl_spl_snmpEtherStatsPkts65to127Octets", \
    "opennsl_spl_snmpEtherStatsPkts128to255Octets", \
    "opennsl_spl_snmpEtherStatsPkts256to511Octets", \
    "opennsl_spl_snmpEtherStatsPkts512to1023Octets", \
    "opennsl_spl_snmpEtherStatsPkts1024to1518Octets", \
    "opennsl_spl_snmpEtherStatsOversizePkts", \
    "opennsl_spl_snmpEtherRxOversizePkts", \
    "opennsl_spl_snmpEtherTxOversizePkts", \
    "opennsl_spl_snmpEtherStatsJabbers", \
    "opennsl_spl_snmpEtherStatsOctets", \
    "opennsl_spl_snmpEtherStatsPkts", \
    "opennsl_spl_snmpEtherStatsCollisions", \
    "opennsl_spl_snmpEtherStatsCRCAlignErrors", \
    "opennsl_spl_snmpEtherStatsTXNoErrors", \
    "opennsl_spl_snmpEtherStatsRXNoErrors", \
    "opennsl_spl_snmpDot3StatsAlignmentErrors", \
    "opennsl_spl_snmpDot3StatsFCSErrors", \
    "opennsl_spl_snmpDot3StatsSingleCollisionFrames", \
    "opennsl_spl_snmpDot3StatsMultipleCollisionFrames", \
    "opennsl_spl_snmpDot3StatsSQETTestErrors", \
    "opennsl_spl_snmpDot3StatsDeferredTransmissions", \
    "opennsl_spl_snmpDot3StatsLateCollisions", \
    "opennsl_spl_snmpDot3StatsExcessiveCollisions", \
    "opennsl_spl_snmpDot3StatsInternalMacTransmitErrors", \
    "opennsl_spl_snmpDot3StatsCarrierSenseErrors", \
    "opennsl_spl_snmpDot3StatsFrameTooLongs", \
    "opennsl_spl_snmpDot3StatsInternalMacReceiveErrors", \
    "opennsl_spl_snmpDot3StatsSymbolErrors", \
    "opennsl_spl_snmpDot3ControlInUnknownOpcodes", \
    "opennsl_spl_snmpDot3InPauseFrames", \
    "opennsl_spl_snmpDot3OutPauseFrames", \
    "opennsl_spl_snmpIfHCInOctets", \
    "opennsl_spl_snmpIfHCInUcastPkts", \
    "opennsl_spl_snmpIfHCInMulticastPkts", \
    "opennsl_spl_snmpIfHCInBroadcastPkts", \
    "opennsl_spl_snmpIfHCOutOctets", \
    "opennsl_spl_snmpIfHCOutUcastPkts", \
    "opennsl_spl_snmpIfHCOutMulticastPkts", \
    "opennsl_spl_snmpIfHCOutBroadcastPckts", \
    "opennsl_spl_snmpIpv6IfStatsInReceives", \
    "opennsl_spl_snmpIpv6IfStatsInHdrErrors", \
    "opennsl_spl_snmpIpv6IfStatsInAddrErrors", \
    "opennsl_spl_snmpIpv6IfStatsInDiscards", \
    "opennsl_spl_snmpIpv6IfStatsOutForwDatagrams", \
    "opennsl_spl_snmpIpv6IfStatsOutDiscards", \
    "opennsl_spl_snmpIpv6IfStatsInMcastPkts", \
    "opennsl_spl_snmpIpv6IfStatsOutMcastPkts", \
    "opennsl_spl_snmpIfInBroadcastPkts", \
    "opennsl_spl_snmpIfInMulticastPkts", \
    "opennsl_spl_snmpIfOutBroadcastPkts", \
    "opennsl_spl_snmpIfOutMulticastPkts", \
    "opennsl_spl_snmpIeee8021PfcRequests", \
    "opennsl_spl_snmpIeee8021PfcIndications", \
    "snmpOpenNSLReceivedUndersizePkts", \
    "snmpOpenNSLTransmittedUndersizePkts", \
    "snmpOpenNSLIPMCBridgedPckts", \
    "snmpOpenNSLIPMCRoutedPckts", \
    "snmpOpenNSLIPMCInDroppedPckts", \
    "snmpOpenNSLIPMCOutDroppedPckts", \
    "snmpOpenNSLEtherStatsPkts1519to1522Octets", \
    "snmpOpenNSLEtherStatsPkts1522to2047Octets", \
    "snmpOpenNSLEtherStatsPkts2048to4095Octets", \
    "snmpOpenNSLEtherStatsPkts4095to9216Octets", \
    "snmpOpenNSLReceivedPkts64Octets", \
    "snmpOpenNSLReceivedPkts65to127Octets", \
    "snmpOpenNSLReceivedPkts128to255Octets", \
    "snmpOpenNSLReceivedPkts256to511Octets", \
    "snmpOpenNSLReceivedPkts512to1023Octets", \
    "snmpOpenNSLReceivedPkts1024to1518Octets", \
    "snmpOpenNSLReceivedPkts1519to2047Octets", \
    "snmpOpenNSLReceivedPkts2048to4095Octets", \
    "snmpOpenNSLReceivedPkts4095to9216Octets", \
    "snmpOpenNSLTransmittedPkts64Octets", \
    "snmpOpenNSLTransmittedPkts65to127Octets", \
    "snmpOpenNSLTransmittedPkts128to255Octets", \
    "snmpOpenNSLTransmittedPkts256to511Octets", \
    "snmpOpenNSLTransmittedPkts512to1023Octets", \
    "snmpOpenNSLTransmittedPkts1024to1518Octets", \
    "snmpOpenNSLTransmittedPkts1519to2047Octets", \
    "snmpOpenNSLTransmittedPkts2048to4095Octets", \
    "snmpOpenNSLTransmittedPkts4095to9216Octets", \
    "snmpOpenNSLTxControlCells", \
    "snmpOpenNSLTxDataCells", \
    "snmpOpenNSLTxDataBytes", \
    "snmpOpenNSLRxCrcErrors", \
    "snmpOpenNSLRxFecCorrectable", \
    "snmpOpenNSLRxBecCrcErrors", \
    "snmpOpenNSLRxDisparityErrors", \
    "snmpOpenNSLRxControlCells", \
    "snmpOpenNSLRxDataCells", \
    "snmpOpenNSLRxDataBytes", \
    "snmpOpenNSLRxDroppedRetransmittedControl", \
    "snmpOpenNSLTxBecRetransmit", \
    "snmpOpenNSLRxBecRetransmit", \
    "snmpOpenNSLTxAsynFifoRate", \
    "snmpOpenNSLRxAsynFifoRate", \
    "snmpOpenNSLRxFecUncorrectable", \
    "snmpOpenNSLRxBecRxFault", \
    "snmpOpenNSLRxCodeErrors", \
    "snmpOpenNSLRxLlfcPrimary", \
    "snmpOpenNSLRxLlfcSecondary", \
    "snmpOpenNSLCustomReceive0", \
    "snmpOpenNSLCustomReceive1", \
    "snmpOpenNSLCustomReceive2", \
    "snmpOpenNSLCustomReceive3", \
    "snmpOpenNSLCustomReceive4", \
    "snmpOpenNSLCustomReceive5", \
    "snmpOpenNSLCustomReceive6", \
    "snmpOpenNSLCustomReceive7", \
    "snmpOpenNSLCustomReceive8", \
    "snmpOpenNSLCustomTransmit0", \
    "snmpOpenNSLCustomTransmit1", \
    "snmpOpenNSLCustomTransmit2", \
    "snmpOpenNSLCustomTransmit3", \
    "snmpOpenNSLCustomTransmit4", \
    "snmpOpenNSLCustomTransmit5", \
    "snmpOpenNSLCustomTransmit6", \
    "snmpOpenNSLCustomTransmit7", \
    "snmpOpenNSLCustomTransmit8", \
    "snmpOpenNSLCustomTransmit9", \
    "snmpOpenNSLCustomTransmit10", \
    "snmpOpenNSLCustomTransmit11", \
    "snmpOpenNSLCustomTransmit12", \
    "snmpOpenNSLCustomTransmit13", \
    "snmpOpenNSLCustomTransmit14", \
    "opennsl_spl_snmpDot3StatsInRangeLengthError", \
    "opennsl_spl_snmpDot3OmpEmulationCRC8Errors", \
    "opennsl_spl_snmpDot3MpcpRxGate", \
    "opennsl_spl_snmpDot3MpcpRxRegister", \
    "opennsl_spl_snmpDot3MpcpTxRegRequest", \
    "opennsl_spl_snmpDot3MpcpTxRegAck", \
    "opennsl_spl_snmpDot3MpcpTxReport", \
    "opennsl_spl_snmpDot3EponFecCorrectedBlocks", \
    "opennsl_spl_snmpDot3EponFecUncorrectableBlocks", \
    "snmpOpenNSLPonInDroppedOctets", \
    "snmpOpenNSLPonOutDroppedOctets", \
    "snmpOpenNSLPonInDelayedOctets", \
    "snmpOpenNSLPonOutDelayedOctets", \
    "snmpOpenNSLPonInDelayedHundredUs", \
    "snmpOpenNSLPonOutDelayedHundredUs", \
    "snmpOpenNSLPonInFrameErrors", \
    "snmpOpenNSLPonInOamFrames", \
    "snmpOpenNSLPonOutOamFrames", \
    "snmpOpenNSLPonOutUnusedOctets", \
    "snmpOpenNSLEtherStatsPkts9217to16383Octets", \
    "snmpOpenNSLReceivedPkts9217to16383Octets", \
    "snmpOpenNSLTransmittedPkts9217to16383Octets", \
    "snmpOpenNSLRxVlanTagFrame", \
    "snmpOpenNSLRxDoubleVlanTagFrame", \
    "snmpOpenNSLTxVlanTagFrame", \
    "snmpOpenNSLTxDoubleVlanTagFrame", \
    "snmpOpenNSLRxPFCControlFrame", \
    "snmpOpenNSLTxPFCControlFrame", \
    "snmpOpenNSLRxPFCFrameXonPriority0", \
    "snmpOpenNSLRxPFCFrameXonPriority1", \
    "snmpOpenNSLRxPFCFrameXonPriority2", \
    "snmpOpenNSLRxPFCFrameXonPriority3", \
    "snmpOpenNSLRxPFCFrameXonPriority4", \
    "snmpOpenNSLRxPFCFrameXonPriority5", \
    "snmpOpenNSLRxPFCFrameXonPriority6", \
    "snmpOpenNSLRxPFCFrameXonPriority7", \
    "snmpOpenNSLRxPFCFramePriority0", \
    "snmpOpenNSLRxPFCFramePriority1", \
    "snmpOpenNSLRxPFCFramePriority2", \
    "snmpOpenNSLRxPFCFramePriority3", \
    "snmpOpenNSLRxPFCFramePriority4", \
    "snmpOpenNSLRxPFCFramePriority5", \
    "snmpOpenNSLRxPFCFramePriority6", \
    "snmpOpenNSLRxPFCFramePriority7", \
    "snmpOpenNSLTxPFCFramePriority0", \
    "snmpOpenNSLTxPFCFramePriority1", \
    "snmpOpenNSLTxPFCFramePriority2", \
    "snmpOpenNSLTxPFCFramePriority3", \
    "snmpOpenNSLTxPFCFramePriority4", \
    "snmpOpenNSLTxPFCFramePriority5", \
    "snmpOpenNSLTxPFCFramePriority6", \
    "snmpOpenNSLTxPFCFramePriority7", \
    "opennsl_spl_snmpFcmPortClass3RxFrames", \
    "opennsl_spl_snmpFcmPortClass3TxFrames", \
    "opennsl_spl_snmpFcmPortClass3Discards", \
    "opennsl_spl_snmpFcmPortClass2RxFrames", \
    "opennsl_spl_snmpFcmPortClass2TxFrames", \
    "opennsl_spl_snmpFcmPortClass2Discards", \
    "opennsl_spl_snmpFcmPortInvalidCRCs", \
    "opennsl_spl_snmpFcmPortDelimiterErrors", \
    "snmpOpenNSLSampleIngressPkts", \
    "snmpOpenNSLSampleIngressSnapshotPkts", \
    "snmpOpenNSLSampleIngressSampledPkts", \
    "snmpOpenNSLSampleFlexPkts", \
    "snmpOpenNSLSampleFlexSnapshotPkts", \
    "snmpOpenNSLSampleFlexSampledPkts", \
    "snmpOpenNSLEgressProtectionDataDrop"  \
}

#ifndef OPENNSL_HIDE_DISPATCHABLE

/***************************************************************************//** 
 *\brief Clear the port-based statistics for the indicated device port.
 *
 *\description Set all counters to zero to the specified port.
 *
 *\param    unit [IN]   Unit number.
 *\param    port [IN]   Zero-based device or logical port number
 *
 *\retval    OPENNSL_E_NONE Success
 *\retval    OPENNSL_E_INTERNAL Device access failure
 ******************************************************************************/
extern int opennsl_stat_clear(
    int unit, 
    opennsl_port_t port) LIB_DLL_EXPORTED ;

/***************************************************************************//** 
 *\brief Get the specified statistics from the device.
 *
 *\description The native statistics are 64-bits wide; use opennsl_stat_get32()
 *          for 32-bit  statistics. Some counters are implemented on a given
 *          port only when it is  operating in a specific mode, for example,
 *          10 or 100, and not 1000 Mbps.  If the counter is not implemented
 *          on the specified port, or on the port  given its current operating
 *          mode, OPENNSL_E_UNAVAIL is returned.
 *
 *\param    unit [IN]   Unit number.
 *\param    port [IN]   Zero-based device or logical port number
 *\param    type [IN]   SNMP statistics type defined in opennsl_stat_val_t
 *\param    value [OUT]   Counter value
 *
 *\retval    OPENNSL_E_NONE Success.
 *\retval    OPENNSL_E_PARAM Illegal parameter.
 *\retval    OPENNSL_E_BADID Illegal port number.
 *\retval    OPENNSL_E_INTERNAL Device access failure.
 *\retval    OPENNSL_E_UNAVAIL Counter/variable is not implemented on this current
 *          chip.
 ******************************************************************************/
extern int opennsl_stat_get(
    int unit, 
    opennsl_port_t port, 
    opennsl_stat_val_t type, 
    uint64 *value) LIB_DLL_EXPORTED ;

/***************************************************************************//** 
 *\brief Get the specified statistics from the device.
 *
 *\description This API will retrieve a set of statistic values of the types
 *          specified in the stat_arr array.  The number of values in the
 *          stat_arr array and the available positions in the value_arr array
 *          must match the number given in the nstat argument. 64-bit values
 *          may be truncated to fit into a 32-bit array for
 *          opennsl_stat_multi_get32.
 *
 *\param    unit [IN]   Unit number.
 *\param    port [IN]   <UNDEF>
 *\param    nstat [IN]   Number of elements in stat array
 *\param    stat_arr [IN]   Array of SNMP statistics types defined in
 *          opennsl_stat_val_t
 *\param    value_arr [OUT]   Collected 64-bit or 32-bit statistics values
 *
 *\retval    OPENNSL_E_xxx
 ******************************************************************************/
extern int opennsl_stat_multi_get(
    int unit, 
    opennsl_port_t port, 
    int nstat, 
    opennsl_stat_val_t *stat_arr, 
    uint64 *value_arr) LIB_DLL_EXPORTED ;

#endif /* OPENNSL_HIDE_DISPATCHABLE */

#endif /* __OPENNSL_STAT_H__ */
/*@}*/
