/******************************************************************************
 DO NOT EDIT - This file is generated by the SysConfig tool.
 @file ti_154stack_config.h

 @brief TI-15.4 Stack configuration parameters for Sensor
 applications

 *****************************************************************************/
#ifndef TI_154STACK_CONFIG_H
#define TI_154STACK_CONFIG_H

/******************************************************************************
 Includes
 *****************************************************************************/
#include "api_mac.h"
#include "ti_154stack_features.h"

#ifdef __cplusplus
extern "C"
{
#endif


/* Setting for PAN ID */
#define CONFIG_PAN_ID                   0xFFFF

/* Setting for phy ID */
#define CONFIG_PHY_ID                   APIMAC_50KBPS_915MHZ_PHY_1

/* Setting for channel page */
#define CONFIG_CHANNEL_PAGE             APIMAC_CHANNEL_PAGE_9


 /* Setting for symbol duration */
#define RF_CONFIG_CUSTOM_PHY_ID    {                                                           \
    &RF_prop_custom,                                                                  \
    txPowerTable_custom,                                                              \
    (const rfc_CMD_PROP_RADIO_DIV_SETUP_PA_t *)&RF_cmdPropRadioDivSetup_custom,       \
    (const rfc_CMD_FS_t *)&RF_cmdFs_custom,                                           \
    (const rfc_CMD_PROP_TX_ADV_t *)&RF_cmdPropRxAdv_custom,                           \
    (const rfc_CMD_PROP_RX_ADV_t *)&RF_cmdPropTxAdv_custom,                           \
    (const rfc_CMD_PROP_CS_t *)&RF_cmdPropCs_custom,                                  \
    (void *)NULL                                                                                     \
} 

/*
 Channel mask used when CONFIG_FH_ENABLE is false.
 Each bit indicates if the corresponding channel is to be scanned
 First byte represents channels 0 to 7 and the last byte represents
 channels 128 to 135.
 For byte zero in the bit mask, LSB representing Ch0.
 For byte 1, LSB represents Ch8 and so on.
 e.g., 0x01 0x10 represents Ch0 and Ch12 are included.
*/
#define CONFIG_CHANNEL_MASK             { 0x0F,0x00,0x00,0x00,0x00,0x00, \
                                          0x00,0x00,0x00,0x00,0x00,0x00, \
                                          0x00,0x00,0x00,0x00,0x00 }

/*
 Channel mask used when CONFIG_FH_ENABLE is true.
 Represents the list of channels on which the device can hop.
 The actual sequence used shall be based on DH1CF function.
 It is represented as a bit string with LSB representing Ch0.
 e.g., 0x01 0x10 represents Ch0 and Ch12 are included.
 */
#define CONFIG_FH_CHANNEL_MASK          { 0xFF,0xFF,0xFF,0xFF,0xFF,0xFF, \
                                          0xFF,0xFF,0xFF,0xFF,0xFF,0xFF, \
                                          0xFF,0xFF,0xFF,0xFF,0x01 }

/*
 List of channels to target asynchronous frames when CONFIG_FH_ENABLE = true.
 It is represented as a bit string with LSB representing Ch0
 e.g., 0x01 0x10 represents Ch0 and Ch12 are included
 It should cover all channels that could be used by a target device in its
 hopping sequence. Channels marked beyond number of channels supported by
 PHY Config will be excluded by stack. To avoid interference on a channel,
 it should be removed from Async Mask and excluded from the FH channel mask.
 */
#define FH_ASYNC_CHANNEL_MASK           { 0xFF,0xFF,0xFF,0xFF,0xFF,0xFF, \
                                          0xFF,0xFF,0xFF,0xFF,0xFF,0xFF, \
                                          0xFF,0xFF,0xFF,0xFF,0x01 }

/*
Channel mask composed of all supported channels for selected PHY. Used to
validate user input during runtime channel mask configuration.
*/
#define CUI_VALID_CHANNEL_MASK          { 0xFF,0xFF,0xFF,0xFF,0xFF,0xFF, \
                                          0xFF,0xFF,0xFF,0xFF,0xFF,0xFF, \
                                          0xFF,0xFF,0xFF,0xFF,0x01 }

/* Setting for FH network name attribute */
#define CONFIG_FH_NETNAME               {"FHTest"}

/*
 Setting for reporting interval - in milliseconds to be set on connected devices
 using configuration request messages
 */
#define CONFIG_REPORTING_INTERVAL       10000

/*
 Setting for polling interval - in milliseconds to be set on connected devices
 using configuration request messages
 */
#define CONFIG_POLLING_INTERVAL         800

/* Setting for interval in ms between tracking message intervals */
#define CONFIG_SCAN_BACKOFF_INTERVAL    5000

/* Setting for delay in ms between orphan notifications */
#define CONFIG_ORPHAN_BACKOFF_INTERVAL  300000

/* Setting for scan duration in seconds */
#define CONFIG_SCAN_DURATION            5

/* Setting for beacon order */
#define CONFIG_MAC_BEACON_ORDER         15

/* Setting for superframe order */
#define CONFIG_MAC_SUPERFRAME_ORDER     15

/* Setting for minimum backoff exponent */
#define CONFIG_MIN_BE                   3

/* Setting for maximum backoff exponent */
#define CONFIG_MAX_BE                   5

/* ! Setting for transmit power in dBm */
#define CONFIG_TRANSMIT_POWER           5

/* Setting to enable frequency hopping mode */
#define CONFIG_FH_ENABLE                false

/* Setting to enable RX on when idle. False for sleepy device */
#define CONFIG_RX_ON_IDLE               false

/* Setting to enable network security */
#define CONFIG_SECURE                   true

/* Setting for network security key*/
#define KEY_TABLE_DEFAULT_KEY           { 0x12,0x34,0x56,0x78,0x9A,0xBC,0xDE,0xF0, \
                                          0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00 }

/* Setting to enable certification test mode */
#define CERTIFICATION_TEST_MODE         false

#ifdef __cplusplus
}
#endif

#endif /* TI_154STACK_CONFIG_H */
