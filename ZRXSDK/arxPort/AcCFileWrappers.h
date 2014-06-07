#ifndef _ARXPORT_AD_ACCFILEWRAPPERS_H_
#define _ARXPORT_AD_ACCFILEWRAPPERS_H_ 1

#include "AdCharFmt.h"
#include "..\inc\ZcCFileWrappers.h"

typedef ZcOutputBufMgr AcOutputBufMgr;
typedef ZcCFile AcCFile;
typedef ZcCStdioFile AcCStdioFile;

#define AcCFile_Assert				ZcCFile_Assert

#ifdef UNICODE
#define acByteSwap					zcByteSwap
#define acWriteWCharToCFile			zcWriteWCharToCFile
#define acReadCIFFromCFile			zcReadCIFFromCFile
#define acReadAnsiCharFromCFile		zcReadAnsiCharFromCFile
#define acReadUtf8CharFromCFile		zcReadUtf8CharFromCFile
#define acReadUtf16CharFromCFile	zcReadUtf16CharFromCFile
#endif

#define acCheckCFileCharFormat		zcCheckCFileCharFormat

typedef ZcOutputBufMgr				AcOutputBufMgr;
typedef ZcCStdioFile				AcCStdioFile;

//#define acCheckCFileCharFormat		zcCheckCFileCharFormat
//#define acByteSwap					zcByteSwap
//#define acReadCIFFromCFile			zcReadCIFFromCFile
//#define acReadAnsiCharFromCFile		zcReadAnsiCharFromCFile
//#define acReadUtf8CharFromCFile		zcReadUtf8CharFromCFile
//#define acReadUtf16CharFromCFile	zcReadUtf16CharFromCFile
#endif

