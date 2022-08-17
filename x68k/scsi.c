// ---------------------------------------------------------------------------------------
//  SCSI.C - 外付けSCSIボード (CZ-6BS1) 
//    SCSI IOCSを乗っ取る形で対応（SPCはエミュレートしない）
//    内蔵SCSI（のダミー）IPLは winx68k.c 内で定義してます
// ---------------------------------------------------------------------------------------

#include	"common.h"
#include	"fileio.h"
#include	"winx68k.h"
#include	"m68000.h"
#include	"scsi.h"

uint8_t	SCSIIPL[0x2000];

void SCSI_Init(void)
{
	// オリジナルのSCSI ROM
	// 動作：SCSI IOCSが呼ばれると、SCSI IOCS番号を $e9f800 に出力します。
	// SCSIデバイスからの起動は不可、初期化ルーチンはSCSI IOCS($F5)のベクタ設定のみを行います。
	static	uint8_t	SCSIIMG[] = {
		0x00, 0xea, 0x00, 0x34,			// $ea0020 SCSI起動用のエントリアドレス
		0x00, 0xea, 0x00, 0x36,			// $ea0024 IOCSベクタ設定のエントリアドレス(必ず"Human"の8バイト前)
		0x00, 0xea, 0x00, 0x4a,			// $ea0028 SCSI IOCSエントリアドレス
		0x48, 0x75, 0x6d, 0x61,			// $ea002c ↓
		0x6e, 0x36, 0x38, 0x6b,			// $ea0030 ID "Human68k"	(必ず起動エントリポイントの直前)
		0x4e, 0x75,				// $ea0034 "rts"		(起動エントリポイント、何もしないよ)
		0x23, 0xfc, 0x00, 0xea, 0x00, 0x4a,	// $ea0036 ↓			(IOCSベクタ設定エントリポイント)
		0x00, 0x00, 0x07, 0xd4,			// $ea003c "move.l #$ea004a, $7d4.l" (IOCS $F5のベクタ設定)
		0x74, 0xff,				// $ea0040 "moveq #-1, d2"
		0x4e, 0x75,				// $ea0042 "rts"
		0x53, 0x43, 0x53, 0x49, 0x45, 0x58,	// $ea0044 ID "SCSIEX"		(SCSIカードのID)
		0x13, 0xc1, 0x00, 0xe9, 0xf8, 0x00,	// $ea004a "move.b d1, $e9f800"	(SCSI IOCSコールエントリポイント)
		0x4e, 0x75,				// $ea0050 "rts"
	};
	int i;
	uint8_t tmp;
	memset(SCSIIPL, 0, 0x2000);
	memcpy(&SCSIIPL[0x20], SCSIIMG, sizeof(SCSIIMG));
	for (i=0; i<0x2000; i+=2)
	{
		tmp = SCSIIPL[i];
		SCSIIPL[i] = SCSIIPL[i+1];
		SCSIIPL[i+1] = tmp;
	}
}

void SCSI_Cleanup(void) { }
void FASTCALL SCSI_Write(DWORD adr, uint8_t data) { }

uint8_t FASTCALL SCSI_Read(DWORD adr)
{
	return SCSIIPL[(adr^1)&0x1fff];
}
