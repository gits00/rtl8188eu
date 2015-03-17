/******************************************************************************
 *
 * Copyright(c) 2007 - 2011 Realtek Corporation. All rights reserved.
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms of version 2 of the GNU General Public License as
 * published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for
 * more details.
 *
 * You should have received a copy of the GNU General Public License along with
 * this program; if not, write to the Free Software Foundation, Inc.,
 * 51 Franklin Street, Fifth Floor, Boston, MA 02110, USA
 *
 *
 ******************************************************************************/
#ifndef _RTW_MP_H_
#define _RTW_MP_H_

/* 	00 - Success */
/* 	11 - Error */
#define STATUS_SUCCESS				(0x00000000L)
#define STATUS_PENDING				(0x00000103L)

#define STATUS_UNSUCCESSFUL			(0xC0000001L)
#define STATUS_INSUFFICIENT_RESOURCES		(0xC000009AL)
#define STATUS_NOT_SUPPORTED			(0xC00000BBL)

#define NDIS_STATUS_SUCCESS			((NDIS_STATUS)STATUS_SUCCESS)
#define NDIS_STATUS_PENDING			((NDIS_STATUS)STATUS_PENDING)
#define NDIS_STATUS_NOT_RECOGNIZED		((NDIS_STATUS)0x00010001L)
#define NDIS_STATUS_NOT_COPIED			((NDIS_STATUS)0x00010002L)
#define NDIS_STATUS_NOT_ACCEPTED		((NDIS_STATUS)0x00010003L)
#define NDIS_STATUS_CALL_ACTIVE			((NDIS_STATUS)0x00010007L)

#define NDIS_STATUS_FAILURE			((NDIS_STATUS)STATUS_UNSUCCESSFUL)
#define NDIS_STATUS_RESOURCES			((NDIS_STATUS)STATUS_INSUFFICIENT_RESOURCES)
#define NDIS_STATUS_CLOSING			((NDIS_STATUS)0xC0010002L)
#define NDIS_STATUS_BAD_VERSION			((NDIS_STATUS)0xC0010004L)
#define NDIS_STATUS_BAD_CHARACTERISTICS		((NDIS_STATUS)0xC0010005L)
#define NDIS_STATUS_ADAPTER_NOT_FOUND		((NDIS_STATUS)0xC0010006L)
#define NDIS_STATUS_OPEN_FAILED			((NDIS_STATUS)0xC0010007L)
#define NDIS_STATUS_DEVICE_FAILED		((NDIS_STATUS)0xC0010008L)
#define NDIS_STATUS_MULTICAST_FULL		((NDIS_STATUS)0xC0010009L)
#define NDIS_STATUS_MULTICAST_EXISTS		((NDIS_STATUS)0xC001000AL)
#define NDIS_STATUS_MULTICAST_NOT_FOUND		((NDIS_STATUS)0xC001000BL)
#define NDIS_STATUS_REQUEST_ABORTED		((NDIS_STATUS)0xC001000CL)
#define NDIS_STATUS_RESET_IN_PROGRESS		((NDIS_STATUS)0xC001000DL)
#define NDIS_STATUS_CLOSING_INDICATING		((NDIS_STATUS)0xC001000EL)
#define NDIS_STATUS_NOT_SUPPORTED		((NDIS_STATUS)STATUS_NOT_SUPPORTED)
#define NDIS_STATUS_INVALID_PACKET		((NDIS_STATUS)0xC001000FL)
#define NDIS_STATUS_OPEN_LIST_FULL		((NDIS_STATUS)0xC0010010L)
#define NDIS_STATUS_ADAPTER_NOT_READY		((NDIS_STATUS)0xC0010011L)
#define NDIS_STATUS_ADAPTER_NOT_OPEN		((NDIS_STATUS)0xC0010012L)
#define NDIS_STATUS_NOT_INDICATING		((NDIS_STATUS)0xC0010013L)
#define NDIS_STATUS_INVALID_LENGTH		((NDIS_STATUS)0xC0010014L)
#define NDIS_STATUS_INVALID_DATA		((NDIS_STATUS)0xC0010015L)
#define NDIS_STATUS_BUFFER_TOO_SHORT		((NDIS_STATUS)0xC0010016L)
#define NDIS_STATUS_INVALID_OID			((NDIS_STATUS)0xC0010017L)
#define NDIS_STATUS_ADAPTER_REMOVED		((NDIS_STATUS)0xC0010018L)
#define NDIS_STATUS_UNSUPPORTED_MEDIA		((NDIS_STATUS)0xC0010019L)
#define NDIS_STATUS_GROUP_ADDRESS_IN_USE	((NDIS_STATUS)0xC001001AL)
#define NDIS_STATUS_FILE_NOT_FOUND		((NDIS_STATUS)0xC001001BL)
#define NDIS_STATUS_ERROR_READING_FILE		((NDIS_STATUS)0xC001001CL)
#define NDIS_STATUS_ALREADY_MAPPED		((NDIS_STATUS)0xC001001DL)
#define NDIS_STATUS_RESOURCE_CONFLICT		((NDIS_STATUS)0xC001001EL)
#define NDIS_STATUS_NO_CABLE			((NDIS_STATUS)0xC001001FL)

#define NDIS_STATUS_INVALID_SAP			((NDIS_STATUS)0xC0010020L)
#define NDIS_STATUS_SAP_IN_USE			((NDIS_STATUS)0xC0010021L)
#define NDIS_STATUS_INVALID_ADDRESS		((NDIS_STATUS)0xC0010022L)
#define NDIS_STATUS_VC_NOT_ACTIVATED		((NDIS_STATUS)0xC0010023L)
#define NDIS_STATUS_DEST_OUT_OF_ORDER		((NDIS_STATUS)0xC0010024L)  /*  cause 27 */
#define NDIS_STATUS_VC_NOT_AVAILABLE		((NDIS_STATUS)0xC0010025L)  /*  cause 35,45 */
#define NDIS_STATUS_CELLRATE_NOT_AVAILABLE	((NDIS_STATUS)0xC0010026L)  /*  cause 37 */
#define NDIS_STATUS_INCOMPATABLE_QOS		((NDIS_STATUS)0xC0010027L)  /*  cause 49 */
#define NDIS_STATUS_AAL_PARAMS_UNSUPPORTED	((NDIS_STATUS)0xC0010028L)  /*  cause 93 */
#define NDIS_STATUS_NO_ROUTE_TO_DESTINATION	((NDIS_STATUS)0xC0010029L)  /*  cause 3 */

enum ANTENNA_PATH {
	ANTENNA_NONE	= 0x00,
	ANTENNA_D,
	ANTENNA_C,
	ANTENNA_CD,
	ANTENNA_B,
	ANTENNA_BD,
	ANTENNA_BC,
	ANTENNA_BCD,
	ANTENNA_A,
	ANTENNA_AD,
	ANTENNA_AC,
	ANTENNA_ACD,
	ANTENNA_AB,
	ANTENNA_ABD,
	ANTENNA_ABC,
	ANTENNA_ABCD
};


#define MAX_MP_XMITBUF_SZ	2048
#define NR_MP_XMITFRAME		8

struct mp_xmit_frame {
	struct  list_head list;
	struct pkt_attrib attrib;
	struct sk_buff *pkt;
	int frame_tag;
	struct adapter *padapter;

	/* insert urb, irp, and irpcnt info below... */
	/* max frag_cnt = 8 */

	u8 *mem_addr;
	u32 sz[8];

	struct urb * pxmit_urb[8];
	u8 bpending[8];
	sint ac_tag[8];
	sint last[8];
	uint irpcnt;
	uint fragcnt;
	uint mem[(MAX_MP_XMITBUF_SZ >> 2)];
};

struct mp_wiparam {
	u32 bcompleted;
	u32 act_type;
	u32 io_offset;
	u32 io_value;
};

struct mp_tx {
	u8 stop;
	u32 count, sended;
	u8 payload;
	struct pkt_attrib attrib;
	struct tx_desc desc;
	u8 *pallocated_buf;
	u8 *buf;
	u32 buf_size, write_size;
	void * PktTxThread;
};

#include <Hal8188EPhyCfg.h>

#define MP_MAX_LINES		1000
#define MP_MAX_LINES_BYTES	256

#define ULONG u32
#define PULONG u32*

struct mpt_context {
	/*  Indicate if we have started Mass Production Test. */
	bool			bMassProdTest;

	/*  Indicate if the driver is unloading or unloaded. */
	bool			bMptDrvUnload;

	struct  semaphore MPh2c_Sema;
	struct timer_list MPh2c_timeout_timer;
/*  Event used to sync H2c for BT control */

	bool		MptH2cRspEvent;
	bool		MptBtC2hEvent;
	bool		bMPh2c_timeout;

	bool			bMptWorkItemInProgress;
	/*  An instance which implements function and context of MptWorkItem. */
	void (*CurrMptAct)(void * Adapter);

	/*  1=Start, 0=Stop from UI. */
	ULONG			MptTestStart;
	/*  _TEST_MODE, defined in MPT_Req2.h */
	ULONG			MptTestItem;
	/*  Variable needed in each implementation of CurrMptAct. */
	ULONG			MptActType;	/*  Type of action performed in CurrMptAct. */
	/*  The Offset of IO operation is depend of MptActType. */
	ULONG			MptIoOffset;
	/*  The Value of IO operation is depend of MptActType. */
	ULONG			MptIoValue;
	/*  The RfPath of IO operation is depend of MptActType. */
	ULONG			MptRfPath;

	WIRELESS_MODE		MptWirelessModeToSw;	/*  Wireless mode to switch. */
	u8			MptChannelToSw;		/*  Channel to switch. */
	u8			MptInitGainToSet;	/*  Initial gain to set. */
	ULONG			MptBandWidth;		/*  bandwidth to switch. */
	ULONG			MptRateIndex;		/*  rate index. */
	/*  Register value kept for Single Carrier Tx test. */
	u8			btMpCckTxPower;
	/*  Register value kept for Single Carrier Tx test. */
	u8			btMpOfdmTxPower;
	/*  For MP Tx Power index */
	u8			TxPwrLevel[2];	/*  rf-A, rf-B */

	/*  Content of RCR Regsiter for Mass Production Test. */
	ULONG			MptRCR;
	/*  true if we only receive packets with specific pattern. */
	bool			bMptFilterPattern;
	/*  Rx OK count, statistics used in Mass Production Test. */
	ULONG			MptRxOkCnt;
	/*  Rx CRC32 error count, statistics used in Mass Production Test. */
	ULONG			MptRxCrcErrCnt;

	bool			bCckContTx;	/*  true if we are in CCK Continuous Tx test. */
	bool			bOfdmContTx;	/*  true if we are in OFDM Continuous Tx test. */
	bool			bStartContTx;	/*  true if we have start Continuous Tx test. */
	/*  true if we are in Single Carrier Tx test. */
	bool			bSingleCarrier;
	/*  true if we are in Carrier Suppression Tx Test. */
	bool			bCarrierSuppression;
	/* true if we are in Single Tone Tx test. */
	bool			bSingleTone;

	/*  ACK counter asked by K.Y.. */
	bool			bMptEnableAckCounter;
	ULONG			MptAckCounter;

	/*  SD3 Willis For 8192S to save 1T/2T RF table for ACUT	Only fro ACUT delete later ~~~! */
	/* s8		BufOfLines[2][MAX_LINES_HWCONFIG_TXT][MAX_BYTES_LINE_HWCONFIG_TXT]; */
	/* s8			BufOfLines[2][MP_MAX_LINES][MP_MAX_LINES_BYTES]; */
	/* s32			RfReadLine[2]; */

	u8		APK_bound[2];	/* for APK	path A/path B */
	bool		bMptIndexEven;

	u8		backup0xc50;
	u8		backup0xc58;
	u8		backup0xc30;
	u8		backup0x52_RF_A;
	u8		backup0x52_RF_B;

	u8			h2cReqNum;
	u8			c2hBuf[20];

	u8          btInBuf[100];
	ULONG			mptOutLen;
	u8          mptOutBuf[100];
};

enum {
	WRITE_REG = 1,
	READ_REG,
	WRITE_RF,
	READ_RF,
	MP_START,
	MP_STOP,
	MP_RATE,
	MP_CHANNEL,
	MP_BANDWIDTH,
	MP_TXPOWER,
	MP_ANT_TX,
	MP_ANT_RX,
	MP_CTX,
	MP_QUERY,
	MP_ARX,
	MP_PSD,
	MP_PWRTRK,
	MP_THER,
	MP_IOCTL,
	EFUSE_GET,
	EFUSE_SET,
	MP_RESET_STATS,
	MP_DUMP,
	MP_PHYPARA,
	MP_SetRFPathSwh,
	MP_QueryDrvStats,
	MP_SetBT,
	CTA_TEST,
	MP_DISABLE_BT_COEXIST,
	MP_PwrCtlDM,
	MP_NULL,
};

struct mp_priv {
	struct adapter *papdater;

	/* Testing Flag */
	u32 mode;/* 0 for normal type packet, 1 for loopback packet (16bytes TXCMD) */

	u32 prev_fw_state;

	/* OID cmd handler */
	struct mp_wiparam workparam;
/* 	u8 act_in_progress; */

	/* Tx Section */
	u8 TID;
	u32 tx_pktcount;
	struct mp_tx tx;

	/* Rx Section */
	u32 rx_pktcount;
	u32 rx_crcerrpktcount;
	u32 rx_pktloss;

	struct recv_stat rxstat;

	/* RF/BB relative */
	u8 channel;
	u8 bandwidth;
	u8 prime_channel_offset;
	u8 txpoweridx;
	u8 txpoweridx_b;
	u8 rateidx;
	u32 preamble;
	u32 CrystalCap;
	u16 antenna_tx;
	u16 antenna_rx;
	u8 check_mp_pkt;
	u8 bSetTxPower;
	struct wlan_network mp_network;
	u8 network_macaddr[ETH_ALEN];

	u8 *pallocated_mp_xmitframe_buf;
	u8 *pmp_xmtframe_buf;
	struct  __queue free_mp_xmitqueue;
	u32 free_mp_xmitframe_cnt;
	struct mpt_context MptCtx;
};

struct rf_reg_param {
	u32 path;
	u32 offset;
	u32 value;
};

struct bb_reg_param {
	u32 offset;
	u32 value;
};
/*  */

#define LOWER	true
#define RAISE	false

/* Hardware Registers */
#define BB_REG_BASE_ADDR		0x800

/* MP variables */
enum MP_MODE {
	MP_OFF,
	MP_ON,
	MP_ERR,
	MP_CONTINUOUS_TX,
	MP_SINGLE_CARRIER_TX,
	MP_CARRIER_SUPPRISSION_TX,
	MP_SINGLE_TONE_TX,
	MP_PACKET_TX,
	MP_PACKET_RX
};

#define MAX_RF_PATH_NUMS	RF_PATH_MAX

extern u8 mpdatarate[NumRates];

/* MP set force data rate base on the definition. */
enum MPT_RATE_INDEX {
	/* CCK rate. */
	MPT_RATE_1M,	/* 0 */
	MPT_RATE_2M,
	MPT_RATE_55M,
	MPT_RATE_11M,	/* 3 */

	/* OFDM rate. */
	MPT_RATE_6M,	/* 4 */
	MPT_RATE_9M,
	MPT_RATE_12M,
	MPT_RATE_18M,
	MPT_RATE_24M,
	MPT_RATE_36M,
	MPT_RATE_48M,
	MPT_RATE_54M,	/* 11 */

	/* HT rate. */
	MPT_RATE_MCS0,	/* 12 */
	MPT_RATE_MCS1,
	MPT_RATE_MCS2,
	MPT_RATE_MCS3,
	MPT_RATE_MCS4,
	MPT_RATE_MCS5,
	MPT_RATE_MCS6,
	MPT_RATE_MCS7,	/* 19 */
	MPT_RATE_MCS8,
	MPT_RATE_MCS9,
	MPT_RATE_MCS10,
	MPT_RATE_MCS11,
	MPT_RATE_MCS12,
	MPT_RATE_MCS13,
	MPT_RATE_MCS14,
	MPT_RATE_MCS15,	/* 27 */
	MPT_RATE_LAST
};

#define MAX_TX_PWR_INDEX_N_MODE 64	/*  0x3F */

enum POWER_MODE {
	POWER_LOW = 0,
	POWER_NORMAL
};

#define RX_PKT_BROADCAST	1
#define RX_PKT_DEST_ADDR	2
#define RX_PKT_PHY_MATCH	3

enum ENCRY_CTRL_STATE {
	HW_CONTROL,		/* hw encryption& decryption */
	SW_CONTROL,		/* sw encryption& decryption */
	HW_ENCRY_SW_DECRY,	/* hw encryption & sw decryption */
	SW_ENCRY_HW_DECRY	/* sw encryption & hw decryption */
};

#define Mac_OFDM_OK			0x00000000
#define Mac_OFDM_Fail			0x10000000
#define Mac_OFDM_FasleAlarm	0x20000000
#define Mac_CCK_OK				0x30000000
#define Mac_CCK_Fail			0x40000000
#define Mac_CCK_FasleAlarm		0x50000000
#define Mac_HT_OK				0x60000000
#define Mac_HT_Fail				0x70000000
#define Mac_HT_FasleAlarm		0x90000000
#define Mac_DropPacket			0xA0000000

s32 init_mp_priv(struct adapter *padapter);
void free_mp_priv(struct mp_priv *pmp_priv);
s32 MPT_InitializeAdapter(struct adapter *padapter, u8 Channel);
void MPT_DeInitAdapter(struct adapter *padapter);
s32 mp_start_test(struct adapter *padapter);
void mp_stop_test(struct adapter *padapter);

u32 _read_rfreg(struct adapter *padapter, u8 rfpath, u32 addr, u32 bitmask);
void _write_rfreg(struct adapter *padapter, u8 rfpath, u32 addr, u32 bitmask, u32 val);

u32 read_macreg(struct adapter *padapter, u32 addr, u32 sz);
void write_macreg(struct adapter *padapter, u32 addr, u32 val, u32 sz);
u32 read_bbreg(struct adapter *padapter, u32 addr, u32 bitmask);
void write_bbreg(struct adapter *padapter, u32 addr, u32 bitmask, u32 val);
u32 read_rfreg(struct adapter *padapter, RF_RADIO_PATH_E rfpath, u32 addr);
void write_rfreg(struct adapter *padapter, u8 rfpath, u32 addr, u32 val);

void	SetChannel(struct adapter *pAdapter);
void	SetBandwidth(struct adapter *pAdapter);
void	SetTxPower(struct adapter *pAdapter);
void	SetAntennaPathPower(struct adapter *pAdapter);
void	SetTxAGCOffset(struct adapter *pAdapter, u32 ulTxAGCOffset);
void	SetDataRate(struct adapter *pAdapter);

void	SetAntenna(struct adapter *pAdapter);

s32	SetThermalMeter(struct adapter *pAdapter, u8 target_ther);
void	GetThermalMeter(struct adapter *pAdapter, u8 *value);

void	SetContinuousTx(struct adapter *pAdapter, u8 bStart);
void	SetSingleCarrierTx(struct adapter *pAdapter, u8 bStart);
void	SetSingleToneTx(struct adapter *pAdapter, u8 bStart);
void	SetCarrierSuppressionTx(struct adapter *pAdapter, u8 bStart);
void PhySetTxPowerLevel(struct adapter *pAdapter);

void	fill_txdesc_for_mp(struct adapter *padapter, struct tx_desc *ptxdesc);
void	SetPacketTx(struct adapter *padapter);
void	SetPacketRx(struct adapter *pAdapter, u8 bStartRx);

void	ResetPhyRxPktCount(struct adapter *pAdapter);
u32	GetPhyRxPktReceived(struct adapter *pAdapter);
u32	GetPhyRxPktCRC32Error(struct adapter *pAdapter);

s32	SetPowerTracking(struct adapter *padapter, u8 enable);
void	GetPowerTracking(struct adapter *padapter, u8 *enable);

u32	mp_query_psd(struct adapter *pAdapter, u8 *data);


void Hal_SetAntenna(struct adapter *pAdapter);
void Hal_SetBandwidth(struct adapter *pAdapter);

void Hal_SetTxPower(struct adapter *pAdapter);
void Hal_SetCarrierSuppressionTx(struct adapter *pAdapter, u8 bStart);
void Hal_SetSingleToneTx ( struct adapter *pAdapter , u8 bStart );
void Hal_SetSingleCarrierTx (struct adapter *pAdapter, u8 bStart);
void Hal_SetContinuousTx (struct adapter *pAdapter, u8 bStart);
void Hal_SetBandwidth(struct adapter *pAdapter);

void Hal_SetDataRate(struct adapter *pAdapter);
void Hal_SetChannel(struct adapter *pAdapter);
void Hal_SetAntennaPathPower(struct adapter *pAdapter);
s32 Hal_SetThermalMeter(struct adapter *pAdapter, u8 target_ther);
s32 Hal_SetPowerTracking(struct adapter *padapter, u8 enable);
void Hal_GetPowerTracking(struct adapter *padapter, u8 * enable);
void Hal_GetThermalMeter(struct adapter *pAdapter, u8 *value);
void Hal_mpt_SwitchRfSetting(struct adapter *pAdapter);
void Hal_MPT_CCKTxPowerAdjust(struct adapter *Adapter, bool bInCH14);
void Hal_MPT_CCKTxPowerAdjustbyIndex(struct adapter *pAdapter, bool beven);
void Hal_SetCCKTxPower(struct adapter *pAdapter, u8 * TxPower);
void Hal_SetOFDMTxPower(struct adapter *pAdapter, u8 * TxPower);
void Hal_TriggerRFThermalMeter(struct adapter *pAdapter);
u8 Hal_ReadRFThermalMeter(struct adapter *pAdapter);
void Hal_SetCCKContinuousTx(struct adapter *pAdapter, u8 bStart);
void SetCCKContinuousTx(struct adapter *pAdapter, u8 bStart);
void SetOFDMContinuousTx(struct adapter *pAdapter, u8 bStart);
void Hal_SetOFDMContinuousTx(struct adapter *pAdapter, u8 bStart);
void Hal_ProSetCrystalCap (struct adapter *pAdapter , u32 CrystalCapVal);
void _rtw_mp_xmit_priv(struct xmit_priv *pxmitpriv);
void MP_PHY_SetRFPathSwitch(struct adapter *pAdapter ,bool bMain);
void MPT_PwrCtlDM(struct adapter *padapter, u32 bstart);

#endif /* _RTW_MP_H_ */
