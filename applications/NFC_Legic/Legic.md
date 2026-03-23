

Classification   License partner documentation (Info Level 3)
Docu. No.LA-33-110d-en
## Edition05.2006
LEGIC advant
## ®

## 2000 Series
## Reference Manual
## Commands
SC-2560 Vxx20
SM-2570 Vxx20
## Headquarters
LEGIC® Identsystems Ltd.
## Kastellstrasse 1, Post Box 673
CH-8623 Wetzikon
## Switzerland
## Phone  +41 44 933 64 64
## Fax+41 44 933 64 65
Email    info@legic.com
## Asia
## Phone  +86 21 6288 4108
## Fax+86 21 6288 4106
Email    infoasia@legic.com
www.legic.com
## PRELIMINARY


## ..
## PRELIMINARY


LEGIC Identsystems Ltd
## CONFIDENTIAL
## 000-00

LEGIC advant 2000 Series
Reference Manual, Commands, SC-2560, SM-2570
05.2006© Transmission of contents to others prohibitedLA-33-110d-en1/92
Technical specifications subject to change
Commands, SC-2560, SM-2570LA-33-110d-en
Table of contents
1About this document .............................................................................................  3
Scope .......................................................................................................................  3
Target users .............................................................................................................  3
Further documents ...................................................................................................  3
Conventions .............................................................................................................  3
Change history .........................................................................................................  3
Compatibility  ............................................................................................................   4
Trade mark  ..............................................................................................................  4
2Command overview  ...............................................................................................   5
Command sets .........................................................................................................  5
Command structure  .................................................................................................  5
Operating commands  ..............................................................................................  6
Set-up commands ....................................................................................................  7
Initialization commands  ...........................................................................................  7
LEGIC prime commands  .........................................................................................  7
2.1SEARCH_TXP .........................................................................................................  9
2.2SELECT_TXP ........................................................................................................  10
2.3SEARCH_SEGMENT  ............................................................................................   12
2.4GET_TXP_INFO ....................................................................................................  16
2.5READ .....................................................................................................................  20
2.6WRITE  ...................................................................................................................   22
2.7MAKE_CRC ...........................................................................................................  24
2.8AUTO_READ .........................................................................................................  26
2.9IDLE ....................................................................................................................... 30
2.10GET_STATUS  .......................................................................................................   31
2.11STATUS .................................................................................................................  34
2.12POWER_REDUCTION ..........................................................................................  36
2.13GET_EVENT  .........................................................................................................   37
2.14INIT_VALUE  ..........................................................................................................   39
2.15OPEN_VALUE .......................................................................................................  41
2.16WRITE_VALUE  .....................................................................................................   43
2.17ADD_VALUE  .........................................................................................................   44
2.18SUB_VALUE ..........................................................................................................  45
2.19READ_VALUE  .......................................................................................................   46
2.20VAL_COM_ANSWER ............................................................................................  47
2.21GET_PORT  ...........................................................................................................   50
2.22SET_PORT ............................................................................................................  51
2.23UNLOCK ................................................................................................................  53
2.24LOCK  .....................................................................................................................   54
2.25BUS_ENABLE  .......................................................................................................   55
2.26SUPERUSER_MODE ............................................................................................  57
2.27RESET ...................................................................................................................  58
## PRELIMINARY


LEGIC Identsystems Ltd
## CONFIDENTIAL
## 000-00

LEGIC advant 2000 Series
Reference Manual, Commands, SC-2560, SM-2570
2/92LA-33-110d-en© Transmission of contents to others prohibited05.2006
Technical specifications subject to change
2.28POWER_SAVE ......................................................................................................  59
2.29AUTH_A .................................................................................................................  60
2.30AUTH_B .................................................................................................................  61
2.31AUTH_MSG  ...........................................................................................................   63
2.32ENCRYPT_MSG  ...................................................................................................   65
2.33AUTH_ENCRYPT_MSG ........................................................................................  67
2.34SET_PARAMETER  ...............................................................................................   69
2.35GET_PARAMETER  ...............................................................................................   71
2.36DELETE_LAUNCH_DATA  ....................................................................................  73
2.37START_SWDL .......................................................................................................  74
2.38DATA_SWDL  .........................................................................................................   77
2.39SET_PASSWORD  .................................................................................................  78
2.40ADD_MASTER_DATA ...........................................................................................  79
2.41DELETE_MASTER_DATA  ....................................................................................   81
2.42ADD_SEGMENT  ...................................................................................................   82
2.43REMOVE_SEGMENT  ...........................................................................................   88
3Status and Error Codes .......................................................................................  90
Overview  ................................................................................................................   90
General errors ........................................................................................................  90
System error or fatal error ......................................................................................  92
## PRELIMINARY


LEGIC Identsystems Ltd
## CONFIDENTIAL
## 000-00

LEGIC advant 2000 Series
Reference Manual, Commands, SC-2560, SM-2570
05.2006© Transmission of contents to others prohibitedLA-33-110d-en3/92
Technical specifications subject to change
1About this document
ScopeThis document describes the commands for bi-directional interfaces of the LEGIC advant
SM, contained in the secure reader operating system LEGIC OS.
Target usersThis document addresses engineers and technicians who are entrusted with developing ap-
plication software for readers with LEGIC advant technology.
The LEGIC training program is matched to this documentation. The persons mentioned
above must have attended the corresponding training courses.
Further documents
NoteRefer also to the document "Document Regulations, LA-03-150" for handling the LEGIC ad-
vant documentation, for information on the intended use of LEGIC products and on warranty.
Conventions•LEGIC prime: Name of the existing LEGIC product line (with MIM256, MIM1024,
## SM05-S..., SM100-S..., SM300-S...).
•Note on LEGIC prime: Differences and information that must be observed during the
migration from LEGIC prime to LEGIC advant.
•LEGIC advant SM: Security module (general term for the designs Security Chip Set and
## Security Module)
•TXP: Transponder in general
•ATC: LEGIC advant Transponder Chip
•MIM: LEGIC prime Transponder Chip
-   Hexadecimal figures are represented in the form 0xnm (e.g. 0x23)
-   Commands and status messages are represented in upper-case letters (e.g.
## SET_PARAMETER)
-   Remarks and examples are represented in italics.
-   Warnings (Important, Attention) are shown in bold print.
Change history
Documentation typeTitleDoc. No.
[2]    Reference ManualSecurity Rules, SC-2560, SM-2570LA-13-050
[3]    User ManualLEGIC advant 2000 Series, SC-2560, SM-2570  LA-13-100
[4]    Reference ManualApplication interfaces, SC-2560, SM-2570LA-33-105
[5]    Reference ManualInformation Database IDB, SC-2560, SM-2570   LA-33-100
[6]    Product DescriptionLEGIC prime documentation:
SM-S Software V7.x
## L3-05-005
[7]    Product DescriptionLEGIC prime documentation:
MSM-S Software V4.x
## L3-05-010
ChangeEditionDocu. No.
New edition11.2003LA-33-110a
–   Additions see page 19 and page 47
–   Corrections see page 6, page 12, page 13 and page 75
–   Change of the AUTO_READ command
06.2004LA-33-110b
Extensions in notes on LEGIC prime commands, page 711.2005LA-33-110c
Changes for LEGIC OS V2.0
–   Changed commands: POWER_SAVE (previous STOP),
## SEARCH_TXP
–   New command: GET_EVENT
–   Temp. segment no longer available: SEARCH_
## SEGMENT, ADD_SEGMENT, REMOVE_SEGMENT
05.2006LA-33-110d
## PRELIMINARY


LEGIC Identsystems Ltd
## CONFIDENTIAL
## 000-00

LEGIC advant 2000 Series
Reference Manual, Commands, SC-2560, SM-2570
4/92LA-33-110d-en© Transmission of contents to others prohibited05.2006
Technical specifications subject to change
CompatibilityThis document refers to the LEGIC advant SM types SC-2560 Vxx20 and SM-2570 Vxx20.
(with LEGIC OS version 2.0) The version is printed on each LEGIC advant SM (with the Se-
curity Chip Sets on the LEGIC OS controller). The coding of the imprint is described in the
product description of the respective LEGIC advant SM.
The version can also be read from the LEGIC advant SM (IDB object SYSTEM_INFO).
Trade markINSIDE Contactless is a trade mark of INSIDE Contactless.
## PRELIMINARY


LEGIC Identsystems Ltd
## CONFIDENTIAL
## 000-00

LEGIC advant 2000 Series
Reference Manual, Commands, SC-2560, SM-2570
05.2006© Transmission of contents to others prohibitedLA-33-110d-en5/92
Technical specifications subject to change
2Command overview
Command setsFor the bi-directional interfaces (SPI, serial-asynchronous) the following command sets are
available depending on the LEGIC advant SM type.
The interfaces OMRON, Wiegand and BPA/L cannot be addressed via commands. They
operate in the AUTO_READ mode (in accordance with the settings in the IDB objects
## AUTO_READ...).
## *
The LEGIC cash Standard is only available with the security modules SC-2140C, SC-2240C, SC-2560C and
SM-2570C. This security module can only be purchased with a supplement to the license agreement.
Operating commandsThe operating commands are mainly used for communication with the transponder. They are
contained in every LEGIC advant security module.
Set-up commandsThe set-up commands are used to set and interrogate parameters in the information data-
base (IDB) in the security module. They are contained in every LEGIC advant security mod-
ule.
Initialization commandsThe initialization commands are used to initialize authorization and application segments.
LEGIC prime commandsLEGIC advant contains new commands that are in some cases not compatible to the LEGIC
prime commands (SM-S Software Version 7.x, MSM-S Version 4.1).
To ensure downward compatibility, the LEGIC prime commands for transponder access (e.g.
SM_START, WRITE_MIM) are also contained in LEGIC advant.
ImportantThe LEGIC prime commands only function with LEGIC prime transponders (MIM).
The LEGIC prime commands must not be used for new developments!
The LEGIC prime transponders (MIM) can also be processed with the LEGIC advant com-
mands.
Commands for LEGIC cash
## TM
## Standard
The high-level commands for the LEGIC cash standard are used for simple handling of
LEGIC cash segments on LEGIC transponders. These commands are only available with the
LEGIC advant SM SC-2140C, SC-2240C, SC-2560C and SM-2570C. They are described in
the reference manual "LEGIC cash" LA-53-030 .
This documentation and the corresponding security modules are only available for licensed
partners which have signed a corresponding supplement to the license agreement.
Note on LEGIC primeThe LEGIC cash standard commands correspond to the LEGIC plus Cash application.
Command structureThe structure of commands and answers is described in document [4], Command Structure
chapter.
Command SetSC-2140,
## SC-2240
## SC-2140C,
## SC-2240C
## SC-2560,
## SM-2570
## SC-2560C,
## SM-2570C
Operating commandsXXXX
Set-up commandsXXXX
Initialization commandsXX
LEGIC prime commandsXXXX
Commands for LEGIC cash
## TM
## Stand-
ard*
## XX
Table 1: Command sets
## PRELIMINARY


LEGIC Identsystems Ltd
## CONFIDENTIAL
## 000-00

LEGIC advant 2000 Series
Reference Manual, Commands, SC-2560, SM-2570
6/92LA-33-110d-en© Transmission of contents to others prohibited05.2006
Technical specifications subject to change
Operating commandsThe following operating commands are available with SC-2560 and SM-2570.
Command NameDescriptionCommand
## Code
## Details,
see
TXP access
SEARCH_TXPSearches for the TXPs located in the RF field and returns their unique numbers (UID) (max.
8 UIDs)
0xB0page 9
SELECT_TXPSelects a TXP located in the RF field (from SEARCH_TXP answer) and authenticates it,
also evaluates launch media
0xB1page 10
SEARCH_SEGMENTSelects a segment o the TXP addressed with SELECT_TXP0xB2page 12
GET_TXP_INFOReads the data areas TXP_INFO, FS_INFO or S_INFO0x9Apage 16
READReads a number of data bytes from the S_DATA area (max. 200 bytes)0xC0page 20
WRITEWrites a number of data bytes to the S_DATA area (max. 200 bytes)0xC1page 22
MAKE_CRCCalculates the CRC value via the specified data bytes and writes these to the specified ad-
dress in the S_DATA area
0xC2page 24
AUTO_READPeriodically searches for a TXP with the desired search criteria (contains SEARCH_TXP,
SELECT_TXP SEARCH_SEGMENT and READ)
## 0x79page 26
## States
IDLEPuts the LEGIC advant SM in the communication state "Idle", switches the RF carrier on or
off or activates the Sleep mode
## 0x14page 30
GET_STATUSInterrogates the system status of the LEGIC advant SM0x30page 31
STATUSStatus or error answer, follows incorrectly executed commands,
same format as answer to GET_STATUS
## 0x30page 34
POWER_REDUCTIONReduces the transmission power of LEGIC advant SM0x12page 36
GET_EVENTInterrogates the accumulated signalling and/or wake-up events0x34page 37
Handling value fields
INIT_VALUECreates a new value field.0x5Dpage 39
OPEN_VALUEOpens a value field. 0x59page 41
WRITE_VALUEWrites a new value to the value field.0x5Apage 43
ADD_VALUEAdds a value to the value field.0x5Bpage 44
SUB_VALUESubtracts a value from the value field.0x5Cpage 45
READ_VALUEReads the value from a value field.0x28page 46
Digital inputs and outputs
GET_PORTReads the states of the digital inputs and outputs of the LEGIC advant SM.0x72page 50
SET_PORTSets the digital outputs of the LEGIC advant SM.0x74page 51
Password protection of SM
UNLOCKEnables LEGIC advant SM with password protection0x02page 53
LOCKLocks LEGIC advant SM with password protection0x03page 54
Bus operation
BUS_ENABLEBus operation0x04page 55
Superuser mode
SUPERUSER_MODESwitches the LEGIC advant into the "Superuser Mode" communication state0xBApage 57
RESETTriggers a reset of the LEGIC advant SM (only possible in the "Superuser mode")0xB7page 58
POWER_SAVESets the LEGIC advant SM to the extended power saving mode (stop/watch)
(only possible in the "Superuser mode")
0xBFpage 59
Protected mode
AUTH_AStarts authentication via application interface (Step A)0xD0page 60
AUTH_BStarts authentication via application interface (Step B)0xD1page 61
AUTH_MSGSends authenticated command0xD2page 63
ENCRYPT_MSGSends encrypted command0xD3page 65
AUTH_ENCRYPT_MSGSends authenticated and encrypted command0xD4page 67
Table 2: Operating commands
## PRELIMINARY


LEGIC Identsystems Ltd
## CONFIDENTIAL
## 000-00

LEGIC advant 2000 Series
Reference Manual, Commands, SC-2560, SM-2570
05.2006© Transmission of contents to others prohibitedLA-33-110d-en7/92
Technical specifications subject to change
Set-up commandsThe following set-up commands are available with SC-2560 and SM-2570.
Initialization commandsThe following initialization commands are available with the SC-2560 and the SM-2570.
LEGIC prime commandsThe following LEGIC prime commands are contained in every LEGIC advant SM for compat-
ibility reasons. For a description of these commands, see document [6].
ImportantThe LEGIC prime commands only function with LEGIC prime transponders (MIM).
The LEGIC prime commands must not be used for new developments!
Notes on LEGIC prime•   In the MODE byte of the commands SM_START and SM_START_TS the following set-
tings must be selected:
–   MUX bit = 1: The multiplex function is always active and is defined by connecting the
ACTION pin on the LEGIC advant SM.
–   SAF_DAT bit: No function. The Safe Data Handling function is defined in the
RFID_OPTIONS object of the IDB.
Command NameDescriptionCommand
## Code
## Details,
see
Information database (IDB)
SET_PARAMETERSets the parameters of an IDB object in the LEGIC advant SM0xB5page 69
GET_PARAMETERReads the parameters of an IDB object in the LEGIC advant SM0xB6page 71
DELETE_LAUNCH_DATADeletes a launch data record in the LEGIC advant SM0x54page 73
Superuser mode
SUPERUSER_MODESwitches the LEGIC advant into the "Superuser Mode" communication state0xBApage 57
START_SWDLStarts the software download for reader OS updates (only possible in the "Superuser mode")0xBDpage 74
DATA_SWDLWrites data during software download (only possible in the "Superuser mode")0xBEpage 77
Password protection of SM
SET_PASSWORDSets the password for the LEGIC advant SM, deletes all launch data records0x01page 78
Table 3: Set-up commands
Command NameDescriptionCommand
## Code
## Details,
see
Master data
ADD_MASTER_DATAReads the data of an authorization medium into LEGIC advant SM as a master data record 0xC3page 79
DELETE_MASTER_DATADeletes a master data record in the LEGIC advant SM.0xC4page 81
## Segments
ADD_SEGMENTInitializes an authorization or application segment on a TXP0xC5page 82
REMOVE_SEGMENTDeletes an authorization or application segment on a TXP0xC6page 88
Table 4: Initialization commands
Command NameDescriptionCommand
## Code
SM_STARTPeriodically searches the RF field for a LEGIC advant MIM, starts communication, reads data and
evaluates launch and launch-withdrawal media.
## 0x80
READ_MIMReads a number of data bytes from the LEGIC advant MIM.0x20
READ_MIM_CRCAs READ_MIM, additionally with CRC comparison.0x22
WRITE_MIMWrites a number of data bytes onto the LEGIC advant MIM.0x40
WRITE_MIM_CRCAs WRITE_MIM, additionally with writing of a CRC0x42
MAKE_MIM_CRCCalculates the CRC via a number of data bytes and writes these to the LEGIC advant MIM.0x44
READ_SM_IDReads a data block from the LEGIC advant SM (parts of the IDB)0x62
WRITE_SM_IDWrites a data block to the LEGIC advant SM (parts of the IDB)0x64
GEN_SET_READReads a launch data record from the LEGIC advant SM.0x52
WRITE_MIM_VALUE_DEFAULTSSets default parameters for handling value fields in the LEGIC advant SM.0x5E
READ_MIM_VALUE_DEFAULTSReads the default parameters for handling value fields from LEGIC advant SMs.0x5F
SET_BUS_PARAMETERSets bus parameters (LEGIC advant SM address and operating mode for bus operation)0x05
READ_BUS_PARAMETERReads the bus parameters.0x06
Table 5: LEGIC prime commands
## PRELIMINARY


LEGIC Identsystems Ltd
## CONFIDENTIAL
## 000-00

LEGIC advant 2000 Series
Reference Manual, Commands, SC-2560, SM-2570
8/92LA-33-110d-en© Transmission of contents to others prohibited05.2006
Technical specifications subject to change
–   P_HEAD = 1: The data access via the physical address is not possible with LEGIC
advant.
SM_START automatically activates the addressing mode PROTOCOL_HEADER
(see document [2]). This applies to all subsequent write and read commands
(READ_MIM, WRITE_MIM etc.).
–   The functions CRCALC and CRCHK can be used as with LEGIC prime.
The SM_START command first returns an answer when the segment searched has been
found. The SM_START answer 3 is eliminated.
-   From LEGIC OS version V1.3.9.0 application data in the ADF field of a LEGIC prime
authorization medium (GAM, SAM, IAM, XAM_1) can be read with the READ_MIM com-
mand. The reading of LEGIC advant media and the writing of data is not possible.
-   In the case of an error, the STATUS answer is returned instead of the GET_STATUS
answer. The format is identical, and the status and error messages have the same
meaning as for LEGIC prime (see document [6]).
-   The GEN_SET_READ command only returns the first 7 bytes of a launch data record
(according to LEGIC prime definition). With extended launch data, WEX is returned
instead of DATA_WEX.
-   The commands of the MSM-S software V4.x are not available with LEGIC advant. Here
the new LEGIC advant initialization commands must be used.
-   The commands WRITE_SM_ID and READ_SM_ID access parts of the information data-
base (IDB). The following changes must be taken into account in the process:
–   SM_ID Block 1: From the LEGIC advant SM serial number the bytes MCD_Low and
SER_NO 4 ... 2 are returned.
–   SM_ID Block 2: Not available, all bytes = 0xFF. The versions can be found in the
SYSTEM_INFO object.
–   SM_ID Block 3: Can only be read if the CMD_MODE parameter of the AUTO_READ_
OPTIONS object in the IDB is set to SM_START (otherwise all bytes = 0xFF).
–   SM_ID Block 4 to 7: These blocks are identical to the objects USER_DATA 1 to 4.
–   SM_ID Block 8: Not available.
This means with READ_SM_ID only the blocks 1 and 3 to 7 can be read.
With WRITE_SM_ID only the blocks 4 to 7 can be read.
-   The setting and reading out of parameters in the LEGIC advant SM (commands
READ_SM_ID and following) can also be carried out by the new set-up commands
SET_PARAMETER and GET_PARAMETER.
-   With LEGIC advant each command and each answer can also be completed with a CRC
(Cyclic Redundancy Check) instead of with an LRC (Longitudinal Redundancy Check).
This also applies to the LEGIC prime commands mentioned above. The CRC results in a
higher transfer security, however the command and the answer are 1 byte longer.
The check method (LRC/CRC) is defined with the connection of the MOD_FRM pin on
the LEGIC advant SM (see product description of the respective SM). For the calculation
of the CRC, see Table 9 in document [4].
With LRCWith CRC
...LRC...CRC_HighCRC_Low
## ......
## PRELIMINARY


LEGIC Identsystems Ltd
## CONFIDENTIAL
## 000-00

LEGIC advant 2000 Series
Reference Manual, Commands, SC-2560, SM-2570
05.2006© Transmission of contents to others prohibitedLA-33-110d-en9/92
Technical specifications subject to change
## 2.1SEARCH_TXP
The SEARCH_TXP command searches for all transponders located in the RF field and re-
turns their unique numbers (UID) (also see document [3], Manual Segment Selection).
Conditions•   The IDB object RFID_OPTIONS in the LEGIC advant SM defines the active RF stand-
ards and the anti-collision functions (see document [5]).
-   After SEARCH_TXP is carried out, the LEGIC advant SM is in the "Idle" state. With
SELECT_TXP one of the found TXPs can be selected.
SEARCH_TXP command
SEARCH_TXP answer
Important*   Compared to the SM_START command, the UID (bytes MSN...) of LEGIC prime MIM
(TXP_RFID_STD = 0x01) is returned in the opposite order.
STATUS answerWith a non-command-specific error (e.g. communication error when sending the command)
a STATUS answer is returned (see page 34 and “Status and Error Codes" on page 90).
# BYTECMDLRC/CRC_HighCRC_Low
[0x02 / 03][0xB0]
ByteDescriptionValue
# BYTENumber of following bytes (CMD ... LRC/CRC)0x02 / 0x03
CMDCommand code for SEARCH_TXP0xB0
## LRC/
CRC_High,
CRC_Low
Check character, (see document [4], Command Structure), in
accordance with MOD_FRM pin on LEGIC advant SM
LRC: 1 byte, CRC: 2 bytes
## TXP 0
# BYTECMDSTAT# TXPTXP_RFID_STD# UIDUID1 (MSB)...UIDn (LSB)
[0x04 ... 5D][0xB0][0x00][0x00 ... 08][0x10 ... 30][0x04 ... 0A][0x00 ... FF] [0x00 ... FF]
TXP_RFID_STD# UIDUID1 (MSB)...UIDn (LSB)... ...LRC/CRC_HighCRC_Low
[0x10 ... 30][0x04 ... 0A][0x00 ... FF] [0x00 ... FF]
## TXP 1TXP 2 ... 9
ByteDescriptionValue
# BYTENumber of following bytes (CMD ... LRC/CRC)0x04 ... 5D
CMDAnswer code for SEARCH_TXP0xB0
STATStatus (see document [4], Communication States)
0x00OK, command executed →  "Idle"
## 0x00
# TXPNumber of transponders found (max. 8)0x00 ... 08
TXP_RFID_STDRF standard of transponder
0x10LEGIC RF standard
0x20ISO 15693
0x21INSIDE Contactless (ISO 15693-basiert)
0x30ISO 14443 A
## 0x10 ... 30
# UIDNumber of bytes of UID (unique number)
4, 5, 7, 8 or 10 bytes
0x04 ... 0A
UID1 ... n *Data bytes of UID (unique number)
LRC/CRC_High,
CRC_Low
Check character, (see document [4], Command Struc-
ture), in accordance with MOD_FRM pin on LEGIC
advant SM
LRC: 1 byte, CRC: 2 bytes
## PRELIMINARY


LEGIC Identsystems Ltd
## CONFIDENTIAL
## 000-00

LEGIC advant 2000 Series
Reference Manual, Commands, SC-2560, SM-2570
10/92LA-33-110d-en© Transmission of contents to others prohibited05.2006
Technical specifications subject to change
## 2.2SELECT_TXP
The SELECT_TXP command selects a transponder located in the RF field and authenticates
it.
Conditions•   A list of all transponders located in the RF field is obtained with the SEARCH_TXP com-
mand.
-   After SELECT _TXP is carried out, the LEGIC advant SM is in the "TXP selected" state.
-   LEGIC SafeID: If the SELECT_TXP command has been executed successfully, the UID
of the selected TXP is save (authenticated).
-   If the addressed TXP is a launch medium, a launch procedure is carried out. The answer
is not returned until after 15 sec. A command sent in the meantime is followed by the
BUSY_LAUNCHING error message.
-   SELECT_TXP also checks whether the selected TXP has a LEGIC data structure.
RestrictionsIf several TXPs are in the RF field and the anticollision function is activated (IDB object
RFID_OPTIONS), it may happen that TXPs found with the SEARCH_TXP command cannot
be selected. This concerns third-party transponders which do not comply with all ISO stan-
dard layers, earlier LEGIC prime MIM versions (e.g. MIM256-PS) or TXPs in the border area
of the RF field.
SELECT_TXP command
SELECT_TXP answer
# BYTECMDTXP_RF_STDUID_LENUID1...UIDnLRC/CRC_HighCRC_Low
[0x08 ... 0F] [0xB1][0x10 ... 30][0x04 ... 0A][0x00 ... FF] [0x00 ... FF]
ByteDescriptionValue
# BYTENumber of following bytes (CMD ... LRC/CRC)0x08 / 0x0F
CMDCommand code for SELECT_TXP0xB1
TXP_RF_STDRF standard of selected transponder
0x10LEGIC RF standard
0x20ISO 15693
0x21Inside Contactless
0x30ISO 14443 A
## 0x10 ... 30
UID_LENNumber of bytes of UID (unique number)
4, 5, 7, 8 or 10 bytes
0x04 ... 0A
UID1 ... nData bytes of UID (unique number)
LRC/CRC_High,
CRC_Low
Check character, (see document [4], Command Struc-
ture), in accordance with MOD_FRM pin on LEGIC
advant SM
LRC: 1 byte, CRC: 2 bytes
# BYTECMDSTATFS_VERSIONEVENTSTATLRC/CRC_HighCRC_Low
[0x05 / 06][0xB1][0x00 ... 51][0x00 ... 20][0x00 ... 09]
ByteDescriptionValue
# BYTENumber of following bytes (CMD ... LRC/CRC)0x05 / 06
CMDAnswer code for SELECT_TXP0xB1
## PRELIMINARY


LEGIC Identsystems Ltd
## CONFIDENTIAL
## 000-00

LEGIC advant 2000 Series
Reference Manual, Commands, SC-2560, SM-2570
05.2006© Transmission of contents to others prohibitedLA-33-110d-en11/92
Technical specifications subject to change
STATUS answerWith a non-command-specific error (e.g. communication error when sending the command)
a STATUS answer is returned (see page 34 and “Status and Error Codes" on page 90).
STATStatus
0x00OK, transponder authenticated →  "TXP selected",
addressing mode "ADVANT"
0x01TXP without LEGIC data structure →  "Idle"
0x02TXP not found →  "Idle"
0x03Unknown RF standard, incorrect UID length or TXP
not supported →  "Idle"
0x50UNKNOWN_MEDIUM_SEG_TXPE
Unknown segment type →  "Idle"
0x51CORRUPT_MEDIUM
LEGIC data structure defective →  "Idle"
## 0x00 ... 51
FS_VERSIONVersion of LEGIC data structure
0x00LEGIC prime MIM, AM or IM
0x11LEGIC prime MIM, IM-S
0x20LEGIC advant ATC, AM or IM-S
## 0x00 ... 20
EVENTSTATEvent status
0x00   OK or no event
0x01   LAUNCH_MEMORY_FULL
Memory for launch data is already full
0x02   LAUNCH_DATA_ADDED
New launch data record saved
0x03   ADD_LAUNCH_DATA_ERROR
Launching cancelled, e.g. because timer expired
(15 s)
0x04   NO_IDENT_LAUNCH_DATA
No launch data record available
0x05   LAUNCH_DATA_DELETED
Launch data record deleted
0x06   DEL_LAUNCH_DATA_ERROR
Launching withdrawal cancelled, e.g. because timer
expired (15 s)
0x07   LAUNCH_DATA_IN_SM
Launch data record already saved
0x08   INVALID_LAUNCH_DATA
Launch data record invalid
0x09   LAUNCH_DATA_WITH_PARAMETER_ADDED
New launch data record with extended launch data
saved
## 0x00 ... 09
## LRC/
CRC_High,
CRC_Low
Check character, (see document [4], Command Structure),
in accordance with MOD_FRM pin on LEGIC advant SM
LRC: 1 byte, CRC: 2 bytes
ByteDescriptionValue
## PRELIMINARY


LEGIC Identsystems Ltd
## CONFIDENTIAL
## 000-00

LEGIC advant 2000 Series
Reference Manual, Commands, SC-2560, SM-2570
12/92LA-33-110d-en© Transmission of contents to others prohibited05.2006
Technical specifications subject to change
## 2.3SEARCH_SEGMENT
The SEARCH_SEGMENT command establishes the communication with the selected trans-
ponder (SELECT_TXP) and searches for the desired segment. In the process, the segment
number, search string or segment type can be specified.
Conditions•   The transponder must be authenticated with SELECT_TXP (state "TXP selected").
-   SEARCH_SEGMENT only operates in the ADVANT addressing mode.
-   SEARCH_SEGMENT returns the segment type, the segment number S_OL and S_FL
(with AM) following the successful establishment of communication.
-   After SEARCH_SEGMENT is executed, all TXP-related commands are permissible (e.g.
READ, WRITE), and the LEGIC advant SM is in the "Segment selected" state.
-   SEARCH_SEGMENT contains the following search option. As soon as a segment has
been found, TXP_INFO, FS_INFO and S_INFO (according to read protection) can be
read. Additional commands are possible in accordance with the segment type and pro-
tective functions (S_DATA_WRP, S_WRC, S_RD)
–   Segment number n, segment type = 0
The specified segment is selected if present, regardless of the segment type and pro-
tective functions.
–   Segment number n, segment type m, length of search string = 0
The first segment with the desired segment type with segment number  ≥ n is selected
if present.
–   Segment number n, segment type > 0, length of search string > 0
The first segment with the desired segment type with segment number  ≥ n and the
stamp data to match the search string is selected if present.
SEARCH_SEGMENT com-
mand
1) If S_TYPE = 0x00 (any) the segment specified under S_NUM will be selected.
# BYTECMDS_NUMS_TYPE#DATADATA 0 ... nLRC/CRC_HighCRC_Low
[0x05 ... 13][0xB2][0x01 ... 7F][0x00 ... 60][0x00 ... 0E][0x00 ... FF]
ByteDescriptionValue
# BYTENumber of following bytes (CMD ... LRC/CRC)0x05 ... 13
CMDCommand code for SEARCH_SEGMENT0xB2
S_NUMNumber of the desired segment or start segment for searching
with search string
0x01 ... 7F
S_TYPEType of desired segment
0x00Any desired segment type (only if S_STR_LEN = 0)
## 1)
0x01      GAM
0x02SAM
0x03IAM
0x04XAM_1
0x40Data segment
## 0x00 ... 60
#DATANumber of segment-specific data bytes (see following pages)  0x00 ... 0E
DATA 0 ... nSegment specific data for segment search (see next page)0x00 ... FF
## LRC/
CRC_High,
CRC_Low
Check character, (see document [4], Command Structure), in
accordance with MOD_FRM pin on LEGIC advant SM
LRC: 1 byte, CRC: 2 bytes
## PRELIMINARY


LEGIC Identsystems Ltd
## CONFIDENTIAL
## 000-00

LEGIC advant 2000 Series
Reference Manual, Commands, SC-2560, SM-2570
05.2006© Transmission of contents to others prohibitedLA-33-110d-en13/92
Technical specifications subject to change
Segment-specific data for stand-
ard segments
For the search for segment types 0x01 ... 40 (GAM, SAM, IAM, XAM_1, data segment)
DATA 0DATA 1DATA 2DATA 3...DATA n
## STAMP_LEN_
## PRIME
S_STR_LENS_STR 1S_STR 2...S_STR m
[0x00 ... 0C][0x00 ... 0C][0x00 ... FE] [0x00 ... FF] ...[0x00 ... FF]
ByteDescriptionValue
## STAMP_LEN_
## PRIME
Stamp length for access to data segments on LEGIC prime
MIM (IM und IM-S),
S_OL of segment is defined with stamp length
(is not interpreted with LEGIC advant ATC)
0x00 ... 0C
S_STR_LENLength of search string (max. 12 bytes)0x00 ... 0C
S_STR 1Search string: STAMP 1 (SSC)0x00 ... FE
S_STR 2 ... m    Search string: STAMP 2 ... m (m = max. 12)0x00 ... FF
## PRELIMINARY


LEGIC Identsystems Ltd
## CONFIDENTIAL
## 000-00

LEGIC advant 2000 Series
Reference Manual, Commands, SC-2560, SM-2570
14/92LA-33-110d-en© Transmission of contents to others prohibited05.2006
Technical specifications subject to change
SEARCH_SEGMENT answer
## # BYTECMDSTATS_NUMS_TYPES_FLS_OLRES
[0x08 / 09][0xB2][0x00 ... 70][0x00 ... 7F][0x00 ... FF][0x00 ... 40][0x00 ... 0C]0x00
LRC/CRC_HighCRC_Low
ByteDescriptionValue
# BYTENumber of following bytes (CMD ... LRC/CRC)0x09 / 0A
CMDAnswer code for SEARCH_SEGMENT0xB2
STATStatus
0x00OK, communication established with segment
→  "Segment selected"
0x01OK, no read authorization in accordance with Security
## Rules
(RD = 1, no suitable launch data in LEGIC advant SM,
no suitable master data in LEGIC advant SM,
SAM n/63 or SAM n/64) →  "Segment selected"
0x40COMMUNICATION_LOST
TXP no longer in RF field →  "Idle"
0x50UNKNOW_MEDUIM_S_TYPE
Unknown segment type →  "TXP selected"
0x51CORRUPT_MEDIUM
Segment linking defective →  "Idle"
0x52CORRUPT_SEGMENT
Search for segment number (segment type = 0 and
search string = 0) and segment defective →  "TXP se-
lected"
0x70SEG_NOT_FOUND
Segment not found, segment number too high →  "TXP
selected"
## 0x00 ... 70
S_NUMCurrent segment number
If STAT = 0x00 or 0x01
1 ... 127   Segment number
If STAT > 0x01
0no segment selected
0x00 ... 7F
S_TYPESegment type
If STAT = 0x00 or 0x01
0x00Deleted segment
0x01      GAM
0x02SAM
0x03IAM
0x04XAM_1
0x40Data segment
0xFFUnknown segment type on LEGIC prime MIM
If STAT ≥ 0x02: 0x00
0x00 ... FF
S_FLFunction Level
If STAT = 0x00
## GAM16
SAM1 ... 64(55 ... 62 blocked LEGIC)
IAM1 ... 48(40 ... 48 blocked LEGIC)
## XAM_10
Data segment0
If STAT ≥ 0x01: 0x00
## 0x01 ... 40
## PRELIMINARY


LEGIC Identsystems Ltd
## CONFIDENTIAL
## 000-00

LEGIC advant 2000 Series
Reference Manual, Commands, SC-2560, SM-2570
05.2006© Transmission of contents to others prohibitedLA-33-110d-en15/92
Technical specifications subject to change
- The stamp length STAMP_LEN_PRIME is defined in the SEARCH_SEGMENT command.
STATUS answerWith a non-command-specific error (e.g. communication error when sending the command)
a STATUS answer is returned (see page 34 and “Status and Error Codes" on page 90).
STATUS answer for comman-
do-specific errors
With this command the following command-specific error is returned in the STATUS answer.
S_OLOrganization Level
If STAT = 0x00
## GAM, SAM, IAM, XAM_1   1 ... 12
Data segment
LEGIC prime MIM1 ... 12 (in accordance with
## STAMP_LEN_PRIME) *
LEGIC advant ATC1 ... 12
If STAT ≥ 0x01: 0x00
0x00 ... 0C
RESReserved0x00
## LRC/
CRC_High,
CRC_Low
Check character, (see document [4], Command Structure), in
accordance with MOD_FRM pin on LEGIC advant SM
LRC: 1 byte, CRC: 2 bytes
ByteDescriptionValue
STATDescription
0x22INVALID_SYNTAX
Segment number < 1
## PRELIMINARY


LEGIC Identsystems Ltd
## CONFIDENTIAL
## 000-00

LEGIC advant 2000 Series
Reference Manual, Commands, SC-2560, SM-2570
16/92LA-33-110d-en© Transmission of contents to others prohibited05.2006
Technical specifications subject to change
## 2.4GET_TXP_INFO
The GET_TXP_INFO command reads the data areas TXP_INFO, FS_INFO or S_INFO of
the TXP or segment.
Conditions•   GET_TXP_INFO reads data areas TXP_INFO and FS_INFO as entire blocks. The
S_INFO area of the selected segment is only partially read if a read protection is set.
-   Before GET_TXP_INFO is executed, communication with the segment must be estab-
lished with SEARCH_SEGMENT ("Segment selected" state)
-   GET_TXP_INFO only operates in the ADVANT addressing mode.
-   The content of the individual areas is described in document [2], Transponder Data
## Structure.
GET_TXP_INFO command
GET_TXP_INFO answer
STATUS answerWith a non-command-specific error (e.g. communication error when sending the command)
a STATUS answer is returned (see page 34 and “Status and Error Codes" on page 90).
# BYTECMDINFO_TYPELRC/CRC_HighCRC_Low
[0x03 / 04][0x9A][0x01 ... 03]
ByteDescriptionValue
# BYTENumber of following bytes (CMD ... LRC/CRC)0x03 / 04
CMDCommand code for GET_TXP_INFO0x9A
INFO_TYPEArea to be read
0x01TXP_INFO, Transponder Info
0x02FS_INFO, File System Info
0x03S_INFO, Segment Info
## 0x01 ... 03
LRC/CRC_High,
CRC_Low
Check character, (see document [4], Command Struc-
ture), in accordance with MOD_FRM pin on LEGIC
advant SM
LRC: 1 byte, CRC: 2 bytes
# BYTECMDSTAT#DATADATA 0 ... nLRC/CRC_HighCRC_Low
[0x04 ... FF][0x9A][0x00 / 40][0x07 ... 1C][0x00 ... FF]
ByteDescriptionValue
# BYTENumber of following bytes (CMD ... LRC/CRC)0x04 ... FF
CMDAnswer code for GET_TXP_INFO0x9A
STATStatus
0x00OK
0x40COMMUNICATION_LOST
TXP no longer in RF field →  "Idle"
## 0x00 / 40
#DATANumber of data bytes read (see next page)0x07 ... 1C
DATA 0 ... nData bytes read (see next page)0x00 ... FF
LRC/CRC_High,
CRC_Low
Check character, (see document [4], Command Struc-
ture), in accordance with MOD_FRM pin on LEGIC
advant SM
LRC: 1 byte, CRC: 2 bytes
## PRELIMINARY


LEGIC Identsystems Ltd
## CONFIDENTIAL
## 000-00

LEGIC advant 2000 Series
Reference Manual, Commands, SC-2560, SM-2570
05.2006© Transmission of contents to others prohibitedLA-33-110d-en17/92
Technical specifications subject to change
STATUS answer for comman-
do-specific errors
With this command the following command-specific errors are returned in the STATUS an-
swer.
INFO_TYPE = 0x00
## (TXP_INFO)
The detailed description of the following fields can be found in document [2], chapter 5.5.
-   Compared to the SM_START command, the serial number of LEGIC prime MIM is returned in the op-
posite order.
INFO_TYPE = 0x01 (FS_INFO)
STATDescription
0x22INVALID_SYNTAX
Incorrect data area (INFO_TYPE)
0x23WRONG_COMMAND
No segment selected for S_INFO area
LEGIC advant ATCLEGIC prime MIM
## DATA
## Index
DescriptionDescription
0TXP_RFID_STDRF standard of transponder TXP_RFID_STDRF standard of transponder
1TXP_TYPEType of transponder chipTXP_TYPEType of transponder chip
2TXP_PAGE_SIZESize of a pageTXP_PAGE_SIZESize of a page (1 byte)
3UID_SIZELength of the unique number (number
of bytes)
UID_SIZELength of the unique number (4 bytes)
## 4
UID 0Unique number byte 0 (MSB)MCDManufacturer's code
## 5
UID 1Unique number byte 1MSN_High *Serial number
(Manufacturer's code + serial number = unique
number)
6UID 2Unique number byte 2MSN_Mid *
7UID 3Unique number byte 3MSN_Low *
## 8
UID 4Unique number byte 4MCCCheck sum across MCD and MSN
9UID 5Unique number byte 5RESReserved                                       (0x00)
10UID 6Unique number byte 6RESReserved                                       (0x00)
## 11
UID 7Unique number byte 7RESReserved                                       (0x00)
12UID 8Unique number byte 8RESReserved                                       (0x00)
13UID 9Unique number byte 9 (LSB)RESReserved                                       (0x00)
LEGIC advant ATCLEGIC prime MIM
## DATA
## Index
DescriptionDescription
0FS_ISSUER_High File system creatorRESReserved                                         (0x00)
1FS_ISSUER_LowMCDManufacturer's code
## 2
FS_VERSIONFile system versionFS_VERSIONFile system version(AM, IM oder IM-S)
3FS_PAGE_SIZEFile system page sizeFS_PAGE_SIZEPage size (1 byte)
4FS_USR_SIZE_HighUsable memory space for application
segments
FS_USR_SIZE_High    IM-S: Usable memory space for application segments
AM, IM: Memory size of MIM (MIM_SIZE)
## 5
FS_USR_SIZE_LowFS_USR_SIZE_Low
6FS_CRYPTData encryption typeFS_CRYPTData encryption type
7FS_DATE_HighFile system creation dateRESReserved                                         (0x00)
## 8
FS_DATE_LowRESReserved                                         (0x00)
9RESReservedRESReserved(0x00)
10RESReservedRESReserved(0x00)
## PRELIMINARY


LEGIC Identsystems Ltd
## CONFIDENTIAL
## 000-00

LEGIC advant 2000 Series
Reference Manual, Commands, SC-2560, SM-2570
18/92LA-33-110d-en© Transmission of contents to others prohibited05.2006
Technical specifications subject to change
INFO_TYPE = 0x03 (S_INFO)
S_INFOLEGIC advant ATC
## DATA
## Index
AccessDescription
## 0
Can always be read
S_LEN_HighTotal segment length (S_INFO + S_DATA) in multiples of 8 bytes
## (pages)
1S_LEN_Low
2S_ENGSegment engaged
3S_LASTLast segment
4S_TYPESegment type
5RESReserved (0x00)
6S_CRYPTEncryption in segment
## 7
Can only be read when no read protection or
read protection and authorization
S_OLEOrganization level enable
8S_FLFunction level
9S_DATA_LEN_HighLength of segment data (S_DATA) in bytes (effective length)
10S_DATA_LEN_Low
11S_DATA_WRP_HighLength of read-only area in segment data (S_DATA)
12S_DATA_WRP_Low
13S_WRCKey length for write/read protection of entire segment
14S_RDRead protection for entire segment
15S_OLOrganization level
16S_STAMP 1 (SSC)Stamp data,
variable, number of bytes in accordance with S_OL
## 17S_STAMP 2
## 18
## S_STAMP 3
## ::
## 27S_STAMP 12
S_INFOLEGIC prime MIM
## DATA
## Index
AccessDescription
## 0
Can always be read
S_LEN_HighIM-S: Effective segment length
AM, IM: Memory size of MIM (MIM_SIZE)
1S_LEN_Low
2S_ENGSegment engaged (AM, IM: 0x01, NM: 0x00)
## 3
S_LASTLast segment (NM, AM, IM: 0x01)
4S_TYPESegment type
5RESReserved                                           (0x00)
## 6
S_CRYPTEncryption(LEGIC encryption)
## 7
Can only be read when no read protection or
read protection and authorization
OLEOrganization level enable(IM, IM-S: 0x00)
8FLFunction level (IM, IM-S: 0x00)
## 9
S_DATA_LEN_HighLength of segment data (S_DATA) in bytes (effective length)
## (IM, AM: MIM_SIZE – S_OL – 8)
10S_DATA_LEN_Low
11S_DATA_WRP_HighLength of read-only area in segment data (S_DATA)
(AM: 0x00)
## 12
S_DATA_WRP_Low
13S_WRCKey length for write/read protection of entire segment
## (IM, AM: WRC)
## 14
S_RDRead protection for entire segment   (IM, AM: RD)
15S_OLOrganization level (stamp length) (IM, AM: OL)
16S_STAMP 1 (SSC)Stamp data,
variable, number of bytes in accordance with S_OL or OL
## 17
## S_STAMP 2
## 18S_STAMP 3
## ::
## 27S_STAMP 12
## PRELIMINARY


LEGIC Identsystems Ltd
## CONFIDENTIAL
## 000-00

LEGIC advant 2000 Series
Reference Manual, Commands, SC-2560, SM-2570
05.2006© Transmission of contents to others prohibitedLA-33-110d-en19/92
Technical specifications subject to change
Extended launch data in
S_INFO area
When reading out the S_INFO area of a SAM n/63 the extended launch data are shown as
follows.
Important*These values are necessary for accessing LEGIC advant ATCs
**   These values are not defined with SAM n/63 on LEGIC prime MIMs (0x00)
*** These values are necessary for accessing LEGIC prime MIMs (see document [2])
DATA_WEX = WEX – stamp length – 1
S_INFOLEGIC advant
## ATC
LEGIC prime
## MIM
IndexAccess    Field NameField NameDescription
Can only be read when no read protection or
read protection and authorization
16S_STAMP 1 (SSC)S_STAMP 1 (SSC)    Stamp data (number of bytes in accordance with S_OL)
## 17S_STAMP 2S_STAMP 2
## 18S_STAMP 3S_STAMP 3
## :::
## 27S_STAMP 12S_STAMP 12
15 + S_OL + 1WELWELLength of the data field with extended write access
15 + S_OL +2DATA_WEX_High *RES **Starting address of data field with extended write access (from DATA_BYTE 0)
15 + S_OL +3DATA_WEX_Low *RES **
15 + S_OL +4WEX_High ***WEX_HighStart address of data field with extended write access (from STAMP 1, for access-
ing LEGIC prime MIMs), WEX > 12
15 + S_OL +5WEX_Low ***WEX_Low
15 + S_OL +6WESWESShadow memory management
15 + S_OL +7WEMWEMMode for extended write access
Table 6: S_INFO data area with extended launch data
## PRELIMINARY


LEGIC Identsystems Ltd
## CONFIDENTIAL
## 000-00

LEGIC advant 2000 Series
Reference Manual, Commands, SC-2560, SM-2570
20/92LA-33-110d-en© Transmission of contents to others prohibited05.2006
Technical specifications subject to change
## 2.5READ
The READ command reads a number of data bytes from the S_DATA area of the segment.
Conditions•   READ reads a number of data bytes (# DATA) from the specified address in the S_DATA
area (ADR_High, ADR_Low). If the protective functions of the segment allow, the LEGIC
advant SM returns the requested data in the answer.
-   Before READ is executed, communication with the segment must be established with
SEARCH_SEGMENT ("Segment selected" state)
-   READ only operates in the ADVANT addressing mode.
-   If the data bytes to be read are to be checked with a CRC, the CRC type and address of
the CRC must be specified in the command.
-   The CRC bytes in the command (CRC_FLAGS_PRIME, CRC_ADR) must always be
specified, even if no CRC checking is required. In this case, the CRC bytes are not inter-
preted.
-   In the case of existing LEGIC prime MIM, the CRC-protected area can also contain
stamp data and/or protective functions. With the CRC_FLAGS field it can be specified
which areas are to be included in the CRC calculation. In this way existing LEGIC prime
MIMs with a "Kaba Group Header" structure can also be processed.
READ command
## # BYTECMDCRC_TYPECRC_FLAGS_
## PRIME
CRC_ADR_HighCRC_ADR_LowADR_HighADR_Low
[0x09 / 0A][0xC0][0x00 ... 02][0x00 ... 03][0x00 ... ][0x00 ... ]
#DATALRC/CRC_HighCRC_Low
## [0x00 ... C8]
ByteDescriptionValue
# BYTENumber of following bytes (CMD ... LRC/CRC)0x09 / 0A
CMDCommand code for READ0xC0
CRC_TYPECRC check
0x00No CRC check
0x01CRC check with 8 bits (1 byte)
0x02CRC check with 16 bits (2 bytes)
## 0x00 ... 02
## CRC_FLAGS_
## PRIME
Flag byte for CRC calculation LEGIC prime MIM
(For description, see next page)
–   LEGIC prime MIM: both flags are interpreted
–   LEGIC advant ATC: Flags are ignored!
## 0x00 ... 03
CRC_ADR_High,
CRC_ADR_Low
Address of CRC in S_DATA area0x00 ...
ADR_High,
ADR_Low
Address of the first data byte to be read in the S_DATA
area (if CRC_FLAGS_PRIME > 0, ADR = 0x00)
## 0x00 ...
#DATANumber of data bytes to be read (1 ... 200)0x01 ... C8
LRC/CRC_High,
CRC_Low
Check character, (see document [4], Command Struc-
ture), in accordance with MOD_FRM pin on LEGIC
advant SM
LRC: 1 byte, CRC: 2 bytes
## PRELIMINARY


LEGIC Identsystems Ltd
## CONFIDENTIAL
## 000-00

LEGIC advant 2000 Series
Reference Manual, Commands, SC-2560, SM-2570
05.2006© Transmission of contents to others prohibitedLA-33-110d-en21/92
Technical specifications subject to change
CRC_FLAGS_PRIMEThe two flags define the areas (stamp, protective functions) to be included in the CRC calcu-
lation (LEGIC prime MIM only).
These flags have to be set to 0x00 when reading LEGIC advant ATCs.
READ answer
STATUS answerWith a non-command-specific error (e.g. communication error when sending the command)
a STATUS answer is returned (see page 34 and “Status and Error Codes" on page 90).
STATUS answer for comman-
do-specific errors
With this command the following command-specific error is returned in the STATUS answer.
Bit 7Bit 6Bit 5Bit 4Bit 3Bit 2Bit 1Bit 0
## RESRESRESRESRESRESWRP/WRC/RDSTAMP
BitNameDescription
0STAMP1     All bytes of stamp of LEGIC prime MIM are also included in
the CRC calculation
0     CRC calculation without stamp data
## 1WRP/
## WRC/RC
1     The byte WRP/WRC/RD of the LEGIC prime MIM is also
included in the CRC calculation
0CRC calculation without byte WRP/WRC/RD
2 ... 7RESReserved
# BYTECMDSTAT#DATADATA 0 ... nLRC/CRC_HighCRC_Low
[0x04 ... CD][0xC0][0x00 ... 68][0x01 ... C8][0x00 ... FF]
ByteDescriptionValue
# BYTENumber of following bytes (CMD ... LRC/CRC)0x04 ... CD
CMDAnswer code for READ0xC0
STATStatus
0x00OK
0x01CRC check has failed
0x02Invalid address area for data or CRC
0x40COMMUNICATION_LOST
TXP no longer in RF field →  "Idle"
0x50UNKNOWN_MEDIUM_S_TYPE
Invalid segment
0x60ACCESS_DENIED
Read or write protection set
0x68WRONG_MEDIUM_S_TYPE
Deleted segment or incorrect segment type
## 0x00 ... 68
#DATANumber of data bytes read
If STAT = 0x00
0x01 ... C8    No. of bytes (1 ... 200)
If STAT ≥ 0x01
0x00No data read
## 0x01 ... C8
DATA 0 ... n   Read data bytes0x00 ... FF
## LRC/
CRC_High,
CRC_Low
Check character, (see document [4], Command Structure), in
accordance with MOD_FRM pin on LEGIC advant SM
LRC: 1 byte, CRC: 2 bytes
STATDescription
0x22INVALID_SYNTAX
Incorrect CRC_FLAGS_PRIME combination, too many data bytes, or
CRC_FLAGS_PRIME > 0 and ADR ≠ 0
## PRELIMINARY


LEGIC Identsystems Ltd
## CONFIDENTIAL
## 000-00

LEGIC advant 2000 Series
Reference Manual, Commands, SC-2560, SM-2570
22/92LA-33-110d-en© Transmission of contents to others prohibited05.2006
Technical specifications subject to change
## 2.6WRITE
The WRITE command writes a number of data bytes to the S_DATA area of the segment.
Conditions•   If the protective functions of the TXP permit, the data are written from the specified
address in the S_DATA area (ADR_High, ADR_Low).
-   Before WRITE is executed, communication with the segment must be established with
SEARCH_DATA ("Segment selected" state)
-   WRITE only operates in the ADVANT addressing mode.
-   If the data bytes to be written are to be checked with a CRC, the CRC type and address
of the CRC must be specified in the command.
-   The CRC address in the command must always be specified, even if no CRC calculation
is required. In this case, the CRC address is not interpreted.
WRITE command
WRITE answer
# BYTECMDCRC_TYPECRC_ADR_HighCRC_ADR_LowADR_HighADR_Low#DATA
[0x09 ... D1][0xC1][0x00 ... 02][0x00 ... ][0x00 ... ][0x00 ... C8]
DATA 1 ... nLRC/CRC_HighCRC_Low
[0x00 ... FF]
ByteDescriptionValue
# BYTENumber of following bytes (CMD ... LRC/CRC)0x09 ... D1
CMDCommand code for WRITE0xC1
CRC_TYPECRC calculation
0x00No CRC calculation
0x01CRC calculation with 8 bits (1 byte)
0x02CRC calculation with 16 bits (2 bytes)
## 0x00 ... 02
CRC_ADR_High,
CRC_ADR_Low
Address of CRC in S_DATA area0x00 ...
ADR_High,
ADR_Low
Address of the first data byte to be written in the
S_DATA area
#DATANumber of data bytes to be written (1 ... 200)0x01 ... C8
DATA 0 ... nData bytes to be written0x00 ... FF
LRC/CRC_High,
CRC_Low
Check character, (see document [4], Command Struc-
ture), in accordance with MOD_FRM pin on LEGIC
advant SM
LRC: 1 byte, CRC: 2 bytes
# BYTECMDSTATLRC/CRC_HighCRC_Low
[0x03 / 04][0xC1][0x00 ... 68]
ByteDescriptionValue
# BYTENumber of following bytes (CMD ... LRC/CRC)0x03 / 04
CMDAnswer code for WRITE0xC1
## PRELIMINARY


LEGIC Identsystems Ltd
## CONFIDENTIAL
## 000-00

LEGIC advant 2000 Series
Reference Manual, Commands, SC-2560, SM-2570
05.2006© Transmission of contents to others prohibitedLA-33-110d-en23/92
Technical specifications subject to change
STATUS answerWith a non-command-specific error (e.g. communication error when sending the command)
a STATUS answer is returned (see page 34 and “Status and Error Codes" on page 90).
STATUS answer for comman-
do-specific errors
With this command the following command-specific error is returned in the STATUS answer.
STATStatus
0x00OK
0x01Invalid address area for data or CRC
0x40COMMUNICATION_LOST
TXP no longer in RF field →  "Idle"
0x50UNKNOWN_MEDIUM_S_TYPE
Invalid segment
0x60ACCESS_DENIED
Write protection set
0x68WRONG_MEDIUM_S_TYPE
Deleted segment or incorrect segment type
## 0x00 ... 68
## LRC/
CRC_High,
CRC_Low
Check character, (see document [4], Command Structure),
in accordance with MOD_FRM pin on LEGIC advant SM
LRC: 1 byte, CRC: 2 bytes
ByteDescriptionValue
STATDescription
0x22INVALID_SYNTAX
Too many data bytes
## PRELIMINARY


LEGIC Identsystems Ltd
## CONFIDENTIAL
## 000-00

LEGIC advant 2000 Series
Reference Manual, Commands, SC-2560, SM-2570
24/92LA-33-110d-en© Transmission of contents to others prohibited05.2006
Technical specifications subject to change
## 2.7MAKE_CRC
The MAKE_CRC command calculates the CRC via a number of data bytes and writes it to
the specified address in the S_DATA area of the segment.
Conditions•   If the protective functions of the segment permit, MAKE_CRC reads out a number of data
bytes (# DATA) from the specified address (ADR_High, ADR_Low) in the S_DATA area.
After the data have been read, the LEGIC advant SM calculates the corresponding CRC.
If the protective functions of the segment permit, the LEGIC advant SM writes the CRC to
the specified address (CRCADR_High, CRCADR_Low) in the S_DATA area.
-   The CRC address may not lie within the data area to be read.
-   CRC type: The MAKE_CRC command can calculate 8-bit or 16-bit CRCs.
-   Before MAKE_CRC is executed, communication with the segment must be established
with SEARCH_SEGMENT ("Segment selected" state)
-   MAKE_CRC only operates in the ADVANT addressing mode.
-   In the case of existing LEGIC prime MIM, the CRC-protected area can also contain
stamp data and/or protective functions. With the CRC_FLAGS_PRIME field it can be
specified which areas are to be included in the CRC calculation.
NoteEnsure that the CRC will not be written to an address which has data which are still needed.
MAKE_CRC command
## # BYTECMDCRC_TYPECRC_FLAGS_
## PRIME
CRCADR_HighCRCADR_LowADR_HighADR_Low
[0x09 / 0A][0xC2][0x01 / 02][0x00 ... 03][0x00 ... ][0x00 ... ]
#DATALRC/CRC_HighCRC_Low
## [0x01 ... C8]
ByteDescriptionValue
# BYTENumber of following bytes (CMD ... LRC/CRC)0x09 / 0A
CMDCommand code for MAKE_CRC0xC2
CRC_TYPECRC calculation
0x01CRC calculation with 8 bits (1 byte)
0x02CRC calculation with 16 bits (2 bytes)
## 0x01 / 02
## CRC_FLAGS_
## PRIME
Flag byte for CRC calculation for LEGIC prime MIM
(For description, see next page)
–   LEGIC prime MIM: both flags are interpreted
–   LEGIC advant ATC: Flags are ignored!
## 0x00 ... 03
CRCADR_High,
CRCADR_Low
Address of CRC to be written in S_DATA area0x00 ...
ADR_High,
ADR_Low
Address of the first data byte to be read in the S_DATA
area (if CRC_FLAGS_PRIME > 0, ADR = 0x00)
## 0x00 ...
#DATANumber of data bytes to be read (1 ... 200)0x01 ... C8
## LRC/
CRC_High,
CRC_Low
Check character, (see document [4], Command Structure),
in accordance with MOD_FRM pin on LEGIC advant SM
–   LRC: 1 byte, CRC: 2 bytes
## PRELIMINARY


LEGIC Identsystems Ltd
## CONFIDENTIAL
## 000-00

LEGIC advant 2000 Series
Reference Manual, Commands, SC-2560, SM-2570
05.2006© Transmission of contents to others prohibitedLA-33-110d-en25/92
Technical specifications subject to change
CRC_FLAGS_PRIMELEGIC prime MIM: The two flags define the areas (stamp, protective functions) to be included
in the CRC calculation.
These flags have to be set to 0x00 when writing LEGIC advant ATCs.
MAKE_CRC answer
STATUS answerWith a non-command-specific error (e.g. communication error when sending the command)
a STATUS answer is returned (see page 34 and “Status and Error Codes" on page 90).
STATUS answer for comman-
do-specific errors
With this command the following command-specific error is returned in the STATUS answer.
Bit 7Bit 6Bit 5Bit 4Bit 3Bit 2Bit 1Bit 0
## RESRESRESRESRESRESWRP/WRC/RDSTAMP
BitNameDescription
0STAMP1     All bytes of stamp of LEGIC prime MIM are also included in
the CRC calculation
0     CRC calculation without stamp data
## 1WRP/
## WRC/RC
1     The byte WRP/WRC/RD of the LEGIC prime MIM is also
included in the CRC calculation
0CRC calculation without byte WRP/WRC/RD
2 ... 7RESReserved
# BYTECMDSTATLRC/CRC_HighCRC_Low
[0x03 / 04][0xC2][0x00 ... 68]
ByteDescriptionValue
# BYTENumber of following bytes (CMD ... LRC/CRC)0x03 / 04
CMDAnswer code for MAKE_CRC0xC2
STATStatus
0x00OK
0x01Invalid address area for data or CRC
0x40COMMUNICATION_LOST
TXP no longer in RF field →  "Idle"
0x50UNKNOWN_MEDIUM_S_TYPE
Invalid segment
0x60ACCESS_DENIED
Write protection set
0x68WRONG_MEDIUM_S_TYPE
Deleted segment or incorrect segment type
## 0x00 ... 68
## LRC/
CRC_High,
CRC_Low
Check character, (see document [4], Command Structure),
in accordance with MOD_FRM pin on LEGIC advant SM
LRC: 1 byte, CRC: 2 bytes
STATDescription
0x22INVALID_SYNTAX
Incorrect CRC_FLAGS_PRIME combination, too many data bytes, or
CRC_FLAGS_PRIME > 0 and ADR ≠ 0
## PRELIMINARY


LEGIC Identsystems Ltd
## CONFIDENTIAL
## 000-00

LEGIC advant 2000 Series
Reference Manual, Commands, SC-2560, SM-2570
26/92LA-33-110d-en© Transmission of contents to others prohibited05.2006
Technical specifications subject to change
## 2.8AUTO_READ
The AUTO_READ command activates the AUTO_READ mode. It searches periodically for
the specified data on all transponders located in the RF field and returns the data in the an-
swer. The search criteria and the data to be read is defined in the AUTO_READ_... objects
of the IDB (see document [5] and document [3], chapter "Automatic reading of data").
The AUTO_READ command contains basically the SEARCH_TXP, SELECT_TXP,
SEARCH_SEGMENT and READ commands.
Conditions•   The parameters for the execution of the AUTO_READ command are set in the following
IDB objects (see document [5]):
–   AUTO_READ_OPTIONS: Activation of command, query cycle, answer format, etc.
–   AUTO_READ_SEARCH_PATTERN: Authentication, search criteria, etc.
–   AUTO_READ_DATA_WINDOW: Data format, definition of data to be read
-   The AUTO_READ command can only be executed if the TRIGGER_MODE parameter in
the IDB object AUTO_READ_OPTIONS is set to 0 (single execution).
If the TRIGGER_MODE parameter is set to 1 (continous execution), the AUTO_READ
mode is started automatically after a power-up or after a reset. In the this mode, no com-
mands with TXP access can be sent, not even the AUTO_READ command. However, if
a TXP is found, the AUTO_READ answer is returned.
-   The IDB object RFID_OPTIONS defines the active RF standards and the anti-collision
functions (see document [5]).
-   AUTO_READ only operates in the ADVANT addressing mode (CMD_MODE in the IDB
object AUTO_READ_OPTIONS is not interpreted). Thus, it is not possible to execute
AUTO_READ with the SM_START command.
-   AUTO_READ cyclically searches the RF field for TXPs with the searched data (RF pulse,
4 ms). The query cycle is set in the IDB object AUTO_READ_OPTIONS. AUTO_READ is
a command with a wait state; an answer is first returned when a TXP with the specified
search criteria has been found in the RF field.
If several TXPs are in the RF field, a specific selection of a TXP is not possible.
-   With the MODE byte in the command the following options can be selected:
–   WAIT_NEXT_TXP: A TXP, which is already in the RF field when the command is sent,
is not read. The LEGIC advant SM waits until all TXP have left the RF field before it
searches for new TXPs. This prevents that a TXP, which remains in the RF field, is
read again with every sent command.
–   SINGLE_CYCLE: After sendig the command, only one single read attempt is made
(no periodic execution). An answer follows always, even if no TXP is in the RF field
during this attempt. With this option an answer can be forced, e.g. for test purposes.
-   Depending on the searched data the AUTO_READ command acts as follows:
*IDB object AUTO_READ_SEARCH_PATTERN: INDEX_ENABLE = 0x01 (without authentication)
**    IDB object AUTO_READ_SEARCH_PATTERN: INDEX_ENABLE = 0x02 (with authentication)
***   IDB object AUTO_READ_SEARCH_PATTERN: INDEX_ENABLE = 0x03 (with authentication and seg-
ment search)
## Searched
data
UseAnswer is returned
when ...
Communication state
after execution
No or UID *To check if any TXP
is in the RF field
... any TXP is in the
RF-field
"Idle"
## TXP_TYPE,
## UID **
To search for a
## LEGIC TXP
... a TXP with a LEGIC
data structure is in the
RF-field
"TXP selected"
S_DATA ***   To read the desired
data in the segment
... a TXP with the
searched segment is
in the RF-field
"Segment selected"
## PRELIMINARY


LEGIC Identsystems Ltd
## CONFIDENTIAL
## 000-00

LEGIC advant 2000 Series
Reference Manual, Commands, SC-2560, SM-2570
05.2006© Transmission of contents to others prohibitedLA-33-110d-en27/92
Technical specifications subject to change
-   If the INDEX_ENABLE parameter in the AUTO_READ_SEARCH_PATTERN object is et
to 0x02 or 0x03 (with authentication), a launch procedure is executed as soon as a a
launch medium (SAM n/63, SAM n/64) enters the RF field.
If segment data (S_DATA) is searched, no answer is returned after the launch procedure
because a launch medium does not contain a S_DATA aera.
If other TXP information is searched (e.g. TXP_TYPE, UID, S_STAMP), an answer is
returned after the launch procedure (after approx. 15 sec.). In the answer the status of
the launch procedure (EVENTSTAT) is returned.
-   Depending on the information searched, the LEGIC advant SM is in the "TXP selected"
or in the "Segment selected" state after the command execution (see table above). Addi-
tional TXP-based commands are now permitted (e.g READ, WRITE) (see document [4],
## Communication States)
Another segment can be directly addressed with SELECT_SEGMENT.
AUTO_READ command
# BYTECMDMODELRC/CRC_HighCRC_Low
## [0x03 / 04][0x79][0x00 ... 02]
ByteDescriptionValue
# BYTENumber of following bytes (CMD ... LRC/CRC)0x03 / 0x04
CMDCommand code for AUTO_READ0x79
MODEParameter for command execution0x00 ... 02
WAIT_NEXT_TXP: Wait for next TXP
0    When sending the command, TXPs already
present in the RF field are also read.
1    When sending the command, TXPs already
present in the RF field are not read. The LEGIC
advant SM waits until all TXPs have left the RF
field.
## 0 / 1
SINGLE_CYCLE: Single read attempt
0    Periodical search for desired data. An answer fol-
lows only after reading the data.
1    Single read attempt. An answer follows immedia-
tely, even if no data has been found.
If SINGLE_CYCLE = 1, WAIT_NEXT_TXP is not inter-
preted.
## 0 / 1
RES (Reserved)0
LRC/CRC_High,
CRC_Low
Check character, (see document [4], Command Struc-
ture), in accordance with MOD_FRM pin on LEGIC
advant SM
LRC: 1 byte, CRC: 2 bytes
MS BitLS Bit
Bit 7   Bit 6   Bit 5   Bit 4   Bit 3   Bit 2Bit 1Bit 0
## RESRESRESRESRESRESSINGLE_
## CYCLE
## WAIT_
## NEXT_TXP
## PRELIMINARY


LEGIC Identsystems Ltd
## CONFIDENTIAL
## 000-00

LEGIC advant 2000 Series
Reference Manual, Commands, SC-2560, SM-2570
28/92LA-33-110d-en© Transmission of contents to others prohibited05.2006
Technical specifications subject to change
AUTO_READ answerThe AUTO_READ answer contains the contents of all data windows in ascending order
(AUTO_READ_DATA_WINDOW [1] ...), which have been assigned to the found search cri-
teria (AUTO_READ_SEARCH_PATTERN).
In the AUTO_READ_OPTIONS object, CMD_OUTPUT parameter, it can be specified if the
bytes ALIGNMENT, SEARCH_PATTERN_INDEX and DATA_WIN_LEN_... are contained in
the AUTO_READ answer.
## # BYTECMDSTATEVENTSTATALIGNMENTSEARCH_PATTERN_
## INDEX
## #DATA
## [0x05 ... ][0x79][0x00 / 01][0x00 ... 09][0x00 ... ]
DATA_WIN_LEN_1DATA_1 0 to nDATA_WIN_LEN_2DATA_2 0 to m...LRC/CRC_HighCRC_Low
[0xn]                                                                 [0xm]                                                                 ...
## AUTO_READ_DATA_WINDOW [1]AUTO_READ_DATA_WINDOW [2]
## ...
ByteDescriptionValue
# BYTENumber of following bytes (CMD ... LRC/CRC)0x05 ...
CMDAnswer code for AUTO_READ0x79
STATStatus
0x00OK, data found
→   "Idle", "TXP selected" or "Segment selected",
see table on previous page.
A launch or launch withdrawal process can also
have been carried out, see EVENTSTAT
0x01Data not found (only possible if
## SINGLE_CYCLE = 1)
## 0x00 / 01
EVENTSTATEvent status
0x00   OK or no event
0x01   LAUNCH_MEMORY_FULL
Memory for launch data is already full
0x02   LAUNCH_DATA_ADDED
New launch data record saved
0x03   ADD_LAUNCH_DATA_ERROR
Launching cancelled, e.g. because timer expired
(15 s)
0x04   NO_IDENT_LAUNCH_DATA
No launch data record available
0x05   LAUNCH_DATA_DELETED
Launch data record deleted
0x06   DEL_LAUNCH_DATA_ERROR
Launching withdrawal cancelled, e.g. because
timer expired (15 s)
0x07   LAUNCH_DATA_IN_SM
Launch data record already saved
0x08   INVALID_LAUNCH_DATA
Launch data record invalid
0x09   LAUNCH_DATA_WITH_PARAMETER_ADDED
New launch data record with extended launch
data saved
## 0x00 ... 09
ALIGNMENTLength of searched data (DATA_WIN_LEN) in bits or
bytes
0x00DATA_WIN_LEN in bytes
0x01DATA_WIN_LEN in bits
(This byte is only contained if ADD_ALIGNMENT = 1,
AUTO_READ_OPTIONS object)
## 0x00 / 0x01
## PRELIMINARY


LEGIC Identsystems Ltd
## CONFIDENTIAL
## 000-00

LEGIC advant 2000 Series
Reference Manual, Commands, SC-2560, SM-2570
05.2006© Transmission of contents to others prohibitedLA-33-110d-en29/92
Technical specifications subject to change
STATUS answerWith a non-command-specific error (e.g. communication error when sending the command)
a STATUS answer is returned (see page 34 and “Status and Error Codes" on page 90).
AUTO_READ does not produce further error messages.
## SEARCH_
## PATTERN_INDEX
Contents of found search criteria, defined in the
AUTO_READ_SEARCH_PATTERN object
(This byte is only contained if ADD_SEARCH_
PATTERN_INDEX = 1, AUTO_READ_OPTIONS object)
0x00 ... 0A
# DATASize of complete, following data block in bytes
(AUTO_READ_DATA_WINDOW [1] ... [n])
## 0x00 ...
## DATA_WIN_
## LEN_1
Number of bits or bytes of first data window, dependig
on ALIGNMENT parameter
(This byte is only contained if ADD_DATA_WIN_
LEN = 1, AUTO_READ_OPTIONS object)
## 0x01 ...
DATA_1Contents of first data window AUTO_READ_DATA_
## WINDOW [1]
If the data is specified in bits, the first byte is filled up
with zeros (e.g. 111 11111111 →  0x07 FF)
## DATA_WIN_
## LEN_2
Number of bits or bytes of second data window,
dependig on ALIGNMENT parameter
## 0x01 ...
DATA_2Contents of second data window AUTO_READ_DATA_
## WINDOW [2]
...Further data windows, if specified
LRC/CRC_High,
CRC_Low
Check character, (see document [4], Command Struc-
ture), in accordance with MOD_FRM pin on LEGIC
advant SM
LRC: 1 byte, CRC: 2 bytes
ByteDescriptionValue
## PRELIMINARY


LEGIC Identsystems Ltd
## CONFIDENTIAL
## 000-00

LEGIC advant 2000 Series
Reference Manual, Commands, SC-2560, SM-2570
30/92LA-33-110d-en© Transmission of contents to others prohibited05.2006
Technical specifications subject to change
## 2.9IDLE
The IDLE command switches the LEGIC advant SM to the communication state "Idle" as well
as the RF carrier on or off. If communication to a TXP existed, it is terminated by the IDLE
command (see document [4], Communication States).
-   When the IDLE command is issued, any execution of the AUTO_READ command is first
aborted. Then the LEGIC advant SM is set to the state "Idle" and the RF carrier is
switched on or off.
-   The RF carrier can be set to the following states:
–   Constantly switched on (HF_ON), e.g. for test purposes
–   Switched off (HF_OFF)
IDLE command
IDLE answer
STATUS answerWith a non-command-specific error (e.g. communication error when sending the command)
a STATUS answer is returned (see page 34 and “Status and Error Codes" on page 90).
# BYTECMDPOFFLRC/CRC_HighCRC_Low
## [0x03 / 04][0x14][0x00 / 01]
ByteDescriptionValue
# BYTENumber of following bytes (CMD ... LRC/CRC)0x03 / 0x04
CMDCommand code for IDLE0x14
POFFState of the RF carrier after execution of the command
0x00Switched on constantly (RF_ON, Clean Carrier)
0x01Switched off (RF_OFF)
## 0x00 / 01
## LRC/
CRC_High,
CRC_Low
Check character, (see document [4], Command Structure), in
accordance with MOD_FRM pin on LEGIC advant SM
LRC: 1 byte, CRC: 2 bytes
# BYTECMDPOFFLRC/CRC_HighCRC_Low
## [0x03 / 04][0x14][0x00 / 01]
ByteDescriptionValue
# BYTENumber of following bytes (CMD ... LRC/CRC)0x03 / 0x04
CMDAnswer code for IDLE0x14
POFFState of the RF carrier after execution of the command
0x00Switched on constantly (RF_ON, Clean Carrier)
0x01Switched off (RF_OFF)
## 0x00 / 01
## LRC/
CRC_High,
CRC_Low
Check character, (see document [4], Command Structure), in
accordance with MOD_FRM pin on LEGIC advant SM
LRC: 1 byte, CRC: 2 bytes
## PRELIMINARY


LEGIC Identsystems Ltd
## CONFIDENTIAL
## 000-00

LEGIC advant 2000 Series
Reference Manual, Commands, SC-2560, SM-2570
05.2006© Transmission of contents to others prohibitedLA-33-110d-en31/92
Technical specifications subject to change
## 2.10    GET_STATUS
The command GET_STATUS queries the current system status.
Conditions•   GET_STATUS supplies the current system state and the information on whether a TXP
is in the RF field.
-   GET_STATUS can be issued at any time, even during a launch process (but not during
the execution of AUTO_READ).
-   During the execution of GET_STATUS the RF carrier is activated briefly if it was deacti-
vated.
-   The GET_STATUS answer is automatically triggered after the LEGIC advant SM is
switched on or after a reset. If the ACTION pin is set to Low when doing so, the RF car-
rier is not switched on.
Note on LEGIC primeThe GET_STATUS answer has the same format as the answer to READ_SM_STATUS. The
reserve bytes are used with GET_STATUS for LEGIC advant-specific status or error mes-
sages.
## GET_STATUS
## Command
GET_STATUS answer
# BYTECMDRESLRC/CRC_HighCRC_Low
## [0x03 / 04][0x30][0x00]
ByteDescriptionValue
# BYTENumber of following bytes (CMD ... LRC/CRC)0x03 / 04
CMDCommand code for GET_STATUS0x30
RESReserve0x00
## LRC/
CRC_High,
CRC_Low
Check character, (see document [4], Command Structure), in
accordance with MOD_FRM pin on LEGIC advant SM
–   LRC: 1 byte, CRC: 2 bytes
## # BYTECMDSTATSUB_STATCAUSING_CMDSWVSMSTATHF_POW
[0x09 / 0A][0x30][0x00 ... F2][0x00 ... FF] [0x30][0xFF][0x00 ... FF] [0x00 ... FF]
TXPSTATLRC/CRC_HighCRC_Low
[0x00 ... FF]
ByteDescriptionValue
# BYTENumber of following bytes (CMD ... LRC/CRC)0x09 / 0A
CMDAnswer code for GET_STATUS0x30
## PRELIMINARY


LEGIC Identsystems Ltd
## CONFIDENTIAL
## 000-00

LEGIC advant 2000 Series
Reference Manual, Commands, SC-2560, SM-2570
32/92LA-33-110d-en© Transmission of contents to others prohibited05.2006
Technical specifications subject to change
STATStatus code of LEGIC advant (both addressing modes),
see detailed description on page 90
## 0x00 ... F2
0x00OK
Command-specific status / error (0x01 ... 1F)
0x01Wait for TXP
0x02Launch / delete launch data
0x03Communication blocked
0x04Communication blocked, wait for TXP
System error, system messages (0xF0 ... 0xFF)
0xF0SYS_ANSWER FROM_RESET
Spontaneous answer after switching on LEGIC
advant SM or after reset
0xF1SYS_RECEIVE_ERROR
Communication, framing error
0xF2SYS_LOCKED
LEGIC advant SM is protected with password
SUB_STATReserve0x00 ... FF
CAUSING_CMDCommand code (GET_STATUS)0x30
SWVSoftware version (not in use, LEGIC advant = 0xFF)0xFF
SMSTATStatus code of LEGIC prime (for backward compatibility,
do not interprete with LEGIC advant), see document [6]
for a description of these status codes
0x00 ... FF
0x00SYS_OK
Command-specific status / error
0x11SYS_INIT_ACTIVE
0x14SM_BUSY
0xD3SM100_MUX_DISABLED
0xD4SM100_DISABLED_SYS_INIT_ACTIVE
System error, system messages
0xF0ANSWER_FROM_RESET
Spontaneous answer after switching on LEGIC
advant SM or after reset
0x13SYS_RECEIVE_ERROR
Communication, framing error
0x4BSM_LOCKED
LEGIC advant SM is protected with password
HF_POWTransmission power of the HF carrier
If STAT = 0x03, 04, F1, F2, F0 with ACTION = Low
0x00RF carrier off
If STAT = 0x00, 01, 02, F0
0x00RF carrier off
0x01 ... FFRF carrier on
(value depends on the antenna, medium and environ-
ment, can only be used for comparison measurements)
0x00 ... FF
TXPSTATStatus of TXP, see TXPSTAT on next page0x00 ... FF
LRC/CRC_High,
CRC_Low
Check character, (see document [4], Command Struc-
ture), in accordance with MOD_FRM pin on LEGIC
advant SM
–   LRC: 1 byte, CRC: 2 bytes
ByteDescriptionValue
## PRELIMINARY


LEGIC Identsystems Ltd
## CONFIDENTIAL
## 000-00

LEGIC advant 2000 Series
Reference Manual, Commands, SC-2560, SM-2570
05.2006© Transmission of contents to others prohibitedLA-33-110d-en33/92
Technical specifications subject to change
TXPSTATThe TXPSTAT field of the GET_STATUS answer signals the status of the TXP. The field is
interpreted bit-by-bit.
NoteIn the TXPSTAT field it can be seen whether at least one TXP is located in the RF field.
If all TXPs in the RF field and their UIDs are to be detected, the SEARCH_TXP command
must be used.
State table
Bit 7Bit 6Bit 5Bit 4Bit 3Bit 2Bit 1Bit 0
RESRESTXP_IN_FIELDNOMIMRESRESMIMVER_HighMIMVER_Low
BitNameDescription
0, 1MIMVERIf NOMIM = 0
Size of the MIM
00 = 22 bytes (MIM022)
10 = 256 bytes (MIM256)
11 = 1,024 bytes (MIM1024)
2, 3RESReserved (0)
4NOMIM1 =  No LEGIC prime MIM in RF field
0 =  LEGIC prime MIM in RF field, see MIMVER
5TXP_IN_FIELD    1 =  TXP in RF field
0 =  No TXP in RF field
6, 7RESReserved (0)
TXP_IN_FIELD   NOMIM   MIMVER_High   MIMVER_Low    TXP type in RF field
## 1000MIM022
## 1010MIM256
## 1011MIM1024
11xxTXP with ISO 15693, ISO
14443 A or INSIDE Con-
tactless
01xxNo TXP in RF field
Table 7: TXP status
## PRELIMINARY


LEGIC Identsystems Ltd
## CONFIDENTIAL
## 000-00

LEGIC advant 2000 Series
Reference Manual, Commands, SC-2560, SM-2570
34/92LA-33-110d-en© Transmission of contents to others prohibited05.2006
Technical specifications subject to change
## 2.11    STATUS
The STATUS answer is returned with command-specific or general errors (see "STATUS an-
swer" in the individual command descriptions).
Conditions•   The STATUS answer is identical to the answer to GET_STATUS, however the fields
HF_POW and TXP_STAT are not interpreted.
-   The CAUSING_CMD field contains the command code of the command that has trig-
gered the error. This enables STATUS answers to be assigned to the correct command.
-   The status codes which describe the errors are shown in the STAT and SMSTAT fields.
STAT contains the error code according to the LEGIC advant definition, SMSTAT the
error code according to the LEGIC prime definition.
-   The SMSTAT field is only to be evaluated via the addressing mode
## PROTOCOL_HEADER.
-   Following the STATUS answer the communication state can change, see "STATUS
answer" in the individual command descriptions.
STATUS answer
## # BYTECMDSTATSUB_STATCAUSING_CMDSWVSMSTATHF_POW
[0x09 / 0A][0x30][0x00 ... FF] [0x00 ... CF][0x01 ... FF] [0xFF][0x00 ... FF] [0x00]
TXPSTATLRC/CRC_HighCRC_Low
## [0x10]
ByteDescriptionValue
# BYTENumber of following bytes (CMD ... LRC/CRC)0x09 / 0A
CMDAnswer code for STATUS0x30
STATStatus code of LEGIC advant (both addressing modes)0x00 ... F8
0x00OK
Command-specific status / error (0x01 ... 1F),
see description of answer to command according to
## CAUSING_CMD
General error, (0x20 ... 7F),
see detailed description on page 90
0x20      INVALID_COMMAND
0x21      INVALID_COMMAND_LENGTH
0x22      INVALID_SYNTAX
0x23WRONG_COMMAND
0x24MUX_DISABLED
0x30      BUSY_WAITING_TXP
0x31      BUSY_LAUNCHING
0x40COMMUNICATION_LOST
0x50UNKNOWN_MEDIUM_S_TYPE
0x51CORRUPT_MEDIUM
0x52      CORRUPT_SEG
0x60ACCESS_DENIED
0x61      AUTHORIZATION_MISSING
0x68      WRONG_MEDIUM_S_TYPE
0x70      SEG_NOT_FOUND
0x71      SEG_SPACE_NOT_AVAILABLE
0xE0INTERFACE_SECURITY_ERROR
## PRELIMINARY


LEGIC Identsystems Ltd
## CONFIDENTIAL
## 000-00

LEGIC advant 2000 Series
Reference Manual, Commands, SC-2560, SM-2570
05.2006© Transmission of contents to others prohibitedLA-33-110d-en35/92
Technical specifications subject to change
- In case of a FATAL_ERROR please contact LEGIC Identsystems Ltd
System error, system messages (0xF0 ... 0xFF)
0xF0SYS_ANSWER_FROM_RESET
Message after start-up or reset
0xF1SYS_RECEIVE_ERROR
Communication, framing error
0xF2SYS_LOCKED
LEGIC advant SM is protected with password
0xF3SYS_GENERAL_ERROR
0xF8BOOTLOADER_ANSWER_FROM_RESET
Message from Bootloader: LEGIC OS is invalid
and can not be startet up
0xF9FATAL_ERROR *
Boot error (e.g. faulty EEPROM)
SUB_STAT0x00OK
0x01NO_VALID_EEPROM (only if STAT = 0xF8)
Message from Bootloader: no communication
with EEPROM
0x14Invalid hardware detection (STAT = 0xF9) *
0xC0 .. CFEEPROM error (STAT = 0xF9) *
0x00 ... CF
CAUSING_CMD0x01 ... FECommand code of command that has trig-
gered the error
0xFFCommand code could not be determined
0x01 ... FF
SWVSoftware version (not in use, LEGIC advant = 0xFF)0xFF
SMSTATStatus code of LEGIC prime (for backward compatibility,
do not interprete with LEGIC advant), see document [6]
for a description of these status codes
0x00 ... FF
HF_POWTransmission power of RF carrier, is not determined0x00
TXPSTATStatus of TXP, is not determined0x10
LRC/CRC_High,
CRC_Low
Check character, (see document [4], Command Struc-
ture), in accordance with MOD_FRM pin on LEGIC
advant SM
–   LRC: 1 byte, CRC: 2 bytes
ByteDescriptionValue
## PRELIMINARY


LEGIC Identsystems Ltd
## CONFIDENTIAL
## 000-00

LEGIC advant 2000 Series
Reference Manual, Commands, SC-2560, SM-2570
36/92LA-33-110d-en© Transmission of contents to others prohibited05.2006
Technical specifications subject to change
## 2.12    POWER_REDUCTION
The POWER_REDUCTION command reduces the transmission power of the LEGIC advant
## SM.
Conditions•   With POWER_REDUCTION the LEGIC advant SM adjusts the transmission power of the
RF carrier to the desired value: Full or reduced transmission power.
-   POWER_REDUCTION can be used with all LEGIC advant SMs. For the circuitry of the
Security Chip Set (SC-...), see the corresponding product information.
-   When the transmitting power is reduced, so is the range of the LEGIC advant SM.
-   There are no restrictions for communication between the LEGIC advant SM and the TXP.
In particular, the command POWER_REDUCTION does not influence either the commu-
nication state of the LEGIC advant SM nor does it prevent or impair – within the reduced
range – execution of any other commands.
-   The reduction of the transmission power is retained until it is reset again or until the
LEGIC advant SM is switched off.
-   Without POWER_REDUCTION the LEGIC advant SM always operates at full power.
-   POWER_REDUCTION can also be set in the RFID_OPTIONS object of the IDB.
-   The "Safe Data Handling" function is not possible with reduced transmission power, (see
document [5], RFID_OPTIONS object).
## POWER_REDUCTION
## Command
## POWER_REDUCTION
## Answer
STATUS answerWith a non-command-specific error (e.g. communication error when sending the command)
a STATUS answer is returned (see page 34 and “Status and Error Codes" on page 90).
# BYTECMDPOW_REDLRC/CRC_HighCRC_Low
## [0x03 / 04][0x12][0x00 / 0x01]
ByteDescriptionValue
# BYTENumber of following bytes (CMD ... LRC/CRC)0x03 / 0x04
CMDCommand code for POWER_REDUCTION0x12
POW_REDTransmission power of the RF carrier after execution of the
command
0x00Full transmission power
0x01Reduced transmission power (approx. 25 % of the full
power)
## 0x00 / 0x01
## LRC/
CRC_High,
CRC_Low
Check character, (see document [4], Command Structure), in
accordance with MOD_FRM pin on LEGIC advant SM
–   LRC: 1 byte, CRC: 2 bytes
# BYTECMDPOW_REDLRC/CRC_HighCRC_Low
## [0x03 / 04][0x12][0x00 / 0x01]
ByteDescriptionValue
# BYTENumber of following bytes (CMD ... LRC/CRC)0x03 / 0x04
CMDAnswer code for POWER_REDUCTION0x12
POW_REDTransmission power of the RF carrier after execution of the
command
0x00Full transmission power
0x01Reduced transmission power
## 0x00 / 0x01
## LRC/
CRC_High,
CRC_Low
Check character, (see document [4], Command Structure), in
accordance with MOD_FRM pin on LEGIC advant SM
–   LRC: 1 byte, CRC: 2 bytes
## PRELIMINARY


LEGIC Identsystems Ltd
## CONFIDENTIAL
## 000-00

LEGIC advant 2000 Series
Reference Manual, Commands, SC-2560, SM-2570
05.2006© Transmission of contents to others prohibitedLA-33-110d-en37/92
Technical specifications subject to change
## 2.13    GET_EVENT
The GET_EVENT command interrogates the signalling and wake-up events which occured
as well as possibly present data. GET_EVENT is mainly used with the extended power save
mode. After the wake-up of the LEGIC advant SM and the application from the power save
mode, the application can interrogate the wake-up reason and react accordingly.
-   The signalling and wake-up events must be defined in the IDB object WATCH_EVENT_
## MASK.
-   The signalling and wake-up events which occurred since the last GET_EVENT command
are saved and returned in the current GET_EVENT answer.
-   If the events ARA or OIF_ARA are activated in the IDB object WATCH_EVENT_MASK,
the GET_EVENT answer contains also the AUTO_READ answer. In the watch mode,
the LEGIC advant SM can not send any answers. Therefore the answer is saved and
returned with the GET_EVENT answer.
GET_EVENT command
GET_EVENT answer
# BYTECMDRESLRC/CRC_HighCRC_Low
## [0x03 / 04][0x34][0x00]
ByteDescriptionValue
# BYTENumber of following bytes (CMD ... LRC/CRC)0x03 / 0x04
CMDCommand code for GET_EVENT0x34
RESReserved0x00
## LRC/
CRC_High,
CRC_Low
Check character, (see document [4], Command Structure), in
accordance with MOD_FRM pin on LEGIC advant SM
–   LRC: 1 byte, CRC: 2 bytes
## # BYTECMDEVENT_MAIN_1RESALARMRESRES# EVENT_ANSW
[0x08 ... ][0x34][0x04 ... FC][0x00][0x00 ... FF][0x00][0x00][0x00 / 01]
# DATA_1ANSW_1 0 to nLRC/CRC_HighCRC_Low
## [0x04 ... ]
ByteDescriptionValue
# BYTENumber of following bytes (CMD ... LRC/CRC)0x08 ...
CMDAnswer code for GET_EVENT0x34
## EVENT_
## MAIN_1
Occurred events0x04 ... FC
AFR (Answer form reset):
1Signalling due to a reset
0No reset
## 0 / 1
## INPUT:
1Signalling due to a hardware pin (function definition in IDB
object SYSTEM_POWER_CONTROL)
0No signal on hardware pin
## 0 / 1
MS BitLS Bit
Bit 7Bit 6Bit 5Bit 4    Bit 3Bit 2Bit 1Bit 0
## AFRINPUTRTC_ALARMOIFARAOIF_ARARESRES
## PRELIMINARY


LEGIC Identsystems Ltd
## CONFIDENTIAL
## 000-00

LEGIC advant 2000 Series
Reference Manual, Commands, SC-2560, SM-2570
38/92LA-33-110d-en© Transmission of contents to others prohibited05.2006
Technical specifications subject to change
STATUS answerWith a non-command-specific error (e.g. communication error when sending the command)
a STATUS answer is returned (see page 34 and “Status and Error Codes" on page 90).
## RTC_ALARM:
1Signalling and wake-up due to an alarm (alarm no. see
ALARM byte)
0No alarm
## 0 / 1
OIF (object in field):
1Signalling and wake-up due to an object in the RF field
0No object in field
## 0 / 1
ARA (AUTO_READ answer):
1Signalling and wake-up due to reading of a transponder
with the AUTO_READ function (AUTO_READ answer see
ANSW_1 byte)
0No AUTO_READ answer
## 0 / 1
OIF_ARA (combination of OIF and ARA function):
1Signalling and wake-up due to an object in the RF field and
reading of a transponder with the AUTO_READ function
(AUTO_READ answer see ANSW_1 byte)
0No object in field and no AUTO_READ answer
## 0 / 1
RES (Reserved)0
RESReserved0x00
ALARMNumber of occurred alarm (only relevant if RTC_ALARM = 1))0x00 ... FF
## ALARM1 ... 8:
1Signalling and wake-up due to alarm 1 ... 8
0No alarm
## 0 / 1
RESReserved0x00
RESReserved0x00
## # EVENT_
## ANSW
AUTO_READ answer contained in GET_EVENT answer (last
AUTO_READ answer is saved only)
0x01AUTO_READ answer follows
0x00No AUTO_READ answer
## 0x00 / 01
# DATA_1Number of bytes of following AUTO_READ answer0x04 ...
## ANSW_1
0 to n
Data bytes of AUTO_READ answer (without LRC / CRC)
## LRC/
CRC_High,
CRC_Low
Check character, (see document [4], Command Structure), in
accordance with MOD_FRM pin on LEGIC advant SM
–   LRC: 1 byte, CRC: 2 bytes
ByteDescriptionValue
MS BitLS Bit
Bit 7Bit 6Bit 5Bit 4Bit 3Bit 2Bit 1Bit 0
## ALARM
## 8
## ALARM
## 7
## ALARM
## 6
## ALARM
## 5
## ALARM
## 4
## ALARM
## 3
## ALARM
## 2
## ALARM
## 1
## PRELIMINARY


LEGIC Identsystems Ltd
## CONFIDENTIAL
## 000-00

LEGIC advant 2000 Series
Reference Manual, Commands, SC-2560, SM-2570
05.2006© Transmission of contents to others prohibitedLA-33-110d-en39/92
Technical specifications subject to change
## 2.14    INIT_VALUE
The INIT_VALUE command is used for handling value fields (for a description of the value
field see document [3], Pre-Defined Application Segments).
It creates a value field in the S_DATA area with data memory, shadow memory and 16-bit
CRCs.
Conditions•   Before INIT_VALUE is executed, communication with the segment must be established
("Segment selected" communication state)
-   The value field has a length of 2 x number of bytes for user data + 4 bytes.
-   After the INIT_VALUE command has been completed, the value field is ready for the
High Level commands ("Value Handling" communication state, see document [4]).
INIT_VALUE command
INIT_VALUE answer
STATUS answerWith a non-command-specific error (e.g. communication error when sending the command)
a STATUS answer is returned (see page 34 and “Status and Error Codes" on page 90).
# BYTECMDADR_HighADR_LowV_LENVAL_...LRC/CRC_HighCRC_Low
[0x06 ... 0A][0x5D][0x01 ... 04]1 ... 4 bytes
ByteDescriptionValue
# BYTENumber of following bytes (CMD ... LRC/CRC)0x06 ... 0A
CMDCommand code for INIT_VALUE0x5D
ADR_High,
ADR_Low
Start address of value field (first byte of value field) in
S_DATA area
V_LENNumber of bytes for user data (1 ... 4)0x01 ... 04
VAL_...Start value for user data,
1 ... 4 bytes, MSB leading (big endian)
## 0x00000000 ...
## FFFFFFFF
## LRC/
CRC_High,
CRC_Low
Check character, (see document [4], Command Struc-
ture), in accordance with MOD_FRM pin on LEGIC
advant SM
–   LRC: 1 byte, CRC: 2 bytes
# BYTECMDVAL_COM_ANSWERVAL_...LRC/CRC_HighCRC_Low
[0x09 ... 0D][0x5D]6 bytes1 ... 4 bytes
ByteDescriptionValue
# BYTENumber of following bytes (CMD ... LRC/CRC)0x09 ... 0D
CMDAnswer code for INIT_VALUE0x5D
VAL_COM_ANSWER    Uniform answer block for handling value fields,
6 bytes, see page 47
VAL_...Current value, 1 ... 4 bytes, MSB leading (big
endian)
LRC/CRC_High,
CRC_Low
Check character, (see document [4], Command
Structure), in accordance with MOD_FRM pin on
LEGIC advant SM
–   LRC: 1 byte, CRC: 2 bytes
## PRELIMINARY


LEGIC Identsystems Ltd
## CONFIDENTIAL
## 000-00

LEGIC advant 2000 Series
Reference Manual, Commands, SC-2560, SM-2570
40/92LA-33-110d-en© Transmission of contents to others prohibited05.2006
Technical specifications subject to change
STATUS answer for comman-
do-specific errors
With this command the following command-specific errors are returned in the STATUS an-
swer.
STATDescription
0x01Invalid address range
0x22INVALID_SYNTAX
Field length too small or too large
0x60ACCESS_DENIED
Read or write protection set and no authorization
0x68WRONG_MEDIUM_S_TYPE
Deleted segment or incorrect segment type
## PRELIMINARY


LEGIC Identsystems Ltd
## CONFIDENTIAL
## 000-00

LEGIC advant 2000 Series
Reference Manual, Commands, SC-2560, SM-2570
05.2006© Transmission of contents to others prohibitedLA-33-110d-en41/92
Technical specifications subject to change
## 2.15    OPEN_VALUE
The OPEN_VALUE command is used for handling value fields (for a description of the value
field see document [3], Pre-Defined Application Segments).
It checks the state of the value field and carries out a field repair if necessary.
Conditions•   Before OPEN_VALUE is executed, communication with the segment must be estab-
lished ("Segment selected" communication state)
-   The OPEN_VALUE command sets the parameters for addressing and the field length for
the subsequent High Level commands.
-   With OPEN_VALUE the current value of the user data is also read.
-   After the OPEN_VALUE command has been completed, the value field is ready for the
High Level commands ("Value Handling" communication state, see document [4]).
## OPEN_VALUE
## Command
OPEN_VALUE answer
STATUS answerWith a non-command-specific error (e.g. communication error when sending the command)
a STATUS answer is returned (see page 34 and “Status and Error Codes" on page 90).
# BYTECMDADR_HighADR_LowV_LENLRC/CRC_HighCRC_Low
## [0x05 / 06][0x59][0x01 ... 04]
ByteDescriptionValue
# BYTENumber of following bytes (CMD ... LRC/CRC)0x05 / 06
CMDCommand code for OPEN_VALUE0x59
ADR_High,
ADR_Low
Start address of the value field
(first byte of the value field)
V_LENNumber of bytes for user data (1 ... 4)0x01 ... 04
## LRC/
CRC_High,
CRC_Low
Check character, (see document [4], Command Struc-
ture), in accordance with MOD_FRM pin on LEGIC
advant SM
–   LRC: 1 byte, CRC: 2 bytes
# BYTECMDVAL_COM_ANSWERVAL_...LRC/CRC_HighCRC_Low
[0x09 ... 0D][0x59]6 bytes1 ... 4 bytes
ByteDescriptionValue
# BYTENumber of following bytes (CMD ... LRC/CRC)0x09 ... 0D
CMDAnswer code for OPEN_VALUE0x59
VAL_COM_ANSWER    Uniform answer block for handling value fields,
6 bytes, see page 47
VAL_...Current value, 1 ... 4 bytes, MSB leading (big
endian)
LRC/CRC_High,
CRC_Low
Check character, (see document [4], Command
Structure), in accordance with MOD_FRM pin on
LEGIC advant SM
–   LRC: 1 byte, CRC: 2 bytes
## PRELIMINARY


LEGIC Identsystems Ltd
## CONFIDENTIAL
## 000-00

LEGIC advant 2000 Series
Reference Manual, Commands, SC-2560, SM-2570
42/92LA-33-110d-en© Transmission of contents to others prohibited05.2006
Technical specifications subject to change
STATUS answer for comman-
do-specific errors
With this command the following command-specific errors are returned in the STATUS an-
swer.
STATDescription
0x01Invalid address range
0x22INVALID_SYNTAX
Field length too small or too large
0x40COMMUNICATION_LOST
TXP no longer in RF field →  "Idle"
0x60ACCESS_DENIED
Read or write protection set and no authorization
0x68WRONG_MEDIUM_S_TYPE
Deleted segment or incorrect segment type
## PRELIMINARY


LEGIC Identsystems Ltd
## CONFIDENTIAL
## 000-00

LEGIC advant 2000 Series
Reference Manual, Commands, SC-2560, SM-2570
05.2006© Transmission of contents to others prohibitedLA-33-110d-en43/92
Technical specifications subject to change
## 2.16    WRITE_VALUE
The WRITE_VALUE command is used for handling value fields (for a description of the value
field see document [3], Pre-Defined Application Segments).
It overwrites the value (user data) in the value field.
Conditions•   WRITE_VALUE is a high-level commando.
-   Communication must be established with the segment and the OPEN_VALUE (or
INIT_VALUE) command must have been executed ("Value Handling" communication
state) before WRITE_VALUE is executed.
-   If OPEN_VALUE (or INIT_VALUE) has not been carried out before WRITE_VALUE, a
STATUS answer is returned with WRONG_COMMAND.
-   The number of bytes in VAL_... has to agree with the length of the user data in the value
field. Otherwise a STATUS answer is returned with INVALID_PARAMETER.
## WRITE_VALUE
## Command
WRITE_VALUE answer
STATUS answerWith a non-command-specific error (e.g. communication error when sending the command)
a STATUS answer is returned (see page 34 and “Status and Error Codes" on page 90).
STATUS answer for comman-
do-specific errors
With this command the following command-specific errors are returned in the STATUS an-
swer.
# BYTECMDVAL_...LRC/CRC_HighCRC_Low
[0x03 ... 07][0x5A]1 ... 4 bytes
ByteDescriptionValue
# BYTENumber of following bytes (CMD ... LRC/CRC)0x03 ... 07
CMDCommand code for WRITE_VALUE0x5A
VAL_...New value for user data,
1 ... 4 bytes, MSB leading (big endian)
## 0x00000000 ...
## FFFFFFFF
## LRC/
CRC_High,
CRC_Low
Check character, (see document [4], Command Structure),
in accordance with MOD_FRM pin on LEGIC advant SM
–   LRC: 1 byte, CRC: 2 bytes
# BYTECMDVAL_COM_ANSWERVAL_...LRC/CRC_HighCRC_Low
[0x09 ... 0D][0x5A]6 bytes1 ... 4 bytes
ByteDescriptionValue
# BYTENumber of following bytes (CMD ... LRC/CRC)0x09 ... 0D
CMDAnswer code for WRITE_VALUE0x5A
## VAL_COM
## _ANSWER
Uniform answer block for handling value fields, 6 bytes, see
page 47
VAL_...Current value, 1 ... 4 bytes, MSB leading (big endian)
## LRC/
CRC_High,
CRC_Low
Check character, (see document [4], Command Structure), in
accordance with MOD_FRM pin on LEGIC advant SM
–   LRC: 1 byte, CRC: 2 bytes
STATDescription
0x60ACCESS_DENIED
Read or write protection set
## PRELIMINARY


LEGIC Identsystems Ltd
## CONFIDENTIAL
## 000-00

LEGIC advant 2000 Series
Reference Manual, Commands, SC-2560, SM-2570
44/92LA-33-110d-en© Transmission of contents to others prohibited05.2006
Technical specifications subject to change
## 2.17    ADD_VALUE
The ADD_VALUE command is used for handling value fields (for a description of the value
field, see document [3], Pre-Defined Application Segments).
It adds the transferred value to the current value in the value field.
Conditions•   ADD_VALUE is a high-level commando.
-   Communication must be established with the segment and the OPEN_VALUE (or
INIT_VALUE) command must have been executed ("Value Handling" communication
state) before ADD_VALUE is executed.
-   If OPEN_VALUE (or INIT_VALUE) has not been carried out before ADD_VALUE, a STA-
TUS answer is returned with WRONG_COMMAND.
-   The number of bytes in VAL_... has to agree with the length of the user data in the value
field. Otherwise a STATUS answer is returned with INVALID_PARAMETER.
-   The sum of the transferred value and the existing value may not exceed the maximum
value (in accordance with the number of bytes).
## ADD_VALUE
## Command
ADD_VALUE answer
STATUS answerWith a non-command-specific error (e.g. communication error when sending the command)
a STATUS answer is returned (see page 34 and “Status and Error Codes" on page 90).
STATUS answer for comman-
do-specific errors
With this command the following command-specific errors are returned in the STATUS an-
swer.
# BYTECMDVAL_...LRC/CRC_HighCRC_Low
[0x03 ... 07][0x5B]1 ... 4 bytes
ByteDescriptionValue
# BYTENumber of following bytes (CMD ... LRC/CRC)0x03 ... 07
CMDCommand code for ADD_VALUE0x5B
VAL_...Value to be added,
1 ... 4 bytes, MSB leading (big endian)
## 0x00000000 ...
## FFFFFFFF
## LRC/
CRC_High,
CRC_Low
Check character, (see document [4], Command Structure),
in accordance with MOD_FRM pin on LEGIC advant SM
–   LRC: 1 byte, CRC: 2 bytes
# BYTECMDVAL_COM_ANSWERVAL_...LRC/CRC_HighCRC_Low
[0x09 ... 0D][0x5B]6 bytes1 ... 4 bytes
ByteDescriptionValue
# BYTENumber of following bytes (CMD ... LRC/CRC)0x09 ... 0D
CMDAnswer code for ADD_VALUE0x5B
## VAL_COM
## _ANSWER
Uniform answer block for handling value fields,
6 bytes, see page 47
VAL_...Current value, 1 ... 4 bytes, MSB leading (big endian)
## LRC/
CRC_High,
CRC_Low
Check character, (see document [4], Command Structure), in
accordance with MOD_FRM pin on LEGIC advant SM
–   LRC: 1 byte, CRC: 2 bytes
STATDescription
0x60ACCESS_DENIED
Read or write protection set
## PRELIMINARY


LEGIC Identsystems Ltd
## CONFIDENTIAL
## 000-00

LEGIC advant 2000 Series
Reference Manual, Commands, SC-2560, SM-2570
05.2006© Transmission of contents to others prohibitedLA-33-110d-en45/92
Technical specifications subject to change
## 2.18    SUB_VALUE
The SUB_VALUE command is used for handling value fields (for a description of the value
field see document [3], Pre-Defined Application Segments).
It subtracts the transferred value from the current value in the value field.
Conditions•   SUB_VALUE is a high-level commando.
-   Communication must be established with the segment and the OPEN_VALUE (or
INIT_VALUE) command must have been executed ("Value Handling" communication
state) before SUB_VALUE is executed.
-   If OPEN_VALUE (or INIT_VALUE) has not been carried out before SUB_VALUE, a STA-
TUS answer is returned with WRONG_COMMAND.
-   The number of bytes in VAL_... has to agree with the length of the user data in the value
field. Otherwise a STATUS answer is returned with INVALID_PARAMETER.
•The difference between the existing value and the transferred value must be ≥ 0.
## SUB_VALUE
## Command
SUB_VALUE answer
STATUS answerWith a non-command-specific error (e.g. communication error when sending the command)
a STATUS answer is returned (see page 34 and “Status and Error Codes" on page 90).
STATUS answer for comman-
do-specific errors
With this command the following command-specific errors are returned in the STATUS an-
swer.
# BYTECMDVAL_...LRC/CRC_HighCRC_Low
[0x03 ... 07][0x5C]1 ... 4 bytes
ByteDescriptionValue
# BYTENumber of following bytes (CMD ... LRC/CRC)0x03 ... 07
CMDCommand code for SUB_VALUE0x5C
VAL_...Value to be subtracted,
1 ... 4 bytes, MSB leading (big endian)
## 0x00000000 ...
## FFFFFFFF
## LRC/
CRC_High,
CRC_Low
Check character, (see document [4], Command Struc-
ture), in accordance with MOD_FRM pin on LEGIC
advant SM
–   LRC: 1 byte, CRC: 2 bytes
# BYTECMDVAL_COM_ANSWERVAL_...LRC/CRC_HighCRC_Low
[0x09 ... 0D][0x5C]6 bytes1 ... 4 bytes
ByteDescriptionValue
# BYTENumber of following bytes (CMD ... LRC/CRC)0x09 ... 0D
CMDAnswer code for SUB_VALUE0x5C
## VAL_COM
## _ANSWER
Uniform answer block for handling value fields, 6 bytes, see
page 47
VAL_...Current value, 1 ... 4 bytes, MSB leading (big endian)
## LRC/
CRC_High,
CRC_Low
Check character, (see document [4], Command Structure), in
accordance with MOD_FRM pin on LEGIC advant SM
–   LRC: 1 byte, CRC: 2 bytes
STATDescription
0x60ACCESS_DENIED
Read or write protection set
## PRELIMINARY


LEGIC Identsystems Ltd
## CONFIDENTIAL
## 000-00

LEGIC advant 2000 Series
Reference Manual, Commands, SC-2560, SM-2570
46/92LA-33-110d-en© Transmission of contents to others prohibited05.2006
Technical specifications subject to change
## 2.19    READ_VALUE
The READ_VALUE command is used for handling value fields (for a description of the value
field see document [3], Pre-Defined Application Segments).
READ_VALUE reads the current value of the value field. READ_VALUE is also used to
check whether the TXP is still in the RF field.
Conditions•   READ_VALUE is a high-level commando.
-   Communication must be established with the segment and the OPEN_VALUE (or
INIT_VALUE) command must have been executed ("Value Handling" communication
state) before READ_VALUE is executed.
-   If OPEN_VALUE (or INIT_VALUE) has not been carried out before READ_VALUE, a
STATUS answer is returned with WRONG_COMMAND.
-   The READ_VALUE command returns the state of the preceding action (OPEN_VALUE,
WRITE_VALUE, ADD_VALUE or SUB_VALUE). The data are not read again.
-   In order to ensure that the transponder is in the RF field during the execution of the com-
mand, READ_VALUE carries out a check reading of a byte.
If the transponder is no longer in the RF field, this is signalled by VAL_COM_ANSWER. If
the same transponder returns to the field, communication can be re-established (within
the limits defined by the default parameters).
## READ_VALUE
## Command
READ_VALUE answer
STATUS answerWith a non-command-specific error (e.g. communication error when sending the command)
a STATUS answer is returned (see page 34 and “Status and Error Codes" on page 90).
# BYTECMDLRC/CRC_HighCRC_Low
## [0x02 / 03][0x28]
ByteDescriptionValue
# BYTENumber of following bytes (CMD ... LRC/CRC)0x02 / 03
CMDCommand code for READ_VALUE0x28
## LRC/
CRC_High,
CRC_Low
Check character, (see document [4], Command Structure), in
accordance with MOD_FRM pin on LEGIC advant SM
–   LRC: 1 byte, CRC: 2 bytes
# BYTECMDVAL_COM_ANSWERVAL_...LRC/CRC_HighCRC_Low
[0x09 ... 0D][0x28]6 bytes1 ... 4 bytes
ByteDescriptionValue
# BYTENumber of following bytes (CMD ... LRC/CRC)0x09 ... 0D
CMDAnswer code for READ_VALUE0x28
## VAL_COM
## _ANSWER
Uniform answer block for handling value fields, 6 bytes, see
page 47
VAL_...Current value, 1 ... 4 bytes, MSB leading (big endian)
## LRC/
CRC_High,
CRC_Low
Check character, (see document [4], Command Structure), in
accordance with MOD_FRM pin on LEGIC advant SM
–   LRC: 1 byte, CRC: 2 bytes
## PRELIMINARY


LEGIC Identsystems Ltd
## CONFIDENTIAL
## 000-00

LEGIC advant 2000 Series
Reference Manual, Commands, SC-2560, SM-2570
05.2006© Transmission of contents to others prohibitedLA-33-110d-en47/92
Technical specifications subject to change
## 2.20    VAL_COM_ANSWER
The commands for handling value fields return an answer block for value fields
(VAL_COM_ANSWER) in their answer. This answer block provides very detailed information
on the course of the action. In case of aborting, the state of the value field can be determined
with high accuracy.
Answer block
Meaning of the fields in the an-
swer block
Degree of success of the
transaction (SUCC)
The SUCC parameter shows the degree of success of an action. The value increases with
increasing quality or increasing progress of the action.
The following table lists the possible values of SUCC as well as the action already executed
successfully at every value and the state of the VAL_... bytes.
-   The new data has possibly be written correctly if the abortion took place before checking the data (read after
write).
## SUCCFLAGREG 1FLAGREG 2FLAGREG 3FLAGREG 4HIGH_RES
[0x00 ... 5A][0x00 ... FF] [0x00 ... FF] [0x00 ... FF] [0x00 ... FF] [0x00 / 11]
ByteDescription
SUCCDegree of success of the action, see below
## FLAGREG 1
Flag register for displaying errors, see page 48
## FLAGREG 2
## FLAGREG 3
## FLAGREG 4
HIGH_RESDisplay of writing errors with high resolution, see page 49
## SUCC
## (hex)
## SUCC
## (dez.)
Action executedData in answer
## (VAL_...)
0x000VAL_SUCC_NO_ACTION
No action executed
old
0x2234VAL_SUCC_VALUE_WRITING_RUNNING
Aborted during writing of data memory
old *
0x3250VAL_SUCC_VALUE_WRITING_DONE
Mutation of the data memory completed error-free
new
0x3E62VAL_SUCC_SHADOW_WRITING_RUNNING
Aborted during writing of shadow memory
new
0x5080VAL_SUCC_SHADOW_WRITING_DONE
Mutation of the shadow memory completed error-
free
new
0x5A90VAL_SUCC_READ_OK
Commands OPEN_VALUE, READ_VALUE: Data
memory and shadow memory are consistent (CRC
OK) and contain the same values.
old (read only)
## PRELIMINARY


LEGIC Identsystems Ltd
## CONFIDENTIAL
## 000-00

LEGIC advant 2000 Series
Reference Manual, Commands, SC-2560, SM-2570
48/92LA-33-110d-en© Transmission of contents to others prohibited05.2006
Technical specifications subject to change
Flag register
## (FLAGREG 1 ... 4)
The flag register of the answer block shows whether and, if so, which errors occurred and
which operations were carried out.
The flag register consists of 4 bytes and is evaluated bit-by-bit.
Flag register 1 (FLAGREG 1)
Flag register 2 (FLAGREG 2)
Flag register 3 (FLAGREG 3)
Flag register 4 (FLAGREG 4)
Meaning of the fields in the flag
register
Bit 7Bit 6Bit 5Bit 4Bit 3Bit 2Bit 1Bit 0
## RESERVEBAL_
## OVER
## BAL_
## UNDER
## SHD_CRC_
## ERROR
## VAL_CRC_
## ERROR
## VALUE_
## ABORTED
## GENERAL_
## WARNING
## GENERAL_
## ERROR
Bit 7Bit 6Bit 5Bit 4Bit 3Bit 2Bit 1Bit 0
## RESERVEFALSE_
## MIM
## RESERVERESERVEVALUE_
## INIT
## SHADOW_
## REPAIRED
## VALUE_
## REPAIRED
## RESERVE
Bit 7Bit 6Bit 5Bit 4Bit 3Bit 2Bit 1Bit 0
## NO_
## VALID_
## TXP
## RESERVERESERVERESERVESHADOW_
## WRITE_
## FAIL
## VALUE_
## WRITE_
## FAIL
## RETRY_
## TIMEOUT
## MAX_
## RETRYS
Bit 7Bit 6Bit 5Bit 4Bit 3Bit 2Bit 1Bit 0
## RESERVERESERVERESERVERESERVERESERVERESERVERESERVERESERVE
DesignationFlag-Reg.
## / Bit
DescriptionCommunication
state after event
## Message
type
## GENERAL_
## ERROR
1 / 0Fatal error in connection with exe-
cuted command. All lines with E.
## GENERAL_
## WARNING
1 / 1Warning or remark in connection
with executed command. All lines
with W.
## VALUE_
## ABORTED
1 / 2Action aborted. Error could not be
eliminated.
Reason for aborting is displayed in a
further flag.
E"Idle"
## VAL_CRC_
## ERROR
1 / 3CRC error data memory, aborting of
the data memory repair.
If flag SHD_CRC_ERROR is also
set, data fields are destroyed.
E"Idle"
## SHD_CRC_
## ERROR
1 / 4CRC error shadow memory, aborting
of the shadow memory repair.
If flag VAL_CRC_ERROR is also
set, data fields are destroyed.
E"Idle"
BAL_UNDER1 / 5Attempt to devalue to < 0. Value too
low
E"Value
## Handl."
BAL_OVER1 / 6Attempt to revaluate to > maximum
value. Value too high
E"Value
## Handl."
RESERVE1 / 7Reserved
RESERVE2 / 0Reserved
## VALUE_
## REPAIRED
2 / 1Data memory repairedW"Value
## Handl."
## SHADOW_
## REPAIRED
2 / 2Shadow memory repaired
W"Value
## Handl."
VALUE_INIT2 / 3New value field created"Value
## Handl."
RESERVE2 / 4Reserved
RESERVE2 / 5Reserved
## PRELIMINARY


LEGIC Identsystems Ltd
## CONFIDENTIAL
## 000-00

LEGIC advant 2000 Series
Reference Manual, Commands, SC-2560, SM-2570
05.2006© Transmission of contents to others prohibitedLA-33-110d-en49/92
Technical specifications subject to change
Display of writing errors with
high resolution (HIGH-RES)
This parameter is contained to ensure the compatibility with the LEGIC prime commands.
The following values are possible:
FALSE_MIM2 / 6A second TXP has entered the field
while communication was being re-
established. Action aborted.
E"Idle"
RESERVE2 / 7Reserved
## MAX_
## RETRYS
3 / 0Permitted number of attempts for re-
establishing communication
exceeded. Action aborted.
Flag VALUE_WRITE_FAIL or
SHADOW_WRITE_FAIL is also set.
E"Idle"
## RETRY_
## TIMEOUT
3 / 1Timeout for re-establishing commu-
nication expired. Action aborted.
Flag VALUE_WRITE_FAIL or
SHADOW_WRITE_FAIL is also set.
E"Idle"
## VALUE_
## WRITE_FAIL
3 / 2Action aborted while writing the data
memory due to number of attempts
being exceeded or timeout expiring.
E"Idle"
## SHADOW_
## WRITE_FAIL
3 / 3Action aborted while writing the
shadow memory due to number of
attempts being exceeded or timeout
expiring.
E"Idle"
RESERVE3 / 4Reserved
RESERVE3 / 5Reserved
RESERVE3 / 6Reserved
## NO_VALID_
## TXP
3 / 7Only with READ_VALUE command,
communication still valid, but inter-
rupted. Communication can be re-
established, when same TXP is in
field again.
E"Value
## Handl."
RESERVE4 / 0 ... 7    Reserved
DesignationFlag-Reg.
## / Bit
DescriptionCommunication
state after event
## Message
type
HIGH_RESDescription
0x00Write procedure executed successfully
0x11Write error
## PRELIMINARY


LEGIC Identsystems Ltd
## CONFIDENTIAL
## 000-00

LEGIC advant 2000 Series
Reference Manual, Commands, SC-2560, SM-2570
50/92LA-33-110d-en© Transmission of contents to others prohibited05.2006
Technical specifications subject to change
## 2.21    GET_PORT
The GET_PORT command reads the states of the digital inputs and outputs
(IN 1 ... 4, OUT 1 ... 4) of the LEGIC advant SM.
Conditions•   The GET_PORT answer returns the current states which exist immediately after the
command has been executed.
GET_PORT command
GET_PORT answer
Answer byte PORT
STATUS answerWith a non-command-specific error (e.g. communication error when sending the command)
a STATUS answer is returned (see page 34 and “Status and Error Codes" on page 90).
# BYTECMDLRC/CRC_HighCRC_Low
## [0x02 / 03][0x72]
ByteDescriptionValue
# BYTENumber of following bytes (CMD ... LRC/CRC)0x02 / 03
CMDCommand code for GET_PORT0x72
## LRC/
CRC_High,
CRC_Low
Check character, (see document [4], Command Structure), in
accordance with MOD_FRM pin on LEGIC advant SM
LRC: 1 byte, CRC: 2 bytes
# BYTECMDPORTLRC/CRC_HighCRC_Low
[0x03 / 04][0x72][0x00 ... FF]
ByteDescriptionValue
# BYTENumber of following bytes (CMD ... LRC/CRC)0x03 / 04
CMDAnswer code for GET_PORT0x72
PORTCurrent states of the digital inputs and outputs (see "Answer
byte PORT" below)
0x00 ... FF
## LRC/
CRC_High,
CRC_Low
Check character, (see document [4], Command Structure), in
accordance with MOD_FRM pin on LEGIC advant SM
LRC: 1 byte, CRC: 2 bytes
Bit 7Bit 6Bit 5Bit 4Bit 3Bit 2Bit 1Bit 0
## OUT 4OUT 3OUT 2OUT 1IN 4IN 3IN 2IN 1
## [0 / 1][0 / 1][0 / 1][0 / 1][0 / 1][0 / 1][0 / 1][0 / 1]
## PRELIMINARY


LEGIC Identsystems Ltd
## CONFIDENTIAL
## 000-00

LEGIC advant 2000 Series
Reference Manual, Commands, SC-2560, SM-2570
05.2006© Transmission of contents to others prohibitedLA-33-110d-en51/92
Technical specifications subject to change
## 2.22    SET_PORT
The SET_PORT command sets the digital outputs (OUT 1 ... 4) of a LEGIC advant SM to the
desired state.
ConditionsThe following states are possible:
-   No change in the output signal
-   Square-wave signal (toggle)
-   Inverting of the existing output signal
-   Individual pulse, inversion relative to existing output signal
-   Set output to logical 0
-   Pulse with logical 0, then logical 1
-   Set output to logical 1
-   Pulse with logical 1, then logical 0
-   When the SET_PORT command is issued, all the outputs are set simultaneously. Run-
ning functions are aborted.
SET_PORT command
Command bytes
## OUTPAR 1 ... 4
# BYTECMDOUTPAR 4OUTPAR 3OUTPAR 2OUTPAR 1LRC/CRC_HighCRC_Low
[0x06 / 07][0x74][0x00 ... FF] [0x00 ... FF] [0x00 ... FF] [0x00 ... FF]
ByteDescriptionValue
# BYTENumber of following bytes (CMD ... LRC)0x06 / 07
CMDCommand code for SET_PORT0x74
## OUTPAR
## 1 ... 4
Parameter for the corresponding digital output
OUTPAR 1 →  Output OUT 1, etc.
(for settings see table below)
0x00 ... FF
## LRC/
CRC_High,
CRC_Low
Check character, (see document [4], Command Structure), in
accordance with MOD_FRM pin on LEGIC advant SM
LRC: 1 byte, CRC: 2 bytes
Byte OUTPAR 1 ... 4ValueFunction
Bit 7Bit 6Bit 5Bit 4Bit 3Bit 2Bit 1Bit 0
000000000x00No change in the output signal
00nnnnnn0x01 ... 3FSquare-wave signal (toggle)
t = n x 0.1 sf = 1/(2 x n x 0.1 s)
Function starts inverted in relation to the existing signal
010000000x40Inverted output signal: Existing output signal is inverted.
01nnnnnn0x41 ... 7FInverted single pulse:
Existing output signal is inverted for the
period t = n x 0.1 s.
100000000x80Output is set to logical 0
10nnnnnn0x81 ... BFPulse with logical 0, then logical 1:
The output is set to 0 for the period t = n x 0.1 s , then to 1
110000000xC0Output is set to logical 1
11nnnnnn0xC1 ... FFPulse with logical 1, then logical 0:
The output is set to 1 for the period t = n x 0.1 s , then to 0
## 1
t
## 0
t
## 1
t
## 0
t
## 1
## 0
t
## 1
## 0
t
## PRELIMINARY


LEGIC Identsystems Ltd
## CONFIDENTIAL
## 000-00

LEGIC advant 2000 Series
Reference Manual, Commands, SC-2560, SM-2570
52/92LA-33-110d-en© Transmission of contents to others prohibited05.2006
Technical specifications subject to change
Time factor nFor signals with a time factor n, bits 0 ... 5 determine the duration. With these 5 bits, values
from 1 ... 63 are possible. The resolution is 100 ms. Therefore, times from
t = 0.1 ... 6.3 s are possible.
SET_PORT answerThe answer for SET_PORT is identical to the GET_PORT answer. The states of all the digital
inputs and outputs (IN 1 ... 4, OUT 1 ... 4) are returned.
Answer byte PORT
STATUS answerWith a non-command-specific error (e.g. communication error when sending the command)
a STATUS answer is returned (see page 34 and “Status and Error Codes" on page 90).
# BYTECMDPORTLRC/CRC_HighCRC_Low
[0x03 / 04][0x74][0x00 ... FF]
ByteDescriptionValue
# BYTENumber of following bytes (CMD ... LRC/CRC)0x03 / 04
CMDAnswer code for SET_PORT0x74
PORTCurrent states of the digital inputs and outputs (see "Answer
byte PORT" below)
0x00 ... FF
## LRC/
CRC_High,
CRC_Low
Check character, (see document [4], Command Structure), in
accordance with MOD_FRM pin on LEGIC advant SM
LRC: 1 byte, CRC: 2 bytes
Bit 7Bit 6Bit 5Bit 4Bit 3Bit 2Bit 1Bit 0
## OUT 4OUT 3OUT 2OUT 1IN 4IN 3IN 2IN 1
## [0 / 1][0 / 1][0 / 1][0 / 1][0 / 1][0 / 1][0 / 1][0 / 1]
## PRELIMINARY


LEGIC Identsystems Ltd
## CONFIDENTIAL
## 000-00

LEGIC advant 2000 Series
Reference Manual, Commands, SC-2560, SM-2570
05.2006© Transmission of contents to others prohibitedLA-33-110d-en53/92
Technical specifications subject to change
## 2.23    UNLOCK
The UNLOCK command is used for the password protection of LEGIC advant SMs (for a de-
scription, see document [2]).
It enables a LEGIC advant SM with activated password protection.
Conditions•   A LEGIC advant SM with activated password protection expects the UNLOCK command
with the correct password following a power-up.
-   If an incorrect password is transferred with UNLOCK or a different command is transmit-
ted, the LEGIC advant SM returns a STATUS answer with STAT = 0xF2, SYS_LOCKED.
UNLOCK command
UNLOCK answer
STATUS answerWith a non-command-specific error (e.g. communication error when sending the command)
a STATUS answer is returned (see page 34 and “Status and Error Codes" on page 90).
STATUS answer for comman-
do-specific errors
With this command the following command-specific errors are returned in the STATUS an-
swer.
Notes•   After an incorrect password the LEGIC advant SM remains deactivated. Further com-
mands are followed by the STATUS answer SYS_LOCKED.
-   The LEGIC advant SM is blocked after three UNLOCK commands with incorrect pass-
word. Renewed powering up is required.
# BYTECMDPWD0PWD1PWD2PWD3LRC/CRC_HighCRC_Low
[0x06 / 07][0x02][0x00 ... FF] [0x00 ... FF] [0x00 ... FF] [0x00 ... FF]
ByteDescriptionValue
# BYTENumber of following bytes (CMD ... LRC/CRC)0x06 / 07
CMDCommand code for UNLOCK0x02
PWD0 ... 3Password: > 0x00 00 00 000x00 ... FF
## LRC/
CRC_High,
CRC_Low
Check character, (see document [4], Command Structure), in
accordance with MOD_FRM pin on LEGIC advant SM
LRC: 1 byte, CRC: 2 bytes
# BYTECMDPWD_STATLRC/CRC_HighCRC_Low
## [0x03 / 04][0x02][0x00 ... 02]
ByteDescriptionValue
# BYTENumber of following bytes (CMD ... LRC/CRC)0x03 / 04
CMDAnswer code for UNLOCK0x02
PWD_STAT   Password status:
0    Password is correct, LEGIC advant SM is enabled
1    No password protection is set, command does not have
any effect
2    LEGIC advant SM is already enabled.
## 0x00 ... 02
## LRC/
CRC_High,
CRC_Low
Check character, (see document [4], Command Structure), in
accordance with MOD_FRM pin on LEGIC advant SM
LRC: 1 byte, CRC: 2 bytes
STATDescription
0xF2SYS_LOCKEDWrong password
## PRELIMINARY


LEGIC Identsystems Ltd
## CONFIDENTIAL
## 000-00

LEGIC advant 2000 Series
Reference Manual, Commands, SC-2560, SM-2570
54/92LA-33-110d-en© Transmission of contents to others prohibited05.2006
Technical specifications subject to change
## 2.24    LOCK
The LOCK command is used for the password protection of LEGIC advant SMs (for a de-
scription, see document [2]).
It locks a LEGIC advant SM with activated password protection.
Conditions•   The LEGIC advant SM cannot be operated after a LOCK command, until an UNLOCK
command with a correct password has been issued. All other commands are followed by
the STATUS answer SYS_LOCKED.
LOCK command
LOCK answer
STATUS answerWith a non-command-specific error (e.g. communication error when sending the command)
a STATUS answer is returned (see page 34 and “Status and Error Codes" on page 90).
# BYTECMDLRC/CRC_HighCRC_Low
## [0x02 / 03][0x03]
ByteDescriptionValue
# BYTENumber of following bytes (CMD ... LRC/CRC)0x02 / 03
CMDCommand code for LOCK0x03
## LRC/
CRC_High,
CRC_Low
Check character, (see document [4], Command Structure), in
accordance with MOD_FRM pin on LEGIC advant SM
LRC: 1 byte, CRC: 2 bytes
# BYTECMDPWD_STATLRC/CRC_HighCRC_Low
## [0x03 / 04][0x03][0x00 / 01]
ByteDescriptionValue
# BYTENumber of following bytes (CMD ... LRC/CRC)0x03 / 04
CMDAnswer code for LOCK0x03
PWD_STAT   Password status:
0    Password protection activated, LEGIC advant SM is
locked
1    No password protection is set, command does not have
any effect
## 0x00 / 01
## LRC/
CRC_High,
CRC_Low
Check character, (see document [4], Command Structure), in
accordance with MOD_FRM pin on LEGIC advant SM
LRC: 1 byte, CRC: 2 bytes
## PRELIMINARY


LEGIC Identsystems Ltd
## CONFIDENTIAL
## 000-00

LEGIC advant 2000 Series
Reference Manual, Commands, SC-2560, SM-2570
05.2006© Transmission of contents to others prohibitedLA-33-110d-en55/92
Technical specifications subject to change
## 2.25    BUS_ENABLE
The BUS_ENABLE command is used for the bus operation of several LEGIC advant SMs
(multiplex operation via the serial-asynchronous interface, see document [4]).
The BUS_ENABLE command controls the bus communication during the bus operation of
several LEGIC advant SMs.
Conditions•   The LEGIC advant SM addressed through BUS_ENABLE is enabled. The other LEGIC
advant SMs at the same bus are in an inactive state.
-   The bus operation is deactivated with the bus address 0x00.
-   The BUS_ENABLE answer returns the status of the TXP when the TXP_CHECK charac-
ter is set accordingly in the command.
-   All inactive LEGIC advant SMs on the same bus remain in the current communication
state, but they don’t accept any commands except BUS_ENABLE.
-   Before bus operation is initiated the parameters in the INTERFACE_OPTIONS object of
the information database (IDB) must be set (bus address and polarity of the Driver-Ena-
ble signal). See document [5].
-   If the interface type is changed (e.g. to SPI), the bus address is deleted.
BUS_ENABLE command
NoteWith the TXP presence message (TXP_CHECK) it can be immediately determined whether
a TXP is located in the RF field without a SEARCH_TXP or AUTO_READ command having
to be issued.
If no TXPs are located in the RF field, then the next LEGIC advant SM can be addressed
immediately. If a TXP is located in the RF field, communication can be started with
SEARCH_TXP, SELECT_TXP etc. or AUTO_READ.
# BYTECMDSM_ADRTXP_CHECKLRC/CRC_HighCRC_Low
[0x04 / 05][0x04][0x00 ... FF] [0x00 / 01]
ByteDescriptionValue
# BYTENumber of following bytes (CMD ... LRC/CRC)0x04 / 05
CMDCommand code for BUS_ENABLE0x04
SM_ADRBus address
0x00Bus operation not activated
0x01 ... FFBus address of the LEGIC advant SM to be
enabled
0x00 ... FF
TXP_CHECKTXP presence message in BUS_ENABLE answer
0x00 Without TXP presence message
0x01With TXP presence message
## 0x00 / 01
## LRC/
CRC_High,
CRC_Low
Check character, (see document [4], Command Structure),
in accordance with MOD_FRM pin on LEGIC advant SM
LRC: 1 byte, CRC: 2 bytes
## PRELIMINARY


LEGIC Identsystems Ltd
## CONFIDENTIAL
## 000-00

LEGIC advant 2000 Series
Reference Manual, Commands, SC-2560, SM-2570
56/92LA-33-110d-en© Transmission of contents to others prohibited05.2006
Technical specifications subject to change
BUS_ENABLE answer
STAT byte
State table
STATUS answerWith a non-command-specific error (e.g. communication error when sending the command)
a STATUS answer is returned (see page 34 and “Status and Error Codes" on page 90).
# BYTECMDSM_ADRSTATLRC/CRC_HighCRC_Low
[0x04 / 05][0x04][0x00 ... FF] [0x00 ... 10]
ByteDescriptionValue
# BYTENumber of following bytes (CMD ... LRC/CRC)0x04 / 05
CMDAnswer code for BUS_ENABLE0x04
SM_ADRAcknowledgement of own bus address0x00 ... FF
STATError and current TXP status (see below)0x00 ... 10
## LRC/
CRC_High,
CRC_Low
Check character, (see document [4], Command Structure), in
accordance with MOD_FRM pin on LEGIC advant SM
LRC: 1 byte, CRC: 2 bytes
Bit 7Bit 6Bit 5Bit 4Bit 3Bit 2Bit 1Bit 0
RESRESTXP_IN_FIELDERR_STATRESMIM_S_HighMIM_S_MidMIM_S_Low
BitNameDescription
0 ... 2MIM_SLEGIC prime MIM in RF field
000 = No MIM in RF field
## 001 = MIM022
## 011 = MIM256
## 100 = MIM1024
3RESReserved
4ERR_STAT0 =  No error, OK →  "SM enabled"
1 =  No bus address set (address = 0), bus operation of LEGIC
advant SM not activated
5TXP_IN_FIELD    1 =  TXP in RF field
0 =  No TXP in RF field
6, 7RESReserved
TXP_IN_FIELD   MIM_S_High  MIM_S_MidMIM_S_Low   TXP type in RF field
0000No TXP in RF field or
## ERR_STAT = 1
1000LEGIC advant ATC in RF
field
1001MIM022 in RF field
1011MIM256 in RF field
1100MIM1024 in RF field
## PRELIMINARY


LEGIC Identsystems Ltd
## CONFIDENTIAL
## 000-00

LEGIC advant 2000 Series
Reference Manual, Commands, SC-2560, SM-2570
05.2006© Transmission of contents to others prohibitedLA-33-110d-en57/92
Technical specifications subject to change
## 2.26    SUPERUSER_MODE
The SUPERUSER_MODE command sets the LEGIC advant SM to the "Superuser Mode"
communication state (see document [4], Communication States).
Conditions•   The RESET, POWER_SAVE, STOP, START_SWDL and DATA_SWDL commands can
only be executed in the Superuser mode.
-   Any other command cancels the Superuser mode.
SUPERUSER_MODE com-
mand
SUPERUSER_MODE answer
STATUS answerWith a non-command-specific error (e.g. communication error when sending the command)
a STATUS answer is returned (see page 34 and “Status and Error Codes" on page 90).
# BYTECMDLRC/CRC_HighCRC_Low
[0x02 / 03][0xBA]
ByteDescriptionValue
# BYTENumber of following bytes (CMD ... LRC/CRC)0x02 / 0x03
CMDCommand code for SUPERUSER_MODE0xBA
## LRC/
CRC_High,
CRC_Low
Check character, (see document [4], Command Structure), in
accordance with MOD_FRM pin on LEGIC advant SM
LRC: 1 byte, CRC: 2 bytes
# BYTECMDSTATLRC/CRC_HighCRC_Low
[0x03 / 04][0xBA]0x00
ByteDescriptionValue
# BYTENumber of following bytes (CMD ... LRC/CRC)0x03 / 0x04
CMDAnswer code for SUPERUSER_MODE0xBA
STATStatus
0x00OK, LEGIC advant SM in Superuser mode
## 0x00
## LRC/
CRC_High,
CRC_Low
Check character, (see document [4], Command Structure), in
accordance with MOD_FRM pin on LEGIC advant SM
LRC: 1 byte, CRC: 2 bytes
## PRELIMINARY


LEGIC Identsystems Ltd
## CONFIDENTIAL
## 000-00

LEGIC advant 2000 Series
Reference Manual, Commands, SC-2560, SM-2570
58/92LA-33-110d-en© Transmission of contents to others prohibited05.2006
Technical specifications subject to change
## 2.27    RESET
The RESET command resets the LEGIC advant SM. It has the same effects as switching the
LEGIC advant SM on and off or a reset on the /RESET pin. Following a reset the LEGIC ad-
vant SM is in the "Idle" communication state (see document [4], Communication States).
Conditions•   When the RESET command is issued, any execution of the AUTO_READ command or a
launch process is immediately aborted.
-   RESET can only be issued in the Superuser mode, see page 57.
RESET command
RESET answerThe answer to RESET is identical to the GET_STATUS answer (see “GET_STATUS" on
page 31). The following status codes are possible:
# BYTECMDLRC/CRC_HighCRC_Low
[0x02 / 03][0xB7]
ByteDescriptionValue
# BYTENumber of following bytes (CMD ... LRC/CRC)0x02 / 0x03
CMDCommand code for RESET0xB7
## LRC/
CRC_High,
CRC_Low
Check character, (see document [4], Command Structure), in
accordance with MOD_FRM pin on LEGIC advant SM
LRC: 1 byte, CRC: 2 bytes
STATDescription
0x23WRONG_COMMAND
LEGIC advant SM is not in the "Superuser mode" communication state
0xF0SYS_ANSWER_FROM_RESET
Reset executed →  "Idle"
## PRELIMINARY


LEGIC Identsystems Ltd
## CONFIDENTIAL
## 000-00

LEGIC advant 2000 Series
Reference Manual, Commands, SC-2560, SM-2570
05.2006© Transmission of contents to others prohibitedLA-33-110d-en59/92
Technical specifications subject to change
## 2.28    POWER_SAVE
The POWER_SAVE command activates the power saving mode of the LEGIC advant SM
(reduced power consumption, for values see product despription of corresponding LEGIC
advant SM).
With the LEGIC advant SM an extended power save mode (stop/watch) is available. The be-
haviour in the power save mode is defined by the following IDB objects (see document [5]).
These objects must be set before the execution of the POWER_SAVE command.
## –   SYSTEM_POWER_CONTROL:
Behaviour of hardware pins for activating and deactivating of power save mode; state in
the power save mode (stop or watch mode)
## –   WATCH_EVENT_MASK:
Definition of signalling and wake-up events for wake-up from stop or watch mode.
## –   WATCH_EVENT_OPTIONS:
Various watch mode parameters
–   RTC_DATA_TIME (optional):
Time setting for alarm function in watch mode
–   RTC_ALARM (optional):
Alarm definition for watch mode
–   AUTO_READ... (optional):
Definition of AUTO_READ function in watch mode
Conditions•   Before a POWER_SAVE command is issued, any execution of the AUTO_READ com-
mand has to be stopped with IDLE.
-   POWER_SAVE can only be issued in the Superuser mode, see page 57.
-   After execution of the POWER_SAVE command the LEGIC advant SM is in the “Power
Save” communication state (see document [4]), Communication states). The conditions
for wake-up from this state are defined in the IDB objects mentioned above.
POWER_SAVE command
POWER_SAVE anwser
STATUS answerWith a non-command-specific error (e.g. communication error when sending the command)
a STATUS answer is returned (see page 34 and “Status and Error Codes" on page 90).
# BYTECMDRESLRC/CRC_HighCRC_Low
[0x03 / 04][0xBF]0x00
ByteDescriptionValue
# BYTENumber of following bytes (CMD ... LRC/CRC)0x03 / 0x04
CMDCommand code for POWER_SAVE0xBF
RESReserved0x00
## LRC/
CRC_High,
CRC_Low
Check character, (see document [4], Command Structure), in
accordance with MOD_FRM pin on LEGIC advant SM
LRC: 1 byte, CRC: 2 bytes
# BYTECMDSTATLRC/CRC_HighCRC_Low
[0x03 / 04][0xBF]0x00
ByteDescriptionValue
# BYTENumber of following bytes (CMD ... LRC/CRC)0x03 / 0x04
CMDAnswer code for POWER_SAVE0xBF
STATStatus
0x00OK, LEGIC advant SM in power saving mode
## 0x00
## LRC/
CRC_High,
CRC_Low
Check character, (see document [4], Command Structure), in
accordance with MOD_FRM pin on LEGIC advant SM
LRC: 1 byte, CRC: 2 bytes
## PRELIMINARY


LEGIC Identsystems Ltd
## CONFIDENTIAL
## 000-00

LEGIC advant 2000 Series
Reference Manual, Commands, SC-2560, SM-2570
60/92LA-33-110d-en© Transmission of contents to others prohibited05.2006
Technical specifications subject to change
## 2.29    AUTH_A
The AUTH_A command is used to establish secure communication via the application inter-
face (LEGIC advant SM – Host Computer). The AUTH_A command carries out the first step
of the authentication.
See document [4] for a description of secure communication.
Conditions•   The AUTH_A command must be followed by the AUTH_B command.
AUTH_A command
AUTH_A answer
STATUS answerWith a non-command-specific error (e.g. communication error when sending the command)
a STATUS answer is returned (see page 34 and “Status and Error Codes" on page 90).
# BYTECMDLRC/CRC_HighCRC_Low
[0x02 / 03][0xD0]
ByteDescriptionValue
# BYTENumber of following bytes (CMD ... LRC/CRC)0x02 / 0x03
CMDCommand code for AUTH_A0xD0
## LRC/
CRC_High,
CRC_Low
Check character, (see document [4], Command Structure), in
accordance with MOD_FRM pin on LEGIC advant SM
LRC: 1 byte, CRC: 2 bytes
# BYTECMDSTATRND_SM_7RND_SM_6...RND_SM_0LRC/CRC_HighCRC_Low
[0x0B / 0C][0xD0][0x00]8 bytes
ByteDescriptionValue
# BYTENumber of following bytes (CMD ... LRC/CRC)0x0B / 0C
CMDAnswer code for AUTH_A0xD0
STATStatus
0x00OK, function carried out →  "Waiting AUTH_B"
## 0x00
RND_SM_7 ... 08 byte random number generated by LEGIC advant SM
LRC/CRC_High,
CRC_Low
Check character, (see document [4], Command Struc-
ture), in accordance with MOD_FRM pin on LEGIC
advant SM
LRC: 1 byte, CRC: 2 bytes
## PRELIMINARY


LEGIC Identsystems Ltd
## CONFIDENTIAL
## 000-00

LEGIC advant 2000 Series
Reference Manual, Commands, SC-2560, SM-2570
05.2006© Transmission of contents to others prohibitedLA-33-110d-en61/92
Technical specifications subject to change
## 2.30    AUTH_B
The AUTH_B command is used to establish secure communication via the application inter-
face (LEGIC advant SM – Host Computer). The AUTH_B command carries out the second
step of the authentication.
See document [4] for a description of secure communication.
Conditions•   The AUTH_B command must follow the AUTH_A command.
-   The host computer must encrypt the bytes RND_HST_7 to PADDING_7 (see document
[4], section "Secured Communication"). Because the encryption algorithm needs a multi-
ple of 8 bytes, 7 PADDING bytes are necessary. The encryption algorithm uses the key
in the INTERFACE_KEYS object of the IDB. When sending the AUTH_B command for
the first time, the default setting of the key has to be used (see document [5]).
-   After the AUTH_B command has been executed, the LEGIC advant SM is in the
"Secure" state. For operation, now the key in the INTERFACE_KEYS object of the IDB
should be changed and the FORCE_SECURITY parameter should be set (with com-
mand ENCRYPT_MSG [SET_PARAMETER] or AUTH_ENCRYPT_MSG
## [SET_PARAMETER]).
-   In the answer, the bytes RND_SM_7 to RND_HST_0 are transferred encrypted. The host
computer has to decrypt these bytes and to check the random numbers contanied.
AUTH_B command
## # BYTECMDRND_HST_7RND_HST_6...RND_HST_0RND_SM_7RND_SM_6...RND_SM_0
[0x1A / 1B][0xD1]8 Bytes8 Bytes
ALGOPADDING_1PADDING_2...PADDING_7LRC/CRC_HighCRC_Low
## [0x01 ... 21]7 Bytes [0x00]
encrypted with KEY_HST (or KEY_SRV)
ByteDescriptionValue
# BYTENumber of following bytes (CMD ... LRC/CRC)0x1A / 1B
CMDCommand code for AUTH_A0xD1
RND_HST_7 ... 08 byte random number generated by host computer
RND_SM_7 ... 08 byte random number received in AUTH_A command
ALGOAlgorithms for command encryption and command
authentication, see next page
## 0x01 ... 21
PADDING_1 ... 7Completion bytes for encryption algorithm (7 bytes)0x00
LRC/CRC_High,
CRC_Low
Check character, (see document [4], Command Struc-
ture), in accordance with MOD_FRM pin on LEGIC
advant SM
LRC: 1 byte, CRC: 2 bytes
## PRELIMINARY


LEGIC Identsystems Ltd
## CONFIDENTIAL
## 000-00

LEGIC advant 2000 Series
Reference Manual, Commands, SC-2560, SM-2570
62/92LA-33-110d-en© Transmission of contents to others prohibited05.2006
Technical specifications subject to change
ALGO byte
ImportantThe combination 0x00 (No encryption and no authentication) is not allowed.
AUTH_B answer
STATUS answerWith a non-command-specific error (e.g. communication error when sending the command)
a STATUS answer is returned (see page 34 and “Status and Error Codes" on page 90).
STATUS answer for comman-
do-specific errors
With this command the following command-specific errors are returned in the STATUS an-
swer.
Bit 7Bit 6Bit 5Bit 4Bit 3Bit 2Bit 1Bit 0
## ENC_3ENC_2ENC_1ENC_0AUTH_3AUTH_2AUTH_1AUTH_0
BitNameDescription
7 ... 4ENC_3 ... 0Command encryption
0x0 = No encryption
0x1 = DES encryption (64-bit key)
0x2 = 3DES encryption (112-bit key)
0x3 ... F =Reserved
3 ... 0AUTH_3 ... 0Command authentication
0x0 =No authentication
0x1 = HMAC-MD5
0x2 ... F =Reserved
## # BYTECMDSTATRND_SM_7RND_SM_6...RND_SM_0
[0x15 ... 2E][0xD1][0x00]8 Bytes
RND_HST_7RND_HST_6...RND_HST_0LRC/CRC_HighCRC_Low
## 8 Bytes
encrypted with KEY_HST (or KEY_SRV)
ByteDescriptionValue
# BYTENumber of following bytes (CMD ... LRC/CRC)0x15 ... 2E
CMDAnswer code for AUTH_B0xD1
STATStatus
0x00OK, action executed →  "Secure"
## 0x00
RND_SM_7 ... 08 byte random number generated by LEGIC advant SM
RND_HST_7 ... 08 byte random number generated by host computer
LRC/CRC_High,
CRC_Low
Check character, (see document [4], Command Struc-
ture), in accordance with MOD_FRM pin on LEGIC
advant SM
LRC: 1 byte, CRC: 2 bytes
STATDescription
0xE0INTERFACE_SECURITY_ERROR
LEGIC advant is not in the "Secure" state, no supported algorithm, wrong
random number, or communication error in secured communication →
"Plain"
## PRELIMINARY


LEGIC Identsystems Ltd
## CONFIDENTIAL
## 000-00

LEGIC advant 2000 Series
Reference Manual, Commands, SC-2560, SM-2570
05.2006© Transmission of contents to others prohibitedLA-33-110d-en63/92
Technical specifications subject to change
## 2.31    AUTH_MSG
The AUTH_MSG command serves for transmission of an authenticated command (any
LEGIC advant command) via the application interface. Between the LEGIC advant SM and
the host computer, a secured communication must be established.
See document [4] for a description of the secured communication.
Conditions•   A secured communication on the application interface must be established (AUTH_A and
AUTH_B commands). The LEGIC advant SM must be in the "Secure" state.
-   The authenticated command contains the original command, secured with a MAC (Mes-
sage Authentication Code, HMAC-MD5).
AUTH_MSG command
# BYTECMDSEQ_HighSEQ_MidSEQ_LowO_# BYTEO_CMDO_PAR
[0x0C ... ][0xD2][0x00 00 00 ... FF FF FF][0x02 ... ][0x01 ... D4]
O_LRC/O_CRC_HighO_CRC_LowMAC_7MAC_6...MAC_0LRC/CRC_HighCRC_Low
8 bytes
ByteDescriptionValue
# BYTENumber of following bytes (CMD ... LRC/CRC)0x0C ...
CMDCommand code for AUTH_MSG0xD2
SEQ_High,
SEQ_Mid
SEQ_Low
Value of send sequence counter, managed by the host
computer
O_# BYTENumber of bytes of the original command
## (O_CMD ... O_LRC/O_CRC)
## 0x02 ...
O_CMDCommand code of original command0x01 ... D4
O_PARParameter and data bytes of original command
## O_LRC/
O_CRC_High,
O_CRC_Low
Check character of original command, (see document [4],
Command Structure), in accordance with MOD_FRM pin
on LEGIC advant SM
LRC: 1 byte, CRC: 2 bytes
MAC_7 ... 0Message Authentication Code across SEQ ... LRC/CRC
(8 bytes)
LRC/CRC_High,
CRC_Low
Check character, (see document [4], Command Struc-
ture), in accordance with MOD_FRM pin on LEGIC
advant SM
LRC: 1 byte, CRC: 2 bytes
## PRELIMINARY


LEGIC Identsystems Ltd
## CONFIDENTIAL
## 000-00

LEGIC advant 2000 Series
Reference Manual, Commands, SC-2560, SM-2570
64/92LA-33-110d-en© Transmission of contents to others prohibited05.2006
Technical specifications subject to change
AUTH_MSG answer
STATUS answerWith a non-command-specific error (e.g. communication error when sending the command)
a STATUS answer is returned (see page 34 and “Status and Error Codes" on page 90).
STATUS answer for comman-
do-specific errors
With this command the following command-specific errors are returned in the STATUS an-
swer.
# BYTECMDSTATSEQ_HighSEQ_MidSEQ_LowO_# BYTEO_CMDO_PAR
[0x0D ... ][0xD2][0x00][0x00 00 00 ... FF FF FF][0x02 ... ][0x01 ... D4]
O_LRC/O_CRC_HighO_CRC_LowMAC_7MAC_6...MAC_0LRC/CRC_HighCRC_Low
8 bytes
ByteDescriptionValue
# BYTENumber of following bytes (CMD ... LRC/CRC)0x0D ...
CMDAnswer code for AUTH_MSG0xD2
STATStatus
0x00OK, action executed →  "Secure"
## 0x00
SEQ_High,
SEQ_Mid
SEQ_Low
Value of send sequence counter, managed by the LEGIC
advant SM
O_# BYTENumber of bytes of the original command
## (O_CMD ... O_LRC/O_CRC)
## 0x02 ...
O_CMDCommand code of original command0x01 ... D4
O_PARParameter and data bytes of original command
## O_LRC/
O_CRC_High,
O_CRC_Low
Check character of original command, (see document [4],
Command Structure), in accordance with MOD_FRM pin
on LEGIC advant SM
LRC: 1 byte, CRC: 2 bytes
MAC_7 ... 0Message Authentication Code across SEQ ... LRC/CRC
(8 bytes)
LRC/CRC_High,
CRC_Low
Check character, (see document [4], Command Struc-
ture), in accordance with MOD_FRM pin on LEGIC
advant SM
LRC: 1 byte, CRC: 2 bytes
STATDescription
0xE0INTERFACE_SECURITY_ERROR
LEGIC advant is not in the "Secure" state, MAC or sequence counter error,
or communication error in secured communication →  "Plain"
## PRELIMINARY


LEGIC Identsystems Ltd
## CONFIDENTIAL
## 000-00

LEGIC advant 2000 Series
Reference Manual, Commands, SC-2560, SM-2570
05.2006© Transmission of contents to others prohibitedLA-33-110d-en65/92
Technical specifications subject to change
## 2.32    ENCRYPT_MSG
The ENCRYPT_MSG command serves for transmission of an encrypted command (any
LEGIC advant command) via the application interface. Between the LEGIC advant SM and
the host computer, a secured communication must be established.
See document [4] for a description of the secured communication.
Conditions•   A secured communication on the application interface must be established (AUTH_A and
AUTH_B commands). The LEGIC advant SM must be in the "Secure" state.
-   The encrypted command contains the original command.
-   The encryption algorithm is defined in the ALGO byte of the AUTH_B command (DES or
## 3DES).
ENCRYPT_MSG command
# BYTECMDSEQ_HighSEQ_MidSEQ_LowO_# BYTEO_CMDO_PAR
[0x08 ... ][0xD3][0x00 00 00 ... FF FF FF][0x02 ... ][0x01 ... D4]
O_LRC/O_CRC_HighO_CRC_LowPADDING 0 ... 7LRC/CRC_HighCRC_Low
encrypted with ENC_KEY
ByteDescriptionValue
# BYTENumber of following bytes (CMD ... LRC/CRC)0x08 ...
CMDCommand code for ENCRYPT_MSG0xD3
SEQ_High,
SEQ_Mid
SEQ_Low
Value of send sequence counter, managed by the host
computer
O_# BYTENumber of bytes of the original command
## (O_CMD ... O_LRC/O_CRC)
## 0x02 ...
O_CMDCommand code of original command0x01 ... D4
O_PARParameter and data bytes of original command
## O_LRC/
O_CRC_High,
O_CRC_Low
Check character of original command, (see document [4],
Command Structure), in accordance with MOD_FRM pin
on LEGIC advant SM
LRC: 1 byte, CRC: 2 bytes
PADDING 0 ... 7Completion bytes for DES / 3DES algorithm (0 ... 7 bytes)
The DES / 3DES algorithm uses a block size of 8 bytes.
The number of bytes of the encrypted command (SEQ ...
PADDING) must be a multiple of 8.
## 0x00
LRC/CRC_High,
CRC_Low
Check character (see document [4], Command Structure),
in accordance with MOD_FRM pin on LEGIC advant SM
LRC: 1 byte, CRC: 2 bytes
## PRELIMINARY


LEGIC Identsystems Ltd
## CONFIDENTIAL
## 000-00

LEGIC advant 2000 Series
Reference Manual, Commands, SC-2560, SM-2570
66/92LA-33-110d-en© Transmission of contents to others prohibited05.2006
Technical specifications subject to change
ENCRYPT_MSG answer
STATUS answerWith a non-command-specific error (e.g. communication error when sending the command)
a STATUS answer is returned (see page 34 and “Status and Error Codes" on page 90).
STATUS answer for comman-
do-specific errors
With this command the following command-specific errors are returned in the STATUS an-
swer.
# BYTECMDSTATSEQ_HighSEQ_MidSEQ_LowO_# BYTEO_CMD
[0x08 ... ][0xD3][0x00][0x00 00 00 ... FF FF FF][0x02 ... ][0x01 ... D4]
O_PARO_LRC/O_CRC_HighO_CRC_LowPADDING 0 ... 7LRC/CRC_HighCRC_Low
encrypted with ENC_KEY
ByteDescriptionValue
# BYTENumber of following bytes (CMD ... LRC/CRC)0x08 ...
CMDAnswer code for ENCRYPT_MSG0xD3
STATStatus
0x00OK, action executed →  "Secure"
## 0x00
SEQ_High,
SEQ_Mid
SEQ_Low
Value of send sequence counter, managed by the LEGIC
advant SM
O_# BYTENumber of bytes of the original command
## (O_CMD ... O_LRC/O_CRC)
## 0x02 ...
O_CMDCommand code of original command0x01 ... D4
O_PARParameter and data bytes of original command
## O_LRC/
O_CRC_High,
O_CRC_Low
Check character of original command, (see document [4],
Command Structure), in accordance with MOD_FRM pin
on LEGIC advant SM
LRC: 1 byte, CRC: 2 bytes
PADDING 0 ... 7Completion bytes for DES / 3DES algorithm (0 ... 7 bytes)
The DES / 3DES algorithm uses a block size of 8 bytes.
The number of bytes of the encrypted command (SEQ ...
PADDING) must be a multiple of 8.
## 0x00
LRC/CRC_High,
CRC_Low
Check character (see document [4], Command Structure),
in accordance with MOD_FRM pin on LEGIC advant SM
LRC: 1 byte, CRC: 2 bytes
STATDescription
0xE0INTERFACE_SECURITY_ERROR
LEGIC advant is not in the "Secure" state, sequence counter error, or com-
munication error in secured communication →  "Plain"
## PRELIMINARY


LEGIC Identsystems Ltd
## CONFIDENTIAL
## 000-00

LEGIC advant 2000 Series
Reference Manual, Commands, SC-2560, SM-2570
05.2006© Transmission of contents to others prohibitedLA-33-110d-en67/92
Technical specifications subject to change
## 2.33    AUTH_ENCRYPT_MSG
The AUTH_ENCRYPT_MSG command serves for transmission of an authenticated and en-
crypted command (any LEGIC advant command) via the application interface. Between the
LEGIC advant SM and the host computer, a secured communication must be established.
See document [4] for a description of the secured communication.
Conditions•   A secured communication on the application interface must be established (AUTH_A and
AUTH_B commands). The LEGIC advant SM must be in the "Secure" state.
-   The authenticated and encrypted command contains the original command, which is
encrypted and additionally secured with a MAC (Message Authentication Code, HMAC-
## MD5).
-   The encryption algorithm is defined in the ALGO byte of the AUTH_B command (DES or
## 3DES).
## AUTH_ENCTYPT_MSG
command
# BYTECMDSEQ_HighSEQ_MidSEQ_LowO_# BYTEO_CMDO_PARO_LRC/O_CRC_High
[0x0C ... ][0xD4][0x00 00 00 ... FF FF FF][0x02 ... ][0x01 ... D4]
O_CRC_LowMAC_7MAC_6...MAC_0PADDING 0 ... 7LRC/CRC_HighCRC_Low
8 bytes
encrypted with ENC_KEY
ByteDescriptionValue
# BYTENumber of following bytes (CMD ... LRC/CRC)0x0C ...
CMDCommand code for AUTH_ENCRYPT_MSG0xD4
SEQ_High,
SEQ_Mid
SEQ_Low
Value of send sequence counter, managed by the host
computer
O_# BYTENumber of bytes of the original command
## (O_CMD ... O_LRC/O_CRC)
## 0x02 ...
O_CMDCommand code of original command0x01 ... D4
O_PARParameter and data bytes of original command
## O_LRC/
O_CRC_High,
O_CRC_Low
Check character of original command, (see document [4],
Command Structure), in accordance with MOD_FRM pin
on LEGIC advant SM
LRC: 1 byte, CRC: 2 bytes
MAC_7 ... 0Message Authentication Code across SEQ ... LRC/CRC
PADDING 0 ... 7Completion bytes for DES / 3DES algorithm (0 ... 7 bytes)
The DES / 3DES algorithm uses a block size of 8 bytes.
The number of bytes of the encrypted command (SEQ ...
PADDING) must be a multiple of 8.
## 0x00
LRC/CRC_High,
CRC_Low
Check character (see document [4], Command Structure),
in accordance with MOD_FRM pin on LEGIC advant SM
LRC: 1 byte, CRC: 2 bytes
## PRELIMINARY


LEGIC Identsystems Ltd
## CONFIDENTIAL
## 000-00

LEGIC advant 2000 Series
Reference Manual, Commands, SC-2560, SM-2570
68/92LA-33-110d-en© Transmission of contents to others prohibited05.2006
Technical specifications subject to change
## AUTH_ENCTYPT_MSG
answer
STATUS answerWith a non-command-specific error (e.g. communication error when sending the command)
a STATUS answer is returned (see page 34 and “Status and Error Codes" on page 90).
STATUS answer for comman-
do-specific errors
With this command the following command-specific errors are returned in the STATUS an-
swer.
# BYTECMDSTATSEQ_HighSEQ_MidSEQ_LowO_# BYTEO_CMDO_PAR
[0x0D ... ][0xD4][0x00][0x00 00 00 ... FF FF FF][0x02 ... ][0x01 ... D4]
O_LRC/O_CRC_HighO_CRC_LowMAC_7MAC_6...MAC_0PADDING 0 ... 7LRC/CRC_HighCRC_Low
## 8 Bytes
encrypted with ENC_KEY
ByteDescriptionValue
# BYTENumber of following bytes (CMD ... LRC/CRC)0x0D ...
CMDAnswer code for AUTH_ENCRYPT_MSG0xD4
STATStatus
0x00OK, action executed→  "Secure"
## 0x00
SEQ_High,
SEQ_Mid
SEQ_Low
Value of send sequence counter, managed by the LEGIC
advant SM
O_# BYTENumber of bytes of the original command
## (O_CMD ... O_LRC/O_CRC)
## 0x02 ...
O_CMDCommand code of original command0x01 ... D4
O_PARParameter and data bytes of original command
## O_LRC/
O_CRC_High,
O_CRC_Low
Check character of original command, (see document [4],
Command Structure), in accordance with MOD_FRM pin
on LEGIC advant SM
LRC: 1 byte, CRC: 2 bytes
MAC_7 ... 0Message Authentication Code across SEQ ... LRC/CRC
(8 bytes)
PADDING 0 ... 7Completion bytes for DES / 3DES algorithm (0 ... 7 bytes)
The DES / 3DES algorithm uses a block size of 8 bytes.
The number of bytes of the encrypted command (SEQ ...
PADDING) must be a multiple of 8.
## 0x00
LRC/CRC_High,
CRC_Low
Check character (see document [4], Command Structure),
in accordance with MOD_FRM pin on LEGIC advant SM
LRC: 1 byte, CRC: 2 bytes
STATDescription
0xE0INTERFACE_SECURITY_ERROR
LEGIC advant is not in the "Secure" state, MAC or sequence counter error,
or communication error in secured communication →  "Plain"
## PRELIMINARY


LEGIC Identsystems Ltd
## CONFIDENTIAL
## 000-00

LEGIC advant 2000 Series
Reference Manual, Commands, SC-2560, SM-2570
05.2006© Transmission of contents to others prohibitedLA-33-110d-en69/92
Technical specifications subject to change
## 2.34    SET_PARAMETER
The SET_PARAMETER command sets the parameters of an object of the information data-
base (IDB) in the LEGIC advant SM (see document [5], Information Database).
SET_PARAMETER command
## # BYTECMDOIDINDEXMODEIDB_V#DATADATA 0DATA 1
[0x0B ... 21][0xB5][0x00 ... 51][0x01 ... 04][0x00 / 01][0x01][0x01 ... 1C][0x00 ... FF] [0x00 ... FF]
DATA 2DATA 3...DATA nLRC/CRC_HighCRC_Low
[0x00 ... FF] [0x00 ... FF] [0x00 ... FF]
ByteDescriptionValue
# BYTENumber of following bytes (CMD ... LRC/CRC)0x0B ... 21
CMDCommand code for SET_PARAMETER0xB5
OIDObject to be written (see document [2], Information Database)
0x02INTERFACE_OPTIONS [1, 2]
0x03INTERFACE_KEYS [1, 2] *
0x04SRV_INTERFACE_ACCESS_CONTROL
0x05RFID_OPTIONS
0x06SYSTEM_POWER_CONTROL
0x07WATCH_EVENT_MASK
0x08WATCH_EVENT_OPTIONS
0x12MASTER_TIMEOUT
0x21AUTO_READ_OPTIONS
0x22AUTO_READ_SEARCH_PATTERN [1 ... 10]
0x23AUTO_READ_DATA_WINDOW [1 ... 10]
0x30CASH_VALUE_OPTIONS **
0x40USER_DATA [1 ... 4]
0x50RTC_DATE_TIME
0x51RTC_ALARM [1 ... 8]
- Only possible in "Secure" mode (following AUTH_A, AUTH_B com-
mands)
## **    LEGIC
cash
## TM
standard only with LEGIC advant SM types SC-2140C,
## SC-2240C, SC-2560C, SM-2570C
## 0x00 ... 51
INDEXObject index (some objects have several elements; these ele-
ments are selected with the index)
INTERFACE_OPTIONS [1, 2] 0x01 / 02
INTERFACE_KEYS [1, 2] *0x01 / 02
AUTO_READ_SEARCH_PATTERN 0x01 ... 0A
AUTO_READ_DATA_WINDOW 0x01 ... 0A
USER_DATA [1 ... 4]0x01 ... 04
RTC_ALARM [1 ... 8]0x01 ... 08
Objects without index0x01
-    Only possible in "Secure" mode (following AUTH_A, AUTH_B com-
mands)
## 0x01 ... 04
MODEMemory mode
0x00Object is written to permanent and temporary mem-
ory
0x01Object is written to temporary memory only
–   Objects that are instantly active:
If they are frequently changed they can be written to the temporary
memory (RAM) instead of to the permanent memory (EEPROM) of the
LEGIC advant SM. However, they must be written again following the
next start-up or a reset because the EEPROM values are transfered to
the RAM at start-up.
–   Objects that are only active after a reset:
They have to be written to the pernanent memory always.
## 0x00 / 01
## PRELIMINARY


LEGIC Identsystems Ltd
## CONFIDENTIAL
## 000-00

LEGIC advant 2000 Series
Reference Manual, Commands, SC-2560, SM-2570
70/92LA-33-110d-en© Transmission of contents to others prohibited05.2006
Technical specifications subject to change
SET_PARAMETER answer
STATUS answerWith a non-command-specific error (e.g. communication error when sending the command)
a STATUS answer is returned (see page 34 and “Status and Error Codes" on page 90).
IDB_VIDB version0x01
#DATANumber of parameter bytes to be written (depending on
selected object), 1 ... 28
0x01 ... 1C
DATA 0 ... nParameter bytes to be written, according to object definition
(see document [5])
0x00 ... FF
## LRC/
CRC_High,
CRC_Low
Check character, (see document [4], Command Structure), in
accordance with MOD_FRM pin on LEGIC advant SM
LRC: 1 byte, CRC: 2 bytes
ByteDescriptionValue
# BYTECMDSTATLRC/CRC_HighCRC_Low
[0x03 / 04][0xB5][0x00 ... 04]
ByteDescriptionValue
# BYTENumber of following bytes (CMD ... LRC/CRC)0x03 / 04
CMDAnswer code for SET_PARAMETER0xB5
STATStatus
0x00   OK, parameters set
–   for objects that are instantly active
0x01   OK, parameters will be set following next reset
–   for objects that are active only after the next reset
–   if MODE = 0x01, no action
0x02   Invalid index
0x03   Invalid Object No. (OID) or IDB version
0x04   Defective object (wrong length, invalid values)
0x05   Object cannot be written
(read only, wrong interface (host, service), not in “secure”
communication state)
## 0x00 ... 04
## LRC/
CRC_High,
CRC_Low
Check character, (see document [4], Command Structure), in
accordance with MOD_FRM pin on LEGIC advant SM
LRC: 1 byte, CRC: 2 bytes
## PRELIMINARY


LEGIC Identsystems Ltd
## CONFIDENTIAL
## 000-00

LEGIC advant 2000 Series
Reference Manual, Commands, SC-2560, SM-2570
05.2006© Transmission of contents to others prohibitedLA-33-110d-en71/92
Technical specifications subject to change
## 2.35    GET_PARAMETER
The GET_PARAMETER command reads the parameters of an object from the information
database (IDB) in the LEGIC advant SM (see document [5]). The values are read from the
## RAM.
GET_PARAMETER command
# BYTECMDOIDINDEXIDB_VLRC/CRC_HighCRC_Low
[0x5 / 06][0xB6][0x00 ... 51][0x01 ... 1E][0x01]
ByteDescriptionValue
# BYTENumber of following bytes (CMD ... LRC/CRC)0x05 / 06
CMDCommand code for GET_PARAMETER0xB6
OIDObject to be read (see document [2], Information Database)
0x00SYSTEM_INFO
0x01SYSTEM_OPTIONS
0x02INTERFACE_OPTIONS [1, 2]
0x04SRV_INTERFACE_ACCESS_CONTROL
0x05RFID_OPTIONS
0x06SYSTEM_POWER_CONTROL
0x07WATCH_EVENT_MASK
0x08WATCH_EVENT_OPTIONS
0x10LAUNCH_DATA [1 ... 16]
0x11MASTER_DATA [1 ... 30]
0x12MASTER_TIMEOUT
0x21AUTO_READ_OPTIONS
0x22AUTO_READ_SEARCH_PATTERN
0x23AUTO_READ_DATA_WINDOW
0x30CASH_VALUE_OPTIONS *
0x40USER_DATA [1 ... 4]
0x50RTC_DATE_TIME
0x51RTC_ALARM [1 ... 8]
*LEGIC cash
## TM
standard only with LEGIC advant SM types SC-2140C,
## SC-2240C, SC-2560C, SM-2570C
## 0x00 ... 51
INDEXObject index (some objects have several elements; these ele-
ments are selected with the index)
INTERFACE_OPTIONS [1, 2] 0x01 / 02
LAUNCH_DATA [1 ... 16]0x01 ... 10
MASTER_DATA [1 ... 30]0x01 ... 1E
AUTO_READ_SEARCH_PATTERN 0x01 ... 0A
AUTO_READ_DATA_WINDOW 0x01 ... 0A
USER_DATA [1 ... 4]0x01 ... 04
RTC_ALARM [1 ... 8] *0x01 ... 08
Objects without index0x01
0x01 ... 1E
IDB_VIDB version0x01
## LRC/
CRC_High,
CRC_Low
Check character, (see document [4], Command Structure), in
accordance with MOD_FRM pin on LEGIC advant SM
LRC: 1 byte, CRC: 2 bytes
## PRELIMINARY


LEGIC Identsystems Ltd
## CONFIDENTIAL
## 000-00

LEGIC advant 2000 Series
Reference Manual, Commands, SC-2560, SM-2570
72/92LA-33-110d-en© Transmission of contents to others prohibited05.2006
Technical specifications subject to change
GET_PARAMETER answer
STATUS answerWith a non-command-specific error (e.g. communication error when sending the command)
a STATUS answer is returned (see page 34 and “Status and Error Codes" on page 90).
## # BYTECMDSTAT#DATADATA 0DATA 1DATA 2DATA 3...
[0x04 ... 20][0xB6][0x00 ... 02][0x01 ... 1C][0x00 ... FF] [0x00 ... FF] [0x00 ... FF] [0x00 ... FF]
DATA nLRC/CRC_HighCRC_Low
[0x00 ... FF]
ByteDescriptionValue
# BYTENumber of following bytes (CMD ... LRC/CRC)0x04 ... 20
CMDAnswer code for GET_PARAMETER0xB6
STATStatus (In case of a fault, no data are returned, #DATA = 0)
0x00    OK
0x01    Invalid index
0x02   Invalid Object No. (OID) or IDB version
0x03   Object cannot be read
(write only, wrong interface (host, service))
## 0x00 ... 02
#DATANumber of parameter bytes to be read (depending on selected
object), 1 ... 29
0x01 ... 1D
DATA 0 ... n   Read parameter bytes, according to object definition (see
document [5])
0x00 ... FF
## LRC/
CRC_High,
CRC_Low
Check character, (see document [4], Command Structure), in
accordance with MOD_FRM pin on LEGIC advant SM
LRC: 1 byte, CRC: 2 bytes
## PRELIMINARY


LEGIC Identsystems Ltd
## CONFIDENTIAL
## 000-00

LEGIC advant 2000 Series
Reference Manual, Commands, SC-2560, SM-2570
05.2006© Transmission of contents to others prohibitedLA-33-110d-en73/92
Technical specifications subject to change
## 2.36    DELETE_LAUNCH_DATA
The DELETE_LAUNCH_DATA command deletes a launch data record from the information
database (IDB) in the LEGIC advant SM.
Conditions•   DELETE_LAUNCH_DATA deletes a launch data record in which Byte 1 (DATA 0) of the
launch data record is set to 0x00. The launch data record is thus marked as deleted.
-   The DELETE_LAUNCH_DATA answer returns information on the successful execution
of the command.
## DELETE_LAUNCH_DATA
## Command
DELETE_LAUNCH_DATA an-
swer
STATUS answerWith a non-command-specific error (e.g. communication error when sending the command)
a STATUS answer is returned (see page 34 and “Status and Error Codes" on page 90).
STATUS answer for comman-
do-specific errors
With this command the following command-specific errors are returned in the STATUS an-
swer.
# BYTECMDGEN_SET_NUMLRC/CRC_HighCRC_Low
## [0x03 / 04][0x54][0x01 ... 10]
ByteDescriptionValue
# BYTENumber of following bytes (CMD ... LRC)0x03 / 04
CMDCommand code for DELETE_LAUNCH_DATA0x54
GEN_SET_NUM   Number of the launch data record to be deleted (1 ... 16)0x01 ... 10
LRC/CRC_High,
CRC_Low
Check character, (see document [4], Command Structure),
in accordance with MOD_FRM pin on LEGIC advant SM
LRC: 1 byte, CRC: 2 bytes
# BYTECMDGEN_SET_NUMLRC/CRC_HighCRC_Low
## [0x03 / 04][0x54][0x01 ... 10]
ByteDescriptionValue
# BYTENumber of following bytes (CMD ... LRC)0x03 / 04
CMDAnswer code for DELETE_LAUNCH_DATA0x54
GEN_SET_NUM   Status message or number of the deleted launch data
record (1 ... 16)
0x00Launch data record could not be deleted. Write
error in the LEGIC advant SM
0x01 ... 10  Number of the deleted launch data record
## 0x00 ... 10
LRC/CRC_High,
CRC_Low
Check character, (see document [4], Command Structure),
in accordance with MOD_FRM pin on LEGIC advant SM
LRC: 1 byte, CRC: 2 bytes
STATDescription
0x01Launch-data record number too high or 0
## PRELIMINARY


LEGIC Identsystems Ltd
## CONFIDENTIAL
## 000-00

LEGIC advant 2000 Series
Reference Manual, Commands, SC-2560, SM-2570
74/92LA-33-110d-en© Transmission of contents to others prohibited05.2006
Technical specifications subject to change
## 2.37    START_SWDL
The START_SWDL command starts the software download function and sets the baud rate
for the following data transmission with DATA_SWDL. With the software download function
an update of the LEGIC OS can be loaded in the LEGIC advant SM.
Conditions•   The LEGIC advant SM must operate in the serial-asynchronous interface mode.
-   START_SWDL can only be issued in the Superuser Mode, see page 57.
-   With START_SWDL a different baud rate for the data transfer can be selected. After the
data trasfer, the baud rate is reset to the value defined by the MODE pins or the IDB
object with a reset.
-   After the START_SWDL command, the software download can be cancelled by a reset.
The RESET command must be sent with the baud rate returnded in the START_SWDL
answer.
Procedure1.  Send the SUPERUSER_MODE command.
-  Send the START_SWDL command with the desired baud rate. The LEGIC advant SM
enters the bootloader application for software download.
-  Send the DATA_SWDL command repeatedly to transmit the new LEGIC OS version
(see page 77). If all data is tranfered successfully, the STAT byte of the last
DATA_SWDL command contains 0xFF.
-  Execute a reset (connect /RESET pin to GND or execute RESET command). The STA-
TUS answer after the reset (SYS_ANSWER_FROM_RESET) is returned with the baud
rate defined by the MODE pins or in the IDB object INTERFACE_OPTIONS.
NoteIf an error occurs in the procedure above or if the /RESGEN pin had been activated, execute
a reset (connect /RESET pin to GND or execute RESET command) and repeat steps 1 ... 4.
For that purpose set the baud rate of the host computer to 9600 bps.
## START_SWDL
command
# BYTECMDRESBAUDLRC/CRC_HighCRC_Low
[0x04 / 05][0xBD][0x00][0x00 ... 03]
ByteDescriptionValue
# BYTENumber of following bytes (CMD ... LRC)0x04 / 05
CMDCommand code for START_SWDL0xBD
RESReserve0x00
BAUDDesired transmission speed for data transfer with
DATA_SWDL (active after START_SWDL answer)
0x009600 bps
0x0119’200 bps
0x0238’400 bps
0x0357’600 bps
0x04115’200 bps
## 0x00 ... 03
LRC/CRC_High,
CRC_Low
Check character, (see document [4], Command Structure),
in accordance with MOD_FRM pin on LEGIC advant SM
LRC: 1 byte, CRC: 2 bytes
## PRELIMINARY


LEGIC Identsystems Ltd
## CONFIDENTIAL
## 000-00

LEGIC advant 2000 Series
Reference Manual, Commands, SC-2560, SM-2570
05.2006© Transmission of contents to others prohibitedLA-33-110d-en75/92
Technical specifications subject to change
START_SWDL answer
## # BYTECMDSTATBAUDBLV 4BLV 3BLV 2BLV 1
[0x1E / 1F][0xBD][0x00 ... 02][0x00 ... 04][0x00 ... 99][0x00 ... 99][0x00 ... 99][0x00 ... 99]
## MCD_1MCD_2SER_NO 4SER_NO 3SER_NO 2SER_NO 1SERIESSM_TYPE
[0x00 ... FF]    [0x00 ... FF][0x00 ... FF][0x00 ... FF][0x00 ... FF][0x00 ... FF][0x00 / 01][0x00 ... 04]
## SWV 4SWV 3SWV 2SWV 1HWV 4HWV 3HWV 2HWV 1
[0x00 ... 99]    [0x00 ... 99][0x00 ... 99][0x00 ... 99][0x00 ... 99][0x00 ... 99][0x00 ... 99][0x00 ... 99]
DATE_HighDATE_LowPARAM 1..8PARAM 9..16PARAM 17..24RESLRC/CRC_HighCRC_Low
[0x01 ... 34]    [0x00 ... FF][0xFE / FF][0x01][0x00 ... 07][0x00]
ByteDescriptionValue
# BYTENumber of following bytes (CMD ... LRC)0x1E / 1F
CMDCommand code for START_SWDL0xBD
STATStatus
0x00OK, bootloader in LEGIC advant SM is ready for
receiving data
0x01LEGIC advant SM is not in Superuser Mode
0x02Error during download, execute a reset and repeat
steps 1 ... 4 with 9600 bps (see previous page).
## 0x00 ... 02
BAUDTransmission speed set for data transfer (active after
START_SWDL answer)
0x00    9600 bps
0x01    19’200 bps
0x02    38’400 bps
0x03    57’600 bps
0x04    115’200 bps
## 0x00 ... 04
BLV 4 ... 1Bootloader version (BCD-encoded)
Example: 0x00 02 01 01Version 0.2.1.1
## 0x0000000
## ... 99999999
MCD_1 License partner code (orderer of LEGIC advant SM)0x00 ... FF
MCD_2Reserved0x00 ... FF
## SER_NO
## 4 ... 1
Serial number of LEGIC advant SM (4 bytes)0x0000000..
## FFFFFFFF
SERIESLEGIC advant Series
0x00Reserved
0x01LEGIC advant 2000 Series
## 0x00 / 01
SM_TYPELEGIC advant SM type
0x01SC-2140
0x02SC-2240
0x03SC-2560
0x04SM-2570
## 0x01 ... 04
SWV 4 ... 1Software version (LEGIC OS version) (BCD-encoded)
Examples: 0x00 02 00 00Version 0.2.0.0
0x01 04 09 09Version 1.4.9.9
The imprint on the SM only contains the first two digits of the
version number
## 0x0000000
## ... 99999999
HWV 4 ... 1Hardware version (BCD-encoded)
Examples: 0x00 02 00 00Version 0.2.0.0
0x01 04 09 09Version 1.4.9.9
The imprint on the SM only contains the first two digits of the
version number
## 0x0000000
## ... 99999999
DATE_High,
## Low
Production date (week, year (2000 = 0))
Example:   0x06 03 = week 6, 2003
## 0x0100 ...
## 34FF
## PRELIMINARY


LEGIC Identsystems Ltd
## CONFIDENTIAL
## 000-00

LEGIC advant 2000 Series
Reference Manual, Commands, SC-2560, SM-2570
76/92LA-33-110d-en© Transmission of contents to others prohibited05.2006
Technical specifications subject to change
STATUS answerWith a non-command-specific error (e.g. communication error when sending the command)
a STATUS answer is returned (see page 34 and “Status and Error Codes" on page 90).
STATUS answer for comman-
do-specific errors
With this command the following command-specific errors are returned in the STATUS an-
swer.
## PARAM
## 1 ... 8
LEGIC cash
## TM
## Standard
0xFENot activated (SC-2140, SC-2240, SC-2560,
## SM-2570)
0xFFActivated (SC-2140C, SC-2240C, SC-2560C,
## SM-2570C)
0xFE / FF
## PARAM
## 9 ... 16
Not in use, fixed value = 0x010x01
## PARAM
## 17 ... 24
Supported RF standards of LEGIC advant SM0x00 ... 07
RES (reserved)
## ISO 14443
0    ISO 14443 A is not supported (SC-2240)
1    ISO 14443 A is supported (SC-2140, SC-2560,
## SM-2570)
## ISO 15693
0    ISO 15693 is not supported (SC-2140)
1    ISO 15693 is supported (SC-2240, SC-2560, SM-2570)
## LEGIC RF
0    LEGIC RF Standard is not supported
1    LEGIC RF Standard is supported (all LEGIC advant SM)
RESReserved0x00
## LRC/
CRC_High,
CRC_Low
Check character, (see document [4], Command Structure), in
accordance with MOD_FRM pin on LEGIC advant SM
LRC: 1 byte, CRC: 2 bytes
ByteDescriptionValue
MS BitLS Bit
Bit 7    Bit 6    Bit 5    Bit 4    Bit 3Bit 2Bit 1Bit 0
## RESRESRESRESRESISO14443ISO15693LEGIC RF
STATDescription
0x22INVALID_PARAMETER
Specified baud rate is not supported.
## PRELIMINARY


LEGIC Identsystems Ltd
## CONFIDENTIAL
## 000-00

LEGIC advant 2000 Series
Reference Manual, Commands, SC-2560, SM-2570
05.2006© Transmission of contents to others prohibitedLA-33-110d-en77/92
Technical specifications subject to change
## 2.38    DATA_SWDL
The DATA_SWDL command is used for the software download function (see page 74). It
tranfers a LEGIC OS update in 128 byte steps to the LEGIC advant SM.
The file with the encrypted LEGIC OS update is supplied by LEGIC Identsystems Ltd.
Conditions•   The LEGIC advant SM must operate in the serial-asynchronous interface mode.
-   DATA_SWDL can only be issued in the Superuser Mode (see page 57) and after the
START_SWDL command (prodecure see page 74).
-   A DATA_SWDL command transmits 128 bytes. The DATA_SWDL command has to be
repeated until all bytes of the LEGIC OS are transfered. If all data is tranfered success-
fully, the STAT byte of the last DATA_SWDL command contains 0xFF.
-   After completion of the download, a reset must be executed (connect /RESET pin to
GND or execute RESET command). After the reset, the new LEGIC OS is active.
NoteIf an error occurs during software download, execute a reset (connect /RESET pin to GND
or execute RESET command) and repeat steps 1 ... 4 (see page 74). For that purpose set
the baud rate of the host computer to 9600 bps.
## DATA_SWDL
command
DATA_SWDL Antwort
STATUS answerWith a non-command-specific error (e.g. communication error when sending the command)
a STATUS answer is returned (see page 34 and “Status and Error Codes" on page 90).
# BYTECMDDATA 0...DATA 127LRC/CRC_HighCRC_Low
[0x82 / 83][0xBE][0x00 ... FF]...[0x00 ... FF]
ByteDescriptionValue
# BYTENumber of following bytes (CMD ... LRC)0x82 / 83
CMDCommand code for DATA_SWDL0xBE
DATA 0 ... 127    Encrypted data of LEGIC OS update (block of 128 bytes)
## LRC/
CRC_High,
CRC_Low
Check character, (see document [4], Command Structure),
in accordance with MOD_FRM pin on LEGIC advant SM
LRC: 1 byte, CRC: 2 bytes
# BYTECMDSTATLRC/CRC_HighCRC_Low
[0x03 / 04][0xBE][0x00 ... FF]
ByteDescriptionValue
# BYTENumber of following bytes (CMD ... LRC)0x03 / 04
CMDCommand code for DATA_SWDL0xBE
STATStatus
0x00OK, data transfered, send next block
0x01General error, wrong state
0xFFDownload terminated (LEGIC OS completely tran-
fered)
0x00 ... FF
## LRC/
CRC_High,
CRC_Low
Check character, (see document [4], Command Structure),
in accordance with MOD_FRM pin on LEGIC advant SM
LRC: 1 byte, CRC: 2 bytes
## PRELIMINARY


LEGIC Identsystems Ltd
## CONFIDENTIAL
## 000-00

LEGIC advant 2000 Series
Reference Manual, Commands, SC-2560, SM-2570
78/92LA-33-110d-en© Transmission of contents to others prohibited05.2006
Technical specifications subject to change
## 2.39    SET_PASSWORD
The SET_PASSWORD command is used for the password protection of LEGIC advant SMs
(for a description, see document [2]).
It activates the password protection of a LEGIC advant SM.
Conditions•   A LEGIC advant SM with activated password protection expects the UNLOCK command
with the correct password following every power-up. If the wrong password is given or a
different command is issued, the LEGIC advant SM returns a STATUS answer with
STAT = 0xF2, SYS_LOCKED.
-   SET_PASSWORD causes all the launch data records and master data records to be
deleted (except if the password protection is already activated, see SET_PASSWORD
answer).
-   A password cannot be overwritten with another password, except with 0. If the password
is set to 0, the password protection is deactivated.
-   The password protection can also be deactivated with a signal at /RESGEN pin of the
LEGIC advant SM. All the launch data records are deleted simultaneously.
NoteIf the /RESGEN pin is set to GND for more than 5 s, the IDB object
INTERFACE_OPTIONS is also reset.
SET_PASSWORD command
SET_PASSWORD answer
STATUS answerWith a non-command-specific error (e.g. communication error when sending the command)
a STATUS answer is returned (see page 34 and “Status and Error Codes" on page 90).
# BYTECMDPWD0PWD1PWD2PWD3LRC/CRC_HighCRC_Low
[0x06 / 07][0x01][0x00 ... FF] [0x00 ... FF] [0x00 ... FF] [0x00 ... FF]
ByteDescriptionValue
# BYTENumber of following bytes (CMD ... LRC/CRC)0x06 / 07
CMDCommand code for SET_PASSWORD0x01
PWD0 ... 3Password:
0x00 00 00 00Password protection deacti-
vated
0x00 00 00 01 ... FF FF FF FF    Password protection activated
0x00 ... FF
## LRC/
CRC_High,
CRC_Low
Check character, (see document [4], Command Structure), in
accordance with MOD_FRM pin on LEGIC advant SM
LRC: 1 byte, CRC: 2 bytes
# BYTECMDPWD_STATLRC/CRC_HighCRC_Low
## [0x03 / 04][0x01][0x00 ... 02]
ByteDescriptionValue
# BYTENumber of following bytes (CMD ... LRC/CRC)0x03 / 04
CMDAnswer code for SET_PASSWORD0x01
PWD_STAT   Password status:
0x00  Password set to 0x00 00 00 00, password protection
deactivated
0x01  Password protection activated,
password > 0x00 00 00 00
0x02  Password protection already activated, password can-
not be overwritten
## 0x00 ... 02
## LRC/
CRC_High,
CRC_Low
Check character, (see document [4], Command Structure), in
accordance with MOD_FRM pin on LEGIC advant SM
LRC: 1 byte, CRC: 2 bytes
## PRELIMINARY


LEGIC Identsystems Ltd
## CONFIDENTIAL
## 000-00

LEGIC advant 2000 Series
Reference Manual, Commands, SC-2560, SM-2570
05.2006© Transmission of contents to others prohibitedLA-33-110d-en79/92
Technical specifications subject to change
## 2.40    ADD_MASTER_DATA
The ADD_MASTER_DATA command reads in the data of an authorization medium (GAM,
SAM, IAM, XAM_1) as a master data record into the information database (IDB) of the LEGIC
advant SM.
Conditions•   ADD_MASTER_DATA can only be executed with a LEGIC advant SM with an initializa-
tion function (SC-2560, SM-2570). The /ICE-Pin has to be enabled.
-   Before ADD_MASTER is executed, communication with the authorization segment must
be established with the SEARCH_SEGMENT command ("Segment selected" communi-
cation state).
-   ADD_MASTER reads in the stamp data of the authorization segment as a master data
record. The data of GAM, SAM and IAM are saved in the temporary memory, the data of
XAM_1 in the permanent memory. The master data records can be read out with the
MASTER_DATA object of the IDB (see document [5]).
-   The LEGIC advant SM can hold a maximum of 30 master data records, 20 in the tempo-
rary memory, 10 in the permanent memory (XAM_1 master data records).
-   Master data records of GAM, SAM and IAM are deleted automatically from the memory
of the LEGIC advant SM, if no initialization function occurs during the time limit (master
timeout) or if the SM is switched off. The master timeout is stored in the
MASTER_TIMEOUT object of the IDB.
-   The master record of an XAM_1 is stored in the permanent memory of the LEGIC advant
SM (data record can only be deleted with DELETE_MASTER_DATA or with the
/RESGEN pin)
NoteIf the /RESGEN pin is set to GND for more than 5 s, the IDB object
INTERFACE_OPTIONS is also reset.
CautionProtect an LEGIC advant SM with stored XAM_1 master data record against unau-
thorized access (logistics, spare parts). New application segments can be initial-
ized or deleted at any time with this kind of LEGIC advant SM.
Ensure by means of the application that segments cannot be deleted unintention-
ally.
-   If the command is carried out successfully, the master timeout is restarted.
-   After ADD_MASTER_DATA is processed, the LEGIC advant SM remains in the "Seg-
ment selected" state.
ADD_MASTER_DATA com-
mand
# BYTECMDLRC/CRC_HighCRC_Low
[0x02 / 03][0xC3]
ByteDescriptionValue
# BYTENumber of following bytes (CMD ... LRC/CRC)0x02 / 03
CMDCommand code for ADD_MASTER_DATA0xC3
## LRC/
CRC_High,
CRC_Low
Check character, (see document [4], Command Structure), in
accordance with MOD_FRM pin on LEGIC advant SM
LRC: 1 byte, CRC: 2 bytes
## PRELIMINARY


LEGIC Identsystems Ltd
## CONFIDENTIAL
## 000-00

LEGIC advant 2000 Series
Reference Manual, Commands, SC-2560, SM-2570
80/92LA-33-110d-en© Transmission of contents to others prohibited05.2006
Technical specifications subject to change
ADD_MASTER_DATA answer
STATUS answerWith a non-command-specific error (e.g. communication error when sending the command)
a STATUS answer is returned (see page 34 and “Status and Error Codes" on page 90).
# BYTECMDSTATMASTER_NOLRC/CRC_HighCRC_Low
[0x03 / 04][0xC3]0x00 ... 68[0x01 ... 1E]
ByteDescriptionValue
# BYTENumber of following bytes (CMD ... LRC/CRC)0x03 / 04
CMDCommand code for ADD_MASTER_DATA0xC3
STATStatus
0x00     OK,     →   "Segment selected"
0x01     Master data memory full →  "TXP selected"
0x02Master data record is already saved in the Master
data memory →  "Segment selected"
0x40COMMUNICATION_LOST
TXP no longer in RF field →  "Idle"
0x50UNKNOWN_MEDIUM_S_TYPE
Unknown segment type or authorization segment out-
side specification →  "TXP selected"
0x68     WRONG_MEDIUM_S_TYPE
No authorization segment →  "TXP selected"
## 0x00 ... 68
MASTER_NO   Number of master data record
1 ... 20    Master data record in temporary memory (GAM,
## SAM, IAM)
21 ... 30  Master data record in permanent memory (XAM_1)
0x01 ... 1E
## LRC/
CRC_High,
CRC_Low
Check character, (see document [4], Command Structure), in
accordance with MOD_FRM pin on LEGIC advant SM
LRC: 1 byte, CRC: 2 bytes
## PRELIMINARY


LEGIC Identsystems Ltd
## CONFIDENTIAL
## 000-00

LEGIC advant 2000 Series
Reference Manual, Commands, SC-2560, SM-2570
05.2006© Transmission of contents to others prohibitedLA-33-110d-en81/92
Technical specifications subject to change
## 2.41    DELETE_MASTER_DATA
The DELETE_MASTER_DATA command deletes a master data record from the information
database (IDB) of the LEGIC advant SM.
Conditions•   DELETE_MASTER_DATA can only be executed with a LEGIC advant SM with an initial-
ization function (SC-2560, SM-2570). The /ICE-Pin has to be enabled.
-   The LEGIC advant SM contains a maximum of 30 master data records, 20 in temporary
memory (1 ... 20) and 10 in permanent memory (21 ... 30).
## DELETE_MASTER_DATA
command
DELETE_MASTER_DATA an-
swer
STATUS answerWith a non-command-specific error (e.g. communication error when sending the command)
a STATUS answer is returned (see page 34 and “Status and Error Codes" on page 90).
# BYTECMDMASTER_NOLRC/CRC_HighCRC_Low
[0x04 / 05][0xC4][0x01 ... 1E]
ByteDescriptionValue
# BYTENumber of following bytes (CMD ... LRC/CRC)0x04 / 05
CMDCommand code for DELETE_MASTER_DATA0xC4
MASTER_NO   Number of the master data record to be deleted
1 ... 20    Master data record in temporary memor (GAM,
## SAM, IAM)
21 ... 30  Master data record in permanent memory
## (XAM_1)
0x01 ... 1E
## LRC/
CRC_High,
CRC_Low
Check character, (see document [4], Command Structure),
in accordance with MOD_FRM pin on LEGIC advant SM
LRC: 1 byte, CRC: 2 bytes
# BYTECMDSTATLRC/CRC_HighCRC_Low
[0x03 / 04][0xC4][0x00 / 01]
ByteDescriptionValue
# BYTENumber of following bytes (CMD ... LRC/CRC)0x03 / 04
CMDAnswer code for DELETE_MASTER_DATA0xC4
STATStatus
0x00OK, master data record deleted
0x01Number of master data record too high or 0
## 0x00
## LRC/
CRC_High,
CRC_Low
Check character, (see document [4], Command Structure),
in accordance with MOD_FRM pin on LEGIC advant SM
LRC: 1 byte, CRC: 2 bytes
## PRELIMINARY


LEGIC Identsystems Ltd
## CONFIDENTIAL
## 000-00

LEGIC advant 2000 Series
Reference Manual, Commands, SC-2560, SM-2570
82/92LA-33-110d-en© Transmission of contents to others prohibited05.2006
Technical specifications subject to change
## 2.42    ADD_SEGMENT
The ADD_SEGMENT command creates a new segment on a TXP. Both authorization (AM)
and application segments (IM_S) can be created.
Conditions•   ADD_SEGMENT can only be executed with a LEGIC advant SM with an initialization
function (SC-2560, SM-2570). The /ICE-Pin has to be enabled.
-   Before ADD_SEGMENT is executed, communication with the TXP must be established
with the SELECT_TXP command ("TXP selected" communication state).
-   After ADD_SEGMENT is processed, the LEGIC advant SM remains in the "Segment
selected" state. Additional write and read commands can follow.
-   If the execution was successful, the master timeout is restarted.
-   An authorization or application segment can only be created when a valid master data
record is stored in the LEGIC advant SM in accordance with the authorization rules (see
document [2], Authorization and Data Access Management).
•Only one authorization segment can be created on a TXP.
-   When creating an application segment, the application data can also be written directly
afterward (S_DATA area).
-   Depending on the segment and TXP type the creation of a segment may take up to 3 s.
NoteDuring the execution of the command, no second TXP may be located in the sphere of
influence of the antenna and the TXP may not be removed from the field prematurely.
ADD_SEGMENT command
Number of the segment to be
created
Automatic placing of the segment:
-   The first existing segment which is empty (S_ENG = 0) and which has the same length
as the one to be created is automatically searched. The new segment to be created is
written to this memory area.
-   If no suitable, existing segment is found, the new segment is added after the last existing
segment (S_LAST = 1).
# BYTECMDS_NUMS_TYPE#DATADATA 0 ... nLRC/CRC_HighCRC_Low
[0x05 ... 80][0xC5][0x00 ... 7F][0x00 ... A0][0x00 ... 7A][0x00 ... FF]
ByteDescriptionValue
# BYTENumber of following bytes (CMD ... LRC/CRC)0x05 ... 80
CMDCommand code for ADD_SEGMENT0xC5
S_NUMNumber of the segment to be created (see next page)
0x00 Automatic placing of the segment
0x01 ... 7F     Segment number
0x00 ... 7F
S_TYPETyp of segment to be created
0x01       GAM       *
0x02SAM *
0x03IAM *
0x04XAM_1 *
0x40Data segment
- Only 1 segment per TXP possible
## 0x00 ... A0
#DATANumber of following segment-type-specific data bytes0x00 ... 7A
DATA 0 ... nSegment-type-specific data bytes (see following pages)0x00 ... FF
## LRC/
CRC_High,
CRC_Low
Check character, (see document [4], Command Structure),
in accordance with MOD_FRM pin on LEGIC advant SM
LRC: 1 byte, CRC: 2 bytes
## PRELIMINARY


LEGIC Identsystems Ltd
## CONFIDENTIAL
## 000-00

LEGIC advant 2000 Series
Reference Manual, Commands, SC-2560, SM-2570
05.2006© Transmission of contents to others prohibitedLA-33-110d-en83/92
Technical specifications subject to change
-   The segment number is returned in the ADD_SEGMENT answer.
Segment number:
-   The new segment to be created is inserted at the desired point if the existing segment is
empty at this point (S_ENG = 0) and has the same length as the one to be created.
-   If the existing segment is occupied at the desired point (S_ENG = 1) or if it has a different
length, a corresponding STATUS answer is returned.
-   If the specified segment number is greater than the segment number of the last existing
segment (S_LAST = 1), the new segment is added to the last existing one.
-   If the segment was created successfully, the segment number is returned in the
ADD_SEGMENT answer.
GAM segment typeFor a GAM authorization medium, the following data must be specified (see document [2],
Authorization and Data Access Management).
SAM segment typeFor a SAM authorization medium, the following data must be specified (see document [1],
Authorization and Data Access Management).
The extended launch data (WEL, DATA_WEX, WES, WEM) are only interpreted when a
SAM n/63 is created (for a description of extended launch data, see document [1], Launch
## Procedure)
DATA 0DATA 1DATA 2DATA 3DATA n
S_OLES_FLS_OLS_STAMP 1 (SSC)S_STAMP n
[0x00 / 01][0x10][0x01 ... 0C][0x00 ... FE] [0x00 ... FF]
ByteDescriptionValue
S_OLEOrganization level enable
0x00Blocked
0x01Enabled
## 0x00 / 01
S_FLFunction level
## 16
## 0x10
S_OLOrganization level (corresponds to length of stamp
data)
## 1 ... 12
0x01 ... 0C
S_STAMP 1 (SSC)   1st byte of stamp data (SSC)0x00 ... FE
S_STAMP 2 ... nFollowing bytes of stamp data0x00 ... FF
## DATA 0DATA 1DATA 2DATA 3DATA 4DATA 5DATA 6DATA 7
S_OLES_FLS_WRCWELDATA_WEX_HighDATA_WEX_LowWEX_HighWEX_Low
[0x00 / 01][0x10][0x00 ... 0C][0x00 ... FF] [0x00 ... ][0x0D ... ]
DATA 8DATA 9DATA 10DATA 11DATA n
WESWEMS_OLS_STAMP 1 (SSC)S_STAMP n
[0x00 / 01][0x00 ... 02][0x01 ... 0C][0x00 ... FE] [0x00 ... FF]]
ByteDescriptionValue
S_OLEOrganization level enable
0Blocked
1Enabled
## 0x00 / 01
## PRELIMINARY


LEGIC Identsystems Ltd
## CONFIDENTIAL
## 000-00

LEGIC advant 2000 Series
Reference Manual, Commands, SC-2560, SM-2570
84/92LA-33-110d-en© Transmission of contents to others prohibited05.2006
Technical specifications subject to change
-   These data are only interpreted when a SAM n/63 is created and S_WRC > 0. For permit-
ted values, see the following table (also see document [2], Extended Write Authorization).
**  With LEGIC prime MIM the value WEX is defined. WEX = stamp length + DATA_WEX
(WEX must be > 12)
Permissible values for extended launch data
S_FLFunction level
1 ... 54Unrestricted
55 ... 62 Reserved LEGIC
63Launch medium
64Launch withdrawal medium
## 0x01 ... 40
S_WRCLaunch data length (S_WRC ≤ S_OL)
0No launch data (with S_FL ≠ 63, 64)
1 ... 7Launch data length (LEGIC prime MIM)
1 ... 12Launch data length (LEGIC advant ATC)
0x00 ... 0C
WEL *Length of the field with extended write access
0No extended launch data
1 ... 255Field length
0x00 ... FF
DATA_WEX *Start address of the field for extended write access in
the S_DATA area
0 ... Upper segment limit
## 0x00 00 ...
WEX **Start address of the field for extended write access (in
accordance with LEGIC prime definition), only relevant
when LEGIC prime MIMs are to be accessed with a
launched LEGIC advant SM.
## WEX > 12
0x00 0C ...
WES *Shadow memory for extended write authorization
0without autom. shadow memory
1with autom. shadow memory and 16-bit CRC
## 0x00 / 01
WEM *Mode for extended write authorization
0unrestricted writing
1Decrement only
2Increment only
## 0x00 ... 02
S_OLOrganization level (corresponds to length of stamp data)
## 1 ... 12
0x01 ... 0C
S_STAMP 1 (SSC)  1st byte of stamp data (SSC)0x00 ... FE
S_STAMP 2 ... nFollowing bytes of stamp data0x00 ... FF
WEM   WES   WELDATA_WEX   AccessRemarks
001 ... 255nUnrestricted
016 ... 255nUnrestricted with
shadow memory
Several value fields with
a length of 1 ... 4 bytes
possible,
only ...VALUE com-
mands allowed
1 16 ... 255nIncrementing with
shadow memory
216 ... 255nDecrementing with
shadow memory
ByteDescriptionValue
## PRELIMINARY


LEGIC Identsystems Ltd
## CONFIDENTIAL
## 000-00

LEGIC advant 2000 Series
Reference Manual, Commands, SC-2560, SM-2570
05.2006© Transmission of contents to others prohibitedLA-33-110d-en85/92
Technical specifications subject to change
IAM segment typeFor an IAM authorization medium, the following data must be specified (see document [2],
Authorization and Data Access Management).
Segment type XAM_1For an XAM_1 authorization medium, the following data must be specified (see document
[2], Authorization and Data Access Management).
ImportantLEGIC advant SM with initialization function and stored XAM_1 master data record
must be protected from unauthorized access (logistics, spare parts). New application
segments can be initialized, deleted or changed at any time with this kind of LEGIC
advant SM.
Ensure by means of the application software that segments cannot be deleted unin-
tentionally.
DATA 0DATA 1DATA 2DATA 3DATA n
S_OLES_FLS_OLS_STAMP 1 (SSC)S_STAMP n
[0x00 / 01][0x01 ... 30][0x01 ... 0C][0x00 ... FE] [0x00 ... FF]]
ByteDescriptionValue
S_OLEOrganization level enable
0x00Blocked
0x01Enabled
## 0x00 / 01
S_FLFunction level
1 ... 48    (40 ... 48 reserved LEGIC)
## 0x01 ... 30
S_OLOrganization level (corresponds to length of stamp
data)
## 1 ... 12
0x01 ... 0C
S_STAMP 1 (SSC)   1st byte of stamp data (SSC)0x00 ... FE
S_STAMP 2 ... nFollowing bytes of stamp data0x00 ... FF
DATA 0DATA 1DATA n
S_OLS_STAMP 1 (SSC)S_STAMP n
[0x01 ... 0C][0x00 ... FE] [0x00 ... FF]]
ByteDescriptionValue
S_OLOrganization level (corresponds to length of stamp
data)
## 1 ... 12
0x01 ... 0C
S_STAMP 1 (SSC)   1st byte of stamp data (SSC)0x00 ... FE
S_STAMP 2 ... nFollowing bytes of stamp data0x00 ... FF
## PRELIMINARY


LEGIC Identsystems Ltd
## CONFIDENTIAL
## 000-00

LEGIC advant 2000 Series
Reference Manual, Commands, SC-2560, SM-2570
86/92LA-33-110d-en© Transmission of contents to others prohibited05.2006
Technical specifications subject to change
Segment type data segmentFor an application segment, the following data must be specified (see document [2], Author-
ization and Data Access Management).
For segments on LEGIC prime MIM, S_WRP is defined. This value is calculated as follows:
## S_WRP = S_DATA_WRP + S_OL
-   With ADD_SEGMENT a maximum of 100 data bytes can be written. Further data bytes can be written with
## WRITE.
## DATA 0DATA 1DATA 2DATA 3DATA 4DATA 5DATA 6
S_SUB_TYPES_CRYPTS_DATA_WRP_HighS_DATA_WRP_LowS_RDS_WRCS_DATA_LEN_High
[0x00][0x00 ... 03][0x00 00 ... ][0x00 / 01][0x00 ... 0C][0x00 ... ]
DATA 7DATA 8DATA 9DATA 10DATA 11DATA n
S_DATA_LEN_LowS_OLS_STAMP 1 (SSC)S_STAMP n# S_DATAS_DATA 1 ... n
[0x00 ... ][0x01 ... 0C][0x00 ... FE] [0x00 ... FF]][0x01 ... 64][0x00 ... FF]
ByteDescriptionValue
S_SUB_TYPESubgroup of segment type (only 0x00 permitted)0x00
S_CRYPTData encryption in segment
0x01LEGIC encryption
0x02DES encryption
0x033DES encryption
## 0x01 ... 03
S_DATA_WRPLength of read-only area in the S_DATA area from
address 0x00
## 0x00 00 ...
S_RDRead protection over entire segment
0No read protection
1Read protection set (if S_WRC > 0)
## 0x00 / 01
S_WRCKey length for write/read protection of entire segment
## (S_WRC ≤ S_OL)
0No write/read protection
1 ... 12key length for write/read protection
0x00 ... 0C
S_DATA_LENLength of S_DATA area in bytes0x00 00 ...
S_OLOrganization level (corresponds to length of stamp data)
## 1 ... 12
0x00 ... 0C
S_STAMP 1 (SSC)  1st byte of stamp data (SSC)0x00 ... FE
S_STAMP 2 ... nFollowing bytes of stamp data0x00 ... FF
# S_DATANumber of data bytes to be written in the S_DATA area    0x00 ... 64 *
S_DATA 1 ... nData bytes to be written in the S_DATA area0x00 ... FF
## PRELIMINARY


LEGIC Identsystems Ltd
## CONFIDENTIAL
## 000-00

LEGIC advant 2000 Series
Reference Manual, Commands, SC-2560, SM-2570
05.2006© Transmission of contents to others prohibitedLA-33-110d-en87/92
Technical specifications subject to change
ADD_SEGMENT answer
STATUS answerWith a non-command-specific error (e.g. communication error when sending the command)
a STATUS answer is returned (see page 34 and “Status and Error Codes" on page 90).
STATUS answer for comman-
do-specific errors
With this command the following command-specific errors are returned in the STATUS an-
swer.
# BYTECMDSTATS_NUMLRC/CRC_HighCRC_Low
[0x04 / 05][0xC5][0x00 ... 71][0x00 ... 7F]
ByteDescriptionValue
# BYTENumber of following bytes (CMD ... LRC/CRC)0x04 / 05
CMDAnswer code for ADD_SEGMENT0xC5
STATStatus
0x00OK, segment created →   "Segment selected"
0x01     GAM, IAM, XAM_1: S_FL, S_OL too large
→   "TXP selected"
SAM: DATA_WEX, S_FL, S_OL too large
→   "TXP selected"
Data segment: S_DATA_WRP, S_OL, S_WRC
too large or unknown S_CRYPT algorithm →   "TXP
selected"
0x40COMMUNICATION_LOST
TXP no longer in RF field →  "Idle"
0x51CORRUPT_MEDIUM
Segment linking defective →  "Idle"
0x52CORRUPT_SEG
Defective segment →  "TXP selected"
0x61     AUTHORIZATION_MISSING
No suitable master data →  "TXP selected"
0x68     WRONG_MEDIUM_S_TYPE
No suitable medium (e.g. not empty)
→  "TXP selected"
0x71     SEG_SPACE_NOT_AVAILABLE
Insufficient memory space for segment
→  "TXP selected"
## 0x00 ... 71
S_NUMNumber of the generated segment
0x00 Automatic search for suitable location
0x01 ... 7F     Segment number
0x00 ... 7F
## LRC/
CRC_High,
CRC_Low
Check character, (see document [4], Command Structure),
in accordance with MOD_FRM pin on LEGIC advant SM
LRC: 1 byte, CRC: 2 bytes
STATDescription
0x22INVALID_SYNTAX
S_OLE > 1, S_FL < 1, S_RD > 1, wrong segment type
## PRELIMINARY


LEGIC Identsystems Ltd
## CONFIDENTIAL
## 000-00

LEGIC advant 2000 Series
Reference Manual, Commands, SC-2560, SM-2570
88/92LA-33-110d-en© Transmission of contents to others prohibited05.2006
Technical specifications subject to change
## 2.43    REMOVE_SEGMENT
The REMOVE_SEGMENT command deletes a segment on a TXP. Both authorization (AM)
and application segments (IM_S) can be deleted.
Conditions•   REMOVE_SEGMENT can only be executed with a LEGIC advant SM with an initializa-
tion function (SC-2560, SM-2570). The /ICE-Pin has to be enabled.
-   Before REMOVE_SEGMENT is executed, communication with the transponder must be
established ("TXP selected" communication state)
-   After REMOVE _SEGMENT is processed, the LEGIC advant SM is in the "TXP selected"
state.
-   A segment can only be deleted when a valid master data record is stored in the LEGIC
advant SM in accordance with the authorization rules (see document [2], Authorization
and Data Access Management).
Note on LEGIC primeIf the command is used on an unsegmented LEGIC prime MIM (AM or IM), a blank IM-S re-
sults.
REMOVE_SEGMENT com-
mand
REMOVE_SEGMENT answer
# BYTECMDS_NUMLRC/CRC_HighCRC_Low
[0x03 / 04][0xC6][0x01 ... 7F]
ByteDescriptionValue
# BYTENumber of following bytes (CMD ... LRC/CRC)0x03 / 04
CMDCommand code for REMOVE_SEGMENT0xC6
S_NUMNumber of the segment to be deleted0x01 ... 7F
## LRC/
CRC_High,
CRC_Low
Check character, (see document [4], Command Structure),
in accordance with MOD_FRM pin on LEGIC advant SM
LRC: 1 byte, CRC: 2 bytes
# BYTECMDSTATLRC/CRC_HighCRC_Low
[0x03 / 04][0xC6][0x00 ... 70]
ByteDescriptionValue
# BYTENumber of following bytes (CMD ... LRC/CRC)0x03 / 04
CMDAnswer code for REMOVE_SEGMENT0xC6
STATStatus
0x00OK, segment deleted →   "TXP selected"
0x40COMMUNICATION_LOST
TXP no longer in RF field →  "Idle"
0x50UNKNOWN_MEDIUM_S_TYPE
Unknown segment type  →  "TXP selected"
0x51CORRUPT_MEDIUM
Segment linking defective →  "Idle"
0x52CORRUPT_SEGMENT
Authorization segment defective →  "TXP selected"
0x61     AUTHORIZATION_MISSING
No suitable master data →  "TXP selected"
0x68WRONG_MEDIUM_S_TYPE
Action not possible with current TXP
→  "TXP selected"
0x70SEG_NOT_FOUND
Segment not found  →  "TXP selected"
## 0x00 ... 70
## PRELIMINARY


LEGIC Identsystems Ltd
## CONFIDENTIAL
## 000-00

LEGIC advant 2000 Series
Reference Manual, Commands, SC-2560, SM-2570
05.2006© Transmission of contents to others prohibitedLA-33-110d-en89/92
Technical specifications subject to change
STATUS answerWith a non-command-specific error (e.g. communication error when sending the command)
a STATUS answer is returned (see page 34 and “Status and Error Codes" on page 90).
STATUS answer for comman-
do-specific errors
With this command the following command-specific errors are returned in the STATUS an-
swer.
## LRC/
CRC_High,
CRC_Low
Check character, (see document [4], Command Structure),
in accordance with MOD_FRM pin on LEGIC advant SM
LRC: 1 byte, CRC: 2 bytes
ByteDescriptionValue
STATDescription
0x22INVALID_SYNTAX
Segment number < 1
## PRELIMINARY


LEGIC Identsystems Ltd
## CONFIDENTIAL
## 000-00

LEGIC advant 2000 Series
Reference Manual, Commands, SC-2560, SM-2570
90/92LA-33-110d-en© Transmission of contents to others prohibited05.2006
Technical specifications subject to change
3Status and Error Codes
OverviewStatus and error messages can be returned in the command-specific answer (answer code
= command code) or in the STATUS answer.
Both in the STATUS-specific and in the command-specific answer, the status and error
codes have a uniform numbering. The numbering refers to the STAT field in the answer. The
following categories are defined:
General errorsThe general errors are returned in the command-specific answer or as a STATUS answer.
RangeStatus and error category
0x00OK, command executed error-free
0x01 ... 1FCommand-specific status or error
Returned in the command-specific answer.
(For description, see respective command)
0x20 ... EFGeneral error
Returned in the command-specific answer or as a STATUS answer.
(See below for description)
0xF0 ... FFSystem error or fatal error
Returned as STATUS answer.
(For description, see page 92)
Table 8: Status and error categories
Number/NameDescription
## 0x20
## INVALID_COMMAND
Invalid command code or command is not supported
## 0x21
## INVALID_COMMAND_
## LENGTH
Command length does not correspond to #BYTE or a varia-
ble field exceeds the command length.
## 0x22
## INVALID_SYNTAX
Command parameters do not match the specification.
## Remarks:
This error is caught after issuing the command, and the
communication states remain unchanged.
Only rough errors in the command parameters are discov-
ered. Transponder or data-structure-dependent area vio-
lations or parameters errors that cannot be determined
until the command is executed are returned with specific
error codes.
## 0x23
## WRONG_COMMAND
Command is not permitted in the current context.
Example: Read command when no TXP is selected yet
## 0x24
## MUX_DISABLED
Command execution not possible. Multiplex operation,
LEGIC advant SM is deactivated with a low signal on the
ACTION pin ("MUX disabled" communication state)
## 0x30
## BUSY_WAITING_TXP
Command not permitted. A TXP in the RF field is waited for
## (AUTO_READ).
## 0x31
## BUSY_LAUNCHING
Command not permitted. A launch process is active.
## 0x40
## COMMUNICATION_LOST
The connection to the TXP is aborted. Transmission error or
TXP no longer in RF field.
The connection must be re-established.
## 0x50
## UNKNOWN_MEDIUM_
## S_TYPE
The TXP has a LEGIC data structure, but the data structure
or the segment data are outside the specification.
## Examples:
Unknown segment type, XAM with wrong S_FL
Table 9: General errors
## PRELIMINARY


LEGIC Identsystems Ltd
## CONFIDENTIAL
## 000-00

LEGIC advant 2000 Series
Reference Manual, Commands, SC-2560, SM-2570
05.2006© Transmission of contents to others prohibitedLA-33-110d-en91/92
Technical specifications subject to change
## 0x51
## CORRUPT_MEDIUM
The TXP has a LEGIC data structure, but an integrity check
(e.g. CRC) in the header of the LEGIC data structure or in
the segment linking has failed.
## Remarks:
If this error occurs while selecting the TXP, then the con-
tent of the TXP is lost. If this error occurs during the seg-
ment search, then at least those segments that lie before
the defective segment can be accessed (after selecting
again).
## 0x52
## CORRUPT_SEG
An integrity check in the segment header (S_INFO) has
failed, however the linking (reference to the next segment) is
## OK.
## Remarks:
The content of the segment is lost, however the segments
before and after can be accessed. When searching for a
segment with a search string, this kind of defective seg-
ment is skipped without an error message.
## 0x60
## ACCESS_DENIED
This access type (read/write/value handling etc.) is not per-
mitted (e.g. write/read protection).
## Remarks:
Certain access may be permitted by reading in a master
data record or by carrying out a launch. Therefore, the
same command must not necessarily lead to an error the
next time.
## 0x61
## AUTHORIZATION_
## MISSING
Authorization is missing.
## Example:
Creating or deleting of segments without corresponding
master data record.
## Remarks:
This error will not occur next time by reading in a corre-
sponding master data record.
## 0x68
## WRONG_MEDIUM_S_TY
## PE
This action is not possible on this TXP or segment.
## Example:
Creation of AMs on TXPs with application segments, con-
version of MIM22 into IM-S or command is not supported
with the current segment type.
## 0x70
## SEG_NOT_FOUND
Segment search has failed.
## Example:
Empty TXP, segment number too high or no segment
matches search string.
## 0x71
## SEG_SPACE_NOT_
## AVAILABLE
No space available for creating segment.
## Example:
Specified segment number is not free, gap does not fit or
TXP has too little free memory.
0xE0
## INTERFACE_SECURITY_
## ERROR
Command is not permitted in the current state or communi-
cation error (only for secured communication)
Number/NameDescription
Table 9: General errors
## PRELIMINARY


LEGIC Identsystems Ltd
## CONFIDENTIAL
## 000-00

LEGIC advant 2000 Series
Reference Manual, Commands, SC-2560, SM-2570
92/92LA-33-110d-en© Transmission of contents to others prohibited05.2006
Technical specifications subject to change
System error or fatal errorThe system and fatal errors are returned as a STATUS answer.
Number/NameDescription
0xF0
## SYS_ANSWER_FROM_RESET
Reset of LEGIC advant SM
## Remarks:
A power failure or a watchdog triggering can also
lead to a reset, and therefore to this message.
0xF1
## SYS_RECEIVE_ERROR
Framing error
## Examples:
CRC in the protocol frame (framing) is incorrect,
command shorter than specified in #BYTE byte or
pause between characters too long.
## Remarks:
Following this kind of error, additional errors can fol-
low (even with only one command), as start or end
of protocol frame cannot be found.
0xF2
## SYS_LOCKED
LEGIC advant SM is blocked with password.
## Remarks:
This error occurs with every command until unlock-
ing is carried out with the correct password
(UNLOCK command).
0xF3
## SYS_GENERAL_ERROR
Software error.
## Remarks:
LEGIC Identsystems should be contacted when an
error of this kind occurs in the field.
0xF8
## SYS_ANSWER FROM_RESET
Message from Bootloader: LEGIC OS is invalid and
can not be startet up
## Remark:
The software download of the LEGIC OS must be
repeated.
0xF9
## FATAL_ERROR
Boot error (e.g. faulty EEPROM)
## Remarks:
LEGIC Identsystems should be contacted when an
error of this kind occurs.
Table 10: System and fatal errors
## PRELIMINARY
