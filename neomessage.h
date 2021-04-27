// This file is a subset of the neomessage.h found in libicsneo/include/communication/message

#ifndef __NEOMESSAGE_H_
#define __NEOMESSAGE_H_

#pragma pack(push, 1)

#ifdef _MSC_VER
#pragma warning(push)
#pragma warning(disable : 4201) // nameless struct/union
#endif
typedef union {
	struct {
		uint32_t globalError : 1;
		uint32_t transmitMessage : 1;
		uint32_t extendedFrame : 1;
		uint32_t remoteFrame : 1;
		uint32_t crcError : 1;
		uint32_t canErrorPassive : 1;
		uint32_t incompleteFrame : 1;
		uint32_t lostArbitration : 1;
		uint32_t undefinedError : 1;
		uint32_t canBusOff : 1;
		uint32_t canErrorWarning : 1;
		uint32_t canBusShortedPlus : 1;
		uint32_t canBusShortedGround : 1;
		uint32_t checksumError : 1;
		uint32_t badMessageBitTimeError : 1;
		uint32_t ifrData : 1;
		uint32_t hardwareCommError : 1;
		uint32_t expectedLengthError : 1;
		uint32_t incomingNoMatch : 1;
		uint32_t statusBreak : 1;
		uint32_t avsiRecOverflow : 1;
		uint32_t testTrigger : 1;
		uint32_t audioComment : 1;
		uint32_t gpsData : 1;
		uint32_t analogDigitalInput : 1;
		uint32_t textComment : 1;
		uint32_t networkMessageType : 1;
		uint32_t vsiTXUnderrun : 1;
		uint32_t vsiIFRCRCBit : 1;
		uint32_t initMessage : 1;
		//uint32_t highSpeedMessage : 1; // Occupies the same space as flexraySecondStartupFrame
		uint32_t flexraySecondStartupFrame : 1;
		uint32_t extended : 1;
		// ~~~ End of bitfield 1 ~~~
		uint32_t hasValue : 1;
		uint32_t valueIsBoolean : 1;
		uint32_t highVoltage : 1;
		uint32_t longMessage : 1;
		uint32_t : 12;
		uint32_t globalChange : 1;
		uint32_t errorFrame : 1;
		uint32_t : 2;
		uint32_t endOfLongMessage : 1;
		uint32_t linErrorRXBreakNotZero : 1;
		uint32_t linErrorRXBreakTooShort : 1;
		uint32_t linErrorRXSyncNot55 : 1;
		uint32_t linErrorRXDataGreaterEight : 1;
		uint32_t linErrorTXRXMismatch : 1;
		uint32_t linErrorMessageIDParity : 1;
		//isoFrameError
		uint32_t linSyncFrameError : 1;
		//isoOverflowError
		uint32_t linIDFrameError : 1;
		//isoParityError
		uint32_t linSlaveByteError : 1;
		uint32_t rxTimeoutError : 1;
		uint32_t linNoSlaveData : 1;
		// mostPacketData
		// mostStatus
		// mostLowLevel
		// mostControlData
		// mostMHPUserData
		// mostMHPControlData
		// mostI2SDump
		// mostTooShort
		// most50
		// most150
		// mostChangedParameter
		// ethernetCRCError
		// ethernetFrameTooShort
		// ethernetFCSAvailable
		// ~~~ End of bitfield 2 ~~~
		//uint32_t linJustBreakSync : 1;
		//uint32_t linSlaveDataTooShort : 1;
		//uint32_t linOnlyUpdateSlaveTableOnce : 1;
		uint32_t canfdESI : 1;
		uint32_t canfdIDE : 1;
		uint32_t canfdRTR : 1;
		uint32_t canfdFDF : 1;
		uint32_t canfdBRS : 1;
	};
	uint32_t statusBitfield[4];
} neomessage_statusbitfield_t;
#ifdef _MSC_VER
#pragma warning(pop)
#endif

#define ICSNEO_NETWORK_TYPE_INVALID ((uint8_t)0)
#define ICSNEO_NETWORK_TYPE_INTERNAL ((uint8_t)1) // Used for statuses that don't actually need to be transferred to the client application
#define ICSNEO_NETWORK_TYPE_CAN ((uint8_t)2)
#define ICSNEO_NETWORK_TYPE_LIN ((uint8_t)3)
#define ICSNEO_NETWORK_TYPE_FLEXRAY ((uint8_t)4)
#define ICSNEO_NETWORK_TYPE_MOST ((uint8_t)5)
#define ICSNEO_NETWORK_TYPE_ETHERNET ((uint8_t)6)
#define ICSNEO_NETWORK_TYPE_ANY ((uint8_t)0xFE) // Never actually set as type, but used as flag for filtering
#define ICSNEO_NETWORK_TYPE_OTHER ((uint8_t)0xFF)

typedef struct {
	neomessage_statusbitfield_t status;
	uint64_t timestamp;
	uint64_t timestampReserved;
	const uint8_t* data;
	size_t length;
	uint8_t header[4];
	uint16_t netid;
	uint8_t type;
	uint8_t reserved[17];
} neomessage_t; // 72 bytes total
// Any time you add another neomessage_*_t type, make sure to add it to the static_asserts below!

typedef struct {
	neomessage_statusbitfield_t status;
	uint64_t timestamp;
	uint64_t timestampReserved;
	const uint8_t* data;
	size_t length;
	uint32_t arbid;
	uint16_t netid;
	uint8_t type;
	uint8_t dlcOnWire;
	uint8_t reserved[16];
} neomessage_can_t;

typedef struct {
	neomessage_statusbitfield_t status;
	uint64_t timestamp;
	uint64_t timestampReserved;
	const uint8_t* data;
	size_t length;
	uint8_t preemptionFlags;
	uint8_t reservedHeader[3];
	uint16_t netid;
	uint8_t type;
	uint8_t reserved[17];
} neomessage_eth_t;

#pragma pack(pop)

#endif